#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
    int number_of_vert;
    int **element;
}matrix;

void init_matrix(matrix *graph, int number_of_vert);
void display_matrix(matrix graph);
void add_directed_edge_matrix(matrix graph, int from, int to);
void remove_directed_edge_matrix(matrix graph, int from, int to);
