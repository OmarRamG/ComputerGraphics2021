#include "point.h"
#include <stdio.h>
//Impresion de los puntos
void printPoints(Point * points, int pointIndex){
    printf("Puntos obtenidos:\n");
    int i, j;
    for(i = 0; i < pointIndex; i++){
        printf("%d -> %f, %f\n", i+1, points[i].x, points[i].y);
    }
    return;
}