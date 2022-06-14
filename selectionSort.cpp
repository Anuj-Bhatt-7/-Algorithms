#include<iostream>
#include<stdio.h>

using namespace std;

int array[] = {11,22,53,6,8,3};


int main(){
	int i, j, min_index, temp;

	cout<<"Unsorted Array: "<<endl;
	for(i=0 ; i<6 ; i++){
		cout<<array[i]<<" ";
	}
	
	for(i=0 ; i<6 ; i++){	
		min_index = i;
		for(j=i+1; j<6 ; j++){		
			if(array[j] < array[min_index]){
				temp= array[j];
				array[j]= array[min_index];
				array[min_index] = temp;
			}
		}
	}
	
	cout<<"\nSorted array"<<endl;
	for(i=0; i<6 ;i++){
		cout<<array[i]<<" ";
	}
	

return 0;
}
