#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n,int row,int col){
    // Same col
    for (int i = row-1; i >=0; i--)
    {
        if(board[i][col]==1)
            return false;
    }
    //  Upper left Diagonal
    for (int i = row-1,j=col-1; i >=0 && j>=0; i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    //  Upper right Diagonal
    for (int i = row-1,j=col+1; i >=0 && j<n; i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}

void nQueenHelp(int n,int row){
    if(row==n){
        // We have reached a solution -> print it -> return
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n\n";
        return;
    }

    // place at all possible positions and move to smaller problem
    for (int j = 0; j < n; j++)
    {
        if(isPossible(n,row,j)){
            board[row][j] = 1;
            nQueenHelp(n,row+1);
            board[row][j] = 0 ; // for next soln we make it 0;
        }
    }
    return;
    
}
void placeNQueens(int n){
    memset(board,0,11*11*sizeof(int));
    nQueenHelp(n,0);
}

int main(){
    placeNQueens(4);
}