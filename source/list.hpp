// list.hpp (Programmiersprachen Aufgabe 4)

#ifndef BUW_LIST_HPP 
#define BUW_LIST_HPP
#include <cstddef> 

template <typename T>
class List;

template <typename T>
struct ListNode {
  ListNode() : m_value {}, m_prev {nullptr}, m_next {nullptr} {}
  ListNode(T const& v, ListNode* prev, ListNode* next) : 
  m_value{v}, m_prev{prev}, m_next{next} {}

  T m_value;
  ListNode* m_prev;
  ListNode* m_next;
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
  pointer operator -> () const {
    return;
  } 

    // Increment: Prefix ++a
  Self& operator ++ () {
    if (m_node) {
      m_node = m_node -> m_next; // m_node now points to the next element
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

  List(): m_size {0}, m_first {nullptr}, m_last {nullptr} {} //myFirstConstructor

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

// not implemented yet 
private:
  std::size_t m_size = 0;
  ListNode<T>* m_first = nullptr;
  ListNode<T>* m_last = nullptr;
};

#endif // #define BUW_LIST_HPP
