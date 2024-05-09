#include <iostream>
#include <vector>
using namespace std;
class nqueen
{
public:
    int N;
    nqueen(int n)
    {
        N = n;
    }
    void displayboard(vector<vector<char>> &board)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    ////Backtracking
    bool isSafe(int row, int col, vector<vector<char>> board, int N)
    {
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }
        col = dupcol;
        row = duprow;
        while (row < N && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void bnd()
    {
        vector<vector<char>> board(N, vector<char>(N, '.'));
        return bnbsolver(0,board);
    }
    void bnbsolver(int col, vector<vector<char>> &board)
    {
        if (col == N)
        {
            displayboard(board);
            return;
        }
        for (int row = 0; row < N; row++)
        {
            if(isSafe(row,col,board,N))
            {
                board[row][col]='Q';
                bnbsolver(col+1,board);
                board[row][col]='.';
            }
        }
    }
    ////////////Branch and Bound////////////////////////
    void bnb()
    {
        vector<vector<char>> board(N,vector<char>(N,'.'));
        vector<int> remainingrows(N,0);
        vector<int> upperdiagonal(2*N-1,0);
        vector<int> lowerdiagonal(2*N+1,0);
        return branchandbound(0,remainingrows,lowerdiagonal,upperdiagonal,board);
    }
    void branchandbound(int col , vector<int> & remainingRows , vector<int>lowerDiagonal ,    vector<int>upperDiagonal , vector<vector<char>> &board)
    {
        if(col==N)
        {
            displayboard(board);
            return;
        }
        for(int row=0;row<N;row++)
        {
            if(remainingRows[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[N-1-row+col]==0)
            {
                board[row][col]='Q';
                remainingRows[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[N-1-row+col]=1;
                branchandbound(col+1 ,remainingRows ,lowerDiagonal,upperDiagonal,board);
               board[row][col]='.';
                remainingRows[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[N-1-row+col]=0;


            }
        }
    }
};
int main()
{
    cout << "Enter the number of queens :";
    int n;
    cin >> n;
    if (n == 2 || n == 3)
    {
        cout << "NQueens problem cannot be supported" << endl;
    }
    nqueen obj(n);
    // obj.bnd();
    obj.bnb();
}