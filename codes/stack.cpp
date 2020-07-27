#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

std::vector<long int> stack = {};
void push(int a) {
    stack.push_back(a);
}
int pop() {
    int a = stack.back();
    stack.pop_back();
    return a;
}

int main() {

    while (true) {
        std::string s;
        std::cin >> s;
        if (std::cin.eof()) {
            break;
        }

        if (s == "+") {
            push(pop()+pop());
        } else if (s == "-") {
            auto aa = pop();
            auto ab = pop();
            push(ab-aa);
        } else if (s == "*") {
            push(pop()*pop());
        } else { // instant value
            push(std::stoi(s));
        }
    }

    std::cout << pop() << std::endl;

    return 0;
}
