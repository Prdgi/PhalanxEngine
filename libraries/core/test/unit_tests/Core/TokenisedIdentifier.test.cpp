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

    TEST_CASE("Phalanx::Core::TokenisedIdentifier with 3 tokens") {
        auto identifier = TokenisedIdentifier{};
        identifier.Append("Token1");
        identifier.Append("Token2");
        identifier.Append("Token3");

        SECTION("Should be able to retrieve a token at a specific depth") {
            REQUIRE(identifier.At(0) == "Token1");
            REQUIRE(identifier.At(1) == "Token2");
            REQUIRE(identifier.At(2) == "Token3");
        }

        SECTION("At() should throw when provided with an out of range depth") {
            REQUIRE_THROWS(identifier.At(3));
        }

        SECTION("Should be able to remove a token at a specific depth") {
            identifier.Remove(1);   // Token with value "Token2"

            REQUIRE(identifier.At(0) == "Token1");
            REQUIRE(identifier.At(1) == "Token3"); // Index decremented
        }

        SECTION("Should be able to concatenate the tokens") {
            auto concatenators = TokenisedIdentifier::Concatenators{};
            concatenators.prefix = "@";
            concatenators.infix = "/";
            concatenators.postfix = ";";
            std::string expected = "@Token1/Token2/Token3;";

            REQUIRE(identifier.Concatenate(concatenators) == expected);
        }

        SECTION("Should be able to replace a token at a specific depth") {
            identifier.Replace(1, "Replaced");

            REQUIRE(identifier.At(1) == "Replaced");
        }

        SECTION("Replace() should throw when provided with an out of range depth") {
            REQUIRE_THROWS(identifier.Replace(3, "Replaced"));
        }

        SECTION("Should be able to insert a token at a specific depth") {
            auto current = identifier.At(1);
            identifier.Insert(1, "Inserted");

            REQUIRE(identifier.At(1) == "Inserted");    // Was it inserted correctly?
            REQUIRE(identifier.At(2) == current);       // What used to be at 1, should now be at 2
        }

        SECTION("Should be able to insert a token at the end") {
            auto current = identifier.At(1);
            identifier.Insert(3, "Inserted");

            REQUIRE(identifier.At(3) == "Inserted");
        }

        SECTION("Insert() should throw when provided with a depth beyond the end") {
            REQUIRE_THROWS(identifier.Replace(4, "Replaced"));
        }

        SECTION("Compare() should return true if an identifier is copied then compared with its copy") {
            auto copied_identifier = identifier;
            REQUIRE(identifier.Compare(copied_identifier) == true);
        }

        SECTION("Compare() should return false if an identifier recieves a new token after being copied then compared to the original") {
            auto copied_identifier = identifier;
            copied_identifier.Append("NewToken");
            REQUIRE(identifier.Compare(copied_identifier) == false);
        }

        SECTION("Compare() should return false if an identifier has a token modified after being copied then compared to the original") {
            auto copied_identifier = identifier;
            copied_identifier.Replace(1, "NewToken");
            REQUIRE(identifier.Compare(copied_identifier) == false);
        }
    }
}	// namespace Phalanx::Core
