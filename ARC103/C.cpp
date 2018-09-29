#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

pair<int,int> odd[100001];
pair<int,int> even[100001];
int v[100000];

int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<100001;i++)
	{
		odd[i]=make_pair(0,i);
		even[i]=make_pair(0,i);
	}
	for(int i=0;i<n;i+=2)
	{
		odd[v[i]].first++;
	}
	for(int i=1;i<n;i+=2)
		even[v[i]].first++;
	sort(odd,odd+100001);
	reverse(odd,odd+100001);
	sort(even,even+100001);
	reverse(even,even+100001);
	if(odd[0].second==even[0].second)
	{
		ans=min(n-odd[1].first-even[0].first,n-odd[0].first-even[1].first);
	}else{
		ans=n-odd[0].first-even[0].first;
	}
	cout<<ans<<endl;
	return 0;
}