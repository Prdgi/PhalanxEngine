#pragma once

#include <string>
#include <vector>

namespace Phalanx::Core {
    class TokenisedIdentifier {
    public:
        struct Concatenators {
            std::string prefix{ "" };
            std::string infix{ "" };
            std::string postfix{ "" };
        };

        auto Append(std::string token) -> size_t;
        auto At(size_t depth) const -> std::string;
        auto Remove(size_t) -> void;
        auto Concatenate(Concatenators concatenators) const -> std::string;
        auto Count() const -> size_t;
    protected:
    private:
        std::vector<std::string> tokens_{};
    };	// class TokenisedIdentifier
}	// namespace Phalanx::Core
