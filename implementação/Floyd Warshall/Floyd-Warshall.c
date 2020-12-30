#include<stdio.h>
#define MAX 20

void floydWarshall(int graph[MAX][MAX], int n)
{
  int i, j, k;
  for (k = 0; k < n; k++){
    for (i = 0; i < n; i++){
      for (j = 0; j < n; j++){
        if (graph[i][k] + graph[k][j] < graph[i][j])
        {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
}

int main()
{
  int i, j, graph[MAX][MAX], n;
  printf("Insira o numero de vertices: ");
  scanf("%d",&n);
  printf("\n");
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      printf("graph[%d][%d]:", i, j);
      scanf("%d", &graph[i][j]);
    }
  }
  floydWarshall(graph, n);
  printf ("Distancias mais curtas entre cada par de vertices: \n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf ("%d\t", graph[i][j]);
    }
    printf("\n");
  }
  return 0;
}
