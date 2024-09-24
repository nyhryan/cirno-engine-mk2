#pragma once

#include "Cirno/Defines.hpp"
#include "debugbreak.h"

#include <spdlog/spdlog.h>
#include <memory>

namespace CIRNO_API Cirno
{

class Logger
{
public:
    static void Init();

    [[nodiscard]] static auto &GetInteralLogger() { return s_InternalLogger; }
    [[nodiscard]] static auto &GetEngineLogger() { return s_EngineLogger; }

private:
    static std::shared_ptr<spdlog::logger> s_InternalLogger;
    static std::shared_ptr<spdlog::logger> s_EngineLogger;
};

}  // namespace Cirno

// Internal logging macros
// stripped in release builds
#if !defined(NDEBUG)
#define INTERNAL_CRITICAL(fmt, ...) ::Cirno::Logger::GetInteralLogger()->critical(fmt __VA_OPT__(, ) __VA_ARGS__)
#define INTERNAL_DEBUG(fmt, ...)    ::Cirno::Logger::GetInteralLogger()->debug(fmt __VA_OPT__(, ) __VA_ARGS__)
#define INTERNAL_ERROR(fmt, ...)    ::Cirno::Logger::GetInteralLogger()->error(fmt __VA_OPT__(, ) __VA_ARGS__)
#define INTERNAL_INFO(fmt, ...)     ::Cirno::Logger::GetInteralLogger()->info(fmt __VA_OPT__(, ) __VA_ARGS__)
#define INTERNAL_WARN(fmt, ...)     ::Cirno::Logger::GetInteralLogger()->warn(fmt __VA_OPT__(, ) __VA_ARGS__)
#define INTERNAL_TRACE(fmt, ...)    ::Cirno::Logger::GetInteralLogger()->trace(fmt __VA_OPT__(, ) __VA_ARGS__)
#else
#define INTERNAL_CRITICAL(fmt, ...)
#define INTERNAL_DEBUG(fmt, ...)
#define INTERNAL_ERROR(fmt, ...)
#define INTERNAL_INFO(fmt, ...)
#define INTERNAL_WARN(fmt, ...)
#define INTERNAL_TRACE(fmt, ...)
#endif

// Engine logging macros(for clients)
#define CIRNO_CRITICAL(fmt, ...)    ::Cirno::Logger::GetEngineLogger()->critical(fmt __VA_OPT__(, ) __VA_ARGS__)
#define CIRNO_DEBUG(fmt, ...)       ::Cirno::Logger::GetEngineLogger()->debug(fmt __VA_OPT__(, ) __VA_ARGS__)
#define CIRNO_ERROR(fmt, ...)       ::Cirno::Logger::GetEngineLogger()->error(fmt __VA_OPT__(, ) __VA_ARGS__)
#define CIRNO_INFO(fmt, ...)        ::Cirno::Logger::GetEngineLogger()->info(fmt __VA_OPT__(, ) __VA_ARGS__)
#define CIRNO_WARN(fmt, ...)        ::Cirno::Logger::GetEngineLogger()->warn(fmt __VA_OPT__(, ) __VA_ARGS__)
#define CIRNO_TRACE(fmt, ...)       ::Cirno::Logger::GetEngineLogger()->trace(fmt __VA_OPT__(, ) __VA_ARGS__)

#if !defined(NDEBUG)
#define INTERNAL_ASSERT(x, ...)                               \
    if (!(x))                                                 \
    {                                                         \
        INTERNAL_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
        debug_break();\
    }
#define CIRNO_ASSERT(x, ...)                               \
    if (!(x))                                                 \
    {                                                         \
        CIRNO_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
        debug_break();\
    }
#else
#define INTERNAL_ASSERT(x, ...)
#define CIRNO_ASSERT(x, ...)
#endif