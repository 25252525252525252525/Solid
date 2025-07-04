#include "Log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Solid{

std::shared_ptr<spdlog::logger> Log::coreLogger_;
std::shared_ptr<spdlog::logger> Log::clientLogger_;

spdlog::logger& Log::getCoreLogger() {
    if (!coreLogger_) {
        coreLogger_ = spdlog::stdout_color_mt("SOLID");
        coreLogger_->set_level(spdlog::level::trace);
    }

    return *coreLogger_;
}

spdlog::logger& Log::getClientLogger() {
    if (!clientLogger_) {
        clientLogger_ = spdlog::stdout_color_mt("APP");
        clientLogger_->set_level(spdlog::level::trace);
    }

    return *clientLogger_;
}

}
