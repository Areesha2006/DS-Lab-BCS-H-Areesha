#include<iostream>
using namespace std;
bool isSafe(int board[],int row,int col){
    for(int i = 0; i < row; i++){
        if(board[i]==col||abs(board[i]-col)==abs(i-row)){
            return false;
        } 
    }
    return true;
}
void solveNQueens(int board[],int n,int row=0){
    if(row==n){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(board[i]==j){
                    cout<<"Q";
                }
                else{
                    cout<<"-";
                }
            }
            cout<<endl;        
        }
        cout<<endl;
        return;
    }
    for (int col = 0; col < n; col++){
        if(isSafe(board,row,col)){
            board[row]=col;
            solveNQueens(board,n,row+1);
            board[row]=-1;
        }
    }
}
int main(){
    int N;
    cout<<"Enter the number of queens: ";
    cin>>N;
    int *board=new int[N];
    for(int i=0;i<N;i++){
        board[i]=-1;
    }
    solveNQueens(board,N);
    delete board;
    return 0;
}