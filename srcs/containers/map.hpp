#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>
#include <exception>
#include <functional>
#include <limits>
#include <stdexcept>

#include "../functions/enable_if.hpp"
#include "../functions/is_integral.hpp"
#include "../functions/pair.hpp"

namespace ft {

/* *********************************************************************** */
/*                             NODE                                        */
/* *********************************************************************** */

template <class Content>
class Node {
 public:
  Node()
      : parent(NULL),
        left(NULL),
        right(NULL),
        left_height(0),
        right_height(0){};

  Node(Content c)
      : parent(NULL),
        left(NULL),
        right(NULL),
        left_height(0),
        right_height(0),
        content(c){};

  Node(const Node& other) : content(other.content) {
    left = other.left;
    right = other.right;
    parent = other.parent;
    left_height = other.left_height;
    right_height = other.right_height;
  }

  Node& operator=(const Node& other) {
    if (&other == this) return (*this);
    left = other.left;
    right = other.right;
    content = other.content;
    parent = other.parent;
    left_height = other.left_height;
    right_height = other.right_height;
    return (*this);
  }

  ~Node() { content.~Content(); };

  Content content;
  Node* parent;
  Node* left;
  Node* right;

  std::size_t left_height;
  std::size_t right_height;
};

/* *********************************************************************** */
/*                             TREE HEADER                                 */
/* *********************************************************************** */
template <class Content, class Allocator, class Key, class Value>
class mapHeader {
 public:
  typedef typename Allocator::template rebind<Node<pair<Key, Value> > >::other
      node_allocator;
  mapHeader() {
    count = 0;
    endNode.left = &endNode;
    endNode.right = &endNode;
    endNode.parent = NULL;

    rendNode.left = &rendNode;
    rendNode.right = &rendNode;
    rendNode.parent = NULL;
  };

  ~mapHeader(){};

  node_allocator a;
  Node<Content> rendNode;
  Node<Content> endNode;
  std::size_t count;
};

/* *********************************************************************** */
/*                                TREE                                     */
/* *********************************************************************** */
template <class Key, class Value, class Compare = std::less<Key>,
          class Allocator = std::allocator<pair<const Key, Value> > >

class map {
  /* *********************************************************************** */
  /*                                ITERATOR                                 */
  /* *********************************************************************** */
 public:
  class iterator {
   public:
    typedef Node<pair<Key, Value> > value_type;
    typedef Node<pair<Key, Value> >& node_reference;
    typedef Node<pair<Key, Value> >* node_pointer;
    typedef ft::pair<Key, Value>& reference;
    typedef ft::pair<Key, Value>* pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    /* Constructors and destructor */
    iterator() throw() : node(NULL){};
    iterator(value_type node) : node(&node){};
    iterator(node_pointer ptr) throw() : node(ptr) {}

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

    reference operator*() { return (node->content); }
    pointer operator->() { return &node->content; }

    /* comparison */
    bool operator==(const iterator& rhs) { return node == rhs.node; }
    bool operator!=(const iterator& rhs) { return !(node == rhs.node); }

    void increment() {
      if (node->right == node && node->parent->left == node)
        node = node->parent;  // NOLINT
      else if (node->right != NULL) {
        node = node->right;
        if (node->left == node) return;
        while (node->left != NULL) node = node->left;
      } else if (node == node->parent->left) {
        node = node->parent;
      } else if (node == node->parent->right) {
        while (!(node == node->parent->left)) node = node->parent;
        node = node->parent;
      }
    }

    void decrement() {
      if (node->left == node && node->parent->right == node)
        node = node->parent;  // NOLINT
      else if (node->left != NULL && node->left != node) {
        node = node->left;
        while (node->right != NULL && node->right != node) node = node->right;
      } else if (node == node->parent->right) {
        node = node->parent;
      } else if (node == node->parent->left) {
        while (!(node == node->parent->right)) node = node->parent;
        node = node->parent;
      }
    }

    node_pointer node;
  };

  /* *********************************************************************** */
  /*                            CONST ITERATOR                               */
  /* *********************************************************************** */
  class const_iterator {
   public:
    typedef const Node<pair<Key, Value> > value_type;
    typedef const Node<pair<Key, Value> >& node_reference;
    typedef const Node<pair<Key, Value> >* node_pointer;
    typedef const ft::pair<Key, Value>& reference;
    typedef const ft::pair<Key, Value>* pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    /* Constructors and destructor */
    const_iterator() throw() : node(NULL){};
    const_iterator(value_type node) throw() : node(&node) {}
    const_iterator(node_pointer ptr) throw() : node(ptr) {}
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
      const_iterator it = *this;
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
    reference operator*() const { return node->content; }
    pointer operator->() const { return &node->content; }

