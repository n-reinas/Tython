#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

struct Node
{
	int nivel;
	int ganancia;
	int peso;
};

//se va hasta que el peso aguante en el fondo de un arbol para determinar la utilidad
float bound(Node u, int pesoMax, int n, const int peso[], const int val[])
{
	if(u.peso >= pesoMax)
		return 0;
	
	int j;
	int pesoTotal;
	float resultado;

	resultado = u.ganancia;
	j = u.nivel + 1;
	pesoTotal = u.peso;

	while(j <= n && pesoTotal + peso[j] <= pesoMax)
	{
		pesoTotal += peso[j];
		resultado += val[j];
		j++;
	}
	
	if(j <= n)
		resultado += (pesoMax - pesoTotal) * val[j]/peso[j];
	
	return resultado;
}

//beardth first search con branch and bound pruning
int knapSack(int n, const int val[], const int peso[], int pesoMax)
{
	int gananciaMax;

	//la busqueda de breadth first
	std::queue<Node> Q;
	Node u, v;

	v.nivel = 0;
	v.ganancia = 0;
	v.peso = 0;

	gananciaMax = 0;

	Q.push(v);

	while(!Q.empty())
	{
		v = Q.front();
		Q.pop();

		u.nivel = v.nivel + 1;
		u.peso = v.peso + peso[u.nivel];
		u.ganancia = v.ganancia + val[u.nivel];
		
		if(u.peso <= pesoMax && u.ganancia > gananciaMax)
			gananciaMax = u.ganancia;
		
		if(bound(u, pesoMax, n, peso, val) > gananciaMax)
			Q.push(u);
		
		u.peso = v.peso;
		u.ganancia = v.ganancia;

		if(bound(u, pesoMax, n, peso, val) > gananciaMax)
			Q.push(u);
	}

	return gananciaMax;
}

/*params
 * t: numero de test cases
 * n: numero de objetos
 * pesoMax: peso Maximo que aguanta el saco
 * val: vector de valores de cada objeto
 * peso: vector de peso de cada objeto
 */
int main()
{
	int n, pesoMax, t;
	
	//saco el numero de casos
	std::scanf("%d", &t);

	while(t--)
	{
		//obtengi el numero de objetos y el peso maximo
		std::scanf("%d %d", &n, &pesoMax);
	
		//creo el vector de valores
		int *val = new int[n];
		for(int i = 0; i < n; i++)
			std::scanf("%d", &val[i]);
	
		//creo el vector de pesos
		int *peso = new int[n];
		for(int i = 0; i < n; i++)
			std::scanf("%d", &peso[i]);
		
		std::cout << knapSack(n, val, peso, pesoMax) << std::endl;
	}
}
