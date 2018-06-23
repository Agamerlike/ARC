#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <functional>
typedef long long ll;

using namespace std;

class Edge
{
	public:
	int cost;
	int from;
	int to;

	Edge(int n,int c)
	{
		to=n;
		cost=c;
	}

	Edge(int f,int t,int c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

vector<Edge> g[700];
bool used[700];

int main()
{
	int ans=1e9-1;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
	}
	
	for(int i=0;i<n;i++)
	{
		fill(used,used+n,false);
		bool u[700];
		int d[700];
		int taka=0;
		fill(u,u+700,false);
		fill(d,d+700,1e9-1);
		u[i]=true;
		taka++;
		for(int j=0;j<g[i].size();j++)
		{
			u[g[i][j].to]=true;
			taka++;
		}
		int s=0;
		for(int j=0;j<n;j++)
		{
			if(!u[j])
			{
				s=j;
				break;
			}
		}
		//ダイクストラ
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
		d[s]=0;
		que.push(make_pair(0,s));
		while(!que.empty())
		{
			pair<int,int> p=que.top();
			que.pop();
			int v=p.second;
			if(d[v]<p.first)
				continue;
			
			for(int i=0;i<g[v].size();i++)
			{
				Edge e=g[v][i];
				if(d[e.to]>d[v]+e.cost)
				{
					d[e.to]=d[v]+e.cost;
					que.push(make_pair(d[e.to],e.to));
				}
			}
		}

		bool f=true;
		for(int j=0;j<n;j++)
		{
			if(!u[j])
			{
				if(d[j]>1)
				{
					f=false;
					break;
				}
			}
		}

		if(f)
		{
			int cnt=taka*(taka-1)/2;
			int hashi=n-taka;
			cnt+=hashi*(hashi-1)/2;
			cerr<<taka<<" "<<hashi<<" "<<cnt<<endl;
			ans=min(ans,cnt);
		}
	}
	if(ans==1e9-1)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}