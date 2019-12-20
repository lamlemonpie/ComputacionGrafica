//
//  point2d.h
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/9/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef point2d_h
#define point2d_h

#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif


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

void drawPoint(float x1, float y1){
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2f(x1,y1);
    glEnd();
}


void drawPoint2(Point2d point){
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2f(point.x,point.y);
    glEnd();
}



#endif /* point2d_h */
