/* 
NAME: Samantha Sax

changelog:
2/15/20 - made scaffolding of the project - input validation function complete
          wrote matrix read in function and read in movie titles into an array - potential problems with flexibility
2/16/20   changed the array for movie titles to a vector for ease of iterating through in a loop via size()
          wrote the search function using parallel arrays for direction searching
2/18/20   commented out debugging code and refined layout
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include<string>

using namespace std;

//for use in searching the matrix
int xDirection[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int yDirection[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
string direction[] = {"NW", "N", "NE","W", "E","SW","S","SE" };

//skip through comment lines
void skipAnyCommentLines(ifstream& infile) {
    string textLine;
    char ch;
    ch = infile.peek();
    while (ch == '#' || ch == '\n') {
        getline(infile, textLine);
        ch = infile.peek();
    }
    //when we leave, we're at a non-comment, non-blank line
} //skipAnyCommentLines

//validate input or quit
void inputErrorAndValid(ifstream& infile, string userInfile) {
    bool badFile = true;

    //while the user file cannot be read
    while (badFile == true) {
        cout << "The file name you entered could not be opened.\n";
        cout << "The file you entered is: " << userInfile << ".\n";
        cout << "Please enter another file name, or enter \"quit\" to exit\n";

        cin >> userInfile;

        if (userInfile == "quit") {
            break;
        }

        //try to open file again
        infile.open(userInfile);


        if (infile) {
            //if the file opened successfully
            badFile = false;
            cout << "File opened successfully.\n";
            break;
        }

        //if the file still could not be opened, loop until user enters valid file name or "quit"
        else
        {
            badFile = true;
        }
    }
}

bool getUserInFile(ifstream& infile, string userInfile) {

    cout << "Please enter a file name and location" << endl;
    cin >> userInfile;

    infile.open(userInfile);

    //if the file didnt open successfully
    if (infile) {
        return(true);
        //PROCESS DATA


    }

    //if the file did open successfully, process it
    else {

        inputErrorAndValid(infile, userInfile);
        //PROCESS DATA
    }
}


void getMatrixDimen(ifstream& infile, int& MAT_ROW, int& MAT_COL) {

    //skip down to first non comment line
    skipAnyCommentLines(infile);
    //get matrix dimentions
    infile >> MAT_ROW >> MAT_COL;
    cout << "Number of rows: " << MAT_ROW << endl;
    cout << "Number of columns: " << MAT_COL << endl;
}

    //read in matrix to console
void readInMatrix(ifstream& infile, int MAT_ROW, int MAT_COL, char gameMatrix[][100]) {
    //skip any comment lines
    skipAnyCommentLines(infile);

    //read in each character into the array gameMatrix
    //and display results to the console
    for (int i = 0; i < MAT_ROW; i++) {
        for (int j = 0; j < MAT_COL; j++) {
            infile >> gameMatrix[i][j];
            cout << gameMatrix[i][j];
        }
        cout << endl;
    }
}

void getTitleIntoVector(ifstream& infile, vector<char>& movieTitle, string& title) {
    
    skipAnyCommentLines(infile);
    //make sure the vector is empty
    movieTitle.clear();
    
    char ch;
    //read in a line and copy it into the vector
    getline(infile, title);
    copy(title.begin(), title.end(), back_inserter(movieTitle));
    
    //DEBUGGING 
   //for (unsigned int i = 0; i < movieTitle.size(); i++) {
      //  cout << movieTitle[i];
    //}
}

bool searchMatrix(char gameMatrix[][100], vector<char>& movieTitle, vector<string>& foundMovies, int MAT_ROW,
    int MAT_COL, int x, int y, int xDirection[8], int yDirection[8], string title) {
   
    //check first position
    int tI = 0;

    //DEBUGGING
    // cout << x << " " << y << endl;

    //if the movie title first letter and game matrix dont match return false
    if (movieTitle[tI] != gameMatrix[x][y]) {
       
        //DEBUGGING
       // cout << "no match 1" << endl;
        return (false);
    }

    //if it does match, it will fall through to here. Check 8 directions
    for (int check = 0; check < 8; check++) {
       
        //we've already checked the starting x,y,tI, so reassign accordingly
        int xMove = x + xDirection[check];
        int yMove = y + yDirection[check];
        string directionFound = direction[check];
        
        //now iterate through movieTitle
        for (tI = 1; tI < movieTitle.size(); tI++) {

            //bounds check and equality check, break if this is violated
            if ((xMove < 0) || (xMove >= MAT_ROW) || (yMove < 0) || (yMove >= MAT_COL) ||
                (gameMatrix[xMove][yMove] != movieTitle[tI])) {
               //DEBUGGING
                // cout << "OOB" << endl;
                break;
            }

            //if it falls through to here, it didn't break, so move in the same direction and check again
            //until it hits the size of the movie title
            xMove = xMove + xDirection[check];
            yMove = yMove + yDirection[check];
        }

        //if it gets here, it hit the length of the movie title, so the title was found
        if (tI == movieTitle.size()) {
            cout << "Title: " << title << " complete in "<< direction[check]<< " direction" << endl;
            return(true);
        }
       }
        //else return false
        return(false);
 }
      
    //  search in all 8 directions  
    bool checkForFirstMatch(char gameMatrix[][100], vector<char>& movieTitle, vector<string>& lostMovies,
        string title, int MAT_ROW, int MAT_COL, int index, int x, int y)
    {
        //for use in determining lost movie titles
        bool flag = false;

        //check for the first letter systematically through the matrix
        for (int x = 0; x < MAT_ROW; x++) {
            for (int y = 0; y < MAT_COL; y++) {

                //if this returns true, output message saying the title was found
                if (searchMatrix(gameMatrix, movieTitle, lostMovies, MAT_ROW, MAT_COL, x, y,
                    xDirection, yDirection, title)) {
                    //set the lost movie flag to true so we dont lump it into the lost vector
                    flag = true;
                    cout << "Found at " << x << ", "
                        << y << endl;
                }
               
            }
        }
        //return the lost movie flag
        return(flag);
    }

    //display the lost movies in the lost movie vector
    void displayLostMovies(vector<string>& lostMovies) {
        for (int i = 0; i < lostMovies.size(); i++) {
            cout << lostMovies[i] << " could not be found\n";
        }
   }
    

    //MAIN FUNCTION
int main()
{
    //for game matrix and reading in movie titles
    char gameMatrix[100][100];
    vector<char> movieTitle(4);
    vector<string> lostMovies(1);
    
    //make sure lost movies vector is empty
    lostMovies.clear();
   
    //for use in storing movie titles into found array 
    string title;
    string userInfile;

    //for matrix size and searching
    int index=0, x=0, y=0;
    int MAT_ROW, MAT_COL;
    
    ifstream infile;
    
    //DEBUGGING
    //infile.open("searchtest1.txt");

    //validate and get user file name input
    if (getUserInFile(infile, userInfile)) {
        cout << "file open" << endl;

        //get matrix dimentions
        getMatrixDimen(infile, MAT_ROW, MAT_COL);
        //read in matrix to console
        readInMatrix(infile, MAT_ROW, MAT_COL, gameMatrix);

        //while there are words to read in the word bank, get a title, search for it, report, and repeat
        while (infile.peek() != EOF) {
            //make getline function to call each time a word is done and the next needs to be put into the vector
            getTitleIntoVector(infile, movieTitle, title);
            
            //DEBUGGING
            //cout << endl;
           // cout << endl << movieTitle.size() << endl;
           // cout << movieTitle[0];

            //collect the movies that were missing using the flag returned
            if (checkForFirstMatch(gameMatrix, movieTitle, lostMovies, title, MAT_ROW, MAT_COL, index, x, y) == false) {
                lostMovies.push_back(title);
            }  
        }

        //display the lost movies
        //cout << lostMovies.size();
       displayLostMovies(lostMovies);
    }
}

