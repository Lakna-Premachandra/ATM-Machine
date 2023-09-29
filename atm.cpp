#include <iostream>
#include <string>

using namespace std;

int amount = 100000; //Global variable
int pin = 1234; //Default pin // You can change the pin

void interface();
int login();
void balance();
void withdrawal();
void deposit();
void billPayment();
void moneyTransfer();
void needHelp();
void changePIN(); 

void balance()//Function for check balance
{   
    cout << "----------------------------------------" << endl;
    cout << "        Account Balance Inquiry         " << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Your Account Balance: $ " << amount << endl;
    cout << "----------------------------------------" << endl;
    
    string confirm;
    cout << "Do you want to go back to the main menu? (Y/N): ";
    cin >> confirm;
    cout << endl;

    if (confirm == "y" || confirm == "Y") {
        interface();
        
    } else {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us.    "<< endl;
    cout << "             Have anice day.            "<< endl;
    cout << "----------------------------------------" << endl;
        
    }
}

void withdrawal()
{
    int wAmount; // Function for money withdrawal
    int option;
    string confirm;
    string recipt;

    cout << "Enter the account type" << endl;
    cout << "1. Current Account" << endl;
    cout << "2. Saving account" << endl << endl;
    cout << "Choose your Option : ";
    cin >> option;
    cout << "Enter amount : ";
    cin >> wAmount;
    cout << "Do you want to confirm " << wAmount << " ? (Y/N)";
    cin >> confirm;

    while (confirm == "n")
    {
        cout << "Enter Amount: ";
        cin >> wAmount;
        cout << endl;
        cout << "Do you want to confirm " << wAmount << " ? (Y/N) ";
        cin >> confirm;
        cout << endl;
    }
    if (amount >= wAmount)
    {
        amount = amount - wAmount;
        cout << "Do you need a Receipt (Y/N) : ";
        cin >> recipt;
        cout << endl;
        if (recipt == "y")
        { 
        cout << "----------------------------------------" << endl;
        cout << "           Withdrawal Receipt           " << endl;
        cout << "----------------------------------------" << endl;
        cout << "           Withdrawal Amount: $ " << wAmount << endl;
        cout << "           Remaining Balance: $ " << amount << endl;
        cout << "----------------------------------------" << endl;
        }
        cout << endl;
        cout << "Withdrawal Successful." << endl <<endl;
        
        // Go back to the interface
        cout << "Do you want to go back to the main menu? (Y/N): ";
        cin >> confirm;
        cout << endl;
        if (confirm == "y" || confirm == "Y")
        {
            interface();
            
        }
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us.    "<< endl;
    cout << "             Have anice day.            "<< endl;
    cout << "----------------------------------------" << endl;

    
}

void deposit()
{
    int dAmount; //Function for deposit money 
    string confirm;
    string recipt;
    
    cout << "Enter the deposit amount: $";
    cin >> dAmount;
    cout << "Do you want to confirm " << dAmount << " ? (Y/N)";
    cin >> confirm;

while (confirm == "n")
    {
        cout << "Enter Amount: ";
        cin >> dAmount;
        cout << endl;
        cout << "Do you want to confirm " << dAmount << " ? (Y/N) ";
        cin >> confirm;
        cout << endl;
    }

 if ((dAmount > 0))
    {
        amount = amount + dAmount;
        cout << "Do you need a Receipt (Y/N) : ";
        cin >> recipt;
        cout << endl;
        if (recipt == "y")
        { 
    cout << "----------------------------------------" << endl;
    cout << "           Deposit Receipt              " << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Deposit Amount: $ " << dAmount << endl;
    cout << "          Updated Balance: $ " << amount << endl;
    cout << "----------------------------------------" << endl;
        }
        cout << endl;
        cout << "Deposit Successful." << endl <<endl;

    // Go back to the main menu
    cout << "Do you want to go back to the main menu? (Y/N): ";
    cin >> confirm;
    if (confirm == "y" || confirm == "Y") {
        interface();
        
    }
    else {
       
    
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us.    "<< endl;
    cout << "             Have anice day.            "<< endl;
    cout << "----------------------------------------" << endl;

    }
    }
}

void billPayment() // Function for bill payment
{
    string billType;
    int billAmount;
    string confirm;
    string receiptConfirm;

    cout << "Select the type of bill to pay:" << endl;
    cout << "1. Electricity" << endl;
    cout << "2. Water" << endl;
    cout << "3. Telephone" << endl;
    cout << "4. Insurance" << endl;
    cout << "5. Back to main menu" << endl;
    cout << "Enter your choice: ";
    
    int billChoice;
    cin >> billChoice;

    switch (billChoice)
    {
        case 1:
            billType = "Electricity";
            break;
        case 2:
            billType = "Water";
            break;
        case 3:
            billType = "Telephone";
            break;
        case 4:
            billType = "Insurance";
            break;
        case 5:
            interface();
            
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            
    }

    cout << "Enter the bill amount: $";
    cin >> billAmount;
    cout << "Do you want to confirm the payment of $" << billAmount << " for " << billType << "? (Y/N)";
    cin >> confirm;

    if (confirm == "Y" || confirm == "y")
    {
        if (amount >= billAmount)
        {
            amount -= billAmount;
            cout << "Payment of $" << billAmount << " for " << billType << " successful." << endl;

            // Print receipt
            cout << "Do you want a receipt for this transaction? (Y/N): ";
            cin >> receiptConfirm;

            if (receiptConfirm == "Y" || receiptConfirm == "y")
            {
                cout << "----------------------------------------" << endl;
                cout << "           Bill Payment Receipt          " << endl;
                cout << "----------------------------------------" << endl;
                cout << "           Bill Type: "  << billType << endl; 
                cout << "           Bill Amount: $ " << billAmount << endl;
                cout << "           Remaining Balance: $ " << amount << endl;
                cout << "----------------------------------------" << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "Insufficient balance for bill payment." << endl;
        }
    }
    else
    {
        cout << "Bill payment canceled." << endl;
    }

    // Go back to the main menu
    cout << "Do you want to go back to the main menu? (Y/N): ";
    cin >> confirm;
    if (confirm == "Y" || confirm == "y")
    {
        interface();
        
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us.    "<< endl;
    cout << "             Have anice day.            "<< endl;
    cout << "----------------------------------------" << endl;
   
}

void moneyTransfer() // Function for fund transfer
{
    string recipientAccount;
    int transferAmount;
    string confirm;
    string receiptConfirm;

    cout << "Enter recipient's account number: ";
    cin >> recipientAccount;

    cout << "Enter the amount to transfer: $";
    cin >> transferAmount;

    cout << "Do you want to confirm the transfer of $" << transferAmount << " to account " << recipientAccount << "? (Y/N)";
    cin >> confirm;

    if (confirm == "Y" || confirm == "y")
    {
        if (amount >= transferAmount)
        {
            amount -= transferAmount;
            cout << "Transfer of $" << transferAmount << " to account " << recipientAccount << " successful." << endl;

            // Print receipt
            cout << "Do you want a receipt for this transaction? (Y/N): ";
            cin >> receiptConfirm;

            if (receiptConfirm == "Y" || receiptConfirm == "y")
            {
                cout << "----------------------------------------" << endl;
                cout << "           Money Transfer Receipt        " << endl;
                cout << "----------------------------------------" << endl;
                cout << "           Recipient's Account: " << recipientAccount << endl;
                cout << "           Transfer Amount: $ " << transferAmount << endl;
                cout << "           Remaining Balance: $ " << amount << endl;
                cout << "----------------------------------------" << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "Insufficient balance for the transfer." << endl;
        }
    }
    else
    {
        cout << "Transfer canceled." << endl;
    }

    // Go back to the main menu
    cout << "Do you want to go back to the main menu? (Y/N): ";
    cin >> confirm;
    if (confirm == "Y" || confirm == "y")
    {
        interface();
        
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us.    "<< endl;
    cout << "             Have anice day.            "<< endl;
    cout << "----------------------------------------" << endl;
    
    
}

void needHelp() // Function for contact us
{
    cout << "----------------------------------------" << endl;
    cout << "              Need Help                 " << endl;
    cout << "----------------------------------------" << endl;
    cout << "If you require any assistance or have questions, please contact our customer support:" << endl;
    cout << "Phone: 1-800-123-4567" << endl;
    cout << "Email: support@abcbank.com" << endl;
    cout << "Visit our website: www.abcbank.com/support" << endl;
    cout << "----------------------------------------" << endl;

    // Go back to the main menu
    string confirm;
    cout << "Do you want to go back to the main menu? (Y/N): ";
    cin >> confirm;
    
    if (confirm == "Y" || confirm == "y")
    {
        interface();
        
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us.    "<< endl;
    cout << "             Have anice day.            "<< endl;
    cout << "----------------------------------------" << endl;
    
}

void changePIN() // Function for change pin
{
    int newPIN;
    cout << "Enter your new PIN: ";
    cin >> newPIN;

    pin = newPIN; // Update the PIN
    cout << "PIN changed successfully!" << endl;

    //Go back to the main menu
    string confirm;
    cout << "Do you want to go back to the main menu? (Y/N): ";
    cin >> confirm;
    
    if (confirm == "Y" || confirm == "y")
    {
        interface();
        
    }

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us.    "<< endl;
    cout << "             Have anice day.            "<< endl;
    cout << "----------------------------------------" << endl;
}

int login() // Function for login
{
    int defaultpin;

    for (int attempts = 1; attempts <= 3; attempts++)
    {
        cout << "Enter your PIN: ";
        cin >> defaultpin;
        cout << endl;
        if (defaultpin == pin)
        {
            interface(); // Successful login, proceed to the main menu
            return 0;
        }
        else
        {
            cout << endl;
            cout << "Invalid Pin. Please try again." << endl;
        }
    }

    cout << endl;
    cout << "Maximum amount of chances are exceeded." << endl;
    exit(0); // Exit the program

    return 0;
}

void interface() // Function for main interface
{
    int mainOption;
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Welcome to ABC Bank          " << endl;
    cout << "----------------------------------------" << endl << endl;

    cout << "1. Cash withdrawal" << endl;
    cout << "2. Balance Enquiry " << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Bill Payment" << endl;
    cout << "5. Money Transfer" << endl;
    cout << "6. Change PIN" << endl;
    cout << "7. Need Help" << endl;
    cout << "8. Back" << endl;
    cout << "9. Exit" << endl <<endl;

    cout << "Which Service would you like to Use? Enter your option."  << endl;

    cin >> mainOption;
    cout << endl;

    if (mainOption == 1)
    {
        withdrawal();
    }
    else if (mainOption == 2)
    {
        balance();
    }
    else if (mainOption == 3)
    {
         deposit();
    }
    else if (mainOption == 4)
    { 
        billPayment();
    }
    else if (mainOption == 5)
    {
        moneyTransfer();
    }
    else if (mainOption == 6)
    {
        changePIN();
    }
    else if (mainOption == 7)
    {
        needHelp();
    }
    else if (mainOption == 8)
    {
        login();
    }
    else if (mainOption ==9)
    {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "      Thank You for Banking with us."     << endl;
    cout << "             Have anice day."             << endl;
    cout << "----------------------------------------" << endl;
        
        
        exit(0);
    }
    else
    {
        cout << endl;
        cout << "Wrong option. Try Again." << endl;
    }
}


int main() // Main function 
{
	login();
	return 0;
}
