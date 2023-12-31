#include <catch2/catch_test_macros.hpp>		/// Test Framework
#include "Core/Logbook.hpp"					/// Class to test

#include "Core/LogbookEntry.hpp"

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

    TEST_CASE("Phalanx::Core::Logbook with default construction") {
        auto logbook = Logbook{};
        auto entry_message = "Test Message";
        auto entry_level = LogbookEntry::Levels::WARNING;
        auto entry = LogbookEntry(entry_message, entry_level);

        SECTION("Count() should return 0 when default constructed") {
            REQUIRE(logbook.Count() == 0);
        }

        SECTION("Count() should return the number of entries held by the logbook") {
            logbook.AddEntry(entry);
            REQUIRE(logbook.Count() == 1);
        }

        SECTION("Should be able to add an entry by passing a message and level") {
            logbook.AddEntry(entry_message, entry_level);
            REQUIRE(logbook.Count() == 1);
        }

        SECTION("AddInfo(arg) should be an alias to construct a new LogbookEntry with level INFO and the provided message") {
            logbook.AddInfo(entry_message);
            REQUIRE(logbook.Count() == 1);
        }
        SECTION("AddWarning(arg) should be an alias to construct a new LogbookEntry with level INFO and the provided message") {
            logbook.AddWarning(entry_message);
            REQUIRE(logbook.Count() == 1);
        }
        SECTION("AddError(arg) should be an alias to construct a new LogbookEntry with level INFO and the provided message") {
            logbook.AddError(entry_message);
            REQUIRE(logbook.Count() == 1);
        }
        SECTION("AddFatal(arg) should be an alias to construct a new LogbookEntry with level INFO and the provided message") {
            logbook.AddFatal(entry_message);
            REQUIRE(logbook.Count() == 1);
        }

    }
}	// namespace Phalanx::Core
