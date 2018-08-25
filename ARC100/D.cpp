#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[200000];
ll sum[200001];

int main()
{
	int n;
	int in[3];//切り分けの座標
	ll p[4];//部分列の総和
	ll ans=0;
	
	fill(sum,sum+200000,0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum[i+1]=sum[i]+a[i];
	}

	in[1]=n-2;
	for(int i=2;i<n-1;i++)
	{
		ll tar=sum[n]/2;
		if(sum[i]>tar)
		{
			if(sum[i]-tar>tar-sum[i-1])
			{
				in[1]=i-1;
			}else{
				in[1]=i;//a[i]は後ろ側に含む
			}
			break;
		}
	}

	//前半
	in[0]=1;
	for(int i=1;i<in[1];i++)
	{
		ll tar=sum[in[1]]/2;
		if(sum[i]>tar)
		{
			if(sum[i]-tar>tar-sum[i-1])
			{
				in[0]=i-1;
			}else{
				in[0]=i;//a[i]は後ろ側に含む
			}
			break;
		}
	}

	//後半
	in[2]=n-1;
	for(int i=in[1]+1;i<n;i++)
	{
		ll tar=(sum[n]-sum[in[1]])/2;
		if(sum[i]-sum[in[1]]>tar)
		{
			if(sum[i]-sum[in[1]]-tar>tar-(sum[i-1]-sum[in[1]]))
			{
				in[2]=i-1;
			}else{
				in[2]=i;
			}
			break;
		}
	}

	p[0]=sum[in[0]];
	p[1]=sum[in[1]]-sum[in[0]];
	p[2]=sum[in[2]]-sum[in[1]];
	p[3]=sum[n]-sum[in[2]];
	cerr<<"pqrs"<<endl;
	for(int i=0;i<4;i++)
	{
		cerr<<p[i]<<endl;
	}
	cerr<<"bcde"<<endl;
	cerr<<0<<endl;
	for(int i=0;i<3;i++)
	{
		cerr<<in[i]<<endl;
	}
	sort(p,p+4);
	ans=p[3]-p[0];
	cout<<ans<<endl;
	return 0;
}