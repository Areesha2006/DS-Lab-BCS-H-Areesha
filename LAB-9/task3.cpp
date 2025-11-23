#include<iostream>
using namespace std;
class Patient{
    public:
        int severity,height,id;
        Patient *left,*right;
        Patient(int id,int value){
            this->id=id;
            height=1;
            severity=value;
            left=NULL;
            right=NULL;
        }
};
class Hospital{
    Patient* rotate_right(Patient* y){
        Patient *x=y->left;
        Patient *T2=x->right;
        x->right=y;
        y->left=T2;
        y->height=1+((get_height(y->left)>get_height(y->right))? get_height(y->left):get_height(y->right));
        x->height=1+((get_height(x->left)>get_height(x->right))? get_height(x->left):get_height(x->right));
        return x;
    }
    Patient* rotate_left(Patient* x){
        Patient *y=x->right;
        Patient *T2=y->left;
        y->left=x;
        x->right=T2;
        y->height=1+((get_height(y->left)>get_height(y->right))? get_height(y->left):get_height(y->right));
        x->height=1+((get_height(x->left)>get_height(x->right))? get_height(x->left):get_height(x->right));
        return y;
    }
    int get_balance(Patient *node){
        return get_height(node->left)-get_height(node->right);
    }
    public:
        Patient *root;
        Hospital(){
            root=NULL;
        }
        int get_height(Patient *node){
            if(node!=NULL){
                int h_left=get_height(node->left),h_right=get_height(node->right);
                return (h_left>h_right)? h_left+1:h_right+1;
            }
            return 0;
        }
        Patient* insert_patient(Patient *node,int id,int no,bool &balanced){
            if(node==NULL){
                return new Patient(id,no);
            }
            if(no<node->severity){
                node->left=insert_patient(node->left,id,no,balanced);
            }
            else if(no>node->severity){
                node->right=insert_patient(node->right,id,no,balanced);
            }
            else{
                cout<<"Patient with same severity level is not allowed"<<endl;
                return node;
            }
            node->height=1+((get_height(node->left)>get_height(node->right))? get_height(node->left):get_height(node->right));        
            int balance=get_balance(node);
            if(balance>1&&no<node->left->severity){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is left-left case. To resolve it we need to do right rotation"<<endl;
                return rotate_right(node);
            }
            if(balance<-1&&no>node->right->severity){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is right-right case. To resolve it we need to do left rotation"<<endl;
                return rotate_left(node);
            }
            if(balance>1&&no>node->left->severity){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is left-right case. To resolve it we first need to do left rotation and then right rotation is performed"<<endl;
                node->left=rotate_left(node->left);
                return rotate_right(node);
            }
            if(balance<-1&&no<node->right->severity){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is right-left case. To resolve it we first need to do right rotation and then left rotation is performed"<<endl;
                node->right=rotate_right(node->right);
                return rotate_left(node);
            }
            return node;
        }
        Patient* delete_patient(Patient *node,int no,bool &balanced){
            if(node==NULL){
                return node;
            }
            if(no<node->severity){
                node->left=delete_patient(node->left,no,balanced);
            }
            else if(no>node->severity){
                node->right=delete_patient(node->right,no,balanced);
            }
            else{
                if(node->left==NULL||node->right==NULL){
                    Patient *temp=node->left? node->left:node->right;
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
                    Patient *temp=node;
                    while(temp->left!=NULL){
                        temp=temp->left;
                    }
                    node->severity=temp->severity;
                    node->right=delete_patient(node->right,temp->severity,balanced);
                }
            }
            if(node==NULL){
                return node;
            }
            node->height=1+((get_height(node->left)>get_height(node->right))? get_height(node->left):get_height(node->right));        
            int balance=get_balance(node);
            if(balance>1&&get_balance(node->left)>=0){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is left-left case. To resolve it we need to do right rotation"<<endl;
                return rotate_right(node);
            }
            if(balance<-1&&get_balance(node->right)<=0){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is right-right case. To resolve it we need to do left rotation"<<endl;
                return rotate_left(node);
            }
            if(balance>1&&get_balance(node->left)<0){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is left-right case. To resolve it we first need to do left rotation and then right rotation is performed"<<endl;
                node->left=rotate_left(node->left);
                return rotate_right(node);
            }
            if(balance<-1&&get_balance(node->right)>0){
                balanced=false;
                cout<<"Yes the tree becomes unbalance and the unbalance case is right-left case. To resolve it we first need to do right rotation and then left rotation is performed"<<endl;
                node->right=rotate_right(node->right);
                return rotate_left(node);
            }
            return node;
        }
        Patient* highest_severity_patient(){
            Patient *temp=root;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            return temp;
        }
};
int main(){
    Hospital hospital;
    while(true){
        int c;
        cout<<"Enter the appropriate key according too the function you want to perform\n1.Insert a patient\n2.Delete a patient\n3.Find patient with highest severity level\nAny other key to exit\nEnter: ";
        cin>>c;
        if(c==1){
            int id,no;
            bool balanced=true;
            cout<<"Enter patient id: ";
            cin>>id;
            cout<<"Enter patient severity level: ";
            cin>>no;
            hospital.root=hospital.insert_patient(hospital.root,id,no,balanced);
            if(balanced){
                cout<<"Tree is balanced"<<endl;
            }
            cout<<"Height of tree is "<<hospital.get_height(hospital.root)<<endl;
        }
        else if(c==2){
            if(hospital.root==NULL){
                cout<<"Patients not found"<<endl;
            }
            else{
                int no;
                bool balanced=true;
                cout<<"Enter the severity level of the patient who is discharging: ";
                cin>>no;
                hospital.root=hospital.delete_patient(hospital.root,no,balanced);
                if(balanced){
                    cout<<"Tree is balanced"<<endl;
                }
                cout<<"Height of tree is "<<hospital.get_height(hospital.root)<<endl;
            }
        }
        else if(c==3){
            if(hospital.root==NULL){
                cout<<"Patients not found"<<endl;
            }
            else{
                Patient *p=hospital.highest_severity_patient();
                cout<<"Following is the details of patient with highest severity level\n";
                cout<<"Patient ID: "<<p->id<<endl;
                cout<<"Severity Level: "<<p->severity<<endl;
            }
        }
        else{
            cout<<"Exited successfully"<<endl;
            return 0;
        }
        cout<<endl;
    }
}