//  Travelling Salesman Problem, Genetic algorithms (GAs)


#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point{
 private:
    double x_coord;
    double y_coord;
    double z_coord;

 public:
    Point();
    Point(double x, double y, double z) : x_coord(x), y_coord(y), z_coord(z) {}
    ~Point() {;}

    int getX_coord() const {return x_coord;}
    int getY_coord() const {return y_coord;}
    int getZ_coord() const {return z_coord;}

    //  3D Euclidean space: sqrt( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
    double calcDist(const Point& p2) const
    {
        return sqrt(pow(p2.getX_coord()-x_coord, 2)
                + pow(p2.getY_coord()-y_coord, 2)
                + pow(p2.getZ_coord()-z_coord, 2));
    }
};

#endif
