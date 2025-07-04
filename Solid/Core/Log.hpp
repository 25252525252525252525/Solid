#ifndef SOLID_CORE_LOG_HPP
#define SOLID_CORE_LOG_HPP

#include "spdlog/logger.h"
#include <spdlog/spdlog.h>

#include <memory>

namespace Solid {

class Log {
public:
    static spdlog::logger& getCoreLogger();
    static spdlog::logger& getClientLogger();

private:
    static std::shared_ptr<spdlog::logger> coreLogger_;
    static std::shared_ptr<spdlog::logger> clientLogger_;
};

}

// Core log macros
#define SOLID_CORE_TRACE(...) ::Solid::Log::getCoreLogger().trace(__VA_ARGS__)
#define SOLID_CORE_INFO(...) ::Solid::Log::getCoreLogger().info(__VA_ARGS__)
#define SOLID_CORE_WARN(...) ::Solid::Log::getCoreLogger().warn(__VA_ARGS__)
#define SOLID_CORE_ERROR(...) ::Solid::Log::getCoreLogger().error(__VA_ARGS__)
#define SOLID_CORE_CRITICAL(...) ::Solid::Log::getCoreLogger().critical(__VA_ARGS__)

// Client log macros
#define SOLID_TRACE(...) ::Solid::Log::getClientLogger().trace(__VA_ARGS__)
#define SOLID_INFO(...) ::Solid::Log::getClientLogger().info(__VA_ARGS__)
#define SOLID_WARN(...) ::Solid::Log::getClientLogger().warn(__VA_ARGS__)
#define SOLID_ERROR(...) ::Solid::Log::getClientLogger().error(__VA_ARGS__)
#define SOLID_CRITICAL(...) ::Solid::Log::getClientLogger().critical(__VA_ARGS__)

#endif
