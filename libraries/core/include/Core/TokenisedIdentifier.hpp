#pragma once

#include <string>
#include <vector>

namespace Phalanx::Core {
    class TokenisedIdentifier {
    public:
        auto AppendToken(std::string token) -> size_t;
        auto At(size_t depth) const -> std::string;
        auto Remove(size_t) -> void;
        auto TokenCount() const -> size_t;
    protected:
    private:
        std::vector<std::string> tokens_{};
    };	// class TokenisedIdentifier
}	// namespace Phalanx::Core
