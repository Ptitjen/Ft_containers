#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <cstddef>
#include <exception>
#include <functional>
#include <limits>
#include <stdexcept>

#include "pair.hpp"
#include "reverse_iterator.hpp"

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
        right_height(0),
        height(0){};

  Node(Content c)
      : parent(NULL),
        left(NULL),
        right(NULL),
        left_height(0),
        right_height(0),
        height(0),
        content(c){};

  Node(const Node& other) : content(other.content) {
    left = other.left;
    right = other.right;
    parent = other.parent;
    left_height = other.left_height;
    right_height = other.right_height;
    height = other.height;
  }

  Node& operator=(const Node& other) {
    if (&other == this) return (*this);
    left = other.left;
    right = other.right;
    content = other.content;
    parent = other.parent;
    // left_height = other.left_height;
    // right_height = other.right_height;
    height = other.height;
    return (*this);
  }

  ~Node() { content.~Content(); };

  Content content;
  Node* parent;
  Node* left;
  Node* right;

  std::size_t left_height;
  std::size_t right_height;
  std::size_t height;
};

/* *********************************************************************** */
/*                             TREE HEADER                                 */
/* *********************************************************************** */
template <class Content, class Allocator, class Key, class Value>
class BstTreeHeader {
 public:
  typedef typename Allocator::template rebind<Node<pair<Key, Value> > >::other
      node_allocator;
  BstTreeHeader() {
    count = 0;
    hnode.left = &hnode;
    hnode.right = &hnode;
    hnode.parent = NULL;
  };

  ~BstTreeHeader(){};

  node_allocator a;
  Node<Content> hnode;
  std::size_t count;
};

/* *********************************************************************** */
/*                                TREE                                     */
/* *********************************************************************** */
template <class Key, class Value, class Compare = std::less<Key>,
          class Allocator = std::allocator<pair<const Key, Value> > >

class BstTree {
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

    reference operator*() { return *(node->content); }
    pointer operator->() { return &node->content; }

    /* comparison */
    bool operator==(const iterator& rhs) {
      return node == rhs.node;
    }  // check this
    bool operator!=(const iterator& rhs) { return !(node == rhs.node); }

