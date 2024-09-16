#pragma once

#include "Cirno/Defines.hpp"
#include "Cirno/Events/Event.hpp"

#include <format>

namespace Cirno
{

class CIRNO_API WindowResizeEvent : public Event
{
public:
    WindowResizeEvent(int w, int h) : m_Width(w), m_Height(h) {}

private:
    EventType GetEventType() const override { return EventType::WindowResize; }

    EventCategory GetEventCategory() const override
    {
        return EventCategory::Application;
    }

    std::string ToString() const override
    {
        return std::format("WindowResize: ({}, {})", m_Width, m_Height);
    }

private:
    int m_Width;
    int m_Height;
};

class CIRNO_API WindowCloseEvent : public Event
{
public:
    EventType GetEventType() const override { return EventType::WindowClose; }

    EventCategory GetEventCategory() const override
    {
        return EventCategory::Application;
    }

    std::string ToString() const override
    {
        return "WindowClose";
    }
};

} // namespace Cirno