#include "core/TokenisedIdentifier.hpp"

#include <stdexcept>

namespace Phalanx::Core {
	auto TokenisedIdentifier::
	Append(std::string token) -> size_t {
		tokens_.push_back(token);
		return Count();
	}

	auto TokenisedIdentifier::
	At(size_t depth) const -> std::string {
		return tokens_.at(depth);	// May throw std::out_of_range
	}

	auto TokenisedIdentifier::
		Remove(size_t depth) -> void {
		tokens_.erase(tokens_.begin() + depth);
	}

	auto TokenisedIdentifier::
	Replace(size_t depth, std::string token) -> void {
		tokens_[depth] = token;
	}

	auto TokenisedIdentifier::
		Concatenate(Concatenators concatenators) const->std::string {
		auto result = std::string{ concatenators.prefix };
		for (auto it = tokens_.begin(); it != tokens_.end(); ++it) {
			if (it != tokens_.begin()) {
				result += concatenators.infix;
			}
			result += *it;
		}
		result += concatenators.postfix;
		return result;
	}

	auto TokenisedIdentifier::
	Count() const -> size_t {
		return tokens_.size();
	}
}	// namespace Phalanx::Core
