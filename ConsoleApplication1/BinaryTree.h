#pragma once
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    Node* root;

    void insert(Node*& node, T data) {
        if (node == nullptr) {
            node = new Node{ data, nullptr, nullptr };
        }
        else if (data < node->data) {
            insert(node->left, data);
        }
        else {
            insert(node->right, data);
        }
    }

    void inorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        // Optional: Add a recursive deletion function here if needed
    }

    void insert(T data) {
        insert(root, data);
    }

    void displayInOrder() const {
        inorder(root);
        std::cout << std::endl;
    }
};

#endif
