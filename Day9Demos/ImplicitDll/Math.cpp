#include "Math.h"
#include<iostream>
using namespace std;

__declspec(dllexport)
int add(int a, int b)
{
	return (a+b);
}

__declspec(dllexport)
double add(double a, double b)
{
	return (a+b);
}


void Student::disp()
{
	cout<<"Student details are displayed"<<endl;
}
