#include <gtest/gtest.h>
#include "gitgut.hpp"
#include "common.hpp"
#include <fstream>


struct GitgutTests : public ::testing::Test
{
    Gitgut gitgut;
};

TEST_F(GitgutTests, testInitDescriptionFile)
{
    //GIVEN
    const std::filesystem::path filePath = "./.git/description";
    //WHEN
    gitgut.init();
    std::ifstream file(filePath);
    std::string fileContent;
    //THEN
    ASSERT_TRUE(file.is_open());
    std::getline(file, fileContent);
    file.close();
    ASSERT_EQ("Unnamed repository; edit this file 'description' to name the repository.", fileContent);
}

TEST_F(GitgutTests, testInitHeadFile)
{
    //GIVEN
    const std::filesystem::path filePath = "./.git/HEAD";
    //WHEN
    gitgut.init();
    std::ifstream file(filePath);
    std::string fileContent;
    //THEN
    ASSERT_TRUE(file.is_open());
    std::getline(file, fileContent);
    file.close();
    ASSERT_EQ("ref: refs/heads/master", fileContent);
}

TEST_F(GitgutTests, testInitConfigFile)
{
    //GIVEN
    const std::filesystem::path filePath = "./.git/config";
    //WHEN
    gitgut.init();
    std::ifstream file(filePath);
    std::string fileContent;
    //THEN
    ASSERT_TRUE(file.is_open());
    std::getline(file, fileContent);
    ASSERT_EQ("[core]", fileContent);
    std::getline(file, fileContent);
    ASSERT_EQ("\trepositoryformatversion = 0", fileContent);
    std::getline(file, fileContent);
    ASSERT_EQ("\tfilemode = true", fileContent);
    std::getline(file, fileContent);
    ASSERT_EQ("\tbare = false", fileContent);
    std::getline(file, fileContent);
    ASSERT_EQ("\tlogallrefupdates = true", fileContent);
    file.close();
}