// Auto generated

#ifndef NEOVIM_CPP__NVIM_HPP_
#define NEOVIM_CPP__NVIm_HPP_

#include "nvim_rpc.h"

namespace nvim {

class Nvim {
 public:
  void connect_tcp(const std::string& host, const std::string& service,
                   double timeout_sec = 1.0) {
    client_.connect_tcp(host, service, timeout_sec);
  }

  void nvim_del_autocmd(Integer id) {
    client_.call("nvim_del_autocmd", nullptr, id);
  }

  void nvim_del_augroup_by_id(Integer id) {
    client_.call("nvim_del_augroup_by_id", nullptr, id);
  }

  void nvim_del_augroup_by_name(const std::string& name) {
    client_.call("nvim_del_augroup_by_name", nullptr, name);
  }

  Integer nvim_buf_line_count(Buffer buffer) {
    Integer res;
    client_.call("nvim_buf_line_count", res, buffer);
    return res;
  }

  bool nvim_buf_detach(Buffer buffer) {
    bool res;
    client_.call("nvim_buf_detach", res, buffer);
    return res;
  }

  std::vector<std::string> nvim_buf_get_lines(Buffer buffer, Integer start,
                                              Integer end,
                                              bool strict_indexing) {
    std::vector<std::string> res;
    client_.call("nvim_buf_get_lines", res, buffer, start, end,
                 strict_indexing);
    return res;
  }

  void nvim_buf_set_lines(Buffer buffer, Integer start, Integer end,
                          bool strict_indexing,
                          const std::vector<std::string>& replacement) {
    client_.call("nvim_buf_set_lines", nullptr, buffer, start, end,
                 strict_indexing, replacement);
  }

  void nvim_buf_set_text(Buffer buffer, Integer start_row, Integer start_col,
                         Integer end_row, Integer end_col,
                         const std::vector<std::string>& replacement) {
    client_.call("nvim_buf_set_text", nullptr, buffer, start_row, start_col,
                 end_row, end_col, replacement);
  }

  Integer nvim_buf_get_offset(Buffer buffer, Integer index) {
    Integer res;
    client_.call("nvim_buf_get_offset", res, buffer, index);
    return res;
  }

  Object nvim_buf_get_var(Buffer buffer, const std::string& name) {
    Object res;
    client_.call("nvim_buf_get_var", res, buffer, name);
    return res;
  }

  Integer nvim_buf_get_changedtick(Buffer buffer) {
    Integer res;
    client_.call("nvim_buf_get_changedtick", res, buffer);
    return res;
  }

  void nvim_buf_del_keymap(Buffer buffer, const std::string& mode,
                           const std::string& lhs) {
    client_.call("nvim_buf_del_keymap", nullptr, buffer, mode, lhs);
  }

  void nvim_buf_set_var(Buffer buffer, const std::string& name,
                        const Object& value) {
    client_.call("nvim_buf_set_var", nullptr, buffer, name, value);
  }

  void nvim_buf_del_var(Buffer buffer, const std::string& name) {
    client_.call("nvim_buf_del_var", nullptr, buffer, name);
  }

  std::string nvim_buf_get_name(Buffer buffer) {
    std::string res;
    client_.call("nvim_buf_get_name", res, buffer);
    return res;
  }

  void nvim_buf_set_name(Buffer buffer, const std::string& name) {
    client_.call("nvim_buf_set_name", nullptr, buffer, name);
  }

  bool nvim_buf_is_loaded(Buffer buffer) {
    bool res;
    client_.call("nvim_buf_is_loaded", res, buffer);
    return res;
  }

  bool nvim_buf_is_valid(Buffer buffer) {
    bool res;
    client_.call("nvim_buf_is_valid", res, buffer);
    return res;
  }

  bool nvim_buf_del_mark(Buffer buffer, const std::string& name) {
    bool res;
    client_.call("nvim_buf_del_mark", res, buffer, name);
    return res;
  }

  std::vector<Integer> nvim_buf_get_mark(Buffer buffer,
                                         const std::string& name) {
    std::vector<Integer> res;
    client_.call("nvim_buf_get_mark", res, buffer, name);
    return res;
  }

  void nvim_del_user_command(const std::string& name) {
    client_.call("nvim_del_user_command", nullptr, name);
  }

