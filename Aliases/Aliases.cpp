// Can be considered same as pointers. 2 variables using same memory addresses.

#include <iostream>
using namespace std;

int &Func(void)
{
	static int a = 0;
	cout << "a == " << a << endl;
	return a;
}

int main()
{
	int x = 3,&y=x , z; //y is alias of x
	
	cout << "x = " << x  << " y = " << y <<endl;
	y=7;
	cout <<"x = " << x << endl << "&y = " << &y <<endl <<"&x = " << &x<<endl;
	
	z=y;
	cout << "z = " <<z<<endl;
	cout << "\nA function returning reference: \n\n" ;

	Func();
	Func() =5;
	
	Func() += 5;
	Func();

	cout << "\n\nPress Enter to exit.\n";
	cin.get();

return 0;
}
