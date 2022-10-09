                     //SELECTION SORT

#include <iostream>
using namespace std;

int main() {
	int arr[6]={9,64,34,5,11,17},min_element= -1;
	for(int i=0;i<6-1;i++)
	{ min_element=i;
	for(int j=i+1;j<6;j++)
	{
	    if(arr[min_element]>arr[j])
	    {
	        swap(arr[min_element],arr[j]);
	    }
	}
	    
	}
	for(int i=0;i<6;i++)
	{
	    cout<<arr[i]<<" ";
	}
	return 0;
}
