#include "stdafx.h"


#include <iostream>
using namespace std;


void _1z()
{
	int X, Y, Z;
	cout<<"enter 3 numbers";
	cin>>X>>Y>>Z;
	if (X%2!=0&&Y%2!=0)
	{cout<<"cond 1 true";}
	else
	{cout<<"cond 1 false"<<endl;}
	if (X<20&&Y<20)
	{cout<<"cond 2 true"<<endl;}
	else
	{cout<<"cond 2 false"<<endl;}
	if (X==0||Y==0)
	{cout<<"cond 3 true"<<endl;}
	else
	{cout<<"cond 3 false"<<endl;}
	if (X<0&&Y<0&&Z<0)
	{cout<<"cond 4 true"<<endl;}
	else
	{cout<<"cond 4 false"<<endl;}
	if (X%5==0&&Y%5==0&&Z%5==0)
	{cout<<"cond 5 true"<<endl;}
	else
	{cout<<"cond 5 false"<<endl;}
	if (X>100&&Y>100&&Z>100)
	{cout<<"cond 6 true"<<endl;}
	else
	{cout<<"cond 6 false"<<endl;}
}

void _2z()
{
	int a,b,c,d;
	cout<<"enter 1st chess piece positions";
	cin>>a>>b;
	cout<<"enter 2nd chess piece positions";
	cin>>c>>d;
	if(a==c||b==d)
		cout<<"rook danger"<<endl;
	else
		cout<<"rook safe"<<endl;
	if(abs(a-b)==abs(c-d))
		cout<<"bishop danger"<<endl;
	else
		cout<<"bishop safe"<<endl;
	if(abs(a-c)==1||abs(b-d)==1)
		cout<<"king danger"<<endl;
	else
		cout<<"king safe"<<endl;
	if((a==c||b==d)||abs(a-b)==abs(c-d))
		cout<<"queen danger"<<endl;
	else
		cout<<"queen safe"<<endl;
	if(a+1!=c&&b+1!=d)
		cout<<"pawn move"<<endl;
	if((a+1==c)||(a-1==c)&&(b+1==d))
		cout<<"pawn fight"<<endl;
}

void _3z()

{
	int n;
	cin>>n;
for (int i=1;i<10;i++)
	{
		cout<<i<<" x "<<n<<" = "<<n*i<<endl;
	}
}

void _4z()
{
	for (int i=8;i<15;i++)
		for(int j=9;j<15;j++)
			cout<<i*j<<endl;
}

void main()
{
	_1z();
			cout<<"______________________________________________________________"<<endl;
	_2z();
			cout<<"______________________________________________________________"<<endl;
	_3z();
			cout<<"______________________________________________________________"<<endl;
	_4z();
			cout<<"______________________________________________________________"<<endl;
	system ("pause");
}