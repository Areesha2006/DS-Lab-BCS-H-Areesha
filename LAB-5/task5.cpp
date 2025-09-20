#include<iostream>
using namespace std;
bool isSafe(int** sudoko,int r,int c,int num){
    for(int i=0;i<9;i++){
        if(sudoko[i][c]==num||sudoko[r][i]==num){
            return false;
        }
    }
    int start_row=r-(r%3);
    int start_column=c-(c%3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(sudoko[start_row+i][start_column+j]==num){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoko(int **sudoko,int r=0,int c=0){
    if(r==9){
        cout<<"After solving"<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoko[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    int next_row,next_col=(c+1)%9;
    if(c==8){
        next_row=r+1;
    }
    else{
        next_row=r;
    }
    if(sudoko[r][c]==0){
        for (int i = 1; i <=9; i++){
            if(isSafe(sudoko,r,c,i)){
                sudoko[r][c]=i;
                if(solveSudoko(sudoko,next_row,next_col)){
                    return true;
                }
                sudoko[r][c]=0;
            }
        }
    }
    else{
        return solveSudoko(sudoko,next_row,next_col);
    }
    return false;
}
int main(){
    cout<<"Enter elements for sudoko"<<endl;
    int **sudoko=new int*[9];
    for(int i=0;i<9;i++){
        sudoko[i]=new int[9];
        for(int j=0;j<9;j++){
            while(true){
                cout<<"Enter the element for row "<<i+1<<" column "<<j+1<<" (0-9): ";
                cin>>sudoko[i][j];
                if(sudoko[i][j]>=0&&sudoko[i][j]<=9){
                    break;
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
            }
        }
    }
    cout<<"Before solving"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoko[i][j]<<" ";
        }
        cout<<endl;
    }
    if(!solveSudoko(sudoko)){
        cout<<"No solution Found";
    }
    for (int i = 0; i < 9; i++){
        delete[] sudoko[i];
    }
    delete[] sudoko;
    return 0;
}