#pragma once

#include "Cirno/Events/Event.hpp"

#include <format>

namespace Cirno
{

class CIRNO_API WindowResizeEvent : public Event
{
public:
    WindowResizeEvent(int w, int h) : m_Width(w), m_Height(h) {}

private:
    [[nodiscard]] EventType GetEventType() const override
    {
        return EventType::WindowResize;
    }

    [[nodiscard]] EventCategory GetEventCategory() const override
    {
        return EventCategory::Application;
    }

    [[nodiscard]] std::string ToString() const override
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
    [[nodiscard]] EventType GetEventType() const override
    {
        return EventType::WindowClose;
    }

    [[nodiscard]] EventCategory GetEventCategory() const override
    {
        return EventCategory::Application;
    }

    [[nodiscard]] std::string ToString() const override
    {
        return "WindowClose";
    }
};

}  // namespace Cirno