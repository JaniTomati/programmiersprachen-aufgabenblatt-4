// TestList.cpp (Programmiersprachen Aufgabe 4

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "list.hpp"


// * --------------- VEC2-Tests --------------- * //
TEST_CASE("describe_List_empty", "[aufgabe4.1]") {
	List<int> l1 {};
	REQUIRE(l1.empty() == true);
}

TEST_CASE("describe_List_size", "[aufgabe4.1]") {
	List<int> l1 {};
	REQUIRE(l1.size() == 0);
}

TEST_CASE("add an element with push_front", "[aufgabe4.2]") {
    List<int> list; 
    list.push_front(42); 
    REQUIRE(42 == list.front());
} 


// * --------------- Main --------------- * //

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

// * ----------------------------------- * //)