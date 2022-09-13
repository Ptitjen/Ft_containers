#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <cstddef>
#include <functional>
#include <limits>

#include "pair.hpp"
#include "reverse_iterator.hpp"

namespace ft {

/* ******************* NODE BASE ****************** */

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
  //   BstTreeHeader(Content c) {
  //     count = 1;
  //     node.left = &node;
  //     node.right = &node;
  //     node.parent = NULL;
  //     node.content = c.content;
  //   }

  void resetHeader() {
    count = 0;
    node->left = node;
    node->right = node;
    node->parent = NULL;
    // node.content = NULL;
  }
};

// /* ******************* ITERATOR ******************* */
// template <class T>
// class BstIterator {
//  public:
//   typedef T value_type;
//   typedef T& reference;
//   typedef T* pointer;
//   typedef std::bidirectional_iterator_tag iterator_category;
//   typedef std::ptrdiff_t difference_type;

//   typedef Node<T>* node_ptr;

//   node_ptr node;
//   // node = node_ptr::BstBaseNode();

//   /* Constructors and destructor */
//   BstIterator() throw() : node(){};
//   explicit BstIterator(node_ptr ptr) throw() : node(ptr) {}
//   BstIterator(BstIterator const& it) throw() : node(it.node){};
//   BstIterator& operator=(BstIterator const& it) {
//     if (&it == this) return (*this);
//     node = it.node;
//     return (*this);
//   };
//   ~BstIterator() throw(){};

//   /* incrementation and decrementation */
//   BstIterator& operator++() {
//     increment();
//     return *this;
//   }
//   BstIterator operator++(int) {
//     BstIterator it = *this;
//     increment();
//     return it;
//   }

//   BstIterator& operator--() {
//     decrement();
//     return *this;
//   }
//   BstIterator operator--(int) {
//     BstIterator it = *this;
//     decrement();
//     return it;
//   }

//   reference operator*() { return
//   *static_cast<node_ptr>(node)->content_ptr(); } pointer operator->() {
//   return static_cast<node_ptr>(node)->content_ptr();
//   }

//   /* comparison */
//   bool operator==(const BstIterator& other) { return node == other.node; }
//   bool operator!=(const BstIterator& other) { return !(node == other.node);
//   }

//   void increment() {
//     // if (node->parent == NULL) {  // START NODE
//     //   node = node->right;
//     //   while (node->left != NULL) node = node->left;
//     // } else
//     if (node->right != NULL) {
//       node = node->right;
//       while (node->left != NULL) node = node->left;

//     } else if (node == node->parent->left) {  // LEFT NODE
//       node = node->parent;
//     } else if (node == node->parent->right) {  // RIGHT NODE
//       while (!(node == node->parent->left)) node = node->parent;
//       node = node->parent;
//     }
//   }

//   void decrement() {
//     // if (node->parent == NULL) {
//     //   node = node->left;
//     //   while (node->right != NULL) node = node->right;
//     // } else
//     if (node->left != NULL) {
//       node = node->left;
//       while (node->right != NULL) node = node->right;
//     } else if (node == node->parent->right) {  // RIGHT NODE
//       node = node->parent;
//     } else if (node == node->parent->left) {
//       while (!(node == node->parent->right)) node = node->parent;
//       node = node->parent;
//     }
//   }
// };

// template <class T>
// class BstConstIterator {
//  public:
//   typedef T value_type;
//   typedef T& reference;
//   typedef T* pointer;
//   typedef std::bidirectional_iterator_tag iterator_category;
//   typedef std::ptrdiff_t difference_type;

//   typedef Node<T>* node_ptr;

//   node_ptr node;

//   /* Constructors and destructor */
//   BstConstIterator() throw() : node(){};
//   explicit BstConstIterator(node_ptr ptr) throw() : node(ptr) {}
//   BstConstIterator(BstConstIterator const& it) throw() : node(it.node){};
//   BstConstIterator& operator=(BstConstIterator const& it) {
//     if (&it == this) return (*this);
//     node = it.node;
//     return (*this);
//   };
//   ~BstConstIterator() throw(){};

//   /* incrementation and decrementation */
//   BstConstIterator& operator++() {
//     increment();
//     return *this;
//   }
//   BstConstIterator operator++(int) {
//     BstConstIterator it = *this;
//     increment();
//     return it;
//   }

//   BstConstIterator& operator--() {
//     decrement();
//     return *this;
//   }
//   BstConstIterator operator--(int) {
//     BstConstIterator it = *this;
//     decrement();
//     return it;
//   }

//   reference operator*() { return *(node)->content_ptr(); }
//   pointer operator->() { return (node)->content_ptr(); }

//   /* comparison */
//   bool operator==(const BstConstIterator& other) { return node ==
//   other.node; } bool operator!=(const BstConstIterator& other) {
//     return !(node == other.node);
//   }

//   void increment() {
//     // if (node->parent == NULL) {  // START NODE
//     //   node = node->right;
//     //   while (node->left != NULL) node = node->left;
//     // } else
//     if (node->right != NULL) {
//       node = node->right;
//       while (node->left != NULL) node = node->left;

