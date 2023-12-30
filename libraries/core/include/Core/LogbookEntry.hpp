#pragma once

#include <string>

namespace Phalanx::Core {
    class LogbookEntry {
    public:
        enum class Levels { INFO };
        auto Level() const -> LogbookEntry::Levels;
        auto Message() const -> std::string;
        auto Message(std::string message) -> void;
    protected:
    private:
        std::string message_{ "" };
    };	// class LogbookEntry
}	// namespace Phalanx::Core