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
            REQUIRE(identifier.Count() == 0);
        }

        SECTION("Appending a token to the identifier should increase size correctly") {
            REQUIRE(identifier.Append("Token1") == 1);
            REQUIRE(identifier.Append("Token2") == 2);
        }
    }

    TEST_CASE("") {
        auto identifier = TokenisedIdentifier{};
        identifier.Append("Token1");
        identifier.Append("Token2");
        identifier.Append("Token3");

        SECTION("Should be able to retrieve a token at a specific depth") {
            REQUIRE(identifier.At(0) == "Token1");
            REQUIRE(identifier.At(1) == "Token2");
            REQUIRE(identifier.At(2) == "Token3");
        }

        SECTION("Should be able to remove a token at a specific depth") {
            identifier.Remove(1);   // Token with value "Token2"
            REQUIRE(identifier.At(0) == "Token1");
            REQUIRE(identifier.At(1) == "Token3"); // Index decremented
        }
    }

}	// namespace Phalanx::Core
