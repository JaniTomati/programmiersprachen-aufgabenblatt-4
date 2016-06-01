// TestList.cpp (Programmiersprachen Aufgabe 4)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "list.hpp"


// * --------------- List-Tests --------------- * //
TEST_CASE("checks whether a list is empty or not", "[aufgabe4.1]") {
	List<int> l1 {};
	REQUIRE(l1.empty() == true);
}

TEST_CASE("gets the size of a list", "[aufgabe4.1]") {
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
  l2.push_front(120);
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

TEST_CASE("should be empty after clearing", "[aufgabe4.3]") {
	List<int> list; 
	list.push_front(1); 
	list.push_front(2); 
	list.push_front(3); 
	list.push_front(4); 
	list.clear(); 
	REQUIRE(list.empty());

	List<int> l1; 
	list.push_front(3); 
	list.push_front(21); 
	list.push_front(199); 
	list.push_front(16); 
	list.push_front(19);
	list.push_front(21);
	list.clear(); 
	REQUIRE(list.empty());
}

TEST_CASE("++operator increments int", "[aufgabe4.4]") {
	
}

TEST_CASE("should be an empty range after default construction", "[aufgabe4.5]") {
  List<int> list;
  auto b = list.begin(); 
  auto e = list.end(); 
  REQUIRE(b == e);
}

TEST_CASE("provide acces to the first element with begin", "[aufgabe4.5]") {
  List<int> list; 
  list.push_front(42); 
  REQUIRE(42 == *list.begin());

  List<int> l1; 
  l1.push_back(69); 
  l1.push_back(101);
  l1.push_back(36);
  REQUIRE(69 == *l1.begin());
}

TEST_CASE("checks whether two lists are equal or not", "[aufgabe4.6]") {
  List<int> l1 {};
  l1.push_back(42); 
  l1.push_back(69);
  l1.push_back(101);
  List<int> l2 {};
  l2.push_back(42);
  l2.push_back(69);
  l2.push_back(101);
  REQUIRE(l1 == l2);

  List<int> l3 {};
  List<int> l4 {};
  REQUIRE(l3 == l4);

  List<int> l5 {};
  l5.push_back(678); 
  l5.push_back(144);
  l5.push_back(123);
  l5.push_back(42);
  l5.push_back(69);
  List<int> l6 {};
  l6.push_back(678); 
  l6.push_back(144);
  l6.push_back(123);
  l6.push_back(42);
  l6.push_back(69);
  REQUIRE(l5 == l6);
}

TEST_CASE("checks whether two lists are different or not", "[aufgabe4.6]") {
  List<int> l1 {};
  l1.push_back(42); 
  l1.push_back(69);
  l1.push_back(101);
  List<int> l2 {};
  l2.push_back(42);
  l2.push_back(4);
  l2.push_back(101);
  REQUIRE(l1 != l2);

  List<int> l3 {};
  l3.push_back(3);
  List<int> l4 {};
  REQUIRE(l3 != l4);

  List<int> l5 {};
  l5.push_back(876); 
  l5.push_back(441);
  l5.push_back(234);
  l5.push_back(24);
  l5.push_back(96);
  List<int> l6 {};
  l6.push_back(678); 
  l6.push_back(144);
  l6.push_back(123);
  l6.push_back(42);
  l6.push_back(69);
  REQUIRE(l5 != l6);
}

TEST_CASE("copy constructor", "[aufgabe4.7]") {
  List<int> list; 
  list.push_front(1); 
  list.push_front(2); 
  list.push_front(3); 
  list.push_front(4); 
  List<int> list2{list}; 
  REQUIRE(list == list2);

  List<int> l1; 
  list.push_front(69); 
  list.push_front(42); 
  list.push_front(101); 
  list.push_front(264); 
  list.push_front(9); 
  List<int> l2{l1}; 
  REQUIRE(l1 == l2);
}

// * --------------- Main --------------- * //

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

// * ----------------------------------- * //