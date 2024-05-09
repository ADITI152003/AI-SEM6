#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int g=0;
bool solvable(int start[])
{
    int inversions=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]<=1)continue;
        for(int j=i+1;j<9;j++)
        {
            if(start[j]==-1)continue;
            else if(start[j]<start[i])
            {
                inversions++;
            }
        }
    }
    if(inversions%2==0)
    {
        return true;
    }
    return false;
}
void Print(int puzzle[]){
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0) cout << '\n';
        if(puzzle[i] == -1) cout << "_ ";
        else cout << puzzle[i] << " ";
    }
    cout << "\n\n";
}
void Copy(int start[],int goal[])
{
    for(int i=0;i<9;i++)
    {
        goal[i]=start[i];
    }
}
void moveleft(int t1[],int position)
{
    swap(t1[position],t1[position-1]);
}
void moveright(int t2[],int position)
{
    swap(t2[position],t2[position+1]);
}
void moveup(int t2[],int position)
{
    swap(t2[position],t2[position-3]);
}
void movedown(int t2[],int position)
{
    swap(t2[position],t2[position+3]);
}
int hueristic(int start[],int goal[])
{
    int h=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(start[i]==goal[j] && start[i]!=-1)
            {
                h+=(abs(j-i)/3+abs(j-i)%3);
            }
        }
    }
    return h+g;
}
void movetile(int start[],int goal[])
{
    int emptytile=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]==-1)
        {
            emptytile=i;
            break;
        }
    }
    int t1[9],t2[9],t3[9],t4[9];
    Copy(start,t1);
    Copy(start,t2);
    Copy(start,t3);
    Copy(start,t4);
    int f1=INT_MAX;
    int f2=INT_MAX;
    int f3=INT_MAX;
    int f4=INT_MAX;
    int row=emptytile/3;
    int col=emptytile%3;
    if(col-1>=0)
    {
        moveleft(t1,emptytile);
        f1=hueristic(t1,goal);
    }
    if(col+1<3)
    {
        moveright(t2,emptytile);
        f2=hueristic(t2,goal);
    }
    if(row-1>=0)
    {
        moveup(t3,emptytile);
       f3=hueristic(t3,goal);
    }
    if(row+1<3)
    {
        movedown(t4,emptytile);
        f4=hueristic(t4,goal);
    }
    if(f1<=f2 && f1<=f3 && f3<=f4)
    {
        moveleft(start,emptytile);
    }
    else if(f2<=f1 && f2<=f3 && f2<=f4)
    {
        moveright(start,emptytile);
    }
    else if(f3<=f1 && f3<=f2 && f3<=f4)
    {
         moveup(start,emptytile);
    }
    else
    {
        movedown(start,emptytile);
    }
}
void solveeight(int start[], int goal[])
{
    g++;
    movetile(start, goal);
    int f = hueristic(start, goal);
    Print(start);
    if (f == g)
    {
        cout << "Solved in " << g << endl;
        return;
    }
    if (start != goal) // Check if current state is the goal state
    {
        solveeight(start, goal); // Recursive call
    }
}

int main()
{
    int start[9];
    for(int i=0;i<9;i++)
    {
        cin>>start[i];
    }
    int goal[9];
    for(int i=0;i<9;i++)
    {
        cin>>goal[i];
    }   
    if(!solvable(start))
    {
        cout<<"Impossible to solve"<<endl;
    }
    else
    {
        solveeight(start,goal);
    }
}