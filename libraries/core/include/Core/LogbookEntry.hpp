#pragma once

#include <string>

namespace Phalanx::Core {
    class LogbookEntry {
    public:
        enum class Levels { INFO, WARNING, ERROR, FATAL };
        
        LogbookEntry() = default;
        LogbookEntry(std::string message);
        LogbookEntry(std::string message, Levels level);
        
        auto Level() const -> LogbookEntry::Levels;
        auto Level(LogbookEntry::Levels level) -> LogbookEntry&;
        
        auto Message() const -> std::string;
        auto Message(std::string message) -> LogbookEntry&;
        
        auto ToString() const -> std::string;
    protected:
    private:
        std::string message_{ "" };
        LogbookEntry::Levels level_ = LogbookEntry::Levels::INFO;
    };	// class LogbookEntry
}	// namespace Phalanx::Core