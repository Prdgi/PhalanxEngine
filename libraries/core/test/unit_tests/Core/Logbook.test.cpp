#include <catch2/catch_test_macros.hpp>		/// Test Framework
#include "Core/Logbook.hpp"					/// Class to test

namespace Phalanx::Core {
    TEST_CASE("Phalanx::Core::Logbook Rule of 0/3/5") {
        SECTION("Default constructor should be enabled") {
            REQUIRE(std::is_default_constructible<Logbook>::value == true);
        }

        SECTION("Class should be destructible") {
            REQUIRE(std::is_destructible<Logbook>::value == true);
        }

        SECTION("Copy semantics should be enabled") {
            REQUIRE(std::is_copy_constructible<Logbook>::value == true);
            REQUIRE(std::is_copy_assignable<Logbook>::value == true);
        }

        SECTION("Move semantics should be enabled") {
            REQUIRE(std::is_move_constructible<Logbook>::value == true);
            REQUIRE(std::is_move_assignable<Logbook>::value == true);
        }
    }
}	// namespace Phalanx::Core