  void nvim_buf_del_user_command(Buffer buffer, const std::string& name) {
    client_.call("nvim_buf_del_user_command", nullptr, buffer, name);
  }

  std::string nvim_command_output(const std::string& command) {
    std::string res;
    client_.call("nvim_command_output", res, command);
    return res;
  }

  Integer nvim_buf_get_number(Buffer buffer) {
    Integer res;
    client_.call("nvim_buf_get_number", res, buffer);
    return res;
  }

  void nvim_buf_clear_highlight(Buffer buffer, Integer ns_id,
                                Integer line_start, Integer line_end) {
    client_.call("nvim_buf_clear_highlight", nullptr, buffer, ns_id, line_start,
                 line_end);
  }

  void buffer_insert(Buffer buffer, Integer lnum,
                     const std::vector<std::string>& lines) {
    client_.call("buffer_insert", nullptr, buffer, lnum, lines);
  }

  std::string buffer_get_line(Buffer buffer, Integer index) {
    std::string res;
    client_.call("buffer_get_line", res, buffer, index);
    return res;
  }

  void buffer_set_line(Buffer buffer, Integer index, const std::string& line) {
    client_.call("buffer_set_line", nullptr, buffer, index, line);
  }

  void buffer_del_line(Buffer buffer, Integer index) {
    client_.call("buffer_del_line", nullptr, buffer, index);
  }

  std::vector<std::string> buffer_get_line_slice(Buffer buffer, Integer start,
                                                 Integer end,
                                                 bool include_start,
                                                 bool include_end) {
    std::vector<std::string> res;
    client_.call("buffer_get_line_slice", res, buffer, start, end,
                 include_start, include_end);
    return res;
  }

  void buffer_set_line_slice(Buffer buffer, Integer start, Integer end,
                             bool include_start, bool include_end,
                             const std::vector<std::string>& replacement) {
    client_.call("buffer_set_line_slice", nullptr, buffer, start, end,
                 include_start, include_end, replacement);
  }

  Object buffer_set_var(Buffer buffer, const std::string& name,
                        const Object& value) {
    Object res;
    client_.call("buffer_set_var", res, buffer, name, value);
    return res;
  }

  Object buffer_del_var(Buffer buffer, const std::string& name) {
    Object res;
    client_.call("buffer_del_var", res, buffer, name);
    return res;
  }

  Object window_set_var(Window window, const std::string& name,
                        const Object& value) {
    Object res;
    client_.call("window_set_var", res, window, name, value);
    return res;
  }

  Object window_del_var(Window window, const std::string& name) {
    Object res;
    client_.call("window_del_var", res, window, name);
    return res;
  }

  Object tabpage_set_var(Tabpage tabpage, const std::string& name,
                         const Object& value) {
    Object res;
    client_.call("tabpage_set_var", res, tabpage, name, value);
    return res;
  }

  Object tabpage_del_var(Tabpage tabpage, const std::string& name) {
    Object res;
    client_.call("tabpage_del_var", res, tabpage, name);
    return res;
  }

  Object vim_set_var(const std::string& name, const Object& value) {
    Object res;
    client_.call("vim_set_var", res, name, value);
    return res;
  }

  Object vim_del_var(const std::string& name) {
    Object res;
    client_.call("vim_del_var", res, name);
    return res;
  }

  Integer nvim_create_namespace(const std::string& name) {
    Integer res;
    client_.call("nvim_create_namespace", res, name);
    return res;
  }

  bool nvim_buf_del_extmark(Buffer buffer, Integer ns_id, Integer id) {
    bool res;
    client_.call("nvim_buf_del_extmark", res, buffer, ns_id, id);
    return res;
  }

  Integer nvim_buf_add_highlight(Buffer buffer, Integer ns_id,
                                 const std::string& hl_group, Integer line,
                                 Integer col_start, Integer col_end) {
    Integer res;
    client_.call("nvim_buf_add_highlight", res, buffer, ns_id, hl_group, line,
                 col_start, col_end);
    return res;
  }

  void nvim_buf_clear_namespace(Buffer buffer, Integer ns_id,
                                Integer line_start, Integer line_end) {
    client_.call("nvim_buf_clear_namespace", nullptr, buffer, ns_id, line_start,
                 line_end);
  }

  void nvim_set_option(const std::string& name, const Object& value) {
    client_.call("nvim_set_option", nullptr, name, value);
  }

