#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 2147483647

struct Edge
{
    int O;
    int D;
    int P;
};
 
struct Graph
{
    int V;
    int E;
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* gp = (struct Graph*) malloc( sizeof(struct Graph));
    gp->V = V;
    gp->E = E;
    gp->edge = (struct Edge*) malloc( gp->E * sizeof( struct Edge ) );
    return gp;
}
 
void bellman_ford(int O, struct Graph* graph)
{
    int i = 0, j, V = graph->V, E = graph->E, aux[V];
    
    while (i < V)
    {
        aux[i] = MAX;
        i++;
    }
 
    aux[O] = 0;
 
    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int x = graph->edge[j].O, y = graph->edge[j].D, z = graph->edge[j].P;
            if (aux[x] + z < aux[y])
            {
                aux[y] = aux[x] + z;
            }
        }
    }
    i = 0;
    while (i < E)
    {
        int x = graph->edge[i].O, y = graph->edge[i].D, z = graph->edge[i].P;
        if (aux[x] + z < aux[y])
        {
            printf("Este grafo possui ciclo de aresta negativa\n");
        }
        i++;
    }

    printf("\nVertice \tDistancia do vertice de Origem\n");
    i = 0;
    while (i < V)
    {
        printf("%d \t\t %d\n", i, aux[i]);
        i++;
    }
}
 
int main()
{
    int Vertices, Edges, Inicial, i;
    printf("Insira o numero de vertices: \n");
    scanf("%d", &Vertices);
 
    printf("Insira o numero de arestas: \n");
    scanf("%d", &Edges);
    
    struct Graph* graph = createGraph(Vertices, Edges);

    printf("Insira o numero do vertice de origem: \n");
    scanf("%d", &Inicial);

    for(i = 0; i < Edges; i++)
    {
        printf("***Propriedades da aresta %d ***\n", i+1);
        printf("Informe a Origem: \n");
        scanf("%d",&graph->edge[i].O);
        printf("Informe o Destino: \n");
        scanf("%d",&graph->edge[i].D);
        printf("Informe o Peso: \n");
        scanf("%d",&graph->edge[i].P);
    }
 
    bellman_ford(Inicial, graph);
    return 0;
}
