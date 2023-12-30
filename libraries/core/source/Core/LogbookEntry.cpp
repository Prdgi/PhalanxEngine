#include "Core/LogbookEntry.hpp"

namespace Phalanx::Core {

	auto LogbookEntry::
	Level() const -> LogbookEntry::Levels {
		return level_;
	}

	auto LogbookEntry::
	Level(LogbookEntry::Levels level) -> void {
		level_ = level;
	}

	auto LogbookEntry::
	Message() const -> std::string {
		return message_;
	}

	auto LogbookEntry::
	Message(std::string message) -> void {
		message_ = message;
	}

}	// namespace Phalanx::Core