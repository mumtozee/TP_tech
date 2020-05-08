#pragma once

#include <vector>
#include <string>

struct FileNode {
  std::string name;
  bool is_dir;
  std::vector<FileNode> children;
};

FileNode GetTree(const std::string& path, bool dirs_only);

bool operator == (const FileNode& f1, const FileNode& f2);