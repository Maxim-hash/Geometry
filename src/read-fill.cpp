#include "geom.h"
#include "readCircle.h"
#include "intesections.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string.h>
#define N 256
#define PI 3.14
using namespace std;


void fill_struct(vector<string>& a, char figure[], vector<figures>& res)
{
    vector<int> b;
    b.resize(a.size());
    for (int i = 0; i < int(a.size()); i++) {
        b[i] = atoi(a[i].c_str());
    }
    int sizee = b.size();
    if (strcmp("circle", figure) == 0) {
        try {
            if (b[sizee - 1] > 0) {
                circle* to_push = new circle;
                triangle* to_push1 = new triangle;
                to_push->figure = "circle";
                to_push->x = b[0];
                to_push->y = b[1];
                to_push->r = b[2];
                to_push->perimeter = 2 * PI * b[2];
                to_push->area = PI * b[2] * b[2];

                figures* f = new figures;
                f->a = *to_push;
                f->b = *to_push1;
                res.push_back(*f);
                return;
            } else
                throw "invalid input format";
        } catch (const char* exception) {
            std::cerr << "Error: " << exception << '\n';
        }
    }
    if (strcmp("triangle", figure) == 0) {
        try {
            if (b[sizee - 1] == b[1] && b[sizee - 2] == b[0]) {
                triangle* to_push = new triangle;
                circle* to_push1 = new circle;
                to_push->figure = "triangle";
                to_push->xy = b;
                to_push->perimeter = perimetrs(b);
                to_push->area = areas(b);

                figures* f = new figures;
                f->b = *to_push;
                f->a = *to_push1;
                res.push_back(*f);
                return;
            } else
                throw "invalid input format: check the latest coordinates";
        } catch (const char* exception) {
            std::cerr << "Error: " << exception << '\n';
        }
    }
}

void print_triangle(triangle* tr, vector<figures> result, int num)
{
    if (tr->figure == "") {
        return;
    }
    cout << "\ttriangle((";
    int count = 0;
    for (std::vector<int>::const_iterator i = tr->xy.begin(); i != tr->xy.end();
         ++i) {
        std::cout << tr->xy[count];
        count++;
        if (count % 2 == 0 && count != 8) {
            cout << ", ";
        } else if (count != 8) {
            cout << " ";
        }
    }
    cout << "))" << endl;
    cout << "\tperimeter = " << tr->perimeter << endl;
    cout << "\tarea = " << tr->area << endl;
        int s = result.size();
    bool flg;
    for (int i = 0; i < s; i++) {
        if (i + 1 == num) {
            goto nxt;
        }
        if (result[i].a.figure == "") {
            flg = intersections_triangles(tr, &(result[i].b));
            if (flg) {
                tr->inter.push_back(i + 1);
                tr->f.push_back(2);
                flg = false;
            }
        } else {
            flg = inter_circle_triangl(&(result[i].a), tr);
            if (flg) {
                tr->inter.push_back(i + 1);
                tr->f.push_back(1);
                flg = false;
            }
        }
    nxt:
        flg = false;
    }
    if (tr->inter.empty()) {
        return;
    } else {
        cout << "\tintersections:" << endl;
        int sizee = tr->inter.size();
        for (int i = 0; i < sizee; i++) {
            cout << "\t\t" << tr->inter[i] << ". ";
            if (tr->f[i] == 1) {
                cout << "circle" << endl;
            } else {
                cout << "triangle" << endl;
            }
        }
    }
}

void print_circle(circle* c, vector<figures> result, int num)
{
    if (c->figure == "") {
        return;
    }
    cout << "\tcircle(" << c->x << " " << c->y << ", " << c->r << ")" << endl;
    cout << "\tperimeter = " << c->perimeter << endl;
    cout << "\tarea = " << c->area << endl;
        int s = result.size();
    bool flg;
    for (int i = 0; i < s; i++) {
        if (i + 1 == num) {
            goto nxt;
        }
        if (result[i].a.figure == "") {
            flg = inter_circle_triangl(c, &(result[i].b));
            if (flg) {
                c->inter.push_back(i + 1);
                c->f.push_back(2);
                flg = false;
            }
        } else {
            flg = intersections_circles(c, &(result[i].a));
            if (flg) {
                c->inter.push_back(i + 1);
                c->f.push_back(1);
                flg = false;
            }
        }
    nxt:
        flg = false;
    }
    if (c->inter.empty()) {
        return;
    } else {
        cout << "\tintersections:" << endl;
        int sizee = c->inter.size();
        for (int i = 0; i < sizee; i++) {
            cout << "\t\t" << c->inter[i] << ". ";
            if (c->f[i] == 1) {
                cout << "circle" << endl;
            } else {
                cout << "triangle" << endl;
            }
        }
    }
}

void print(vector<figures> result)
{
    int count = 0;
    for (std::vector<figures>::iterator i = result.begin(); i != result.end();
         ++i) {
        count++;
        cout << count << ". ";
        print_circle(&(i->a), result, count);
        print_triangle(&(i->b), result, count);
    }
}

void inf_input()
{
    int num = 0;
    cout << "Enter N = ";
    cin >> num;
    cin.ignore();
    char tmp[N];
    char coo[N];
    vector<string> res_str;
    vector<figures> result;
    string str, coor;
    for (int i = 0; i < num; i++) {
        cout << "enter circle(x y, r) or triangle ((x1 y1, x2 y2, x3 y3, "
                "x1 "
                "y1)): ";
        cin.getline(tmp, 100, '(');
        cin.getline(coo, 100);
        _strlwr(tmp);
        if (strcmp("triangle", tmp) == 0) {
            int size = strlen(coo);
            try {
                if (coo[0] == '(' && coo[size - 1] == ')'
                    && coo[size - 2] == ')') {
                    coo[0] = ' ';
                    coo[size - 1] = ' ';
                    coo[size - 2] = ' ';
                } else
                    throw "invalid input format";
            } catch (const char* exception) {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        if (strcmp("circle", tmp) == 0) {
            int size = strlen(coo);
            try {
                if (coo[size - 1] == ')') {
                    coo[size - 1] = ' ';
                } else
                    throw "invalid input format";
            } catch (const char* exception) {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        try {
            if (strcmp("circle", tmp) != 0 && strcmp("triangle", tmp) != 0) {
                throw "unknown figure";
            }
        } catch (const char* exception) {
            std::cerr << "Error: " << exception << '\n';
            goto next;
        }
        str = string(tmp);
        coor = string(coo);
        res_str = split(coor, ',');
        if (strcmp("circle", tmp) == 0) {
            try {
                if (res_str.size() != 3) {
                    throw "invalid input format";
                }
            } catch (const char* exception) {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        if (strcmp("triangle", tmp) == 0) {
            try {
                if (res_str.size() != 8) {
                    throw "invalid input format";
                }
            } catch (const char* exception) {
                std::cerr << "Error: " << exception << '\n';
                goto next;
            }
        }
        fill_struct(res_str, tmp, result);
    next:
        str = " ";
        coor = " ";
    }
    cout << endl;
    print(result);
}
