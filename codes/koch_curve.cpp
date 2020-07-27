#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

typedef std::pair<double, double> vertex;
typedef std::pair<vertex, vertex> two_vertices;

constexpr vertex operator*(double f, const vertex& v) {
    return {f*v.first, f*v.second};
}
constexpr vertex operator/(const vertex& v, double f) {
    return {v.first/f, v.second/f};
}
constexpr vertex operator+(const vertex& v1, const vertex& v2) {
    return {v1.first+v2.first, v1.second+v2.second};
}

double absv(two_vertices t) {
    return std::sqrt(std::pow(t.first.first - t.second.first, 2)+std::pow(t.first.second - t.second.second, 2));
}

std::vector<vertex> koch(two_vertices t) {
    auto v1 = (2.0*t.first + t.second)/3.0;
    auto v3 = (t.first + 2.0*t.second)/3.0;
    double abs = absv({v1, v3});
    double atan = std::atan2(v3.second-v1.second, v3.first-v1.first);
    auto v2 = v1 + vertex(abs*std::cos(atan+M_PI/3.0), abs*std::sin(atan+M_PI/3.0));
    return {v1, v2, v3};
}

std::vector<vertex> koch_n(std::vector<vertex> t, int ttl) {
    if (ttl==0) {
        return t;
    }
    std::vector<vertex> ret;
    for (int i=0; i<t.size()-1; i++) {
        ret.push_back(t[i]);
        auto newv = koch({t[i], t[i+1]});
        ret.push_back(newv[0]);
        ret.push_back(newv[1]);
        ret.push_back(newv[2]);
    }
    ret.push_back(t[t.size()-1]);
    if (--ttl > 0) {
        return koch_n(ret, ttl);
    } else {
        return ret;
    }
}

int main() {
    int n;
    std::cin >> n;

    auto v=koch_n({{0,0}, {100,0}}, n);
    for (int i=0; i<v.size(); i++) {
        std::cout << std::fixed << std::setprecision(8) << v[i].first << " " << v[i].second << std::endl;
    }

    return 0;
}
