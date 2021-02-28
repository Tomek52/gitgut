#include <iostream>
#include <sstream>
#include "gitgut.hpp"

int main(int argc, char* argv[])
{
    try
    {
        handleCommandLineArgs(argc, argv);
    }
    catch (...)
    {
    }
    return 0;
}
