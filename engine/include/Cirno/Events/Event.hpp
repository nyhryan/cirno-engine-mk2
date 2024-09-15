#pragma once

#include <mach_debug/zone_info.h>
#include "Cirno/Defines.hpp"

#include <functional>
#include <string>
#include <sstream>
#include <format>
#include <iostream>

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

class CIRNO_API CRTP
{
    friend class CRTPEventDispatcher;
public:
    virtual ~CRTP() = default;
protected:
    bool m_IsHandled = false;
};

template<typename T>
class CIRNO_API CRTPBaseEvent : public CRTP
{
public:
    EventType GetEventType()
    {
        return ToUnderlyingPtr()->GetEventTypeImpl();
    }
    EventCategory GetEventCategory()
    {
        return ToUnderlyingPtr()->GetEventCategoryImpl();
    }
    std::string ToString()
    {
        return ToUnderlyingPtr()->ToStringImpl();
    }

private:
    constexpr T *ToUnderlyingPtr() { return static_cast<T *>(this); }
};

class CRTPEventDispatcher
{
    template<typename T>
    using EventCallback = std::function<bool(T &)>;
public:
    CRTPEventDispatcher(CRTP &e) : m_Event(e) {}

    template<typename T>
    bool Dispatch(EventCallback<T> &&cb)
    {
        try
        {
            T &toEventT = dynamic_cast<T &>(m_Event);
            m_Event.m_IsHandled = cb(toEventT);
            return true;
        }
        catch (std::exception &)
        {
            return false;
        }
    }

private:
    CRTP &m_Event;
};

class CIRNO_API BaseEvent
{
    friend class EventDispatcher;

public:
    virtual EventType GetEventType() const = 0;
    virtual EventCategory GetEventCategory() const = 0;
    virtual std::string ToString() const = 0;

protected:
    bool m_IsHandled = false;
};

class EventDispatcher
{
    template <typename EventT>
    using EventCallback = std::function<bool(EventT &)>;

public:
    EventDispatcher(BaseEvent &e) : m_Event(e) {}

    template <typename EventT>
    bool Dispatch(EventCallback<EventT> &&callback)
    {
        // try downcast to EventT
        try
        {
            auto toEventT = dynamic_cast<EventT &>(m_Event);
            m_Event.m_IsHandled = callback(toEventT);
            return true;
        }
        catch (std::exception&)
        {
            return false;
        }
    }

private:
    BaseEvent &m_Event;
};

}  // namespace Cirno