#include<stdio.h>

int n, wtsAndVals[10][2];

void backtrack(int w, int memTable[n+1][w+1]){
	int x[n];
	for(int i=0;i<n;i++) x[i]=0;

	for(int k=n; k>0; k--){
		if((k-1)!=-1 && (memTable[k][w] != memTable[k-1][w])){
			x[k-1] = 1;
			w = w - wtsAndVals[k-1][0];
		}
	}

	printf("\nItem no. Weight");
	for(int i=0;i<n;i++){
		if(x[i] == 1){
			printf("\n%d\t  %d", (i+1), wtsAndVals[i][0]);
		}
	}
	printf("\n");
}

void printMemTable(int n, int w, int memTable[n+1][w+1]){
	for(int i=0; i<(n+1); i++){
		printf("\n");
		for(int j=0; j<(w+1); j++){
			printf("%d ",memTable[i][j]);
		}
	}	
}

int max(int v1, int v2){
	printf("\nv1=%d and v2=%d",v1,v2);
	return v1 > v2 ? v1 : v2;
}

int knap(int i, int j){
	printf("\nFor i= %d and j=%d", i, j);
	
	if(j<0)
		return -99;
	
	if(i<=0)
		return 0;

	return max( (knap((i-1), (j-wtsAndVals[i-1][0]))+ wtsAndVals[i-1][1]), knap(i-1, j) );
}

// Fills the memoization table columnwise
void fillMemTable(int n, int w, int memTable[n+1][w+1]){
	for(int j=0; j<(w+1); j++){
		for(int i=0; i<(n+1); i++){
			memTable[i][j] = knap(i, j);
		}
	}
	knap(1,2);
	knap(1,3);
}

void initMemTable(int *memTable, int n, int w){
	for(int i=0; i<(n+1); i++)
		for(int j=0; j<(w+1); j++)
			*((memTable+(i*(n+1)))+j) = 0;
}

void printItems(int arr[][2], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void printWeightAndValues(){
	printf("\nWeights and Values are");
	for(int i=0; i<n; i++){
		printf("\n");
		for(int j=0; j<2; j++)
			printf("%d ", wtsAndVals[i][j]);
	}
}

void main(){
	int w;

	printf("\nEnter the number of items:");
	scanf("%d",&n);

	printf("\nEnter the item weight and its value:");
	for(int i=0; i<n; i++)
		for(int j=0; j<2; j++)
			scanf("%d",&wtsAndVals[i][j]);

	//printItems(arr, n);

	printWeightAndValues();
	printf("\nEnter the maximum weight that can be carried in the knapsack:");
	scanf("%d",&w);	

	int memTable[n+1][w+1];

	initMemTable((int *)memTable, n, w);

	fillMemTable(n, w, memTable);

	printMemTable(n, w, memTable);

	backtrack(w, memTable);
}
