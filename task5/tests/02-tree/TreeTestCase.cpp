#include "TreeTestCase.h"

FileNode TreeTestCase::GetFileTree(const std::string& path, bool dirs_only) {
    return GetTree(path, dirs_only);
}

TEST(TreeTestCase, PathNotFound) {
    ASSERT_THROW(TreeTestCase::GetFileTree("/bla_bla_blAA", false), std::invalid_argument);
}

TEST(TreeTestCase, IsDirectory) {
    std::string dir_name_ = __FILE__;
    ASSERT_THROW(TreeTestCase::GetFileTree(dir_name_, false), std::invalid_argument);
}

TEST(TreeTestCase, FileNodeName) {
    std::string dir_name_ = __FILE__;
    dir_name_ = dir_name_.substr(0, dir_name_.rfind('/'));
    auto curr_path_ = boost::filesystem::path(dir_name_);
    FileNode f_node_ = TreeTestCase::GetFileTree(curr_path_.string(), true);
    ASSERT_EQ(curr_path_.filename().string(), f_node_.name);
}

TEST(TreeTestCase, FileNodeIsDir) {
    std::string dir_name_ = __FILE__;
    dir_name_ = dir_name_.substr(0, dir_name_.rfind('/'));
    auto curr_path_ = boost::filesystem::path(dir_name_);
    FileNode f_node_ = TreeTestCase::GetFileTree(curr_path_.string(), true);
    ASSERT_TRUE(f_node_.is_dir);
}

TEST(TreeTestCase, FileNodeChildren) {
    std::string dir_name_ = __FILE__;
    dir_name_ = dir_name_.substr(0, dir_name_.rfind('/'));
    dir_name_ = dir_name_.substr(0, dir_name_.rfind('/'));
    auto curr_path_ = boost::filesystem::path(dir_name_);

    FileNode f_node_ = TreeTestCase::GetFileTree(curr_path_.string(), false);

    std::vector<std::string> names;
    for (const auto& fNode : f_node_.children) {
        names.push_back(fNode.name);
    }

    std::sort(names.begin(), names.end());
    bool ans = false;

    if ("00-aplusb" == names[0] && 
        "01-simple-library" == names[1] && 
        "02-tree" == names[2] && 
        "03-weather" == names[3]) {
        ans = true;
    }

    ASSERT_TRUE(ans);
}

TEST(TreeTestCase, ComparisonOperatorEquality) {
    auto curr_path_ = boost::filesystem::current_path();
    FileNode f_node_ = TreeTestCase::GetFileTree(curr_path_.c_str(), true);

    ASSERT_TRUE(f_node_ == f_node_);
}

TEST(TreeTestCase, ComparisonOperatorInequality) {
    auto curr_path_ = boost::filesystem::current_path();
    FileNode f_node_1 = TreeTestCase::GetFileTree(curr_path_.c_str(), true);
    curr_path_ += "/..";
    FileNode f_node_2 = TreeTestCase::GetFileTree(curr_path_.c_str(), true);
    ASSERT_FALSE(f_node_1 == f_node_2);
}
