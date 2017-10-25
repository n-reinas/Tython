#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main(){


    char cadena;


    string par;

    int numAbc;

    int cont;


	while(cin>>cadena){

		//cin>>cadena;

		numAbc= (cadena-64);

		par="";

		cont=0;
        getline(cin,par);

		while(getline(cin,par)){

			if(par==""){
				break;
			}
			cont++;
		}

		cout<<numAbc-cont<<endl;

	}
}