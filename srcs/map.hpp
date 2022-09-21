#ifndef MAP_HPP
#define MAP_HPP
#include <functional>

#include "bstree.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class map : public BstTree<Key, T, std::less<Key>,
                           std::allocator<ft::pair<const Key, T> > > {};
}  // namespace ft
#endif
