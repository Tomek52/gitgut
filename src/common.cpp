#include "common.hpp"
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

void writeToFile(const std::string filename, std::filesystem::path path, const std::string content)
{
    path /= filename;
    std::ofstream s(path);
    if (!s.is_open()) {
    std::cout << "failed to open " << filename << '\n';
    }
    else {
        s << content;
        s.close();
    }
}