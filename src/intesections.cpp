#include "read-fill.h"
#include <cmath>
#include <iostream>
using namespace std;

bool intersections_circles(circle* a, circle* b)
{
    double d
            = sqrt(((a->x) - (b->x)) * ((a->x) - (b->x))
                   + ((a->y) - (b->y)) * ((a->y) - (b->y)));
    double r1 = a->r, r2 = b->r;
    if (d == (r1 + r2) || d > (r1 + r2))
        return false;
    if (d < (r1 + r2))
        return true;
}

double area_int(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool inters_segment(int a, int b, int c, int d)
{
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }
    return max(a, c) <= min(b, d);
}

bool inter_segments(
        int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    return inters_segment(x1, x2, x3, x4) && inters_segment(y1, y1, y3, y4)
            && (area_int(x1, y1, x2, y2, x3, y3)
                        * area_int(x1, y1, x2, y2, x4, y4)
                <= 0)
            && (area_int(x3, y3, x4, y4, x1, y1)
                        * area_int(x3, y3, x4, y4, x2, y2)
                <= 0);
}
bool intersections_triangles(triangle* a, triangle* b)
{
    int x1 = a->xy[0], y1 = a->xy[1], x2 = a->xy[2], y2 = a->xy[3],
        x3 = a->xy[4], y3 = a->xy[5];
    int x4 = b->xy[0], y4 = b->xy[1], x5 = b->xy[2], y5 = b->xy[3],
        x6 = b->xy[4], y6 = b->xy[5];
    if (inter_segments(x1, y1, x2, y2, x4, y4, x5, y5)) {
        return true;
    }
    if (inter_segments(x1, y1, x2, y2, x5, y5, x6, y6)) {
        return true;
    }
    if (inter_segments(x1, y1, x2, y2, x4, y4, x6, y6)) {
        return true;
    }
    if (inter_segments(x2, y2, x3, y3, x4, y4, x5, y5)) {
        return true;
    }
    if (inter_segments(x2, y2, x3, y3, x5, y5, x6, y6)) {
        return true;
    }
    if (inter_segments(x2, y2, x3, y3, x4, y4, x6, y6)) {
        return true;
    }
    if (inter_segments(x1, y1, x3, y3, x4, y4, x5, y5)) {
        return true;
    }
    if (inter_segments(x1, y1, x3, y3, x5, y5, x6, y6)) {
        return true;
    }
    if (inter_segments(x1, y1, x3, y3, x4, y4, x6, y6)) {
        return true;
    }
    return false;
}
bool inter_circle_segment(int x1, int y1, int x2, int y2, int x, int y, int r)
{
    double a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    double b = 2 * ((x2 - x1) * (x1 - x) + (y2 - y1) * (y1 - y));
    double c
            = x * x + y * y + x1 * x1 + y1 * y1 - 2 * (x * x1 + y * y1) - r * r;
    if (-b < 0) {
        return (c < 0);
    }
    if (-b < (2 * a)) {
        return (4 * a * c - b * b < 0);
    }
    return (a + b + c < 0);
}
bool inter_circle_triangl(circle* a, triangle* b)
{
    int x1 = b->xy[0], y1 = b->xy[1], x2 = b->xy[2], y2 = b->xy[3],
        x3 = b->xy[4], y3 = b->xy[5];
    int x = a->x, y = a->y, r = a->r;
    if (inter_circle_segment(x1, y1, x2, y2, x, y, r)) {
        return true;
    }
    if (inter_circle_segment(x1, y1, x3, y3, x, y, r)) {
        return true;
    }
    if (inter_circle_segment(x2, y2, x3, y3, x, y, r)) {
        return true;
    }
    return false;
}