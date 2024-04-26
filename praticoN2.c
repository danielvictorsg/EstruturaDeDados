#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

// Struct para representar um polígono
typedef struct {
    int numVertices;
    Ponto *vertices;
} Poligono;

float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * ((A.X * (B.Y - C.Y)) + (B.X * (C.Y - A.Y)) + (C.X * (A.Y - B.Y)));
}