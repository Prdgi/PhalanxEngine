#include "Core/LogbookEntry.hpp"

namespace Phalanx::Core {

	auto LogbookEntry::
	Level() const -> LogbookEntry::Levels {
		return Levels::INFO;
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