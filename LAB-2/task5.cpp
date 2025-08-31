#include<iostream>
using namespace std;
int main(){
    int r,c,element=1;
    cout<<"How many rows are there: ";
    cin>>r;
    cout<<"How many columns are there: ";
    cin>>c;
    int **mat1=new int*[r],**mat2=new int*[r];
    for(int i=0;i<r;i++){
        mat1[i]=new int[c];
        mat2[i]=new int[c];
    }
    cout<<"For Matrix 1"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter element "<<element++<<": ";
            cin>>mat1[i][j];
        }
    }
    element=1;
    cout<<"\nFor Matrix 2"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter element "<<element++<<": ";
            cin>>mat2[i][j];
        }
    }
    cout<<"\nMatrix 1"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat1[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMatrix 2"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat2[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMatrix 1+Matrix 2"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat1[i][j]+mat2[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMatrix 1-Matrix 2"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat1[i][j]-mat2[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i=0;i<r;i++){
        delete[] mat1[i];
        delete[] mat2[i];
    }
    delete[] mat1;
    delete[] mat2;
    return 0;
}