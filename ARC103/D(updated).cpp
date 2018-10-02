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
vector<ll> arm;
char com[36];

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
	//アームは大きい方から40本
	int armcnt=35;
	if(((ll)abs(x[0])+(ll)abs(y[0]))%2==0)
	{
		arm.push_back(1);//偶数なら1を足しておく
		armcnt--;
	}
	ll bit=1;
	for(int i=0;i<armcnt;i++)
	{
		arm.push_back(bit);
		bit*=2;
	}
	sort(arm.begin(),arm.end());
	reverse(arm.begin(),arm.end());

	//ここから答え
	cout<<35<<endl;
	for(int i=0;i<35;i++)
		cout<<arm[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		//fill(com,com+36,'0');
		ll nowx=0;
		ll nowy=0;
		for(int j=0;j<35;j++)
		{
			if(abs(x[i]-nowx)<abs(y[i]-nowy))
			{
				if(y[i]<=nowy)
				{
					nowy-=arm[j];
					cout<<"D";
				}else{
					nowy+=arm[j];
					cout<<"U";
				}
			}else{
				if(x[i]<=nowx)
				{
					nowx-=arm[j];
					cout<<"L";
				}else{
					nowx+=arm[j];
					cout<<"R";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}