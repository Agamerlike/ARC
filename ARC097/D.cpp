#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
typedef long long ll;

using namespace std;

class Edge
{
	public:
	int cost;
	int next;

	Edge(int n,int c)
	{
		next=n;
		cost=c;
	}
};

vector<Edge> g[100000];
vector<int> pr[100000];
bool used[100000];
int p[100000];
int cnt;

int dfs(int now)
{
	used[now]=true;
	pr[cnt].push_back(now);
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if(!used[e.next])
		{
			dfs(e.next);
		}
	}
	return 0;
}

int main()
{
	int n,m;
	cnt=0;
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		p[i]--;
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].push_back(Edge(y,1));
		g[y].push_back(Edge(x,1));
	}
	fill(used,used+100000,false);
	//連結判定
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			dfs(i);
			cnt++;
		}
	}
	
	for(int i=0;i<cnt;i++)
	{
		int s=pr[i].size();
		for(int j=0;j<s;j++)
		{
			pr[i].push_back(p[pr[i][j]]);
		}
		sort(pr[i].begin(),pr[i].end());
		for(int j=1;j<pr[i].size();j++)
		{
			if(pr[i][j]==pr[i][j-1])
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}