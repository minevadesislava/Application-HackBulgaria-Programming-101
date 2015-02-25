#include<iostream>
#include<cmath>
#include <stdexcept>  
#include <sstream>  

using namespace std;



double fill_tetrahedron (int num) 
{  
	const float pi = 4*atan(1);
	if(num<0)
    {
		ostringstream oss;
		oss << "Invalid argument: " << num;
		throw invalid_argument(oss.str());
	}

	double b=(num*num* sin (pi/3) )/2;
	double h=(sqrt(2/3.))*num;
	double voluemeOfTetrahedron = (b*h)/3;
	double capaityOfTetrahedron = voluemeOfTetrahedron/1000;
  	return capaityOfTetrahedron;
}


int main()
{  
	int num;
	double result;
    try {
	cout<< "Enter the edge of the tetrahedron in centimeters: ";
	cin>>num;
	result= fill_tetrahedron(num);
	cout << "The amount of water that can be filled in the tetrahedron in liters is: " << result << endl;
	} catch (const invalid_argument& e) {
       cout << e.what() << endl;
	}
	system("pause");
	return 0;
}