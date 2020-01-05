#include <iostream> 
using namespace std; 
  
int binarySearch(int arr[], int l, int r) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == mid) 
            return mid; 
  
        if (arr[mid] > mid) 
            return binarySearch(arr, l, mid - 1); 
        
        // mid > arr[mid]
        return binarySearch(arr, mid + 1, r); 
    } 
  
    return -1; 
} 
  
int main(void) 
{ 
    int n;
    
    cout<<"\nEnter the number of array elements:";
    cin>>n;
    
    int *arr = new int[n];

    cout<<"\nEnter the array elements:";
    for(int i=0; i<n; i++)  
        cin>>arr[i];

    int result = binarySearch(arr, 0, n - 1); 
    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result; 
    return 0; 
} 