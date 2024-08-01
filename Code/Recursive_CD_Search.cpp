/* ********************************************************************
Travis Darby

Program presents a user with nine options.
    1 - Read in CD collection:  data is read in from a .txt file
        The .txt file with the CD collection is read into a array that
        contains objects from a created class called CD. The objects
        each store the Artist's name, Album Title and the year the CD was released.
    2 - Display the CD collection
    3 - Sort the CD Collection using a selection sort algorithm. The
        objects are sorted alphabetically by artist name
    4 - Search for a specific album in the collection using a linear
        search function.
    5 - Search for a specific album in the collection using a *recursive* linear
        search function.
    6 - Edit a CD: gives the user the option to edit a specific CD's
        artist, album title or year released
    7 - Add Number of Tracks: searches for a user requested CD, if found prompts
        the user for the number of tracks. A dynamic memory array is
        created at this point to store the names of the tracks which the user provides
    8 - Delete Tracks: searched for a user requested CD, if found, and the specific
        CD has tracks assigned to it, the tracks array is deleted and reassigned to be null.
    9 - Math Break: Provides a break from the collection by having the
        user play three games 1 - is the number Even or Odd, 2 - is the
        number a Prime Number, 3 - reverses a string the user has input using a recursive function
    10 - Exit and end the program
 
    Option 1 must be selected before options 2 - 7 can be run. A message
    will display saying this to the user.
******************************************************************** */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//CD class decleration
class CD
{
//CD Class private data attributes
private:
    string artist, title;
    int year;
    int numTracks;
    string *tracks;
    
//CD class Prototypes for member functions
public:
    CD();
    ~CD();
    CD(string a, string t, int y);
    void setArtist(string a);
    void setTitle(string t);
    void setYear(int y);
    void setNumTracks(int n);
    void setTrack(string t, int i);
    string getArtist();
    string getTitle();
    int getYear();
    int getNumTracks();
    string getTrack(int n);
    void deleteTracks();
};
//Object Constructor
//assigns null values to each attribute
CD::CD()
{
    artist = title = " ";
    year = 0;
    numTracks = 0;
    tracks = nullptr;
}
//Object Destructor
//destroys any dynamic arrays, when rhe program cloess, if an object
//has a vlaue greater than 0 assigned to numTracks
CD::~CD()
{
    if (numTracks)
    {
        delete [] tracks;
        tracks = nullptr;
        numTracks = 0;
    }
}
//parameterized constructor
//CD::CD(string a, string t, int y)
//{
//    artist = a;
//    title = t;
//    year = y;
//}
/* *****************************************************************
Function:   setArtist()
Inputs:     string a
Outputs:    None
Purpose:    This function copies the argument passed into the parameter
            to the private attribute artist
******************************************************************* */
void CD::setArtist(string a)
{ artist = a; }
/* *****************************************************************
Function:   setTitle()
Inputs:     string t
Outputs:    None
Purpose:    This function copies the argument passed into the parameter
             to the private attribute title
******************************************************************* */
void CD::setTitle(string t)
{ title = t; }
/* *****************************************************************
Function:   setYear()
Inputs:     int y
Outputs:    None
Purpose:    This function copies the argument passed into the parameter
            to the private attribute year
******************************************************************* */
void CD::setYear(int y)
{year = y; }
/* *****************************************************************
Function:   setNumTracks()
Inputs:     int
Outputs:    None
Purpose:    This function assigns user input to number of tracks and
            creates the dynamic array based on the numTracks
******************************************************************* */
void CD::setNumTracks(int n)
{
    numTracks = n;
    tracks = new string[numTracks];
}
/* *****************************************************************
Function:   setTrack()
Inputs:     string t, int i
Outputs:    None
Purpose:    This function sets an individual track name to the dynamic
            array as long as the poistion is within the range of the numTracks
******************************************************************* */
void CD::setTrack(string t, int i)
{
    if (i >= 0 && i < numTracks)
        tracks[i] = t;
}
/* *****************************************************************
 Function:   getArtist()
Inputs:      string a
Outputs:     None
Purpose:     This function returns the value assigned to attribute artist
******************************************************************* */
string CD::getArtist()
{ return artist; }
/* *****************************************************************
 Function:   getTitle()
Inputs:      string t
Outputs:     string artist
Purpose:     This function returns the value assigned to attribute title
******************************************************************* */
string CD::getTitle()
{ return title; }
/* *****************************************************************
 Function:   getYear()
Inputs:      int y
Outputs:     string title
Purpose:     This function returns the value assigned to attribute year
******************************************************************* */
int CD::getYear()
{ return year; }
/* *****************************************************************
Function:   getNumTracks()
Inputs:     None
Outputs:    int year
Purpose:    This function returns the total number of tracks in the
            dynamic array
******************************************************************* */
int CD::getNumTracks()
{ return numTracks; }
/* *****************************************************************
Function:   getTrack
Inputs:     int n
Outputs:    string tracks[n]
Purpose:    This function gets an individual track name from the dynamic array
******************************************************************* */
string CD::getTrack(int n)
{ return tracks[n]; }
/* *****************************************************************
Function:   deleteTrack()
Inputs:     None
Outputs:    None
Purpose:    This function deletes the dynamic array tracks, reassigns
            it to null, and reassigns numTracks to 0, if the specific
            object has a value greater than 0 in numTracks
******************************************************************* */
void CD::deleteTracks()
{
    if (numTracks)
    {
        delete [] tracks;
        tracks = nullptr;
        numTracks = 0;
    }
}

