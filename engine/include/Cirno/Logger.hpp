#pragma once

#include "Cirno/Defines.hpp"

#include <spdlog/spdlog.h>
#include <memory>

namespace Cirno
{

class Logger
{
public:
    static void Init();

    static auto &GetInteralLogger() { return s_InternalLogger; }
    static auto &GetEngineLogger() { return s_EngineLogger; }

private:
    static std::shared_ptr<spdlog::logger> s_InternalLogger;
    static std::shared_ptr<spdlog::logger> s_EngineLogger;
};

}  // namespace Cirno

template<typename... Args>
constexpr void CIRNO_INTERNAL_ERROR(spdlog::format_string_t<Args...> fmt, Args&&... args)
{
    ::Cirno::Logger::GetInteralLogger()->error(fmt, args...);
}