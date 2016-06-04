// list.hpp (Programmiersprachen Aufgabe 4)

#ifndef BUW_LIST_HPP 
#define BUW_LIST_HPP
#include <cstddef> 
#include <utility>

template <typename T>
class List;

template <typename T>
struct ListNode {
  ListNode() : m_value {}, m_prev {nullptr}, m_next {nullptr} {}
  ListNode(T const& v, ListNode* prev, ListNode* next) : 
  m_value{v}, m_prev{prev}, m_next{next} {}

  T m_value; // value
  ListNode* m_prev; // pointer to next node
  ListNode* m_next; // pointer to previous node
};

template <typename T>
struct ListIterator {
  typedef ListIterator<T> Self;
  typedef T value_type; 
  typedef T* pointer; 
  typedef T& reference; 
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  friend class List<T>;

  ListIterator() : m_node {nullptr} {}
  ListIterator(ListNode<T>* n) : m_node {n} {}

    // https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
    // Indirection: *a ("object pointed to by a")
  reference operator * () const {
    return m_node -> m_value; // value pointed to by m_node
  } 

    // Structure dereference: a -> b ("member b of object pointed to by a")
  pointer operator -> () const { // equal to (*a).b
    return &(m_node -> m_value); // address-of
  } 

    // Increment: Prefix ++a
  Self& operator ++ () {
    if (m_node) {
      m_node = m_node -> m_next; // m_node now points to the next node
    }
    return *this; // returns m_node
  } 

    // Increment: Postfix a++ 
  Self operator ++ (int) { // int => dummy parameter used to differentiate between prefix and postfix version
    Self temp = *this; // creates copy
    ++(*this); // pre-increment 
    return temp;   // returns the copy from before the increment
  } 

    // Checks whether the node the iterator is pointing to is equal to the one of object x 
  bool operator == (const Self& x) const {
    return m_node == x.m_node;
  } 

    // Checks whether the node the iterator is pointing to isn't equal to the one of object x 
  bool operator != (const Self& x) const {
    return m_node != x.m_node;
  } 

  Self next() const {
    if (m_node)
      return ListIterator(m_node -> m_next);
    else
      return ListIterator(nullptr);
  }

  Self prev() const {
    if (m_node)
      return ListIterator(m_node -> m_prev);
    else
      return ListIterator(nullptr);
  }

private:
    // The Node the iterator is pointing to 
  ListNode<T>* m_node = nullptr;
};

template <typename T>
struct ListConstIterator {
  friend class List<T>;
public:
// not implemented yet
private:
  ListNode<T>* m_node = nullptr;
};

template <typename T>
class List {
public: 
  // Default Constructor
  typedef T value_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference; 
  typedef const T& const_reference;
  typedef ListIterator<T> iterator; 
  typedef ListConstIterator<T> const_iterator;

  friend class ListIterator<T>;
  friend class ListConstIterator<T>;

    // default-constructor
  List(): m_size {0}, m_first {nullptr}, m_last {nullptr} {} //myFirstConstructor

    // copy-constructor 
  List(List<T> const& listC): m_size {0}, m_first {nullptr}, m_last {nullptr} {
    for (iterator i = listC.begin(); i != listC.end(); ++i) {
      push_back(*i); // protip ;-)
    }
  }

    // move-constructor
  List(List&& listM): m_size {listM.m_size}, m_first {listM.m_first}, m_last {listM.m_last} { // steals list elements from listM
    listM.m_size = 0;
    listM.m_first = nullptr;
    listM.m_last = nullptr; // listM is now empty
  }

    // the assignment operator assigns the elements of one list to another
  List<T>& operator = (List<T> list) { // copy-construct by passing by-value
    swap(list); // swap memberwise
    return *this; // destructor call for list (contains old *this)
  }

    // swaps contents of list with *this
  void swap(List<T>& list) {
      std::swap(m_size, list.m_size);
      std::swap(m_first, list.m_first);
      std::swap(m_last, list.m_last);
  }

    // free swap function in namespace of List
  friend void swap(List<T>& l1, List<T>& l2) {
    l1.swap(l2);
  }

    // destructor 
  ~List() {
    clear(); // deletes all elements from the list
  }

    // boolean that states whether a list is empty or not 
  bool empty() const {
    return m_size == 0;
  }