    void increment() {
      if (node->right != NULL) {
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
      if (node->left == node)
        node = node->parent;  // NOLINT
      else if (node->left != NULL) {
        node = node->left;
        while (node->right != NULL) node = node->right;
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
    reference operator*() const { return *(node->content); }
    pointer operator->() const { return &node->content; }

    /* comparison */
    bool operator==(const const_iterator& rhs) {
      return node == rhs.node;
    }  // check this
    bool operator!=(const const_iterator& rhs) { return !(node == rhs.node); }

    void increment() {
      if (node->right != NULL) {
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
      if (node->left == node)
        node = node->parent;  // NOLINT
      else if (node->left != NULL) {
        node = node->left;
        while (node->right != NULL) node = node->right;
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
  /*                                CLASS                                    */
  /* *********************************************************************** */

  // public:
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

  typedef BstTree::iterator iterator;
  typedef BstTree::const_iterator const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
    friend class map;

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

  /* *********************************************************************** */
  /*                      CONSTRUCTORS & DESTRUCTOR                          */
  /* *********************************************************************** */

  explicit BstTree(const key_compare& comp = key_compare(),
                   const allocator_type& alloc = allocator_type())
      : a(alloc) {
    try {
    } catch (std::exception& e) {
      throw e;
    }
  };

  template <class InputIterator>
  BstTree(InputIterator first, InputIterator last,
          const key_compare& comp = key_compare(),
          const allocator_type& alloc = allocator_type()) {
    try {
      a = alloc;  // ?
      while (first != last) {
        insert(first.node->content);
        first++;
      }
      resetHeader();
    } catch (std::exception& e) {
      resetHeader();
      clear();  // ?
      throw e;
    }
  };

  BstTree(const BstTree<Key, Value, Compare, Allocator>& x) {
    a = node_allocator();  // ???
    try {
      if (x.size() != 0) {
        for (const_iterator it = x.begin(); it != x.end(); it++)
          insert(it.node->content);
        resetHeader();
      }
    } catch (std::exception& e) {
      resetHeader();
      clear();  // ?
      throw e;
    }
  };

  BstTree& operator=(const BstTree<Key, Value, Compare, Allocator>& other) {
    try {
      if (&other == this) return *this;
      clear();
      if (other.size() != 0) {
        for (const_iterator it = other.begin(); it != other.end(); it++)
          insert(it.node->content);
        resetHeader();
      }
    } catch (std::exception& e) {
      resetHeader();
      clear();  // ?
      throw e;
    }
    return *this;
  }

  ~BstTree() throw() { clear(); };

  /* ***********************************************************************
   */
  /*                             ITERATORS */
  /* ***********************************************************************
   */
  iterator begin() throw() {
    if (header.count == 0) return end();  // ???
    iterator itb(_startNode);
    while (itb.node->left) itb.node = itb.node->left;
    return itb;
  }
  const_iterator begin() const throw() {
    if (header.count == 0) return end();  // ???
    const_iterator itb(_startNode);
    while (itb.node->left) itb.node = itb.node->left;
    return itb;
  }

  iterator end() throw() { return iterator(&header.hnode).node; }
  const_iterator end() const throw() {
    return (const_iterator(&header.hnode).node);
  }

  reverse_iterator rbegin() throw() { return reverse_iterator(end()); }  // test
  const_reverse_iterator rbegin() const throw() {
    return const_reverse_iterator(end());
  }

  reverse_iterator rend() throw() { return reverse_iterator(begin()); }
  const_reverse_iterator rend() const throw() {
    return const_reverse_iterator(begin());
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

  mapped_type& operator[](const key_type& k) {  // inserts element if not found
    BstTree<Key, Value, Compare, Allocator> save(*this);
    try {
      node_ptr n = searchToAdd(k, _startNode);
      if (n->content.first == k) return n->content.second;
      Node<value_type>* newNode;
      newNode = a.allocate(1);
      a.construct(newNode, Node<pair<Key, Value> >());
      newNode->content.first = k;
      newNode->content.second = Value();
      if (f(k, n->content.first)) {
        n->left = newNode;
      } else {
        if (n->right == &header.hnode) {
          newNode->right = &header.hnode;
          header.hnode.parent = newNode;
        }
        n->right = newNode;
      }
      newNode->parent = n;
      newNode->height = n->height + 1;
      resetHeightsAbove(newNode);
      if (newNode->parent->parent != NULL) rebalanceNode(newNode);

      resetHeader();
      header.count++;
      return newNode->content.second;
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  mapped_type& at(const key_type& k) {  // strong guarantee : something to do??
    node_ptr n = searchToAdd(k, _startNode);
    if (n->content.first == k)  // replace
      return n->content.second;
    throw std::out_of_range("");
  };

  const mapped_type& at(const key_type& k) const {
    node_ptr n = searchToAdd(k, _startNode);
    if (n->content.first == k)  // replace
      return n->content.second;
    throw std::out_of_range("");
  };

  /* ***********************************************************************
   */
  /*                               MOFIFIERS */
  /* ***********************************************************************
   */

  pair<iterator, bool> insert(const value_type& x) {
    //    BstTree<Key, Value, Compare, Allocator> save(*this);
    try {
      if (header.count == 0) {
        _startNode = a.allocate(1);
        a.construct(_startNode, Node<pair<Key, Value> >());
        _startNode->content = x;
        _startNode->left = NULL;
        _startNode->right = NULL;
        _startNode->parent = NULL;
        _startNode->left_height = 0;
        _startNode->height = 0;
        _startNode->right_height = 0;
        header.count++;
        resetHeader();
        return ft::pair<iterator, bool>(iterator(_startNode), true);
      }
      iterator it = iterator(searchToAdd(x.first, _startNode));
      if (it->first == x.first)  //  change == with !< && !>
        return (ft::pair<iterator, bool>(it, false));
      Node<value_type>* newNode;
      newNode = a.allocate(1);
      a.construct(newNode, Node<pair<Key, Value> >());
      newNode->content = x;
      if (f(x.first, it->first)) {
        it.node->left = newNode;
      } else {
        if (it.node->right == &header.hnode) {
          newNode->right = &header.hnode;
          header.hnode.parent = newNode;
        }
        it.node->right = newNode;
      }
      newNode->parent = it.node;
      newNode->height = it.node->height + 1;
      resetHeightsAbove(newNode);
      if (newNode->parent->parent != NULL) rebalanceNode(newNode);
      resetHeader();

      header.count++;
      return (ft::pair<iterator, bool>(iterator(newNode), true));
    } catch (std::exception& e) {
      throw e;
    }
  };

  iterator insert(iterator position, const value_type& x) {
    // BstTree<Key, Value, Compare, Allocator> save(*this);
    try {
      if (header.count == 0) {
        _startNode = a.allocate(1);
        a.construct(_startNode, Node<pair<Key, Value> >());
        _startNode->content = x;
        _startNode->left = NULL;
        _startNode->right = NULL;
        _startNode->parent = NULL;
        _startNode->left_height = 0;
        _startNode->height = 0;
        _startNode->right_height = 0;
        header.count++;
        resetHeader();
        return iterator(_startNode);
      }
      if (position->first == x.first) return position;  // position = new value
      if (!f(position->first, x.first)) {               // position == good hint
        position++;                                     // limit if end
        if (f(position->first, x.first)) {
          position--;
          Node<value_type>* newNode;
          newNode = a.allocate(1);
          a.construct(newNode, Node<pair<Key, Value> >());
          newNode->content = x;
          if (position.node->right == &header.hnode) {
            newNode->right = &header.hnode;
            header.hnode.parent = newNode;
          }
          position.node->right = newNode;
          newNode->parent = position.node;
          newNode->height = position.node->height + 1;
          header.count++;
          resetHeightsAbove(newNode);
          if (newNode->parent->parent != NULL) rebalanceNode(newNode);
          resetHeader();
          return iterator(newNode);
        }
      }
      return insert(x).first;  // position == bad hint
    } catch (std::exception& e) {
      //   swap(save);
      throw e;
    }
  };

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    if (header.count == 0) {
      _startNode = a.allocate(1);
      a.construct(_startNode, Node<pair<Key, Value> >());
      _startNode->content = first.node->content;
      _startNode->left = first.node->left;
      _startNode->right = first.node->right;
      _startNode->parent = NULL;
      _startNode->left_height = first.node->left_height;
      _startNode->height = 0;
      _startNode->right_height = first.node->right_height;
      header.count++;
      resetHeader();
      first++;
    }
    iterator hint = begin();
    while (first != last) {
      hint = insert(hint, first.node->content);
      first++;
    }
  };

  void erase(iterator position) throw() {  //? see this - depends if
                                           // comparison throws
    if (position.node->left == NULL && position.node->right == NULL) {
      /* NO CHILD */

      if (position.node == _startNode) {
        clear();
        return;
      }
      if (position.node->parent->left == position.node) {
        position.node->parent->left = NULL;
        position.node->parent->left_height = 0;
      } else {
        position.node->parent->right = NULL;
        position.node->parent->right_height = 0;
      }
      resetHeightAboveErase(position.node->parent);
      rebalanceNodeErase(position.node->parent);
    } else if (position.node->left != NULL &&
               (position.node->right == NULL ||
                position.node->right == &header.hnode)) {
      /* ONE LEFT CHILD */

      resetHeightsDown(position.node);
      if (position.node->parent->left == position.node) {
        position.node->parent->left = position.node->left;
        position.node->left->parent = position.node->parent;
      } else if (position.node->parent->right == position.node) {
        position.node->parent->right = position.node->left;
        position.node->left->parent = position.node->parent;
      } else if (position.node == _startNode) {
        _startNode = position.node->left;
        position.node->left->parent = NULL;
      }
      resetHeightAboveErase(position.node->parent);
      rebalanceNodeErase(position.node->parent);

    } else if (position.node->left == NULL && position.node->right != NULL) {
      /* ONE RIGHT CHILD */

      resetHeightsDown(position.node);
      if (position.node->parent->left == position.node) {
        position.node->parent->left = position.node->right;
        position.node->right->parent = position.node->parent;
      } else if (position.node->parent->right == position.node) {
        position.node->parent->right = position.node->right;
        position.node->right->parent = position.node->parent;
      } else if (position.node == _startNode) {
        _startNode = position.node->right;
        position.node->right->parent = NULL;
      }
      resetHeightAboveErase(position.node->parent);
      rebalanceNodeErase(position.node->parent);

    } else {  // REBALANCE TO DO
      /* 2 CHILDREN */
      position++;
      iterator next = position;
      position--;
      if (position.node == _startNode) {
        if (next.node->right) next.node->right->parent = next.node->parent;
        next.node->parent->left = next.node->right;
        next.node->left = _startNode->left;
        next.node->right = _startNode->right;
        next.node->left->parent = next.node;
        next.node->right->parent = next.node;
        next.node->left_height = _startNode->left_height;
        next.node->right_height = _startNode->right_height;
        resetHeightsDown(next.node->parent->left);
        next.node->parent->left_height--;
        _startNode = next.node;
        next.node->parent = NULL;
        _startNode->height = 0;
      } else if (position.node->parent->right == position.node) {
        resetHeightsDown(position.node->right);
        next.node->left = position.node->left;
        position.node->left->parent = next.node;
        next.node->parent = position.node->parent;
        position.node->parent->right = next.node;
        next.node->left_height = position.node->left_height;
        resetHeightAboveErase(position.node->parent);
      } else if (position.node->parent->left == position.node) {
        if (next.node->right) next.node->right->parent = next.node->parent;
        next.node->parent->left = next.node->right;

        next.node->left = position.node->left;
        if (next.node->left) next.node->left->parent = next.node;

        next.node->right = position.node->right;
        if (next.node->right) next.node->right->parent = next.node;

        next.node->height = position.node->height;
        if (next.node->parent->left) {
          resetHeightsDown(next.node->parent->left);
          next.node->parent->left_height =
              std::max(next.node->parent->left->left_height,
                       next.node->parent->left->right_height) +
              1;
        }
        next.node->parent = position.node->parent;
        next.node->parent->left = next.node;

        if (next.node->right)
          next.node->right_height = std::max(next.node->right->right_height,
                                             next.node->right->left_height) +
                                    1;
        next.node->left_height = position.node->left_height;
        resetHeightAboveErase(next.node->parent);
      }
      rebalanceTree(_startNode);
    }
    dealloc(position.node);
    resetHeader();
  }

  size_type erase(const key_type& x) {
    BstTree<Key, Value, Compare, Allocator> save(*this);
    try {
      iterator it = find(x);
      if (it != &header.hnode) {
        erase(x);
        return 1;
      }
      return 0;
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  void erase(iterator first, iterator last) {
    iterator it = first;
    while (it != last) {
      it++;
      erase(first);
      first++;
    }
  };  // TO DO :test
  /* ***************************************** */

  void swap(BstTree<Key, Value, Compare, Allocator>& other) throw() {
    try {
      BstTree<Key, Value, Compare, Allocator> tmp = *this;
      std::swap(tmp.a, a);
      *this = other;
      other = tmp;
    } catch (std::exception& e) {
      return;
    }
  };  // TODO : test

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
    header.hnode.parent = NULL;
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
    return (searchToFind(k, _startNode) == &header.hnode ? 0 : 1);
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
    if (it.node->content.first == k && it != end()) it++;
    return it;
  };

  const_iterator upper_bound(const key_type& k) const {
    const_iterator it = begin();
    while (f(it.node->content.first, k) && it != end()) {
      it++;
    }
    if (it.node->content.first == k && it != end()) it++;
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

  /*** Utils : put all in private when finished ***/
  Node<value_type>* getStart() { return _startNode; };

 private:
  void recursiveDealloc(node_ptr n) {
    if (n == NULL || n == &header.hnode) return;
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

  void resetHeightsDown(node_ptr n) {
    if (n == NULL || n == &header.hnode) return;
    n->height--;
    resetHeightsDown(n->left);
    resetHeightsDown(n->right);
  }

  void resetHeightsUnderIncrease(node_ptr n) {
    if (n == NULL || n == &header.hnode) return;
    n->height++;
    resetHeightsDown(n->left);
    resetHeightsDown(n->right);
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
    node_ptr x = y->left = z->left->left;
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
    y->height--;
    resetHeightsDown(y->left);
    z->height++;
    if (z->left)
      z->left_height = std::max(z->left->right_height, z->left->left_height);
    else
      z->left_height = 0;
    resetHeightsUnderIncrease(z->right);
    resetHeightsAbove(z);
  }

  void singleLeftRotate(node_ptr z) {
    node_ptr y = z->right;
    node_ptr x = y->right = z->right->right;
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
    y->height--;
    resetHeightsDown(y->right);
    z->height++;
    if (z->right)
      z->right_height = std::max(z->right->right_height, z->right->left_height);
    else
      z->right_height = 0;
    resetHeightsUnderIncrease(z->left);
    resetHeightsAbove(z);
  }

  long int balanceFactor(node_ptr n) {
    if (n != NULL && n != &header.hnode)
      return n->left_height - n->right_height;
    return 0;
  }

  void rebalanceTree(node_ptr n) {
    if (n == NULL || n == &header.hnode) return;
    if (balanceFactor(n) == 2 || balanceFactor(n) == -2) rebalanceNodeErase(n);
    rebalanceTree(n->left);
    rebalanceTree(n->right);
  }

  void rebalanceNodeErase(node_ptr n) {
    if (n == NULL || n == &header.hnode) return;
    // while (n->parent) {
    if (balanceFactor(n) == 2) {
      if (balanceFactor(n->left) == -1)
        singleRightRotate(n);
      else
        leftRightRotate(n);
      // break;
    }
    if (balanceFactor(n) == -2) {
      if (balanceFactor(n->right) == -1)
        singleLeftRotate(n);
      else
        rightLeftRotate(n);
      // break;
    }
    // n = n->parent;
    //}
  }

  void rebalanceNode(node_ptr n) {
    if (n == NULL || n == &header.hnode) return;
    while (n->parent) {
      if (balanceFactor(n->parent->parent) == 2 ||
          balanceFactor(n->parent->parent) == -2) {
        // std::cout << "Imbalanced node: " << n->parent->parent->content.first
        //<< std::endl;
        if (n == n->parent->left && n->parent == n->parent->parent->left) {
          // std::cout << "LEFT LEFT CASE" << std::endl;
          singleRightRotate(n->parent->parent);
        } else if (n == n->parent->right &&
                   n->parent == n->parent->parent->left) {
          // std::cout << "LEFT RIGHT CASE" << std::endl;
          leftRightRotate(n->parent->parent);
        } else if (n == n->parent->right &&
                   n->parent == n->parent->parent->right) {
          // std::cout << "RIGHT RIGHT CASE" << std::endl;
          singleLeftRotate(n->parent->parent);
        } else if (n == n->parent->left &&
                   n->parent == n->parent->parent->right) {
          rightLeftRotate(n->parent->parent);
          // std::cout << "RIGHT LEFT CASE" << std::endl;
        }
        break;
      }
      n = n->parent;
    }
  }

  void resetHeader() {
    if (header.count == 0) return;
    iterator it = last();
    it.node->right = &header.hnode;
    header.hnode.parent = it.node;
  };

  template <typename A, typename B>
  bool f(A a, B b, std::less<Key> u = std::less<Key>()) {
    return u(a, b);
  }
  template <typename A, typename B>
  bool f(A a, B b, std::less<Key> u = std::less<Key>()) const {
    return u(a, b);
  }

 public:  // TODO:remove when fixed
  iterator last() {
    iterator itl(_startNode);
    while (itl.node->right && itl.node->right != &header.hnode)
      itl.node = itl.node->right;
    return itl;
  }

  const_iterator last() const {
    const_iterator itl(_startNode);
    while (itl.node->right && itl.node->right != &header.hnode)
      itl.node = itl.node->right;
    return itl;
  }

  node_ptr searchToFind(const key_type& key, node_ptr root) const {
    if (root == NULL) return const_cast<node_ptr>(&(header.hnode));
    if (root->content.first == key) return root;
    if (f(root->content.first, key)) {
      if (root->right == &header.hnode)
        return const_cast<node_ptr>(&(header.hnode));
      return searchToFind(key, root->right);
    }
    return searchToFind(key, root->left);
  }

  node_ptr searchToAdd(const key_type& key, node_ptr root) {
    if (root == NULL) return NULL;
    if (root->content.first == key) return root;
    if (f(root->content.first, key)) {
      if (root->right == &header.hnode) return header.hnode.parent;
      if (root->right == NULL) return root;
      return searchToAdd(key, root->right);
    }
    if (root->left == NULL) return root;
    return searchToAdd(key, root->left);
  }

  /* ********************************************************************** */
  /*                               MEMBER VALUES                            */
  /* ********************************************************************** */
  node_allocator a;
  BstTreeHeader<value_type, Allocator, Key, Value> header;
  Node<value_type>* _startNode;
};

/* *********************************************************************** */
/*                               NON MEMBER FUNCTIONS                      */
/* *********************************************************************** */
template <class Key, class T, class Compare, class Allocator>
bool operator==(const BstTree<Key, T, Compare, Allocator>& x,
                const BstTree<Key, T, Compare, Allocator>& y) throw() {
  if (x.size() != y.size()) return false;
  typename ft::BstTree<Key, T, Compare, Allocator>::const_iterator itx =
      x.begin();
  typename ft::BstTree<Key, T, Compare, Allocator>::const_iterator ity =
      y.begin();
  while (itx != x.end()) {
    if (itx->first != ity->first || itx->second != ity->second) return false;
    itx++;
    ity++;
  }
  return true;
};
template <class Key, class T, class Compare, class Allocator>
bool operator<(const BstTree<Key, T, Compare, Allocator>& x,
               const BstTree<Key, T, Compare, Allocator>& y) throw() {
  typename ft::BstTree<Key, T, Compare, Allocator>::const_iterator itx =
      x.begin();
  typename ft::BstTree<Key, T, Compare, Allocator>::const_iterator ity =
      y.begin();
  while (itx != x.end() && ity != y.end()) {
    if (!Compare(itx->first, ity->first) && !Compare(ity->first, itx->first))
      if (Compare(ity->second, itx->second)) return false;
    if (Compare(ity->first, itx->first)) return false;
    itx++;
    ity++;
  }
  // check this : length + with begin equal
  return true;
};

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const BstTree<Key, T, Compare, Allocator>& x,
                const BstTree<Key, T, Compare, Allocator>& y) throw() {
  return !(x == y);
}
template <class Key, class T, class Compare, class Allocator>
bool operator>(const BstTree<Key, T, Compare, Allocator>& x,
               const BstTree<Key, T, Compare, Allocator>& y) throw() {
  return (y < x);
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const BstTree<Key, T, Compare, Allocator>& x,
                const BstTree<Key, T, Compare, Allocator>& y) throw() {
  return (!(x < y));
};

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const BstTree<Key, T, Compare, Allocator>& x,
                const BstTree<Key, T, Compare, Allocator>& y) throw() {
  return (!(y < x));
};

template <class Key, class T, class Compare, class Allocator>
void swap(BstTree<Key, T, Compare, Allocator>& x,
          BstTree<Key, T, Compare, Allocator>& y) throw() {
  x.swap(y);
};

}  // namespace ft

#endif

/* TO DO LEFT */
// perf : if not ok : rebalance as AVL tree
// transform to map
// check iterator print shit
// swap allocators