//     } else if (node == node->parent->left) {  // LEFT NODE
//       node = node->parent;
//     } else if (node == node->parent->right) {  // RIGHT NODE
//       while (!(node == node->parent->left)) node = node->parent;
//       node = node->parent;
//     }
//   }

//   void decrement() {
//     // if (node->parent == NULL) {
//     //   node = node->left;
//     //   while (node->right != NULL) node = node->right;
//     // } else
//     if (node->left != NULL) {
//       node = node->left;
//       while (node->right != NULL) node = node->right;
//     } else if (node == node->parent->right) {  // RIGHT NODE
//       node = node->parent;
//     } else if (node == node->parent->left) {
//       while (!(node == node->parent->right)) node = node->parent;
//       node = node->parent;
//     }
//   }
// };

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

  class const_iterator {};

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
  }

  BstTree(node_ptr startNode) {  // tree from node
    _startNode = a.allocate(1);
    _startNode = startNode;
    header = BstTreeHeader<value_type, Allocator>();
  }
  /*
    template <class InputIterator>
    BstTree(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()){};

    BstTree(const BstTree& x){};*/

  /**************** ACCESS ************/

  iterator begin() {
    iterator itb(_startNode);
    while (itb.node->left) {
      itb.node = itb.node->left;
    };

    return itb;
  }
  const_iterator cbegin() const {
    const_iterator itb(_startNode);
    while (itb.node->left) {
      itb.node = itb.node->left;
    };

    return itb;
  }

  iterator last() {
    iterator itl(_startNode);
    while (itl.node->right && itl.node->right != header.node) {  //??
      itl.node = itl.node->right;
    };
    // itl.node->right = &header.node;
    return itl;
  }  // remove when it & end ok

  const_iterator last() const {
    const_iterator itl(_startNode);
    while (itl.node->right && itl.node->right != header.node) {  // /
      itl.node = itl.node->right;
    };

    return itl;
  }  // remove when it & end ok

  iterator end() { return header.node; }

  const_iterator cend() const { return header.node; }

  reverse_iterator rbegin() { return reverse_iterator(end()); }
  const_reverse_iterator crbegin() const { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator crend() const { return reverse_iterator(begin()); }

  template <typename A, typename B>
  bool f(A a, B b, std::less<Key> u = std::less<Key>()) {
    return u(a, b);
  }

  /* ********* CAPACITY ********* */

  bool empty() { return header.count == 0; }

  std::size_t size() { return header.count; }

  std::size_t max_size() { return std::numeric_limits<std::size_t>::max(); }

  iterator find(const key_type& k) {}

  const_iterator find(const key_type& k) const {}

  // HERE

  node_ptr search(const key_type& key, node_ptr root) {
    if (root == NULL) {
      std::cout << key << " not found" << std::endl;
      return NULL;
    }
    if (root->content.first == key) return root;  // found
    if (f(root->content.first, key)) {
      if (root->right == header.node) {
        std::cout << key << " not found - bigger"
                  << std::endl;  // bigger then last
        return NULL;
      }
      return search(key, root->right);
    }
    return search(key, root->left);
  }

  void addNode(value_type newValue) {
    /* ALREADY EXISTS */
    node_ptr n = search(newValue.first, _startNode);
    if (n != NULL) {
      std::cout << newValue.first << " already exists - replacing old value"
                << std::endl;
      n->content = newValue;
    }
    // if (f(x->content.first, begin()->content.first)) {
    //   std::cout << "Add node at beginning" << std::endl;  // new first
    //   (begin())->left = a.allocate(1);
    //   begin()->left = &x;
    //   begin()->left->parent = begin();
    //   resetHeader();
    //   return;
    // }
    // /* LAST */

    // if (!f((x.content).first, last()->content.first)) {
    //   std::cout << "Add node at end" << std::endl;  // new first
    //   last()->right = a.allocate(1);
    //   last()->right = &x;
    //   last()->right->parent = last();
    //   resetHeader();
    //   return;

    /* Find position */
  }

  void resetHeader() {
    iterator it = last();
    it.node->right = header.node;
    header.node->parent = it.node;

    // y'a de l'idee mais ca marche pas encore

    // while (it.node->right) it.node = it.node->right;
    // it.node->right = header.node;
    // itl.node->right = &header.node;
    // header.node.right->right = header.node;
  };

  Node<value_type>* getStart() { return _startNode; };

  /************ MEMBER VALUES ************/
 private:  // put back when ok
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


Element access:

operator[]
    Access element (public member function)

at
    Access element (public member function)


Modifiers:

insert
    Insert elements (public member function)

erase
    Erase elements (public member function)

swap
    Swap content (public member function)

clear
    Clear content (public member function)

emplace
    Construct and insert element (public member function)

emplace_hint
    Construct and insert element with hint (public member function)


Observers:

key_comp
    Return key comparison object (public member function)

value_comp
    Return value comparison object (public member function)


Operations:

find
    Get iterator to element (public member function)

count
    Count elements with a specific key (public member function)

lower_bound
    Return iterator to lower bound (public member function)

upper_bound
    Return iterator to upper bound (public member function)

equal_range
    Get range of equal elements (public member function)


Allocator:

get_allocator
    Get allocator (public member function)*/