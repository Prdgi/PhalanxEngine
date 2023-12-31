#include "Core/Logbook.hpp"

namespace Phalanx::Core {
	auto Logbook::AddEntry(LogbookEntry entry) -> Logbook& {
		entries_.push_back(entry);
		return *this;
	}

	auto Logbook::Count() const -> size_t {
		return entries_.size();
	}
}	// namespace Phalanx::Core