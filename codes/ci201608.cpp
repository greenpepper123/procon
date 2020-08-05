#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct number {
    int num;
    int posx;
    int posy;

    int width() {
        if (num == 1) {
            return 1;
        } else {
            return 4;
        }
    }
};

void draw(number n, int x, char** canvas) {
}

int main() {
    std::vector<number> numbers;
    std::string line, poe;
    int nu, count=0, xx=0;
    char canvas[10][100];
    for (int i=0; i<10; i++) {
        for (int j=0; j<100; j++) {
            canvas[i][j] = ' ';
        }
    }
    std::cin >> poe;
    std::istringstream iss(poe);
    if (std::getline(iss, line, ',')) {
        for (int i=0; i<line.size(); i++) {
            numbers.push_back({int(line[i]-'0'), 0, 0});
        }
    }
    while (std::getline(iss, line, ',')) {        
        if (count%2 == 0) {
            numbers[count/2].posy=std::stoi(line);
        } else {
            numbers[count/2].posx=std::stoi(line);
        }
        count++;
    }
    std::getline(iss, line, '\0');
    numbers[count/2].posy=std::stoi(line);
    for (int i=0; i<numbers.size(); i++) {
        std::cout << numbers[i].num << numbers[i].posy << numbers[i].posx << "\n";
    }

    for (int i=0; i<numbers.size(); i++) {
        number n = numbers[i];
        int yy=n.posy;
        if (n.num == 0) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+1][xx+3] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx] = '|';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx] = '*';
            canvas[yy+4][xx+1] = '*';
            canvas[yy+4][xx+2] = '*';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 1) {
            canvas[yy][xx] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+3][xx] = '|';
            canvas[yy+4][xx] = '*';
        } else if (n.num == 2) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx+3] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+1] = '*';
            canvas[yy+2][xx+2] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx] = '|';
            canvas[yy+4][xx] = '*';
            canvas[yy+4][xx+1] = '*';
            canvas[yy+4][xx+2] = '*';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 3) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx+3] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+1] = '*';
            canvas[yy+2][xx+2] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx] = '*';
            canvas[yy+4][xx+1] = '*';
            canvas[yy+4][xx+2] = '*';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 4) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+1][xx+3] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+1] = '*';
            canvas[yy+2][xx+2] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 5) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+1] = '*';
            canvas[yy+2][xx+2] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx] = '*';
            canvas[yy+4][xx+1] = '*';
            canvas[yy+4][xx+2] = '*';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 6) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+1] = '*';
            canvas[yy+2][xx+2] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx] = '|';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx] = '*';
            canvas[yy+4][xx+1] = '*';
            canvas[yy+4][xx+2] = '*';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 7) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+1][xx+3] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 8) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+1][xx+3] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+1] = '*';
            canvas[yy+2][xx+2] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx] = '|';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx] = '*';
            canvas[yy+4][xx+1] = '*';
            canvas[yy+4][xx+2] = '*';
            canvas[yy+4][xx+3] = '*';
        } else if (n.num == 9) {
            canvas[yy][xx] = '*';
            canvas[yy][xx+1] = '*';
            canvas[yy][xx+2] = '*';
            canvas[yy][xx+3] = '*';
            canvas[yy+1][xx] = '|';
            canvas[yy+1][xx+3] = '|';
            canvas[yy+2][xx] = '*';
            canvas[yy+2][xx+1] = '*';
            canvas[yy+2][xx+2] = '*';
            canvas[yy+2][xx+3] = '*';
            canvas[yy+3][xx+3] = '|';
            canvas[yy+4][xx] = '*';
            canvas[yy+4][xx+1] = '*';
            canvas[yy+4][xx+2] = '*';
            canvas[yy+4][xx+3] = '*';
        }
        xx+=numbers[i].width()+numbers[i].posx;
    }

    std::ofstream of;
    of.open("out.txt", std::ios::out);
    for (int i=0; i<10; i++) {
        for (int j=0; j<50; j++) {
            of << canvas[i][j];
        }
        of << "\n";
    }

    return 0;
}
