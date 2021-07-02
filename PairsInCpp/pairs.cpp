//https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/
//https://www.geeksforgeeks.org/sort-c-stl/
//vector of pairs

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<pair <int, int> > vect;
	int arr[] ={10,20,5,40};
	int arr1[]={30,60,20,50};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++)
		vec.push_back(make_pair([arr[i] , arr1[i]));
	
	cout << "The vector before sort operation is:\n" ;
	for(int i=0;i<n;i++)
		cout << vect[i].first << " "<<vect[i].second <<endl;
		//to access first and second element of pair 
	
	cout << " The vector after sort opration is:\n";
	sort(vect.begin() , vect.end () ) ;   // sorted acc to 1st value in pair
     // sort(vect.begin() , vect.end() , sortbysec); //sorted acc to 2nd value in pair
	for(int i=0;i<n;i++)
		cout << vect[i].first << " "<<vect[i].second <<endl;

	return 0;
}
 
