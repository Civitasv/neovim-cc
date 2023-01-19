// Auto generated

#ifndef NEOVIM_CPP__NVIM_HPP_
#define NEOVIM_CPP__NVIM_HPP_

#include "nvim_rpc.h"
#include "type.h"

namespace nvim {

class Nvim {
 public:
  void connect_tcp(const std::string& host, const std::string& service,
                   double timeout_sec = 1.0) {
    client_.connect_tcp(host, service, timeout_sec);
  }

  std::vector<Variant> nvim_get_autocmds(
      const std::map<std::string, Variant>& opts) {
    std::vector<Variant> res;
    client_.call("nvim_get_autocmds", res, opts);
    return res;
  }

  int64_t nvim_create_autocmd(const Variant& event,
                              const std::map<std::string, Variant>& opts) {
    int64_t res;
    client_.call("nvim_create_autocmd", res, event, opts);
    return res;
  }

  void nvim_del_autocmd(int64_t id) {
    client_.call("nvim_del_autocmd", nullptr, id);
  }

  void nvim_clear_autocmds(const std::map<std::string, Variant>& opts) {
    client_.call("nvim_clear_autocmds", nullptr, opts);
  }

  int64_t nvim_create_augroup(const std::string& name,
                              const std::map<std::string, Variant>& opts) {
    int64_t res;
    client_.call("nvim_create_augroup", res, name, opts);
    return res;
  }

  void nvim_del_augroup_by_id(int64_t id) {
    client_.call("nvim_del_augroup_by_id", nullptr, id);
  }

  void nvim_del_augroup_by_name(const std::string& name) {
    client_.call("nvim_del_augroup_by_name", nullptr, name);
  }

  void nvim_exec_autocmds(const Variant& event,
                          const std::map<std::string, Variant>& opts) {
    client_.call("nvim_exec_autocmds", nullptr, event, opts);
  }

  int64_t nvim_buf_line_count(Buffer buffer) {
    int64_t res;
    client_.call("nvim_buf_line_count", res, buffer);
    return res;
  }

  bool nvim_buf_attach(Buffer buffer, bool send_buffer,
                       const std::map<std::string, Variant>& opts) {
    bool res;
    client_.call("nvim_buf_attach", res, buffer, send_buffer, opts);
    return res;
  }

  bool nvim_buf_detach(Buffer buffer) {
    bool res;
    client_.call("nvim_buf_detach", res, buffer);
    return res;
  }

  std::vector<std::string> nvim_buf_get_lines(Buffer buffer, int64_t start,
                                              int64_t end,
                                              bool strict_indexing) {
    std::vector<std::string> res;
    client_.call("nvim_buf_get_lines", res, buffer, start, end,
                 strict_indexing);
    return res;
  }

  void nvim_buf_set_lines(Buffer buffer, int64_t start, int64_t end,
                          bool strict_indexing,
                          const std::vector<std::string>& replacement) {
    client_.call("nvim_buf_set_lines", nullptr, buffer, start, end,
                 strict_indexing, replacement);
  }

  void nvim_buf_set_text(Buffer buffer, int64_t start_row, int64_t start_col,
                         int64_t end_row, int64_t end_col,
                         const std::vector<std::string>& replacement) {
    client_.call("nvim_buf_set_text", nullptr, buffer, start_row, start_col,
                 end_row, end_col, replacement);
  }

  std::vector<std::string> nvim_buf_get_text(
      Buffer buffer, int64_t start_row, int64_t start_col, int64_t end_row,
      int64_t end_col, const std::map<std::string, Variant>& opts) {
    std::vector<std::string> res;
    client_.call("nvim_buf_get_text", res, buffer, start_row, start_col,
                 end_row, end_col, opts);
    return res;
  }

  int64_t nvim_buf_get_offset(Buffer buffer, int64_t index) {
    int64_t res;
    client_.call("nvim_buf_get_offset", res, buffer, index);
    return res;
  }

  Variant nvim_buf_get_var(Buffer buffer, const std::string& name) {
    Variant res;
    client_.call("nvim_buf_get_var", res, buffer, name);
    return res;
  }

  int64_t nvim_buf_get_changedtick(Buffer buffer) {
    int64_t res;
    client_.call("nvim_buf_get_changedtick", res, buffer);
    return res;
  }

