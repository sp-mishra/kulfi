#pragma once
#ifndef FILESYSTEMUTILS_HPP
#define FILESYSTEMUTILS_HPP
#include <filesystem>
#include <fstream>
#include <models/Status.hpp>
#include <constants/GeneralConstants.hpp>
#include <sstream>

namespace grkl {
class FileSystemUtils {
public:
  static Status readFileToString(filesystem::path const &path,
                                 string &content) {
    namespace fs = filesystem;
    Status status;
    if (fs::exists(path) && fs::is_regular_file(path)) {
      const ifstream file(path);
      if (file.good()) {
        auto ss = ostringstream{};
        ss << file.rdbuf();
        content = ss.str();
        status.setMessage(GeneralConstants::SUCCESS);
        status.setSuccess(true);
      }
    }
    return status;
  }
};
} // namespace grkl
#endif // FILESYSTEMUTILS_HPP
