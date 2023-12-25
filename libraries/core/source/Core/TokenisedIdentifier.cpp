#include "core/TokenisedIdentifier.hpp"

namespace Phalanx::Core {
	auto TokenisedIdentifier::
	AppendToken(std::string token) -> size_t {
		tokens_.push_back(token);
		return TokenCount();
	}

	auto TokenisedIdentifier::
	AtDepth(size_t depth) const -> std::string {
		return tokens_[depth];	// May throw std::out_of_range
	}

	auto TokenisedIdentifier::
	Remove(size_t depth) -> void {
		tokens_.erase(tokens_.begin() + depth);
	}

	auto TokenisedIdentifier::
	TokenCount() const -> size_t {
		return tokens_.size();
	}
}	// namespace Phalanx::Core
