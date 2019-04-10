#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v); ////u------>v in case of directed
    adj[v].push_back(u); ////for directed remove this line means one one will have that edge
}
void BFSUtil(vector<int> adj[],int i,vector<bool> &visited)
{
    queue<int> q;
    q.push(i);
    visited[i]=true;

    while(!q.empty())
    {
        int f=q.front();

        q.pop();
        cout<<f<<" ";
        for(int j=0;j<adj[f].size();++j)
        {
            if(visited[adj[f][j]]==false)
            {
                visited[adj[f][j]]=true;
                q.push(adj[f][j]);
            }

        }
    }


}
void BFS(vector<int> adj[],int n)
{
    vector<bool> visited(n,false);
    for(int i=0 ;i<n;++i)
        if(visited[i]==false)
            BFSUtil(adj,i,visited);
}

int main()
{
   // cout<<"enter number of vertex and edges: ";
    int n,e; cin>>n>>e;  //n=no of vertex e=no of edges
    vector<int> adj[n];
    for(int i=0;i<e;++i)
    {
        int u,v; //cout<<"input u and v: ";
        cin>>u>>v;
        addEdge(adj,u, v);
    }
    BFS(adj,n);
    return 0;
}
