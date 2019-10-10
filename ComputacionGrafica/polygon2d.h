//
//  polygon2d.h
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/10/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef polygon2d_h
#define polygon2d_h

#include "line2d.h"
#include "lineFunctions.h"

using namespace std;

struct Polygon2d{
    
    vector<Point2d> points;
    
    Polygon2d(vector<Point2d> points){
        this->points = points;
    }
    
    void draw(){
        size_t size = points.size();
        for(int i = 0; i< size; i++)
        {
            Line2d line( points[i%size], points[(i+1)%size] );
            line.draw();
        }
    }
    
};


#endif /* polygon2d_h */
