// Vector in c++ 
// https://www.geeksforgeeks.org/vector-in-cpp-stl/

//Code to illustrate capacity function i vector

#include <iostream>
#include <vector>

using namespace std;

int main()
{

	vector<int> g1;
	for(int i=1;i<=5;i++)
	g1.push_back(i);

	cout <<"Size : " << g1.size();
	cout <<"\nCapacity : " <<g1.capacity();
	cout <<"\n Max_SIxe : "<<g1.max_size();

	//to resize vector to size 4
	g1.resize(4);
	cout <<"\nSize : " <<g1.size();
	if(g1.empty() ==false)
	cout <<"\nVector is not empty";
	else cout<<"\nVector is empty";

	//Shrink the vector
	g1.shrink_to_fit();
	cout <<"\nVecot elements are: ";
	for (auto i = g1.begin(); i!=g1.end() ; i++)
	cout <<*i<<" ";

	cout<<endl;
	return 0;
}

