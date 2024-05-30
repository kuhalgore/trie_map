#include <string>
#include "Trie.h"
#include "catch.hpp"


TEST_CASE("test 01", "checking mapping is correct between digits as string to actual digit") 
{
    Trie<unsigned int, 10, 48> digits;
	
        digits.insert("00", 0);
        digits.insert("01", 1);
        digits.insert("02", 2);
        digits.insert("03", 3);
        digits.insert("04", 4);
        digits.insert("05", 5);
        digits.insert("06", 6);
        digits.insert("07", 7);
        digits.insert("08", 8);
        digits.insert("09", 9);

        digits.insert("10", 10);
        digits.insert("11", 11);
        digits.insert("12", 12);
        digits.insert("13", 13);
        digits.insert("14", 14);
        digits.insert("15", 15);
        digits.insert("16", 16);
        digits.insert("17", 17);
        digits.insert("18", 18);
        digits.insert("19", 19);

        digits.insert("20", 20);
        digits.insert("21", 21);
        digits.insert("22", 22);
        digits.insert("23", 23);
        digits.insert("24", 24);
        digits.insert("25", 25);
        digits.insert("26", 26);
        digits.insert("27", 27);
        digits.insert("28", 28);
        digits.insert("29", 29);

        digits.insert("30", 30);
        digits.insert("31", 31);
        digits.insert("32", 32);
        digits.insert("33", 33);
        digits.insert("34", 34);
        digits.insert("35", 35);
        digits.insert("36", 36);
        digits.insert("37", 37);
        digits.insert("38", 38);
        digits.insert("39", 39);

        digits.insert("40", 40);
        digits.insert("41", 41);
        digits.insert("42", 42);
        digits.insert("43", 43);
        digits.insert("44", 44);
        digits.insert("45", 45);
        digits.insert("46", 46);
        digits.insert("47", 47);
        digits.insert("48", 48);
        digits.insert("49", 49);

        digits.insert("50", 50);
        digits.insert("51", 51);
        digits.insert("52", 52);
        digits.insert("53", 53);
        digits.insert("54", 54);
        digits.insert("55", 55);
        digits.insert("56", 56);
        digits.insert("57", 57);
        digits.insert("58", 58);
        digits.insert("59", 59);

	const auto& it58 = digits.search("58");
	REQUIRE(it58.first == true);
	REQUIRE(it58.second->first == "58");
	REQUIRE(it58.second->second == 58);
	
	const auto& it0= digits.search("00");
	REQUIRE(it0.first == true);
	REQUIRE(it0.second->first == "00");
	REQUIRE(it0.second->second == 0);
	
	const auto& it60 = digits.search("60");
	REQUIRE(it60.first == false);

}


