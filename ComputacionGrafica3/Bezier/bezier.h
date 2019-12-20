//
//  bezier.h
//  ComputacionGrafica
//
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef bezier_h
#define bezier_h

#include <vector>
#include "point2d.h"

using namespace std;

void drawPoints(vector<Point2d> points){
    for(auto i: points){
        drawPoint2(i);
    }
}

// Algoritmo de Casteljau
void drawPoint(vector<Point2d> points, float t){
    if(points.size() == 1){
        drawPoint2(points[0]);
    }
    else{
        vector<Point2d> aux = points;
        aux.pop_back();
        for(int i=0; i<aux.size(); i++){
            float x = (1-t)*points[i].x + t*points[i+1].x;
            float y = (1-t)*points[i].y + t*points[i+1].y;
            aux[i]  = Point2d(x,y);
        }
        drawPoint(aux, t);
    }
}

void drawCurve(vector<Point2d> points, int steps){
    if(points.size() < 3) return;
    for(int i=0; i<steps; i++){
        float t = float(i)/(steps-1);
        drawPoint(points, t);
    }
}


#endif /* bezier_h */
