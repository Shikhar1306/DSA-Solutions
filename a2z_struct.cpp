#include<bits/stdc++.h>
using namespace std;

struct S10{
	int y;
	S10 *z;
};

struct S9{
	S9 *w;
	int x;
};

struct S8{
	S9 *t;
	int u;
	S10 *v;
};

struct S6{
	int n;
	char o;
	S8 *p;
};

struct S7{
	S6 *q;
	int r;
	S7 *s;
};

struct S5{
	int l;
	S7 *m;
};

struct S4{
	S6 *j;
	S5 *k;
};

struct S3{
	S4 *g;
	S3 *h;
	S5 *i;
};

struct S2{
	char e;
	S3 *f;
};

struct S1{
	S1 *a;
	int b;
	S2 *c;
	S1 *d;	
};

int main(){
	S1 *T = new(S1);
	T->c = new(S2);
	T->c->f = new(S3);
	T->c->f->g = new(S4);
	T->c->f->g->j = new(S6);
	T->c->f->i = new(S5);
	T->c->f->i->m = new(S7);
	T->c->f->g->j->p = new(S8);
	T->c->f->g->j->p->t = new(S9);
	T->c->f->g->j->p->v = new(S10);
	
		cin>>T->c->f->g->j->n;
		cin>>T->c->f->i->m->r;
		cin>>T->c->f->g->j->p->u;
		
	if((T->c->f->g->j->p->u)%2 == 0){
		T->c->f->g->j->p->t->x = T->c->f->g->j->n;
		T->c->f->g->j->p->v->y = T->c->f->i->m->r;
	
		cout<<T->c->f->g->j->n<<" ";
		cout<<T->c->f->i->m->r<<" ";
		cout<<T->c->f->g->j->p->u<<" ";
		cout<<T->c->f->g->j->p->t->x<<" ";
		cout<<T->c->f->g->j->p->v->y<<" ";
	}

	else{
		T->c->f->g->j->p->t->x = T->c->f->i->m->r;
		T->c->f->g->j->p->v->y = T->c->f->g->j->n;
	
		cout<<T->c->f->g->j->n<<" ";
		cout<<T->c->f->i->m->r<<" ";
		cout<<T->c->f->g->j->p->u<<" ";
		cout<<T->c->f->g->j->p->t->x<<" ";
		cout<<T->c->f->g->j->p->v->y<<" ";
	}

		
	return 0;
}
