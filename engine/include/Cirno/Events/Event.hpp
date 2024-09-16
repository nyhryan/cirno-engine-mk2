#pragma once

#include "Cirno/Defines.hpp"

#include <cstdint>
#include <functional>
#include <string>
#include <type_traits>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

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
    KeyPressed,
    KeyReleased,
    MouseMoved,
    MouseScrolled,
    MouseButtonPressed,
    MouseButtonReleased
};

enum class EventCategory : uint8_t
{
    None = 0,
    Application = 1 << 0,
    Input = 1 << 1,
    Keyboard = 1 << 2,
    Mouse = 1 << 3,
    MouseButton = 1 << 4
};

constexpr EventCategory operator|(EventCategory lhs, EventCategory rhs)
{
    using underlying = typename std::underlying_type_t<EventCategory>;
    return static_cast<EventCategory>(static_cast<underlying>(lhs) | static_cast<underlying>(rhs));
}

constexpr EventCategory operator&(EventCategory lhs, EventCategory rhs)
{
    using underlying = typename std::underlying_type_t<EventCategory>;
    return static_cast<EventCategory>(static_cast<underlying>(lhs) & static_cast<underlying>(rhs));
}

class CIRNO_API Event
{
    friend class EventDispatcher;

public:
    virtual ~Event() = default;

    virtual EventType GetEventType() const = 0;
    virtual EventCategory GetEventCategory() const = 0;
    virtual std::string ToString() const = 0;

protected:
    bool m_IsHandled = false;
};

class EventDispatcher
{
    template <typename T>
    using EventCallback = std::function<bool(T &)>;

public:
    EventDispatcher(Event &e) : m_Event(e) {}

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
    Event &m_Event;
};

}  // namespace Cirno

/*

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of_v<A, T>, char>> :
    fmt::formatter<std::string> {
  auto format(const A& a, format_context& ctx) const {
    return formatter<std::string>::format(a.name(), ctx);
  }
};

*/

template <typename T>
struct fmt::formatter<T,
                      std::enable_if_t<std::is_base_of_v<Cirno::Event, T>, char>
                      /* , typename Enable = void */
                      > : fmt::formatter<std::string_view>
{
    template <typename Ctx>
    auto format(const Cirno::Event &e, Ctx &ctx)
    {
        return fmt::format_to(ctx.out(), "{}", e.ToString());
    }
};