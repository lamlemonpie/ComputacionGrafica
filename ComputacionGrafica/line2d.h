//
//  line2d.h
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/9/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef line2d_h
#define line2d_h

#include "point2d.h"
#include "lineFunctions.h"

struct Line2d{
  
    Point2d *from;
    Point2d *to;
    
    Line2d(Point2d p1, Point2d p2){
        from = &p1;
        to   = &p2;
    }
    
    Line2d(int x1, int y1, int x2, int y2){
        from = new Point2d(x1,y1);
        to   = new Point2d(x2,y2);
    }
    
    void draw(){
        drawline(*from, *to);
    }
    
};

#endif /* line2d_h */
