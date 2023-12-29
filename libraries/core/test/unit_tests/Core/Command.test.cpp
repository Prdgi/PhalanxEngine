#include <catch2/catch_test_macros.hpp>		/// Test Framework
#include "Core/Command.hpp"					/// Class to test

#include <string>
#include <type_traits>

#include "Core/TokenisedIdentifier.hpp"

namespace Phalanx::Core {

    TEST_CASE("Phalanx::Core::Command Rule of 0/3/5") {
        SECTION("Default constructor should be disabled") {
            REQUIRE(std::is_default_constructible<Command>::value == false);
        }

        SECTION("Class should be destructible" ) {
            REQUIRE(std::is_destructible<Command>::value == true);
        }

        SECTION("Copy semantics should be enabled") {
            REQUIRE(std::is_copy_constructible<Command>::value == true);
            REQUIRE(std::is_copy_assignable<Command>::value == true);
        }

        SECTION("Move semantics should be enabled") {
            REQUIRE(std::is_move_constructible<Command>::value == true);
            REQUIRE(std::is_move_assignable<Command>::value == true);
        }
    }

    TEST_CASE("Phalanx::Core::Command Can construct with an identifier and body") {
        auto identifier = TokenisedIdentifier{};
        identifier.Append("Token1");
        auto body = "body";
        auto command = Command{ identifier, body };

        SECTION("Can retrieve identifier after construction with identifier and body") {
            REQUIRE(identifier.Compare(command.Identifier()) == true);
        }

        SECTION("Can retrieve body after construction with identifier and body") {
            REQUIRE(command.Body() == body);
        }
    }

    TEST_CASE("Phalanx::Core::Command Can construct with an identifier and without a body") {
        auto identifier = TokenisedIdentifier{};
        identifier.Append("Token1");
        auto command = Command{ identifier };

        SECTION("Can retrieve identifier after construction with only an identifier") {
            REQUIRE(identifier.Compare(command.Identifier()) == true);
        }

        SECTION("Body should be an empty string after construction with only an identifier") {
            REQUIRE(command.Body() == std::string{""});
        }
    }

}	// namespace Phalanx::Core
