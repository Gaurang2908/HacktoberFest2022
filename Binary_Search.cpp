void Binary(arr, size) {
beg = 0;  
end = size - 1;  
while ( beg <= end)  
{   
mid = (beg + end) / 2;  
if(arr[mid] == num)  
{  
return mid + 1;  
}  
else if (arr[mid] > num)  
{  
    end = mid - 1;  
}  
else if(arr [mid] < num)  
{  
    beg = mid + 1;  
}  
}  
// If the element does not exist in the array, return -1.  
Return -1;  
}
