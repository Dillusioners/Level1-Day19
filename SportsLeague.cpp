// for input and output
# include <iostream>
// for std::numeric_limits::max
# include <limits>
// for string class and functions
# include <string>
// for dynamic arrays
# include <vector>
/*
	Author: LeeTuah
	Program: 
	Date: 00/00/23
	For SuperB League event
*/

// initializing the fixCin() function to be used in the classes
void fixCin();

class Game{
	private:
		// schedule -> stores the timing of the game
		std::string schedule, pass;
		// score -> stores the scores for both the parties
		std::pair<int, int> score;
		
	public:
		// Empty constructor for Game class
		Game(){}
		// Constructor for the Game class
		// sch -> the schedule of the game
		// s1 -> score of team 1
		// s2 -> score of team 2
		// p -> password for the game
		Game(std::string sch, std::string p);
		
		// returns the schedule of the game
		std::string getSchedule();
		// returns the scores of the game
		std::pair<int, int> getScore();
		// returns the password of the game
		std::string getPass();
		
		// setting the schedule of the game
		// s -> new schedule
		Game setSchedule(std::string s);
		// setting the scores for the game
		// s1 -> score for the first team
		// s2 -> score for the second team
		Game setScore(int s1, int s2);
		// setting the password for the game
		// p -> new password
		Game setPass(std::string p);
		// copying all data from other game to this game
		// game -> the game which is copied in
		Game operator=(Game game);
};

// The following are the declaration of the Game class functions

Game::Game(std::string sch, std::string p){
	// setting all the values
	schedule = sch;
	score.first = 0;
	score.second = 0;
	pass = p;
}

std::string Game::getSchedule(){
	return schedule;	
}

std::pair<int, int> Game::getScore(){
	return score;
}

std::string Game::getPass(){
	return pass;	
}

Game Game::setSchedule(std::string s){
	schedule = s;
	return *this;	
}

Game Game::setScore(int s1, int s2){
	score.first = s1;
	score.second = s2;
	return *this;	
}

Game Game::setPass(std::string p){
	pass = p;
	return *this;
}

Game Game::operator=(Game game){
	schedule = game.getSchedule();
	score = game.getScore();
	pass = game.getPass();
	return *this;	
}

// Game class functions end here

class SportsLeague{
	private:
		// stores all the games
		std::vector<Game> games;
		
	public:
		// shows the admin panel
		void viewPanel();
		// prints all of the games in the list
		void viewAllGames();
		// create a new game
		void createGame();
		// edit a game
		void editGame();
		// show game details
		void gameDetails();
};

// The following are SportsLeague class functions

void SportsLeague::viewPanel(){
	bool running = true;
	int choice;
	
	// running the program
	while(running){
		std::cout << "\n\nAdmin Panel for the Sports Event:\n";
		std::cout << "Choose any one of the following options:\n";
		std::cout << "1. View All Games\n";
		std::cout << "2. Create a Game\n";
		std::cout << "3. Edit Game Details\n";
		std::cout << "4. View Standings for a Game\n";
		std::cout << "5. Exit\n";
		std::cout << ">> ";
		std::cin >> choice;
		fixCin();
		
		// running a switch-case on choice
		switch(choice){
			// exit
			case 6: {
				std::cout << "Closing Admin panel.\n";
				running = false;	
			}
			
			// view all games
			case 1: {
				viewAllGames();
				break;	
			}
			
			// create a game
			case 2: {
				createGame();
				break;	
			}
			
			// edit a game
			case 3: {
				editGame();
				break;	
			}
			
			// view standings of a game
			case 4: {
				gameDetails();
				break;	
			}
			
			// invalid choice
			default: {
				std::cout << "Invalid choice provided.\n";
			}
		}
	}
}

void SportsLeague::viewAllGames(){
	// prints all of the games
	std::cout << "Here are the following leagues: \n";
	int index = 1;
	for(auto i = games.begin(); i != games.end(); index++, i++){
		std::cout << index << ". " << i->getSchedule() << '\n';
	}
}

void SportsLeague::createGame(){
	std::string s, p;
	int s1, s2;
	
	// asks user input
	std::cout << "Enter your schedule(in DD/MM/YY): ";
	std::cin >> s;
	if(s.size() != 8){
		std::cout << "Invalid Schedule format.";
		return;	
	}
	std::cout << "Enter Game password: ";
	std::cin >> p;
	std::cout << "Enter score for first party: ";
	std::cin >> s1;
	fixCin();
	std::cout << "Enter score for second party: ";
	std::cin >> s2;
	fixCin();
	
	// creates a new game
	Game g(s, p);
	g.setScore(s1, s2);
	games.push_back(g);
}

void SportsLeague::editGame(){
	std::string p;
	int s1, s2;
	
	// asks for password
	std::cout << "Enter the password for the game: ";
	std::cin >> p;
	
	// looping through the games
	for(int i = 0; i < (int)games.size(); i++){
		// if password matches with game pass
		if(p == games[i].getPass()){
			std::cout << "Enter score for first team: ";
			std::cin >> s1;
			std::cout << "Enter score for second team: ";
			std::cin >> s2;
			
			games[i].setScore(s1, s2);
			return;
		}	
	}
	
	std::cout << "Game not found!\n";
}

void SportsLeague::gameDetails(){
	std::string p;
	
	// asking for password
	std::cout << "Enter the password for the game: ";
	std::cin >> p;
	
	// looping through games
	for(int i = 0; i < (int)games.size(); i++){
		// checking if password matches, then printing all the details
		if(p == games[i].getPass()){
			std::pair<int, int> score = games[i].getScore();
			std::cout << "\nGame Schedule: " << games[i].getSchedule();
			std::cout << "\nScore for first party: " << score.first;
			std::cout << "\nScore for second party: " << score.second;
			return;
		}	
	}
	
	std::cout << "Game not found!\n";
}

// SportsLeague class functions end here

// fixes std::cin if bad input is provided
void fixCin(){
	if(std::cin.fail()){
		// clearing std::cin from bad to good
		std::cin.clear();
		// removing all of the bad input from std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}	
}

// execution starts from here
// int argc -> total argument count from run
// char** argv -> all the provided arguments in a string array
int main(int argc, char** argv){
	// creating sports league and calling it
	SportsLeague s;
	s.viewPanel();
	return 0;
}
