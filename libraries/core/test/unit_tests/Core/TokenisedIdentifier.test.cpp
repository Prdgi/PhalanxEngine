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
    }

}	// namespace Phalanx::Core
