#pragma once
#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data;
    int top;
    int capacity;

public:
    Stack(int size = 10) : capacity(size), top(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(T item) {
        if (top == capacity - 1) {
            throw std::overflow_error("Stack overflow");
        }
        data[++top] = item;
    }

    void pop() {
        if (top == -1) {
            throw std::underflow_error("Stack underflow");
        }
        --top;
    }

    T peek() const {
        if (top == -1) {
            throw std::underflow_error("Stack is empty");
        }
        return data[top];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

#endif
