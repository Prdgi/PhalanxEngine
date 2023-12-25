#include "core/TokenisedIdentifier.hpp"

namespace Phalanx::Core {
	auto TokenisedIdentifier::
	Append(std::string token) -> size_t {
		tokens_.push_back(token);
		return Count();
	}

	auto TokenisedIdentifier::
	At(size_t depth) const -> std::string {
		return tokens_[depth];	// May throw std::out_of_range
	}

	auto TokenisedIdentifier::
	Remove(size_t depth) -> void {
		tokens_.erase(tokens_.begin() + depth);
	}

	auto TokenisedIdentifier::
	Count() const -> size_t {
		return tokens_.size();
	}
}	// namespace Phalanx::Core