    /* comparison */
    bool operator==(const const_iterator& rhs) { return node == rhs.node; }
    bool operator!=(const const_iterator& rhs) { return !(node == rhs.node); }

    void increment() {
      if (node->right == node && node->parent->left == node)
        node = node->parent;  // NOLINT
      else if (node->right != NULL) {
        node = node->right;
        if (node->left == node) return;
        while (node->left != NULL) node = node->left;
      } else if (node == node->parent->left) {
        node = node->parent;
      } else if (node == node->parent->right) {
        while (!(node == node->parent->left)) node = node->parent;
        node = node->parent;
      }
    }

    void decrement() {
      if (node->left == node && node->parent->right == node)
        node = node->parent;  // NOLINT
      else if (node->left != NULL && node->left != node) {
        node = node->left;
        while (node->right != NULL && node->right != node) node = node->right;
      } else if (node == node->parent->right) {
        node = node->parent;
      } else if (node == node->parent->left) {
        while (!(node == node->parent->right)) node = node->parent;
        node = node->parent;
      }
    }

    node_pointer node;
  };
  /* *********************************************************************** */
  /*                            REVERSE ITERATOR */
  /* *********************************************************************** */
  class reverse_iterator {
   public:
    typedef iterator iterator_type;
    typedef typename iterator::difference_type difference_type;
    typedef ft::pair<Key, Value>& reference;
    typedef ft::pair<Key, Value>* pointer;
    reverse_iterator() throw() : current(NULL){};
    explicit reverse_iterator(iterator x) throw() : current(x){};

    reverse_iterator(const reverse_iterator& u) throw() : current(u.current){};
    reverse_iterator& operator=(reverse_iterator const& it) throw() {  // PB?
      if (&it == this) return (*this);
      ptr_(it.ptr_);
      return (*this);
    };
    ~reverse_iterator() throw(){};

    iterator base() const {
      iterator it = current;
      it++;
      return it;
    };

    reference operator*() { return *current; };
    pointer operator->() { return &(*current); };

    reverse_iterator& operator++() {
      current--;
      return *this;
    };

    reverse_iterator operator++(int) {
      reverse_iterator it = *this;
      current--;
      return it;
    };

    reverse_iterator& operator--() {
      current++;
      return *this;
    };

    reverse_iterator operator--(int) {
      reverse_iterator it = *this;
      current++;
      return it;
    };

    bool operator==(const reverse_iterator& rhs) {
      return current == rhs.current;
    }
    bool operator!=(const reverse_iterator& rhs) {
      return current != rhs.current;
    }

   protected:
    iterator current;
  };

  /* ***************** const reverse operator **************** */

  class const_reverse_iterator {
    typedef iterator iterator_type;
    typedef typename iterator::difference_type difference_type;
    typedef typename iterator::reference reference;
    typedef typename iterator::pointer pointer;
    const_reverse_iterator() throw() : current(NULL){};
    explicit const_reverse_iterator(iterator x) throw() : current(x){};

    const_reverse_iterator(const_reverse_iterator& u) throw()
        : current(u.current){};
    const_reverse_iterator& operator=(
        const_reverse_iterator const& it) throw() {
      if (&it == this) return (*this);
      ptr_(it.ptr_);
      return (*this);
    };

    ~const_reverse_iterator() throw(){};

    iterator base() const {
      iterator it = current;
      it++;
      return it;
    };

    reference operator*() { return *current; };
    pointer operator->() { return &(*current); };

    const_reverse_iterator& operator++() {
      current--;
      return *this;
    };

    const_reverse_iterator operator++(int) {
      const_reverse_iterator it = *this;
      current--;
      return it;
    };

    const_reverse_iterator& operator--() {
      current++;
      return *this;
    };

    const_reverse_iterator operator--(int) {
      const_reverse_iterator it = *this;
      current++;
      return it;
    };

    bool operator==(const const_reverse_iterator& rhs) {
      return current == rhs.current;
    }
    bool operator!=(const const_reverse_iterator& rhs) {
      return current != rhs.current;
    }

   protected:
    iterator current;
  };

  /* ***********************************************************************
   */
  /*                                CLASS */
  /* ***********************************************************************
   */

  typedef Key key_type;
  typedef Value mapped_type;
  typedef pair<Key, Value> value_type;
  typedef Compare key_compare;

  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  typedef Node<value_type>* node_ptr;

