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
    std::cin >> n;
    int parent[100000], depth[100000], type[100000]; // root:0, in:1, leaf:2
    std::vector<std::vector<int>> child(n);
    for (int i=0; i<n; i++) {
        parent[i]=-1; //default
        depth[i]=-1; //default
    }
    for (int i=0; i<n; i++) {
        int id,k;
        std::cin >> id >> k;
        if (k==0) {
            type[id] = 2;
        }
        for (int j=0; j<k; j++) {
            int c;
            std::cin >> c;
            child[id].push_back(c);
            parent[c] = id;
        }
    }
    for (int i=0; i<n; i++) {
        if (parent[i]==-1) {
            type[i] = 0;
        } else if (type[i] != 2) {
            type[i] = 1;
        }
    }

    for (int i=0; i<n; i++) {
        std::string childs;
        for (int j=0; j<child[i].size(); j++) {
            childs += std::to_string(child[i][j]);
            if (j!=child[i].size()-1) {
                childs += ", ";
            }
        }
        //printf("node %d: parent = %d, depth = %d, %s, [%s]\n", i, parent[i], depth_rec(type, parent, depth, i), typef(type[i]).c_str(), childs.c_str());
        std::cout << "node " << i << ": parent = " << parent[i] << ", depth = " << depth_rec(type, parent, depth, i) << ", " << typef(type[i]).c_str() << ", [" << childs.c_str() << "]\n";
    }

    return 0;
}
