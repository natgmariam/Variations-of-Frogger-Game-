/*
Description: a game using a frog(x) to leave a field based on user 
    selction of movment using random number generator to move within
    a loop. With winning and lossing conditions.  
Input: user is asked to input int for the seed to generat random numbers
    as well as to make selections to change the position of the frog
    moving within the filed till game over or condition won. As well as
    asked to play the game in silent mode, without the table.  
Output: A program that shows selection allowing for the change of 
    position for the frog, with a fence as well as a count down of 
    how many moves you have left before the game is over. Showing 
    an increamnting vaalue of where frog is at on the table. 
*/
#include <iostream> //library for c++ 
#include <cmath> //library for math 
#include <iomanip> //library for parametric manipulators 
#include <cstdlib> //library to use randoziation 
#include <string> //library to use strigns 
using namespace std; 
int main () { //main function for C++ code 

const short MAX_JUMPS = 10; //declaration of constants & short ints  
const short MAX_DIST = 5; 
const short WIDTH = 14; 
const short HEIGHT = 5;
short int jumps = 0; 
short int distance = 0; 
short int frog_x = 0; 
short int frog_y = 0; 
short int exit_col = WIDTH /2; 
char choice = ' '; 
string game_info; //declaration of strings 
int seed = 0; //initilaztion of random number generator
char silent = '\0'; 

//print out welcome statement 
cout << "GAME CONFIGURATION:" 
    << "\nenter seed value (0=time(NULL)): ";
    cin >> seed; //usser input for seed, for ramdomization 

if (seed == 0) { //if..else for randomization based on user input 
    srand (time(NULL)); 
    }
else 
    srand(seed); 

cout << "silent mode? (y/n): "; //prompt for user response to print without table 
cin >> silent; //user input 

bool displaychart = false;  //boolin statement to allow silent function  
if (silent == 'n' || silent == 'N'){ //to print the table 
    displaychart = true; 
}
else { 
    displaychart = false;  //to print without the table 
}
//randomizing x and y value for the x to print  
frog_x = rand() % WIDTH + 1; //randamization of frog in the table x-axis  
frog_y = rand() % HEIGHT +1; //randamization of frog on the y-axis 
jumps = 0;
//game info being printed 
string s1 = "################";
string s2 = "\nGAME INFO:";
string s3 = "\nfrog_x=";
string s4 = "\tfrog_y=";  
string s5 = "\njumps="; 
string s6 = "/";
string s7 = "";
 //while loop to get the game going till loss or win based on jump incremants 
    while (jumps < MAX_JUMPS){
        //using append to print out the game info using on cout statement
        
        game_info.append(s1);
        game_info.append(s2);
        game_info.append(s3); 
        game_info.append(to_string(frog_x)); 
        game_info.append(s4); 
        game_info.append(to_string(frog_y));
        game_info.append(s5); 
        game_info.append(to_string(jumps));
        game_info.append(s6);
        game_info.append(to_string(MAX_JUMPS));  
        game_info.append(s7); 
        //print out game info & everything in append 
        cout << game_info << endl;  //prints everying appended 
        game_info= "";
        //cout << endl; 
    //if statement for boolin condition, selecting what to print  
        if (displaychart == true){ 
        cout << endl; 
//for the upper fence of the first row 
        cout <<"|" << setfill('*') << setw(WIDTH + 1) << "|" << '\n'; 
        
//loop to print the inner grid within the WIDTH & HEIGHT const
        for (int j = 1; j <= HEIGHT; j++)
        {  // condition to print an X in the field based on rad-y & rand-x 
            if (frog_y == j) 
            {   //printing frog_x in the field 
                cout << "|" << setw(frog_x) << setfill('-') << right << 
                "X" << setw((WIDTH + 1)- frog_x) << setfill('-') << "|" << '\n';
            }
            else //field to ptint out when frog_x is not on the field 
                cout << "|" << setw(WIDTH + 1) << setfill('-') << "|" << '\n';
        } //printing out the last fence with the winning condition  
        cout << "|" << setw(exit_col) << setfill('*') << right << " " 
        << setw((WIDTH + 1)- exit_col) << setfill('*') << right << "|" << '\n';
      //printing menue to control frog movment within the filed 
        cout << endl; 
        cout << "MENU:" << '\n';
        cout << "w: UP" << '\n';
        cout << "a: LEFT" << '\n';
        cout << "s: DOWN" << '\n';
        cout << "d: RIGHT" << '\n';
        } //prompt user for modification of frog_x based on menu
        cout << "Enter selection: ";
        cin >> choice; 
        distance = rand() % MAX_DIST + 1; //changes for X based on selection 
        cout << "distance=" << distance << '\n'; //statment of distance 
        //cout << endl; 
        //changes to the frog postion to exit
        //jumps to change frogs position using frogx and y as refrence 
        switch (choice)  
        {
        case 'w': //to accept both upper & lower case char 
        case 'W': 
            cout << "jumping UP by " << distance << endl;
            frog_y -= distance;//modification of frog position using y
            //cout << endl; 
            break;  
        case 's':
        case 'S': 
            cout << "jumping DOWN by " << distance << endl;
            frog_y += distance; 
            //cout << endl;
            break;
        case 'd':
        case 'D':
            cout << "jumping RIGHT by " << distance << endl;
            frog_x += distance;//modification of frog position using x
            //cout << endl; 
            break;  
        case 'a':
        case 'A': 
            cout << "jumping LEFT by " << distance << endl; 
            frog_x -= distance;
          //  cout << endl; 
            break;
        default:
            cout << "invalid" << '\n'; //to account for user error 
            break;
        }   
        jumps++;//incremation of jumps, turn based 
        //checks to see if exited through opening 
        if (frog_y > HEIGHT && frog_x == exit_col)
        { //printing out the winning condition based on jumps 
            cout << "WIN in "<< jumps << " jumps" << '\n';
            return 0; 
        }
        //checks to see if frog is out of boundary 
        if(frog_y < 1 || frog_y > HEIGHT || frog_x < 1 || frog_x > WIDTH)
        { //informing lose of game due to being out of field 
            cout << "GAME OVER: out of field" << '\n';
            return 0; 
        }
        
        cout << endl; 
    }
    //statment to print no more jumps so exits game 
    cout << "GAME OVER: out of jumps" << '\n';
 
 
 return 0; 

}