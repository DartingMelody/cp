#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200001];
int dp[200001];
int dia[200001];
void solve(int u, int par){
  int dia = 0;
  int l = 0, sl = 0;
  for(int i = 0;i<adj[u].size();i++){
    int v = adj[u][i];
    if(v!=par)
      solve(v, u);
    if(dp[v]> l ){
      sl = l;l = dp[v];
    }
  }
  dp[u] = l+1;
  if (adj[u].size()==0)
    dia[u] = 0;
  if(adj[u].size()==1)
    dia[u] = 1+l;
  else
    dia[u] = 2+l;
  return;
}
int main()
{
  int n;
  cin>>n;
  for(int i = 0;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0;i<=n;i++){
    dp[i] = 0;
  }
  solve(1, 0);
  int maxDia = 0;
  for(int i = 1;i<=n;i++){
    maxDia = max(maxDia, dia[i]);
  }
  cout<<maxDia<<"\n";
}