#include<iostream>
using namespace std;
struct Song{
    int playCount;
    string name;
    Song *left,*right;
    Song(string n,int count){
        playCount=count;
        name=n;
        left=right=NULL;
    }
};
Song* create_new_song(string name,int count){
    return new Song(name,count);
}
Song* insert_song(Song *root,string name,int count){
    if(root==NULL){
        return create_new_song(name,count);
    }
    if(count<root->playCount){
        root->left=insert_song(root->left,name,count);
    }
    if(count>root->playCount){
        root->right=insert_song(root->right,name,count);
    }
    return root;
}
int search_song(Song *root,int count){
    if(!root){
        return -1;
    }
    if(root->playCount==count){
        cout<<"Song Found"<<endl;
        cout<<"Song Name: "<<root->name<<endl;
        cout<<"Play Count: "<<root->playCount<<endl;
        return 1;
    }
    if(count<root->playCount){
        if(search_song(root->left,count)){
            return 1;
        }
        return 0;
    }
    if(count>root->playCount){
        if(search_song(root->right,count)){
            return 1;
        }
        return 0;
    }
}
void inorder(Song *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->name<<" with playcount "<<root->playCount<<endl;
    inorder(root->right);
}
void postorder(Song *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->name<<" with playcount "<<root->playCount<<endl;    
}
Song* delete_song(Song *root,int count){
    if(root==NULL){
        return root;
    }
    else if(count<root->playCount){
        root->left=delete_song(root->left,count);
    }
    else if(count>root->playCount){
        root->right=delete_song(root->right,count);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL&&root->right!=NULL){
            Song *temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->name=temp->name;
            root->playCount=temp->playCount;
            root->right=delete_song(root->right,temp->playCount);
        }
        else if(root->left==NULL){
            Song *temp=root->right;
            delete root;
            return temp;
        }
        else{
            Song *temp=root->left;
            delete root;
            return temp;
        }
    }
    return root;
}
int main(){
    Song *root=NULL;
    string name;
    int count,c;
    while(1){
        cout<<"Enter the appropriate key according to the function you want to perform\n1.Insert Song\n2.Search Song\n3.Display songs inorder\n4.Display songs postorder\n5.Delete a song\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter song name: ";
                cin>>name;
                cout<<"Enter play count (Play count of all songs must be unique else the song will not be added): ";
                cin>>count;
                root=insert_song(root,name,count);
                break;
            case 2:
                cout<<"Enter play count: ";
                cin>>count;
                if(search_song(root,count)==0){
                    cout<<"Song not found"<<endl;
                }
                else{
                    if(search_song(root,count)==-1){
                        cout<<"Playlist is empty"<<endl;
                    }
                }
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                cout<<"Enter play count: ";
                cin>>count;
                if(search_song(root,count)==1){
                    root=delete_song(root,count);
                    cout<<"Updated BST"<<endl;
                    cout<<"Inorder Traversal"<<endl;
                    inorder(root);
                    cout<<"\nPostorder Traversal"<<endl;
                    postorder(root);
                }
                else if(search_song(root,count)==-1){
                    cout<<"Playlist is empty"<<endl;
                }
                else{
                    cout<<"Song not found"<<endl;
                }        
                break;
            default:
                cout<<"Exited successfully"<<endl;
                return 0;
        }
        cout<<endl;
    }
}