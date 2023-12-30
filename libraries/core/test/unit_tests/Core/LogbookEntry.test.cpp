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
        auto message = std::string{ "This is a message" };
        auto level = LogbookEntry::Levels::WARNING;

        SECTION("Message() should return an empty string when default constructed") {
            REQUIRE(entry.Message() == std::string{ "" });
        }

        SECTION("Message() should return a string previously passed to Message(arg)") {
            entry.Message(message);
            REQUIRE(entry.Message() == message);

        }
        
        SECTION("Level() should return LogbookEntry::Levels::INFO when default constructed") {
            REQUIRE(entry.Level() == LogbookEntry::Levels::INFO);
        }

        SECTION("Level() should return a LogbookEntry::Levels previously passed to Level(arg)") {
            entry.Level(level);
            REQUIRE(entry.Level() == level);
        }

        SECTION("Logbook::Levels should support have INFO, WARNING, ERROR, FATAL values") {
            entry.Level(LogbookEntry::Levels::INFO);
            entry.Level(LogbookEntry::Levels::WARNING);
            entry.Level(LogbookEntry::Levels::ERROR);
            entry.Level(LogbookEntry::Levels::FATAL);
        }

    }
}	// namespace Phalanx::Core
