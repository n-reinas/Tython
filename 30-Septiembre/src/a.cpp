#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
	const string notas[] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", 
	"SOL#", "LA", "LA#", "SI"};
	int s=0;
	string nota="";

	cin >> s >> nota;

	for(int i=0; i<12; i++){
		if(notas[i]==nota){
			if(s>i){
				cout << notas[12-s+i] << endl;
			}else{
				cout << notas[i-s] << endl;
			}
		}
	}

	return 0;
}