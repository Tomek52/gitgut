#include <gtest/gtest.h>
#include <fstream>
#include "common.hpp"

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

struct CommonTests : public ::testing::Test
{
};

TEST_F(CommonTests, testCommandLineArgs_HelpMessage)
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

TEST_F(CommonTests, testCommandLineArgs_HelpMessageLong)
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

TEST_F(CommonTests, testCommandLineArgs_initMessage)
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

TEST_F(CommonTests, testWriteToFileFunction)
{
    //GIVEN
    const std::string fileName = "Gitgut.txt";
    const std::string fileContentWrite = "Gitgut\n";
    const std::string expectedContent = "Gitgut";
    //WHEN
    std::ifstream file(fileName);
    writeToFile(fileName, ".", fileContentWrite);
    //THEN
    ASSERT_TRUE(file.is_open());
    std::string fileContentRead = "Gitgut";
    std::getline(file, fileContentRead);
    file.close();
    ASSERT_EQ(expectedContent, fileContentRead);
}