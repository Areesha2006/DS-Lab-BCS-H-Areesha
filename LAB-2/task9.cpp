#include<iostream>
using namespace std;
int main(){
    int r,c,element=0;
    cout<<"Enter the number of rows: ";
    cin>>r;
    cout<<"Enter the number of columns: ";
    cin>>c;
    int **mat=new int*[r];
    for(int i=0;i<r;i++){
        mat[i]=new int[c];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter element "<<++element<<": ";
            cin>>mat[i][j];
        }
    }
    cout<<"\nIn Normal Form"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nIn Compressed Form\nRow\tColumn\tValue"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]!=0){
                cout<<i<<"\t"<<j<<"\t"<<mat[i][j]<<endl;
            }
        }
    }
    for(int i=0;i<r;i++){
        delete[] mat[i];
    }
    delete[] mat;
    return 0;
}