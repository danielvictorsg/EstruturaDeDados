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
    float determinante = (A.X * B.Y + B.X * C.Y + C.X * A.Y) - (A.Y * B.X + B.Y * C.X + C.Y * A.X);
    return fabs(determinante) / 2.0;
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

    arquivo = fopen("poligono.txt", "r");
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