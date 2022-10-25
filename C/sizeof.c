	// sizeof() tells the size of data type,variable or constant in bits
	
	#include<stdio.h>
	
	int main()
	{
	int x,y,z;
	x=sizeof(int);
	y=sizeof(float);    // real constant = double data type
	z=sizeof(char);    // ASCII a = 97 each character has a value from 0 to 255 
	printf("%d %d %d",x,y,z);
	return 0;
	}
