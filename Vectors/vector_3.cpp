// Vector in c++ 
// https://www.geeksforgeeks.org/vector-in-cpp-stl/

//code to illustrate element accesser in vector

//The <bits/stdc++.h> is a header file. This file includes all standard library. Sometimes in some coding contests, when we have to save time while solving, then using this header file is helpful.Using this, it may require unnecessary longer time to compile.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>g1;
	
	for(int i =1;i<=10;i++)
	g1.push_back(i*10);
	
	cout<<"\nReference operator [g] : g1[2] = " <<g1[2];
	cout<<"\nat : g1.at(4) = " <<g1.at(4);
	cout<<"\nfront() : g1.front() = "<<g1.front();
	cout<<"\nback() : g1.back() = "<<g1.back();

	//pointer to first element 
	int* pos = g1.data();
	cout <<"\nThe first element is "<<*pos;
	cout<<endl;
	
	return 0;
}

