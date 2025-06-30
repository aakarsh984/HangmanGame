// C++ program to implement the hangman game 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 
 //define maximum number of incorrect attempts 

#define MAX_ATTEMPTS 6 
//main class 
class HangmanGame { 
public: 
	// constructor 
	HangmanGame() 
	{ 
		srand(static_cast<unsigned int>(time(nullptr))); 
		secretWord = getRandomWord(); 
		currentWord = string(secretWord.length(),'-'); 
		attemptsLeft =MAX_ATTEMPTS; 
	} 

	// function to start the game. 
	void play() 
	{ 
        cout<<"\t======================================"<<endl;
        cout << "\t\tWelcome to Hangman Game!" << endl; 
        cout<<"\t======================================"<<endl<<endl;
        
        cout << "Rules of the game:-\n";
		cout << "You have " << attemptsLeft 
            << " attempts to guess the secret word."<< endl; 
       
        cout << "1. There were will be number of blanks"
                    " generated depending on the word.\n";
        cout << "2. Try to guess each letter of the word.\n";
        cout << "3. Each wrong guess displays the parts of the hangman.\n";
         cout << "4. When the hangman is fully drawn, YOU LOOSE!!.\n\n";
        cout << "\t\t Good Luck!!\n\n";
		// the main game loop which will go on till the 
		// attempts are left or the game is won. 
		while (attemptsLeft > 0) { 
			displayGameInfo(); 
			char guess; 
			cout << "Guess a letter: "; 
			cin >> guess; 
            cout<<"*********************************\n"<<endl;
			if (isalpha(guess)) { 
				guess = tolower(guess); 
				if (alreadyGuessed(guess)) { 
					cout << "You've already guessed that letter." << endl; 
				} 
				else { 
					bool correctGuess = updateCurrentWord(guess); 
					// if the guess is correct, we will 
					// update the word and check if the word 
					// is completely guessed or not 
					if (correctGuess) { 
						cout << "Good guess!" << endl; 
						// if the word is completely guessed. 
						if (currentWord == secretWord) { 
							displayGameInfo();
                            cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
							cout << "Congratulations!!!!!!!!!!! \n"
                                 <<"You guessed the word: "
								<< secretWord << endl; 
							cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                            break; 
						} 
					} 
					else { 
						cout << "Incorrect guess." << endl; 
						attemptsLeft--; 
						draw_hangman(attemptsLeft); 
					} 
				} 
			} 
			else { 
				cout << "Please enter a valid letter."<< endl; 
			} 
		} 

		if (attemptsLeft == 0) { 
			displayGameInfo(); 
            cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"NOOOOOOO!...you've been hanged.\n ";
            cout<<"!!!!!!!!GAME OVER!!!!!!!!!!!!\n ";
			cout<< "You've run out of attempts."
                << "The word was: "
                << secretWord << endl; 
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        } 
	} 

private: 
	string secretWord; 
	string currentWord; 
	int attemptsLeft; 
	vector<char> guessedLetters; 

	// select random word from the predefined word 
	string getRandomWord() 
	{ 
		vector<string> words 
            = { "friend","jecrc","course","data","student","today"}; 
		int index = rand() % words.size(); 
		return words[index]; 
	} 

	// checking if the word is already guessed 
	bool alreadyGuessed(char letter) 
	{ 
		return find(guessedLetters.begin(), guessedLetters.end(), letter) 
			!= guessedLetters.end(); 
	} 

	// updating the word after correct guess 
	bool updateCurrentWord(char letter) 
	{ 
		bool correctGuess = false; 
		for (size_t i = 0; i < secretWord.length(); i++) { 
			if (secretWord[i] == letter) { 
				currentWord[i] = letter; 
				correctGuess = true; 
			} 
		} 
		guessedLetters.push_back(letter); 
		return correctGuess; 
	} 

	// display information about game after a guess 
	void displayGameInfo() 
	{ 
        cout<<"\n*********************************"<<endl;
		cout << "Word: " << currentWord << endl; 
		cout << "Attempts left: " << attemptsLeft << endl; 
		cout << "Guessed letters: "; 
		for (char letter : guessedLetters) { 
			cout << letter << " "; 
		} 
		cout << endl;
        
	} 

	// function to progressively draw the hangman 
	void draw_hangman(int attemptsLeft) 
	{ 

		if (attemptsLeft == 5) { 
			cout << " _____" << endl; 
			cout << " |  |" << endl; 
			cout << " |  O" << endl;  
			cout << " |" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
		} 
		else if (attemptsLeft == 4) { 
			cout << " _____" << endl; 
			cout << " |  |" << endl; 
			cout << " |  O" << endl; 
			cout << " |  |" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
		} 
		else if (attemptsLeft == 3) { 
			cout << " _____" << endl; 
			cout << " |  |" << endl; 
			cout << " |  O" << endl; 
			cout << " | /|" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
		} 
		else if (attemptsLeft == 2) { 
			cout << " _____" << endl; 
			cout << " |  |" << endl; 
			cout << " |  O" << endl; 
			cout << " | /|\\" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
		} 
		else if (attemptsLeft == 1) { 
			cout << " _____" << endl; 
			cout << " |  |" << endl; 
			cout << " |  O" << endl; 
			cout << " | /|\\" << endl; 
			cout << " | /" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
		} 
		else if (attemptsLeft == 0) { 
			cout << " _____" << endl; 
			cout << " |  |" << endl; 
			cout << " |  O" << endl; 
			cout << " | /|\\" << endl; 
			cout << " | / \\" << endl; 
			cout << " |" << endl; 
			cout << " |" << endl; 
		} 
	} 
}; 


int main() 
{ 
 while (true){
	HangmanGame game; 
	game.play(); 
 };
	return 0; 
}
