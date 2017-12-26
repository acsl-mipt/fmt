/*
 Formatting library for C++ - locale support

 Copyright (c) 2012 - 2016, Victor Zverovich
 All rights reserved.

 For the license information refer to format.h.
 */

#include "fmt/format.h"
#include <locale>

namespace fmt {
class locale {
 private:
  std::locale locale_;

 public:
  explicit locale(std::locale loc = std::locale()) : locale_(loc) {}
  std::locale get() { return locale_; }
};

template <typename T>
locale basic_buffer<T>::locale() const { return fmt::locale(); }
}