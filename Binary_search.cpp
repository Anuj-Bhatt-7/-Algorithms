#include <iostream>

using namespace std;
int arr[6] = {5,8,9,17,26,89};

void binary_search(int lower_bound,int upper_bound ,int data){
	
	int mid = (lower_bound + upper_bound)/2;
	
	if(lower_bound > upper_bound || upper_bound < lower_bound){
		cout<<"Not present";
		exit(0);
	}
	
	if(arr[mid]==data)
	 cout<<"Data present at "<<mid+1<<" location"<<endl;
	else if(arr[mid]>data)
	{
		upper_bound=mid-1;
		binary_search(lower_bound,upper_bound,data);
	}
	else 
	{
	lower_bound=mid+1;

	binary_search(lower_bound,upper_bound,data);
	}
	
	
    
}

int main(){
	int lower_bound=0 ,upper_bound=0;
	int i,data=0;
	int len;
	len =  sizeof(arr)/sizeof(arr[0]);
	upper_bound=len-1;
	cout<<"Printing Data"<<endl;
	for(i=0;i<len;i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;
	cout<<"Enter Data value to search: ";
	cin>>data;
	
	binary_search(lower_bound,upper_bound,data);
	return 0;
	
}