//constant variable for array
const int SIZE = 17;

//Program Function Prototypes
int mainMenu();
void mathBreak();
int getMathBreakChoice();
void evenOdd();
bool isEven(int validNum);
void primeNumber();
bool isPrime(int userNumber);
int mathInputValidation(int input);
CD createCD(CD cd, string artist, string title, int year);
void readCollection(CD albums[], int size);
void displayAlbums(CD [], int);
void sortCollection(CD cds[], int);
void findACD(CD cds[], int);
int linearSearch(CD cds[], string target);
void editACD(CD cds[], int size);
void editIndividualCD(CD *album);
void addNumTracks(CD cds[], int size);
void deleteTracks(CD cds[], int size);
void findCdRecursive (CD cds[], int size);
bool cdRecursiveSearch(CD cds[], string target, int position, bool albumIndex);
void printBackwards(string userStr, int position);
void stringReverse();
char validStringResponse(char answer);

/* *****************************************************************
                            Main
******************************************************************* */
int main()
{
    //variable for main menu choice
    int mainMenuChoice;
    //creates cd class object array
    CD albums[SIZE];
    //declares and intializes cdFlag and sortFlag varaibles.
    bool cdFlag = false;

    //program main menu options displayed
    mainMenuChoice = mainMenu();
    //
    while (mainMenuChoice !=10)
    {
        //swtich based on user choice for math break
        switch (mainMenuChoice)
        {
            //option to read in cd.txt file data
            case 1:
            {
                //calls readCollection() and passes CD object array and array size
                readCollection(albums, SIZE);
                //checks to see if data is in CD object array. If not blank changes cdFlag to true
                if (albums[0].getArtist() != " ")
                    cdFlag = true;
                
            } //end case 1
                break;
            
            //option to display cd class object array
            case 2:
            {
                //if flag variable is true calls display ablum function
                if (cdFlag)
                    displayAlbums(albums, SIZE);
                //displays the below text prompting the user to select main menu option 1 have cd file read in
                else
                {
                    cout << "\n\n*******************************************************" << endl;
                    cout << "       THERE IS NO DATA TO **DISPLAY** YET        " << endl;
                    cout << "PLEASE SELECT OPTION 1 TO READ IN CD COLLECTION FIRST" << endl;
                    cout << "*******************************************************\n\n";
                }
            } //end case 2
                break;
            //option to sort CD collection data
            case 3:
            {
                //if data has been read in and cdFlag is true CD object albums is sorted and bool sortFlag
                //variable is changed to true
                if (cdFlag)
                {
                    sortCollection(albums, SIZE);
                }
                //displays the below text prompting the user to select main menu option 1 have cd file read in
                else
                {
                    cout << "\n\n*******************************************************" << endl;
                    cout << "       THERE IS NO DATA TO **SORT** YET        " << endl;
                    cout << "PLEASE SELECT OPTION 1 TO READ IN CD COLLECTION FIRST" << endl;
                    cout << "*******************************************************\n\n";
                }
            }//end case 3
                break;
                
            //option to search for a cd from collection data
            case 4:
            {
                //if both flag variables are true, calls findACD()
                if (cdFlag)
                    findACD(albums, SIZE);
            
                //displays the below text prompting the user to select main menu option 1 have cd file read
                //in if cdFlag is false
                else if (!cdFlag)
                {
                    cout << "\n\n*******************************************************" << endl;
                    cout << "       THERE IS NO DATA TO **FIND** YET        " << endl;
                    cout << "PLEASE SELECT OPTION 1 TO READ IN CD COLLECTION FIRST" << endl;
                    cout << "*******************************************************\n\n";
                }
            }
                break;
            
            //option to search for a cd using a recursive function
            case 5:
            {
                if (cdFlag)
                {
                    cout << "in recursive CD search case" << endl;
                    //if flag varaible is true calls findCdRecursive()
                    findCdRecursive(albums, SIZE);
                }
                
                else
                {
                    cout << "\n\n*******************************************************" << endl;
                    cout << "       THERE IS NO DATA TO **FIND** YET        " << endl;
                    cout << "PLEASE SELECT OPTION 1 TO READ IN CD COLLECTION FIRST" << endl;
                    cout << "*******************************************************\n\n";
                }
                
            }
                break;
            
            //option to edit a cd from collection data
            case 6:
            {
                //if flag variable is true calls editACD()
                if (cdFlag)
                    editACD(albums, SIZE);
                //else displays the below text prompting the user to select main menu option 1 have cd file read in
                else
                {
                    cout << "\n\n*******************************************************" << endl;
                    cout << "          THERE IS NO DATA TO **EDIT** YET        " << endl;
                    cout << "PLEASE SELECT OPTION 1 TO READ IN CD COLLECTION FIRST" << endl;
                    cout << "*******************************************************\n\n";
                }
            }
                break;
            
            //Add Tracks to a selected CD object
            case 7:
            {
                //if flag variable is true calls addNumTracks()
                if (cdFlag)
                    addNumTracks(albums, 17);
                
                //else displays the below text prompting the user to select main menu option 1 have cd file read in
                else
                {
                    cout << "\n\n*******************************************************" << endl;
                    cout << "          THERE IS NO DATA TO **ADD TRACKS TO ** YET       " << endl;
                    cout << "PLEASE SELECT OPTION 1 TO READ IN CD COLLECTION FIRST" << endl;
                    cout << "*******************************************************\n\n";
                }
            }
                break;
            
            //Delete all Tracks from a selected CD object
            case 8:
            {
                //if flag variable is true calls deleteTracks()
                if (cdFlag)
                    deleteTracks(albums, 17);
                
                //else displays the below text prompting the user to select main menu option 1 have cd file read in
                else
                {
                    cout << "\n\n*******************************************************" << endl;
                    cout << "      THERE IS NO DATA TO **DELETE TRACKS FROM** YET       " << endl;
                    cout << "PLEASE SELECT OPTION 1 TO READ IN CD COLLECTION FIRST" << endl;
                    cout << "*******************************************************\n\n";
                }
            }
                break;
                
            //math break option
            case 9:
            {
                //calls mathBreak()
                mathBreak();
            }
                break;
        }
        //prompts user for next choice
        mainMenuChoice = mainMenu();
    }
    //condition for loop to iterate
    //as long as the choice is valid and is not 7, loop again
    return 0;
}//end of main

