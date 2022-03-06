//
// Created by Jay Lee on 2022/03/06.
//

#ifndef TEST_LINKEDLIST_H
#define TEST_LINKEDLIST_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* next_node = nullptr;

public:
    explicit Node(T data);
    [[nodiscard]] T get() const;
    [[nodiscard]] Node<T>* next() const;
    void set_next(Node<T>* next);
    ~Node<T>();
};
template <typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;

public:
    LinkedList();
    ~LinkedList();
    void append(T value);
    void remove(int index = 0);
    T peek();
    void print();
};

#endif //TEST_LINKEDLIST_H
