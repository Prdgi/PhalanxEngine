#include <catch2/catch_test_macros.hpp>     /// Test Framework
#include "core/TokenisedIdentifier.hpp"		/// Class to test

#include <string>
#include <type_traits>

namespace Phalanx::Core {

    TEST_CASE("Phalanx::Core::TokenisedIdentifier Rule of 0/3/5") {
        SECTION("Default constructor should be enabled") {
            REQUIRE(std::is_default_constructible<TokenisedIdentifier>::value == true);
        }

        SECTION("Class should be destructible") {
            REQUIRE(std::is_destructible<TokenisedIdentifier>::value == true);
        }

        SECTION("Copy semantics should be enabled") {
            REQUIRE(std::is_copy_constructible<TokenisedIdentifier>::value == true);
            REQUIRE(std::is_copy_assignable<TokenisedIdentifier>::value == true);
        }

        SECTION("Move semantics should be enabled") {
            REQUIRE(std::is_move_constructible<TokenisedIdentifier>::value == true);
            REQUIRE(std::is_move_assignable<TokenisedIdentifier>::value == true);
        }
    }

    TEST_CASE("Phalanx::Core::TokenisedIdentifier with default construction") {
        auto identifier = TokenisedIdentifier{};
        
        SECTION("Token count should initialise to zero when using the default constructor") {
            REQUIRE(identifier.TokenCount() == 0);
        }

        SECTION("Appending a token to the identifier should increase size correctly") {
            REQUIRE(identifier.AppendToken("Token1") == 1);
            REQUIRE(identifier.AppendToken("Token2") == 2);
        }
    }

    TEST_CASE("") {
        auto identifier = TokenisedIdentifier{};
        identifier.AppendToken("Token1");
        identifier.AppendToken("Token2");
        identifier.AppendToken("Token3");

        SECTION("Should be able to retrieve a token at a specific depth") {
            REQUIRE(identifier.AtDepth(0) == "Token1");
            REQUIRE(identifier.AtDepth(1) == "Token2");
            REQUIRE(identifier.AtDepth(2) == "Token3");
        }
    }

}	// namespace Phalanx::Core
