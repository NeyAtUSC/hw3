#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()); //done

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(); //automatic

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item); //done

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const; //done

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop(); //done

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const; //done

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const; //done

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items_;
  int m_;
  PComparator c_;

  void heapify(size_t idx); //done
  
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c) {}

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
    T& current = items_[idx];
    T& parent = items_[p_idx];
    if (c_(parent, current)) {
      break;
    }
    std::swap(current, parent);
    idx = p_idx;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t idx) {
  size_t best_idx = idx;

  for (int i = 1; i<= m_; ++i) {
    size_t child_idx = m_ * idx + i;
  }

  if (child_idx < items_.size() && c_(items_[child_idx], items_[best_idx])) {
    best_idx = child_idx;
  }

  if (best_idx != idx) {
    std::swap(items_[idx], items_[best_idx]);
    heapify(best_idx);
  }
} 

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("ERROR: cannot access top of empty heap")
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("ERROR: cannot pop from empty heap")

  }

  items_[0] = items_.back();
  items_.pop_back();

  if (!empty()) {
    heapify(0);
  }
}



#endif

