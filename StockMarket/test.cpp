#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Date.h"
#include "Quote.h"
#include "Position.h"
#include "Strategy.h"
#include "ConservativeStrategy.h"
#include "AggressiveStrategy.h"

TEST_CASE("Testing Date::isSameDay") {
    Date d1(15, 1, 2026);
    Date d2(15, 1, 2026);
    Date d3(16, 1, 2026);

    CHECK(d1.isSameDay(d2) == true);
    CHECK(d1.isSameDay(d3) == false);
}

TEST_CASE("ConservativeStrategy - buy conditions") {
    ConservativeStrategy s(10000);
    s.onQuote("AAPL", 100.0, Date(1, 1, 2026));

    CHECK(s.wantBuy("AAPL", 95.0) == true);
    CHECK(s.wantBuy("AAPL", 99.0) == false);
}

TEST_CASE("ConservativeStrategy - sell conditions") {
    ConservativeStrategy s(10000);

    CHECK(s.wantSell(106.0, 100.0) == true);
    CHECK(s.wantSell(103.0, 100.0) == false);
}

TEST_CASE("AggressiveStrategy - buy conditions") {
    AggressiveStrategy s(10000);
    s.onQuote("GOOG", 200.0, Date(1, 1, 2026));

    CHECK(s.wantBuy("GOOG", 184.0) == true);
    CHECK(s.wantBuy("GOOG", 190.0) == false);
}

TEST_CASE("AggressiveStrategy - sell conditions") {
    AggressiveStrategy s(10000);

    CHECK(s.wantSell(101.0, 100.0) == true);
    CHECK(s.wantSell(99.0, 100.0) == false);
}