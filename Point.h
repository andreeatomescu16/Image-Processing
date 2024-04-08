//
// Created by Andreea on 22.03.2024.
//

#ifndef EXTRA2_POINT_H
#define EXTRA2_POINT_H


class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int given_x, int given_y);

    int getX() const;
    int getY() const;

    void setX(int new_x);
    void setY(int new_y);


};


#endif //EXTRA2_POINT_H
