#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	int data;
	int degree;
	Node *next;
}*lptr;

//Functions
void insert(lptr T,int data,int degree){
	while(T->next!=NULL){
		T = T->next;
	}
	
	lptr temp =new Node;
	temp->data = data;
	temp->degree = degree;
	temp->next = NULL;
	T->next = temp;
}

lptr add_poly(lptr T1,lptr T2){
	lptr T3 = new Node;
	T3->data = 0;
	T3->degree = 0;
	T3->next = NULL;
	
	while(T1!=NULL && T2!=NULL){
		
		if(T1->degree > T2->degree){
			insert(T3,T1->data,T1->degree);
			T1 = T1->next;
		}
		else if(T1->degree < T2->degree){
			insert(T3,T2->data,T2->degree);
			T2 = T2->next;
		}	
		else{
			insert(T3,T1->data + T2->data,T1->degree);
			T1 = T1->next;
			T2 = T2->next;
		}
	}
	
	while(T1!=NULL || T2!=NULL){
		
		if(T1!=NULL){
			insert(T3,T1->data,T1->degree);
			T1 = T1->next;
		}
		if(T2!=NULL){
			insert(T3,T2->data,T2->degree);
			T2 = T2->next;
		}
	}
	return T3;
}

void display(lptr T){
	while(T!=NULL){
		cout<<T->data<<" "<<T->degree<<" ";
		T = T->next;
	}
}

void disp_add(lptr T){
	T = T->next;
	while(T!=NULL){
		cout<<T->data<<" "<<T->degree<<" ";
		T = T->next;
	}
	
}

//MAIN FUNCTION
int main()
{
	lptr poly1,poly2;
	int val,pow;
	
	cout<<"Enter the data and degree of polynomial1 (-1 to stop): ";
	cin>>val>>pow;
	
	poly1 = new Node;
	poly1->data = val;
	poly1->degree = pow;
	poly1->next = NULL;

	while(val!=-1){
		cin>>val;
		if(val==-1)	break;
		cin>>pow;
		insert(poly1,val,pow);
	}
	
	display(poly1);
	
	cout<<"\nEnter the data and degree of polynomial2 (-1 to stop): ";
	cin>>val>>pow;
	
	poly2 = new Node;
	poly2->data = val;
	poly2->degree = pow;
	poly2->next = NULL;

	while(val!=-1){
		cin>>val;
		if(val==-1)	break;
		cin>>pow;
		insert(poly2,val,pow);
	}
		
	display(poly2);
	
	lptr poly3 = add_poly(poly1,poly2);
	
	cout<<"\nThe addition of these two polynomials is: ";
	disp_add(poly3);
	
	return 0;
}

