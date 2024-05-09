#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
    public:
    int n;
    vector<vector<int>> adjlist;
    Graph(int N)
    {
        n=N;
        adjlist.resize(n);
    }
    void addedge(int a,int b)
    {
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    void dfs(int start)
    {
        vector<bool> vis(n,false);
        dfs_recursive(vis,0);
    }
    void dfs_recursive(vector<bool> &vis,int v)
    {
        cout<<v<<" ";
        vis[v]=1;
        for(auto ver:adjlist[v])
        {
            if(vis[ver]==false)
            {
                dfs_recursive(vis,ver);
            }
        }
    }
    void bfs(int start)
    {
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(start);
        bfs_recursive(vis,q);
    }
    void bfs_recursive(vector<bool> &vis,queue<int> q)
    {
        if(q.empty())
        {
            return;
        }
        int a=q.front();
        
            cout<<a<<" ";
        q.pop();
        vis[a]=true;
        for(auto it:adjlist[a])
        {
            if(vis[it]==false)
            {
                q.push(it);
                vis[it]=true;
            }
        }
        bfs_recursive(vis,q);
    }
};
int main()
{
    Graph g(6);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,5);
    g.addedge(5,4);
    g.addedge(3,4);
    g.addedge(1,3);
    g.addedge(0,3);
    g.dfs(0);
    cout<<endl;
    g.bfs(0);
}