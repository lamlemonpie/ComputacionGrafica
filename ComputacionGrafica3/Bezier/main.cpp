//
//  main.cpp
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/9/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

#include "point2d.h"
#include "bezier.h"


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

using namespace std;

void display();
void reshape(int, int);


vector<Point2d> points;

void init(){
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void mouseEvent(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        y = abs(y-500);
        printf("CLICK! (%d,%d) \n",x,y);
        Point2d clicked (x,y);
        points.push_back(clicked);
    }

    glutPostRedisplay();
}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    

    drawPoints(points);
    drawCurve(points, 300);
    
    glFlush();
}

void reshape(int w, int h){
    
    //viewport (zona de dibujo)
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    
    //projection
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity(); //Resetea los parametros de la matriz de proyección
    
    gluOrtho2D(0, 500, 0, 500); //Espacio de dibujo
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB); //GLUT_RGB : colores. rojo, verde y azul.
    
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    
    glutCreateWindow("Bezier (Click izquierdo para dibujar punto)");
    
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMouseFunc(mouseEvent);
    
    
    glutMainLoop();
    
}
