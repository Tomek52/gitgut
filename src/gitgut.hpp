#pragma once
#include <filesystem>

class Gitgut
{
    const std::filesystem::path rootPath{"./.git/"};

    void initFiles();
    void initDescription();
    void initHead();
    void initConfig();

public:
    void init();
};
