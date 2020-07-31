// Authors: Handling
// Created by 15870 on 2020/7/28.
// This is 

#ifndef ANALYSESTL__MYITERATOR_H_
#define ANALYSESTL__MYITERATOR_H_

#include <iterator>



// count 算法
template<class Iter, class Type>
typename std::iterator_traits<Iter>::difference_type
count(Iter first, Iter last, const Type &value) {
  typename std::iterator_traits<Iter>::difference n = 0;
  for(; first != last; ++last) {
    if(*first == value)
      ++n;
    return n;
  }
}



#endif //ANALYSESTL__MYITERATOR_H_