/* *****************************************************************
Function:   mainMenu
Inputs:      None
Outputs:    validated main menu choice from user
Purpose:    This function displays the main menu options for the user to choose from
            and validates their choice to make sure it is an option provided.
******************************************************************* */
int mainMenu()
{
    //decleration for main menu option
    int mainMenuChoice;
    //do-while loop for displaying main menu and validating user input
    do
    {
        //displays main menu
        cout << "                  Main Menu\n";
        cout << "------------------------------------------------\n";
        cout << "1. Read Collection\n";
        cout << "2. Display Collection\n";
        cout << "3. Sort Collection\n";
        cout << "4. Find a CD\n";
        cout << "5. Find a CD *Recursive Version*\n";
        cout << "6. Edit a CD\n";
        cout << "7. Add Tracks for a CD\n";
        cout << "8. Delete All Tracks for a CD\n";
        cout << "9. Math Beak\n";
        cout << "10. Quit\n\n";
        cout << "Please Enter Number for Corresponding Choice: ";
        //user menu choice
        cin >> mainMenuChoice;
        
        //input validation check
        while (mainMenuChoice < 1 || mainMenuChoice > 10)
        {
            //displays below instead of relisting all menu options
            cout << "\n\n**************************************************\n";
            cout << "INVALID CHOICE - Please Enter a Listed Option: ";
            cin >> mainMenuChoice;
        }
    //continue to iterate until contidtions are met
    } while (mainMenuChoice < 1 || mainMenuChoice > 10);
    
    return mainMenuChoice;
} //end of mainMenu()


/* *****************************************************************
//Function:   mathBreak
//Inputs:     None
//Outputs:    None
//Purpose:    function that calls getMathBreakChoice, takes the validated input
              from said function, and plays the math game selected by the user
******************************************************************* */
void mathBreak()
{
    //decleration for user math break choice
    int mathBreakChoice;
    //assigns validated user input to variable
    mathBreakChoice = getMathBreakChoice();
    
    //if user does not want to exit math break
    while (mathBreakChoice !=4)
    {
        //if input is 1, evenOdd function is called
            if (mathBreakChoice == 1)
                evenOdd();
            
            //if input is 2, primeNumber function is called
            else if (mathBreakChoice == 2)
                 primeNumber();
            //if input is 3, string reverse is called
            else if (mathBreakChoice == 3)
                stringReverse();
        
        //prompts user for next choice
        mathBreakChoice = getMathBreakChoice();
    }
} //end of mathBreak()

/* *****************************************************************
//Function:  mathBreakMenu
//Inputs:       None
//Outputs:    None
//Purpose:    This function displays the math break games options for the user to choose from
******************************************************************* */
int getMathBreakChoice()
{
    //decleration for math break menu option
    int mathBreakChoice;
    
    do
    {
        //display math break menu
        cout << "\n    Math Break Menu\n";
        cout << "------------------------\n";
        cout << "1. Even or Odd\n";
        cout << "2. Prime Number\n";
        cout << "3. String Reverse\n";
        cout << "4. End my Math Break\n";
        cout << "\nEnter a Choice: ";
        //user choice input
        cin >> mathBreakChoice;
        
        
        //input validation check
        while (mathBreakChoice < 1 || mathBreakChoice > 4)
        {
            //displays below instead of relisting all menu options
            cout << "**************************************************";
            cout << "\nINVALID CHOICE - Please Enter a Listed Option: ";
            cin >> mathBreakChoice;
        }
        
    }while (mathBreakChoice <1 || mathBreakChoice >4);
        
    return mathBreakChoice;
} //end of mathBreakMenu()

