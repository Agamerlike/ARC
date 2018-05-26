#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[2000];
ll cpa[2000];
ll sa[2000];//a[i]-a[i-1]
ll rui[2001];//sa[i]未満の累積和
bool tori[2000];//a[i]を最小値として取り出せるか

int main()
{
	int n,k,q;
	ll ans=1e16+1;
	
	cin>>n>>k>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cpa[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=max(0,i-q+1);j<min(n,i+q))
		{
			
		}
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		sa[i]=a[i]-a[i-1];
	}
	rui[1]=0;
	for(int i=2;i<n+1;i++)
	{
		rui[i]=rui[i-1]+sa[i-1];
	}

	for(int i=1;i<n+2-q;i++)
	{
		ll temp=rui[i+q-1]-rui[i];
		cerr<<temp<<endl;
		ans=min(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}