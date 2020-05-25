#ifndef READFILL_H
#define READFILL_H
#include <string>
#include <vector>

struct circle;
struct triangle;
struct figures;
void fill_struct(
          std::vector<std::string>& a, char figure[], std::vector<figures>& res);
void print_triangle(triangle* tr);
void print_circle(circle* c);
void print(std::vector<figures> result);
void inf_input();
#endif