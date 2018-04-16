#include <iostream>     // I/O 
#include <fstream>      // file I/O
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>       //string
#include <iomanip>      // format manipulation
#include <vector>		// vectors

#include "User.h"       // User class

using namespace std;

//Function declaration:
void StartScreen(string &name, bool &mainScreen); 
void MainScreen(string &sName, char &choice, bool & mainScreen, bool & startScreen);
void GuessNumber(bool &mainScreen, bool &startScreen);
void SpinWheel(bool &mainScreen, bool &startScreen);
void GameMenu (bool &mainScreen, bool &startScreen);
vector<string> GetOptions(string inString);

vector<USER> BuildUsers();
void PrintUsers(vector<USER> inVector);
void Wait(int in);
void SlowOut(string inStr, int inNum);
void SlowPeriod(int inNum, int inSpeed);
void PrintOptions(vector<string> inOptions);
void TicTac();

//GLOBAL FUNCTIONS: 

string sName;




//Main Program
int main() {
    vector<USER> Users = BuildUsers();   //returns vector of users
    PrintUsers(Users);
    
	char dummyChar = 0, cName = 0, choice = 0;//, &choiceP =  choice;
	bool startScreen = 1, mainScreen = 1, dummyBool = 0;
    int intChoice = 0; 
	sName = "dummy"; 
	
	while (startScreen) {
	    StartScreen(sName, mainScreen);             //gets name
	    
    cout << string(50, '\n');
    
        while (mainScreen) {           
	        MainScreen(sName, choice, mainScreen, startScreen);              // gets choice AND operates choice
	        cout << string(50, '\n');
	    }
	} 

	return 0;
}

//StarScreen - essentially just gets the user name:
void StartScreen(string &sName, bool &mainScreen) {
    char nameIn = 0;
    bool gettingName = 1; 
    vector<string> optionsVS = GetOptions("optionsVS");// = {"(G) for Gia", "(A) for Ari", "(B) for Bella"};    //name options

    mainScreen = 1;         //sets main screen back on in case name is changed

    cout << string(50, '\n');
    
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    cout << "\n          <<<<< START SCREEN >>>>> \n" ;
    cout << "\n\nHELLO! Please tell me who is playing today. \n\n";

    while (gettingName){
        PrintOptions(optionsVS);
	    //cin.clear(); cin.ignore(10000,'\n');   
	    cin >> nameIn; 	
	    cout << string(50, '\n');
    	nameIn = toupper(nameIn); 
    	switch (nameIn) {   case 'G':   sName = "Gia Bobia!";   gettingName = 0; break;
    	                    case 'A':   sName = "Ari Bari!";    gettingName = 0; break;
    	                    case 'B':   sName = "Bella Bear!";  gettingName = 0; break;
    	                    default: cout << endl << "Entry did not work, try again."; gettingName = 1 ;
    	}
    	
    }
    cout << "Hello, " << sName << "!" << endl;
}

void MainScreen(string &sName, char &choice, bool & mainScreen, bool & startScreen) {
    bool exit = 0, gettingChoice = 1;
    int intChoice = 0, numOptions = 5;
  	string dummyString = "0";
  	//vector<string> optionsVM;// = {"(S) Spin the Prize Wheel,", "(G) Guess the Number to Win,", "(P) Play a Game,", "(C) Change user, or", "(E) Exit"};

  	// FUTURE READ IN FILE
  	vector<string> optionsVM = GetOptions("optionsVM");      // builds vector from txt
  	
  	

    cout << string(30, '\n');
    cout << "\n          <<<<< MAIN SCREEN >>>>> \n" ;
    
    while (gettingChoice) {
    	gettingChoice = 0;      // turns off, set back if entry does not work
    	cout << "\nWelcome, " << sName << "!!\n\n" ;
    	PrintOptions(optionsVM);
    	//PrintOptions(optionStr, numOptions);
        cin >> choice;
        choice = toupper(choice);
        switch (choice) {
            case 'S': SpinWheel(mainScreen, startScreen); break;              //Spin the wheel for a prize
    	    case 'P': GameMenu(mainScreen, startScreen); break;//out << " Game still under construction" << endl; break;
            case 'G': GuessNumber(mainScreen, startScreen); break;
            case 'E': cout << "\n\nGoodBye, " << sName << endl; mainScreen = 0; startScreen =0;break;
            case 'C': cout << "\n\nOK, Lets change the user . . . " << endl << endl; mainScreen = 0;break;
            default: cout << "\n\n Entry did not work, try again: \n" << endl; gettingChoice = 1;break;
        }
    }
}