  std::vector<std::map<std::string, Variant>> nvim_buf_get_keymap(
      Buffer buffer, const std::string& mode) {
    std::vector<std::map<std::string, Variant>> res;
    client_.call("nvim_buf_get_keymap", res, buffer, mode);
    return res;
  }

  void nvim_buf_set_keymap(Buffer buffer, const std::string& mode,
                           const std::string& lhs, const std::string& rhs,
                           const std::map<std::string, Variant>& opts) {
    client_.call("nvim_buf_set_keymap", nullptr, buffer, mode, lhs, rhs, opts);
  }

  void nvim_buf_del_keymap(Buffer buffer, const std::string& mode,
                           const std::string& lhs) {
    client_.call("nvim_buf_del_keymap", nullptr, buffer, mode, lhs);
  }

  void nvim_buf_set_var(Buffer buffer, const std::string& name,
                        const Variant& value) {
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

  void nvim_buf_delete(Buffer buffer,
                       const std::map<std::string, Variant>& opts) {
    client_.call("nvim_buf_delete", nullptr, buffer, opts);
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

  bool nvim_buf_set_mark(Buffer buffer, const std::string& name, int64_t line,
                         int64_t col,
                         const std::map<std::string, Variant>& opts) {
    bool res;
    client_.call("nvim_buf_set_mark", res, buffer, name, line, col, opts);
    return res;
  }

  std::pair<int64_t, int64_t> nvim_buf_get_mark(Buffer buffer,
                                                const std::string& name) {
    std::pair<int64_t, int64_t> res;
    client_.call("nvim_buf_get_mark", res, buffer, name);
    return res;
  }

  std::map<std::string, Variant> nvim_parse_cmd(
      const std::string& str, const std::map<std::string, Variant>& opts) {
    std::map<std::string, Variant> res;
    client_.call("nvim_parse_cmd", res, str, opts);
    return res;
  }

  std::string nvim_cmd(const std::map<std::string, Variant>& cmd,
                       const std::map<std::string, Variant>& opts) {
    std::string res;
    client_.call("nvim_cmd", res, cmd, opts);
    return res;
  }

  void nvim_create_user_command(const std::string& name, const Variant& command,
                                const std::map<std::string, Variant>& opts) {
    client_.call("nvim_create_user_command", nullptr, name, command, opts);
  }

  void nvim_del_user_command(const std::string& name) {
    client_.call("nvim_del_user_command", nullptr, name);
  }

  void nvim_buf_create_user_command(
      Buffer buffer, const std::string& name, const Variant& command,
      const std::map<std::string, Variant>& opts) {
    client_.call("nvim_buf_create_user_command", nullptr, buffer, name, command,
                 opts);
  }

  void nvim_buf_del_user_command(Buffer buffer, const std::string& name) {
    client_.call("nvim_buf_del_user_command", nullptr, buffer, name);
  }

  std::map<std::string, Variant> nvim_get_commands(
      const std::map<std::string, Variant>& opts) {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_commands", res, opts);
    return res;
  }

  std::map<std::string, Variant> nvim_buf_get_commands(
      Buffer buffer, const std::map<std::string, Variant>& opts) {
    std::map<std::string, Variant> res;
    client_.call("nvim_buf_get_commands", res, buffer, opts);
    return res;
  }

  std::string nvim_command_output(const std::string& command) {
    std::string res;
    client_.call("nvim_command_output", res, command);
    return res;
  }

  Variant nvim_execute_lua(const std::string& code,
                           const std::vector<Variant>& args) {
    Variant res;
    client_.call("nvim_execute_lua", res, code, args);
    return res;
  }

  int64_t nvim_buf_get_number(Buffer buffer) {
    int64_t res;
    client_.call("nvim_buf_get_number", res, buffer);
    return res;
  }

  void nvim_buf_clear_highlight(Buffer buffer, int64_t ns_id,
                                int64_t line_start, int64_t line_end) {
    client_.call("nvim_buf_clear_highlight", nullptr, buffer, ns_id, line_start,
                 line_end);
  }

  int64_t nvim_buf_set_virtual_text(
      Buffer buffer, int64_t src_id, int64_t line,
      const std::vector<Variant>& chunks,
      const std::map<std::string, Variant>& opts) {
    int64_t res;
    client_.call("nvim_buf_set_virtual_text", res, buffer, src_id, line, chunks,
                 opts);
    return res;
  }

  void buffer_insert(Buffer buffer, int64_t lnum,
                     const std::vector<std::string>& lines) {
    client_.call("buffer_insert", nullptr, buffer, lnum, lines);
  }

  std::string buffer_get_line(Buffer buffer, int64_t index) {
    std::string res;
    client_.call("buffer_get_line", res, buffer, index);
    return res;
  }

  void buffer_set_line(Buffer buffer, int64_t index, const std::string& line) {
    client_.call("buffer_set_line", nullptr, buffer, index, line);
  }

  void buffer_del_line(Buffer buffer, int64_t index) {
    client_.call("buffer_del_line", nullptr, buffer, index);
  }

  std::vector<std::string> buffer_get_line_slice(Buffer buffer, int64_t start,
                                                 int64_t end,
                                                 bool include_start,
                                                 bool include_end) {
    std::vector<std::string> res;
    client_.call("buffer_get_line_slice", res, buffer, start, end,
                 include_start, include_end);
    return res;
  }

  void buffer_set_line_slice(Buffer buffer, int64_t start, int64_t end,
                             bool include_start, bool include_end,
                             const std::vector<std::string>& replacement) {
    client_.call("buffer_set_line_slice", nullptr, buffer, start, end,
                 include_start, include_end, replacement);
  }

  Variant buffer_set_var(Buffer buffer, const std::string& name,
                         const Variant& value) {
    Variant res;
    client_.call("buffer_set_var", res, buffer, name, value);
    return res;
  }

  Variant buffer_del_var(Buffer buffer, const std::string& name) {
    Variant res;
    client_.call("buffer_del_var", res, buffer, name);
    return res;
  }

  Variant window_set_var(Window window, const std::string& name,
                         const Variant& value) {
    Variant res;
    client_.call("window_set_var", res, window, name, value);
    return res;
  }

  Variant window_del_var(Window window, const std::string& name) {
    Variant res;
    client_.call("window_del_var", res, window, name);
    return res;
  }

  Variant tabpage_set_var(Tabpage tabpage, const std::string& name,
                          const Variant& value) {
    Variant res;
    client_.call("tabpage_set_var", res, tabpage, name, value);
    return res;
  }

  Variant tabpage_del_var(Tabpage tabpage, const std::string& name) {
    Variant res;
    client_.call("tabpage_del_var", res, tabpage, name);
    return res;
  }

  Variant vim_set_var(const std::string& name, const Variant& value) {
    Variant res;
    client_.call("vim_set_var", res, name, value);
    return res;
  }

  Variant vim_del_var(const std::string& name) {
    Variant res;
    client_.call("vim_del_var", res, name);
    return res;
  }

  int64_t nvim_create_namespace(const std::string& name) {
    int64_t res;
    client_.call("nvim_create_namespace", res, name);
    return res;
  }

  std::map<std::string, Variant> nvim_get_namespaces() {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_namespaces", res);
    return res;
  }

  std::vector<int64_t> nvim_buf_get_extmark_by_id(
      Buffer buffer, int64_t ns_id, int64_t id,
      const std::map<std::string, Variant>& opts) {
    std::vector<int64_t> res;
    client_.call("nvim_buf_get_extmark_by_id", res, buffer, ns_id, id, opts);
    return res;
  }

  std::vector<Variant> nvim_buf_get_extmarks(
      Buffer buffer, int64_t ns_id, const Variant& start, const Variant& end,
      const std::map<std::string, Variant>& opts) {
    std::vector<Variant> res;
    client_.call("nvim_buf_get_extmarks", res, buffer, ns_id, start, end, opts);
    return res;
  }

  int64_t nvim_buf_set_extmark(Buffer buffer, int64_t ns_id, int64_t line,
                               int64_t col,
                               const std::map<std::string, Variant>& opts) {
    int64_t res;
    client_.call("nvim_buf_set_extmark", res, buffer, ns_id, line, col, opts);
    return res;
  }

  bool nvim_buf_del_extmark(Buffer buffer, int64_t ns_id, int64_t id) {
    bool res;
    client_.call("nvim_buf_del_extmark", res, buffer, ns_id, id);
    return res;
  }

  int64_t nvim_buf_add_highlight(Buffer buffer, int64_t ns_id,
                                 const std::string& hl_group, int64_t line,
                                 int64_t col_start, int64_t col_end) {
    int64_t res;
    client_.call("nvim_buf_add_highlight", res, buffer, ns_id, hl_group, line,
                 col_start, col_end);
    return res;
  }

  void nvim_buf_clear_namespace(Buffer buffer, int64_t ns_id,
                                int64_t line_start, int64_t line_end) {
    client_.call("nvim_buf_clear_namespace", nullptr, buffer, ns_id, line_start,
                 line_end);
  }

  void nvim_set_decoration_provider(
      int64_t ns_id, const std::map<std::string, Variant>& opts) {
    client_.call("nvim_set_decoration_provider", nullptr, ns_id, opts);
  }

  Variant nvim_get_option_value(const std::string& name,
                                const std::map<std::string, Variant>& opts) {
    Variant res;
    client_.call("nvim_get_option_value", res, name, opts);
    return res;
  }

  void nvim_set_option_value(const std::string& name, const Variant& value,
                             const std::map<std::string, Variant>& opts) {
    client_.call("nvim_set_option_value", nullptr, name, value, opts);
  }

  std::map<std::string, Variant> nvim_get_all_options_info() {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_all_options_info", res);
    return res;
  }

  std::map<std::string, Variant> nvim_get_option_info(const std::string& name) {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_option_info", res, name);
    return res;
  }

  void nvim_set_option(const std::string& name, const Variant& value) {
    client_.call("nvim_set_option", nullptr, name, value);
  }

  Variant nvim_get_option(const std::string& name) {
    Variant res;
    client_.call("nvim_get_option", res, name);
    return res;
  }

  Variant nvim_buf_get_option(Buffer buffer, const std::string& name) {
    Variant res;
    client_.call("nvim_buf_get_option", res, buffer, name);
    return res;
  }

  void nvim_buf_set_option(Buffer buffer, const std::string& name,
                           const Variant& value) {
    client_.call("nvim_buf_set_option", nullptr, buffer, name, value);
  }

  Variant nvim_win_get_option(Window window, const std::string& name) {
    Variant res;
    client_.call("nvim_win_get_option", res, window, name);
    return res;
  }

  void nvim_win_set_option(Window window, const std::string& name,
                           const Variant& value) {
    client_.call("nvim_win_set_option", nullptr, window, name, value);
  }

  std::vector<Window> nvim_tabpage_list_wins(Tabpage tabpage) {
    std::vector<Window> res;
    client_.call("nvim_tabpage_list_wins", res, tabpage);
    return res;
  }

  Variant nvim_tabpage_get_var(Tabpage tabpage, const std::string& name) {
    Variant res;
    client_.call("nvim_tabpage_get_var", res, tabpage, name);
    return res;
  }

  void nvim_tabpage_set_var(Tabpage tabpage, const std::string& name,
                            const Variant& value) {
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

  int64_t nvim_tabpage_get_number(Tabpage tabpage) {
    int64_t res;
    client_.call("nvim_tabpage_get_number", res, tabpage);
    return res;
  }

  bool nvim_tabpage_is_valid(Tabpage tabpage) {
    bool res;
    client_.call("nvim_tabpage_is_valid", res, tabpage);
    return res;
  }

  void nvim_ui_attach(int64_t width, int64_t height,
                      const std::map<std::string, Variant>& options) {
    client_.call("nvim_ui_attach", nullptr, width, height, options);
  }

  void ui_attach(int64_t width, int64_t height, bool enable_rgb) {
    client_.call("ui_attach", nullptr, width, height, enable_rgb);
  }

  void nvim_ui_set_focus(bool gained) {
    client_.call("nvim_ui_set_focus", nullptr, gained);
  }

  void nvim_ui_detach() { client_.call("nvim_ui_detach", nullptr); }

  void nvim_ui_try_resize(int64_t width, int64_t height) {
    client_.call("nvim_ui_try_resize", nullptr, width, height);
  }

  void nvim_ui_set_option(const std::string& name, const Variant& value) {
    client_.call("nvim_ui_set_option", nullptr, name, value);
  }

  void nvim_ui_try_resize_grid(int64_t grid, int64_t width, int64_t height) {
    client_.call("nvim_ui_try_resize_grid", nullptr, grid, width, height);
  }

  void nvim_ui_pum_set_height(int64_t height) {
    client_.call("nvim_ui_pum_set_height", nullptr, height);
  }

  void nvim_ui_pum_set_bounds(double width, double height, double row,
                              double col) {
    client_.call("nvim_ui_pum_set_bounds", nullptr, width, height, row, col);
  }

  std::map<std::string, Variant> nvim_get_hl_by_name(const std::string& name,
                                                     bool rgb) {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_hl_by_name", res, name, rgb);
    return res;
  }

  std::map<std::string, Variant> nvim_get_hl_by_id(int64_t hl_id, bool rgb) {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_hl_by_id", res, hl_id, rgb);
    return res;
  }

  int64_t nvim_get_hl_id_by_name(const std::string& name) {
    int64_t res;
    client_.call("nvim_get_hl_id_by_name", res, name);
    return res;
  }

  void nvim_set_hl(int64_t ns_id, const std::string& name,
                   const std::map<std::string, Variant>& val) {
    client_.call("nvim_set_hl", nullptr, ns_id, name, val);
  }

  void nvim_set_hl_ns(int64_t ns_id) {
    client_.call("nvim_set_hl_ns", nullptr, ns_id);
  }

  void nvim_set_hl_ns_fast(int64_t ns_id) {
    client_.call("nvim_set_hl_ns_fast", nullptr, ns_id);
  }

  void nvim_feedkeys(const std::string& keys, const std::string& mode,
                     bool escape_ks) {
    client_.call("nvim_feedkeys", nullptr, keys, mode, escape_ks);
  }

  int64_t nvim_input(const std::string& keys) {
    int64_t res;
    client_.call("nvim_input", res, keys);
    return res;
  }

  void nvim_input_mouse(const std::string& button, const std::string& action,
                        const std::string& modifier, int64_t grid, int64_t row,
                        int64_t col) {
    client_.call("nvim_input_mouse", nullptr, button, action, modifier, grid,
                 row, col);
  }

  std::string nvim_replace_termcodes(const std::string& str, bool from_part,
                                     bool do_lt, bool special) {
    std::string res;
    client_.call("nvim_replace_termcodes", res, str, from_part, do_lt, special);
    return res;
  }

  Variant nvim_exec_lua(const std::string& code,
                        const std::vector<Variant>& args) {
    Variant res;
    client_.call("nvim_exec_lua", res, code, args);
    return res;
  }

  Variant nvim_notify(const std::string& msg, int64_t log_level,
                      const std::map<std::string, Variant>& opts) {
    Variant res;
    client_.call("nvim_notify", res, msg, log_level, opts);
    return res;
  }

  int64_t nvim_strwidth(const std::string& text) {
    int64_t res;
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

  Variant nvim_get_var(const std::string& name) {
    Variant res;
    client_.call("nvim_get_var", res, name);
    return res;
  }

  void nvim_set_var(const std::string& name, const Variant& value) {
    client_.call("nvim_set_var", nullptr, name, value);
  }

  void nvim_del_var(const std::string& name) {
    client_.call("nvim_del_var", nullptr, name);
  }

  Variant nvim_get_vvar(const std::string& name) {
    Variant res;
    client_.call("nvim_get_vvar", res, name);
    return res;
  }

  void nvim_set_vvar(const std::string& name, const Variant& value) {
    client_.call("nvim_set_vvar", nullptr, name, value);
  }

  void nvim_echo(const std::vector<Variant>& chunks, bool history,
                 const std::map<std::string, Variant>& opts) {
    client_.call("nvim_echo", nullptr, chunks, history, opts);
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

  int64_t nvim_open_term(Buffer buffer,
                         const std::map<std::string, Variant>& opts) {
    int64_t res;
    client_.call("nvim_open_term", res, buffer, opts);
    return res;
  }

  void nvim_chan_send(int64_t chan, const std::string& data) {
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

  bool nvim_paste(const std::string& data, bool crlf, int64_t phase) {
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

  int64_t nvim_get_color_by_name(const std::string& name) {
    int64_t res;
    client_.call("nvim_get_color_by_name", res, name);
    return res;
  }

  std::map<std::string, Variant> nvim_get_color_map() {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_color_map", res);
    return res;
  }

  std::map<std::string, Variant> nvim_get_context(
      const std::map<std::string, Variant>& opts) {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_context", res, opts);
    return res;
  }

  Variant nvim_load_context(const std::map<std::string, Variant>& dict) {
    Variant res;
    client_.call("nvim_load_context", res, dict);
    return res;
  }

  std::map<std::string, Variant> nvim_get_mode() {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_mode", res);
    return res;
  }

  std::vector<std::map<std::string, Variant>> nvim_get_keymap(
      const std::string& mode) {
    std::vector<std::map<std::string, Variant>> res;
    client_.call("nvim_get_keymap", res, mode);
    return res;
  }

  void nvim_set_keymap(const std::string& mode, const std::string& lhs,
                       const std::string& rhs,
                       const std::map<std::string, Variant>& opts) {
    client_.call("nvim_set_keymap", nullptr, mode, lhs, rhs, opts);
  }

  void nvim_del_keymap(const std::string& mode, const std::string& lhs) {
    client_.call("nvim_del_keymap", nullptr, mode, lhs);
  }

  std::vector<Variant> nvim_get_api_info() {
    std::vector<Variant> res;
    client_.call("nvim_get_api_info", res);
    return res;
  }

  void nvim_set_client_info(const std::string& name,
                            const std::map<std::string, Variant>& version,
                            const std::string& type,
                            const std::map<std::string, Variant>& methods,
                            const std::map<std::string, Variant>& attributes) {
    client_.call("nvim_set_client_info", nullptr, name, version, type, methods,
                 attributes);
  }

  std::map<std::string, Variant> nvim_get_chan_info(int64_t chan) {
    std::map<std::string, Variant> res;
    client_.call("nvim_get_chan_info", res, chan);
    return res;
  }

  std::vector<Variant> nvim_list_chans() {
    std::vector<Variant> res;
    client_.call("nvim_list_chans", res);
    return res;
  }

  std::vector<Variant> nvim_call_atomic(const std::vector<Variant>& calls) {
    std::vector<Variant> res;
    client_.call("nvim_call_atomic", res, calls);
    return res;
  }

  std::vector<Variant> nvim_list_uis() {
    std::vector<Variant> res;
    client_.call("nvim_list_uis", res);
    return res;
  }

  std::vector<Variant> nvim_get_proc_children(int64_t pid) {
    std::vector<Variant> res;
    client_.call("nvim_get_proc_children", res, pid);
    return res;
  }

  Variant nvim_get_proc(int64_t pid) {
    Variant res;
    client_.call("nvim_get_proc", res, pid);
    return res;
  }

  void nvim_select_popupmenu_item(int64_t item, bool insert, bool finish,
                                  const std::map<std::string, Variant>& opts) {
    client_.call("nvim_select_popupmenu_item", nullptr, item, insert, finish,
                 opts);
  }

  bool nvim_del_mark(const std::string& name) {
    bool res;
    client_.call("nvim_del_mark", res, name);
    return res;
  }

  std::vector<Variant> nvim_get_mark(
      const std::string& name, const std::map<std::string, Variant>& opts) {
    std::vector<Variant> res;
    client_.call("nvim_get_mark", res, name, opts);
    return res;
  }

  std::map<std::string, Variant> nvim_eval_statusline(
      const std::string& str, const std::map<std::string, Variant>& opts) {
    std::map<std::string, Variant> res;
    client_.call("nvim_eval_statusline", res, str, opts);
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

  Variant nvim_eval(const std::string& expr) {
    Variant res;
    client_.call("nvim_eval", res, expr);
    return res;
  }

  Variant nvim_call_function(const std::string& fn,
                             const std::vector<Variant>& args) {
    Variant res;
    client_.call("nvim_call_function", res, fn, args);
    return res;
  }

  Variant nvim_call_dict_function(const Variant& dict, const std::string& fn,
                                  const std::vector<Variant>& args) {
    Variant res;
    client_.call("nvim_call_dict_function", res, dict, fn, args);
    return res;
  }

  std::map<std::string, Variant> nvim_parse_expression(const std::string& expr,
                                                       const std::string& flags,
                                                       bool highlight) {
    std::map<std::string, Variant> res;
    client_.call("nvim_parse_expression", res, expr, flags, highlight);
    return res;
  }

  Window nvim_open_win(Buffer buffer, bool enter,
                       const std::map<std::string, Variant>& config) {
    Window res;
    client_.call("nvim_open_win", res, buffer, enter, config);
    return res;
  }

  void nvim_win_set_config(Window window,
                           const std::map<std::string, Variant>& config) {
    client_.call("nvim_win_set_config", nullptr, window, config);
  }

  std::map<std::string, Variant> nvim_win_get_config(Window window) {
    std::map<std::string, Variant> res;
    client_.call("nvim_win_get_config", res, window);
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

  std::pair<int64_t, int64_t> nvim_win_get_cursor(Window window) {
    std::pair<int64_t, int64_t> res;
    client_.call("nvim_win_get_cursor", res, window);
    return res;
  }

  void nvim_win_set_cursor(Window window,
                           const std::pair<int64_t, int64_t>& pos) {
    client_.call("nvim_win_set_cursor", nullptr, window, pos);
  }

  int64_t nvim_win_get_height(Window window) {
    int64_t res;
    client_.call("nvim_win_get_height", res, window);
    return res;
  }

  void nvim_win_set_height(Window window, int64_t height) {
    client_.call("nvim_win_set_height", nullptr, window, height);
  }

  int64_t nvim_win_get_width(Window window) {
    int64_t res;
    client_.call("nvim_win_get_width", res, window);
    return res;
  }

  void nvim_win_set_width(Window window, int64_t width) {
    client_.call("nvim_win_set_width", nullptr, window, width);
  }

  Variant nvim_win_get_var(Window window, const std::string& name) {
    Variant res;
    client_.call("nvim_win_get_var", res, window, name);
    return res;
  }

  void nvim_win_set_var(Window window, const std::string& name,
                        const Variant& value) {
    client_.call("nvim_win_set_var", nullptr, window, name, value);
  }

  void nvim_win_del_var(Window window, const std::string& name) {
    client_.call("nvim_win_del_var", nullptr, window, name);
  }

  std::pair<int64_t, int64_t> nvim_win_get_position(Window window) {
    std::pair<int64_t, int64_t> res;
    client_.call("nvim_win_get_position", res, window);
    return res;
  }

  Tabpage nvim_win_get_tabpage(Window window) {
    Tabpage res;
    client_.call("nvim_win_get_tabpage", res, window);
    return res;
  }

  int64_t nvim_win_get_number(Window window) {
    int64_t res;
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

  void nvim_win_set_hl_ns(Window window, int64_t ns_id) {
    client_.call("nvim_win_set_hl_ns", nullptr, window, ns_id);
  }

  int64_t buffer_line_count(Buffer buffer) {
    int64_t res;
    client_.call("buffer_line_count", res, buffer);
    return res;
  }

  std::vector<std::string> buffer_get_lines(Buffer buffer, int64_t start,
                                            int64_t end, bool strict_indexing) {
    std::vector<std::string> res;
    client_.call("buffer_get_lines", res, buffer, start, end, strict_indexing);
    return res;
  }

  void buffer_set_lines(Buffer buffer, int64_t start, int64_t end,
                        bool strict_indexing,
                        const std::vector<std::string>& replacement) {
    client_.call("buffer_set_lines", nullptr, buffer, start, end,
                 strict_indexing, replacement);
  }

  Variant buffer_get_var(Buffer buffer, const std::string& name) {
    Variant res;
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

  std::pair<int64_t, int64_t> buffer_get_mark(Buffer buffer,
                                              const std::string& name) {
    std::pair<int64_t, int64_t> res;
    client_.call("buffer_get_mark", res, buffer, name);
    return res;
  }

  std::string vim_command_output(const std::string& command) {
    std::string res;
    client_.call("vim_command_output", res, command);
    return res;
  }

  int64_t buffer_get_number(Buffer buffer) {
    int64_t res;
    client_.call("buffer_get_number", res, buffer);
    return res;
  }

  void buffer_clear_highlight(Buffer buffer, int64_t ns_id, int64_t line_start,
                              int64_t line_end) {
    client_.call("buffer_clear_highlight", nullptr, buffer, ns_id, line_start,
                 line_end);
  }

  int64_t buffer_add_highlight(Buffer buffer, int64_t ns_id,
                               const std::string& hl_group, int64_t line,
                               int64_t col_start, int64_t col_end) {
    int64_t res;
    client_.call("buffer_add_highlight", res, buffer, ns_id, hl_group, line,
                 col_start, col_end);
    return res;
  }

  void vim_set_option(const std::string& name, const Variant& value) {
    client_.call("vim_set_option", nullptr, name, value);
  }

  Variant vim_get_option(const std::string& name) {
    Variant res;
    client_.call("vim_get_option", res, name);
    return res;
  }

  Variant buffer_get_option(Buffer buffer, const std::string& name) {
    Variant res;
    client_.call("buffer_get_option", res, buffer, name);
    return res;
  }

  void buffer_set_option(Buffer buffer, const std::string& name,
                         const Variant& value) {
    client_.call("buffer_set_option", nullptr, buffer, name, value);
  }

  Variant window_get_option(Window window, const std::string& name) {
    Variant res;
    client_.call("window_get_option", res, window, name);
    return res;
  }

  void window_set_option(Window window, const std::string& name,
                         const Variant& value) {
    client_.call("window_set_option", nullptr, window, name, value);
  }

  std::vector<Window> tabpage_get_windows(Tabpage tabpage) {
    std::vector<Window> res;
    client_.call("tabpage_get_windows", res, tabpage);
    return res;
  }

  Variant tabpage_get_var(Tabpage tabpage, const std::string& name) {
    Variant res;
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

  Variant ui_try_resize(int64_t width, int64_t height) {
    Variant res;
    client_.call("ui_try_resize", res, width, height);
    return res;
  }

  void vim_feedkeys(const std::string& keys, const std::string& mode,
                    bool escape_ks) {
    client_.call("vim_feedkeys", nullptr, keys, mode, escape_ks);
  }

  int64_t vim_input(const std::string& keys) {
    int64_t res;
    client_.call("vim_input", res, keys);
    return res;
  }

  std::string vim_replace_termcodes(const std::string& str, bool from_part,
                                    bool do_lt, bool special) {
    std::string res;
    client_.call("vim_replace_termcodes", res, str, from_part, do_lt, special);
    return res;
  }

  int64_t vim_strwidth(const std::string& text) {
    int64_t res;
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

  Variant vim_get_var(const std::string& name) {
    Variant res;
    client_.call("vim_get_var", res, name);
    return res;
  }

  Variant vim_get_vvar(const std::string& name) {
    Variant res;
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

  int64_t vim_name_to_color(const std::string& name) {
    int64_t res;
    client_.call("vim_name_to_color", res, name);
    return res;
  }

  std::map<std::string, Variant> vim_get_color_map() {
    std::map<std::string, Variant> res;
    client_.call("vim_get_color_map", res);
    return res;
  }

  std::vector<Variant> vim_get_api_info() {
    std::vector<Variant> res;
    client_.call("vim_get_api_info", res);
    return res;
  }

  void vim_command(const std::string& command) {
    client_.call("vim_command", nullptr, command);
  }

  Variant vim_eval(const std::string& expr) {
    Variant res;
    client_.call("vim_eval", res, expr);
    return res;
  }

  Variant vim_call_function(const std::string& fn,
                            const std::vector<Variant>& args) {
    Variant res;
    client_.call("vim_call_function", res, fn, args);
    return res;
  }

  Buffer window_get_buffer(Window window) {
    Buffer res;
    client_.call("window_get_buffer", res, window);
    return res;
  }

  std::pair<int64_t, int64_t> window_get_cursor(Window window) {
    std::pair<int64_t, int64_t> res;
    client_.call("window_get_cursor", res, window);
    return res;
  }

  void window_set_cursor(Window window,
                         const std::pair<int64_t, int64_t>& pos) {
    client_.call("window_set_cursor", nullptr, window, pos);
  }

  int64_t window_get_height(Window window) {
    int64_t res;
    client_.call("window_get_height", res, window);
    return res;
  }

  void window_set_height(Window window, int64_t height) {
    client_.call("window_set_height", nullptr, window, height);
  }

  int64_t window_get_width(Window window) {
    int64_t res;
    client_.call("window_get_width", res, window);
    return res;
  }

  void window_set_width(Window window, int64_t width) {
    client_.call("window_set_width", nullptr, window, width);
  }

  Variant window_get_var(Window window, const std::string& name) {
    Variant res;
    client_.call("window_get_var", res, window, name);
    return res;
  }

  std::pair<int64_t, int64_t> window_get_position(Window window) {
    std::pair<int64_t, int64_t> res;
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
