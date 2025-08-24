#include<iostream>
using namespace std;
class BankAccount{
    int *balance;
    public:
        BankAccount(){
            balance=new int(0);
        }
        BankAccount(int b){
            balance=new int(b);
        }
        BankAccount(const BankAccount &obj){
            balance=new int(*obj.balance);
        }
        void deductBalance(int amount){
            if(amount<=*balance){
                *balance=*balance-amount;
                cout<<"Amount deducted successfully"<<endl;
            }
            else{
                cout<<"Insuffucuent Amount"<<endl;
            }
        }
        void printBalance(){
            cout<<"Balance: "<<*balance<<endl;
        }
        ~BankAccount(){
            delete balance;
        }
};
int main(){
    BankAccount account1,account2(1000);
    BankAccount account3=account2;
    cout<<"Checking Account 1 Balance"<<endl;
    account1.printBalance();
    cout<<"\nChecking Account 2 Balance"<<endl;
    account2.printBalance();
    cout<<"\nChecking Account 3 Balance"<<endl;
    account3.printBalance();    
    cout<<"\nDeducting 1100 from Account 3"<<endl;
    account3.deductBalance(1100);    
    cout<<"\nDeducting 200 from Account 3"<<endl;
    account3.deductBalance(200);    
    cout<<"\nChecking Account 2 Balance"<<endl;
    account2.printBalance();
    cout<<"\nChecking Account 3 Balance"<<endl;
    account3.printBalance();     return 0;
}