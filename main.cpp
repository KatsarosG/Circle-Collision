#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include "CircleClass.h"
#include "CircleClass.cpp"

class MouseClass {
    public:
        int x;
        int y;
        int touchingCircle;
};
MouseClass mouse;

int height = 600;
int width = 700;
sf::RenderWindow window(sf::VideoMode(width, height), "Circle collision");

void drawCircle(int x1, int y1, float r1, int color) {
    sf::CircleShape circle(r1-2);
    circle.setPointCount(r1*2);
    circle.setPosition(x1-r1, y1-r1);
    circle.setFillColor(sf::Color((color%10)*100 ,(color%100)*10, color));
    circle.setOutlineThickness(2);

    window.draw(circle);
}

int main(){
    window.setFramerateLimit(60);
    std::vector<Circle> circles;

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        sf::Vector2i tempxy = sf::Mouse::getPosition(window);
        mouse.x = tempxy.x;    mouse.y = tempxy.y;
        mouse.touchingCircle = -1;
    
        if (mouse.x > 0 && mouse.x < width && mouse.y > 0 && mouse.y < height) {
            //create circles
            if (mouse.touchingCircle = -1) {
                for (int i = 0; i < circles.size(); i++) {
                    float dx0 = circles[i].getX() - mouse.x;
                    float dy0 = circles[i].getY() - mouse.y;
                    float d0 = sqrt(dx0*dx0 + dy0*dy0);
                    if (d0 < circles[i].getRadius()) {
                        mouse.touchingCircle = i;
                    }
                }
            }
            if (sf:: Mouse::isButtonPressed(sf::Mouse::Left) &&  mouse.touchingCircle == -1) {
                while (sf:: Mouse::isButtonPressed(sf::Mouse::Left)) {
                }
                Circle newCircle(mouse.x, mouse.y, (rand()%10)*8+25, rand());
                circles.push_back(newCircle);
            } else if (sf:: Mouse::isButtonPressed(sf::Mouse::Left) && mouse.touchingCircle != -1) {
                circles[mouse.touchingCircle].setX(mouse.x);
                circles[mouse.touchingCircle].setY(mouse.y);

            }
        }

        //find collisions
        for (int i = 0; i < circles.size(); i++) {
            for (int n = 0; n < circles.size(); n++) {
                if (i != n) {
                    float dx1 = circles[i].getX() - circles[n].getX();
                    float dy1 = circles[i].getY() - circles[n].getY();
                    float d1 = sqrt(dx1*dx1 + dy1*dy1);
                    float R = circles[i].getRadius() + circles[n].getRadius();
                    float moveDistanceX = 0;
                    float moveDistanceY = 0;

                    if (R >= d1) {  
                        //collision detected
                        float overlap = 0.5 * (R - d1);
                        //move circles
                        moveDistanceX = overlap * ((circles[i].getX() - circles[n].getX()) / d1);
                        moveDistanceY = overlap * ((circles[i].getY() - circles[n].getY()) / d1);
                        circles[i].setX(circles[i].getX() + moveDistanceX);
                        circles[i].setY(circles[i].getY() + moveDistanceY);
                    }   

                    
                }
            }
        }

        //draw circles
        for (int i = 0; i < circles.size(); i++) {
            drawCircle(circles[i].getX(), circles[i].getY(), circles[i].getRadius(), circles[i].getColor());
        }

        window.display();
    
    }
    
    
}