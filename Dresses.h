#pragma once

#include <iostream> // header file for input output stream
#include <fstream> // header file for file streams
#include <iomanip> // header file for setw.

using namespace std;

const int max_dresses = 10; // Maximum number of dresses (rows)




// Struct to represent a Dress with ID, Name, Type, and Price

struct Dresses
{
    string ID;
    string Name;
    string Type;
    double Price;



};

// Function declarations for various operations on Dresses

void DressesMenu(); //function for dress menu
void addDress(Dresses dress[], int& numDresses);// Function to add dress details
void viewDress(const Dresses dress[], int numDresses); // function to view dress details.
void deleteDress(Dresses dress[], int& numDresses);// function to delete dress details.
void updateDress(Dresses dress[], int numDresses);// function to update dress details.
void searchDress(const Dresses dress[], int numDresses);// function for search dress details.
void DressesToFile(const Dresses dress[], int numDresses);// function to write dress details to files.
void DressesLoadFromFile(Dresses dress[], int& numDresses);// function to load dress details from files.



void DressesMenu()
{
    Dresses dress[max_dresses];// array of structure to store dress data
    int numDresses = 0;//variable to keep track of the number of customers 
    DressesLoadFromFile(dress, numDresses);// load dress data from file if available


    int choice;//variable is declared to handle the user's choices
    //displaying the dress menu options
    while (true)
    {
        cout << "*******Dressses*******" << endl;

        cout << "1. Add Dress " << endl;
        cout << "2. View Dress " << endl;
        cout << "3. Search Dress " << endl;
        cout << "4. Update Dress " << endl;
        cout << "5. Delete Dress " << endl;
        cout << "6. Back to Main Menu " << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "Enter your choice: ";//prompts the user to enter choice 

        cin >> choice;//the user enter the choice from the above menu

        //switch statements is used to handle the user choice
        switch (choice)
        {//start of switch brackets
        case 1:
            addDress(dress, numDresses);// If user chooses 1, call addDress function
            break;
        case 2:
            viewDress(dress, numDresses);// If user chooses 2, call viewDress function
            break;
        case 3:
            searchDress(dress, numDresses);// If user chooses 3, call searchDress function
            break;
        case 4:
            updateDress(dress, numDresses);// If user chooses 4, call updateDress function
            break;
        case 5:
            deleteDress(dress, numDresses);// If user chooses 5, call deleteDress function
            break;
        case 6://case 6 if the user enter 6 it return to the main menu
            return;
        default://default case invalid choice.
            cout << "Invalid choice!\n Enter a valid choice" << endl;// Display an error message for invalid choices
            break;
           
        }
        if (choice == 6)
        {
            break;  // Exit the loop if the user chooses to go back to the main menu
        }
    }
}
//function to add a new dress.
void addDress(Dresses dress[], int& numDresses)//function definition to add a new dress.
{//checking if there is space for a new dress.
    if (numDresses < max_dresses)
    {
        // Prompt the user to enter dress details

        cout << "---------------------------" << endl;
        cout << " Enter Dress " << numDresses + 1 << " details: " << endl;
        cout << "---------------------------" << endl;

        cout << " Enter Dress ID: ";
        cin >> dress[numDresses].ID;// reading and storing dress id
        cout << " Enter Dress Name.: ";
        cin >> dress[numDresses].Name;// reading and storing name
        cout << " Enter Dress Type: ";
        cin >> dress[numDresses].Type;// reading and storing dress type
        cout << " Enter Dress Price: ";
        cin >> dress[numDresses].Price;// reading and storing dress price

        numDresses++;//incrementing the number of dresses

        DressesToFile(dress, numDresses);//adding all the dress information to a file 

        cout << "Dress added successfully.\n";
    }
    else// this statement executes if the maximum number of dresses is reached
    {
        cout << "Maximum number of dresses reached." << endl;
    }
}
//function to view the dress details
void viewDress(const Dresses dress[], int numDresses)
{
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << " ID " << setw(15) << " Name " << setw(25) << " Type" << setw(20) << " Price " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    //loop iterates through each dress printing id,name,type and price.
    for (int i = 0; i < numDresses; i++)
    {//starting of for loop brackets.
        //printing each attribute of the dress.
        cout << dress[i].ID << setw(15) << dress[i].Name << setw(20) << dress[i].Type << setw(30) << dress[i].Price << endl;
    }//ending of for loop brackets

}


// Function to search for a dress by id
void searchDress(const Dresses dress[], int numDresses)
{
    string search_id;// Variable to store the dress ID to be searched

    cout << "---------------------------------------------" << endl;
    // Prompt the user to enter the ID of the dress to be searched

    cout << "Enter the ID of Dress you want to search: ";
    cin >> search_id;

    bool found = false;// Boolean flag to indicate whether the dress is found or not


    for (int i = 0; i < numDresses; i++)     // Loop through each dress in the array

    {
        if (dress[i].ID == search_id)   // Check if the current dress's ID matches the search ID

        {
            found = true;  // Set the 'found' flag to true

            cout << "---------------" << endl;
            // Display dress information including id, name,type  and price.

            cout << "Dress Found:" << endl;
            cout << "---------------" << endl;

            cout << "ID: " << dress[i].ID << endl;
            cout << "Name.: " << dress[i].Name << endl;
            cout << "Type: " << dress[i].Type << endl;
            cout << "Price: " << dress[i].Price << endl;
        }
    }
    // Check if the dress was not found and display a message.

    if (!found)
    {
        cout << "Dress with ID " << search_id << " not found." << endl;
    }
}
// Function to update dress details by searching with their ID

