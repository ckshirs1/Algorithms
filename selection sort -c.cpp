#include<iostream>
using namespace std;

void swap(int *arr, int min_element_index, int i){
	int temp;
	temp = arr[min_element_index];
	arr[min_element_index] = arr[i];
	arr[i] = temp;	
}

void selectionSort(int *arr, int n){
	int min_element, min_element_index;
	for(int i=0; i<n; i++){
		min_element = arr[i], min_element_index = i;
		for(int j=i; j<n; j++){
			if(min_element>arr[j]){
				min_element=arr[j];
				min_element_index=j;			
			}
		}
		// Now min element must be containing the smallest element in the list from given j
		swap(arr, min_element_index, i);
	}
}

int main(){
	int n, k;
	
	cout<<"\nEnter the number of array elements:";
	cin>>n;
	
	int *arr = new int[n];

	cout<<"\nEnter the array elements:";
	for(int i=0; i<n; i++)	
		cin>>arr[i];
	
	selectionSort(arr, n);

	if(n%2 == 0){// n is even 
		int middle_index = n/2;
		float median = (arr[middle_index-1]+ arr[middle_index])/2.0;
		cout<<"\nThe median of the array is even:"<<median<<" ";
	}	
	else{
		int middle_index = n/2;
		cout<<"\nThe median of the array is:"<<arr[middle_index]<<" ";
	}
	return 0;
}
