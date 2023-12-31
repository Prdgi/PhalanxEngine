#pragma once

#include <string>
#include <vector>

#include "Core/LogbookEntry.hpp"

namespace Phalanx::Core {
    class Logbook {
    public:
        auto AddEntry(LogbookEntry entry) -> Logbook&;
        auto AddEntry(std::string message, LogbookEntry::Levels level = LogbookEntry::Levels::INFO) -> Logbook&;
        auto AddInfo(std::string message) -> Logbook&;
        auto AddWarning(std::string message) -> Logbook&;
        auto AddError(std::string message) -> Logbook&;
        auto AddFatal(std::string message) -> Logbook&;
        auto Count() const -> size_t;
        auto Name() const -> std::string;
        auto Name(std::string name) -> Logbook&;
    protected:
    private:
        std::vector<LogbookEntry> entries_{};
        std::string name_{ "Untitled Logbook" };
    };	// class Logbook
}	// namespace Phalanx::Core