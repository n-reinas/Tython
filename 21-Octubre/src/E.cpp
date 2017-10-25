#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> v;
	char* original[] ='A';
	char* newStr;

	while(original != ".")
	{
		while(cin >> original)
		{
			cout << original << endl;
			newStr = strtok(original, ",");
			v.push_back(original);
			
			for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i]<< endl;
			}
		}		

	}

	return 0;
}