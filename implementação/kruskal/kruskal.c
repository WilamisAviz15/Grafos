#include<stdio.h>
#define MAX 20
 
typedef struct edge
{
    int u, v, w;
} edge;
 
typedef struct edgelist
{
    edge dados[MAX];
    int n;
} edgelist;
 
edgelist list;
edgelist listAux;
 
void print()
{
    int i, c = 0;
    for(i = 0; i < listAux.n; i++)
    {
        printf("\n%d\t%d\t%d",listAux.dados[i].u, listAux.dados[i].v, listAux.dados[i].w);
        c = c + listAux.dados[i].w;
    }
    printf("\n\nCusto da arvore geradora = %d",c);
}

void kruskal(int graph[MAX][MAX], int n)
{
    int b[MAX], i, j, cnj1, cnj2;
    list.n = 0;
 
    for(i = 1; i < n; i++){
        for(j = 0; j < i; j++)
        {
            if(graph[i][j] != 0)
            {
                list.dados[list.n].u = i;
                list.dados[list.n].v = j;
                list.dados[list.n].w = graph[i][j];
                list.n++;
            }
        }
    }
    sort(n);
    for(i = 0; i < n; i++)
    {
        b[i] = i;
    }
    
    listAux.n = 0;
    
    for(i = 0; i < list.n; i++)
    {
        cnj1 = find(b, list.dados[i].u);
        cnj2 = find(b, list.dados[i].v);
        
        if(cnj1 != cnj2)
        {
            listAux.dados[listAux.n] = list.dados[i];
            listAux.n = listAux.n+1;
            union_f(b, cnj1, cnj2, n);
        }
    }
    print();
}
 
int find(int b[],int v)
{
    return(b[v]);
}

void sort(int n)
{
    int i, j;
    edge t;
    
    for(i = 1 ; i < list.n; i++)
    {
        for(j = 0; j < list.n-1; j++)
        {
            if(list.dados[j].w > list.dados[j+1].w)
            {
                t = list.dados[j];
                list.dados[j] = list.dados[j+1];
                list.dados[j+1] = t;
            }
        }
    }
}

void union_f(int b[],int c1,int c2, int n)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        if(b[i] == c2)
        {
            b[i] = c1;
        }
    }
}
 
void main()
{
    int i, j, graph[MAX][MAX], n;
    
    printf("\nInsira o numero de vertices:");
    scanf("%d", &n);
    printf("\nInsira a matriz de adjacencia:\n");
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }      
    kruskal(graph, n);
}
