#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

template <typename T>
class Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size = 10) : capacity(size), front(0), rear(-1) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T item) {
        if (rear == capacity - 1) {
            throw std::overflow_error("Queue overflow");
        }
        data[++rear] = item;
    }

    void dequeue() {
        if (front > rear) {
            throw std::underflow_error("Queue underflow");
        }
        ++front;
    }

    T frontItem() const {
        if (front > rear) {
            throw std::underflow_error("Queue is empty");
        }
        return data[front];
    }

    bool isEmpty() const {
        return front > rear;
    }
};

#endif
