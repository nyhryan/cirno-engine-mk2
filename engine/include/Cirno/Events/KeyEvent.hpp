#pragma once

#include "Cirno/Events/Event.hpp"
#include "Cirno/Defines.hpp"

namespace Cirno
{

class CIRNO_API KeyBaseEvent : public Event
{
public:
    int GetKeyCode() const { return m_KeyCode; }

protected:
    KeyBaseEvent(int key) : m_KeyCode(key) {}

    int m_KeyCode;
};

class CIRNO_API KeyPressedEvent : public KeyBaseEvent
{
public:
    KeyPressedEvent(int key, int repeatCount) : KeyBaseEvent(key), m_RepeatCount(repeatCount) {}

    int GetRepeatCount() const { return m_RepeatCount; }
    
private:
    EventType GetEventType() const override
    {
        return EventType::KeyPressed;
    }

    EventCategory GetEventCategory() const override
    {
        return EventCategory::Input | EventCategory::Keyboard;
    }

    std::string ToString() const override
    {
        return fmt::format("KeyPressedEvent: {} (Repeat: {})", m_KeyCode, m_RepeatCount);
    }

private:
    int m_RepeatCount;
};

class CIRNO_API KeyReleasedEvent : public KeyBaseEvent
{
public:
    KeyReleasedEvent(int key) : KeyBaseEvent(key) {}

private:
    EventType GetEventType() const override
    {
        return EventType::KeyReleased;
    }

    EventCategory GetEventCategory() const override
    {
        return EventCategory::Input | EventCategory::Keyboard;
    }

    std::string ToString() const override
    {
        return fmt::format("KeyReleasedEvent: {}", m_KeyCode);
    }
};

} // namespace Cirno