void GuessNumber (bool &mainScreen, bool &startScreen) {
    string dummyStr = "Checking to see if you guessed the correct number";
    bool gettingGuess = 1, guessing = 1;
    int highVal = 10;       //high val is number of potential 
    int x = 0, intChoice =0; 
    char cChoice;
    
    cout << string(50, '\n');
    int numOptions = 2;
    vector<string> optionsVYN = GetOptions("optionsVYN");// = {"(Y) Yes, or", "(N) No."};
    
    while (guessing) {
        srand(clock()); 
        x = rand()%highVal+1;
        
        cout << "\n          <<<<< GUESSING THE NUMBER >>>>> \n\n\n" ;
        
        while (gettingGuess) {
            cout << "OK " << sName << ", enter a number between 1 and " << highVal << ": "; 
	        cin.clear(); cin.ignore(10000,'\n');
	        cin >> intChoice; 
	        cout << endl;
	        if (intChoice <1 || intChoice > highVal) {
	            cout << "\nInvalid number.  Enter another number: "; 
	            cin.clear(); cin.ignore(10000,'\n');
	            cin>> intChoice; }
	        else {gettingGuess = 0;}        // get out if good choice;
        }
        
        SlowOut( dummyStr, 1 );     srand(clock());     SlowPeriod(rand()%5+4,7);
        dummyStr = "The random number is: ";
        cout << string(2,'\n');
        SlowOut (dummyStr, 2);      srand(clock());     SlowPeriod(rand()%5+4, 7);
        Wait (5);
        cout << "\n\n\t\t < < <   " << x << "   > > > "  << endl;
        
        Wait(15);
        if (intChoice == x) {cout << "\n\n**************\n\nLucky You!!! \t You guessed the correct number!" ;
                cout << "\n\n Now you get a prize from the wheel!" << endl;
                SpinWheel(mainScreen, startScreen);}
        else {cout << "\n\nSorry, but " << intChoice << " does not match " << x <<".\n" << endl;}
        
        cout << "*****Want to play again?\n\n";
        PrintOptions(optionsVYN);
        
        cin.clear(); cin.ignore(10000,'\n');
        cin >> cChoice; 
        cChoice = toupper(cChoice);
        switch (cChoice){
            case 'Y': guessing = 1; gettingGuess = 1; cout << "\nOK, lets guess again!"; Wait(20); break;
            case 'N': guessing = 0; cout << "\nOK, come back again " << sName << "!" << endl; Wait (20); break;
            default: cout << "***Invalid Entry: Try Again."  << endl; gettingGuess = 1; break;
        }
    }
}

void SpinWheel(bool &mainScreen, bool &startScreen) {
    int x = 0;
    char choice;
    bool spinningWheel = 1, gettingChoice = 1; 
    string dummyStr = "The wheel is spinning"; 
    int numPrizes = 7, numOptions = 3;
    vector<string> optionsVS = GetOptions("optionsVS");
    // {"(S) Spin the wheel again,", "(M) Go to Main Menu, or", "(C) Change user"};
        
    vector<string> prize = {
        "One Piece of Candy!", "Two Gold Stars!", "Five Pennies!",
        "Big hug and kiss!", "One Quarter!", "A Glass of Chocolate Milk!",
        "One Sucker!","One Nom Nom Toy!"};
    
    while (spinningWheel) {
        spinningWheel = 0;  //turn off - turned back on if choose spin again
        srand(clock());         x = rand() % numPrizes;
        
        cout << string(50, '\n') << "\t\t\t<<<<< SPINNING THE WHEEL >>>>> \n\n\n" ;
        SlowOut(dummyStr, 1);        SlowPeriod(5,7);               //wheel is spinning
       
        cout << string(3,'\n');      //clear view
        
        dummyStr = "Congratulations!!!!"; SlowOut(dummyStr,1);
        dummyStr = " You won ";     SlowOut(dummyStr, 6);
        dummyStr = " < < <   " +  prize[x]+  "   > > > ";     
        SlowOut(dummyStr,3);
        Wait (10);
          
        for (int n = 0; n < 3; n++) {
            cout << string(30,'\n');      
            
            cout << "\n\nCongratulations!!!!!!! You won:  "; // should flash prize
            
            Wait (10);
            cout << "---";
            SlowOut(dummyStr,1);
            Wait(10);
            
        }
        Wait(40);  cout << string(2, '\n');
        
        cout << "*****Want to play Again? \n\n";
        
        
        while (gettingChoice) {
            PrintOptions(optionsVS);
            cin >> choice; choice = toupper(choice);
            switch(choice) {
                case 'S': spinningWheel = 1; gettingChoice = 0; break;
                case 'M': mainScreen = 1; gettingChoice = 0; break;
                case 'C': mainScreen = 0; gettingChoice = 0; break;          // should go back to start screen
                case 'E': startScreen = 0; mainScreen = 1; gettingChoice = 0; 
                default : cout << "\n\nInvalid Entry.  Please try again.\n\n" << endl;
            }
        }
    }
	
}

