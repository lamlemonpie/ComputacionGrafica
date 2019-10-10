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
#include "line2d.h"
#include "polygon2d.h"
#include "transformation.h"


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

void init(){
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
}




void drawPolygon( vector<Point2d> points ){
    
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    Point2d p1(100,300);
    Point2d p2(200,400);
    Point2d p3(300,300);
    
//    drawline(p1,p2);
    
//    Line2d line1(p1,p2);
//    line1.draw();
    
    vector<Point2d> points = {p1,p2,p3};
    Polygon2d poli1(points);
    poli1.draw();
    
//    Point2d p4(150,50);
//    translation(poli1, p4);
//    poli1.draw();
    
//    Point2d p5(0.5,0.5);
//    scaling(poli1,p5);
//    poli1.draw();
    
//    rotation(poli1, 20);
//    poli1.draw();
    
    reflectionX(poli1);
    poli1.draw();
    
    glFlush();
}

void reshape(int w, int h){
    
    //viewport (zona de dibujo)
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    
    //projection
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity(); //Resetea los parametros de la matriz de proyección
    
    gluOrtho2D(-500, 500, -500, 500); //Espacio de dibujo
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB); //GLUT_RGB : colores. rojo, verde y azul.
    
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    
    glutCreateWindow("Prueba");
    
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
}
