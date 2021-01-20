#include<bits/stdc++.h>
using namespace std;

struct s6{
	s6 *p;
	int q;
	s6 *r;
};

struct s5{
	char m;
	s6 *n;
	s5 *o;
};

struct s3{
	s3 *d;
	s5 *e;
	s3 *f;
};

struct s2{
	s2 *g;
	s6 *h;
	s2 *i;
};

struct s4{
	s2 *j;
	s3 *k;
	s5 *l;
};

struct s1{
	s1 *a;
	s2 *b;
	s1 *c;
};

int main(){
	s4 *T = new(s4);
	T->j = new(s2);
	T->j->h = new(s6);
	T->j->h->p = new(s6);
	T->k = new(s3);
	T->k->e = new(s5);
	T->k->e->o = new(s5);
	
	cin>>T->j->h->p->q;
	cin>>T->k->e->o->m;
	
	cout<<T->j->h->p->q;
	cout<<T->k->e->o->m;
	
	return 0;
	
}
