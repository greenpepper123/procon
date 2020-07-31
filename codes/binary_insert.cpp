#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

class Tree {
public:
    Node* nodes_;
    Node nil;
    Node* root_;
    int elements_;

    Tree(int n) {
        nodes_ = (Node *)malloc(n*sizeof(Node));
        nil = {-1, nullptr, nullptr, nullptr};
        root_ = &nil;
        elements_ = 0;
    }
    
    void insert(int k) {
        Node *y = nullptr;
        Node *x = root_;
        nodes_[elements_] = {k, nullptr, nullptr, nullptr};
        Node *z = &nodes_[elements_];

        while (x != nullptr and elements_ > 0) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;

        if (y == nullptr) {
            root_ = &nodes_[0];
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        elements_++;
    }

    void inorder(Node* n) {
        if (n->left != nullptr) {
            inorder(n->left);
        }
        std::cout << " " << n->key;
        if (n->right != nullptr) {
            inorder(n->right);
        }
    }

    void preorder(Node* n) {
        std::cout << " " << n->key;
        if (n->left != nullptr) {
            preorder(n->left);
        }
        if (n->right != nullptr) {
            preorder(n->right);
        }
    }

    void print() {
        inorder(root_);
        std::cout << "\n";
        preorder(root_);
        std::cout << "\n";
    }
};


int main() {
    int n;
    std::cin >> n;
    Tree T(n);
    for (int i=0; i<n; i++) {
        std::string operation;
        int operand;
        std::cin >> operation;
        if (operation == std::string("insert")) {
            std::cin >> operand;
            T.insert(operand);
        } else {
            T.print();
        }
    }

    return 0;
}