#include <iostream>
#include <cstdio>

/*
verifica si un vertice v se puede pintar de un color c
V: #de vertices
v: vertice actual
grafo: la matriz de incidencia del grafo
color: vector solucion
c: color actual
*/
bool isSafe(int v, bool **grafo, int color[], int c, int V)
{
	//checkeo si los nodos las que esta conectado v ya tienen el color con el que
	//lo quiero pintar
	for(int i = 0; i < V; i++)
		if(grafo[v][i] && c == color[i])
				return false;
	return true;
}

/*
hace el backtracking para hallar la primera solucion de el problema m-coloring por medio de un depth first
tree
grafo: la matriz de incidencia
m: numero de colores
color: vector solucion
v: vertice actual
V: # de vertices del grafo
*/
bool graphColoringUtil(bool **grafo, int m, int color[], int v, int V)
{
	//si todos los vertices ya tienen color -> devuelva
	if(v == V)
		return true;
	
	//considere un el vertice actual v y pruebe colores diferentes
	for(int c = 1; c <= m; c++)
	{
		//verificamos que se le pueda asignar el color c al vertce v
		if(isSafe(v, grafo, color, c, V))
		{
			//pinto el vertice
			color[v] = c;

			//asigno los colores a los nodos siguientes
			if(graphColoringUtil(grafo, m, color, v+1, V))
				return true;
			
			//si el color no se puede entonces quitelo
			color[v] = 0;
		}
	}
	//si no se le pudo asig
	return false;
}
/*
inicializa color y llama al metodo recursivo
grafo: matriz de incidenicia del grafo
m: # de colores
V: # de vertices del grafo
*/
bool graphColoring(bool **grafo, int m, int V)
{
	int *color = new int[V];
	//lleno de 0s color
	for(int i = 0; i < V; i++)
		color[i] = 0;
	
	//llamo el recursivo
	if(!graphColoringUtil(grafo, m, color, 0, V))
	{
		std::cout << "no" << std::endl;
		return false;
	}

	//imprimo
	for(int i = 0; i < V; i++)
	{
		std::cout << color[i]  << " ";
	}
	std::cout << std::endl;
}
/*
hallar una forma de pintar el grafo
Input:
V: #vertices del grafo
t: #test cases
m: #de colores
grafo: la metriz de incidencia del grafo
Output:
la primera solucion que encuentre
*/
int main()
{
	bool pepe[4][4] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
	
	//numero de ciclos y de colores
	int t, m;
	//numero de nodos
	int V;

	//creo la matriz
	bool **grafo;

	//scaneo a t
	std::scanf("%d", &t);
	while (t--)
	{
		std::scanf("%d %d", &V, &m);
			grafo = new bool *[V];
		for(int i = 0; i < V; i++)
			grafo[i] = new bool[V];

		//scaneo la matriz
		for(int i = 0; i < V; i++)
		{
			for(int j = 0; j < V; j++)
			{
				std::cin >> grafo[i][j];
			}	
		}

		//llamo al metodo de mColoring
		graphColoring(grafo, m, V);
	}
}
