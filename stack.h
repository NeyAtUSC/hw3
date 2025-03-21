#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() : std::vector<T>() {}

template <typename T>
Stack<T>::~Stack() {
    std::vector<T>::clear();
}

template <typename T>
bool Stack<T>::empty() const {
    return std::vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item) {
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {std::underflow_error("ERROR: Cannot Pop Empty Stack")}
    std::vector<T>::pop_back();
}

template <typename T>
T const& Stack<T>::top() const {
    if (empty()) {std::underflow_error("ERROR: Cannot Access Top from Empty Stack")}
    return std::vector<T>::back(); //first in last out
}


#endif