  typedef iterator iterator;
  typedef const_iterator const_iterator;
  typedef reverse_iterator reverse_iterator;
  typedef const_reverse_iterator const_reverse_iterator;
  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
    // friend class map;
   protected:
    Compare comp;
    value_compare(Compare c) : comp(c) {}

   public:
    bool operator()(const value_type& x, const value_type& y) const {
      return comp(x.first, y.first);
    }
  };

  typedef typename Allocator::template rebind<Node<pair<Key, Value> > >::other
      node_allocator;

  /* ***********************************************************************
   */
  /*                      CONSTRUCTORS & DESTRUCTOR */
  /* ***********************************************************************
   */

  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
      : a(alloc) {
    try {
    } catch (std::exception& e) {
      throw e;
    }
  };

  template <typename InputIterator>
  map(InputIterator first, InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type()) {
    try {
      a = alloc;
      while (first != last) {
        this->insert(first.node->content);
        first++;
      }
    } catch (std::exception& e) {
      this->clear();
      throw e;
    }
  };  // marche po

  map(const map<Key, Value, Compare, Allocator>& x) {
    try {
      if (x.size() != 0) {
        for (const_iterator it = x.begin(); it != x.end(); it++)
          insert(it.node->content);
      }
    } catch (std::exception& e) {
      clear();
      throw e;
    }
  };

  map& operator=(const map<Key, Value, Compare, Allocator>& other) {
    try {
      if (&other == this) return *this;
      clear();
      if (other.size() != 0) {
        for (const_iterator it = other.begin(); it != other.end(); it++)
          insert(it.node->content);
      }
    } catch (std::exception& e) {
      clear();
      throw e;
    }
    return *this;
  }

  ~map() throw() { clear(); };

  /* ***********************************************************************
   */
  /*                             ITERATORS */
  /* ***********************************************************************
   */
  iterator begin() throw() {
    if (header.count == 0) return end();
    iterator itb(_startNode);
    while (itb.node->left && itb.node->left != &header.rendNode)
      itb.node = itb.node->left;
    return itb;
  }
  const_iterator begin() const throw() {
    if (header.count == 0) return end();
    const_iterator itb(_startNode);
    while (itb.node->left && itb.node->left != &header.rendNode)
      itb.node = itb.node->left;
    return itb;
  }

  iterator end() throw() { return iterator(&header.endNode).node; }
  const_iterator end() const throw() {
    return (const_iterator(&header.endNode).node);
  }

  reverse_iterator rbegin() throw() {
    return reverse_iterator(header.endNode.parent);
  }
  const_reverse_iterator rbegin() const throw() {
    return const_reverse_iterator(header.endNode.parent);
  }

  reverse_iterator rend() throw() {
    iterator it = begin();
    return reverse_iterator(it.node->left);
  }
  const_reverse_iterator rend() const throw() {
    const_iterator it = begin();
    return const_reverse_iterator(it.node->left);
  }

  /* ***********************************************************************
   */
  /*                             CAPACITY */
  /* ***********************************************************************
   */

  bool empty() const throw() { return header.count == 0; }
  std::size_t size() const throw() { return header.count; }
  std::size_t max_size() const throw() {
    return std::numeric_limits<std::size_t>::max();
  }

  /* ***********************************************************************
   */
  /*                             ELEMENT ACCESS */
  /* ***********************************************************************
   */

  mapped_type& operator[](const key_type& k) {
    try {
      if (header.count == 0) {
        try {
          _startNode = a.allocate(1);
          a.construct(_startNode, Node<pair<Key, Value> >());
        } catch (std::exception& e) {
          throw e;
        }
        _startNode->content.first = k;
        _startNode->left = &header.rendNode;
        _startNode->right = &header.endNode;
        header.endNode.parent = _startNode;
        header.rendNode.parent = _startNode;
        _startNode->parent = NULL;
        _startNode->left_height = 0;
        _startNode->right_height = 0;
        header.count++;
        return _startNode->content.second;
      }
      node_ptr n = searchToAdd(k, _startNode);
      if ((!f(n->content.first, k) && !f(k, n->content.first)))
        return n->content.second;
      Node<value_type>* newNode;
      newNode = a.allocate(1);
      a.construct(newNode, Node<pair<Key, Value> >());
      newNode->content.first = k;
      newNode->content.second = Value();
      if (f(k, n->content.first)) {
        if (n->left == &header.rendNode) {
          newNode->left = &header.rendNode;
          header.rendNode.parent = newNode;
        }
        n->left = newNode;
      } else {
        if (n->right == &header.endNode) {
          newNode->right = &header.endNode;
          header.endNode.parent = newNode;
        }
        n->right = newNode;
      }
      newNode->parent = n;
      resetHeightsAbove(newNode);
      if (newNode->parent->parent != NULL) rebalanceNode(newNode);
      header.count++;
      return newNode->content.second;
    } catch (std::exception& e) {
      throw e;
    }
  };

