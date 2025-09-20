#include<iostream>
using namespace std;
bool isSafe(int** arr,int x,int y,int n,int** solArr){
    if(x>=0&&y>=0&&x<n&&y<n&&arr[x][y]==1&&solArr[x][y]==0){
        return true;
    }
    return false;
}
bool ratinMaze(int** arr,int x,int y,int n,int** solArr){
    if((x==n-1)&&(y==n-1)){
        solArr[x][y]=1;
        return true;
    }
    if(isSafe(arr,x,y,n,solArr)){
        solArr[x][y]=1;
        if(ratinMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x-1,y,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y-1,n,solArr)){
            return true;
        }
        solArr[x][y]=0;
        return false;
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    int **maze=new int*[n],**solArr=new int*[n];
    for (int i = 0; i < n; i++){
        maze[i]=new int[n];
        solArr[i]=new int[n];
    }
    cout<<"Enter maze matrix (0-route is block 1-path is available)"<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            solArr[i][j]=0;
            do{
                cout<<"Enter maze matrix for row "<<i+1<<" column "<<j+1<<": ";
                cin>>maze[i][j];
                if(maze[i][j]!=1&&maze[i][j]!=0){
                    cout<<"Invalid input"<<endl;
                }
            }while(maze[i][j]!=1&&maze[i][j]!=0);
        }
    }
    cout<<"\nMaze"<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    } 
    if(ratinMaze(maze,0,0,n,solArr)){
        cout<<"\nPath Found"<<endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }        
    }
    else{
        cout<<"No path found";
    }
    for(int i=0;i<n;i++){
        delete[] maze[i];
        delete[] solArr[i];
    }
    delete[] maze;
    delete[] solArr;
    return 0;
}