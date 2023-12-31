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

        SECTION("Logbook::Levels should support INFO, WARNING, ERROR, FATAL values") {
            entry.Level(LogbookEntry::Levels::INFO);
            entry.Level(LogbookEntry::Levels::WARNING);
            entry.Level(LogbookEntry::Levels::ERROR);
            entry.Level(LogbookEntry::Levels::FATAL);
        }
    }

    TEST_CASE("Phalanx::Core::LogbookEntry constructor accepting a only a message") {
        auto message = std::string{ "This is a message" };
        auto entry = LogbookEntry{ message };

        SECTION("Message should be stored when passed to constructor") {
            REQUIRE(entry.Message() == message);
        }
    }

    TEST_CASE("Phalanx::Core::LogbookEntry constructor accepting a message and level") {
        auto message = std::string{ "This is a message" };
        auto level = LogbookEntry::Levels::WARNING;
        auto entry = LogbookEntry{ message, level };

        SECTION("Message should be stored when passed to constructor") {
            REQUIRE(entry.Message() == message);
        }

        SECTION("Level should be stored when passed to constructor") {
            REQUIRE(entry.Level() == level);
        }

        SECTION("ToString() should return a string of the entry") {
            REQUIRE(entry.ToString() == "WARNING: " + message);
        }
    }
}	// namespace Phalanx::Core
