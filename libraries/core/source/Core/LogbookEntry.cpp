#include "Core/LogbookEntry.hpp"

namespace Phalanx::Core {

	LogbookEntry::
	LogbookEntry(std::string message) : message_{ message } {}

	LogbookEntry::
	LogbookEntry(std::string message, Levels level) : message_{ message }, level_{ level } {}
	
	auto LogbookEntry::
	Level() const -> LogbookEntry::Levels {
		return level_;
	}

	auto LogbookEntry::
	Level(LogbookEntry::Levels level) -> LogbookEntry& {
		level_ = level;
		return *this;
	}

	auto LogbookEntry::
	Message() const -> std::string {
		return message_;
	}

	auto LogbookEntry::
	Message(std::string message) -> LogbookEntry& {
		message_ = message;
		return *this;
	}

}	// namespace Phalanx::Core