#pragma once

#include <string>

namespace Phalanx::Core {
    class Command {
    public:
        Command() = delete;
        explicit Command(std::string identifier, std::string body = std::string{ "" });
        auto Body() const -> std::string;
        auto Identifier() const -> std::string;
    protected:
    private:
        std::string body_;
        std::string identifier_;
    };	// class Command
}	// namespace Phalanx::Core
