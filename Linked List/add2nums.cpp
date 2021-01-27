#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	int data;
	Node *next;
}*lptr;

//Functions
void insert(lptr T,int val){
	while(T->next!=NULL){
		T = T->next;
	}
	lptr temp = new Node;
	temp->data = val;
	temp->next = NULL;
	T->next = temp;
}

lptr add_list(lptr l1,lptr l2){
	lptr l3 = new Node;
	l3->data = 0;
	l3->next = NULL;
	int sum,carry=0,x,y;
	
	while(l1!=NULL || l2!=NULL){
		if(l1!=NULL){
		x = l1->data;
		}
		else{
			x = 0;
		}	
		if(l2!=NULL){
			y = l2->data;
		}
		else{
			y = 0;
		}
		
		sum = carry + x + y;
		insert(l3,sum%10);
		carry = sum/10;
		
		if(l1!=NULL)	l1 = l1->next;
		if(l2!=NULL)	l2 = l2->next;
	}
	if(carry>0) insert(l3,carry);
	
	return l3;
}

void display_rev(lptr T){
	lptr prevptr = NULL;
	lptr currptr = T;
	lptr nxtptr;
	
	while(currptr != NULL){
		nxtptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nxtptr;		
	}
	
	while(prevptr->next!=NULL){
		cout<<prevptr->data;
		prevptr = prevptr->next;
	}
}

//MAIN FUNCTION
int main(){
	int num1,num2;
	lptr head1 = new Node;
	lptr head2 = new Node;
	cout<<"Enter a number: ";
	cin>>num1;
	int dig = num1%10;
	head1->data = dig;
	head1->next = NULL;
	num1 = num1/10;
	while(num1>0){
		dig = num1%10;
		insert(head1,dig);
		num1 = num1/10;		
	}
	
	cout<<"\nEnter another number: ";
	cin>>num2;
	dig = num2%10;
	head2->data = dig;
	head2->next = NULL;
	num2 = num2/10;
	while(num2>0){
		dig = num2%10;
		insert(head2,dig);
		num2 = num2/10;		
	}
	
	lptr head3 = add_list(head1,head2);
	cout<<"\nThe sum is: ";
	display_rev(head3);
		
	return 0;
}

