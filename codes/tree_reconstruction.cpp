#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

void reconstruct(int pb, int pe, int ib, int ie, int* left, int* right, int* preorder, int* inorder) {
    if (pe != pb) {
        for (int i=ib; i<=ie; i++) {
            if (inorder[i] == preorder[pb]) {
                if (i==ib) {
                    left[preorder[pb]] = -1;
                } else {
                    left[preorder[pb]] = preorder[pb+1];
                    reconstruct(pb+1, pb+i-ib, ib, i-1, left, right, preorder, inorder);
                }
                if (i==ie) {
                    right[preorder[pb]] = -1;
                } else {
                    right[preorder[pb]] = preorder[pb+1+i-ib];
                    reconstruct(pb+i+1-ib, pe, i+1, ie, left, right, preorder, inorder);
                }
            }
        }
    } else {
        left[preorder[pb]] = -1;
        right[preorder[pb]] = -1;
    }
}

void postorder(int root, int id, int* left, int* right) {
    if (left[id] >= 0) {
        postorder(root, left[id], left, right);
    }
    if (right[id] >= 0) {
        postorder(root, right[id], left, right);
    }
    std::cout << id;
    if (id != root) {
        std::cout << " ";
    }
}

int main() {
    int n;
    int left[41], right[41], preorder[41], inorder[41];
    std::cin >> n;
    
    for (int i=0; i<n; i++) {
        std::cin >> preorder[i];
    }
    for (int i=0; i<n; i++) {
        std::cin >> inorder[i];
    }

    reconstruct(0, n-1, 0, n-1, left, right, preorder, inorder);

    postorder(preorder[0], preorder[0], left, right);
    std::cout << "\n";

    return 0;
}
