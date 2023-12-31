#include "Core/Logbook.hpp"

namespace Phalanx::Core {
	auto Logbook::
	AddEntry(LogbookEntry entry) -> Logbook& {
		entries_.push_back(entry);
		return *this;
	}

	auto Logbook::
	AddEntry(std::string message, LogbookEntry::Levels level) -> Logbook& {
		entries_.emplace_back(message, level);
		return *this;
	}

	auto Logbook::
	AddInfo(std::string message) -> Logbook& {
		return AddEntry(message, LogbookEntry::Levels::INFO);
	}

	auto Logbook::
	AddWarning(std::string message) -> Logbook& {
		return AddEntry(message, LogbookEntry::Levels::WARNING);
	}

	auto Logbook::
	AddError(std::string message) -> Logbook& {
		return AddEntry(message, LogbookEntry::Levels::ERROR);
	}

	auto Logbook::
	AddFatal(std::string message) -> Logbook& {
		return AddEntry(message, LogbookEntry::Levels::FATAL);
	}

	auto Logbook::
	Count() const -> size_t {
		return entries_.size();
	}
}	// namespace Phalanx::Core