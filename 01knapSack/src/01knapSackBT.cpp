#include <iostream>
#include <cstdio>

//metodo recursivo para hallar la mayor utilidad
int knapSack(int obj, int *val, int *peso, int pesoMax, int n,  int valAcum, int pesoAcum)
{


	//valido si ya no hay mas objetos o excedo el peso
	if(obj > n || pesoAcum + peso[obj]  > pesoMax)
		return valAcum;

	//std::cout << "obj " << obj << " valAcum " << valAcum << " pesoAcum " << pesoAcum << std::endl;

	//comparo y devuelvo la mayor de las permutaciones. son dos opciones si tomar un objeto o no tomarlo
	return std::max(knapSack(obj+1, val, peso, pesoMax, n, valAcum + val[obj], pesoAcum + peso[obj]),
				    knapSack(obj+1, val, peso, pesoMax, n, valAcum, pesoAcum));
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
		
		//imprimo el resultado
		std::cout << knapSack(0,val, peso, pesoMax, n, 0, 0) << std::endl;
	}
}

