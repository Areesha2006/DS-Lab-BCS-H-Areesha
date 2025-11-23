#include<iostream>
using namespace std;
class Product{
    public:
        int price,height;
        Product *left,*right;
        Product(int value){
            height=1;
            price=value;
            left=NULL;
            right=NULL;
        }
};
int get_height(Product *product){
    if(product!=NULL){
        int h_left=get_height(product->left),h_right=get_height(product->right);
        return (h_left>h_right)? h_left+1:h_right+1;
    }
    return 0;
}
Product* rotate_right(Product* x){
    Product *y=x->left;
    Product *T2=y->right;
    y->right=x;
    x->left=T2;
    y->height=1+((get_height(y->left)>get_height(y->right))? get_height(y->left):get_height(y->right));
    x->height=1+((get_height(x->left)>get_height(x->right))? get_height(x->left):get_height(x->right));
    return y;
}
Product* rotate_left(Product* x){
    Product *y=x->right;
    Product *T2=y->left;
    y->left=x;
    x->right=T2;
    y->height=1+((get_height(y->left)>get_height(y->right))? get_height(y->left):get_height(y->right));
    x->height=1+((get_height(x->left)>get_height(x->right))? get_height(x->left):get_height(x->right));
    return y;
}
int get_balance(Product *product){
    return get_height(product->left)-get_height(product->right);
}
Product* insert_price(Product *root,int price){
    if(root==NULL){
        return new Product(price);
    }
    if(price<root->price){
        root->left=insert_price(root->left,price);
    }
    else if(price>root->price){
        root->right=insert_price(root->right,price);
    }
    else{
        cout<<"Duplicate price is not allowed"<<endl;
        return root;
    }
    root->height=1+((get_height(root->left)>get_height(root->right))? get_height(root->left):get_height(root->right));
    int balance=get_balance(root);
    if(balance>1&&price<root->left->price){
        return rotate_right(root);
    }
    if(balance<-1&&price>root->right->price){
        return rotate_left(root);
    }
    if(balance>1&&price>root->left->price){
        root->left=rotate_left(root->left);
        return rotate_right(root);
    }
    if(balance<-1&&price<root->right->price){
        root->right=rotate_right(root->right);
        return rotate_left(root);
    }
    return root;
}
void range_query(Product *root,int X,int Y){
    if(root==NULL){
        return;
    }
    if(root->price>X){
        range_query(root->left,X,Y);
    }
    if(root->price>=X&&root->price<=Y){
        cout<<root->price<<" ";
    }
    if(root->price<Y){
        range_query(root->right,X,Y);
    }
}
int main(){
    int c;
    Product *root=NULL;
    while(true){
        cout<<"Enter the appropriate key according to the function you want to perform\n1.Insert a price\n2.Range Query\nAny other key to exit\nEnter: ";
        cin>>c;
        if(c==1){
            int price;
            cout<<"Enter the price of the product: ";
            cin>>price;
            root=insert_price(root,price);
        }
        else if(c==2){
            if(root!=NULL){
                int X,Y;
                cout<<"Enter lower limit: ";
                cin>>X;
                cout<<"Enter upper limit: ";
                cin>>Y;
                range_query(root,X,Y);
                cout<<endl;
            }
            else{
                cout<<"No price found"<<endl;
            }
        }
        else{
            cout<<"Exited successfully"<<endl;
            return 0;
        }
        cout<<endl;
    }
}