    // gets the size of a list
  std::size_t size() const {
    return m_size;
  }

    // gets first element of the list
  T const& front() const {
    return (*m_first).m_value; // m_first -> m_value
  }

  T& front() {
    return (*m_first).m_value; // m_first -> m_value
  }

    // adds new first element to the list
  void push_front(T const& a) {
    if (m_size == 0) {
      m_first = new ListNode<T>{a, nullptr, nullptr};
      m_last = m_first;
    }

    else if (m_size >= 1) {
      m_first = new ListNode<T>{a, nullptr, m_first};
      m_first -> m_next -> m_prev = m_first;
    }

    ++m_size;
  }

    // removes first element of the list
  void pop_front() {
    if (m_size == 1) {
      assert(m_first != nullptr);
      delete m_first;
      m_first = nullptr;
      m_size = 0;
    }

    else if (m_size > 1) {
      assert(m_first != nullptr);
      delete m_first;
      m_first = m_first -> m_next;
      --m_size;
    }
  }

    // gets last element of the list
  T const& last() const {
    return (*m_last).m_value; // m_last -> m_value
  }

  T& last() {
    return (*m_last).m_value; // m_last -> m_value
  }

    // adds new last element to the list
  void push_back(T const& a) {
    if (m_size == 0) {
      m_last = new ListNode<T>{a, nullptr, nullptr};
      m_first = m_last;
    }

    else if (m_size >= 1) {
      m_last = new ListNode<T>{a, m_last, nullptr};
      m_last -> m_prev -> m_next = m_last;
    }

    ++m_size;
  }

    // removes last element of the list
  void pop_back() {
    if (m_size == 1) {
      assert(m_last != nullptr);
      delete m_last;
      m_last = nullptr;
      m_size = 0;
    }

    else if (m_size > 1) {
      assert(m_last != nullptr);
      delete m_last;
      m_last = m_last -> m_prev;
      --m_size;
    }
  }

    // removes all elements from the list
  void clear() {
    while (m_size > 0) {
      pop_front();
    }
  }

  	// iterator points to m_first
  iterator begin() const {
  	return iterator {m_first};
  }

  	// iterator points to the element behind m_last
  iterator end() const {
  	return iterator {};
  }

    // inserts given value at given position
  void insert(iterator pos, T const& value) {

    if (pos == begin()) { // inserts value at beginning of the list
      push_front(value);
    }

    else if (pos == end()) { // inserts value at the end of the list
      push_back(value);
    }

    else {
      ListNode <T>* insertNode = new ListNode<T> {value, pos.prev().m_node, pos.m_node};

      pos.prev().m_node -> m_next = insertNode;
      pos.m_node -> m_prev = insertNode;
      ++m_size; // increments size of the list
    }
  }

    // reverses the sequence of the list the function is called on
  void reverse() {
    List<T> tmp{*this}; // creates copy of our list
    clear(); // clears list
    for (iterator it = tmp.begin(); it != tmp.end(); ++it) {
      push_front(*it); // iterates the list tmp and reverses sequence of our initial list by using push_front()
    }
  }


private:
  std::size_t m_size = 0;
  ListNode<T>* m_first = nullptr;
  ListNode<T>* m_last = nullptr;
};


  // checks whether two lists are equal 
template<typename T>
bool operator == (List<T> const& xs, List<T> const& ys) {
	bool result = true;

	if (xs.size() != ys.size()) { // size needs to be equal for lists to be equal
		result = false;
	}

	else {
		ListIterator<T> xs_it = xs.begin(); 
		ListIterator<T> ys_it = ys.begin();

		while (xs_it != xs.end() && ys_it != ys.end()) { // from beginning to end 
			if (*xs_it != *ys_it) { // checks whether an element in list xs is not equal to element in list ys at the same position
				result = false;
        break;
			}

			++xs_it; // increments iterators to next node
			++ys_it;
		}
	}

	return result;
}

  // checks whether two lists are different
template<typename T>
bool operator != (List<T> const& xs, List<T> const& ys) {
	return !(xs == ys);
}
  
  // takes a given List and reverses its sequence
template<typename T>
List<T> reverse (List<T> revList) {
  revList.reverse();
  return revList; // returns new list with reversed sequence
}


#endif // #define BUW_LIST_HPP
