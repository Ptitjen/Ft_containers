#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <cstddef>
#include <functional>
#include <limits>
#include <stdexcept>

#include "pair.hpp"
#include "reverse_iterator.hpp"

namespace ft {

/* ******************* NODE ****************** */

template <class Content>
class Node {
 public:
  Node() : parent(NULL), left(NULL), right(NULL) {}
  Node(Content c) : parent(NULL), left(NULL), right(NULL), content(c){};
  Node(const Node& other) : content(other.content) {
    left = other.left;
    right = other.right;
    parent = other.parent;
  }

  Node& operator=(const Node& other) {
    if (&other == this) return (*this);
    left = other.left;
    right = other.right;
    content = other.content;
    parent = other.parent;
    return (*this);
  }

  ~Node(){};

  Content content;
  Node* parent;
  Node* left;
  Node* right;

  Content* content_ptr() { return &content; }
  Content const* content_ptr() const { return &content; }
};

/* ****************** TREEHEADER ****************** */
template <class Content, class Allocator>
class BstTreeHeader {  // left : begin, self : end
 public:
  Node<Content>* node;
  std::size_t count;

  BstTreeHeader() {
    Allocator a;
    node = a.allocate(1);
    resetHeader();
  };

  void resetHeader() {
    count = 0;
    node->left = node;
    node->right = node;
    node->parent = NULL;
    // node.content = NULL;
  }
};

/* ******************* BST TREE ****************** */
template <class Key, class Value, class Compare = std::less<Key>,
          class Allocator = std::allocator<Node<pair<Key, Value> > > >

class BstTree {
  class iterator {
   public:
    typedef Node<pair<Key, Value> > value_type;
    typedef Node<pair<Key, Value> >& reference;
    typedef Node<pair<Key, Value> >* pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    /* Constructors and destructor */
    iterator() throw() : node(NULL){};
    iterator(pointer ptr) throw() : node(ptr) {}
    iterator(iterator const& it) throw() : node(it.node){};
    iterator& operator=(iterator const& it) {
      if (&it == this) return (*this);
      node = it.node;
      return (*this);
    };
    ~iterator() throw(){};

    /* incrementation and decrementation */
    iterator& operator++() {
      increment();
      return *this;
    }
    iterator operator++(int) {
      iterator it = *this;
      increment();
      return it;
    }

    iterator& operator--() {
      decrement();
      return *this;
    }
    iterator operator--(int) {
      iterator it = *this;
      decrement();
      return it;
    }

    reference operator*() { return *node(); }  // see this
    pointer operator->() { return node; }      // and this

    /* comparison */
    bool operator==(const iterator& rhs) {
      return node == rhs.node;
    }  // check this
    bool operator!=(const iterator& rhs) { return !(node == rhs.node); }

    void increment() {
      if (node->right != NULL) {
        node = node->right;
        if (node->left == node) return;  // headernode
        while (node->left != NULL) node = node->left;
      } else if (node == node->parent->left) {  // LEFT NODE
        node = node->parent;
      } else if (node == node->parent->right) {  // RIGHT NODE
        while (!(node == node->parent->left)) node = node->parent;
        node = node->parent;
      }
    }

    void decrement() {
      if (node->left == node)
        node = node->parent;  // end
      else if (node->left != NULL) {
        node = node->left;
        while (node->right != NULL) node = node->right;
      } else if (node == node->parent->right) {  // RIGHT NODE
        node = node->parent;
      } else if (node == node->parent->left) {
        while (!(node == node->parent->right)) node = node->parent;
        node = node->parent;
      }
    }

    pointer node;
  };

  /* **************** const iterator *************** */

  class const_iterator {
   public:
    typedef Node<pair<Key, Value> > value_type;
    typedef Node<pair<Key, Value> >& reference;
    typedef Node<pair<Key, Value> >* pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    /* Constructors and destructor */
    const_iterator() throw() : node(NULL){};
    const_iterator(pointer ptr) throw() : node(ptr) {}
    const_iterator(const_iterator const& it) throw() : node(it.node){};
    const_iterator& operator=(const_iterator const& it) {
      if (&it == this) return (*this);
      node = it.node;
      return (*this);
    };
    ~const_iterator() throw(){};

    /* incrementation and decrementation */
    const_iterator& operator++() {
      increment();
      return *this;
    }
    const_iterator operator++(int) {
      iterator it = *this;
      increment();
      return it;
    }

