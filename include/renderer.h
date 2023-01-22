#pragma once

#include <curses.h>

#include <fstream>
#include <iostream>
#include <stdexcept>

#include "nvim_rpc.h"

std::ofstream ofs("/tmp/n.log");

class Renderer {
 public:
  Renderer(nvim::NvimRPC *rpc) : rpc_{rpc} {
    wnd_ = ::initscr();
    if (!wnd_) throw std::runtime_error("Couldn't init screen");

    ::keypad(stdscr, TRUE);
    ::raw();
    ::noecho();
  }

  ~Renderer() { ::endwin(); }

  void AttachUI() {
    rpc_->SetOnNotify([this](std::string method, const msgpack::object &obj) {
      std::cout << "NOTIFY" << '\n';
      _OnNotification(method, obj);
    });

    int width{}, height{};
    getmaxyx(wnd_, height, width);

    rpc_->Request(
        [=](nvim::Packer &pk) {
          pk.pack(std::string{"nvim_ui_attach"});
          pk.pack_array(3);
          pk.pack(width);
          pk.pack(height);
          pk.pack_map(2);
          pk.pack("rgb");
          pk.pack(true);
          pk.pack("ext_linegrid");
          pk.pack(true);
        },
        [](const msgpack::object &err, const msgpack::object &resp) {
          std::cout << "RESPONSE: " << resp;
          if (!err.is_nil()) {
            std::ostringstream oss;
            oss << "Failed to attach UI " << err << std::endl;
            throw std::runtime_error(oss.str());
          }
        });
  }

 private:
  nvim::NvimRPC *rpc_;
  WINDOW *wnd_;

  void _OnNotification(const std::string &method, const msgpack::object &obj) {
    if (method != "redraw") {
      ofs << "Notification " << method << " " << obj << std::endl;
      return;
    }

    const auto &arr = obj.via.array;
    ofs << obj;

    for (size_t i = 0; i < arr.size; ++i) {
      const auto &event = arr.ptr[i].via.array;
      std::string subtype = event.ptr[0].as<std::string>();
      // ofs << subtype << " " << event.size << std::endl;
      if (subtype == "flush") {
        ::wrefresh(wnd_);
      } else if (subtype == "grid_line") {
        int y{}, x{};
        getyx(wnd_, y, x);

        for (size_t j = 1; j < event.size; ++j) {
          const auto &inst = event.ptr[j].via.array;
          // ofs << " inst " << inst.size << std::endl;
          int grid = inst.ptr[0].as<int>();
          if (grid != 1) throw std::runtime_error("Multigrid not supported");
          int row = inst.ptr[1].as<int>();
          int col = inst.ptr[2].as<int>();
          const auto &cells = inst.ptr[3].via.array;

          int hl_id;
          for (size_t c = 0; c < cells.size; ++c) {
            const auto &cell = cells.ptr[c].via.array;
            int repeat = 1;
            std::string text = cell.ptr[0].as<std::string>();
            // if repeat is greater than 1, we are guaranteed to send an hl_id
            // https://github.com/neovim/neovim/blob/master/src/nvim/api/ui.c#L483
            if (cell.size > 1) hl_id = cell.ptr[1].as<int>();
            if (cell.size > 2) repeat = cell.ptr[2].as<int>();
            ::wmove(wnd_, row, col);
            col += repeat * text.size();
            while (repeat--) {
              //                attr = self.attributes.get(hl_id,
              //                curses.color_pair(hl_id))
              ::waddstr(wnd_, text.c_str());
            }
          }
        }

        ::wmove(wnd_, y, x);
      }
    }
  }
};
