#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
 
typedef long long ll;
ll MOD = 1e9+7;
double EPS = 1e-10; //誤差
 
ll x[100000];
vector<ll> m; //0未満
vector<ll> p;//o以上
 
 
int main()
{
	int n,k;
	ll ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		if(x[i]<0)
			m.push_back(abs(x[i]));
		else if(x[i]>0)
			p.push_back(x[i]);
		else{
			k++;
			m.push_back(x[i]);
			p.push_back(x[i]);
		}
	}
	reverse(m.begin(),m.end());
	cerr<<"input"<<endl;
	if(k<=m.size() && k<=p.size())
	{
		ans=min(m[k-1],p[k-1]);
		for(int i=0;i<k-1;i++)
			ans=min(ans,m[i]*2+p[k-i-2]);
		for(int i=0;i<k-1;i++)
			ans=min(ans,p[i]*2+m[k-i-2]);
	}else if(k<=m.size()){
		ans=m[k-1];
		for(int i=0;i<p.size();i++)
		{
			ans=min(ans,p[i]*2+m[k-i-2]);
		}
		for(int i=0;i<k-1;i++)
		{
			if(i+1+p.size()<k)
				continue;
			ans=min(ans,m[i]*2+p[k-i-2]);
		}
	}else if(k<=p.size()){
		//cerr<<"plus"<<endl;
		ans=p[k-1];
		for(int i=0;i<m.size();i++)
		{
			ans=min(ans,m[i]*2+p[k-i-2]);
		}
		for(int i=0;i<k-1;i++)
		{
			if(i+1+m.size()<k)
				continue;
			ans=min(ans,p[i]*2+m[k-i-2]);
		}
	}else{
		ans=min(m[m.size()-1]*2+p[k-m.size()-1],p[p.size()-1]*2+m[k-p.size()-1]);
		for(int i=0;i<p.size();i++)
		{
			if(i+1+m.size()<k)
				continue;
			ans=min(ans,p[i]*2+m[k-i-2]);
		}
		for(int i=0;i<m.size();i++)
		{
			if(i+1+p.size()<k)
				continue;			
			ans=min(ans,m[i]*2+p[k-i-2]);
		}
	}
	cout<<ans<<endl;
	return 0;
}