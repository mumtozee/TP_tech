#ifndef TREE_TEST_CASE
#define TREE_TEST_CASE

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>

#include "Tree.h"

using namespace boost::filesystem;

class TreeTestCase : public ::testing::Test {
public:
    static FileNode GetFileTree(const std::string& path, bool dirs_only);
};

#endif
