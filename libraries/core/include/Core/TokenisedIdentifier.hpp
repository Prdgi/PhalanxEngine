#pragma once

#include <string>
#include <vector>

namespace Phalanx::Core {
    class TokenisedIdentifier {
    public:
        auto TokenCount() const -> size_t;
    protected:
    private:
        std::vector<std::string> tokens_{};
    };	// class TokenisedIdentifier
}	// namespace Phalanx::Core
