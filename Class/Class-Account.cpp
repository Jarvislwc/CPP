#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
private:
    string accountHolderName;
    double balance;
public:
    Account(string name,double balance): accountHolderName(name),balance(balance){}
    void deposite(double amount);
    void withdraw(double amount);
    void checkBalance();
    string getAccoutntHoldname();
    int getbalance();
    
};
void Account::deposite(double numberofDep){
    if(numberofDep > 0){ // 先看欲存入金額是否大於0
        balance += numberofDep;
        cout << "Deposite : " << balance << endl;
    }
    else{
        cout << "please enter the valid name again." << endl;
    }
}

void Account::withdraw(double numberofWith){
    if(numberofWith > 0 && balance >= numberofWith)
    {
        cout << "withdraw success"<< endl;    
        balance -= numberofWith;
    }
    else if (balance < numberofWith)
    {
        cout << "insufficient balance." << endl;    
    }
    else
    {
        cout << "Invalid amount." << endl;
    }
}
void Account::checkBalance(){
    cout << "Your deposite:" << balance << endl;
}

string Account::getAccoutntHoldname(){
    return accountHolderName;
}

int Account::getbalance()
{
    return balance;
}


class Saving_Account : public Account
{
private:
    double interestRate;
public:
    Saving_Account(string name, double initialBalance, double rate) : Account(name, initialBalance), interestRate(rate) {}
    void addInterest();
};


void Saving_Account::addInterest(){
    // calculate formula
    // deposite += 0.03 * 12(month) *deposite 
    double interest = getbalance() * interestRate * 12;
    cout << interest << endl;
    deposite(interest);
}

int main() {
    Account Account_Jar("JarvisLee",0);
    Account_Jar.deposite(5000);
    Account_Jar.withdraw(3000);
    Account_Jar.checkBalance();
    cout << "Create new saving account" << endl;

    // ====新增儲蓄帳戶 ======
    Saving_Account SAccont("GarvisLee",5000,0.3);
    SAccont.checkBalance();
    SAccont.addInterest();
    SAccont.checkBalance();
    return 0;
}