void GameMenu (bool &mainScreen, bool &startScreen){
    char optionIn = 0;
    int numOptions = 5;
    vector<string> optionsVM = {"(S) Snakes,", "(T) tic-tac-toe,", "(M) Go to Main Menu,", "(C) Change User, or", "(E) Exit Program."};
    bool choosingGame = 1; 
    
    while (choosingGame) {
        cout << string(30, '\n') << "\t\t\t<<<<< GAME MENU >>>>> \n\n\n" ;
        PrintOptions(optionsVM);
        cin >> optionIn ;
        optionIn = toupper(optionIn);
        switch (optionIn) {
            case 'S':   cout << "Snake Game not ready" << endl; break; //SnakeGame(); break;
            case 'T':   TicTac(); break;
            case 'M':   choosingGame = 0; break;
            case 'C':   choosingGame = 0; mainScreen = 0; break;
            case 'E':   choosingGame = 0; mainScreen = 0; startScreen = 0; break;
            default :   cout << "\n\nInvalid Entry. \t"; break;
        }
    }
}


//**********************************BUILD USERS FROM Users.txt

vector<USER> BuildUsers () {
    ifstream inFile ("Users.txt");
    int dummyInt, numUsers;
    string dummyString;
    
    while (dummyString != "(**)") {inFile >> dummyString;}
    getline(inFile,dummyString);  //goes to next getline
    inFile >>  numUsers;
    
    vector<USER> build(numUsers);
    
    for (int i = 0; i < numUsers; i++) {
        getline(inFile,dummyString);
        getline(inFile,dummyString);
        getline(inFile,dummyString);
        getline(inFile,dummyString);     
        build[i].setName(dummyString);   //sets name
        getline(inFile,dummyString);
        build[i].setNickName(dummyString); //sets nick name
        inFile >> dummyInt;                 // Age
        build[i].setAge(dummyInt);
        inFile >> dummyInt;                 // birth day
        build[i].setBDay(dummyInt);
        inFile >>dummyInt;                  // birth month
        build[i].setBMonth(dummyInt);
        
    }
    
    return build;
}

//************************************PRINT OUT Users

void PrintUsers(vector<USER> inVector) {
    
    
    ofstream outFile ("temp.txt");
    outFile << "// User information\n\n/*Name\nNickName\nAge\nbirthday\nbirthmonth\n\n";
    outFile << "*/\n\nNumber of users:\n(**)" << endl;
    outFile << inVector.size() << endl;
    for (int i = 0; i < inVector.size(); i++) {
        outFile << "\n[]\n";
        outFile << inVector[i].getName() << endl;
        
        outFile << "\n[]\n";
        outFile << inVector[i].getNickName() << endl;

        outFile << "\n[]\n";
        outFile << inVector[i].getAge() << endl;
        
        outFile << "\n[]\n";
        outFile << inVector[i].getBDay() << endl;
        
        outFile << "\n[]\n";
        outFile << inVector[i].getBMonth() << endl;
    }
}


//***********************************GET OPTIONS for menu screens

vector<string> GetOptions(string inString) {
    string findString = inString; 
    string dummyString;
    int numOptions = 0 ; 
    ifstream inFile("elements.txt");
    inFile >> dummyString;
    
    while (dummyString != findString)  {inFile >> dummyString;}
    cout << "FOUND MATCH" << endl;
    getline(inFile,dummyString);  // reads to end of sentence
    inFile >> numOptions;                       //gets number of optionsVM
    
    vector<string> optionsVector(numOptions);       //initialize vector
    getline(inFile, dummyString);    // reads to end of sentence
    
    for (int i = 0; i < numOptions; i++) {
        getline(inFile, optionsVector[i]);
        inFile.clear();
      }
    
    inFile.close();
    return optionsVector;
}
    
    
    

void Wait(int in){
    clock_t t = clock();
    while (clock()-t < in* 30000) {};    // should space about 2 second
    cout.flush();
}

/*SlowOut takes in a string and puts it into the stream slowly depending on input. 
*/
void SlowOut(string inStr, int inNum) {
    for (int m = 0; m < inStr.length(); m++) {cout << inStr[m]; Wait(inNum); }
}

void SlowPeriod(int inNum, int inSpeed) {
    for (int m = 0; m <= inNum ; m++) { cout << " .";  Wait (inSpeed);}
}

void PrintOptions(vector<string> inOptions){
    cout << "Enter:\t";
    for (int i = 0; i < inOptions.size(); i++) { cout << "\n\t\t" << inOptions[i];}
    cout << endl;
}
  
void TicTac() {
}



