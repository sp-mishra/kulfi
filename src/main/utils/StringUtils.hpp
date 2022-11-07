#pragma once
#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP
#include <string>
#include <magic_enum.hpp>

namespace grkl {
  class StringUtils {
  public:
    template<class T>
    [[nodiscard]] inline static std::string enumToString(T const val) {
      return magic_enum::enum_name(val);
    }

    template<class T>
    [[nodiscard]] inline T stringToEnum(std::string const& s) {
      return magic_enum::enum_cast<T>(s);
    }
  };
}
#endif //STRINGUTILS_HPP
