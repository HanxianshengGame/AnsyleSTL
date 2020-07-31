// Authors: Handling
// Created by 15870 on 2020/7/28.
// This is 

#ifndef ANALYSESTL__MYVECTOR_H_
#define ANALYSESTL__MYVECTOR_H_
#include <memory>
#include <algorithm>
//vector的实现技术，关键在于其对大小的控制以及重新配置时的数据移动效率
template<class T, class Alloc = std::allocator<T>>
class MyVector {
 public:
  using value_type = T;
  using pointer = value_type *;
  using iterator = value_type *;
  using reference = value_type &;
  using size_type = size_t;
  using difference_type = ptrdiff_t;
 protected:
  static Alloc data_allocator;
  iterator start;           //表示目前使用空间的头部
  iterator finish;          //表示目前使用空间的尾部
  iterator end_of_storage;  //表示目前可用空间的尾部

  void insert_aux(iterator position, const T &x);
  void deallocate() {
    if (start)
      data_allocator.deallocate(start, end_of_storage - start);
  }
  void destory(iterator beg, iterator end) {
    if (beg) {
      for (auto p = end; p != beg;)
        data_allocator.destroy(--p);
    }
  }
  void fill_initialize(size_type n, const T &value) {
    start = allocate_and_fill(n, value);
    finish = start + n;
    end_of_storage = finish;
  }
 public:
  iterator begin() const { return start; }
  iterator end() const { return finish; }
  size_type size() const { return size_type(end() - begin()); }
  size_type capacity() const { return size_type(end_of_storage - begin()); }
  bool empty() const { return begin() == end(); }
  reference operator[](size_type n) { return *(begin() + n); }
  reference at(size_type n) {
      if (begin() + n >= end())
        throw std::out_of_range("n is out_of_range!\n");
      return *(begin() + n);
  }

  reference front() { return *begin(); }    //返回首元素
  reference back() { return *(end() - 1); }  //返回尾巴元素

  MyVector() : start(nullptr), finish(nullptr), end_of_storage(nullptr) {}
  MyVector(size_type n, const T &value) { fill_initialize(n, value); }
  MyVector(int n, const T &value) { fill_initialize(n, value); }
  MyVector(long n, const T &value) { fill_initialize(n, value); }
  explicit MyVector(size_type n) { fill_initialize(n, T()); }

  ~MyVector() {
    destory(begin(), end());
    deallocate();
  }


  //尾后添加元素
  void push_back(const T &x) {
    if (finish != end_of_storage) {
      data_allocator.construct(finish, x);
      ++finish;
    } else {
      insert_aux(end(), x);
    }
  }
  //尾后出元素
  void pop_back() {
    --finish;
    data_allocator.destory(finish);
  }
  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);
  void insert(iterator position, size_type n, const T &x);

  void resize(size_type new_size, const T &x) {
    if (new_size < size())
      erase(begin() + new_size, end());
    else
      insert(begin() + new_size, size() - new_size, x);
  }
  void resize(size_type new_size) { resize(new_size, T()); }
  void clear() { erase(begin(), end()); }

 protected:
  // 配置空间并填满内容
  iterator allocate_and_fill(size_type n, const T &x) {
    iterator result = data_allocator.allocate(n);
    std::uninitialized_fill_n(result, n, x);
    return result;
  }
};
// Authors: Handling
// Created by 15870 on 2020/7/28.
// This is


template<class T, class Alloc>
void MyVector<T, Alloc>::insert_aux(iterator position, const T &x) {
  if (finish != end_of_storage) {  //还有备用空间
    data_allocator.construct(finish, *(finish - 1));
    ++finish;
    T x_copy = x;
    std::copy_backward(position, finish - 2, finish - 1);
    *position = x_copy;

  } else {
    const size_type old_size = size();
    const size_type len = old_size != 0 ? 2 * old_size : 1;

    iterator new_start = data_allocator.allocate(len);
    iterator new_finish = new_start;

    try {
      new_finish = std::uninitialized_copy(start, position, new_start);
      data_allocator.construct(new_finish, x);
      ++new_finish;
      new_finish = std::uninitialized_copy(position, finish, new_finish);

    } catch (...) {
      destory(new_start, new_finish);
      data_allocator.deallocate(new_start, len);
      throw;
    }

    this->destory(begin(), end());
    deallocate();

    start = new_start;
    finish = new_finish;
    end_of_storage = new_start + len;
  }
}
template<class T, class Alloc>
//typename 要写，因为MyVector<T,Alloc>::iterator 在T没有被推断之前，不清楚iterator到底是什么
typename MyVector<T, Alloc>::iterator MyVector<T, Alloc>::erase(iterator first, iterator last) {
  iterator i = std::copy(last, finish, first);
  destory(i, finish);
  finish = finish - (last - first);
  return first;
}
template<class T, class Alloc>
void MyVector<T, Alloc>::insert(iterator position, size_type n, const T &x) {
  if (n != 0) {
    if (size_type(end_of_storage - finish) >= n) {
      //备用空间足够大于等于其新增元素个数
      T x_copy = x;
      const size_type elems_after = finish - position;
      iterator old_finish = finish;
      if (elems_after > n) {
        std::uninitialized_copy(finish - n, finish, finish);
        finish += n;
        std::copy_backward(position, old_finish);
        std::fill(position, position + n, x_copy);
      } else {
        std::uninitialized_fill_n(finish, n - elems_after, x_copy);
        finish += n - elems_after;
        std::uninitialized_copy(position, old_finish, finish);
        finish += elems_after;
        std::fill(position, old_finish, x_copy);
      }
    } else {
      //备用空间小于”新增元素个数” （额外配置内存）
      const size_type old_size = size();
      const size_type len = old_size + std::max(old_size, n);
      // 配置新的vector空间
      iterator new_start = data_allocator.allocate(len);
      iterator new_finish = new_start;
      try {
        //首先将旧 vector 插入点之前的元素全部赋值到新空间
        new_finish = std::uninitialized_copy(start, position, new_start);
        // 以下再将新增元素（初值皆为n）填入新空间
        new_finish = std::uninitialized_fill_n(new_finish, n, x);
        //以下再将旧 vector 的插入点之后的元素复制到新空间
        new_finish = std::uninitialized_copy(position, finish, new_finish);
      } catch (...) {
        destory(new_start, new_finish);
        data_allocator.deallocate(new_start, len);
        throw;
      }
      this->destory(start, finish);
      deallocate();
      start = new_start;
      finish = new_finish;
      end_of_storage = new_start + len;
    }
  }
}
template<class T, class Alloc>
typename MyVector<T, Alloc>::iterator MyVector<T, Alloc>::erase(iterator position) {
  if (position + 1 != end())
    std::copy(position + 1, finish, position);
  --finish;
  data_allocator.destroy(finish);
  return position;
}
template<class T, class Alloc>
Alloc MyVector<T,Alloc>::data_allocator;
#endif //ANALYSESTL__MYVECTOR_H_
