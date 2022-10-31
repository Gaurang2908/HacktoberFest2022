#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
	cout<<setw(8)<<"Hello"<<endl;
	cout<<setfill('~')<<setw(8)<<"Hello"<<endl;
	cout<<setw(8)<<"Hello"<<setfill('*')<<endl;
	cout<<"Hello"<<setw(8)<<setfill('*')<<endl;
	cout<<setw(8)<<"  Hello"<<endl;
	cout<<"Hello"<<endl;
	//setfill configuration retains throughout the program
	
	cout<<sqrt(6)<<endl;
	cout<<setprecision(8)<<4.5567<<endl;
	cout<<setprecision(8)<<sqrt(6)<<endl;
	cout<<sqrt(6)<<endl;
	//setfill configuration retains throughout the program
}
