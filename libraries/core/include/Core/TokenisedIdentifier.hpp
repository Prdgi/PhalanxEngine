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
        auto Concatenate(Concatenators concatenators) const->std::string;
        auto Count() const->size_t;
        auto Insert(size_t depth, std::string token) -> void;
        auto Remove(size_t depth) -> void;
        auto Replace(size_t depth, std::string token) -> void;
        
    protected:
    private:
        std::vector<std::string> tokens_{};
    };	// class TokenisedIdentifier
}	// namespace Phalanx::Core
