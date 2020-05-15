#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "readCircle.h"
#define N 256
using namespace std;
struct circle {
    char figure[N];
    int x, y;
    double r;
};
int main()
{
    int num = 0;
    cout << "Enter N = ";
    cin >> num;
    char tmp[N];
    char tmp1[N];
    for (int i = 0; i < num; i++) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "enter figure(x y, r)" << endl;
        cin.getline(tmp, 100, '(');
        cout << tmp << endl;
        cin.getline(tmp1, 100,')');
        cout << tmp1 << endl;
        string str = string(tmp);
        string coor = string(tmp1);
        split(coor, ',');
    }

    return 0;
} 