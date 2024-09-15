#include "Cirno/Application.hpp"

#include <memory>

extern Cirno::Application *Cirno::CreateApplication();

int main(int, char **)
{
    auto *app = Cirno::CreateApplication();
    app->Run();
    delete app;
}