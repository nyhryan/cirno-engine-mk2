#pragma once

#include "Cirno/Defines.hpp"
#include "Cirno/Events/Event.hpp"

namespace Cirno
{
class CIRNO_API WindowResizeEvent : public BaseEvent
{
public:
    WindowResizeEvent(int w, int h) : m_Width(w), m_Height(h) {}

    EventType GetEventType() const { return EventType::WindowResize; }

    EventCategory GetEventCategory() const
    {
        return EventCategory::Application;
    }

    std::string ToString() const
    {
        return std::format("WindowResize: ({}, {})", m_Width, m_Height);
    }

private:
    int m_Width;
    int m_Height;
};

class CIRNO_API CRTPWindowResizeEvent : public CRTPBaseEvent<CRTPWindowResizeEvent>
{
    friend CRTPBaseEvent;
public:
    using value_type = CRTPWindowResizeEvent;
    
    CRTPWindowResizeEvent(int w, int h) : m_Width(w), m_Height(h) {}

private:
    EventType GetEventTypeImpl() const { return EventType::WindowResize; }

    EventCategory GetEventCategoryImpl() const
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

class CIRNO_API WindowCloseEvent : public BaseEvent
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

}