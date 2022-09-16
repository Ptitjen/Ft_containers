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

  ~Node() { content.~Content(); };

  Content content;
  Node* parent;
  Node* left;
  Node* right;
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

  // void resetTreeHeader() {

  // }

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
      // header = BstTreeHeader<value_type, Allocator, Key, Value>();
    } catch (std::exception& e) {
    }
  };

  template <class InputIterator>
  BstTree(InputIterator first, InputIterator last,
          const key_compare& comp = key_compare(),
          const allocator_type& alloc = allocator_type()) {
    try {
      // header = BstTreeHeader<value_type, Allocator, Key, Value>();
      while (first != last) {
        insert(first.node->content);
        first++;
      }
      resetHeader();
    } catch (std::exception& e) {
      resetHeader();
      clear();  // ?
    }
  };

  BstTree(const BstTree<Key, Value, Compare, Allocator>& x) {
    try {
      // header = BstTreeHeader<value_type, Allocator, Key, Value>();
      if (x.size() != 0) {
        for (const_iterator it = x.begin(); it != x.end(); it++)
          insert(it.node->content);
        resetHeader();
      }
    } catch (std::exception& e) {
      resetHeader();
      clear();  // ?
    }
  };

  BstTree& operator=(const BstTree<Key, Value, Compare, Allocator>& other) {
    if (&other == this) return *this;
    clear();
    if (other.size() != 0) {
      for (const_iterator it = other.begin(); it != other.end(); it++)
        insert(it.node->content);
      resetHeader();
    }
    return *this;
  }

  ~BstTree() throw() {
    clear();
    // a.destroy(header.hnode);
    // a.deallocate(header.hnode, 1);
    //  header.~BstTreeHeader();  // ?
  };

  /* ***********************************************************************
   */
  /*                             ITERATORS */
  /* ***********************************************************************
   */
  iterator begin() throw() {
    if (header.count == 0) return end();  // ???
    iterator itb(_startNode);
    while (itb.node->left) {
      itb.node = itb.node->left;
    };
    return itb;
  }
  const_iterator begin() const throw() {
    if (header.count == 0) return end();  // ???
    const_iterator itb(_startNode);
    while (itb.node->left) {
      itb.node = itb.node->left;
    };
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
    // BstTree<Key, Value, Compare, Allocator> save(*this);
    try {
      node_ptr n = searchToAdd(k, _startNode);
      if (n->content.first == k) return n->content.second;
      Node<value_type>* newNode;
      newNode = a.allocate(1);
      a.construct(newNode, Node<pair<Key, Value> >());
      newNode->content.first = k;
      newNode->content.second = Value();
      newNode->left = NULL;
      newNode->right = NULL;
      if (f(k, n->content.first)) {
        n->left = newNode;
        newNode->parent = n;
      } else {
        if (n->right == &header.hnode) {
          newNode->right = &header.hnode;
          header.hnode.parent = newNode;
        }
        n->right = newNode;
        newNode->parent = n;
      }
      resetHeader();
      header.count++;
      // save.~BstTree();
      return newNode->content.second;
    } catch (std::exception& e) {
      // swap(save);
      // save.~BstTree();
      throw e;
    }
  };

  mapped_type& at(const key_type& k) {  // strong guarantee : something to do??
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

  /* ***********************************************************************
   */
  /*                               MOFIFIERS */
  /* ***********************************************************************
   */

  pair<iterator, bool> insert(const value_type& x) {
    // BstTree<Key, Value, Compare, Allocator> save(*this);
    try {
      if (header.count == 0) {
        _startNode = a.allocate(1);
        a.construct(_startNode, Node<pair<Key, Value> >());
        _startNode->content = x;
        _startNode->left = NULL;
        _startNode->right = NULL;
        _startNode->parent = NULL;
        header.count++;
        //  save.~BstTree();
        return ft::pair<iterator, bool>(iterator(_startNode), true);
      }
      iterator it = iterator(searchToAdd(x.first, _startNode));
      if (it->first == x.first)  //  change == with !< && !>
        return (ft::pair<iterator, bool>(it, false));
      Node<value_type>* newNode;
      newNode = a.allocate(1);
      a.construct(newNode, Node<pair<Key, Value> >());
      newNode->content = x;
      newNode->left = NULL;
      newNode->right = NULL;
      if (f(x.first, it->first)) {
        it.node->left = newNode;
        newNode->parent = it.node;
      } else {
        if (it.node->right == &header.hnode) {
          newNode->right = &header.hnode;
          header.hnode.parent = newNode;
        }
        it.node->right = newNode;
        newNode->parent = it.node;
      }
      header.count++;
      resetHeader();
      // save.~BstTree();
      return (ft::pair<iterator, bool>(iterator(newNode), true));
    } catch (std::exception& e) {
      //  swap(save);
      //  save.~BstTree();
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
        header.count++;
        // save.~BstTree();
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
          newNode->left = NULL;
          newNode->right = NULL;
          if (position.node->right == &header.hnode) {
            newNode->right = &header.hnode;
            header.hnode.parent = newNode;
          }
          position.node->right = newNode;
          newNode->parent = position.node;
          header.count++;
          resetHeader();
          //  save.~BstTree();
          return iterator(newNode);
        }
      }
      //  save.~BstTree();
      return insert(x).first;  // position == bad hint
    } catch (std::exception& e) {
      // swap(save);
      //  save.~BstTree();
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
      header.count++;
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
      if (position.node == _startNode) {
        clear();
        return;
      }
      if (position.node->parent->left == position.node)
        position.node->parent->left = NULL;
      else
        position.node->parent->right = NULL;
    } else if (position.node->left != NULL &&
               (position.node->right == NULL ||
                position.node->right == &header.hnode)) {
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
    } else if (position.node->left == NULL && position.node->right != NULL) {
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
    } else {
      position++;
      iterator next = position;
      position--;
      if (position.node == _startNode) {
        next.node->right->parent = next.node->parent;
        next.node->parent->left = next.node->right;
        next.node->left = _startNode->left;
        next.node->right = _startNode->right;
        next.node->parent = NULL;
        next.node->left->parent = next.node;
        next.node->right->parent = next.node;
        _startNode = next.node;
      } else if (position.node->parent->right == position.node) {
        next.node->left = position.node->left;
        position.node->left->parent = next.node;
        next.node->parent = position.node->parent;
        position.node->parent->right = next.node;
      } else if (position.node->parent->left == position.node) {
        next--;
        next--;
        next.node->right = position.node->right;
        position.node->right->parent = next.node;
        next.node->parent = position.node->parent;
        position.node->parent->left = next.node;
      }
    }
    dealloc(position.node);
    resetHeader();
  }

  size_type erase(const key_type& x) {
    // BstTree<Key, Value, Compare, Allocator> save(*this);
    try {
      iterator it = find(x);
      if (it != &header.hnode) {
        erase(x);
        // save.~BstTree();
        return 1;
      }
      // save.~BstTree();
      return 0;
    } catch (std::exception& e) {
      // swap(save);
      // save.~BstTree();
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
      *this = other;
      a = other.a;
      _startNode = other._startNode;

      other = tmp;
      other.a = tmp.a;

    } catch (std::exception& e) {
      return;
    }
  };  // TODO : swap allocators

  void clear() throw() {
    if (header.count == 0) return;
    recursiveDealloc(_startNode->left);
    recursiveDealloc(_startNode->right);
    _startNode->left = NULL;
    _startNode->right = NULL;
    a.destroy(_startNode);  // check how to reinit this
    a.deallocate(_startNode, 1);
    _startNode = NULL;
    header.count--;
    resetHeader();
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

  iterator last() {
    iterator itl(_startNode);
    while (itl.node->right && itl.node->right != &header.hnode) {
      itl.node = itl.node->right;
    };
    return itl;
  }

  const_iterator last() const {
    const_iterator itl(_startNode);
    while (itl.node->right && itl.node->right != &header.hnode) {
      itl.node = itl.node->right;
    };
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

  // node_ptr searchToFind(const key_type& key, node_ptr root) {
  //   if (root == NULL) return &header.hnode;
  //   if (root->content.first == key) return root;
  //   if (f(root->content.first, key)) {
  //     if (root->right == &header.hnode) return &header.hnode;
  //     return searchToFind(key, root->right);
  //   }
  //   return searchToFind(key, root->left);
  // }

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

/* TO DO LEFT
construct
*/

// if perfo not ok : rebalance as AVL tree
// Leaks :
/*
Tree header - pb detruit tout
Insert

*/