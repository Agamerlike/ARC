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
	ll k;
	cin>>k;
	ll cnt=0;
	string s;
	int i=0;
	s='0';
	while(cnt<k)
	{
		if(s[i]=='9')
		{
			i++;
			s.push_back('0');
		}
		s[i]++;
		string t=s;
		reverse(t.begin(),t.end());
		cout<<t<<endl;
		cnt++;
	}
	return 0;
}