#include<stdio.h>
#include<iostream>
# define N 7
using namespace std;

int partion(int arr[],int lb, int ub){
	int pivot= arr[lb];
	int temp;
	int i=lb+1;
	int j=ub;
	while(i<=j){
		
		while(arr[i]<=pivot && i<ub)
		i++;
		
		while(arr[j]>pivot)
		j--;
		if(i<j)
		{
		temp=arr[i];
		arr[i]= arr[j];
		arr[j]=temp;
		}
		i++;
	}
	
	if(i>j){
		arr[lb]=arr[j];
		arr[j]=pivot;
	}
	return j;
}

void quickSort(int arr[],int lb, int ub){
	int j;
	if(lb<ub){
		j=partion(arr,lb,ub);
		quickSort(arr,lb,j-1);
		quickSort(arr,j+1,ub);
	}
}



int main(){
	int i,lb=0;
	int ub=N-1;
	int arr[7]={9,8,7,16,2,5,3};
	cout<<"Unsorted Array:\n";
	for(i=0;i<N;i++)
	cout<<arr[i]<<" ";
	quickSort(arr,lb,ub);
	cout<<"\nSorted Array:"<<endl;
	for(i=0;i<N;i++)
	cout<<arr[i]<<" ";
	return 0;
	
}