/* *****************************************************************
Function:   evenOdd
Inputs:       None
Outputs:    None
Purpose:    This function asks for user input for the even odd game,
        validates the data to make sure it is a positive integer,
        passes the valid input to the isEven function. The value
        from the isEven function is eveluated to be even if the
        result is true or odd if false. The user is prompted again
        for another number unless they enter 0 to exit
******************************************************************* */
void evenOdd()
{
    //variables for user input
    int input, validUserNumber;
    //varaible to store isEven function returned value
    bool evenOddResult;
    
    //displays game name, instructions and asks for user input
    cout << "\n-----------Even or Odd Game-----------\n";
    cout << "Enter a positive integer or 0 to exit: ";
    cin >> input;
    
    //validation of user input through mathInputValidation function
    validUserNumber = mathInputValidation(input);
    
    //loop using validated user input
    //as long as the user does not enter 0 exit the game the loop proceedes
    while (validUserNumber != 0)
    {
        //stores returned value from isEven in bool variable evenOddResult
        evenOddResult = isEven(validUserNumber);
        //if bool variable evenOddResult is true, displays number
        //and indicates number is even
        if (evenOddResult == true)
            cout << "\n" <<validUserNumber << " is Even!\n";
        //if bool variable evenOddResult is false, displays number
        //and indicates number is odd
        else
            cout << "\n" << validUserNumber << " is Odd!\n";
        
        //re-displays game name, instructions and asks for user input
        cout << "\n-----------Even or Odd Game-----------\n";
        cout << "Enter a positive integer or 0 to exit: ";
        cin >> input;
        
        //validation of user input through mathInputValidation function
        validUserNumber = mathInputValidation(input);
    }
} //end of evenOdd()

/* *****************************************************************
Function:   isPrime()
Inputs:       None
Outputs:    None
Purpose:    This function asks for user input for the Prime Number
        game, validates the data to make sure it is a positive integer,
        passes the valid input to the isPrime function. The value
        from the isPrime function is eveluated to be prime if the
        result is true or not prime if false. The user is prompted again
        for another number unless they enter 0 to exit
******************************************************************* */
void primeNumber()
{
    //variables to store user input
    int userNumber, validUserNumber;
    //varaible to store isPrime function returned value
    bool primeNumberResult;
    
    //primeNumber game menu instructions and user input
    cout << "\n-----------Prime Number Game-----------\n";
    cout << "Enter a positive integer or 0 to Exit: ";
    cin >> userNumber;
    
    //user input is validated with mathInputValidation Function
    validUserNumber = mathInputValidation(userNumber);
    
    //while loop iterates with valid input unless it is 0
    while (validUserNumber != 0)
    {
        //bool variable primeNumberResult stores returned value from isPrime
        primeNumberResult = isPrime(validUserNumber);
        
        //if primeNumberResult is true, user's number is displayed and
        //program indicates number is prime
        if (primeNumberResult == true)
            cout << "\n" << validUserNumber << " is prime!\n";
        //if primeNumberResult is false, user's number is displayed and
        //program indicates it is not prime
        else
            cout << "\n" <<validUserNumber << " is not prime!\n";
        
        //re-displays game name, instructions and asks for user input
        cout << "\n-----------Prime Number Game-----------\n";
        cout << "Enter a positive integer or 0 to Exit: ";
        cin >> userNumber;
        
        //user input is validated with mathInputValidation Function
        validUserNumber = mathInputValidation(userNumber);
    }
} //end of primeNumber()

/* *****************************************************************
Function:   mathInputValidation
Inputs:     user input
Outputs:    input
Purpose:    The Math games must have positive integers. This function takes in user input,
        checks to see if the number is greater than 0.If it is not, the loop iterates again.
        This will continue until input is greater than 0.
******************************************************************* */
int mathInputValidation(int input)
{
    //loop iterates if input from math games is less than 0
    while (input < 0)
    {
        //displays messagse to user their input was invaild
        cout << "\nInvalid Number\n";
        cout << "Enter a positive integer or 0 to quit: ";
        //prompts for another number
        cin >> input;
    }
    
    //once valid, returns input
    return input;
} //end of mathInputValidation()

/* *****************************************************************
Function:   IsEven()
Inputs:     validated number (greater than 0)
Outputs:    Boolean value in varaible result
Purpose:    This function uses mod divsion to check and see if a number
            is even. If 2 is a factor of the user's chosen number, the
            number is even. If there is a remainder for the user's number
            being divided by 2, the nubmer is odd.
******************************************************************* */
bool isEven(int validNum)
{
    //bool variable to store result if user number is even or odd
    bool result;
    //mod division by two to see if there is a remainder.
    //If no remainder number is even
    if (validNum % 2 == 0)
        result = true;
    //if there is a remainder, number is odd
    else
        result = false;
    //returns boolean value in result
    return result;
} //end of isEven()

