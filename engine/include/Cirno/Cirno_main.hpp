#include "Cirno/Application.hpp"

extern Cirno::Application *Cirno::CreateApplication();

int main(int, char **)
{
    auto *app = Cirno::CreateApplication();
    app->Run();
    delete app;
}