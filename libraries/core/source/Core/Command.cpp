#include "Core/Command.hpp"

namespace Phalanx::Core {
    Command::
    Command(TokenisedIdentifier identifier, std::string body) 
        : identifier_{ identifier }, body_{ body } {}

    auto Command::
    Body() const -> const std::string& {
        return body_;
    }

    auto Command::
    Identifier() const -> const TokenisedIdentifier& {
        return identifier_;
    }
}	// namespace Phalanx::Core