/* *****************************************************************
Function:   IsPrime()
Inputs:     validated number (greater than 0) from  user input, userNumber
Outputs:    Boolean value in varaible result
Purpose:    This function takes the user's chosen number, and iterates through
            1 through the user's number to find if it is prime. If a number is a factor
            of the user's number, 1 is added to the counter variable. A prime number
            can only have two factors, 1 and itself. If the counter variable is equal to
            two once all iterations have completed the number is believed to be prime.
            If the counter variable is anything else, the number is not prime.
            (i.e the number 1 cannot be prime, while 2 is prime)
******************************************************************* */
bool isPrime(int userNumber)
{
    //bool variable to store result if user number is prime or not
    bool result;
    //counter variable for number of factors from the user's chosen number
    int count = 0;
    
    //loop from 1 to user's number, increasing by 1. Quotient variable
    //initialized to store answer to determine if i is a factor of the
    //user's number
    for(int i = 1, quotient; i <= userNumber; i++)
    {
        //divides user input by i value in iteration
        quotient = userNumber % i;
        
        //if user number is cleanly divided by i value in iteration, add 1 to count
        if (quotient == 0)
            count += 1;
    }
    //if count variable is 2 the number is prime and displays on screen
    if (count == 2)
        result = true;
    //if count varaible is anything other than 2, the number is not prime.
    else
        result = false;
    //returns bool value in result variable
    return result;
} //end of isPrime()

/* *****************************************************************
Function:   stringReverse()
Inputs:     None
Outputs:    None
Purpose:    Takes in user input for a string to be reversed. printBackwards()
            recursive function is called passing in the user's string and 0
            for the position
******************************************************************* */
void stringReverse()
{
    //variable decleration
    string userString;
    
    //clears input buffer of numbers
    cin.ignore();
    //prompts user for string that will be reversed
    cout << "Enter something and it will be reversed for you: ";
    getline(cin, userString);
    //formatting to have printbackwards() output on a new line.
    cout << "\n" << endl;

    //printBackwards() is called passing user input
    printBackwards(userString, 0);
    
    //formatting for a new line
    cout << "\n" << endl;
}

/* *****************************************************************
Function:   stringReverse()
Inputs:     string userStr, int position (0)
Outputs:    None
Purpose:    Recursive function that takes in a user string and the initial
            position (0). If the position is less than the length of user's
            string, the function is called again and 1 is added to the position.
            Nothing happens before the function reaches its base case. Before
            the function returns, the cout statement runs back unitl it reaches
            the inital position.
******************************************************************* */
void printBackwards(string userStr, int position)
{
    //base case
    //if postion is less than the length of the user input string
    if (position < userStr.length())
    {
        //printBackwards() is recursivly called and the position is advanced by 1
        printBackwards(userStr, position+1);
        //prints out the position in the string
        cout << userStr[position];
    }
}//end stringReverse()


/* *****************************************************************
Function:   readCollection()
Inputs:     CD albums[], int size
Outputs:    None
Purpose:    opens and reads in text from file to file object. If the
            file can be opened and read in, a loop iterates through
            assigning data to each cd object in the array
******************************************************************* */
void readCollection(CD albums[], int size)
{
    //creates file object
    ifstream cdFile;
    //declartion for year, artist and album year variables
    int year;
    string artist, title;
    //opens cd.txt file
    cdFile.open("cd.txt");
    //if the cd.txt file was opened and read into cdFile
    if (cdFile)
    {
        for (int i = 0; i < SIZE; i++)
        {
            //reads file object line for artist name
            getline(cdFile, artist);
            //reads file object line for album title
            getline(cdFile, title);
            //reads file object line for album year
            cdFile >> year;
            //clears input buffer in order for text to be entered at next iteration
            cdFile.ignore(100, '\n');
            
            //makes assignments to cd class object
            albums[i] = createCD(albums[i], artist, title, year);
        }
        //closes cd.txt file
        cdFile.close();
        //displays once loop has completed reading in data to cdFile
        cout << "\n\nCD Data Has Been Read in\n\n";
    }
    //if cd.txt could not be opened and read into cdFile, display:
    else
        cout << "File could not be opened\n";
} //end readCollection()

/* *****************************************************************
Function:   Create CD()
Inputs:     CD cd, string artist, string title, int year
Outputs:    CD Object
Purpose:    takes inputs and assigns data to each individual cd object
            in array that was passed
******************************************************************* */
CD createCD(CD cd, string artist, string title, int year)
{
    //setter method of CD class attribute artist
    cd.setArtist(artist);
    //setter method for CD class attribute title
    cd.setTitle(title);
    //setter method for CD class attribute year
    cd.setYear(year);
    
    //returns CD class object
    return cd;
} //end of createCD()

