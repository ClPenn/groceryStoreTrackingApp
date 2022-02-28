////*
// CS 210 Project 3 Grocery Store Tracking Application
// 2/20/2022
// 
// Corey Pennebaker
// App takes in a list of products purchased in a day and creates objects based on user input
// 
////*

#include <Python.h>
#include <iostream>
#include <ostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>	
#include <fstream>                                          
using namespace std;

/*
Description:
        To call this function, simply pass the function name in Python that you wish to call.
Example:
        callProcedure("printsomething");
Output:
        Python will print on the screen: Hello from python!
Return:
        None

*/

void callProcedure(string pName)
{
    char* procname = new char[pName.length() + 1];
    std::strcpy(procname, pName.c_str());

    Py_Initialize();														// Initialize the Python Interpreter
    PyObject* my_module = PyImport_ImportModule("PythonCode");				// Build the name object
    PyErr_Print();
    PyObject* my_function = PyObject_GetAttrString(my_module, procname);
    PyObject* my_result = PyObject_CallObject(my_function, NULL);
    Py_Finalize();															// Finish the Python Interpreter

    delete[] procname;														// Clean

}

void CallProcedure(string pName)
{
    char* procname = new char[pName.length() + 1];
    std::strcpy(procname, pName.c_str());

    Py_Initialize();
    PyObject* my_module = PyImport_ImportModule("PythonCode");
    PyErr_Print();
    PyObject* my_function = PyObject_GetAttrString(my_module, procname);
    PyObject* my_result = PyObject_CallObject(my_function, NULL);
    Py_Finalize();

    delete[] procname;
}


/*
Description:
        To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
        int x = callIntFunc("PrintMe","Test");
Output:
        Python will print on the screen:
                You sent me: Test
Return:
        100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
    char* procname = new char[proc.length() + 1];
    std::strcpy(procname, proc.c_str());

    char* paramval = new char[param.length() + 1];
    std::strcpy(paramval, param.c_str());


    PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
    // Initialize the Python Interpreter
    Py_Initialize();
    // Build the name object
    pName = PyUnicode_FromString((char*)"PythonCode");
    // Load the module object
    pModule = PyImport_Import(pName);
    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);
    // pFunc is also a borrowed reference 
    pFunc = PyDict_GetItemString(pDict, procname);
    if (PyCallable_Check(pFunc))
    {
        pValue = Py_BuildValue("(z)", paramval);
        PyErr_Print();
        presult = PyObject_CallObject(pFunc, pValue);
        PyErr_Print();
    }
    else
    {
        PyErr_Print();
    }
    //printf("Result is %d\n", _PyLong_AsInt(presult));
    Py_DECREF(pValue);
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);
    // Finish the Python Interpreter
    Py_Finalize();

    // clean 
    delete[] procname;
    delete[] paramval;


    return _PyLong_AsInt(presult);
}


/*
Description:
        To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
        int x = callIntFunc("doublevalue",5);
Return:
        25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
    char* procname = new char[proc.length() + 1];
    std::strcpy(procname, proc.c_str());

    PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
    // Initialize the Python Interpreter
    Py_Initialize();
    // Build the name object
    pName = PyUnicode_FromString((char*)"PythonCode");
    // Load the module object
    pModule = PyImport_Import(pName);
    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);
    // pFunc is also a borrowed reference 
    pFunc = PyDict_GetItemString(pDict, procname);
    if (PyCallable_Check(pFunc))
    {
        pValue = Py_BuildValue("(i)", param);
        PyErr_Print();
        presult = PyObject_CallObject(pFunc, pValue);
        PyErr_Print();
    }
    else
    {
        PyErr_Print();
    }
    //printf("Result is %d\n", _PyLong_AsInt(presult));
    Py_DECREF(pValue);
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);
    // Finish the Python Interpreter
    Py_Finalize();

    // clean 
    delete[] procname;

    return _PyLong_AsInt(presult);
}

void menu() {

    /// Main menu for users to choose section
    cout << "*******************************************************************************************************************" << endl;
    cout << "*******************************************************************************************************************" << endl;
    cout << "*******************************************************************************************************************" << endl;
    cout << "*********************************   1. Get List of Items Sold in one Day   ****************************************" << endl;
    cout << "*******************************************************************************************************************" << endl;
    cout << "*************************   2. Search the Number of Times an Item was Purchased   *********************************" << endl;
    cout << "*******************************************************************************************************************" << endl;
    cout << "*********************************   3. Print Histogram for the days List   ****************************************" << endl;
    cout << "*******************************************************************************************************************" << endl;
    cout << "**********************************************  4. Quit  **********************************************************" << endl;
    cout << "*******************************************************************************************************************" << endl;
    cout << "*******************************************************************************************************************" << endl;
    cout << "*******************************************************************************************************************" << endl;

}

// function calls .dat file saved from python function displays item name and number of items bought
void readList() {
    string itemName = "none";
    int quantity = 0;

    ifstream inFS;
    inFS.open("frequency.dat");	
    while (!inFS.eof()) {												    
        inFS >> itemName;  
        inFS >> quantity;												    
        if (!inFS.fail()) {                                                 
            cout << left << setw(19) << itemName << "" << string(quantity, '**') << endl;

        }
    }
    inFS.close();
}


int main() {

    // Declaring Variables to be used in main menu and function calls
    int userSelect = 0, wordCount;
    string searchTerm;
    bool loop = false;

    while (!loop) {

            
        // displays menu options
        menu();

        // gets input from user
        cin >> userSelect;

        // switch statement to excute user seletions
        switch (userSelect) {

        case 1:
            // calls function to show dict of key and values made in python 
            system("CLS");                                          //Clear the screen to 
            CallProcedure("DisplayQuantityList");
            cout << endl;
            break;


        case 2:
            // case 2 searchs for a specific item and returns the value of times bought that day
            system("CLS");
            cout << "Enter items you would like to search for (search is case sensitive):" << endl;
            cin >> searchTerm;

            // Calls the python function and saves the results in variable wordCount
            wordCount = callIntFunc("ItemSearch", searchTerm);
            // Checks to see if search item is in days list
            if (wordCount == 0) {
                cout << endl;
                cout << "Item not found" << endl;
                cout << endl;
                break;
            }
            // output to user display
            cout << endl;
            cout << searchTerm << " : " << wordCount << endl;
            cout << endl;
            break;

        case 3:
            // case 3 prints histogram function

            system("CLS");
            // calls python function to create .dat file
            callProcedure("CreateHistogram");
            // C++ function that calls the .dat file made with python, reads and outputs the values 
            readList();

            break;

        case 4:
            // case 4 exits program/loop
            return 0;


        default:
            // returns a default message if user enter invalid selection 
            // 
            // If the input is a string the program enters an infinate loop and I can not figure out why...

            cout << "Please input a valid selection.";
            cout << endl;
            break;
        }
    }
}

//CallProcedure("printsomething");
//cout << callIntFunc("PrintMe", "House") << endl;
//cout << callIntFunc("SquareValue", 2