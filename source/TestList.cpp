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

TEST_CASE("inserts a value at certain position", "[aufgabe4.8]") {
  List<int> list; 
  list.push_front(69); 
  list.push_front(42); 
  list.push_front(101); 
  list.push_front(264); 
  list.push_front(9); 
  list.insert(list.begin(), 13);
  REQUIRE(6 == list.size());
  REQUIRE(13 == list.front());
  REQUIRE(69 == list.last());

  List<int> list2; 
  list2.push_front(69); 
  list2.push_front(42); 
  list2.push_front(101); 
  list2.push_front(264); 
  list2.push_front(9); 
  list2.insert(list2.end(), 13);
  REQUIRE(6 == list2.size());
  REQUIRE(9 == list2.front());
  REQUIRE(13 == list2.last());

  List<int> list3; 
  list3.push_front(69); 
  list3.push_front(42); 
  list3.push_front(101); 
  list3.push_front(264); 
  list3.push_front(9); 
  ListIterator<int> pos = list3.begin();
  pos++; // operator test
  ++pos;
  ++pos; // pos now points to position 3
  list3.insert(pos, 13);
  REQUIRE(6 == list3.size());
  REQUIRE(9 == list3.front());
  REQUIRE(69 == list3.last());
  ListIterator<int> it = list3.begin();
  REQUIRE(9 == *it); // pos = 0 / list.begin
  ++it; 
  REQUIRE(264 == *it); // pos = 1 
  ++it;
  REQUIRE(101 == *it); // pos = 2 
  ++it;
  REQUIRE(13 == *it); // pos = 3
}

TEST_CASE("reverses the sequence of the list", "[aufgabe4.9]") {
    // member function
  List<int> list; 
  list.push_back(1); 
  list.push_back(2); 
  list.push_back(3); 
  list.push_back(4); 
  list.push_back(5);
  list.reverse();
  ListIterator<int> it = list.begin();
  REQUIRE(5 == *it);
  ++it;
  REQUIRE(4 == *it);
  ++it; 
  REQUIRE(3 == *it);
  ++it;
  REQUIRE(2 == *it);
  ++it; 
  REQUIRE(1 == *it);

    // non-member function
  reverse(list);
  ListIterator<int> i = list.begin();
  REQUIRE(5 == *i);
  ++i;
  REQUIRE(4 == *i);
  ++i; 
  REQUIRE(3 == *i);
  ++i;
  REQUIRE(2 == *i);
  ++i; 
  REQUIRE(1 == *i);

}

TEST_CASE("copies the list into a std::vector using std::copy", "[aufgabe4.10]") {
  List<int> list; 
  list.push_back(1); 
  list.push_back(2); 
  list.push_back(3); 
  list.push_back(4); 
  list.push_back(5);
  std::vector<unsigned int> viktor(list.size());
  std::copy(list.begin(), list.end(), std::begin(viktor));
  // std::copy(std::begin(viktor), std::end(viktor), std::ostream_iterator<int>(std::cout, "\n"));
  REQUIRE(1 == viktor[0]);
  REQUIRE(2 == viktor[1]);
  REQUIRE(3 == viktor[2]);
  REQUIRE(4 == viktor[3]);
  REQUIRE(5 == viktor[4]);
}

TEST_CASE("assigns elements of one list to another", "[aufgabe4.11]") {
    // member swap
  List<int> l1 {}; 
  l1.push_back(1); 
  l1.push_back(2); 
  l1.push_back(3); 
  l1.push_back(4); 
  l1.push_back(5);

  List<int> l2 {}; 
  l2.push_back(10); 
  l2.push_back(20); 
  l2.push_back(30); 
  l2.push_back(40); 
  l2.push_back(50);

  l1.swap(l2);
  ListIterator<int> i = l1.begin();
  REQUIRE(10 == *i);
  ++i;
  REQUIRE(20 == *i);
  ++i; 
  REQUIRE(30 == *i);
  ++i;
  REQUIRE(40 == *i);
  ++i; 
  REQUIRE(50 == *i);

    // free swap function
  List<int> l5 {}; 
  l5.push_back(1); 
  l5.push_back(2); 
  l5.push_back(3); 
  l5.push_back(4); 
  l5.push_back(5);

  List<int> l6 {}; 
  l6.push_back(10); 
  l6.push_back(20); 
  l6.push_back(30); 
  l6.push_back(40); 
  l6.push_back(50);

  swap(l5, l6);
  ListIterator<int> iter = l5.begin();
  REQUIRE(10 == *iter);
  ++iter;
  REQUIRE(20 == *iter);
  ++iter; 
  REQUIRE(30 == *iter);
  ++iter;
  REQUIRE(40 == *iter);
  ++iter; 
  REQUIRE(50 == *iter);

  ListIterator<int> itera = l6.begin();
  REQUIRE(1 == *itera);
  ++itera;
  REQUIRE(2 == *itera);
  ++itera; 
  REQUIRE(3 == *itera);
  ++itera;
  REQUIRE(4 == *itera);
  ++itera; 
  REQUIRE(5 == *itera);

    // assignment operator
  List<int> l3 {};
  l3.push_back(1); 
  l3.push_back(2); 
  l3.push_back(3); 
  l3.push_back(4); 
  l3.push_back(5);

  List<int> l4 {}; 

  l4 = l3;
  ListIterator<int> ite = l4.begin();
  REQUIRE(1 == *ite);
  ++ite;
  REQUIRE(2 == *ite);
  ++ite; 
  REQUIRE(3 == *ite);
  ++ite;
  REQUIRE(4 == *ite);
  ++ite; 
  REQUIRE(5 == *ite);

}

TEST_CASE("move constructor", "[aufgabe4.12]") {
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  List<int> list2(std::move(list));
  REQUIRE(0 == list.size());
  REQUIRE(list.empty());
  REQUIRE(4 == list2.size());
}

// * --------------- Main --------------- * //

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

// * ----------------------------------- * //