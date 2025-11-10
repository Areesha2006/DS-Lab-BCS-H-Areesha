#include<iostream>
using namespace std;
struct Person{
    string name;
    Person *mother,*father;
    Person(string n){
        name=n;
        mother=NULL;
        father=NULL;
    }
};
class FamilyTree{
    public:
        Person *root;
        FamilyTree(){
            root=NULL;
        }
        void display_root(){
            if(root==NULL){
                cout<<"Tree is empty"<<endl;
            }
            else{
                cout<<"Root (youngest) person name: "<<root->name<<endl;
            }
        }
        void display_leaf(Person *root){
            if(!root){
                cout<<"Tree is empty"<<endl;
                return;
            }
            if(root->father==NULL&&root->mother==NULL){
                cout<<root->name<<" is a leaf node"<<endl;
                return;
            }
            display_leaf(root->mother);
            display_leaf(root->father);
        }
        int height(Person *root){
            if(!root){
                return 0;
            }
            int h_mother=height(root->mother),h_father=height(root->father);
            return (h_mother>h_father)? h_mother+1:h_father+1;
        }
        void display_level(Person *node,int level=0){
            if(!node){
                return;
            }
            cout<<node->name<<" is at level "<<level<<endl;
            display_level(node->mother,level+1);
            display_level(node->father,level+1);
        }
};
int main(){
//        The tree is like
//            Child
//            /   \
//        Mother  Father
//         /  \    /  \
//        MGM MGF PGM PGF
//  MGM=Maternal Grandmother MGF=Maternal Grandfather 
//  PGM=Paternal Grandmother PGF=Paternal Grandfather
    FamilyTree family;
    Person *child=new Person("Child");
    Person *mother=new Person("Mother");
    Person *father=new Person("Father");
    Person *mgm=new Person("Maternal Grandmoher");
    Person *mgf=new Person("Maternal Grandfather");
    Person *pgm=new Person("Paternal Grandmother");
    Person *pgf=new Person("Paternal Grandfather");
    family.root=child;
    child->mother=mother;
    child->father=father;
    mother->mother=mgm;
    mother->father=mgf;
    father->mother=pgm;
    father->father=pgf;
    cout<<"==========Welcome to like Ancestry.com=========="<<endl;
    family.display_root();
    cout<<endl;
    family.display_leaf(family.root);
    cout<<endl;
    cout<<"Height of the tree: "<<family.height(family.root)<<endl;
    cout<<endl;
    family.display_level(family.root);
    return 0;
}