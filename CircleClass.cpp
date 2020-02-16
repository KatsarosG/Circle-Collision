#include "CircleClass.h"
#include <iostream>

Circle::Circle(int x1, int y1, int r1, int color1){
    x = x1;
    y = y1;
    radius = r1;
    color = color1;
}

void Circle::setX(int x1) {
    x = x1;
}
void Circle::setY(int y1) {
    y = y1;
}
void Circle::setRadius(int r1) {
    radius = r1;
}
void Circle::setColor(int color1) {
    color = color1;
}

int Circle::getX(void) {
    return x;
}
int Circle::getY(void) {
    return y;
}
int Circle::getRadius(void) {
    return radius;
}
int Circle::getColor(void) {
    return color;
}