  Object nvim_get_option(const std::string& name) {
    Object res;
    client_.call("nvim_get_option", res, name);
    return res;
  }

  Object nvim_buf_get_option(Buffer buffer, const std::string& name) {
    Object res;
    client_.call("nvim_buf_get_option", res, buffer, name);
    return res;
  }

  void nvim_buf_set_option(Buffer buffer, const std::string& name,
                           const Object& value) {
    client_.call("nvim_buf_set_option", nullptr, buffer, name, value);
  }

  Object nvim_win_get_option(Window window, const std::string& name) {
    Object res;
    client_.call("nvim_win_get_option", res, window, name);
    return res;
  }

  void nvim_win_set_option(Window window, const std::string& name,
                           const Object& value) {
    client_.call("nvim_win_set_option", nullptr, window, name, value);
  }

  std::vector<Window> nvim_tabpage_list_wins(Tabpage tabpage) {
    std::vector<Window> res;
    client_.call("nvim_tabpage_list_wins", res, tabpage);
    return res;
  }

  Object nvim_tabpage_get_var(Tabpage tabpage, const std::string& name) {
    Object res;
    client_.call("nvim_tabpage_get_var", res, tabpage, name);
    return res;
  }

  void nvim_tabpage_set_var(Tabpage tabpage, const std::string& name,
                            const Object& value) {
    client_.call("nvim_tabpage_set_var", nullptr, tabpage, name, value);
  }

  void nvim_tabpage_del_var(Tabpage tabpage, const std::string& name) {
    client_.call("nvim_tabpage_del_var", nullptr, tabpage, name);
  }

  Window nvim_tabpage_get_win(Tabpage tabpage) {
    Window res;
    client_.call("nvim_tabpage_get_win", res, tabpage);
    return res;
  }

  Integer nvim_tabpage_get_number(Tabpage tabpage) {
    Integer res;
    client_.call("nvim_tabpage_get_number", res, tabpage);
    return res;
  }

  bool nvim_tabpage_is_valid(Tabpage tabpage) {
    bool res;
    client_.call("nvim_tabpage_is_valid", res, tabpage);
    return res;
  }

  void ui_attach(Integer width, Integer height, bool enable_rgb) {
    client_.call("ui_attach", nullptr, width, height, enable_rgb);
  }

  void nvim_ui_set_focus(bool gained) {
    client_.call("nvim_ui_set_focus", nullptr, gained);
  }

  void nvim_ui_detach() { client_.call("nvim_ui_detach", nullptr); }

  void nvim_ui_try_resize(Integer width, Integer height) {
    client_.call("nvim_ui_try_resize", nullptr, width, height);
  }

  void nvim_ui_set_option(const std::string& name, const Object& value) {
    client_.call("nvim_ui_set_option", nullptr, name, value);
  }

  void nvim_ui_try_resize_grid(Integer grid, Integer width, Integer height) {
    client_.call("nvim_ui_try_resize_grid", nullptr, grid, width, height);
  }

  void nvim_ui_pum_set_height(Integer height) {
    client_.call("nvim_ui_pum_set_height", nullptr, height);
  }

  Integer nvim_get_hl_id_by_name(const std::string& name) {
    Integer res;
    client_.call("nvim_get_hl_id_by_name", res, name);
    return res;
  }

  void nvim_set_hl_ns(Integer ns_id) {
    client_.call("nvim_set_hl_ns", nullptr, ns_id);
  }

  void nvim_set_hl_ns_fast(Integer ns_id) {
    client_.call("nvim_set_hl_ns_fast", nullptr, ns_id);
  }

  void nvim_feedkeys(const std::string& keys, const std::string& mode,
                     bool escape_ks) {
    client_.call("nvim_feedkeys", nullptr, keys, mode, escape_ks);
  }

  Integer nvim_input(const std::string& keys) {
    Integer res;
    client_.call("nvim_input", res, keys);
    return res;
  }

  void nvim_input_mouse(const std::string& button, const std::string& action,
                        const std::string& modifier, Integer grid, Integer row,
                        Integer col) {
    client_.call("nvim_input_mouse", nullptr, button, action, modifier, grid,
                 row, col);
  }

  std::string nvim_replace_termcodes(const std::string& str, bool from_part,
                                     bool do_lt, bool special) {
    std::string res;
    client_.call("nvim_replace_termcodes", res, str, from_part, do_lt, special);
    return res;
  }

