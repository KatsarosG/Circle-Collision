#include <iostream>
using namespace std;

#ifndef CIRCLECLASS_H
#define CIRCLECLASS_H

class Circle {
    public:
        void setX(int x1);
        void setY(int y1);
        void setRadius(int r1);
        void setColor(int color1);

        int getX(void);
        int getY(void);
        int getRadius(void);
        int getColor(void);

        Circle(int x1, int y1, int r1, int color1);

    private:
        int x;
        int y;
        int radius;
        int color;

};

#endif