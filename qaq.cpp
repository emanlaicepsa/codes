#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define MAXN 100004
#define MAXR 1000000
#define L(k) (k*2)
#define R(k) (k*2+1)
int inline mid (int a, int b){return (a+b)>>1;}
typedef struct
{
	int cov, len;
}Tree;Tree bsp[MAXR*3];
void update (int a, int b, int x, int k, int l, int r)
{
	if(a>r||b<l)return;
	else if(a<=l && r<=b)
	{
  	bsp[k].cov += x;
  	if(bsp[k].cov!=0)bsp[k].len=r-l+1;
   	else if(r-l>0)bsp[k].len=bsp[L(k)].len+bsp[R(k)].len;
   	else bsp[k].len=0;
  }
  else
  {
  	update (a, b, x, L(k), l, mid(l, r));
   	update (a, b, x, R(k), mid(l, r)+1, r); 
   	if(bsp[k].cov!=0)bsp[k].len=r-l+1;
   	else bsp[k].len=bsp[L(k)].len+bsp[R(k)].len;
	}
	cout<<a<<" "<<b<<" "<<l<<" "<<r<<" "<<bsp[k].len<<'\n';
}
typedef struct
{
	int x, u, d, LR;
}rect;rect qA[MAXN*2];bool inline cmp (rect a, rect b){return a.x<b.x;}
int main ()
{
	int qN, i;scanf ("%d", &qN);
	for (i = 0 ; i < qN ; i ++)
	{
		int l, r, d, u;scanf ("%d%d%d%d", &l, &r, &d, &u);
		qA[i] = (rect){l, u, d, 1};
		qA[i+qN] = (rect){r, u, d, -1};
	}sort (qA, qA+2*qN, cmp);
	int pv=0;ll AC=0;
	for (i = 0 ; i < 2*qN ; i ++)
	{
		AC += (ll)bsp[1].len*(qA[i].x-pv);
		pv = qA[i].x;
		update (qA[i].d+1, qA[i].u, qA[i].LR, 1, 0, MAXR);
	}printf ("%I64d\n", AC);
	return 0;
}