  Integer nvim_strwidth(const std::string& text) {
    Integer res;
    client_.call("nvim_strwidth", res, text);
    return res;
  }

  std::vector<std::string> nvim_list_runtime_paths() {
    std::vector<std::string> res;
    client_.call("nvim_list_runtime_paths", res);
    return res;
  }

  std::vector<std::string> nvim_get_runtime_file(const std::string& name,
                                                 bool all) {
    std::vector<std::string> res;
    client_.call("nvim_get_runtime_file", res, name, all);
    return res;
  }

  void nvim_set_current_dir(const std::string& dir) {
    client_.call("nvim_set_current_dir", nullptr, dir);
  }

  std::string nvim_get_current_line() {
    std::string res;
    client_.call("nvim_get_current_line", res);
    return res;
  }

  void nvim_set_current_line(const std::string& line) {
    client_.call("nvim_set_current_line", nullptr, line);
  }

  void nvim_del_current_line() {
    client_.call("nvim_del_current_line", nullptr);
  }

  Object nvim_get_var(const std::string& name) {
    Object res;
    client_.call("nvim_get_var", res, name);
    return res;
  }

  void nvim_set_var(const std::string& name, const Object& value) {
    client_.call("nvim_set_var", nullptr, name, value);
  }

  void nvim_del_var(const std::string& name) {
    client_.call("nvim_del_var", nullptr, name);
  }

  Object nvim_get_vvar(const std::string& name) {
    Object res;
    client_.call("nvim_get_vvar", res, name);
    return res;
  }

  void nvim_set_vvar(const std::string& name, const Object& value) {
    client_.call("nvim_set_vvar", nullptr, name, value);
  }

  void nvim_out_write(const std::string& str) {
    client_.call("nvim_out_write", nullptr, str);
  }

  void nvim_err_write(const std::string& str) {
    client_.call("nvim_err_write", nullptr, str);
  }

  void nvim_err_writeln(const std::string& str) {
    client_.call("nvim_err_writeln", nullptr, str);
  }

  std::vector<Buffer> nvim_list_bufs() {
    std::vector<Buffer> res;
    client_.call("nvim_list_bufs", res);
    return res;
  }

  Buffer nvim_get_current_buf() {
    Buffer res;
    client_.call("nvim_get_current_buf", res);
    return res;
  }

  void nvim_set_current_buf(Buffer buffer) {
    client_.call("nvim_set_current_buf", nullptr, buffer);
  }

  std::vector<Window> nvim_list_wins() {
    std::vector<Window> res;
    client_.call("nvim_list_wins", res);
    return res;
  }

  Window nvim_get_current_win() {
    Window res;
    client_.call("nvim_get_current_win", res);
    return res;
  }

  void nvim_set_current_win(Window window) {
    client_.call("nvim_set_current_win", nullptr, window);
  }

  Buffer nvim_create_buf(bool listed, bool scratch) {
    Buffer res;
    client_.call("nvim_create_buf", res, listed, scratch);
    return res;
  }

  void nvim_chan_send(Integer chan, const std::string& data) {
    client_.call("nvim_chan_send", nullptr, chan, data);
  }

  std::vector<Tabpage> nvim_list_tabpages() {
    std::vector<Tabpage> res;
    client_.call("nvim_list_tabpages", res);
    return res;
  }

  Tabpage nvim_get_current_tabpage() {
    Tabpage res;
    client_.call("nvim_get_current_tabpage", res);
    return res;
  }

  void nvim_set_current_tabpage(Tabpage tabpage) {
    client_.call("nvim_set_current_tabpage", nullptr, tabpage);
  }

  bool nvim_paste(const std::string& data, bool crlf, Integer phase) {
    bool res;
    client_.call("nvim_paste", res, data, crlf, phase);
    return res;
  }

  void nvim_put(const std::vector<std::string>& lines, const std::string& type,
                bool after, bool follow) {
    client_.call("nvim_put", nullptr, lines, type, after, follow);
  }

  void nvim_subscribe(const std::string& event) {
    client_.call("nvim_subscribe", nullptr, event);
  }

  void nvim_unsubscribe(const std::string& event) {
    client_.call("nvim_unsubscribe", nullptr, event);
  }

