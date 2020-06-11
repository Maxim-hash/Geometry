 #ifndef INTESECTIONS_H
#define INTESECTIONS_H
#include "read-fill.h"

bool intersections_circles(circle* a, circle* b);
double area_int(int x1, int y1, int x2, int y2, int x3, int y3);
bool inters_segment(int a, int b, int c, int d);
bool inter_segments(
        int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
bool intersections_triangles(triangle* a, triangle* b);
bool inter_circle_segment(int x1, int y1, int x2, int y2, int x, int y, int r);
bool inter_circle_triangl(circle* a, triangle* b);
#endif 