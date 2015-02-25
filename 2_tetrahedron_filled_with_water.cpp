#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


float fill_tetrahedron(int num)
{  
	const float pi = 4*atan(1);
    float b=(num*num*sin(pi/3))/2;
	float h=sqrt(2/3.)*num;
	float voluemeOfTetrahedron=(b*h)/3;
	float capaityOfTetrahedron=voluemeOfTetrahedron/1000;
	return capaityOfTetrahedron;
}

int tetrahedron_filled(vector <int> tetrahedrons,int water)
{    
	sort(tetrahedrons.begin(), tetrahedrons.end());
    int usedWater=water;
    int i=0;
	for(; i < tetrahedrons.size(); i++)
	{
		usedWater -= fill_tetrahedron(tetrahedrons[i]);
		if ( usedWater < 0 ) 
		{
			break;
		}
	}
    return i;
}

int main()
{ 
	int waterInLiters;
	cout << "Enter the amount of water that we have in liters: ";
	cin >> waterInLiters;
	int number;
	cout << "Enter the number of the tetrahedrons: ";
	cin >> number;
	vector<int> tetrahedrons;
	for(int i = 0; i < number; i++)
	{
		cout <<  "Enter the edge of the tetrahedron in centimeters: ";
		int edge;
		cin>>edge;
		tetrahedrons.push_back(edge);
	}
	cout << "The maximum number of tetrahedrons, which can be filled with " << waterInLiters << " liters of water is: " << tetrahedron_filled(tetrahedrons, waterInLiters) << endl;
	return 0;
}