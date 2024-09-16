#include "Cirno/Application.hpp"
#include "Cirno/Logger.hpp"

extern Cirno::Application *Cirno::CreateApplication();

int main(int, char **)
{
    Cirno::Logger::Init();
    INTERNAL_DEBUG("Logger initialized");

    auto *app = Cirno::CreateApplication();
    app->Run();
    delete app;
}