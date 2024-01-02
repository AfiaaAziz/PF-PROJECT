#pragma once
#include <iostream> // header file for input output stream
#include <fstream> // header file for file streams
#include <iomanip> // header file for setw.
#include"Dresses.h"// Include the header file for Dresses structure
#include"Customer.h"// Include the header file for Customer structure


using namespace std;

const int max_BillPayment = 10; // Maximum number of bill payments (rows)

// Define a structure for BillPayment

struct BillPayment
{

    string ID;
    Dresses Dress;// Nested structure Dress
    Customer Customer;// Nested structure Customer
    double Amount;

};

void BillPaymentMenu(); // Function for bill payment menu
void addBillPayment(BillPayment payment[], Dresses dress[], Customer customer[], int& numPayment, int& numDresses, int& numCustomers);

void viewBillPayment(const BillPayment payment[], int numPayment); // Function to view bill payment details
void searchBillPayment(const BillPayment payment[], int numPayment);// Function to search for a bill payment
void BillPaymentToFile(const BillPayment payment[], int numPayment); // Function to add bill payment details to files
void BillPaymentloadFromFile(BillPayment payment[], int& numPayment); // Function to load bill payment details from files


// Function to manage bill payment menu

void BillPaymentMenu()
{
    BillPayment payment[max_BillPayment];// Array of structures to store bill payment data
    Dresses dress[max_dresses];// Array of structures to store dress data
    Customer customers[max_customers];// Array of structures to store customer data
    int numPayment = 0; // Variable to keep track of the number of bill payments
    int numDresses = 0;// Variable to keep track of the number of dresses
    int numCustomers = 0;// Variable to keep track of the number of customers

    BillPaymentloadFromFile(payment, numPayment); // Load bill payment data from file
    DressesLoadFromFile( dress, numDresses);// Load dress data from file
    CustomersloadFromFile( customers, numCustomers);// Load customer data from file


    int choice;//variable is declared to handle the user's choices
    
    // Display the bill payment menu options

    while (true)
    {
        cout << "******BILL PAYMENT*******" << endl;

        cout << "1. Add Bill Payment " << endl;
        cout << "2. View Bill Payment " << endl;
        cout << "3. Search Bill Payment" << endl;

        cout << "4. Back to Main Menu " << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "Enter your choice: ";//prompts the user to enter choice 

        cin >> choice;//the user enter the choice from the above menu

        //switch statements is used to handle the user choice
        switch (choice)
        {//start of switch brackets
        case 1://case 1 where add customer function is called
            addBillPayment(payment,dress,customers, numPayment,numDresses,numCustomers);

            break;
        case 2://case 2 where view customer function is called
            viewBillPayment(payment, numPayment);
            break;
        case 3://case 3 where  search customer function is called
            searchBillPayment(payment, numPayment);
            break;

        case 4://case 6 if the user enter 6 it return to the main menu
            return;
        default://default case invalid choice.
            cout << "Invalid choice!\n Enter a valid choice" << endl;
            break;
        }
        if (choice == 4)
        {
            break;  // Exit the loop if the user chooses to go back to the main menu
        }
    }
}

// Function to add a bill payment


void addBillPayment(BillPayment payment[], Dresses dress[], Customer customer[], int& numPayment, int& numDresses, int& numCustomers)
{
    string dress_ID;
    string customer_ID;
    bool dressFound = false;
    bool customerFound = false;


    // Check if there is space for a new bill payment

    if (numPayment < max_BillPayment)
    {
        cout << "---------------------------" << endl;
        cout << " Enter Payment " << numPayment + 1 << " details: " << endl;
        cout << "---------------------------" << endl;

        cout << " Enter Bill ID: ";
        cin >> payment[numPayment].ID; //Read and store bill ID

        // Dress ID input and validation
        cout << " Enter Dress ID: ";
        cin >> dress_ID;

        // Search for the Dress ID in the Dresses array
        for (int i = 0; i < numDresses; i++)
        {
            if (dress_ID == dress[i].ID)
            {
                dressFound = true;
                // Linking the Dress entity with the BillPayment entity

                payment[numPayment].Dress= dress[i];
                cout << "Dress Record Found:" << endl;
                cout << "ID: " << dress[i].ID << endl;
                cout << "Name: " << dress[i].Name << endl;
                cout << "Type: " << dress[i].Type << endl;
                cout << "Price: " << dress[i].Price << endl;
                break;  // Exit the loop if the dress is found
            }
        }

        if (!dressFound)
        {
            cout << "Dress ID " << dress_ID << " not found. Payment not added." << endl;
        }


        // Customer ID input and validation
        cout << " Enter Customer's ID: ";
        cin >> customer_ID;

        // Search for the Customer ID in the Customer array
        for (int i = 0; i < numCustomers; i++)
        {
            if (customer_ID == customer[i].ID)
            {
                customerFound = true;
                // Linking the Customer entity with the BillPayment entity

                payment[numPayment].Customer= customer[i];
                cout << "Customer Record Found:" << endl;
                cout << "ID: " << customer[i].ID << endl;
                cout << "Name: " << customer[i].Name << endl;
                cout << "Total Purchase: " << customer[i].TotalPurchases << endl;
                cout << "Email: " << customer[i].Email << endl;
                break;  // Exit the loop if the customer is found
            }
        }

        if (!customerFound)
        {
            cout << "Customer ID " << customer_ID << " not found. Payment not added." << endl;
            
        }


        if (dressFound && customerFound)
        {
            cout << " Enter Total Amount: ";
            cin >> payment[numPayment].Amount;

            numPayment++;
            BillPaymentToFile(payment, numPayment);
            cout << " Payment added successfully.\n";
        }
    }
    else
    {
        cout << "Maximum number of Payments reached." << endl;
    }
}



