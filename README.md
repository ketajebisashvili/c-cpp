# c-cpp
project for c/c++ course
CW1
![image](https://user-images.githubusercontent.com/89931940/175060572-6555b432-a8ad-4b6f-ba71-c75928d44ba6.png)

Initial data

The initial data is located into a data structure consisting of arrays of pointers, headers and items.
Declarations of items as C / C++ struct s are presented in file Items.h. There are 10 different types of items
( ITEM1, ITEM2, ..., ITEM10 ). Declarations of headers as C / C++ struct s are presented in file Headers.h.
There are 5 different types of headers ( HEADER_A, HEADER_B, HEADER_C, HEADER_D, HEADER_E ). The
both files are stored in Instructor's stuff.

There are 5 different types of data structures ( Struct1, Struct2, Struct3, Struct4, Struct5 ). To generate the
initial data structure you have to use functions from ICS0017DataSource.dll. This DLL is implemented by
instructor and stored in Instructor's stuff. It needs auxiliary file Colors.txt , created from
https://en.m.wikipedia.org/wiki/Lists_of_colors.

To understand the building principles of our data structures analyse the examples on the following pages.
Let us emphasize that they are just examples: the actual presence and absence of items and headers is
determined by the work of item generator built into ICS0017DataSource.dll and is largerly occasional.

The DLL imports 6 public functions declared in file ICS0017DataSource.h (also stored in Instructor's stuff).
Five of them create data structure and return the pointer to it. The sixth function ( GetItem() ) constructs a
stand-alone item and returns the pointer to it. There is also a password-protected function for the
instructor. Comments explaining the usage of public functions are in ICS0017DataSource.h.

To know which item and data structure you have to use contact the instructor.
Task # 1

Write a C / C++ function that prints in the command prompt window the contents of all the items from
the current data structure.

Prototype (text printed in blue depends on the type of data structure, specify it yourself):

void PrintDataStructure(pointer_to_data_structure);

The output should be similar to the following:

If the data structure is empty, print an error message.
Task

Write a C / C++ function that inserts a new item into the current data structure.

Prototype (text printed in blue depends on the type of data structure, specify it yourself):
pointer_to_data_structure = InsertItem(pointer_to_data_structure, char *pNewItemID = 0);

The new item must be constructed by function GetItem() from ICS0017DataSource.dll. The user may set
the ID itself or set the pointer to it to zero. In the last case the ID is selected by GetItem().

You may freely select the position of new item in the linked list of items.

The return value is the pointer to the modified data structure.

The function must keep the current contents of data structure and throw an exception if:

    An item with same ID is already in the data structure.
    The ID presented by user does not follow the formatting rules.

Task

Write a C / C++ function that inserts a new item into the current data structure.

Prototype (text printed in blue depends on the type of data structure, specify it yourself):
pointer_to_data_structure = RemoveItem(pointer_to_data_structure, char *pItemID);

The memory fields occupied by the item to be removed must be released (use operator delete ). Do not
forget that if a header has lost all the items or other headers associated with it, this header itself must
also disappear.

The return value is the pointer to the modified data structure.

The function must keep the current contents of data structure and throw an exception if:

    Item with the specified ID does not exist.
    The ID presented by user does not follow the formatting rules.

First steps

    Launch Visual Studio and a start the new project. The project template must be Visual C++
    Windows Console Application. Suppose that the project name you have selected is Coursework
    and the location folder is C:\ICS0017. The wizard creates project file C:\ 0017 \Courswork1.sln and
    source code folder C:\ICS0017\Coursework1\Coursework1. Into source code folder it puts files
    Coursework1.cpp containing a simple main() function and also some auxilary files.
    Buid you solution. Then set the configuration to Release and build once more. Now you have all
    the folders you need.
    Set the configuration back to Debug. From Instructor's stuff extract DateTime.h , Headers.h ,
    Items.h , ICS0017DataSource.h , Colors.txt and ICS0017DataSource.lib. Store them in source code
    folder C:\ICS0017\Coursework1\Coursework1. In the Visual Studio Solution Explorer right-click
    Header Files and from the pop-up menu select Add → Existing Item. From the existing file list
    select all the four *.h files and click Add.

    From Instructor's stuff extract ICS0017DataSource.dll in debug mode and store in folder
    C:\ICS0017\Coursework1\Debug. Extract also ICS0017DataSource.dll in release mode and store in
    folder C:\ICS0017\Coursework1\Release.
    In the solution folder right-click Coursework1 and from pop-up menu select Properties. In the
    Property Pages box set configuration to All Configurations. Then open the Linker properties list,
    select Input and click on row Additional Dependences :
    Click on the button at the right edge of Additional Dependences list. A menu opens, from it select
    <Edit...>. The Additional Dependeces box opens, write into it ICS0017DataSource.lib (not *.dll !).
    Select OK and once more OK.

    Now you may test is your project well prepared. Suppose you must use Struct2 and ITEM3 and
    you want to create the structure containing 100 items. Then write:
    #include
    #include "DateTime.h"
    #include "Items.h"
    #include "Headers.h"
    #include "ICS0017DataSource.h"
    // IMPORTANT: follow the given order of *.h files: ICS0017DataSource.h must be
    // the last
    int main()
    {
    HEADER_C *p = GetStruct2(3, 100);
    ITEM3 *pNewItem = (ITEM3 *)GetItem(3);
    return 0;
    }
    This program should run. To see the results you have to implement PrintStruct() function.

To run your application without Visual Studio, put your release *.exe together with Colors.txt and
ICS0017DataSource.dll into a separate folder.
Evaluation^1

The deadline is the end of examinations in January. However, it is strongly advised to present the results
of coursework during the semester. The students can do it after each lecture.

(^1) Here we suppose that the semester as well as the session will be carried on in normal way.

To get the assessment the students must attend personally. Electronically (e-mail, etc.) sent courseworks
are neither accepted nor reviewed.

The students must prepare test functions (see below) verifying that all the 3 implemented functions are
working correctly.

Presenting the final release is not necessary. It is OK to demonstrate the work of application in Visual
Studio environment.
Test cases

Write function main() that:

    Sets the number of items to 30 and prints the data structure.
    One after another inserts new items with identifiers: Z A, Z Z, Z K, A Z, A A, A K, G Z, G A, G K, M A, M
    Ba, M Bb, M Z.
    Trys to insert items with identifier M Ba and Mba and prints the error messages.
    Prints the new data structure of 43 items.
    One after another removes the items that were just inserted.
    Trys to remove items with identifier M Ba and Mba and prints the error messages.
    Prints the data structure.

CW2
Task
Coursework2 is actually the continuation of Coursework1. It uses the same data structure, items and
ICS0017DataSource.dll. It is not allowed to replace the data structure with some simple analogue.
Implement class DataStructure containing the following public functions (text printed in blue depends on
the type of item, specify it yourself):
1. DataStructure();
Constructor that creates empty data structure.
2. DataStructure(char *pFilename);
Constructor that reads data from a binary file. The file was created by function Write (see
below). Fails if there occur problems with file handling.
3. ~DataStructure();
Destructor that deletes all the items, vectors of pointers and headers.
4. DataStructure(const DataStructure &Original);
Copy constructor.
5. int GetItemsNumber();
Returns the current number of items in data structure.
6. pointer_to_item GetItem(char *pID);
Returns pointer to item with the specified ID. If the item was not found, returns 0.
7. void operator+=(pointer_to_Item);
Operator function to add a new item into data structure. Fails if the data structure already
contains an item with the specified ID. Usage example:
DataStructure *pds = new DataStructure;
ITEM5 *p = (ITEM5 *)GetItem(5);
*pds += p;
8. void operator-=(char *pID);
Operator function to remove and destroy item with the specified ID. Fails if there is no item with
the specified ID. Usage example:
*pds-= (char *)”Dark Khaki”;
9. DataStructure &operator=(const DataStructure &Right);
Operator function for assignment. Do not forget that before the assignment you have to destroy
all the existing contents. Usage example:
DataStructure ds;
ds = *pds;
10. Int operator==(DataStructure &Other);
Operator function for comparison. Two data structures are equal if they contain the same
number of items and for each item in the first structure there is a 100% matching item in the
second structure. The order in the linked lists may be different. Returs 0 (not equal) or 1 (equal).
Usage example:
cout << (ds == *pds) << endl;
11. void Write(char *pFilename);
Serializes the data structure and writes into the specified file. Fails if there occur problems with
file handling or if the data structure is empty.
12. friend std::ostream &operator<<(std::ostream &ostr, const DataStructure &str);
Prints all the items into command prompt window. Usage example:
cout << *pds << endl << endl;
Requirements
1. For memory allocation and release use operators new and delete.
2. The new items must be created with function GetItem() from ICS0017DataSource.dll. It
guarantees that the item is correct.
3. For string copy use function strcpy_s.
4. For input and output use methods from iostream (cin, cout , etc.).
5. For file operations use methods from fstream.
6. In case of failure any of the functions must throw an object of standard class exception.
7. You may add into data structure attibutes and private fubctions as you consider feasible. But all
the attributes must be private.
8. Write also a simple command prompt menu for testing and checking.
Evaluation1
The deadline is the end of examinations in January. However, it is strongly advised to present the results
of coursework during the semester. The students can do it after each lecture.
To get the assessment the students must attend personally. Electronically (e-mail, etc.) sent courseworks
are neither accepted nor reviewed.
The students must prepare test functions (see below) verifying that all the implemented class functions
are working correctly.
Presenting the final release is not necessary. It is OK to demonstrate the work of application in Visual
Studio environment.
Test cases
Write function main() that:
1 Here we suppose that the semester as well as the session will be carried on in normal way.
1. Creates empty data structure.
2. Inserts 10 items into data structure (in a simple loop that calls 10 times operator+). To create
items use function GetItem from DLL (read ICS0017DataSource.h)
3. Prints the resulting data structure.
4. Prints the number of elements in data structure (using GetItemsNumber).
5. Retrieves item with ID Light Cyan.
6. Tries to retrieve non-existing element X X.
7. Using the copy constructor creates the copy of current structure.
8. Removes items Banana Mania, Persian Green and Vegas Gold from the initial structure.
9. Compares the initial structure (now with 7 items) with the copy structure.
10. Writes the initial structure (now 7 items) into a data file.
11. Creates a new structure from this data file and compares it with initial stucture.
12. Asssigns to the structure just created (7 items) the copy created in step 7 (10 items) and prints
the result.
