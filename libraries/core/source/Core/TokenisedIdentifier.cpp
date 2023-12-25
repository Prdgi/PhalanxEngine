#include "core/TokenisedIdentifier.hpp"

namespace Phalanx::Core {
	auto TokenisedIdentifier::
	AppendToken(std::string token) -> size_t {
		tokens_.push_back(token);
		return TokenCount();
	}

	auto TokenisedIdentifier::
	TokenCount() const -> size_t {
		return tokens_.size();
	}
}	// namespace Phalanx::Core