/* *****************************************************************
Function:   displayAlbums()
Inputs:     albums array and size of array
Outputs:    None
Purpose:    This function takes displays the CD class object array "albums" with
            a for loop that sets each array item on its own line.
******************************************************************* */
void displayAlbums(CD cds[], int size)
{
    //column headers for displaying CD object array
    cout << "\n" << setw(13) << right << "\tArtist"
    << setw(25) << "Title"
    << setw(25) << "Year" << endl;;
    
    //loop that displays each CD object array item individually
    for (int index = 0; index < size; index++)
    {
        cout << setw(30) << left << cds[index].getArtist()
        << setw(30) << cds[index].getTitle()
        << setw(30) << cds[index].getYear() << "\n";
        if (cds[index].getNumTracks())
        {
            for (int i = 0; i<cds[index].getNumTracks(); i++)
                cout << "\t" << i+1 << ". " << cds[index].getTrack(i) << endl;
        }
    }
} //end displayAlbums()

/* *****************************************************************
Function:   sortCollection()
Inputs:     CD cds[], int size
Outputs:    None
Purpose:    Sorts the data alphabetically through the use of a nested
            for loop. The outer loop starts with the assumption that
            the first object is the largest. The inner loop then compares
            the next item in the array to the assumed largest variable.
            The inner loop will make comparisons against each item swapping
            if it finds something bigger. Once the end of the inner loop is
            reached, the biggest found variable is assigned to a temp variable,
            the variable in the array that holds the last spot is swapped to the
            index location of the biggest variable, and the biggest found variable
            is assigned to the last spot in the array. This process repeats until
            the outter loop has run through all its iterations.
******************************************************************* */
void sortCollection(CD cds[], int size)
{
    //Variable declarations
    string biggestBand;
    int albumIndex, last;
    CD tempCD;
    //assigns last to one less than size of CD object array
    last = SIZE - 1;
    //loops through
    for (int x = 0; x < SIZE; x++)
    {
        //assumes largest band is first in the CD object array
        biggestBand = cds[0].getArtist();
        //assigns index to 0 under the assumption biggest band is first in CD object array
        albumIndex = 0;
        
        //nested loop to start comparison
        for (int y = 1; y <= last; y++)
        {
            //compares each band to biggestBand variable
            if (cds[y].getArtist() > biggestBand)
            {
                //if true biggest band variable is reasigned to value at cds[y]
                biggestBand = cds[y].getArtist();
                //index also reassigned to current value of y in loop
                albumIndex = y;
            }
        }
        //once nested loop done comparing, temp CD object array variable is assigned to value at highest band
        tempCD = cds[albumIndex];
        //last object in array is assigned to spot where cds[albumindex] is located
        cds[albumIndex] = cds[last];
        //true largest band is assigned to "last spot"
        cds[last] = tempCD;
        //last int is reduced by one and loop iterates again.
        last --;
    }
    cout << "\nCD collection has been sorted\n" << endl;
} //end sortCollection()

/* *****************************************************************
Function:   findACD()
Inputs:     CD array, int size of array
Outputs:    None
Purpose:    takes in user string input for target variable for the cd search.
            The CD array and search target are passed into the linear search
            function. A bool value is returned to the inCollection variable.
            the value of inCollection determines if a statement saying the cd
            is or is not in the collecetion is displayed.
******************************************************************* */
void findACD(CD cds[], int size)
{
    //decleration of varaibles
    string artist, title, target;
    int inCollection;
    
    //clears input buffer for user text input
    cin.ignore();
    //prompts user for Artist name
    cout << "Enter Arist Name: ";
    getline(cin, artist);
    //prompts user for Album Title name
    cout << "Enter Album Title: ";
    getline(cin, title);
    
    //assigns user input to string variable target for comparison
    target = artist + " " + title;
   
    //passes cd array and album target to linearsearch()
    inCollection = linearSearch(cds, target);
    
    //if index from linearSearch is true
    if (inCollection >= 0)
        cout << "\nCD - " << cds[inCollection].getArtist() + " " + cds[inCollection].getTitle() << " is in the collection\n" << endl;
    //if index from linearSearch is false
    else
        cout << "\nCD - " << target << " is not in the collection.\nCheck your spelling or go out and get it!\n" << endl;
} //end findACD()

/* *****************************************************************
Function:   linearSearch()
Inputs:     CD array, string of target variable
Outputs:    bool value of cdFound Flag
Purpose:    linearSearch starts at the beginng of the CD array object
            and compares the search target variable to the artist and
            title values of each CD array object. If the search target
            is found the loop stops and returns the CD object array
            index where the target was found.
******************************************************************* */
int linearSearch(CD cds[], string target)
{
    //variable declarations
    bool cdFound = false;
    int albumIndex = -1;
    
    //foor loop that compares each CD array object to the search target
    for (int i =0; i < SIZE && !cdFound; i++)
    {
        //if the target is equal to a created string of the CD array object's atist and title
        //loop stops iterating once cdFound is true
        if (target == cds[i].getArtist() + " " + cds[i].getTitle())
        {
            //cdFound flag is changed to true
            cdFound = true;
            albumIndex = i;
        }
    }
    return albumIndex;
} //end linearSearch()


