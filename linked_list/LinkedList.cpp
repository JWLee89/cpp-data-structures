//
// Created by Jay Lee on 2022/03/06.
//
#include <iostream>
#include <string>
#include "LinkedList.h"


template <typename T>
LinkedList<T>::LinkedList() = default;
/**
 * Append to linked list
 * @param value The value to append
 * */
template <typename T>
void LinkedList<T>::append(T value) {
    Node<T>* new_node = new Node(value);
    if (this->head == nullptr) {
        this->head = new_node;
        std::cout << "added new head" << std::endl;
    } else {
        Node<T>* current_node = this->head;
        while (current_node->next() != nullptr) {
            current_node = current_node->next();
        }
        current_node->set_next(new_node);
    }
}

/**
 * Update references during linked list iteration
 * @param prev_node Reference to the previous node pointer
 * @param current_node Reference to the current node pointer
 * @param index Reference to the index
 * */
template <typename T>
void update_references(Node<T>*& prev_node, Node<T>*& current_node, int& index) {
    prev_node = current_node;
    current_node = current_node->next();
    index--;
}


/**
 * Remove value from linked list by index. Yee ...
 * @param index The value to remove.
 * */
template <typename T>
void LinkedList<T>::remove(int index) {
    if (index < 0) {
        throw std::invalid_argument("Cannot provide negative index value to remove()");
    }

    Node<T>* current_node {this->head};

    // Node to delete is head node
    if (index == 0 && this->head != nullptr) {
        this->head = this->head->next();
        delete current_node;
        return;
    }

    Node<T>* prev_node {nullptr};
    update_references(prev_node, current_node, index);


    // Iterate through linked list to find node to delete
    while (current_node != nullptr) {
        // Found node that we want to remove.
        if (index == 0) {
            std::cout << "Removing node with value: " << current_node->get() << std::endl;
            Node<T>* node_to_delete = current_node;
            // Link previous node with next node
            prev_node->set_next(node_to_delete->next());
            delete node_to_delete;
            break;
        }
        update_references(prev_node, current_node, index);
    }

    if (index != 0) {
        throw std::invalid_argument("Index out of bounds ...");
    }
}

/**
 * Print the contents of the linked list
 * */
template <typename T>
void LinkedList<T>::print() {
    Node<T>* current = this->head;
    while (current != nullptr) {
        std::cout << current->get() << ", " << std::endl;
        current = current->next();
    }
}

/**
 * Grab the contents of the head node of the linked list;
 * */
template <typename T>
T LinkedList<T>::peek() {
    // Replace custom exception if needed.
    assert(this->head);
    return this->head->get();
}

template <typename T>
LinkedList<T>::~LinkedList() {
    std::cout << "deleting linked list" << std::endl;
    Node<T>* node_to_delete = this->head;
    while (node_to_delete != nullptr) {
        node_to_delete = node_to_delete->next();
        delete this->head;
        this->head = node_to_delete;
    }
    std::cout << "Reset linked list" << std::endl;
}
template <typename T>
Node<T>::Node(T data) {
    this->data = data;
}

template <typename T>
T Node<T>::get() const {
    return this->data;
}

template <typename T>
Node<T>* Node<T>::next() const {
    return this->next_node;
}

template <typename T>
void Node<T>::set_next(Node<T> *const next) {
    this->next_node = next;
}

template <typename T>
Node<T>::~Node<T>() {
    std::cout << "deleting node " << this->data << std::endl;
}

// Explicit instantiations
template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<std::string>;
