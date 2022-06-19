#include<stdio.h>
#include<iostream>
#define N 7
using namespace std;

	int arr[N]={8,9,1,6,4,3,2};
	int b[N];

	void merge(int lb,int mid,int ub);

	void copy(int low,int high){
		int i;
		for(i=0;i<=high;i++)
		arr[i]=b[i];
	 }
	
	void mergeSort(int low , int high){
		int mid;
	
		if(low<high){
			mid= (low + high)/2;
			mergeSort(low ,mid);
			mergeSort(mid+1,high);
			merge(low ,mid,high);
			copy(low, high);
		}	
	}
	
	void merge(int low ,int mid, int high){
		int i=low ;
		int j=mid+1;
		int k=low;
		
		while(i<=mid &&  j<=high){
		
		if(arr[i]<=arr[j]){
			b[k++]=arr[i++];
		}
		else
		b[k++]=arr[j++];
		}
		
	
		while(i<=mid){
		
		b[k++]=arr[i++];
		}
		
		
		while(j<=high){
		
		b[k++]=arr[j++];
		}
	
	}
	
	
	
	int main(){
		int i;
		int lb=0;
	
		int high=N-1;
		cout<<"Unsorted Array"<<endl;
		for(i=0;i<N;i++)
		cout<<arr[i]<<" ";
		
		mergeSort(lb,high);
		cout<<"\nSorted Array:"<<endl;
		for(i=0;i<N;i++)
		printf("%d ",arr[i]);
		
	return 0;
		
	}
