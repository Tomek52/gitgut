#pragma once
#include <filesystem>

void handleCommandLineArgs(int argc, char* argv[]);
void writeToFile(const std::string, std::filesystem::path, const std::string);