    const_iterator& operator--() {
      decrement();
      return *this;
    }
    const_iterator operator--(int) {
      iterator it = *this;
      decrement();
      return it;
    }

    reference operator*() const { return *node(); }  // see this
    pointer operator->() const { return node; }      // and this

    /* comparison */
    bool operator==(const const_iterator& rhs) {
      return node == rhs.node;
    }  // check this
    bool operator!=(const const_iterator& rhs) { return !(node == rhs.node); }

    void increment() {
      if (node->right != NULL) {
        node = node->right;
        if (node->left == node) return;  // headernode
        while (node->left != NULL) node = node->left;
      } else if (node == node->parent->left) {  // LEFT NODE
        node = node->parent;
      } else if (node == node->parent->right) {  // RIGHT NODE
        while (!(node == node->parent->left)) node = node->parent;
        node = node->parent;
      }
    }

    void decrement() {
      if (node->left == node)
        node = node->parent;  // end
      else if (node->left != NULL) {
        node = node->left;
        while (node->right != NULL) node = node->right;
      } else if (node == node->parent->right) {  // RIGHT NODE
        node = node->parent;
      } else if (node == node->parent->left) {
        while (!(node == node->parent->right)) node = node->parent;
        node = node->parent;
      }
    }

    pointer node;
  };

 public:
  typedef Key key_type;
  typedef Value mapped_type;
  typedef pair<Key, Value> value_type;
  typedef Compare key_compare;

  typedef Allocator allocator_type;
  // typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::size_type size_type;
  // typedef typename allocator_type::difference_type difference_type;
  // typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  typedef Node<value_type>* node_ptr;

  typedef iterator iterator;
  typedef const_iterator const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  class value_compare {
  };  // check what is this - nested function class to compare values

  /************* CONSTRUCTORS **************/

  explicit BstTree(const key_compare& comp = key_compare(),
                   const allocator_type& alloc = allocator_type())
      : a(alloc){};

  BstTree(value_type startNodeValue) {  // tree from value
    _startNode = a.allocate(1);
    _startNode->content = startNodeValue;
    header = BstTreeHeader<value_type, Allocator>();
    resetHeader();
  }

  BstTree(node_ptr startNode) {  // tree from node
    _startNode = a.allocate(1);
    _startNode = startNode;
    header = BstTreeHeader<value_type, Allocator>();
    resetHeader();
  }
  /*
    template <class InputIterator>
    BstTree(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()){};

    BstTree(const BstTree& x){};*/
  BstTree& operator=(const BstTree& other) {
    if (&other == this) return *this;
    header = BstTreeHeader<value_type, Allocator>();

    _startNode = copy(other._startNode);
    resetHeader();
    return *this;
  }
  ~BstTree(){};  // dealloc

  node_ptr copy(const node_ptr& originalNode) {  // NOLINT
    if (originalNode == NULL) {
      return NULL;
    }
    // not working - segfault
    Node<value_type>* newNode;
    newNode = a.allocate(1);
    if (originalNode->parent == NULL) newNode->parent = NULL;

    newNode->content = originalNode->content;
    newNode->left = copy(originalNode->left);
    if (newNode->left) newNode->left->parent = newNode;
    newNode->right = copy(originalNode->right);
    if (newNode->right) newNode->right->parent = newNode;
    return newNode;
  }

  /* ********* CAPACITY ********* */

  bool empty() { return header.count == 0; }
  std::size_t size() { return header.count; }
  std::size_t max_size() { return std::numeric_limits<std::size_t>::max(); }

  /* *********************************************************************** */
  /*                             ELEMENT ACCESS                              */
  /* *********************************************************************** */
  iterator begin() {
    iterator itb(_startNode);
    while (itb.node->left) {
      itb.node = itb.node->left;
    };
    return itb;
  }
  iterator end() { return header.node; }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }

  iterator find(const key_type& k) {
    return iterator(searchToFind(k, _startNode));
  }
  const_iterator find(const key_type& k) const {
    return const_iterator(searchToFind(k, _startNode));
  }

  mapped_type& operator[](const key_type& k) {  // inserts element if not found
    node_ptr n = searchToAdd(k, _startNode);
    if (n->content.first == k) return n->content.second;
    Node<value_type>* newNode;
    newNode = a.allocate(1);
    newNode->content.first = k;
    newNode->content.second = Value();
    newNode->left = NULL;
    newNode->right = NULL;
    if (f(k, n->content.first)) {
      n->left = newNode;
      newNode->parent = n;
    } else {
      if (n->right == header.node) {
        newNode->right = header.node;
        header.node->parent = newNode;
      }
      n->right = newNode;
      newNode->parent = n;
    }
    resetHeader();
    return newNode->content.second;
  };

