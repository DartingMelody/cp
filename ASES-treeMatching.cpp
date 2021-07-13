#include<bits/stdc++.h>
int dp[200001][2];
int maxPair(int u, vector<int> *adj, vector<int> &vis, int par){
  if(vis[u]==1)
    return max(dp[u][0],dp[u][1]);
  vis[u] = 1;
  for(int i = 0;i<adj[u].size();i++){
    int v = adj[u][i];
    if(v==par) return 0;
    dp[u][0]+=maxPair(v, adj, vis, u);
  }
  for(int i = 0;i<adj[u].size();i++){
    int v = adj[u][i];
    int x = dp[u][0] - max(dp[v][1],dp[v][0]);
    dp[u][1] = max(dp[u][1],1+x+dp[v][0]);
  }
  return max(dp[u][0],dp[u][1]);
}
int main(){
  int n;
  cin>>n;
  vector<int> adj[n+1];
  vector<int> vis;
  for(int i = 0;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  vis.push_back(0);
  for(int i = 1;i<=n;i++){
    dp[i][0] = 0;
    dp[i][1] = 0;
    vis.push_back(0);
  }
  maxPair(1, adj, vis, 0);
  cout<<max(dp[1][0],dp[1][1])<<"\n";
}