//function to view the customer details

void viewBillPayment(const BillPayment payment[], int numPayment)

{
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << " Bill ID " << setw(15) << " Dress ID " << setw(25) << " Customer's ID " << setw(20) << " Total Amount " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    // Loop iterates through each bill payment, printing Bill ID, Dress ID, Customer's ID, and Total Amount.

    for (int i = 0; i < numPayment; i++)
    {//starting of for loop brackets.

    // Printing each attribute of the bill payment.

        cout << payment[i].ID << setw(15) << payment[i].Dress.ID << setw(20) << payment[i].Customer.ID << setw(30) << payment[i].Amount << endl;
    }//ending of for loop brackets

}


// Function to search for a bill payment by ID in an array of 'BillPayment'

void searchBillPayment(const BillPayment payment[], int numPayment)
{
    string search_id; // Variable to store the Bill ID to be searched

    cout << "---------------------------------------------" << endl;
        // Prompt the user to enter the ID of the bill payment to be searched

    cout << "Enter the Bill ID you want to search: ";
    cin >> search_id;

    bool found = false; // Boolean flag to indicate whether the bill payment is found or not


    for (int i = 0; i < numPayment; i++) // Loop through each bill payment in the array
    {
        if (payment[i].ID == search_id)  // Check if the current bill payment's ID matches the search ID
        {

            found = true;  // Set the 'found' flag to true

            cout << "---------------" << endl;
             // Display bill payment information including Bill ID, Dress ID, Customer's ID, and Total Amount

            cout << " Payment Found:" << endl;
            cout << "---------------" << endl;
            cout << " Bill ID : " << payment[i].ID << endl;
            cout << " Dress ID : " << payment[i].Dress.ID << endl;
            cout << " Customer's ID : " << payment[i].Customer.ID << endl;
            cout << " Total Amount : " << payment[i].Amount << endl;
        }
    }
    
        // Check if the bill payment was not found and display a message.

    if (!found)
    {
        cout << " Bill with ID " << search_id << " not found." << endl;
    }
}


// Function to add bill payment details to a file

void BillPaymentToFile(const BillPayment payment[], int numPayment)

{
    ofstream fout("payment.txt");// Open a file named "payment.txt" for writing

    // Loop iterates through each bill payment, printing Bill ID, Dress ID, Customer's ID, and Total Amount.

    for (int i = 0; i < numPayment; i++)
    {
        fout << payment[i].ID << setw(15) << payment[i].Dress.ID << setw(20) << payment[i].Customer.ID << setw(30) << payment[i].Amount << endl;
    }//ending of for loop brackets


    fout.close();// Close the file

}



// Function to load bill payment details from a file

void BillPaymentloadFromFile(BillPayment payment[], int& numPayment)
{
    try
    {
        ifstream fin("payment.txt");   // Open a file named "payment.txt" for reading

        if (fin.fail())// Check if reading from the file fails
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }

        numPayment = 0;    // Initialize the total number of bill payments to 0

        // Read bill payment details from the file until the end of the file is reached

        while (fin >> payment[numPayment].ID >> payment[numPayment].Dress.ID >> payment[numPayment].Customer.ID >> payment[numPayment].Amount)
        {
            numPayment++;  // Increment the total number of bill payments

        }

        fin.close();    // Close the file that is opened
    }
    catch (runtime_error& e)// Catch and handle runtime error if file operation fails
    {
        cout << "Error" << e.what() << endl; //  display the error
        return;
    }

}























