#include "Tree.h"

#include <boost/filesystem.hpp>

using boost::filesystem::exists;
using boost::filesystem::is_directory;
using boost::filesystem::path;
using boost::filesystem::directory_iterator;

FileNode GetTree(const std::string& path, bool dirs_only) {
  FileNode answer;
  if (!exists(path)) {
    throw std::invalid_argument("Path not exist");
  }

  if (!is_directory(path)) {
    throw std::invalid_argument("Path is not directory");
  }
  answer.name = boost::filesystem::path(path).filename().string();
  answer.is_dir = true;
  for (auto& child: directory_iterator(path)) {
    if (is_directory(child)){
      answer.children.push_back(
          GetTree(boost::filesystem::path(child).string(), dirs_only)
      );
    } else {
      if (dirs_only) {
        continue;
      }
      answer.children.push_back({
        boost::filesystem::path(child).filename().string(), false, {}
      });
    }
  }
  return answer;
}

bool operator == (const FileNode& f1, const FileNode& f2) {
  return f1.name == f2.name && f1.is_dir == f2.is_dir && f1.children == f2.children;
}

