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

float AreaPoligono(Poligono poligono) {
    float area = 0.0;

    for (int i = 1; i < poligono.numVertices - 1; i++) {
        area += AreaTriangulo(poligono.vertices[0], poligono.vertices[i], poligono.vertices[i + 1]);
    }

    return area;
}
int main() {
    FILE *arquivo;
    int numVertices;
    Ponto *vertices;
    Poligono poligono;

    arquivo = fopen("vertices.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);

    vertices = (Ponto*)malloc(numVertices * sizeof(Ponto));

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(arquivo);

    poligono.numVertices = numVertices;
    poligono.vertices = vertices;

    printf("A area do poligono e: %.2f\n", AreaPoligono(poligono));

    free(vertices);

    return 0;
}