#include <catch2/catch_test_macros.hpp>
#include "Core/Command.hpp"


#include <catch2/catch_test_macros.hpp>		/// Test Framework
#include "Core/Command.hpp"					/// Class to test

#include <string>
#include <type_traits>

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

}	// namespace Phalanx::Core
