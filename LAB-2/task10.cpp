#include<iostream>
using namespace std;
int main(){
    int num_cat;
    cout<<"Enter the number of categories: ";
    cin>>num_cat;
    int **library=new int*[num_cat],*num_books=new int[num_cat];
    string *category_name=new string[num_cat];
    for(int i=0;i<num_cat;i++){
        cout<<"Enter the name of category "<<i+1<<": ";
        cin>>category_name[i];
        while(1){
            cout<<"Enter the number of books in category \' "<<category_name[i]<<" '\: ";
            cin>>num_books[i];
            if(num_books[i]>0){
                break;
            }
            else{
                cout<<"Invalid Input"<<endl;
            }
        }
        library[i]=new int[num_books[i]];
    }
    for(int i=0;i<num_cat;i++){
        cout<<"For category \' "<<category_name[i]<<" '\ "<<endl;
        for(int j=0;j<num_books[i];j++){
            cout<<"Enter book id of book "<<j+1<<": ";
            cin>>library[i][j];
        }
        cout<<endl;
    }
    char is_search;
    cout<<"Do you want to search a book? (Enter 'y' or 'Y' for yes or else anything for no): ";
    cin>>is_search;
    while(is_search=='Y'||is_search=='y'){
        int id,found=0;
        cout<<"Enter the id of the book hich you want to search: ";
        cin>>id;
        for(int i=0;i<num_cat;i++){
            for(int j=0;j<num_books[i];j++){
                if(library[i][j]==id){
                    found=1;
                    cout<<"Yes the book is available"<<endl;
                    cout<<"Book ID: "<<library[i][j]<<endl;
                    cout<<"Category: "<<category_name[i]<<endl;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        if(!found){
            cout<<"No such book is available in any category that have id "<<id<<endl;
        }
        cout<<"Do you want to search another book? (Enter 'y' or 'Y' for yes or else anything for no): ";
        cin>>is_search;
    }
    return 0;
}