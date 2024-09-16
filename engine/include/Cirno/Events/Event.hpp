#pragma once

#include "Cirno/Defines.hpp"

#include <functional>
#include <string>

namespace Cirno
{

enum class EventType
{
    None = 0,
    WindowClose,
    WindowResize,
    WindowFocus,
    WindowLostFocus,
    WindowMoved,
};

enum class EventCategory
{
    None = 0,
    Application = 1 << 0,
    Input = 1 << 1,
    Keyboard = 1 << 2
};

class CIRNO_API IEvent
{
    friend class EventDispatcher;
public:
    virtual ~IEvent() = default;

protected:
    bool m_IsHandled = false;
};

template<typename T>
class CIRNO_API BaseEvent : public IEvent
{
public:
    EventType GetEventType() const
    {
        return T::GetEventTypeImpl();
    }
    EventCategory GetEventCategory() const
    {
        return T::GetEventCategoryImpl();
    }
    std::string ToString() const
    {
        return ToUnderlyingPtr()->ToStringImpl();
    }

private:
    constexpr const T *ToUnderlyingPtr() const { return static_cast<const T *>(this); }
    constexpr T *ToUnderlyingPtr() { return static_cast<T *>(this); }
};

class EventDispatcher
{
    template<typename T>
    using EventCallback = std::function<bool(T &)>;
public:
    EventDispatcher(IEvent &e) : m_Event(e) {}

    template <typename DerivedEvent>
    bool Dispatch(EventCallback<DerivedEvent> &&cb)
    {
        DerivedEvent *toEventT = dynamic_cast<DerivedEvent *>(&m_Event);
        if (toEventT == nullptr)
            return false;

        m_Event.m_IsHandled = cb(*toEventT);
        return true;
    }

private:
    IEvent &m_Event;
};

}  // namespace Cirno