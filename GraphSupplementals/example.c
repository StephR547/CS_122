#include "graphs_matrix.h"
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
 for(i = 1; i <= n; i++)
 if(a[v][i] && !visited[i])
 q[++r] = i;
 if(f <= r) {
 visited[q[f]] = 1;
 bfs(q[f++]);
 }
}
int main(){
  struct matrix graph;
  init_matrix(&graph, 4);
  add_directed_edge_matrix(graph, 0, 1);
  add_directed_edge_matrix(graph, 0, 3);
  add_directed_edge_matrix(graph, 1, 2);
  display_matrix(graph);
 
 for(i=1; i <= graph.number_of_vert; i++) {
 if(visited[i]){
 printf("VISITED:%d\t", i);
 }
 }

}