  mapped_type& at(const key_type& k) {  // strong guarantee : something to do??
    node_ptr n = searchToAdd(k, _startNode);
    if (!f(n->content->first, k) && !f(k, n->content->first))  // replace
      return n->content.second;
    throw std::out_of_range("");
  };

  const mapped_type& at(const key_type& k) const {
    node_ptr n = searchToAdd(k, _startNode);
    if ((!f(n->content->first, k) && !f(k, n->content->first)))  // replace
      return n->content.second;
    throw std::out_of_range("");
  };

  /* ***********************************************************************
   */
  /*                               MOFIFIERS */
  /* ***********************************************************************
   */

  pair<iterator, bool> insert(const value_type& x) {
    try {
      if (header.count == 0) {
        try {
          _startNode = a.allocate(1);
          a.construct(_startNode, Node<pair<Key, Value> >());
        } catch (std::exception& e) {
          throw e;
        }
        _startNode->content = x;
        _startNode->left = &header.rendNode;
        _startNode->right = &header.endNode;
        header.endNode.parent = _startNode;
        header.rendNode.parent = _startNode;
        _startNode->parent = NULL;
        _startNode->left_height = 0;
        _startNode->right_height = 0;
        header.count++;
        return ft::pair<iterator, bool>(iterator(_startNode), true);
      }
      iterator it = iterator(searchToAdd(x.first, _startNode));
      if (!f(it->first, x.first) && !f(x.first, it->first))
        return (ft::pair<iterator, bool>(it, false));
      Node<value_type>* newNode;
      newNode = a.allocate(1);
      a.construct(newNode, Node<pair<Key, Value> >());
      newNode->content = x;
      if (f(x.first, it->first)) {
        if (it.node->left == &header.rendNode) {
          newNode->left = &header.rendNode;
          header.rendNode.parent = newNode;
        }
        it.node->left = newNode;
      } else {
        if (it.node->right == &header.endNode) {
          newNode->right = &header.endNode;
          header.endNode.parent = newNode;
        }
        it.node->right = newNode;
      }
      newNode->parent = it.node;
      resetHeightsAbove(newNode);
      if (newNode->parent->parent != NULL) rebalanceNode(newNode);
      header.count++;
      return (ft::pair<iterator, bool>(iterator(newNode), true));
    } catch (std::exception& e) {
      throw e;
    }
  };

