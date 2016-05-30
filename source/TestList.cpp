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
    REQUIRE(42 == list.front() );

    List<int> l2;
    l2.push_front(42);
    l2.push_front(34);
    l2.push_front(1);
    REQUIRE(1 == l2.front());

    List<int> l3;
    l2.push_front(42);
    l2.push_front(34);
    l2.push_front(1);
    l2.push_front(120)
    REQUIRE(120 == l2.front());
} 

TEST_CASE("add an element with push_back", "[aufgabe4.2]") {
    List<int> list {}; 
    list.push_back(42); 
    REQUIRE(42 == list.last());

    List<int> l2 {};
    l2.push_back(1);
    l2.push_back(12);
    l2.push_back(42);
    REQUIRE(42 == l2.last());

    List<int> l3 {};
    l2.push_back(1);
    l2.push_back(12);
    l2.push_back(42);
    l2.push_back(69);
    REQUIRE(69 == l2.last());
} 

TEST_CASE("remove first element with pop_front", "[aufgabe4.2]") {
    List<int> list {}; 
    list.push_back(42); 
    list.pop_front();
    REQUIRE(true == list.empty());

    List<int> l1 {};
    l1.push_back(42);
    l1.push_back(69);
    l1.pop_front();
    REQUIRE(69 == l1.front());

    List<int> l2 {};
    l2.push_back(42);
    l2.push_back(18);
    l2.push_back(19);
    l2.push_back(28);
    l2.push_back(4);
    l2.pop_front();
    REQUIRE(18 == l2.front());
} 

TEST_CASE("remove last element with pop_back", "[aufgabe4.2]") {
    List<int> list {}; 
    list.push_back(42); 
    list.pop_back();
    REQUIRE(true == list.empty());

    List<int> l1 {};
    l1.push_back(42);
    l1.push_back(69);
    l1.pop_back();
    REQUIRE(42 == l1.last());

    List<int> l2 {};
    l2.push_back(42);
    l2.push_back(18);
    l2.push_back(19);
    l2.push_back(28);
    l2.push_back(4);
    l2.pop_back();
    REQUIRE(28 == l2.last());
} 


// * --------------- Main --------------- * //

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

// * ----------------------------------- * //)