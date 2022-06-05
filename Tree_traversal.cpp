#include<stdlib.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root = NULL;

void insert(int value){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node* parent = root;
	temp->data =value;
	temp->left = NULL;
	temp->right = NULL;
	
	if(root == NULL){
		root = temp;
	}
	else{
		struct node* current = root;
	
		while(current){
			parent = current;
			if( temp->data<=current->data){
				current = current->left;
			}
			else
			current = current->right;
		}
	if(temp->data <= parent->data)
	parent->left = temp;
	else
	parent->right = temp;
	}
	
}

void displayIn(struct node* temp){
	if(temp->left)
	displayIn(temp->left);
 	cout<<temp->data<<" "; 
	if(temp->right)
	displayIn(temp->right);
 
}

 void printPre(struct node* temp){
 	cout<<temp->data<<" "; 
 	if(temp->left)
 	printPre(temp->left);
 	if(temp->right)
 	printPre(temp->right);
 			 
 }
 
 void printPos(struct node* temp){
 	
 	if(temp->left)
 	printPre(temp->left);
 	if(temp->right)
 	printPre(temp->right);
 cout<<temp->data<<" "; 	
 		
	 
 }

	int main(){
				int opt,i;
		
				int arr[] = {40,30,50,25,35,15,28,45};
				int value;

				for(i=0; i<8; i++){
				value= arr[i];
				insert(value);
				}
			
				printf("\nInorder traversal of Binary tree:\n");
				displayIn(root);
			
				printf("\nPreorder traversal of Binary tree:\n");
				printPre(root);
		
				printf("\nPostorder traversal of Binary tree:\n");
				printPos(root);
			
			
				return 0;
	}

