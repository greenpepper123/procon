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

    void find(int k, Node* n) {
        if (n->key == k) {
            std::cout << "yes\n";
        } else if (n->key > k) {
            if (n->left == nullptr) {
                std::cout << "no\n";
            } else {
                find(k, n->left);
            }
        } else {
            if (n->right== nullptr) {
                std::cout << "no\n";
            } else {
                find(k, n->right);
            }
        }
    }

    Node* find_node(int k, Node* n) {
        if (n->key == k) {
            return n;
        } else if (n->key > k) {
            return find_node(k, n->left);
        } else {
            return find_node(k, n->right);
        }
    }

    int inorder_first(Node* n) {
        if (n->left != nullptr) {
            return inorder_first(n->left);
        }
        return n->key;
    }

    void del(int k) {
        Node* to_del = find_node(k, root_);
        if (to_del->left == nullptr and to_del->right == nullptr) {
            if (to_del->parent->left == to_del) {
                to_del->parent->left = nullptr;
            } else {
                to_del->parent->right = nullptr;
            }
        } else if (to_del->left != nullptr and to_del->right == nullptr) {
            if (to_del->parent->left == to_del) {
                to_del->parent->left = to_del->left;
            } else {
                to_del->parent->right = to_del->left;
            }
            to_del->left->parent = to_del->parent;
        } else if (to_del->left == nullptr and to_del->right != nullptr) {
            if (to_del->parent->left == to_del) {
                to_del->parent->left = to_del->right;
            } else {
                to_del->parent->right = to_del->right;
            }
            to_del->right->parent = to_del->parent;
        } else {
            int next = inorder_first(to_del->right);
            del(next);
            to_del->key = next;
        }
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
        } else if (operation == std::string("find")) {
            std::cin >> operand;
            T.find(operand, T.root_);
        } else if (operation == std::string("delete")) {
            std::cin >> operand;
            T.del(operand);
        } else {
            T.print();
        }
    }

    return 0;
}