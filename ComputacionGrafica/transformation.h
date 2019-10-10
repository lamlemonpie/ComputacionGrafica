//
//  transformation.h
//  ComputacionGrafica
//
//  Created by Alejandro Larraondo on 10/10/19.
//  Copyright © 2019 Alejandro Larraondo. All rights reserved.
//

#ifndef transformation_h
#define transformation_h

#include <cstdio>
#include "polygon2d.h"

//Traslation
void translation(Polygon2d &poly,Point2d trans){
    
    for (auto &i: poly.points){
        printf("Antes: x(%.3f) y(%.3f)\n",i.x,i.y);
        i = i + trans;
        printf("Despues: x(%.3f) y(%.3f)\n",i.x,i.y);
    }
}

//Scaling
void scaling(Polygon2d &poly,Point2d trans){
    
    for (auto &i: poly.points){
        printf("Antes: x(%.3f) y(%.3f)\n",i.x,i.y);
        i = i * trans;
        printf("Despues: x(%.3f) y(%.3f)\n",i.x,i.y);
    }
}
//Rotation
void rotation(Polygon2d &poly,float angle){
    //radianes a grados
    float degree = angle * (M_PI/180);
    for (auto &i: poly.points){
        printf("Antes: x(%.3f) y(%.3f)\n",i.x,i.y);
        i.rotate(degree);
        printf("Despues: x(%.3f) y(%.3f)\n",i.x,i.y);
    }
}

//Reflection
void reflectionX(Polygon2d &poly){
    for (auto &i: poly.points){
        printf("Antes: x(%.3f) y(%.3f)\n",i.x,i.y);
        i = i - i - i;
        printf("Despues: x(%.3f) y(%.3f)\n",i.x,i.y);
    }
}


#endif /* transformation_h */
