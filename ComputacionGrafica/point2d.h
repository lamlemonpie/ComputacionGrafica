//
//  point2d.h
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/9/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef point2d_h
#define point2d_h

struct Point2d
{
    float x,y;

    Point2d(float x, float y){
        this->x = x;
        this->y = y;
    }
    Point2d& operator=(const Point2d& other)
    {
        x=other.x;
        y=other.y;
        return *this;
    }
    
    Point2d& operator+(const Point2d& other)
    {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }
    
    Point2d& operator-(const Point2d& other)
    {
        x = x - other.x;
        y = y - other.y;
        return *this;
    }
    
    Point2d& operator*(const Point2d& other)
    {
        x = x * other.x;
        y = y * other.y;
        return *this;
    }
    
    void rotate(float angle){
        x = ( x * cos(angle) ) - ( y * sin(angle) );
        y = ( x * sin(angle) ) + ( y * cos(angle) );
    }
    
};


#endif /* point2d_h */
