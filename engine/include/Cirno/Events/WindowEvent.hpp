#pragma once

#include "Cirno/Defines.hpp"
#include "Cirno/Events/Event.hpp"

#include <format>

namespace Cirno
{

class CIRNO_API WindowResizeEvent : public BaseEvent<WindowResizeEvent>
{
    friend BaseEvent;

public:
    WindowResizeEvent(int w, int h) : m_Width(w), m_Height(h) {}

private:
    static EventType GetEventTypeImpl() { return EventType::WindowResize; }

    static EventCategory GetEventCategoryImpl()
    {
        return EventCategory::Application;
    }

    std::string ToStringImpl() const
    {
        return std::format("WindowResize: ({}, {})", m_Width, m_Height);
    }

private:
    int m_Width;
    int m_Height;
};

class CIRNO_API WindowCloseEvent : public BaseEvent<WindowCloseEvent>
{
public:
    static EventType GetEventType() { return EventType::WindowClose; }

    static EventCategory GetEventCategory()
    {
        return EventCategory::Application;
    }

    std::string ToString() const
    {
        return "WindowClose";
    }
};

}