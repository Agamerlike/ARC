#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int costb[2001];//同じ色内で交換させるのに必要な回数
int costw[2001];
int pb[2001];//並べ替える対象（同じ色）
int pw[2001];
int main()
{
	int n;
	string c[4000];
	string cc[4000];
	int a[4000];
	int aa[4000];
	ll ans=0;
	int fir;
	
	cin>>n;
	for(int i=0;i<2*n;i++)
	{
		cin>>c[i]>>a[i];
		cc[i]=c[i];
		aa[i]=a[i];
	}
	//最初に黒を並べる
	int d=0;
	int e=0;
	for(int i=0;i<2*n;i++)
	{
		if(cc[i]=='B')
		{
			pb[d]=aa[i];
			costb[d]=i;
			d++;
		}else{
			pw[e]=aa[i];
			costw[e]=i;
			e++;
		}
	}
	for(int i=n-1;i>0;i--)
	{
		costb[i]=costb[i]-costb[i-1];
		costw[i]=costw[i]-costw[i-1];
	}
	costb[0]=1;

	//バブルソート
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(pb[j]<pb[j-1])
			{
				swap(pb[j],pb[j-1]);
				ans+=cost[j];
				cost[j]+=cost[j-1]-1;
				cost[j-1]=1;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}