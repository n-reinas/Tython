#include <iostream>
#include <math.h>
#include <cmath>


using namespace std;




bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

/*

bool isPrime(long numero){


    int acu=0;



    int div=2;


    while(div<numero&&numero%div!=0){
    	div++;

    }


    if(div==numero){
    	return true;
    }else{
    	return false;
    }




}
*/

bool primePower(long n){

	int m;

	int power=log2(n);

	for (int i = 1; i <= power+1; ++i){
		
		if(i==1){

			m=n;
		}
		else if(i==2){
			m=sqrt(n);

		}else{
			m=round(exp(log(n)/i));

		}

		if(n==pow(m,i)&&isPrime(m)){
			return true;
		}

	}

	return false;

}

void divisores(long n){


	for (int i = 1; i < n; ++i){
		if(n%i==0){
			cout<<i<<endl;
		}
	}
}


int main(){


	long numero;

	cin>>numero;

	if(primePower(numero)){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}


	return 0;
}