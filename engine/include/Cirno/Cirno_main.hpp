#include "Cirno/Logger.hpp"
#include "Cirno/Application.hpp"

extern Cirno::Application *Cirno::CreateApplication();

int main(int, char **)
{
    Cirno::Logger::Init();
    INTERNAL_DEBUG("Logger initialized");

    auto *app = Cirno::CreateApplication();
    app->Run();
    delete app;
}