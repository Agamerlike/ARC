#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll x[1000];
ll y[1000];

int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	
	bool f=true;
	//座標の合計の偶奇が一致しているかどうか調べる
	if(((ll)abs(x[0])+(ll)abs(y[0]))%2==0)
	{
		for(int i=0;i<n;i++)
		{
			if(((ll)abs(x[i])+(ll)abs(y[i]))%2!=0)
			{
				f=false;
				break;
			}
		}
	}else{
		for(int i=0;i<n;i++)
		{
			if(((ll)abs(x[i])+(ll)abs(y[i]))%2==0)
			{
				f=false;
				break;
			}
		}
	}
	//一致していなければ構成は無理
	if(!f)
	{
		cout<<-1<<endl;
		return 0;
	}
	//一致していればそれぞれ答えを出力
	int arm;
	if(((ll)abs(x[0])+(ll)abs(y[0]))%2==0)
	{
		arm=20;
		cout<<20<<endl;
		for(int i=0;i<20;i++)
			cout<<"1 ";
		cout<<endl;
	}else{
		arm=19;
		cout<<19<<endl;
		for(int i=0;i<19;i++)
			cout<<"1 ";
		cout<<endl;
	}

	//ここから答え
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(int)abs(x[i]);j++)
		{
			if(x[i]<0)
				cout<<"L";
			else
				cout<<"R";
		}
		for(int j=0;j<(int)abs(y[i]);j++)
		{
			if(y[i]<0)
				cout<<"D";
			else
				cout<<"U";
		}
		for(int j=0;j<arm-(int)abs(x[i])-(int)abs(y[i]);j+=2)
			cout<<"LR";
		cout<<endl;
	}
	return 0;
}