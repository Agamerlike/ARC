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
ll g[200001];//1+2+...+n
ll sum[200001];//i未満の累積和
ll xox[200001];//i未満のxor
ll sa[200001];//累積和の差分
ll oo[200001];//xorのxor

int main()
{
	int n;
	ll ans=0;
	
	cin>>n;
	sum[0]=0;
	xox[0]=0;
	g[0]=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		g[i+1]=g[i]+i+1;
		sum[i+1]=sum[i]+a[i];
		ll d=(xox[i]^a[i]);
		xox[i+1]=d;
	}

	int i=0;
	while(i<n+1)
	{
		int j=i+1;
		ll ss=sum[j+1]-sum[i];
		ll xx=(xox[j+1]^xox[i]);
		int cnt=0;
		if(ss==xx)
		{
			cerr<<i<<" ";
			cnt=1;
			while(i<n+1)
			{
				i++;
				int j=i+1;
				ll ss=sum[j+1]-sum[i];
				ll xx=(xox[j+1]^xox[i]);
				if(ss!=xx)
					break;
				else
					cnt++;
			}
			cnt=min(cnt,n);
			cerr<<g[cnt]<<endl;
			ans+=g[cnt];
		}else{
			i++;
		}
	}
	ans+=n-1;
	cout<<ans<<endl;
	return 0;
}