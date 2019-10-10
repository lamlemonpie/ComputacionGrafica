//
//  lineFunctions.h
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/9/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef lineFunctions_h
#define lineFunctions_h

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

void drawPoint(float x1, float y1){
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(x1,y1);
    glEnd();
}

//Punto medio
void drawline(Point2d p1, Point2d p2){
    
    float dx, dy, incE, incNE, d, x, y;
    
    //Si el primer punto es mayor al segundo
    if(p1.x > p2.x ){
        int tmp_x = p1.x, tmp_y = p1.y;
        p1.x = p2.x; p1.y = p2.y;
        p2.x = tmp_x; p2.y = tmp_y;
    }
    
    dx = p2.x - p1.x;
    dy = abs(p2.y - p1.y);
    d  = 2 * dy - dx; //Valor inicial de d
    incE = 2 * dy; //Incremento de E
    incNE = 2 * ( dy - dx ); //Incremento de NE
    
    x = p1.x;
    y = p1.y;
    
    drawPoint(x, y);
    
    while( x < p2.x ){
        if( d <= 0 ){
            //Escoge E
            d = d + incE;
            x = x + 1;
        }
        else{
            //Escoge NE
            d = d + incNE;
            x = x + 1;
            if( p1.y < p2.y ) y = y + 1; //y sube
            else              y = y - 1; //y baja
        }
        drawPoint(x, y);
    }
}

#endif /* lineFunctions_h */