  mapped_type& at(const key_type& k) {
    node_ptr n = searchToAdd(k, _startNode);
    if (n->content.first == k) {  // replace
      return n->content.second;
    }
    throw std::out_of_range("");
  };
  const mapped_type& at(const key_type& k) const {
    node_ptr n = searchToAdd(k, _startNode);
    if (n->content.first == k) {  // replace
      return n->content.second;
    }
    throw std::out_of_range("");
  };

  /* *********************************************************************** */
  /*                                  OTHER                                  */
  /* *********************************************************************** */
  Allocator get_allocator() { return a; }

  /* *********************************************************************** */
  /*                                  UTILS                                  */
  /* *********************************************************************** */

  /*** Utils : put all in private when finished ***/
  Node<value_type>* getStart() { return _startNode; };

  void addNode(value_type newValue) {
    node_ptr n = searchToAdd(newValue.first, _startNode);
    if (n->content.first == newValue.first) {  // replace
      n->content = newValue;
    } else {
      Node<value_type>* newNode;
      newNode = a.allocate(1);
      newNode->content = newValue;
      newNode->left = NULL;
      newNode->right = NULL;
      if (f(newValue.first, n->content.first)) {
        n->left = newNode;
        newNode->parent = n;
      } else {
        if (n->right == header.node) {
          newNode->right = header.node;
          header.node->parent = newNode;
          n->right = newNode;
          newNode->parent = n;
          return;
        }
        n->right = newNode;
        newNode->parent = n;
      }
    }
    resetHeader();
  }

  void resetHeader() {
    iterator it = last();
    it.node->right = header.node;
    header.node->parent = it.node;
  };

 private:
  template <typename A, typename B>
  bool f(A a, B b, std::less<Key> u = std::less<Key>()) {
    return u(a, b);
  }

  iterator last() {
    iterator itl(_startNode);
    while (itl.node->right && itl.node->right != header.node) {  //??
      itl.node = itl.node->right;
    };
    return itl;
  }  // remove if not needed anymore when it & end ok

  const_iterator last() const {
    const_iterator itl(_startNode);
    while (itl.node->right && itl.node->right != header.node) {  // /
      itl.node = itl.node->right;
    };
    return itl;
  }  // remove when it & end ok
  node_ptr searchToFind(const key_type& key, node_ptr root) {
    if (root == NULL) return header.node;
    if (root->content.first == key) return root;
    if (f(root->content.first, key)) {
      if (root->right == header.node) return header.node;
      return searchToFind(key, root->right);
    }
    return searchToFind(key, root->left);
  }

  node_ptr searchToAdd(const key_type& key, node_ptr root) {
    if (root == NULL) {
      std::cout << key << " NULL - ERROR" << std::endl;
      return NULL;
    }
    if (root->content.first == key) return root;  // found
    if (f(root->content.first, key)) {
      if (root->right == header.node) return header.node->parent;
      if (root->right == NULL)  //  does not exist but not biggest
        return root;
      return searchToAdd(key, root->right);
    }
    if (root->left == NULL)  //  does not exist
      return root;
    return searchToAdd(key, root->left);
  }

  /* *********************************************************************** */
  /*                               MEMBER VALUES                             */
  /* *********************************************************************** */
  allocator_type a;
  BstTreeHeader<value_type, Allocator> header;
  Node<value_type>* _startNode;
  Node<value_type>* endNode;
};
}  // namespace ft

#endif

/*
(constructor)
    Construct map (public member function)

(destructor)
    Map destructor (public member function)

operator=
    Copy container content (public member function)


Modifiers:

insert
    Insert elements (public member function)

erase
    Erase elements (public member function)

swap
    Swap content (public member function)

clear
    Clear content (public member function)


Observers:

key_comp
    Return key comparison object (public member function)

value_comp
    Return value comparison object (public member function)


Operations:

count
    Count elements with a specific key (public member function)

lower_bound
    Return iterator to lower bound (public member function)

upper_bound
    Return iterator to upper bound (public member function)

equal_range
    Get range of equal elements (public member function)



NON MEMBER :
relational op
swap
*/