/* *****************************************************************
Function:   editACD
Inputs:     CD Array, Array size
Outputs:    None
Purpose:    function asks for artist and album name. LinearSearch()
            is used to check against collection. If album is in
            collection, the index value from the CD object array is
            returned, if not -1 is returned. If an index is returned
            the specific CD array object is passed by reference for editing.
******************************************************************* */
void editACD(CD cds[], int size)
{
    //varaible declerations
    string albumToEdit, artist, title;
    int albumIndex;
    
    //clears input buffer
    cin.ignore();
    //prompts user for artist name and album title
    cout << "Enter Artist Name: ";
    getline(cin, artist);
    cout << "Enter Album Title: ";
    getline(cin, title);
    
    //assigns user input into albumToEdit string variable
    albumToEdit = artist + " " + title;
    
    //calls linearSearch function and passes CD object array and potential album to edit should the album
    //exist in the collection. result of search is returned to albumIndex variable
    albumIndex = linearSearch(cds, albumToEdit);
    
    //If albumIndex is equal to or greater than 0, it means the album was found and the index of the object
    //in the array was passed back.
    if (albumIndex >= 0)
    {
        cout << "\n" <<albumToEdit << " is in the collection" << endl;
        //editIndividualCD is called and the with the specific object from the CD array to be edited
        editIndividualCD(&cds[albumIndex]);
        cout << cds[albumIndex].getArtist() + " " + cds[albumIndex].getTitle() << " has been edited" << endl;
    }
        
    //if -1 is returned, the requsted album was not found and the below shows for the user
    else
    {
        cout << "\nCD - " << albumToEdit << " is not in the collection.\nCheck your spelling or go out and get it!\n" << endl;
    }
    
} //end editACD()

/* *****************************************************************
Function:   editIndividualCD
Inputs:     Specific Object from CD array
Outputs:    None
Purpose:    Asks the user for choice on what part of the object they
            want to edit, unless they select 4 in which the loop is
            exited. Option 1 edits the Artist name. Option 2 edits
            the Album title. Option 3 edits the album's release year.
            Once the user enters the new info the menu appears again
            if there are more edits to make or to exit.
******************************************************************* */
void editIndividualCD(CD *album)
{
    //variable declerations
    int choice, year;
    string artist, title;
    
    //displays menu of choices for user on what they can edit
    cout << "\n*************************\n";
    cout << setw(18) << right <<"Edit Album\n";
    cout << "*************************\n\n";
    cout << "1. Edit Artist\n";
    cout << "2. Edit Title\n";
    cout << "3. Edit Year\n";
    cout << "4. Exit\n";
    cout << "Enter Choice To Edit: ";
    //asks the use their choice what
    cin >> choice;
    
    //while the choice is not 4 (or quit)
    while (choice !=4)
    {
        switch (choice)
        {
            //if option 1 is selected
            case 1:
            {
                //clears input buffer for text to be entered
                cin.ignore();
                cout << "Enter New Aritst Name: ";
                getline(cin, artist);
                //assigns input to specific object artist
                album->setArtist(artist);
                break;
            }
            case 2:
            {
                //clears input buffer for text to be entered
                cin.ignore();
                //prompts
                cout << "Enter New Album Title Name: ";
                getline(cin, title);
                //assigns input to specific object title
                album->setTitle(title);
                break;
            }
            case 3:
            {
                //prompts user to enter the new year for album
                cout << "Enter New Year: ";
                cin >> year;
                //assigns input to specific object year
                album->setYear(year);
                break;
            }
        }
        //displays menu again if the user wants to edit something else in the object
        cout << "\n*************************\n";
        cout << setw(18) << right <<"Edit Album\n";
        cout << "*************************\n\n";
        cout << "1. Edit Artist\n";
        cout << "2. Edit Title\n";
        cout << "3. Edit Year\n";
        cout << "4. Exit\n";
        cout << "Enter Choice To Edit: ";
        cin >> choice;
    }
} //end editIndividualCD()

