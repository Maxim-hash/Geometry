#include "readCircle.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <exception>
#include <iostream>
#include <vector>
#define N 256
#define PI 3.14
using namespace std;

struct circle {
    string figure;
    int x, y;
    double r;
    double perimeter;
    double area;
};

struct triangle {
    string figure;
    vector<int> xy;
    double perimeter;
    double area;
};

struct figures
{
    circle a;
    triangle b;
};

void inf_input()
{
    int num = 0;
    cout << "Enter N = ";
    cin >> num;
    char tmp[N];
    char fig[N];
    char coo[N];
    vector<string> res_str;
    vector<figures> result;
    string str, coor;
    for (int i = 0; i < num; i++) {
        cin.clear();
        while (cin.get() != '\n')
            ;
        cout << "enter circle(x y, r) or triangle ((x1 y1, x2 y2, x3 y3, x1 y1))" << endl;
        int meetings = 0;
        cin.getline(tmp, 100, '(');
        cin.getline(coo, 100);
        _strlwr(tmp);
        if (strcmp("triangle", tmp) == 0)
        {
            int size = strlen(coo);
            try {
                if (coo[0] == '(' && coo[size - 1] == ')' && coo[size - 2] == ')')
                {
                    coo[0] = ' ';
                    coo[size - 1] = ' ';
                    coo[size - 2] = ' ';
                }
                else
                    throw "invalid input format";
            }
            catch (const char* exception)
            {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        if (strcmp("circle", tmp) == 0)
        {
            int size = strlen(coo);
            try {
                if (coo[size - 1] == ')')
                {
                    coo[size - 1] = ' ';
                }
                else
                    throw "invalid input format";
            }
            catch (const char* exception)
            {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        try {
            if (strcmp("circle", tmp) != 0 && strcmp("triangle", tmp) != 0)
            {
                throw "unknown figure";
            }
        }
        catch (const char* exception)
        {
            std::cerr << "Error: " << exception << '\n';
            goto next;
        }
        str = string(tmp);
        coor = string(coo);
        res_str = split(coor, ',');
        if (strcmp("circle", tmp) == 0)
        {
            try {
                if (res_str.size() != 3)
                {
                    throw "invalid input format";
                }
            }
            catch (const char* exception)
            {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        if (strcmp("triangle", tmp) == 0)
        {
            try {
                if (res_str.size() != 8)
                {
                    throw "invalid input format";
                }
            }
            catch (const char* exception)
            {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        fill_struct(res_str, tmp, result);
    next:
        str = "";
        coor = "";
    }
    cout << endl;
    print(result);
}

int main()
{
    inf_input();
    return 0;
} 