#pragma once

#include <iostream> // header file for input output stream
#include <fstream> // header file for file streams
#include <iomanip> // header file for setw.

using namespace std;
const int max_customers = 10; // Maximum number of customers (rows)


// Structure to represent a Customer
struct Customer
{
    string ID;
    string Name;
    int TotalPurchases;
    string Email;

};

// Function prototypes
void CustomerMenu(); //function for customer menu
void addCustomer(Customer customers[], int& numCustomers);// function to add customer details.
void viewCustomers(const Customer customers[], int numCustomers); // function to view customer details.
void deleteCustomer(Customer customers[], int& numCustomers);// function to delete customer details.
void updateCustomer(Customer customers[], int numCustomers);// function to update customer details.
void searchCustomer(const Customer customers[], int numCustomers);// function for search customer details.
void CustomersToFile(const Customer customers[], int numCustomers);// function to add customer details to files.
void CustomersloadFromFile(Customer customers[], int& numCustomers);// function to load customer details from files.





// function to display customer menu
void CustomerMenu()
{
    Customer customers[max_customers];// array of structures to store customer data
    int numCustomers = 0;//variable to keep track of the number of customers 
    CustomersloadFromFile(customers, numCustomers);//function to load customers data from file is  called.


    int choice;//variable is declared to handle the user's choices
    //displaying the customer menu options
    while (true)
    {
        cout << "*******CUSTOMER*******" << endl;

        cout << "1. Add customer " << endl;
        cout << "2. View customers " << endl;
        cout << "3. Search customer " << endl;
        cout << "4. Update customer " << endl;
        cout << "5. Delete customer " << endl;
        cout << "6. Back to Main Menu " << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "Enter your choice: ";//prompts the user to enter choice 

        cin >> choice;//the user enter the choice from the above menu

        //switch statements is used to handle the user choice
        switch (choice)
        {//start of switch brackets
        case 1://case 1 where add customer function is called
            addCustomer(customers, numCustomers);
            break;
        case 2://case 2 where view customer function is called
            viewCustomers(customers, numCustomers);
            break;
        case 3://case 3 where  search customer function is called
            searchCustomer(customers, numCustomers);
            break;
        case 4://case 4 where update customer function is called
            updateCustomer(customers, numCustomers);
            break;
        case 5://case 5 where delete customer function is called
            deleteCustomer(customers, numCustomers);
            break;
        case 6://case 6 if the user enter 6 it return to the main menu

            return;
        default://default case invalid choice.
            cout << "Invalid choice!\n Enter a valid choice" << endl;
            break;
        }
        if (choice == 6)
        {
            break;  // Exit the loop if the user chooses to go back to the main menu
        }
    }
}
//function to add a new customer.
void addCustomer(Customer customers[], int& numCustomers)//function definition to add a new customer
{//checking if there is space for a new customer as num customer keep the track of number of customers
    if (numCustomers < max_customers)
    {
        cout << "---------------------------" << endl;
        cout << " Enter customer " << numCustomers + 1 << " details: " << endl;
        cout << "---------------------------" << endl;

        cout << " Enter Customer's ID: ";
        cin >> customers[numCustomers].ID;// reading and storing customer id in  array of structure
        cout << " Enter Customer's Name.: ";
        cin >> customers[numCustomers].Name;// reading and storing customer receipt number in array of structure
        cout << " Enter Total Purchases: ";
        cin >> customers[numCustomers].TotalPurchases;// reading and storing customer's age in  array of structure
        cout << " Enter Customer's Email: ";
        cin >> customers[numCustomers].Email;// reading and storing customer's total purchases in array of structure

        numCustomers++;//incrementing the number of customers

        CustomersToFile(customers, numCustomers);//adding all the customer information to a file 

        cout << "Customer added successfully.\n";
    }
    else// this statement executes if the maximum number of customers is reached
    {
        cout << "Maximum number of customers reached." << endl;
    }
}
//function to view the customer details
void viewCustomers(const Customer customers[], int numCustomers)
{
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << " ID " << setw(15) << " Name " << setw(25) << " Total Purchases " << setw(20) << " Email " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    //loop iterates through each customer printing id,receipt number,age and total purchases.
    for (int i = 0; i < numCustomers; i++)
    {//starting of for loop brackets.
        //printing each attribute of the customer.
        cout << customers[i].ID << setw(15) << customers[i].Name << setw(20) << customers[i].TotalPurchases << setw(30) << customers[i].Email << endl;
    }//ending of for loop brackets

}


// Function to search for a customer by ID in a  array of 'customers'(structure)
void searchCustomer(const Customer customers[], int numCustomers)
{
    string search_id;// Variable to store the customer ID to be searched

    cout << "---------------------------------------------" << endl;
    // Prompt the user to enter the ID of the customer to be searched

    cout << "Enter the ID of customer you want to search: ";
    cin >> search_id;

    bool found = false;// Boolean flag to indicate whether the customer is found or not


    for (int i = 0; i < numCustomers; i++)     // Loop through each customer in the array

    {
        if (customers[i].ID == search_id)   // Check if the current customer's ID matches the search ID

        {
            found = true;  // Set the 'found' flag to true

            cout << "---------------" << endl;
            // Display customer information including id receipt number age and total purchaces

            cout << "Customer Found:" << endl;
            cout << "---------------" << endl;

            cout << "ID: " << customers[i].ID << endl;
            cout << "Name.: " << customers[i].Name << endl;
            cout << "Total Purchases: " << customers[i].TotalPurchases << endl;
            cout << "Email: " << customers[i].Email << endl;
        }
    }
    // Check if the customer was not found and display a message.

    if (!found) {
        cout << "Customer with ID " << search_id << " not found." << endl;
    }
}
// Function to update customer details by searching with their ID

