#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <deque>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[2000];
vector<ll> tori;//取り出される可能性のある数字
deque<ll> part[2000];//部分列

int main()
{
	int n,k,q;
	ll ans=1e16+1;
	
	cin>>n>>k>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];

	//a[i]を最小値として取り出せるかを調べる
	for(int i=0;i<n;i++)
	{
		int index=0;
		for(int j=0;j<n;j++)
			part[j].clear();
		tori.clear();
		for(int j=0;j<n;j++)
		{
			if(a[i]>a[j])
				index++;
			else
				part[index].push_back(a[j]);
		}

		for(int j=0;j<index+1;j++)
		{
			sort(part[j].begin(),part[j].end());
			while(part[j].size()>=k)
			{
				tori.push_back(part[j][0]);
				part[j].pop_front();
			}
		}

		sort(tori.begin(),tori.end());
		/*
		cerr<<a[i]<<endl;
		for(int j=0;j<tori.size();j++)
			cerr<<tori[j]<<" ";
		cerr<<endl;*/
		if(tori.size()>=q)
		{
			ll temp=tori[q-1]-tori[0];
			ans=min(temp,ans);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}