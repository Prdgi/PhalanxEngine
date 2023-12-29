#pragma once

#include <string>

#include "Core/TokenisedIdentifier.hpp"

namespace Phalanx::Core {
    class Command {
    public:
        Command() = delete;
        explicit Command(TokenisedIdentifier identifier, std::string body = std::string{ "" });
        auto Body() const -> const std::string&;
        auto Identifier() const -> const TokenisedIdentifier&;
    protected:
    private:
        std::string body_;
        TokenisedIdentifier identifier_;
    };	// class Command
}	// namespace Phalanx::Core
