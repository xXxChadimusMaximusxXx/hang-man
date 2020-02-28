#include <iostream>
#include <cstdlib>;
#include <conio.h>

using namespace std;


bool gameOver;
bool victory;

const int width = 40;
const int height = 15;

const char lobster[] = {'l','o','b','s','t','e','r'};               //just a word
bool lobsterCheck[sizeof(lobster)];
const char ambulance[] = { 'a','m','b','u','l','a','n','c','e'};    //just a word
bool ambulanceCheck[sizeof(ambulance)];
const char furnitare[] = {'f','u','r','n','i','t','a','r','e'};     //just a word
bool furnitareCheck[sizeof(furnitare)];

int word; //chooses the word to be used
int mistakes; //keeps track of the total of mistakes
int arrayLength;//holds the length of the current word

void startUp() {
	//imagine a constructor here
	gameOver = false;
	victory = false;
	word = (rand() % 3) + 1;
	mistakes = 5;
	
	switch (word) {
	case 1: arrayLength = sizeof(lobster);
		break;
	case 2: arrayLength = sizeof(ambulance);
		break;
	case 3: arrayLength = sizeof(furnitare);
		break;
	}
}

void draw() {
	//clearing the terminal
	system("cls");

	//printing the top area
	for (int i = 0; i < width; i++) {
		cout << '-';
	}

	cout << endl;
	//print is for checking if a ' ' (space) is required
	bool print;
	
	int spaces = arrayLength / 2; //the amount of spaces for a word (used for '-')
	int sum = 0;                  //the sum of all characters (used for '-')

	int spaces2 = arrayLength / 2; //the amount of spaces for a word (used for characters)
	int sum2 = 0;                  //the sum of all characters (used for characters)

	for (int i = 0; i < height; i++) {
		
		for (int j = 0; j < width; j++) {
			//printing the walls
			if (j == 0 || j == width - 1) cout << '|';
			else {
			      print = false;
				
				//prints the number of characters and the characters
				for (int k = 0; k < arrayLength; k++) {
					
					//characters
					switch (word) {
					case 1: if ((i == 8 && j == (width / 2) - spaces2) && (sum2 < arrayLength) && (lobsterCheck[k] == true)) {
						cout << lobster[0];
						spaces2--;
						sum2++;
						print = true;
					}
						break;
					case 2: if ((i == 8 && j == (width / 2) - spaces2) && (sum2 < arrayLength) && (ambulanceCheck[k] == true)) {
						cout << ambulance[0];
						spaces2--;
						sum2++;
						print = true;
					}
						  break;
					case 3: if ((i == 8 && j == (width / 2) - spaces2) && (sum2 < arrayLength) && (furnitareCheck[k] == true)) {
						cout << furnitare[0];
						spaces2--;
						sum2++;
						print = true;
					}
						  break;
					}
					
					// '-'
					if ((i == 9 && j == (width / 2) - spaces) && sum<arrayLength) {
						cout << '-';
						spaces--;
						sum++;
						print = true;
					}
				}
				
				

				if (mistakes > 0) {
					//printing the hanged man
					for (int mistakesCopy = 1; mistakesCopy <= mistakes; mistakesCopy++) {

						print = false;

						switch (mistakesCopy) {

						case 1: if ((i == 6 && j == (width / 2) - 3)|| (i == 6 && j == (width / 2) - 2) || (i == 6 && j == (width / 2) - 1)) {
							cout << '-';
							print = true;
							
						}
							  if ((i == 7 && j == (width / 2) - 3) || (i == 7 && j == (width / 2) )) {
								  cout << '|';
								  print = true;
								  
							  }
							break;

						case 2:
							if ((i == 0 && j == (width / 2) - 1) || (i == 1 && j == (width / 2) - 1)) {
								cout << '|';
								print = true;
								
							}
							break;

						case 3:
							if (i == 2 && j == (width / 2) - 1) {
								cout << 'O';
								print = true;
								
							}
							break;

						case 4: 
							if (i == 3 && j == (width / 2) - 2) {
								cout << '|';
								print = true;
								
							}
							break;

						case 5: if (i == 3 && j == (width / 2) - 3) {
							cout << "/";
							print = true;
							
						}
							if(i == 3 && j == (width / 2) - 1) {
								cout << '\\';
								print = true;
								
						}
							break;

						case 6:if (i == 4 && j == (width / 2) - 2) {
							cout << "/";
							print = true;
							
						}
							  if (i == 4 && j == (width / 2) ) {
								  cout << '\\';
								  print = true;
								  
							  }
							break;

						}
						
					}
					if(!print)cout << ' ';
					print = false;
				}else if(!print)cout << ' ';
				
				
			}
		}
		cout << endl;
	}

	

	//printing the bottom area
	for (int i = 0; i < width; i++) {
		cout << '-';
	}
}

void input() {
	//ckecking for user input
	if (_kbhit) {

		//if '0' is pressed the game ends
		if (_getch() == '0') gameOver = true;

		switch (word) {
		case 1: for (int i = 0; i < arrayLength; i++) {
			if (_getch() == lobster[i]) {
				lobsterCheck[i] = true;
			}
			else mistakes++;
		}
			break;
		case 2:for (int i = 0; i < arrayLength; i++) {
			if (_getch() == ambulance[i]) {
				ambulanceCheck[i] = true;
			}
			else mistakes++;
		}
			break;
		case 3: for (int i = 0; i < arrayLength; i++) {
			if (_getch() == furnitare[i]) {
				furnitareCheck[i] = true;
			}
			else mistakes++;
		}
			break;
	}
	}
}
	

void logic() {

	bool whole = false;

	

	switch (word) {
	case 1: for (int i = 0; i < arrayLength; i++) {
		if (lobsterCheck[i == true]) {
			whole = true;
		}
		else {
			whole = false;
			break;
		}
	}
		  break;
	case 2:for (int i = 0; i < arrayLength; i++) {
		if (ambulanceCheck[i == true]) {
			whole = true;
		}
		else {
			whole = false;
			break;
		}
	}
		  break;
	case 3: for (int i = 0; i < arrayLength; i++) {
		if (furnitareCheck[i == true]) {
			whole = true;
		}
		else {
			whole = false;
			break;
		}
	}
		  break;
	}

	if (whole) {
		gameOver = true;
		victory = true;
	}

	if (mistakes >= 6) {
		gameOver = true;
		victory = false;
	}
}

int main() {
	
	startUp();
	//running a loop so the game can be updated constantly
	while (! gameOver) {
		draw();
		input();
		logic();
	}

	cout << endl;

	if (victory) {
		cout << "Congratulations!!!" << endl;
	}
	else {
		cout << "Bummer! You will get them next time!" << endl;
	}
	
}