#include "Cirno/Application.hpp"
#include "Cirno/Logger.hpp"
#include "spdlog/common.h"

extern Cirno::Application *Cirno::CreateApplication();

int main(int, char **)
{

    auto *app = Cirno::CreateApplication();
    app->Run();
    delete app;
}