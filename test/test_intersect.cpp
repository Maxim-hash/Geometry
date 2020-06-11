#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "intesections.h"
#include "read-fill.h"
#include <iostream>
#include <string.h>
#include <vector>

TEST_CASE("intersections of triangles", "[triangles]")
{
    SECTION("counting the area of a triangle by three points")
    {
        REQUIRE(area_int(2, 3, 6, 7, 8, 10) == 4);
    }
    SECTION("checking the location of points")
    {
        REQUIRE(inters_segment(3, 4, 6, 7) == false);
        REQUIRE(inters_segment(5, 5, 5, 5) == true);
    }
    SECTION("checking the location of segments")
    {
        REQUIRE(inter_segments(1, 0, 2, 1, 1, 0, 2, 0) == true);
        REQUIRE(inter_segments(-1, 1, -1, 2, 1, 1, 2, 2) == false);
    }
    vector<int> a = {2, 2, -1, -2, 3, -2, 2, 2};
    vector<int> b = {3, 3, 1, -1, 5, -1, 3, 3};
    vector<int> c = {-2, 2, -3, 4, -4, 2, -2, 2};
    triangle* a_ = new triangle;
    triangle* b_ = new triangle;
    triangle* c_ = new triangle;
    a_->figure = "triangle";
    a_->xy = a;
    b_->figure = "triangle";
    b_->xy = b;
    c_->figure = "triangle";
    c_->xy = c;
    REQUIRE(intersections_triangles(a_, b_) == true);
    REQUIRE(intersections_triangles(a_, c_) == false);
}

TEST_CASE("intersections of circles", "[circles]")
{
    circle* a_ = new circle;
    circle* b_ = new circle;
    circle* c_ = new circle;
    a_->figure = b_->figure = c_->figure = "circle";
    a_->x = 0;
    a_->y = 0;
    a_->r = 3;
    b_->x = 1;
    b_->y = 1;
    b_->r = 2;
    c_->x = 10;
    c_->y = 10;
    c_->r = 3;
    REQUIRE(intersections_circles(a_, b_) == true);
    REQUIRE(intersections_circles(a_, c_) == false);
}

TEST_CASE("intersections of circle and triangle", "[circle and triangle]")
{
    vector<int> a = {2, 2, -1, -2, 3, -2, 2, 2};
    circle* c_ = new circle;
    circle* c1_ = new circle;
    triangle* t_ = new triangle;
    c_->x = 0;
    c_->y = 0;
    c_->r = 3;
    c1_->x = 6;
    c1_->y = 5;
    c1_->r = 2;
    t_->figure = "triangle";
    t_->xy = a;
    REQUIRE(inter_circle_triangl(c_, t_) == true);
    REQUIRE(inter_circle_triangl(c1_, t_) == false);

} 
