#include <iostream>
#include <fstream>

#include "gitgut.hpp"
#include "common.hpp"

void Gitgut::init()
{
    std::cout << "Initialized empty Gitgut repository in /.git/\n";
    std::filesystem::create_directories("./.git/objects");
    std::filesystem::create_directories("./.git/refs/heads");
    std::filesystem::create_directories("./.git/refs/tags");
    std::filesystem::create_directories("./.git/branches");

    initFiles();
}

void Gitgut::initFiles()
{
    initDescription();
    initHead();
    initConfig();
}

void Gitgut::initDescription()
{
    const std::string filename = "description";
    const std::string content = "Unnamed repository; edit this file 'description' to name the repository.\n";
    writeToFile(filename, rootPath, content);
}

void Gitgut::initHead()
{
    const std::string filename = "HEAD";
    const std::string content = "ref: refs/heads/master\n";
    writeToFile(filename, rootPath, content);
}

void Gitgut::initConfig()
{
    const std::string filename = "config";
    std::stringstream content;
    content << "[core]\n";
    content << "\trepositoryformatversion = 0\n";
    content << "\tfilemode = true\n";
    content << "\tbare = false\n";
    content << "\tlogallrefupdates = true\n";
    writeToFile(filename, rootPath, content.str());
}