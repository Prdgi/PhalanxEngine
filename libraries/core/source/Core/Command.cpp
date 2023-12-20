#include "Core/Command.hpp"

namespace Phalanx::Core {
    Command::Command(std::string identifier, std::string body) 
        : identifier_{ identifier }, body_{ body } {}

    auto Command::Body() const -> std::string {
        return body_;
    }

    auto Command::Identifier() const -> std::string{
        return identifier_;
    }
}	// namespace Phalanx::Core