/* *****************************************************************
Function:   addNumTracks()
Inputs:     CD array, size of array
Outputs:    None
Purpose:    Function searches for user requested CD, if found asks the
            user for the number of tracks the CD has, and then asks the
            user for the names of each track.
******************************************************************* */
void addNumTracks(CD cds[], int size)
{
    //variable declerations
    string albumToAddTracks, artist, title, track;
    int albumIndex, numberOfTracks;
    
    //clears input buffer
    cin.ignore();
    //prompts user for artist name and album title
    cout << "Enter Artist Name: ";
    getline(cin, artist);
    cout << "Enter Album Title: ";
    getline(cin, title);
    
    //assigns user input into albumToEdit string variable
    albumToAddTracks = artist + " " + title;
    
    //asigns postion of album to album index
    albumIndex = linearSearch(cds, albumToAddTracks);
    
    //If albumIndex is equal to or greater than 0, it means the album was found and the index of the object
    //in the array was passed back.
    if (albumIndex >= 0)
    {
        cout << "\n" <<albumToAddTracks << " is in the collection" << endl;
        //prompts user for number of tracks to add
        cout << "How Many Tracks: ";
        cin >> numberOfTracks;
        
        //the number of tracks is assigned to the specific object.
        cds[albumIndex].setNumTracks(numberOfTracks);
        //clears unput buffer
        cin.ignore();
        
        cout << "Enter Track Names:\n";
        //loops through number of tracks user indicated the album has
        //and prompts the user for their names
        for(int i=0; i<numberOfTracks; i++)
        {
            cout << i+1 << ". ";
            getline(cin, track);
            //assigns the track name to the dynamic string array
            cds[albumIndex].setTrack(track, i);
        }
    }
        
    //if -1 is returned, the requsted album was not found and the below shows for the user
    else
    {
        cout << "\nCD - " << albumToAddTracks << " is not in the collection.\n" <<
        "Check your spelling or go out and get it!\n" << endl;
    }
}
/* *****************************************************************
Function:   deleteTracks()
Inputs:     CD array, size of array
Outputs:    None
Purpose:    Function searches for user requested CD, if found, and the
            CD object has tracks already assigned to it, the deleteTracks()
            is called and tracks are deleted. If There are no tracks
            assigned to the CD object, the deleteTracks function is not called.
******************************************************************* */
void deleteTracks(CD cds[], int size)
{
    //variable declerations
    string albumToDeleteTracks, artist, title;
    int albumIndex;

    //clears input buffer
    cin.ignore();
    //prompts user for artist name and album title
    cout << "Enter Artist Name: ";
    getline(cin, artist);
    cout << "Enter Album Title: ";
    getline(cin, title);

    //assigns user input into albumToDeleteEdit string variable
    albumToDeleteTracks = artist + " " + title;

    //result from search is assigned to albumIndex
    albumIndex = linearSearch(cds, albumToDeleteTracks);

    //if an album is found and the user has assigned tracks to a CD object
    if (albumIndex >= 0 && cds[albumIndex].getNumTracks() > 0)
    {
        //the deleteTracks member function is called and tracks are deleted
        cds[albumIndex].deleteTracks();
        cout << "\nThe CD - " << albumToDeleteTracks << " - tracks have been deleted.\n\n";
    }
    //if the album is found, but the CD object has no assigned tracks user is told as much
    else if (albumIndex >= 0 && cds[albumIndex].getNumTracks() == 0)
        cout << "\nThe CD - " << albumToDeleteTracks << " - has no tracks to delete.\n\n";
     
    //if cd is not found in search
    else
    {
        cout << "\nCD - " << albumToDeleteTracks << " - is not in the collection.\n" <<
        "Check your spelling or go out and get it!\n" << endl;
    }
}//end deleteTracks()

/* *****************************************************************
Function:   findCdRecursive()
Inputs:     None
Outputs:    None
Purpose:    Obtains the string from the user cdRecursiveSearch will search
            for, CD array, search target, intial postion of 0 and bool albumIndex
            is passed to cdRecursiveSearch() which assigns its return value to
            inCollection. The user is informed if the CD is found or not.
******************************************************************* */
void findCdRecursive (CD cds[], int size)
{
    //decleration of varaibles
    string artist, title, target;
    int inCollection;
    bool albumIndex = false;
    
    //clears input buffer for user text input
    cin.ignore();
    //prompts user for Artist name
    cout << "Enter Arist Name: ";
    getline(cin, artist);
    //prompts user for Album Title name
    cout << "Enter Album Title: ";
    getline(cin, title);
    
    //assigns user input to string variable target for comparison
    target = artist + " " + title;
   
    //passes cd array and album target to binarysearch()
    inCollection = cdRecursiveSearch(cds, target, 0, albumIndex);
    
    //if index from binarySearch is true
    if (inCollection)
        cout << "\nCD - " << target << " is in the collection\n" << endl;
    //if index from binarySearch is false
    else
        cout << "\nCD - " << target << " is not in the collection.\nCheck your spelling or go out and get it!\n" << endl;
} //end findCdRecursive()

/* *****************************************************************
Function:   cdRecursiveSearch()
Inputs:     None
Outputs:    bool albumIndex
Purpose:    Searches the CD object array comparing the artist and title
            to the target. After each comparision, if the album is not
            found the cdRecursiveSearch is run again adding 1 to the postion
            to compare to the next CD array object. If the target is found
            albumIndex is changed to true and the boolean varaible albumIndex
            is returned. If the search target is not found, the albumIndex is
            returned (as false).
******************************************************************* */
bool cdRecursiveSearch(CD cds[], string target, int position, bool albumIndex)
{
    //base case
    //if postion is equal to array size, then return the bool albumIndex variable.
    //if this happens it means the album was not found and "false" is being returned
    if (position == SIZE)
       return albumIndex;
    
    //if the artist and title of the postion in the CD array object is equal to the target
    else if (cds[position].getArtist() + " " + cds[position].getTitle() == target)
    {
        //change albumIndex to "true" and return the albumIndex variable
        albumIndex = true;
        return albumIndex;
    }
    
    //if neither of the above cases are true
    else
    {
        //call cdRecursiveSearch() again adding 1 to the position
        return cdRecursiveSearch(cds, target, position+1, albumIndex);
    }
} //end cdRecursiveSearch()
