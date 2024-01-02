
#include <iostream> // header file for input output stream
#include"Dresses.h"//   Dresses class header file is included 
#include"Customer.h"// Customer class header file is included
#include"Payment.h"//  Payment class header file is include
using namespace std;


int main()  // The main function where the program execution begins
{
    int choice;// Declare a variable 'choice' to store the user's input
    while (true) // Start an infinite loop to keep the program running until explicitly exited
    {
        // Display a header for the Boutique Management System

        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "************************************************************ BOUTIQUE MANAGEMENT SYSTEM ************************************************************" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        // Display menu options for the user to choose from

        cout << "1. DRESSES " << endl;
        cout << "2. CUSTOMER " << endl;
        cout << "3. BILL PAYMENT" << endl;
        cout << "4. Exit " << endl;
        //choice is taken from the user
        cout << "Enter your choice: ";
        cin >> choice;//user enter choice

        switch (choice) //switch statements is used to handle the user choice
        {
        case 1:

            DressesMenu();// If user chooses Dresses, go to DressesMenu function

            break;

        case 2:

            CustomerMenu(); // If user chooses Customer, go to CustomerMenu function

            break;

        case 3:

            BillPaymentMenu(); // If user chooses Bill Payment, go to BillPaymentMenu function
            break;

            break;


        case 4:
            exit(0);// If user chooses Exit, exit the program
        default:
            cout << "Invalid choice!\n Enter a valid choice" << endl;// Display an error message for invalid choices
            break;
        }

    }
    return 0; // Return 0 to indicate successful program execution

}
