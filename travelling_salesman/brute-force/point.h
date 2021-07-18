
#ifndef POINT_H
#define POINT_H

class Point {
 private:
    double x_coord;
    double y_coord;
    double z_coord;

 public:
    Point();
    Point(double, double, double);
    ~Point() {;}

    int getX_coord() const {return x_coord;}
    int getY_coord() const {return y_coord;}
    int getZ_coord() const {return z_coord;}

    void printData();
    double calcDist(const Point &p) const;
};

#endif
