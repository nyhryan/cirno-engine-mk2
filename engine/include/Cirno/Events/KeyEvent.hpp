#pragma once

#include "Cirno/Events/Event.hpp"

namespace Cirno
{

class CIRNO_API KeyBaseEvent : public Event
{
public:
    [[nodiscard]] int GetKeyCode() const { return m_KeyCode; }

protected:
    KeyBaseEvent(int key) : m_KeyCode(key) {}

    int m_KeyCode;
};

class CIRNO_API KeyPressedEvent : public KeyBaseEvent
{
public:
    KeyPressedEvent(int key, int repeatCount)
        : KeyBaseEvent(key), m_RepeatCount(repeatCount)
    {
    }

    int GetRepeatCount() const { return m_RepeatCount; }

private:
    [[nodiscard]] EventType GetEventType() const override
    {
        return EventType::KeyPressed;
    }

    [[nodiscard]] EventCategory GetEventCategory() const override
    {
        return EventCategory::Input | EventCategory::Keyboard;
    }

    [[nodiscard]] std::string ToString() const override
    {
        return fmt::format("KeyPressedEvent: {} (Repeat: {})", m_KeyCode,
                           m_RepeatCount);
    }

private:
    int m_RepeatCount;
};

class CIRNO_API KeyReleasedEvent : public KeyBaseEvent
{
public:
    KeyReleasedEvent(int key) : KeyBaseEvent(key) {}

private:
    [[nodiscard]] EventType GetEventType() const override
    {
        return EventType::KeyReleased;
    }

    [[nodiscard]] EventCategory GetEventCategory() const override
    {
        return EventCategory::Input | EventCategory::Keyboard;
    }

    [[nodiscard]] std::string ToString() const override
    {
        return fmt::format("KeyReleasedEvent: {}", m_KeyCode);
    }
};

}  // namespace Cirno