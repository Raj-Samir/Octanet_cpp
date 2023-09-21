#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

/*mini Project - ATM
    -> Check Balance
    -> Cash Withdraw
    -> Cash Deposit
    -> User Details
    -> Update Mobile No.
*/
class atm
{
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
    {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    long int getAccountNo()
    {
        return account_No;
    }

    string getName()
    {
        return name;
    }

    int getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobileNo()
    {
        return mobile_No;
    }

    void setMobile(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No)
        {
            mobile_No = mob_new;
            cout << endl << "SUCCESSFULLY UPDATED MOBILE NUMBER";
            getch();
        }

        else
        {
            cout << endl << "Incorrect !!  Old Mobile Number";
            getch();
        }
    }

    void cashWithDraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance)
        {
            balance = balance - amount_a;
            cout << endl << "please collect your cash";
            cout << endl << "available balance: " << balance;
            getch();
        }

        else
        {
            cout << endl << "Invalid or Insufficient balance";
            getch();
        }
    }

    void cashDeposit(int amount_a)
    {
        balance = balance + amount_a;
        cout << endl << "Amount Deposited Successfully !!";
        cout << endl << "available balance: " << balance;
        getch();
    }
};

int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNo;
    system("cls");

    atm user1;
    user1.setData(1234567890, "Samir", 6328, 58000, "9898989898");

    do
    {
        system("cls");
        cout << endl << "*****Welcome to ATM*****" << endl;
        cout << endl << "Enter your account number ";
        cin >> enterAccountNo;

        cout << endl << "Enter PIN: ";
        cin >> enterPIN;

        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;
                system("cls");

                cout << endl << "****Welcome to ATM****" << endl;
                cout << endl << "Select options ";
                cout << endl << "1. Check Balance";
                cout << endl << "2. Cash Withdraw";
                cout << endl << "3. Amount Deposit";
                cout << endl << "4. Show User Details";
                cout << endl << "5. Update Mobile no.";
                cout << endl << "6. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << endl << "Your bank balance is : " << user1.getBalance();
                    getch();
                    break;

                case 2:
                    cout << endl << "enter the amount : ";
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    break;

                case 3:
                    cout << endl << "enter the amount : ";
                    cin >> amount;
                    user1.cashDeposit(amount);
                    break;

                case 4:
                    cout << endl << "***User Details are:- ";
                    cout << endl << "-> Account no " << user1.getAccountNo();
                    cout << endl << "-> Name " << user1.getName();
                    cout << endl << "-> Balance " << user1.getBalance();
                    cout << endl << "-> Mobile No. " << user1.getMobileNo();
                    getch();
                    break;

                case 5:
                    cout << endl << "Enter old Mobile No. : ";
                    cin >> oldMobileNo;

                    cout << endl << "Enter new Mobile No. : ";
                    cin >> newMobileNo;

                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                case 6:
                    exit(0);

                default:
                    cout << endl << "Enter Valid Choice!!!" << endl;
                    exit(0);
                }
            } while (1);
        }

        else
        {
            cout << endl << "user details are invalid !!!";
            getch();
        }

    } while (1);

    return 0;
}