#include "H:\training\ExplicitDll\ExplicitDll\Math.h"
#include<Windows.h>
#include<iostream>
using namespace std;

void main()
{

	int (*fp)(int,int);
	HMODULE hdl;
	hdl = LoadLibrary(L"H:\\training\\ExplicitDll\\Debug\\ExplicitDll.dll");
	if(hdl)
	{
		cout<<"library is loaded"<<endl;
		fp = (int(*)(int,int))GetProcAddress(hdl,"add");
		if(fp)
		{
			cout<<"function address is obtained"<<endl;
			int res = fp(20,10);
			cout<<"res="<<res<<endl;
		}
		FreeLibrary(hdl);
	}
	else
		cout<<"library was not loaded"<<endl;

}