  Integer nvim_get_color_by_name(const std::string& name) {
    Integer res;
    client_.call("nvim_get_color_by_name", res, name);
    return res;
  }

  void nvim_del_keymap(const std::string& mode, const std::string& lhs) {
    client_.call("nvim_del_keymap", nullptr, mode, lhs);
  }

  Object nvim_get_proc(Integer pid) {
    Object res;
    client_.call("nvim_get_proc", res, pid);
    return res;
  }

  bool nvim_del_mark(const std::string& name) {
    bool res;
    client_.call("nvim_del_mark", res, name);
    return res;
  }

  std::string nvim_exec(const std::string& src, bool output) {
    std::string res;
    client_.call("nvim_exec", res, src, output);
    return res;
  }

  void nvim_command(const std::string& command) {
    client_.call("nvim_command", nullptr, command);
  }

  Object nvim_eval(const std::string& expr) {
    Object res;
    client_.call("nvim_eval", res, expr);
    return res;
  }

  Buffer nvim_win_get_buf(Window window) {
    Buffer res;
    client_.call("nvim_win_get_buf", res, window);
    return res;
  }

  void nvim_win_set_buf(Window window, Buffer buffer) {
    client_.call("nvim_win_set_buf", nullptr, window, buffer);
  }

  std::vector<Integer> nvim_win_get_cursor(Window window) {
    std::vector<Integer> res;
    client_.call("nvim_win_get_cursor", res, window);
    return res;
  }

  void nvim_win_set_cursor(Window window, const std::vector<Integer>& pos) {
    client_.call("nvim_win_set_cursor", nullptr, window, pos);
  }

  Integer nvim_win_get_height(Window window) {
    Integer res;
    client_.call("nvim_win_get_height", res, window);
    return res;
  }

  void nvim_win_set_height(Window window, Integer height) {
    client_.call("nvim_win_set_height", nullptr, window, height);
  }

  Integer nvim_win_get_width(Window window) {
    Integer res;
    client_.call("nvim_win_get_width", res, window);
    return res;
  }

  void nvim_win_set_width(Window window, Integer width) {
    client_.call("nvim_win_set_width", nullptr, window, width);
  }

  Object nvim_win_get_var(Window window, const std::string& name) {
    Object res;
    client_.call("nvim_win_get_var", res, window, name);
    return res;
  }

  void nvim_win_set_var(Window window, const std::string& name,
                        const Object& value) {
    client_.call("nvim_win_set_var", nullptr, window, name, value);
  }

  void nvim_win_del_var(Window window, const std::string& name) {
    client_.call("nvim_win_del_var", nullptr, window, name);
  }

  std::vector<Integer> nvim_win_get_position(Window window) {
    std::vector<Integer> res;
    client_.call("nvim_win_get_position", res, window);
    return res;
  }

  Tabpage nvim_win_get_tabpage(Window window) {
    Tabpage res;
    client_.call("nvim_win_get_tabpage", res, window);
    return res;
  }

  Integer nvim_win_get_number(Window window) {
    Integer res;
    client_.call("nvim_win_get_number", res, window);
    return res;
  }

  bool nvim_win_is_valid(Window window) {
    bool res;
    client_.call("nvim_win_is_valid", res, window);
    return res;
  }

  void nvim_win_hide(Window window) {
    client_.call("nvim_win_hide", nullptr, window);
  }

  void nvim_win_close(Window window, bool force) {
    client_.call("nvim_win_close", nullptr, window, force);
  }

  void nvim_win_set_hl_ns(Window window, Integer ns_id) {
    client_.call("nvim_win_set_hl_ns", nullptr, window, ns_id);
  }

  Integer buffer_line_count(Buffer buffer) {
    Integer res;
    client_.call("buffer_line_count", res, buffer);
    return res;
  }

  std::vector<std::string> buffer_get_lines(Buffer buffer, Integer start,
                                            Integer end, bool strict_indexing) {
    std::vector<std::string> res;
    client_.call("buffer_get_lines", res, buffer, start, end, strict_indexing);
    return res;
  }

  void buffer_set_lines(Buffer buffer, Integer start, Integer end,
                        bool strict_indexing,
                        const std::vector<std::string>& replacement) {
    client_.call("buffer_set_lines", nullptr, buffer, start, end,
                 strict_indexing, replacement);
  }

