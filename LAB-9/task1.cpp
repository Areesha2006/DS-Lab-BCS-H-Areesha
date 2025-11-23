#include<iostream>
using namespace std;
class Roll_No{
    public:
        int no;
        Roll_No *left,*right;
        Roll_No(int value){
            no=value;
            left=NULL;
            right=NULL;
        }
};
class University{
    Roll_No* rotate_right(Roll_No* x){
        Roll_No *y=x->left;
        Roll_No *T2=y->right;
        y->right=x;
        x->left=T2;
        return y;
    }
    Roll_No* rotate_left(Roll_No* x){
        Roll_No *y=x->right;
        Roll_No *T2=y->left;
        y->left=x;
        x->right=T2;
        return y;
    }
    public:
        Roll_No *root;
        University(){
            root=NULL;
        }
        int get_height(Roll_No *no){
            if(no!=NULL){
                int h_left=get_height(no->left),h_right=get_height(no->right);
                return (h_left>h_right)? h_left+1:h_right+1;
            }
            return 0;
        }
        int get_balance(Roll_No *no){
            return get_height(no->left)-get_height(no->right);
        }
        Roll_No* insert_roll_no(Roll_No *node,int no){
            if(node==NULL){
                return new Roll_No(no);
            }
            if(no<node->no){
                node->left=insert_roll_no(node->left,no);
            }
            else if(no>node->no){
                node->right=insert_roll_no(node->right,no);
            }
            else{
                cout<<"Duplicate roll no is not allowed"<<endl;
                return node;
            }
            int balance=get_balance(node);
            if(balance>1&&no<node->left->no){
                cout<<"As it is a left-left case, right rotation is performed"<<endl;
                Roll_No *new_roll_no=rotate_right(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            if(balance<-1&&no>node->right->no){
                cout<<"As it is a right-right case, left rotation is performed"<<endl;
                Roll_No *new_roll_no=rotate_left(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            if(balance>1&&no>node->left->no){
                cout<<"As it is a left-right case, first left rotation is performed and then right rotation is performed"<<endl;
                node->left=rotate_left(node->left);
                Roll_No *new_roll_no=rotate_right(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            if(balance<-1&&no<node->right->no){
                cout<<"As it is a right-left case, first right rotation is performed and then left rotation is performed"<<endl;
                node->right=rotate_right(node->right);
                Roll_No *new_roll_no=rotate_left(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            return node;
        }
        Roll_No* delete_roll_no(Roll_No *node,int no){
            if(node==NULL){
                return node;
            }
            if(no<node->no){
                node->left=delete_roll_no(node->left,no);
            }
            else if(no>node->no){
                node->right=delete_roll_no(node->right,no);
            }
            else{
                if(node->left==NULL||node->right==NULL){
                    Roll_No *temp=node->left? node->left:node->right;
                    if(temp==NULL){
                        temp=node;
                        node=NULL;
                    }
                    else{
                        *node=*temp;
                        delete temp;
                    }
                }
                else{
                    Roll_No *temp=node;
                    while(temp->left!=NULL){
                        temp=temp->left;
                    }
                    node->no=temp->no;
                    node->right=delete_roll_no(node->right,temp->no);
                }
            }
            if(node==NULL){
                return node;
            }
            int balance=get_balance(node);
            if(balance>1&&get_balance(node->left)>=0){
                cout<<"As it is a left-left case, right rotation is performed"<<endl;
                Roll_No *new_roll_no=rotate_right(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            if(balance<-1&&get_balance(node->right)<=0){
                cout<<"As it is a right-right case, left rotation is performed"<<endl;
                Roll_No *new_roll_no=rotate_left(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            if(balance>1&&get_balance(node->left)<0){
                cout<<"As it is a left-right case, first left rotation is performed and then right rotation is performed"<<endl;
                node->left=rotate_left(node->left);
                Roll_No *new_roll_no=rotate_right(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            if(balance<-1&&get_balance(node->right)>0){
                cout<<"As it is a right-left case, first right rotation is performed and then left rotation is performed"<<endl;
                node->right=rotate_right(node->right);
                Roll_No *new_roll_no=rotate_left(node);
                cout<<"New balance factor if the affected roll no "<<node->no<<" is "<<get_balance(new_roll_no)<<endl;
                return new_roll_no;
            }
            return node;
        }
};
int main(){
    University uni;
    cout<<"Inserting roll no 5"<<endl;
    uni.root=uni.insert_roll_no(uni.root,5);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 4"<<endl;
    uni.root=uni.insert_roll_no(uni.root,4);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 6"<<endl;
    uni.root=uni.insert_roll_no(uni.root,6);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 2"<<endl;
    uni.root=uni.insert_roll_no(uni.root,2);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 1"<<endl;
    uni.root=uni.insert_roll_no(uni.root,1);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 3"<<endl;
    uni.root=uni.insert_roll_no(uni.root,3);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 7"<<endl;
    uni.root=uni.insert_roll_no(uni.root,7);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 9"<<endl;
    uni.root=uni.insert_roll_no(uni.root,9);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nInserting roll no 8"<<endl;
    uni.root=uni.insert_roll_no(uni.root,8);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nDeleting roll no 4"<<endl;
    uni.root=uni.delete_roll_no(uni.root,4);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nDeleting roll no 8"<<endl;
    uni.root=uni.delete_roll_no(uni.root,8);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nDeleting roll no 5"<<endl;
    uni.root=uni.delete_roll_no(uni.root,5);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;

    cout<<"\nDeleting roll no 2"<<endl;
    uni.root=uni.delete_roll_no(uni.root,2);
    cout<<"Height of tree is "<<uni.get_height(uni.root)<<endl;
    return 0;
}