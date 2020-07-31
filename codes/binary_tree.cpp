#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int depth_rec(int* type, int* parent, int* depth, int id) {
    if (type[id] == 0) {
        return 0;
    } else {
        if (depth[parent[id]] == -1) {
            depth[parent[id]] = depth_rec(type, parent, depth, parent[id])+1;
        }
        return depth[parent[id]];
    }
}

int height_rec(int* type, int* deg, int* left, int* right, int* height, int id) {
    if (deg[id] == 0) {
        return 0;
    } else {
        if (left[id] >= 0) { //left exists
            if (right[id] >= 0) { //right exists
                if (height[left[id]] == -1) {
                    height[left[id]] = height_rec(type, deg, left, right, height, left[id]);
                }
                if (height[right[id]] == -1) {
                    height[right[id]] = height_rec(type, deg, left, right, height, right[id]);
                }
                if (height[left[id]]>height[right[id]]) {
                    height[id] = height[left[id]] + 1;
                } else {
                    height[id] = height[right[id]] + 1;
                }
            } else {
                if (height[left[id]] == -1) {
                    height[left[id]] = height_rec(type, deg, left, right, height, left[id]);
                }
                height[id] = height[left[id]] + 1;
            }
        } else {
            if (height[right[id]] == -1) {
                height[right[id]] = height_rec(type, deg, left, right, height, right[id]);
            }
            height[id] = height[right[id]] + 1;
        }
        return height[id];
    }
}

std::string typef(int i) {
    if (i==0) {
        return "root";
    } else if (i==1) {
        return "internal node";
    } else if (i==2) {
        return "leaf";
    }
}

int main() {
    int n;
    int left[25], right[25], type[25], depth[25], height[25], deg[25]={}, parent[25], sibling[25];
    std::cin >> n;
    for (int i=0; i<n; i++) {
        parent[i] = -1;
        sibling[i] = -1;
        type[i] = 1;
        depth[i] = -1;
        height[i] = -1;
    }
    for (int i=0; i<n; i++) {
        int id;
        std::cin >> id;
        std::cin >> left[id] >> right[id];
        if (left[id] >= 0) {
            deg[id]+=1;
            parent[left[id]] = id;
        }
        if (right[id] >= 0) {
            deg[id]+=1;
            parent[right[id]] = id;
        }
        if (deg[id] == 2) {
            sibling[left[id]] = right[id];
            sibling[right[id]] = left[id];
        } else if (deg[id] == 0) {
            type[id] = 2;
        }
    }
    for (int i=0; i<n; i++) {
        if (parent[i] == -1) {
            type[i] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, parent[i], sibling[i], deg[i], depth_rec(type, parent, depth, i), height_rec(type, deg, left, right, height, i), typef(type[i]).c_str());
    }

    return 0;
}
