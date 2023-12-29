#pragma once

#include <string>

namespace Phalanx::Core {
    class LogbookEntry {
    public:
        auto Message() const -> std::string;
        auto Message(std::string message) -> void;
    protected:
    private:
    };	// class LogbookEntry
}	// namespace Phalanx::Core