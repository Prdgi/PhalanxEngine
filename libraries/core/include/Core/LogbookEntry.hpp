#pragma once

#include <string>

namespace Phalanx::Core {
    class LogbookEntry {
    public:
        enum class Levels { INFO, WARNING, ERROR, FATAL };
        auto Level() const -> LogbookEntry::Levels;
        auto Level(LogbookEntry::Levels level) -> void;
        auto Message() const -> std::string;
        auto Message(std::string message) -> void;
    protected:
    private:
        std::string message_{ "" };
        LogbookEntry::Levels level_ = LogbookEntry::Levels::INFO;
    };	// class LogbookEntry
}	// namespace Phalanx::Core