  Object buffer_get_var(Buffer buffer, const std::string& name) {
    Object res;
    client_.call("buffer_get_var", res, buffer, name);
    return res;
  }

  std::string buffer_get_name(Buffer buffer) {
    std::string res;
    client_.call("buffer_get_name", res, buffer);
    return res;
  }

  void buffer_set_name(Buffer buffer, const std::string& name) {
    client_.call("buffer_set_name", nullptr, buffer, name);
  }

  bool buffer_is_valid(Buffer buffer) {
    bool res;
    client_.call("buffer_is_valid", res, buffer);
    return res;
  }

  std::vector<Integer> buffer_get_mark(Buffer buffer, const std::string& name) {
    std::vector<Integer> res;
    client_.call("buffer_get_mark", res, buffer, name);
    return res;
  }

  std::string vim_command_output(const std::string& command) {
    std::string res;
    client_.call("vim_command_output", res, command);
    return res;
  }

  Integer buffer_get_number(Buffer buffer) {
    Integer res;
    client_.call("buffer_get_number", res, buffer);
    return res;
  }

  void buffer_clear_highlight(Buffer buffer, Integer ns_id, Integer line_start,
                              Integer line_end) {
    client_.call("buffer_clear_highlight", nullptr, buffer, ns_id, line_start,
                 line_end);
  }

  Integer buffer_add_highlight(Buffer buffer, Integer ns_id,
                               const std::string& hl_group, Integer line,
                               Integer col_start, Integer col_end) {
    Integer res;
    client_.call("buffer_add_highlight", res, buffer, ns_id, hl_group, line,
                 col_start, col_end);
    return res;
  }

  void vim_set_option(const std::string& name, const Object& value) {
    client_.call("vim_set_option", nullptr, name, value);
  }

  Object vim_get_option(const std::string& name) {
    Object res;
    client_.call("vim_get_option", res, name);
    return res;
  }

  Object buffer_get_option(Buffer buffer, const std::string& name) {
    Object res;
    client_.call("buffer_get_option", res, buffer, name);
    return res;
  }

  void buffer_set_option(Buffer buffer, const std::string& name,
                         const Object& value) {
    client_.call("buffer_set_option", nullptr, buffer, name, value);
  }

  Object window_get_option(Window window, const std::string& name) {
    Object res;
    client_.call("window_get_option", res, window, name);
    return res;
  }

  void window_set_option(Window window, const std::string& name,
                         const Object& value) {
    client_.call("window_set_option", nullptr, window, name, value);
  }

  std::vector<Window> tabpage_get_windows(Tabpage tabpage) {
    std::vector<Window> res;
    client_.call("tabpage_get_windows", res, tabpage);
    return res;
  }

  Object tabpage_get_var(Tabpage tabpage, const std::string& name) {
    Object res;
    client_.call("tabpage_get_var", res, tabpage, name);
    return res;
  }

  Window tabpage_get_window(Tabpage tabpage) {
    Window res;
    client_.call("tabpage_get_window", res, tabpage);
    return res;
  }

  bool tabpage_is_valid(Tabpage tabpage) {
    bool res;
    client_.call("tabpage_is_valid", res, tabpage);
    return res;
  }

  void ui_detach() { client_.call("ui_detach", nullptr); }

  Object ui_try_resize(Integer width, Integer height) {
    Object res;
    client_.call("ui_try_resize", res, width, height);
    return res;
  }

  void vim_feedkeys(const std::string& keys, const std::string& mode,
                    bool escape_ks) {
    client_.call("vim_feedkeys", nullptr, keys, mode, escape_ks);
  }

  Integer vim_input(const std::string& keys) {
    Integer res;
    client_.call("vim_input", res, keys);
    return res;
  }

  std::string vim_replace_termcodes(const std::string& str, bool from_part,
                                    bool do_lt, bool special) {
    std::string res;
    client_.call("vim_replace_termcodes", res, str, from_part, do_lt, special);
    return res;
  }

  Integer vim_strwidth(const std::string& text) {
    Integer res;
    client_.call("vim_strwidth", res, text);
    return res;
  }

  std::vector<std::string> vim_list_runtime_paths() {
    std::vector<std::string> res;
    client_.call("vim_list_runtime_paths", res);
    return res;
  }

  void vim_change_directory(const std::string& dir) {
    client_.call("vim_change_directory", nullptr, dir);
  }

