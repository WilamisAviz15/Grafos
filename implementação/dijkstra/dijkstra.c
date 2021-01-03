#include<stdio.h>
#define INF 9999999 //infinito
#define MAX 20
 
void dijkstra(int graph[MAX][MAX], int n, int initial_node)
{
 
	int g_aux[MAX][MAX], d[MAX], ant[MAX], visited[MAX], c, d_min, aux, i, j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(graph[i][j] == 0)
			{
				g_aux[i][j] = INF;
			}
			else
			{
				g_aux[i][j] = graph[i][j];
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		d[i] = g_aux[initial_node][i];
		ant[i] = initial_node;
		visited[i] = 0;
	}
	
	d[initial_node] = 0;
	visited[initial_node] = 1;
	c = 1;
	
	while(c < n - 1)
	{
		d_min = INF;

		for(i = 0; i < n; i++)
			if(d[i]<d_min&&!visited[i])
			{
				d_min = d[i];
				aux = i;
			}
		
			visited[aux] = 1;
			for(i = 0; i < n; i++)
			{
				if(!visited[i])
				{
					if(d_min + g_aux[aux][i] < d[i])
					{
						d[i] = d_min + g_aux[aux][i];
						ant[i] = aux;
					}
				}
			}
		c++;
	}
 
	for(i = 0; i < n; i++)
		if(i != initial_node)
		{
			printf("\nDistancia do no %d = %d",i,d[i]);
			printf("\nCaminho = %d", i);
			
			j = i;
			do
			{
				j = ant[j];
				printf(" <- %d", j);
			}while(j != initial_node);
	}
}
 
int main()
{
	int graph[MAX][MAX],i , j, n, initial;
	printf("Informe o numero de Vertices:");
	scanf("%d", &n);
	printf("\nDigite a matriz de adjacencia:\n");
	
	for(i = 0; i < n;i++)
	{
		for(j = 0; j < n;j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	printf("\nDigite o no inicial:");
	scanf("%d", &initial);
	dijkstra(graph, n, initial);
	return 0;
}
