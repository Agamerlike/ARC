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
ll bit=0;
int arm[21];

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
	//一致していれば必要なアーム数を求める
	fill(arm,arm+21,0);
	int armcnt=0;
	//and計算をして、必ず2本必要な場所を求める
	for(int i=0;i<n;i++)
	{
		bit=(ll)abs(x[i])&(ll)abs(y[i]);
		for(int j=0;j<21;j++)
		{
			ll temp=bit&(ll)pow(2,j);
			if(temp>0 && arm[j]==0)
			{
				arm[j]+=2;
				armcnt+=2;
			}
		}
	}
	//xorとand計算をして、必ず1本必要な場所を求める
	bit=(ll)abs(x[0])^(ll)abs(y[0]);
	for(int i=1;i<n;i++)
	{
		ll temp=(ll)abs(x[i])^(ll)abs(y[i]);
		bit=bit&temp;
	}
	for(int i=0;i<21;i++)
	{
		ll temp=bit&(ll)pow(2,i);
		if(temp>0)
		{
			arm[i]+=1;
			armcnt+=1;
		}
	}
	//xor計算をそれぞれして、不足分を補う
	for(int i=0;i<n;i++)
	{
		ll bit=(ll)abs(x[i])^(ll)abs(y[i]);
		//それぞれのbitについて調べる
		for(int j=0;j<21;j++)
		{
			ll temp=bit&(ll)pow(2,i);
			if(temp>0)
			{
				//足りない場合は追加する
				//追加の仕方はd/2を2本
				if(arm[j]%2==0 && arm[j-1]%2<3)
				{
					arm[j-1]+=2;
					armcnt+=2;
				}
			}
		}
	}
	//ここから答え
	//armcntが40超えてたら構成は無理
	if(armcnt>40)
	{
		cout<<-1<<endl;
		return 0;
	}
	//それ以外ならできるので復号
	cout<<armcnt<<endl;
	for(int i=0;i<21;i++)
	{
		ll leng=(ll)pow(2,i);
		for(int j=0;j<arm[i];j++)
		{
			cout<<leng;
			cout<<" ";
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		//長さ順に復号されていることに注意
		vector<pair<ll,char>> comm;
		int armcp[21];
		for(int j=0;j<21;j++)
			armcp[j]=arm[j];
		ll aaa=(ll)abs(x[i])&(ll)abs(y[i]);
		ll xxx=(ll)abs(x[i])^(ll)abs(y[i]);
		//まずはandのコマンド
		for(int j=0;j<21;j++)
		{
			ll temp=aaa&(ll)pow(2,j);
			if(temp>0)
			{
				if(x[i]<0)
					comm.push_back(make_pair(temp,'L'));
				else
					comm.push_back(make_pair(temp,'R'));
				if(y[i]<0)
					comm.push_back(make_pair(temp,'D'));
				else
					comm.push_back(make_pair(temp,'U'));
				armcp[j]-=2;
			}
		}
		//次にxorのコマンド
		for(int j=0;j<21;j++)
		{
			ll temp=xxx&(ll)pow(2,j);
			if(temp>0)
			{
				//どっちのものか判定
				ll tt=temp&(ll)abs(x[i]);
				//cerr<<jj<<endl;
				if(tt>0) //x
				{
					if(armcp[j]>0)
					{
						if(x[i]<0)
							comm.push_back(make_pair(temp,'L'));
						else
							comm.push_back(make_pair(temp,'R'));
						armcp[j]--;
					}else{
						if(x[i]<0)
						{
							comm.push_back(make_pair(temp/2,'L'));
							comm.push_back(make_pair(temp/2,'L'));
						}else{
							comm.push_back(make_pair(temp/2,'R'));
							comm.push_back(make_pair(temp/2,'R'));
						}
						armcp[j-1]-=2;
					}
				}else{
					if(armcp[j]>0)
					{
						if(y[i]<0)
							comm.push_back(make_pair(temp,'D'));
						else
							comm.push_back(make_pair(temp,'U'));
						armcp[j]--;
					}else{
						if(y[i]<0)
						{
							comm.push_back(make_pair(temp/2,'D'));
							comm.push_back(make_pair(temp/2,'D'));
						}else{
							comm.push_back(make_pair(temp/2,'U'));
							comm.push_back(make_pair(temp/2,'U'));
						}
						armcp[j-1]-=2;
					}
				}
			}
		}
		//余ったものを補う
		for(int j=0;j<21;j++)
		{
			if(armcp[j]>0)
			{
				int cnt=armcp[j]/2;
				int leng=(int)pow(2,j);
				for(int k=0;k<cnt;k++)
				{
					comm.push_back(make_pair(leng,'D'));
					comm.push_back(make_pair(leng,'U'));
				}
			}
		}
		sort(comm.begin(),comm.end());
		for(int j=0;j<comm.size();j++)
			cout<<comm[j].second;
		cout<<endl;
		/*
		for(int j=0;j<comm.size();j++)
			cerr<<comm[j].first;
		cerr<<endl;*/
	}
	return 0;
}