void updateCustomer(Customer customers[], int numCustomers) {
    string update_id;    // Variable to store the customer ID to be updated

    cout << "---------------------------------------------" << endl;
    // Prompt the user to enter the ID of the customer to be updated

    cout << "Enter the ID of customer you want to update: ";

    cin >> update_id;
    // Boolean flag to indicate whether the customer is found or not

    bool found = false;

    for (int i = 0; i < numCustomers; i++)     // Loop through each customer in the array
    {
        if (customers[i].ID == update_id)         // Check if the current customer's ID matches the update ID

        {
            found = true;
            cout << "-----------------------------------" << endl;

            cout << "Enter new details for the customer:" << endl;
            cout << "-----------------------------------" << endl;

            cout << " Enter Customer's ID: "; // Display a message prompting the user to enter new id

            cin >> customers[i].ID;

            cout << " Enter Customer's Name: "; // Display a message prompting the user to enter new receipt number
            cin >> customers[i].Name;

            cout << "Enter Total Purchases ";  // Display a message prompting the user to enter new age

            cin >> customers[i].TotalPurchases;
            cout << " Enter Email ";  // Display a message prompting the user to enter new total purchases.

            cin >> customers[i].Email;

            CustomersToFile(customers, numCustomers);// Call a function to add the updated customer details to a file


            cout << "Customer updated successfully.\n"; // Display a message that customer (with all his details ) updated successfully

        }
    }

    if (!found) {
        cout << "Customer with ID " << update_id << " not found." << endl;
    }
}

// Function to delete a customer  by searching with their ID

void deleteCustomer(Customer customers[], int& numCustomers) {
    string delete_id;    // Variable to store the customer ID to be deleted

    cout << "----------------------------------------------" << endl;
    // Prompt the user to enter the ID of the customer to be deleted

    cout << "Enter the ID of customer you want to delete: ";
    cin >> delete_id;

    bool found = false;    // Boolean flag to indicate whether the customer is found or not


    for (int i = 0; i < numCustomers; i++)   // Loop through each customer in the array
    {
        if (customers[i].ID == delete_id)
        {
            found = true; // Set the 'found' flag to true

            cout << "-----------------" << endl;
            // Display a message indicating the deleted customer's details

            cout << " Customer Deleted:" << endl;

            cout << " ID " << customers[i].ID << endl;
            cout << " Name. " << customers[i].Name << endl;
            cout << " Total Purchases " << customers[i].TotalPurchases << endl;
            cout << " Email" << customers[i].Email << endl;

            for (int j = i; j < numCustomers - 1; j++) // Initialize the loop variable j to the index of the deleted customer i 
            {

                customers[i].ID = customers[j + 1].ID;
                customers[i].Name = customers[j + 1].Name;
                customers[i].TotalPurchases = customers[j + 1].TotalPurchases;
                customers[i].Email = customers[j + 1].Email;

            }

            numCustomers--; // Decrease the total number of customers

            CustomersToFile(customers, numCustomers); // Call a function to add the updated customer details to a file


            cout << "Customer deleted successfully.\n";//message displayed that the customer deleted successfully

        }

    }

    if (!found) //if the customer not found then this statement executes that customer with ID (this) not found
    {
        cout << "Customer with ID " << delete_id << " not found." << endl;
    }
}

// Function to add customer details to a file

void CustomersToFile(const Customer customers[], int numCustomers)
{
    ofstream fout("customers.txt");// Open a file named "customers.txt" for writing


    //loop iterates through each customer printing id,receipt number,age and total purchases.
    for (int i = 0; i < numCustomers; i++)
    {
        fout << customers[i].ID << setw(15) << customers[i].Name << setw(20) << customers[i].TotalPurchases << setw(30) << customers[i].Email << endl;
    }//ending of for loop brackets


    fout.close();// Close the file

}
// Function to load customer details from a file

void CustomersloadFromFile(Customer customers[], int& numCustomers)
{
    try
    {
        ifstream fin("customers.txt");    // Open a file named "customers.txt" for reading

        if (fin.fail())// Check if reading from the file fails
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
        

        numCustomers = 0;    // Initialize the total number of customers to 0

        // Read customer details from the file until the end of the file is reached

        while (fin >> customers[numCustomers].ID >> customers[numCustomers].Name >> customers[numCustomers].TotalPurchases >> customers[numCustomers].Email)
        {
            numCustomers++;  // Increment the total number of customers

        }

        fin.close();    // Close the file that is opened
    }
    catch (runtime_error& e)// Catch and handle runtime error if file operation fails
    {
        cout << "Error" << e.what() << endl; //  display the error
        return;
    }

}