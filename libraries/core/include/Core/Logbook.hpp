#pragma once

#include <vector>

#include "Core/LogbookEntry.hpp"

namespace Phalanx::Core {
    class Logbook {
    public:
        auto AddEntry(LogbookEntry entry) -> Logbook&;
        auto Count() const -> size_t;
    protected:
    private:
        std::vector<LogbookEntry> entries_{};
    };	// class Logbook
}	// namespace Phalanx::Core