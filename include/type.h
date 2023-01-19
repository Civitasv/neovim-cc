#ifndef NEOVIM_CC__TYPE_H_
#define NEOVIM_CC__TYPE_H_

#include <string>

#include "msgpack.hpp"

using Window = int64_t;
using Buffer = int64_t;
using Tabpage = int64_t;
using Variant = msgpack::type::variant;

#endif
