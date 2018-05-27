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
ll sum[200001];//i未満の累積和
ll xox[200001];//i未満のxor

int main()
{
	int n;
	ll ans=0;
	
	cin>>n;
	sum[0]=0;
	xox[0]=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum[i+1]=sum[i]+a[i];
		ll d=(xox[i]^a[i]);
		xox[i+1]=d;
	}

	//尺取り法
	int r=0;
	for(int l=0;l<n;l++)
	{
		ll ss=sum[r+1]-sum[l];
		ll xx=(xox[r+1]^xox[l]);
		while(ss==xx && r<n+1)
		{
			r++;
			ss=sum[r+1]-sum[l];
			xx=(xox[r+1]^xox[l]);
			//cerr<<ss<<" "<<xx<<endl;
		}
		r=min(r,n);
		//cerr<<l<<" "<<r<<endl;
		ans+=(r-1)-l+1;
	}
	cout<<ans<<endl;
	return 0;
}