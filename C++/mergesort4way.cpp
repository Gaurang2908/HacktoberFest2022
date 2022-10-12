
#include<iostream>

using namespace std;


void merge(int array[],int const start,int const quarter1,int const quarter2,int const quarter3, int const end)
{
    auto const  subArrayOne=quarter1-start+1;
    auto const  subArrayTwo=quarter2-quarter1;
    auto const  subArrayThree=quarter3-quarter2;
    auto const  subArrayFour=end-quarter3;

    auto *arrayOne= new int[subArrayOne],
    *arrayTwo= new int[subArrayTwo],
    *arrayThree= new int[subArrayThree],   
    *arrayFour= new int[subArrayFour];
    
    for (auto  i=0;i<subArrayOne;i++)
    {
        arrayOne[i]=array[start+i];
    }
    for (auto  i=0;i<subArrayTwo;i++)
    {
        arrayTwo[i]=array[quarter1+i + 1];
    }
    for (auto  i=0;i<subArrayThree;i++) 
    {
        arrayThree[i]=array[quarter2+i+1];
    }
    for (auto  i=0;i<subArrayFour;i++)
    {
        arrayFour[i]=array[quarter3+i+1];
    }

    auto  indexOfSubArrayOne=0,
     indexOfSubArrayTwo=0,
     indexOfSubArrayThree=0,
     indexOfSubArrayFour=0;

    int indexOfMergedArray=start;
    int smallest;
    while(indexOfSubArrayOne<subArrayOne || indexOfSubArrayTwo<subArrayTwo || indexOfSubArrayThree<subArrayThree || indexOfSubArrayFour<subArrayFour)
    {

        smallest = min(min(indexOfSubArrayOne < subArrayOne?arrayOne[indexOfSubArrayOne]:__INT32_MAX__, indexOfSubArrayTwo < subArrayTwo?arrayTwo[indexOfSubArrayTwo]:__INT32_MAX__), min(indexOfSubArrayThree < subArrayThree?arrayThree[indexOfSubArrayThree]:__INT32_MAX__, indexOfSubArrayFour < subArrayFour?arrayFour[indexOfSubArrayFour]:__INT32_MAX__));

        if (indexOfSubArrayOne < subArrayOne && arrayOne[indexOfSubArrayOne] == smallest)
        {
            array[indexOfMergedArray++]=arrayOne[indexOfSubArrayOne++];
        }

        else if(indexOfSubArrayTwo < subArrayTwo && arrayTwo[indexOfSubArrayTwo] == smallest)
        {
            array[indexOfMergedArray++]=arrayTwo[indexOfSubArrayTwo++];
        }

        else if(indexOfSubArrayThree < subArrayThree && arrayThree[indexOfSubArrayThree] == smallest)
        {
            array[indexOfMergedArray++]=arrayThree[indexOfSubArrayThree++];
        }

        else if(indexOfSubArrayFour < subArrayFour && arrayFour[indexOfSubArrayFour] == smallest)
        {
            array[indexOfMergedArray++]=arrayFour[indexOfSubArrayFour++];
        }
    }

    // for (int k=start;k<end+1;k++)
    // {

    // }

    // delete[] arrayOne;
    // delete[] arrayTwo;
    // delete[] arrayThree;
    // delete[] arrayFour;


}

void printArray(int A[],int size)
{
    for (auto i=0;i<size;i++)
    {
        cout<< A[i]<< " ";
    } 
}

void mergesort(int array[],int start,int end)
{
    if (start >= end )
        return;
    
    int quarter2=  (start + end)/2;
    int quarter1=  (start + quarter2 - 1)/2;
    int quarter3=  (quarter2 + end)/2;
    cout<<"value of quarter is "<<quarter1<<" \n";
    mergesort(array,start,quarter1);
    mergesort(array,quarter1+1,quarter2);
    mergesort(array,(quarter2)+1,quarter3);
    mergesort(array,(quarter3)+1,end);
    merge(array,start,quarter1,quarter2,quarter3, end);
    for (auto i=0;i<end-start+1;i++)
    {
        cout<< array[i]<< " ";
    } 
}

int main()
{
    int arr[]={11,1,12,4, 14, -5, 13, 0, -45};
    auto n =sizeof(arr)/sizeof(arr[0]);
    cout<<"Value of N is "<< n <<" \n";
    cout<<"Given input array is\n";
    printArray(arr,n);
    mergesort(arr,0,n-1);
    cout<<"\nThe sorted array is \n";
    printArray(arr,n);
    return 0;

}