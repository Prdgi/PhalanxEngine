#pragma once

#include <string>

namespace Phalanx::Core {
    class LogbookEntry {
    public:
        auto Message() const -> std::string;
    protected:
    private:
    };	// class LogbookEntry
}	// namespace Phalanx::Core