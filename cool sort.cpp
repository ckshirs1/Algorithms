#include<iostream>
using namespace std;

void coolSort(int *arr, int n, int *h, int l){
	int i, key, j;
	for(int k=0; k<l; k++){
		for(int m=0; m<n; m++)
			for(i=m; i<n; i=i+h[k]){
				key = arr[i];
				j = i-h[k];
				while(j>=0 && arr[j]>key){
					arr[j+h[k]] = arr[j];
					j=j-h[k];
				}
				arr[j+h[k]] = key;
			}
	}	
}

int main(){
	int n, l;
	
	cout<<"\nEnter the number of array elements:";
	cin>>n;
	
	int *arr = new int[n];

	cout<<"\nEnter the array elements:";
	for(int i=0; i<n; i++)	
		cin>>arr[i];

	cout<<"\nEnter the number of elements of H array(steps):";
	cin>>l;

	int *h = new int[l];

	cout<<"\nEnter the array elements of h:";
	for(int i=0; i<l; i++)	
		cin>>h[i];

	coolSort(arr, n, h, l);

    for (int i = 0; i < n; i++)  
        cout << arr[i] << " ";  

	return 0;
}