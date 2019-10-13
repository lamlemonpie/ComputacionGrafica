//
//  circle.h
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/12/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef circle_h
#define circle_h

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

#include "lineFunctions.h"

void circlePoints(int x, int y){
    drawPoint(x,y);
    drawPoint(x,-y);
    drawPoint(-x,y);
    drawPoint(-x,-y);
    drawPoint(y,x);
    drawPoint(y,-x);
    drawPoint(-y,x);
    drawPoint(-y,-x);
}

void midPointCircleInt(int r){
    //valores iniciales
    int x = 0;
    int y = r;
    
    int d = 1 - r;
    int deltaE = 3;
    int deltaSE = -2*r+5;
    
    circlePoints(x,y);
    while(y > x){
        //Seleccione E
        if (d < 0){
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        }
        //Seleccione SE
        else{
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        }
        x++;
        circlePoints(x,y);
    }
}

#endif /* circle_h */