void updateDress(Dresses dress[], int numDresses) {
    string update_id;    // Variable to store the dress ID to be updated


    cout << "---------------------------------------------" << endl;
    // Prompt the user to enter the ID of the dress to be updated

    cout << "Enter the ID of Dress you want to update: ";

    cin >> update_id;
    // Boolean flag to indicate whether the dress is found or not

    bool found = false;

    for (int i = 0; i < numDresses; i++)     // Loop through each dress in the array
    {
        if (dress[i].ID == update_id)         // Check if the current dress's ID matches the update ID

        {
            found = true;
            cout << "-----------------------------------" << endl;

            cout << "Enter new details for the Dress:" << endl;
            cout << "-----------------------------------" << endl;

            cout << " Enter Dress ID: "; // Display a message prompting the user to enter new id

            cin >> dress[i].ID;

            cout << " Enter Dress Name: "; // Display a message prompting the user to enter new name
            cin >> dress[i].Name;

            cout << "Enter Dress Type ";  // Display a message prompting the user to enter new type

            cin >> dress[i].Type;
            cout << " Enter Dress Price";  // Display a message prompting the user to enter new price

            cin >> dress[i].Price;

            DressesToFile(dress, numDresses);// Call a function to add the updated dress details to a file


            cout << " Dress updated successfully.\n"; // Display a message that dress(with all his details ) updated successfully

        }
    }

    if (!found) {
        cout << " Dress with ID " << update_id << " not found." << endl;
    }
}

// Function to delete a dress  by searching with their ID

void deleteDress(Dresses dress[], int& numDresses)
{
    string delete_id;    // Variable to store the dress ID to be deleted

    cout << "----------------------------------------------" << endl;
    // Prompt the user to enter the ID of the dress to be deleted

    cout << "Enter the ID of Dress you want to delete: ";
    cin >> delete_id;

    bool found = false;    // Boolean flag to indicate whether the dress is found or not


    for (int i = 0; i < numDresses; i++)   // Loop through each dress in the array
    {
        if (dress[i].ID == delete_id)
        {
            found = true; // Set the 'found' flag to true

            cout << "-----------------" << endl;
            // Display a message indicating the deleted dress's details

            cout << " Customer Deleted:" << endl;

            cout << " ID " << dress[i].ID << endl;
            cout << " Name " << dress[i].Name << endl;
            cout << " Type " << dress[i].Type << endl;
            cout << " Price" << dress[i].Price << endl;

            for (int j = i; j < numDresses - 1; j++) // Initialize the loop variable j to the index of the deleted dress i 
            {
                // Move the details of the next dress to the current position

                dress[i].ID = dress[j + 1].ID;
                dress[i].Name = dress[j + 1].Name;
                dress[i].Type = dress[j + 1].Type;
                dress[i].Price = dress[j + 1].Price;

            }

            numDresses--; // Decrease the total number of dresses

            DressesToFile(dress, numDresses); // Call a function to add the updated dress details to a file


            cout << "Dress deleted successfully.\n";//message displayed that the dress deleted successfully

        }

    }

    if (!found) //if the dress not found display a message
    {
        cout << "Dress with ID " << delete_id << " not found." << endl;
    }
}


// Function to add dress details to a file

void DressesToFile(const Dresses dress[], int numDresses)
{
    ofstream fout("dress.txt");// Open a file named "dress.txt" for writing


    //loop iterates through each dress printing id,name,type and price.
    for (int i = 0; i < numDresses; i++)
    {
        fout << dress[i].ID << setw(15) << dress[i].Name << setw(20) << dress[i].Type << setw(30) << dress[i].Price << endl;
    }//ending of for loop brackets


    fout.close();// Close the file

}


// Function to load dress details from a file

void DressesLoadFromFile(Dresses dress[], int& numDresses) 
{
    try
    {
        ifstream fin("dress.txt");    // Open a file named "dress.txt" for reading


        if (fin.fail()) // Check if reading from the file fails
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
       

        numDresses = 0;    // Initialize the total number of dresses to 0


        // Read dress details from the file until the end of the file is reached

        while (fin >> dress[numDresses].ID >> dress[numDresses].Name >> dress[numDresses].Type >> dress[numDresses].Price)
        {
            numDresses++;  // Increment the total number of dresses

        }

        fin.close();    // Close the file that is opened
    }
    catch (runtime_error& e)// Catch and handle runtime error if file operation fails
    {
        cout << "Error" << e.what() << endl; //  display the error
        return;
    }
    

}


