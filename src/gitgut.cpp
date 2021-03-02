#include "gitgut.hpp"
#include <iostream>
#include <fstream>

void handleCommandLineArgs(int argc, char* argv[])
{
    Gitgut gitgut;
    bool incorrectArgs = false;
    if (argc == 2)
    {
        std::string str(argv[1]);
        if (str == "-h" or str == "--help")
        {
            std::stringstream helpInfo;
            helpInfo << std::endl;
            helpInfo << "Gitgut - version control system\n\n";
            helpInfo << "Supported commands:\n";
            helpInfo << "--help -h    print Gitgut info\n";
            helpInfo << "     init    initialize Gitgut repo\n";
            helpInfo << std::endl;
            std::cout << helpInfo.str();
        }
        else if(str == "init")
        {
            gitgut.init();
        }
        else
        {
            incorrectArgs = true;
        }
    }
    else
    {
        incorrectArgs = true;
    }

    if(incorrectArgs)
    {
        std::cout << "Incorrect arguments, run gitgut --help for more info\n";
    }
}

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
    std::filesystem::path path = rootPath;
    path /= filename;
    std::ofstream s(path);
    if (!s.is_open()) {
    std::cout << "failed to open " << filename << '\n';
    }
    else {
        s << "Unnamed repository; edit this file 'description' to name the repository.\n";
        s.close();
    }
}

void Gitgut::initHead()
{
    const std::string filename = "HEAD";
    std::filesystem::path path = rootPath;
    path /= filename;
    std::ofstream s(path);
    if (!s.is_open()) {
    std::cout << "failed to open " << filename << '\n';
    }
    else {
        s << "ref: refs/heads/master\n";
        s.close();
    }
}

void Gitgut::initConfig()
{
    const std::string filename = "config";
    std::filesystem::path path = rootPath;
    path /= filename;
    std::ofstream s(path);
    if (!s.is_open()) {
    std::cout << "failed to open " << filename << '\n';
    }
    else {
        s << "[core]\n";
        s << "\trepositoryformatversion = 0\n";
        s << "\tfilemode = true\n";
        s << "\tbare = false\n";
        s << "\tlogallrefupdates = true\n";
        s.close();
    }
}