  std::string vim_get_current_line() {
    std::string res;
    client_.call("vim_get_current_line", res);
    return res;
  }

  void vim_set_current_line(const std::string& line) {
    client_.call("vim_set_current_line", nullptr, line);
  }

  void vim_del_current_line() { client_.call("vim_del_current_line", nullptr); }

  Object vim_get_var(const std::string& name) {
    Object res;
    client_.call("vim_get_var", res, name);
    return res;
  }

  Object vim_get_vvar(const std::string& name) {
    Object res;
    client_.call("vim_get_vvar", res, name);
    return res;
  }

  void vim_out_write(const std::string& str) {
    client_.call("vim_out_write", nullptr, str);
  }

  void vim_err_write(const std::string& str) {
    client_.call("vim_err_write", nullptr, str);
  }

  void vim_report_error(const std::string& str) {
    client_.call("vim_report_error", nullptr, str);
  }

  std::vector<Buffer> vim_get_buffers() {
    std::vector<Buffer> res;
    client_.call("vim_get_buffers", res);
    return res;
  }

  Buffer vim_get_current_buffer() {
    Buffer res;
    client_.call("vim_get_current_buffer", res);
    return res;
  }

  void vim_set_current_buffer(Buffer buffer) {
    client_.call("vim_set_current_buffer", nullptr, buffer);
  }

  std::vector<Window> vim_get_windows() {
    std::vector<Window> res;
    client_.call("vim_get_windows", res);
    return res;
  }

  Window vim_get_current_window() {
    Window res;
    client_.call("vim_get_current_window", res);
    return res;
  }

  void vim_set_current_window(Window window) {
    client_.call("vim_set_current_window", nullptr, window);
  }

  std::vector<Tabpage> vim_get_tabpages() {
    std::vector<Tabpage> res;
    client_.call("vim_get_tabpages", res);
    return res;
  }

  Tabpage vim_get_current_tabpage() {
    Tabpage res;
    client_.call("vim_get_current_tabpage", res);
    return res;
  }

  void vim_set_current_tabpage(Tabpage tabpage) {
    client_.call("vim_set_current_tabpage", nullptr, tabpage);
  }

  void vim_subscribe(const std::string& event) {
    client_.call("vim_subscribe", nullptr, event);
  }

  void vim_unsubscribe(const std::string& event) {
    client_.call("vim_unsubscribe", nullptr, event);
  }

  Integer vim_name_to_color(const std::string& name) {
    Integer res;
    client_.call("vim_name_to_color", res, name);
    return res;
  }

  void vim_command(const std::string& command) {
    client_.call("vim_command", nullptr, command);
  }

  Object vim_eval(const std::string& expr) {
    Object res;
    client_.call("vim_eval", res, expr);
    return res;
  }

  Buffer window_get_buffer(Window window) {
    Buffer res;
    client_.call("window_get_buffer", res, window);
    return res;
  }

  std::vector<Integer> window_get_cursor(Window window) {
    std::vector<Integer> res;
    client_.call("window_get_cursor", res, window);
    return res;
  }

  void window_set_cursor(Window window, const std::vector<Integer>& pos) {
    client_.call("window_set_cursor", nullptr, window, pos);
  }

  Integer window_get_height(Window window) {
    Integer res;
    client_.call("window_get_height", res, window);
    return res;
  }

  void window_set_height(Window window, Integer height) {
    client_.call("window_set_height", nullptr, window, height);
  }

  Integer window_get_width(Window window) {
    Integer res;
    client_.call("window_get_width", res, window);
    return res;
  }

  void window_set_width(Window window, Integer width) {
    client_.call("window_set_width", nullptr, window, width);
  }

  Object window_get_var(Window window, const std::string& name) {
    Object res;
    client_.call("window_get_var", res, window, name);
    return res;
  }

  std::vector<Integer> window_get_position(Window window) {
    std::vector<Integer> res;
    client_.call("window_get_position", res, window);
    return res;
  }

  Tabpage window_get_tabpage(Window window) {
    Tabpage res;
    client_.call("window_get_tabpage", res, window);
    return res;
  }

  bool window_is_valid(Window window) {
    bool res;
    client_.call("window_is_valid", res, window);
    return res;
  }

 private:
  NvimRPC client_;
};

}  // namespace nvim

#endif  // NEOVIM_CPP__NVIM_HPP_
