#include<bits/stdc++.h>
#include<iostream.h>
using namespace std;
void dfs(int u, int pa, int tot, vector<int>edge[],int sub[], int& re)
{
int sum=sub[u];
for(int i=0;i<edge[u].size();i++){
int v=edge[u][i];
if(v!=pa){
dfs(v,u,tot,edge,sub,re);
sum+=sub[v];
}
}
sub[u]=sum;
if(u!=0 && abs(tot-2*sum)<re)
re=abs(tot-2*sum);
}
int br(int vertex[],int edges[][2], int N)
{
int tot=0;
int sub[N];
for(int i=0;i<N;i++)
{
sub[i]=vertex[i];
tot+=vertex[i];
}
vector<int>edge[N];
for(int i=0;i<N-1;i++)
{
edge[edges[i][0]].push_back(edges[i][1]);
edge[edges[i][1]].push_back(edges[i][0]);
}
int re=INT_MAX;
dfs(0,-1,tot,edge,sub,re);
return re;
}
int main(){
int tc;
cin>>tc;
while(tc--){
int m;
cin>>m;
int e[m-1][2];
int vertex[m];
for(int i=0;i<m-1;i++)
{
cin>>e[i][0];
cin>>e[i][1];
}
for(int i=0;i<m;i++)
{
cin>>vertex[i];
}
cout<<br(vertex,e,m)<<endl;
}
return 0;
}
