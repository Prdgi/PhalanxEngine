#include <catch2/catch_test_macros.hpp>		/// Test Framework
#include "Core/LogbookEntry.hpp"			/// Class to test

namespace Phalanx::Core {
    TEST_CASE("Phalanx::Core::LogbookEntry Rule of 0/3/5") {
        SECTION("Default constructor should be enabled") {
            REQUIRE(std::is_default_constructible<LogbookEntry>::value == true);
        }

        SECTION("Class should be destructible") {
            REQUIRE(std::is_destructible<LogbookEntry>::value == true);
        }

        SECTION("Copy semantics should be enabled") {
            REQUIRE(std::is_copy_constructible<LogbookEntry>::value == true);
            REQUIRE(std::is_copy_assignable<LogbookEntry>::value == true);
        }

        SECTION("Move semantics should be enabled") {
            REQUIRE(std::is_move_constructible<LogbookEntry>::value == true);
            REQUIRE(std::is_move_assignable<LogbookEntry>::value == true);
        }
    }

    TEST_CASE("Phalanx::Core::LogbookEntry with default construction") {
        auto entry = LogbookEntry{};

        SECTION("Message() should return an empty string when default constructed") {
            REQUIRE(entry.Message() == std::string{ "" });
        }
    }
}	// namespace Phalanx::Core
