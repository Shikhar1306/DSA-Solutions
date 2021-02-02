#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node *next;
	
	node(){
		next = NULL;
	}
}*lptr;

//Functions
void insert(lptr &T,int d){
	if(T==NULL){
		T = new node;
		T->data = d;
		return;
	}
	insert(T->next,d);
}

void display(lptr T){
	while(T!=NULL){
		cout<<T->data<<" ";
		T = T->next;
	}
}

int last_value(lptr T){
	int lv = -1;
	while(T!=NULL){
		lv = T->data;
		T = T->next;
	}
	return lv;
}

lptr list_union(lptr T1,lptr T2)
{
	lptr U = NULL;
	while(T1!=NULL && T2!=NULL)
	{
		int a = last_value(U);
		if(T1->data > T2->data)
		{
			if(T2->data!=a)
				insert(U,T2->data);
			T2=T2->next;
		}
		else if(T1->data < T2->data)
		{
			if(T1->data!=a)
				insert(U,T1->data);
			T1=T1->next;
		}
		else{
			if(T1->data!=a)
				insert(U,T1->data);
			T1=T1->next;
			T2=T2->next;
		}
	}
	while(T1!=NULL)
	{
		int a = last_value(U);
		if(T1->data!=a)
			insert(U,T1->data);
		T1=T1->next;
	}
	while(T2!=NULL)
	{
		int lv = last_value(U);
		if(T2->data!=lv)
			insert(U,T2->data);
		T2=T2->next;
	}
	return U;
}

lptr list_intersection(lptr T1,lptr T2){
	lptr I= NULL;
	while(T1 && T2){
		int a = last_value(I);
		if(T1->data == T2->data){
			if(T1->data!=a)
				insert(I,T1->data);
			T1 = T1->next;
			T2 = T2->next;
		}
		else if(T1->data < T2->data)
			T1 = T1->next;
		else
			T2 = T2->next;
	}
	return I;
}	


//MAIN FUNCTION
int main()
{
	lptr head1 = NULL;
	lptr head2 = NULL;
	int n;
	cout<<"Insert values for linked list1 in sorted order (-1 to stop): ";
	cin>>n;
	while(n!=-1){
		insert(head1,n);
		cin>>n;
	}
	display(head1);
	
	cout<<"\nInsert values for linked list2 in sorted order (-1 to stop): ";
	cin>>n;
	while(n!=-1){
		insert(head2,n);
		cin>>n;
	}
	display(head2);
	
	cout<<"\nThe union of two lists is: ";
	lptr u_head = list_union(head1,head2);
	display(u_head);
	cout<<"NULL";
	
	cout<<"\nThe intersection of two lists is: ";
	lptr i_head = list_intersection(head1,head2);
	display(i_head);
	cout<<"NULL";
	
	return 0;
}