/*****************************************************
class USER () {
    int starCount = 0, 
    string nickName;
    
};

}
/*



random(int);
char tic[3][3];               //global matrix declerations
int d,e,f,a,t,i,j,x,y;        //global variables declerations
void display();               //displays the matrix
void user();                  //function for user's move
void newdisp();               //function for display of matrix after every move
void pc();                    //function for pc's move
int check();                  //function for finding out the winner
int horcheck();               //function for horizontal line check
int vercheck();               //function for vertical line check
int diagcheck();              //function for diagonal line check
main()                        //main function
{
    clrscr();                     //clears the previous output screen
    randomize();                  //initialize random function calling
    int d=random(2);              //random function call
    for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    	tic[i][j]=' ';        //assigning space ' ' to all elements of matrix
    display();                    //display function call
    d==0?user():pc();             //random starting of the game depending on d
    getch();                      //provides output by getting input without returning to program
    return 0;                     //return int to main function
}

void display() {               //display function definition
    for(t=0;t<3;t++) {
    	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;  //figure formation
	    if(t!=2)
	    cout<<"		--|---|--"<<endl;
	}
}

void user() {                 //user function definition
    cout<<"ENTER THE CO-ORDINATES WHERE YOU WANT TO PUT 'X' i.e 0,1,2 "; 
    cin>>x>>y;
    if((x<0)||(x>2)&&(y<0)||(y>2)) {  //check for valid co-ordinates
	    cout<<"ENTER THE CORRECT CO-ORDINATES";
	    user();    //user function call
    }
    
}
else
	{
	if(tic[x][y]==' ')    //check for vacant space at entered co-ordinates
		{
		tic[x][y]='X';  //assigning user 'X' to the co-ordinates
		newdisp();    //newdisp function call
		}
	else
		{
		cout<<"		

THIS POSITION IS ALREADY FILLED. CHOOSE SOME OTHER CO-ORDINATES";
		user();       //user function call
		}
	}
d=check();            //check function call
if(d==0)
pc();                 //pc function call
else
	{
	cout<<"		

YOU ARE THE WINNER";
	getche();     //requires enter to return to program. prevents return without display
	exit(1);      //program termination
	}
}
void newdisp()        //newdisp function definition
{
for(t=0;t<3;t++)
	{
	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;   
	                                //displays new tictactoe after user or pc turn
	if(t!=2)
	cout<<"		--|---|--"<<endl;
	}
}
void pc()          //pc function call
{
int f,z;
randomize();       //initialize random function calling
cout<<"		

THIS IS THE COMPUTER'S MOVE 

";
for(i=0;i<=20;i++)
	{
	f=random(3);
	z=random(3);
	if(tic[f][z]==' ')      //check for vacant space at entered co-ordinates
		{
		tic[f][z]='O';  //assigning pc 'O' to the co-ordinates
		goto x;         //exiting for loop to display new tictactoe
		}
	else
	continue;               //
	}
x:newdisp();                    //newdisp function call
d=check();                      //check function call
if(d==0)
user();                         //user function call
else
	{
	cout<<"		

I'M THE WINNER";
	getche();           //requires enter to return to program. prevents
return without display
	exit(1);            //program termination
	}
}
check()                     //check function definition
{
horcheck();                 //horcheck function call
vercheck();                 //vercheck function call
diagcheck();                //diagcheck function call
return (d||e||f);
}
horcheck()                  //horcheck function definition
{
if(((tic[0][0]==tic[0][1])&&(tic[0][1]==tic[0][2])&&(tic[0][1]!='
'))||((tic[1][0]==tic[1][1])&&(tic[1][1]==tic[1][2])&&(tic[1][1]!='
'))||((tic[2][0]==tic[2][1])&&(tic[2][1]==tic[2][2])&&(tic[2][2]!=' 
')))
d=1;                        //checks each element of a horizontal line to be same else                        
                            //returns 1 if all 3 elements of any horizontal line are same
d=0;                        //else returns 0
return d;
}
vercheck()                  //vercheck function definition
{
if(((tic[0][0]==tic[1][0])&&(tic[1][0]==tic[2][0])&&(tic[0][0]!='
'))||((tic[0][1]==tic[1][1])&&(tic[1][1]==tic[2][1])&&(tic[0][1]!='
'))||((tic[0][2]==tic[1][2])&&(tic[1][2]==tic[2][2])&&(tic[0][2]!=' 
')))
e=1;                        //checks each element of a vertical line to be same
else                        //returns 1 if all 3 elements of any vertical line are same
e=0;                        //else returns 0
return e;
}
diagcheck()                 //diagcheck function definition
{
if(((tic[0][0]==tic[1][1])&&(tic[1][1]==tic[2][2])&&(tic[0][0]!='
'))||((tic[0][2]==tic[1][1])&&(tic[1][1]==tic[2][0])&&(tic[1][1]!=' 
')))
f=1;                        //checks each element of a diagonal line to  be same else
                            //returns 1 if all 3 elements of any diagonal line are same
f=0;                        //else returns 0
return f;
}


        
*/


