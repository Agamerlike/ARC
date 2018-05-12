#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	string s;
	int m;
	int cnt=0;
	vector<string> ans;
	int c=0;
	bool f=false;
	
	cin>>s;
	cin>>m;
	for(int i=0;i<s.length();i++)
	{
		string t=s.substr(i,1);
		ans.push_back(t);
	}
	for(int i=1;i<s.length();i++)
	{
		string t=s.substr(i-1,2);
		ans.push_back(t);
	}
	for(int i=2;i<s.length();i++)
	{
		string t=s.substr(i-2,3);
		ans.push_back(t);
	}
	for(int i=3;i<s.length();i++)
	{
		string t=s.substr(i-3,4);
		ans.push_back(t);
	}
	for(int i=4;i<s.length();i++)
	{
		string t=s.substr(i-4,5);
		ans.push_back(t);
	}
	sort(ans.begin(),ans.end());
	int i=1;
	while(i<ans.size())
	{
		if(ans[i]==ans[i-1])
			ans.erase(ans.begin()+i-1);
		else
			i++;
	}
	cout<<ans[m-1]<<endl;
	return 0;
}