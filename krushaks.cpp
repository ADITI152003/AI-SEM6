#include<iostream>
#define v 5
using namespace std;
class graph
{
    public:
    int  par[v];
    int findpar(int x)
    {
        if(par[x]==x)
        {
            return x;
        }
        return par[x]=findpar(par[x]);
    }
    void unionset(int x,int y)
    {
        int p=findpar(x);
        int q=findpar(y);
        par[p]=q;
    }
    void kruskals(int graph[v][v])
    {
        int edges=0;
        for(int i=0;i<v;i++)
        {
            par[i]=i;
        }
        int cost=0;
        while(edges<v-1)
        {
            int x=0,y=0;
            int me=1e9;
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(findpar(i)!=findpar(j) && graph[i][j] && me>graph[i][j])
                    {
                        x=i;
                        y=j;
                        me=graph[i][j];
                    }
                }
            }
            cout<<x<<" "<<y<<endl;
            edges++;
            cost+=me;
            unionset(x,y);
        }
        cout<<cost<<endl;
    }
};
int main()
{
    int g[5][5]={
        { 0, 1, 0, 0, 0 },
        { 0, 0, 3, 0, 2},
        { 1, 0, 0, 0, 0 },
        { 0, 0, 3, 0, 5},
        { 0, 0, 0, 0, 0 } 
    };
    graph obj;
    obj.kruskals(g);
}