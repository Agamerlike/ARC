#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;
int a[200000];

int main()
{
	int n;
	int b;
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]-=(i+1);
	}
	sort(a,a+n);
	b=a[n/2];
	for(int i=0;i<n;i++)
	{
		ans+=abs(a[i]-b);
	}
	cout<<ans<<endl;
	return 0;
}