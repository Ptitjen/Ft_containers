#ifndef MAP_HPP
#define MAP_HPP
#include <functional>

#include "../containers_utils/bstree.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class map : public BstTree<Key, T, std::less<Key>,
                           std::allocator<ft::pair<const Key, T> > > {
 public:
  explicit map(
      const Compare& comp = std::less<Key>(),
      const Allocator& alloc = std::allocator<ft::pair<const Key, T> >())
      : BstTree<Key, T, Compare, Allocator>(){};

  template <typename InputIterator>
  map(InputIterator first, InputIterator last,
      const Compare& comp = std::less<Key>(),
      const Allocator& alloc = std::allocator<ft::pair<const Key, T> >()) {
    try {
      while (first != last) {
        this->insert(first.node->content);
        first++;
      }
    } catch (std::exception& e) {
      this->clear();
      throw e;
    }
  };
};
}  // namespace ft
#endif
