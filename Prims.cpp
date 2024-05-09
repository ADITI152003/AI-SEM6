#include<iostream>
#include<vector>
#include<climits>
#define v 5
using namespace std;
int mind(vector<bool> mst,vector<int> val)
{
    int vertex;
    int min=INT_MAX;
    for(int i=0;i<val.size();i++)
    {
        if(val[i]<min && mst[i]==false)
        {
            vertex=i;
            min=val[i];
        }
    }
    return vertex;
}
void cost(int graph[v][v])
{
    vector<bool> mst(v,false);
    vector<int> val(v,INT_MAX);
    int parent[v];
    val[0]=0;
    parent[0]=0;
    for(int i=0;i<v-1;i++)
    {
        int u=mind(mst,val);
        mst[u]=true;
        for(int j=0;j<v;j++)
        {
            if(mst[j]==false && graph[u][j] && graph[u][j]<val[j])
            {
                parent[j]=u;
                val[j]=graph[u][j];
            }
        }
    }
    int tcost=0;
    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<" "<<graph[parent[i]][i]<<endl;
        tcost+=graph[parent[i]][i];
    }
    cout<<"The total cost is "<<tcost<<endl;

}
int main()
{
    int graph[5][5]=
    {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };
    cost(graph);

}