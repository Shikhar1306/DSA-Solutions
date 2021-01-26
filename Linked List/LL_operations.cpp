#include<bits/stdc++.h>

using namespace std;

//Structure of linked list
typedef struct Node{
	int val;
	Node *next;
}*lptr;

//Functions of linked list operations
void insert(lptr T,int data){
	while(T->next != NULL){
		T = T->next;
	}
	lptr temp = new Node;
	temp->val = data;
	temp->next = NULL;
	T->next = temp;
}

void display(lptr T){
	while(T != NULL){
		cout<<T->val<<" ";
		T = T->next;
	}
}

lptr reverse(lptr T){
	lptr prevptr = NULL;
	lptr currptr = T;
	lptr nxtptr;
	
	while(currptr != NULL){
		nxtptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nxtptr;		
	}
	
	return prevptr;
}

int count_nodes(lptr T){
	int count=0;
	while(T!= NULL){
		count++;
		T = T->next;
	}
	return count;
}

int min_val(lptr T){
	int min = T->val;
	while(T!=NULL){
		if(T->val<=min){
			min = T->val;
		}
		T = T->next;
	}
	return min;
}

int max_val(lptr T){
	int max = T->val;
	while(T!=NULL){
		if(T->val>=max){
			max = T->val;
		}
		T = T->next;
	}
	return max;	
}

int mid_val(lptr T){
	int mid,mid_val;
	mid = count_nodes(T)/2;
	for(int i=0;i<mid;i++){
		T = T->next;
	}
	mid_val = T->val;
	return mid_val;
}

int odd_val(lptr T){
	int odd=0;
	while(T!=NULL){
		if((T->val)%2!=0){
			odd++;
		}
		T = T->next;
	}
	return odd;
}

int even_val(lptr T){
	int even=0;
	while(T!=NULL){
		if((T->val)%2==0){
			even++;
		}
		T = T->next;
	}
	return even;
}

int find(lptr T,int k){
	while(T!=NULL){
		if(T->val ==k){
			return 1;
		}
		T = T->next;
	}
	return 0;
}

//MAIN FUNCTION
int main(){
	int n;
	lptr head = new Node;
	cout<<"Enter values (enter -1 to stop entering values)\n";
	cin>>n;
	if(n==-1){
		return 0;
	}
	head->val = n;
	head->next = NULL;
	cin>>n;
	while(n!=-1){
		insert(head,n);
		cin>>n;
	}
	cout<<"Linked list is: ";
	display(head);
		
	cout<<"\nLinked list in reverse order is: ";
	lptr newhead = reverse(head);
	display(newhead);
	
	head = reverse(newhead);

	cout<<"\nThe number of nodes are: "<<count_nodes(head);
	
	cout<<"\nThe minimum value is: "<<min_val(head);
	
	cout<<"\nThe maximum value is: "<<max_val(head);
	
	cout<<"\nThe middle value is: "<<mid_val(head);
	
	cout<<"\nThe number of odd values are: "<<odd_val(head);
	
	cout<<"\nThe number of even values are: "<<even_val(head);
	
	int k;
	cout<<"\nEnter the value to be searched: ";
	cin>>k;
	cout<<find(head,k);
	
	return 0;	
}

