#pragma once
#ifndef STATUSCONSTANTS_HPP
#define STATUSCONSTANTS_HPP
#include <cstdint>
namespace grkl {
  enum class StatusConstants : std::uint8_t {
    SUCCESS,
    FAILED,
    ABORTED,
  };
}

#endif //STATUSCONSTANTS_HPP