  iterator insert(iterator position, const value_type& x) {  // NOLINT
    try {
      if (position.node == &header.endNode) return insert(x).first;

      if (header.count == 0) {
        try {
          _startNode = a.allocate(1);
          a.construct(_startNode, Node<pair<Key, Value> >());
        } catch (std::exception& e) {
          throw e;
        }
        _startNode->content = x;
        _startNode->left = &header.rendNode;
        _startNode->right = &header.endNode;
        header.endNode.parent = _startNode;
        header.rendNode.parent = _startNode;
        _startNode->parent = NULL;
        _startNode->left_height = 0;
        _startNode->right_height = 0;
        header.count++;
        return iterator(_startNode);
      }
      if (!f(position.node->content.first, x.first) &&
          !f(x.first, position.node->content.first)) {
        return position;
      }
      if (f(position->first, x.first)) {
        position++;
        if ((position == &header.endNode || !f(position->first, x.first)) &&
            !(!f(position.node->content.first, x.first) &&
              !f(x.first, position.node->content.first))) {
          position--;
          if (position.node->right == &header.endNode ||
              position.node->right == NULL) {
            Node<value_type>* newNode;
            try {
              newNode = a.allocate(1);
              a.construct(newNode, Node<pair<Key, Value> >());
            } catch (std::exception& e) {
              throw e;
            }
            newNode->content = x;
            if (position.node->right == &header.endNode) {
              newNode->right = &header.endNode;
              header.endNode.parent = newNode;
            }
            position.node->right = newNode;
            newNode->parent = position.node;
            resetHeightsAbove(newNode);
            if (newNode->parent->parent != NULL) rebalanceNode(newNode);
            header.count++;
            return iterator(newNode);
          }
        }
      }
      return insert(x).first;
    } catch (std::exception& e) {
      throw e;
    }
  };

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    try {
      iterator it = first;
      if (header.count == 0) {
        try {
          _startNode = a.allocate(1);
          a.construct(_startNode, Node<pair<Key, Value> >());
        } catch (std::exception& e) {
          throw e;
        }
        _startNode->content = it.node->content;
        _startNode->left = &header.rendNode;
        _startNode->right = &header.endNode;
        header.endNode.parent = _startNode;
        header.rendNode.parent = _startNode;
        _startNode->parent = NULL;
        _startNode->left_height = 0;
        _startNode->right_height = 0;
        header.count++;
        it++;
      }
      iterator hint = begin();
      while (it != last) {
        hint = insert(hint, it.node->content);
        it++;
      }
    } catch (std::exception& e) {
      throw e;
    }
  };

  void erase(iterator position) throw() {  // NOLINT
    if (position == &header.endNode) return;
    bool noChild = (position.node->left == NULL ||
                    position.node->left == &header.rendNode) &&
                   (position.node->right == NULL ||
                    position.node->right == &header.endNode);
    bool oneChildLeft = position.node->left != NULL &&
                        position.node->left != &header.rendNode &&
                        (position.node->right == NULL ||
                         position.node->right == &header.endNode);
    bool oneChildRight = (position.node->left == NULL ||
                          position.node->left == &header.rendNode) &&
                         (position.node->right != NULL &&
                          position.node->right != &header.endNode);
    if (position.node == _startNode) {
      if (noChild) {
        clear();
        return;
      }
      if (oneChildLeft) {
        position.node->left->parent = NULL;
        _startNode = position.node->left;
      } else if (oneChildRight) {
        position.node->right->parent = NULL;
        _startNode = position.node->right;
      } else {
        iterator next = position;
        next++;
        if (next.node->parent == position.node) {
          next.node->parent = NULL;
          next.node->left = position.node->left;
          next.node->left->parent = next.node;
          next.node->left_height = position.node->left_height;
          _startNode = next.node;
        } else {
          next.node->parent->left = next.node->right;
          if (next.node->right) next.node->right->parent = next.node->parent;
          next.node->parent->left_height--;
          resetHeightAboveErase(next.node->parent);
          next.node->left = position.node->left;
          next.node->left->parent = next.node;
          next.node->right = position.node->right;
          next.node->right->parent = next.node;
          next.node->parent = NULL;
          next.node->left_height = position.node->left_height;
          next.node->right_height = position.node->right_height;
          _startNode = next.node;
        }
      }
      rebalanceTree(_startNode);
    } else if (position.node->parent->left ==
               position.node)  // delete from left subtree
    {
      if (noChild) {
        position.node->parent->left = position.node->left;
        position.node->parent->left_height = 0;
        resetHeightAboveErase(position.node->parent);
      } else if (oneChildLeft) {
        position.node->parent->left = position.node->left;
        position.node->left->parent = position.node->parent;
        position.node->parent->left_height--;
        resetHeightAboveErase(position.node->parent);

      } else if (oneChildRight) {
        position.node->parent->left = position.node->right;
        position.node->right->parent = position.node->parent;
        position.node->parent->left_height--;
        resetHeightAboveErase(position.node->parent);

      } else {
        iterator next = position;
        next--;
        node_ptr tmp = next.node->parent;
        if (next.node->parent == position.node) {
          position.node->parent->left = next.node;
          next.node->parent = position.node->parent;
          next.node->right = position.node->right;
          next.node->right->parent = next.node;
          next.node->right_height = position.node->right_height;
          resetHeightAboveErase(position.node->parent);
        } else {
          next.node->parent->right = next.node->left;
          if (next.node->left) next.node->left->parent = next.node->parent;
          next.node->parent->right_height--;
          resetHeightAboveErase(next.node->parent);
          next.node->left = position.node->left;
          next.node->left->parent = next.node;
          next.node->right = position.node->right;
          next.node->right->parent = next.node;
          next.node->parent = position.node->parent;
          next.node->parent->left = next.node;
          next.node->left_height = position.node->left_height;
          next.node->right_height = position.node->right_height;
          resetHeightAboveErase(next.node->parent);
        }
      }
      rebalanceTree(position.node->parent->left);
      rebalanceTree(position.node->parent->right);
      rebalanceNodeBis(position.node->parent);
    } else if (position.node->parent->right ==
               position.node)  // delete frome right subtree
    {
      if (position.node->right == &header.endNode) {
      }
      if (noChild) {
        position.node->parent->right = position.node->right;
        position.node->parent->right_height = 0;
        resetHeightAboveErase(position.node->parent);
      } else if (oneChildLeft) {
        position.node->parent->right = position.node->left;
        position.node->left->parent = position.node->parent;
        position.node->parent->right_height--;
        if (position.node->right == &header.endNode) {
          node_ptr tmp = position.node->left;
          if (tmp) {
            while (tmp->right) tmp = tmp->right;
            tmp->right = &header.endNode;
            header.endNode.parent = tmp;
          }
        }
        resetHeightAboveErase(position.node->parent);
        rebalanceTree(position.node->parent->right);
        rebalanceNodeBis(position.node->parent);
      } else if (oneChildRight) {
        position.node->parent->right = position.node->right;
        position.node->right->parent = position.node->parent;
        position.node->parent->right_height--;
        resetHeightAboveErase(position.node->parent);
      } else {
        iterator next = position;
        next--;
        node_ptr tmp = next.node->parent;
        if (next.node->parent == position.node) {
          position.node->parent->right = next.node;
          next.node->parent = position.node->parent;
          next.node->right = position.node->right;
          next.node->right->parent = next.node;
          next.node->right_height = position.node->right_height;
          resetHeightAboveErase(position.node->parent);
        } else {
          next.node->parent->right = next.node->left;
          if (next.node->left) next.node->left->parent = next.node->parent;
          next.node->parent->right_height--;
          resetHeightAboveErase(next.node->parent);
          next.node->left = position.node->left;
          next.node->left->parent = next.node;
          next.node->right = position.node->right;
          next.node->right->parent = next.node;
          next.node->parent = position.node->parent;
          next.node->parent->right = next.node;
          next.node->left_height = position.node->left_height;
          next.node->right_height = position.node->right_height;
          resetHeightAboveErase(next.node->parent);
        }
      }
      rebalanceTree(position.node->parent->right);
      rebalanceTree(position.node->parent->left);
      rebalanceNodeBis(position.node->parent);
    }
    dealloc(position.node);
  }

  size_type erase(const key_type& x) {
    try {
      iterator it = find(x);
      if (it != &header.endNode) {
        erase(it);
        return 1;
      }
      return 0;
    } catch (std::exception& e) {
      throw e;
    }
  };

  void erase(iterator first, iterator last) {
    while (first != last) {
      iterator it = first;
      first++;
      erase(it);
    }
  };

  /* ***************************************** */

  void swap(map<Key, Value, Compare, Allocator>& other) throw() {
    try {
      map<Key, Value, Compare, Allocator> tmp = *this;
      std::swap(tmp.a, a);
      *this = other;
      other = tmp;
    } catch (std::exception& e) {
      return;
    }
  };

  void clear() throw() {
    if (header.count == 0) return;
    recursiveDealloc(_startNode->left);
    recursiveDealloc(_startNode->right);
    _startNode->left = NULL;
    _startNode->right = NULL;
    _startNode->left_height = 0;
    _startNode->right_height = 0;
    a.destroy(_startNode);
    a.deallocate(_startNode, 1);
    _startNode = NULL;
    header.count--;
    header.endNode.parent = NULL;
  };

  /* *********************************************************************  */
  /*                                  OBSERVERS                             */
  /* *********************************************************************  */

  value_compare value_comp() const { return value_compare(); }
  key_compare key_comp() const { return key_compare(); };
  Allocator get_allocator() throw() { return a; }

  /* ********************************************************************  */
  /*                                 OPERATIONS                            */
  /* ********************************************************************  */

  iterator find(const key_type& k) {
    return iterator(searchToFind(k, _startNode));
  }
  const_iterator find(const key_type& k) const {
    return const_iterator(searchToFind(k, _startNode));
  }
  size_type count(const key_type& k) const {
    return (searchToFind(k, _startNode) == &header.endNode ? 0 : 1);
  };

  iterator lower_bound(const key_type& k) {
    iterator it = begin();
    while (f(it.node->content.first, k) && it != end()) {
      it++;
    }
    return it;
  };
  const_iterator lower_bound(const key_type& k) const {
    const_iterator it = begin();
    while (f(it.node->content.first, k) && it != end()) {
      it++;
    }
    return it;
  };
  iterator upper_bound(const key_type& k) {
    iterator it = begin();
    while (f(it.node->content.first, k) && it != end()) {
      it++;
    }
    if ((!f(it.node->content.first, k) && !f(k, it.node->content.first)) &&
        it != end())
      it++;
    return it;
  };

  const_iterator upper_bound(const key_type& k) const {
    const_iterator it = begin();
    while (f(it.node->content.first, k) && it != end()) {
      it++;
    }

    if ((!f(it.node->content.first, k) && !f(k, it.node->content.first)) &&
        it != end())
      it++;
    return it;
  };

  pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
    return ft::pair<const_iterator, const_iterator>(lower_bound(k),
                                                    upper_bound(k));
  };
  pair<iterator, iterator> equal_range(const key_type& k) {
    return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
  };

  /* ********************************************************************** */
  /*                                  UTILS                                 */
  /* ********************************************************************** */

 private:
  void recursiveDealloc(node_ptr n) {
    if (n == NULL || n == &header.endNode || n == &header.rendNode) return;
    recursiveDealloc(n->left);
    recursiveDealloc(n->right);
    n->left = NULL;
    n->right = NULL;
    dealloc(n);
  }

  void dealloc(node_ptr n) {
    a.destroy(n);
    a.deallocate(n, 1);
    n = NULL;
    header.count--;
  }

  void resetHeightsAbove(node_ptr n) {
    while (n->parent->parent) {
      if (n->parent->left == n) {
        n->parent->left_height = std::max(n->left_height, n->right_height) + 1;
      } else {
        n->parent->right_height = std::max(n->left_height, n->right_height) + 1;
      }
      n = n->parent;
    }
    if (_startNode->left)
      _startNode->left_height = std::max(_startNode->left->left_height,
                                         _startNode->left->right_height) +
                                1;
    if (_startNode->right)
      _startNode->right_height = std::max(_startNode->right->left_height,
                                          _startNode->right->right_height) +
                                 1;
  }

  void resetHeightAboveErase(node_ptr n) {
    while (n) {
      if (n->left)
        n->left_height =
            std::max(n->left->left_height, n->left->right_height) + 1;
      if (n->right)
        n->right_height =
            std::max(n->right->left_height, n->right->right_height) + 1;

      n = n->parent;
    }
  }

  void rightLeftRotate(node_ptr n) {
    singleRightRotate(n->right);
    singleLeftRotate(n);
  }

  void leftRightRotate(node_ptr n) {
    singleLeftRotate(n->left);
    singleRightRotate(n);
  }

  void singleRightRotate(node_ptr z) {
    node_ptr y = z->left;
    if (z == _startNode) {
      _startNode = y;
      y->parent = NULL;
    } else {
      if (z == z->parent->right)
        z->parent->right = y;
      else
        z->parent->left = y;
      y->parent = z->parent;
    }
    z->left = y->right;
    if (y->right) y->right->parent = z;
    y->right = z;
    z->parent = y;
    if (z->left)
      z->left_height =
          std::max(z->left->right_height, z->left->left_height) + 1;
    else
      z->left_height = 0;
    resetHeightsAbove(z);
  }

  void singleLeftRotate(node_ptr z) {
    node_ptr y = z->right;
    if (z == _startNode) {
      _startNode = y;
      y->parent = NULL;
    } else {
      if (z == z->parent->right)
        z->parent->right = y;
      else
        z->parent->left = y;
      y->parent = z->parent;
    }
    z->right = y->left;
    if (y->left) y->left->parent = z;
    y->left = z;
    z->parent = y;

    if (z->right)
      z->right_height =
          std::max(z->right->right_height, z->right->left_height) + 1;
    else
      z->right_height = 0;
    resetHeightsAbove(z);
  }

  long int balanceFactor(node_ptr n) {
    if (n != NULL && n != &header.endNode && n != &header.rendNode)
      return n->left_height - n->right_height;
    return 0;
  }

  void rebalanceNodeErase(node_ptr n) {
    if (n == NULL || n == &header.endNode || n == &header.rendNode) return;
    if (balanceFactor(n) == 2) {
      if (balanceFactor(n->left) == -1 || balanceFactor(n->left) == 0)
        leftRightRotate(n);
      else if (balanceFactor(n->left) == 1)
        singleRightRotate(n);
    } else if (balanceFactor(n) == -2) {
      if (balanceFactor(n->right) == -1 || balanceFactor(n->right) == 0)
        singleLeftRotate(n);
      else if (balanceFactor(n->right) == 1)
        rightLeftRotate(n);
    }
  }

  void rebalanceNodeBis(node_ptr n) {
    while (n) {
      if (n == NULL || n == &header.endNode || n == &header.rendNode) return;
      if (balanceFactor(n) >= 2) {
        if (balanceFactor(n->left) <= -1 || balanceFactor(n->left) == 0)
          leftRightRotate(n);
        else if (balanceFactor(n->left) >= 1)
          singleRightRotate(n);
      } else if (balanceFactor(n) <= -2) {
        if (balanceFactor(n->right) <= -1 || balanceFactor(n->right) == 0)
          singleLeftRotate(n);
        else if (balanceFactor(n->right) >= 1)
          rightLeftRotate(n);
      }
      n = n->parent;
    }
  }

  void rebalanceNode(node_ptr n) {
    if (n == NULL || n == &header.endNode || n == &header.rendNode) return;
    while (n->parent) {
      if (balanceFactor(n->parent->parent) == 2 ||
          balanceFactor(n->parent->parent) == -2) {
        if (n == n->parent->left && n->parent == n->parent->parent->left) {
          singleRightRotate(n->parent->parent);
        } else if (n == n->parent->right &&
                   n->parent == n->parent->parent->left) {
          leftRightRotate(n->parent->parent);
        } else if (n == n->parent->right &&
                   n->parent == n->parent->parent->right) {
          singleLeftRotate(n->parent->parent);
        } else if (n == n->parent->left &&
                   n->parent == n->parent->parent->right) {
          rightLeftRotate(n->parent->parent);
        }
        break;
      }
      n = n->parent;
    }
  }

  bool isImbalanced(node_ptr n) {
    long int bf = balanceFactor(n);
    return (bf == 2 || bf == -2);
  }

  void rebalanceTree(node_ptr node) {
    if (node == NULL || node == &header.endNode || node == &header.rendNode)
      return;
    rebalanceTree(node->left);
    rebalanceTree(node->right);
    rebalanceNodeErase(node);
  }

  template <typename A, typename B>
  bool f(A a, B b, std::less<Key> u = std::less<Key>()) {
    return u(a, b);
  }
  template <typename A, typename B>
  bool f(A a, B b, std::less<Key> u = std::less<Key>()) const {
    return u(a, b);
  }

  node_ptr searchToFind(const key_type& key, node_ptr root) const {
    if (root == NULL || root == &header.rendNode)
      return const_cast<node_ptr>(&(header.endNode));

    if (!f(root->content.first, key) && !f(key, root->content.first))
      return root;
    if (f(root->content.first, key)) {
      if (root->right == &header.endNode)
        return const_cast<node_ptr>(&(header.endNode));
      return searchToFind(key, root->right);
    }
    return searchToFind(key, root->left);
  }

  node_ptr searchToAdd(const key_type& key, node_ptr root) {
    if (root == NULL || root == &header.rendNode) return NULL;
    if (!f(root->content.first, key) && !f(key, root->content.first))
      return root;
    if (f(root->content.first, key)) {
      if (root->right == &header.endNode) return header.endNode.parent;
      if (root->right == NULL) return root;
      return searchToAdd(key, root->right);
    }
    if (root->left == NULL || root->left == &header.rendNode) return root;
    return searchToAdd(key, root->left);
  }

  Node<value_type>* getStart() { return _startNode; };

  /* ********************************************************************** */
  /*                               MEMBER VALUES                            */
  /* ********************************************************************** */

  node_allocator a;
  mapHeader<value_type, Allocator, Key, Value> header;
  Node<value_type>* _startNode;
};

