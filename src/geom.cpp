#include "geom.h"
#include <cmath>
#include <ctype.h>
#include <vector>
double lenght_of_segment(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double perimetrs(vector<int> a)
{
    double result;
	double ab, bc, ca;
	ab = lenght_of_segment(a[0], a[1], a[2], a[3]);
	bc = lenght_of_segment(a[2], a[3], a[4], a[5]);
	ca = lenght_of_segment(a[4], a[5], a[0], a[1]);
	result = ab + bc + ca;
	return result;
}

double areas(vector<int> a)
{
	double result;
    result = 0.5
            * (a[0] * (a[3] - a[5]) + a[2] * (a[5] - a[1])
               + a[4] * (a[1] - a[3]));
    return fabs(result);
}

char* _strlwr(char* str)
{
    unsigned char *p = (unsigned char*)str;
    while (*p) {
        *p = tolower((unsigned char)*p);
        p++;
    }
    return str;
} 