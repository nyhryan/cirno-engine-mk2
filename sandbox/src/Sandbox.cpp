#include <Cirno/Cirno.hpp>

class Sandbox : public Cirno::Application
{
public:
    Sandbox() {}
    ~Sandbox() {}
};

Cirno::Application *Cirno::CreateApplication()
{
    return new Sandbox();
}