/* *********************************************************************** */
/*                               NON MEMBER FUNCTIONS                      */
/* *********************************************************************** */

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare, Allocator>& x,
                const map<Key, T, Compare, Allocator>& y) throw() {
  if (x.size() != y.size()) return false;
  typename ft::map<Key, T, Compare, Allocator>::const_iterator itx = x.begin();
  typename ft::map<Key, T, Compare, Allocator>::const_iterator ity = y.begin();
  while (itx != x.end()) {
    if (itx->first != ity->first || itx->second != ity->second) return false;
    itx++;
    ity++;
  }
  return true;
};
template <class Key, class T, class Compare, class Allocator>
bool operator<(const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y) throw() {
  typename ft::map<Key, T, Compare, Allocator>::const_iterator itx = x.begin();
  typename ft::map<Key, T, Compare, Allocator>::const_iterator ity = y.begin();
  while (itx != x.end() && ity != y.end()) {
    if (!(itx->first < ity->first) && !(ity->first < itx->first))
      if (ity->second < itx->second) return false;
    if (ity->first < itx->first) return false;
    itx++;
    ity++;
  }
  return (itx == x.end() && ity != y.end());
};

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare, Allocator>& x,
                const map<Key, T, Compare, Allocator>& y) throw() {
  return !(x == y);
}
template <class Key, class T, class Compare, class Allocator>
bool operator>(const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y) throw() {
  return (y < x);
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare, Allocator>& x,
                const map<Key, T, Compare, Allocator>& y) throw() {
  return (!(x < y));
};

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare, Allocator>& x,
                const map<Key, T, Compare, Allocator>& y) throw() {
  return (!(y < x));
};

template <class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare, Allocator>& x,
          map<Key, T, Compare, Allocator>& y) throw() {
  x.swap(y);
};

}  // namespace ft

#endif
