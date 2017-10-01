#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n=0;
	scanf("%d", &n);
	int vect[n];
	int cont=0;
	int aux=0;
	int j=0, k=0;
	//printf("%s\n", creciendo);

	while(k<n){
		cin>>aux;
		if(j==0||vect[j-1]!=aux){
			vect[j]=aux;
			j++;
		}
		k++;
	}
	for(int i=j;i<n;i++){
		vect[i]=0;
	}

	for (int i = 0; i < n; ++i)
	{
		if (((i==0&&vect[i]>0)||(i>0&&vect[i]>vect[i-1]))&&((i==n-1&&vect[i]>0)||(i<n-1&&vect[i]>vect[i+1])))
		{
			cont++;
		}
		
	}

	printf("%d\n", cont);
	return 0;
}
