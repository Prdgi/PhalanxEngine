#include "core/TokenisedIdentifier.hpp"

namespace Phalanx::Core {
	auto TokenisedIdentifier::
	TokenCount() const -> size_t {
		return tokens_.size();
	}
}	// namespace Phalanx::Core
