#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int i,j,min, arr[6]={8,4,2,1,58,5};
	
	cout<<"Unsorted Array is:"<<endl;
		 for(i=0;i<6;i++)
    {
    	cout<<arr[i]<<" ";
	}
		
	for(i=1;i<6;i++)
	{
		min=arr[i];
		for(j=i-1;j>=0;j--)
		{
		
		    if(arr[j]<min)
		    {
			arr[j+1]=arr[j];
			arr[j]=min;
		    }
  	   }
    }
    
    cout<<"\nSorted array is :"<<endl;
    for(i=0;i<6;i++)
    {
    	cout<<arr[i]<<" ";
	}
}
