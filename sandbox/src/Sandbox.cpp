#include <Cirno/Cirno_main.hpp>

#include <Cirno/Application.hpp>
#include <Cirno/Test.hpp>

class Sandbox : public Cirno::Application {};

Cirno::Application *Cirno::CreateApplication()
{
    Cirno::foo();

    return nullptr;
    // return new Sandbox();
}