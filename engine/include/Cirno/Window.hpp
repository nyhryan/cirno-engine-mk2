#pragma once

#include "Cirno/Defines.hpp"
#include "Cirno/Events/Event.hpp"

#include <functional>
#include <string>

namespace Cirno
{

struct WindowProps
{
    std::string title = "Cirno Engine";
    unsigned int width = 640;
    unsigned int height = 480;
};

class CIRNO_API Window
{
public:
    using ApplicationOnEvent = std::function<void(Event &&)>;

    virtual ~Window() {}

    virtual void OnUpdate() = 0;
    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    virtual void SetApplicationEventCallback(ApplicationOnEvent &&cb) = 0;

    virtual void SetVSync(bool isEnabled) = 0;
    virtual bool IsVSync() const = 0;

    static Window *Create(WindowProps &&props = WindowProps{});
};

}  // namespace Cirno