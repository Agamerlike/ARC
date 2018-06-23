#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int a[100000];

int main()
{
	int n,k;
	int ans=1e9-1;
	int mindex;
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			mindex=i;
	}
	//最初に埋める
	for(int i=max(mindex-k+1,0);i<mindex+1;i++)
	{
		//copy(a,a+n,b);
		int cnt=1;
		int l=i;
		if(l>0)
			cnt+=l/(k-1)+(l%(k-1)==0 ? 0: 1);
		//cerr<<i<<" "<<cnt;
		int r=i+k-1;
		if(r<n)
			cnt+=(n-r-1)/(k-1)+((n-r-1)%(k-1)==0 ? 0 : 1);
		ans=min(cnt,ans);
		//cerr<<" "<<cnt<<endl;
	}

	cout<<ans<<endl;
	return 0;
}