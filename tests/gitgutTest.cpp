#include <gtest/gtest.h>
#include "gitgut.hpp"
#include <fstream>

namespace help_message
{
    const std::string line1 = "\n";
    const std::string line2 = "Gitgut - version control system\n\n";
    const std::string line3 = "Supported commands:\n";
    const std::string line4 = "--help -h    print Gitgut info\n";
    const std::string line5 = "     init    initialize Gitgut repo\n";
    const std::string line6 = "\n";
    const std::string all = line1 + line2 + line3 + line4 + line5 + line6;
}

const std::string initMessage = "Initialized empty Gitgut repository in /.git/\n";


struct GitgutTests : public ::testing::Test
{
    Gitgut gitgut;
};

TEST_F(GitgutTests, testCommandLineArgs_HelpMessage)
{
    //GIVEN
    char* input[] = {(char*)"./gitgut", (char*)"-h"};
    //WHEN
    testing::internal::CaptureStdout();
    handleCommandLineArgs(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ(help_message::all, output);
}

TEST_F(GitgutTests, testCommandLineArgs_HelpMessageLong)
{
    //GIVEN
    char* input[] = {(char*)"./gitgut", (char*)"--help"};
    //WHEN
    testing::internal::CaptureStdout();
    handleCommandLineArgs(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ(help_message::all, output);
}

TEST_F(GitgutTests, testCommandLineArgs_initMessage)
{
    //GIVEN
    char* input[] = {(char*)"./gitgut", (char*)"init"};
    //WHEN
    testing::internal::CaptureStdout();
    handleCommandLineArgs(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ(initMessage, output);
}

TEST_F(GitgutTests, testCommandLineArgs_initDescriptionFile)
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

TEST_F(GitgutTests, testCommandLineArgs_initHeadFile)
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

TEST_F(GitgutTests, testCommandLineArgs_initConfigFile)
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