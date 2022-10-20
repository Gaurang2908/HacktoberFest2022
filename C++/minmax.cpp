#include <iostream>

using namespace std;

int main()

{

    int array[50], *max, *min, size, i; //pointer variables declared for max and min

    cout<<"Enter the number of elements in array\n";

    cin>>size;

    cout<<"Enter array elements\n";

    for ( i = 0 ; i < size ; i++ )

    cin>>array[i];

    max = array; //assigning pointer to the address of the first element

    min = array; 

    for (i = 0; i < size; i++)

    {

    //Finding the largest element in the array

    if (*(array+i) > *max)

        *max = *(array+i);

    }

    cout<<"Maximum element in the array is "<< *max << "\n" ;

    for (i = 0; i < size; i++)

    {

    //Finding the smallest element in the array

    if (*(array+i) < *min)

        *min = *(array+i);

    }

    cout<<"Minimum element in the array is"<< *min <<"\n";

    return 0;

}
