#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  Heap(int m = 2, PComparator c = PComparator());
  ~Heap();

  void push(const T& item);
  T const & top() const;
  void pop();
  bool empty() const;
  size_t size() const;
  void printHeap() const; // Add the printHeap function

private:
  std::vector<T> items_;
  int m_;
  PComparator c_;

  void heapify(size_t idx);
};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c) {}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return items_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return items_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  items_.push_back(item);
  size_t idx = items_.size() - 1;

  while (idx != 0) {
    size_t p_idx = (idx - 1) / m_;
    if (c_(items_[p_idx], items_[idx])) {
      break;
    }
    std::swap(items_[idx], items_[p_idx]);
    idx = p_idx;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t idx) {
  size_t best_idx = idx;

  for (int i = 1; i <= m_; ++i) {
    size_t child_idx = m_ * idx + i;
    if (child_idx < items_.size() && c_(items_[child_idx], items_[best_idx])) {
      best_idx = child_idx;
    }
  }
  if (best_idx != idx) {
    std::swap(items_[idx], items_[best_idx]);
    heapify(best_idx);
  }
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {
  if (empty()) {
    throw std::underflow_error("ERROR: cannot access top of empty heap");
  }
  return items_.front();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
  if (empty()) {
    throw std::underflow_error("ERROR: cannot pop from empty heap");
  }

  items_[0] = items_.back();
  items_.pop_back();

  if (!empty()) {
    heapify(0);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::printHeap() const {
  for (const auto& item : items_) {
    std::cout << item->time << " ";
  }
  std::cout << std::endl;
}

#endif

