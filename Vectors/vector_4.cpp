// Vector in c++ 
// https://www.geeksforgeeks.org/vector-in-cpp-stl/

//code to illustrate modifiers in vector

#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v;

	//vector<int> v{10,20,30};    // used to initialize a vector like array
	
	//fill array with 10 5times
	v.assign(5,10);
	cout<<"The vector elements are :";
	for (int i= 0 ; i< v.size() ; i++)
	cout << v[i] << " ";
	

	//inserts 15 to last position
	v.push_back(15);
	int n = v.size();
	cout<<"\nThe vector elements are :";
	for (int i= 0 ; i< v.size() ; i++)
	cout << v[i] << " ";

	cout <<"\nThe last element is : "<< v[n-1];

	v.pop_back();
	cout<<"\nThe vector elements are :";
	for (int i= 0 ; i< v.size() ; i++)
	cout << v[i] << " ";

	v.insert(v.begin(),5);  // insert 5 at beginning
	cout <<"\nThe first element is : " << v[0];

	v.erase(v.begin());
	cout <<"\nThe first element is : " << v[0];

	v.emplace_back(20);  //insert 20 at end 
	n = v.size();
	cout <<"\nTHe last element is : " << v[n-1];

	 v.clear();    //erases the vector
   	 cout << "\nVector size after erase(): " << v.size();
	
	 // two vector to perform swap
	    vector<int> v1, v2;
	    v1.push_back(1);
	    v1.push_back(2);
	    v2.push_back(3);
	    v2.push_back(4);
	  
	    cout << "\n\nVector 1: ";
	    for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	  
	    cout << "\nVector 2: ";
	    for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	  
	    // Swaps v1 and v2
	    v1.swap(v2);    
	  
	    cout << "\nAfter Swap \nVector 1: ";
	    for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	  
	    cout << "\nVector 2: ";
	    for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	    cout <<endl;

	return 0;

}

		
