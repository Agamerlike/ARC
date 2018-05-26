#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int w[300001];
int e[300001];//i未満のeの人数
int main()
{
	int n;
	string s;
	int ans=0;
	
	cin>>n;
	cin>>s;
	w[0]=0;
	e[0]=0;
	for(int i=1;i<n+1;i++)
	{
		if(s[i-1]=='W')
		{
			w[i]=w[i-1]+1;
			e[i]=e[i-1];
		}else{
			w[i]=w[i-1];
			e[i]=e[i-1]+1;
		}
	}

	for(int i=0;i<n;i++)
	{
		int temp=e[i]+(w[n]-w[i+1])+1; //これは向きを変えなくてもいい人の人数
		if(ans<temp)
		{
			//cerr<<i<<" "<<temp<<endl;
			ans=temp;
		}
	}
	ans=n-ans;
	cout<<ans<<endl;
	return 0;
}