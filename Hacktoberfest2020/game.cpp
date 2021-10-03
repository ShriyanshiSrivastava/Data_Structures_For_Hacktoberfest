#include "game.h"
using namespace std;

Game::Game()
{
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat Kohli";
	players[1] = "Rohit Sharma";
	players[2] = "Shikhar Dhawan";
	players[3] = "Rishabh Pant";
	players[4] = "Dinesh Karthik";
	players[5] = "KL Rahul";
	players[6] = "Ravindra Jadeja";
	players[7] = "Hardik Pandya";
	players[8] = "jasprit Bumrah";
	players[9] = "Bhuvneshwar Kumar";
	players[10] = "Ishant Sharma";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}

void Game::Welcome()
{
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"|                            MINI CRICKET                                 |"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"||                         .....WELCOME.....                             ||"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"                  ::::::::::INSTRUCTIONS::::::::::                         "<<endl<<endl;
	cout<<"       1) There will be two teams, Team-A and Team-B                       "<<endl;
	cout<<"       2) Each team will play for one over only.                           "<<endl;
	cout<<"       3) You are allowed to select 4 players from the pool                "<<endl;
	cout<<"       4) Each player can be selected only once                            "<<endl;
	cout<<"       5) This game is entirely based on luck                              "<<endl;
	cout<<"       6) Hope you will enjoy it...GOOD LUCK!!!                            "<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
}

void Game::showAllPlayers()
{
	cout << "\nPress Enter to Continue";
	cin.ignore();
	cout<<"\n....................................................."<<endl;
	cout<<"|                Pool of Players                    |"<<endl;
	cout<<"....................................................."<<endl;
	cout<<"                 [0] Virat Kohli                          "<<endl;
	cout<<"                 [1] Rohit Sharma                          "<<endl;
	cout<<"                 [2] Shikhar Dhawan                          "<<endl;
	cout<<"                 [3] Rishabh Pant                          "<<endl;
	cout<<"                 [4] Dinesh Kartik                           "<<endl;
	cout<<"                 [5] KL Rahul                          "<<endl;
	cout<<"                 [6] Ravindra Jadeja                         "<<endl;
	cout<<"                 [7] Hardik Pandya                         "<<endl;
	cout<<"                 [8] Jasprit Bumrah                          "<<endl;
	cout<<"                 [9] Bhuvneshwar Kumar                           "<<endl;
	cout<<"                 [10] Ishant Sharma                         "<<endl;
	cout<<"....................................................."<<endl;

}

int Game::takeIntegerInput()
{
	int n;

	while (!(cin >> n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Please try again with valid input: ";
	}

	return n;
}

void Game::selectPlayers() {

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|========== Create Team-A and Team-B ==========|" << endl;
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < playersPerTeam; i++) {

		// Add player to team A
		teamASelection:
			cout << endl << "Select player " << i + 1 << " of Team A - ";
			int playerIndexTeamA = takeIntegerInput();

			if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
				cout << endl << "Please select from the given players" << endl;
				goto teamASelection;
			} else if(!validate(playerIndexTeamA))
			{
				cout<<"Player has already been selected. Choose different player..";
				goto teamASelection;
			}else {
				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
			}

		// Add player to team B
		teamBSelection:
			cout << endl << "Select player " << i + 1 << " of Team B - ";
			int playerIndexTeamB = takeIntegerInput();

			if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
				cout << endl << "Please select from the given players" << endl;
				goto teamBSelection;
			} else if(!validate(playerIndexTeamB))
			{
				cout<<"Player has already been selected. Choose different player..";
				goto teamBSelection;
			}else {
				Player teamBPlayer;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}
	}
}

bool Game::validate(int index)
{
	int n;
	vector <Player> players;
	players=teamA.players;
	n=players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id == index)
			return false;
	}
	return true;

}

void Game::printTeams()
{
    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl << endl;
    cout << "------------------------------------\t\t-----------------------------------" << endl;
    cout << "|============  Team-A  ============|\t\t|============  Team-B  ============|" << endl;
    cout << "------------------------------------\t\t------------------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t  "
        		"|"
        	<< "\t\t"
			<< "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t    |" << endl;
    }
    cout << "------------------------------------\t\t------------------------------------" << endl << endl;
}

void Game::toss() {

	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "|========== Let's Toss  ==========|" << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "Tossing the coin..." << endl << endl;

	srand(time(NULL));
	int randomValue = rand() % 2;	// 0 or 1

    switch (randomValue) {
		case 0:
			cout << "Team-A won the toss" << endl << endl;
			tossChoice(teamA);
			break;
		case 1:
			cout << "Team-B won the toss" << endl << endl;
			tossChoice(teamB);
			break;
    }
}

void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}

void Game::startFirstInnings() {

	cout << "\t\t ||| FIRST INNINGS STARTS ||| " << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game::initializePlayers() {

	// Choose batsman and bowler: Initialize *batsman and *bowler
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		getchar();
		cout << "Bowling..." << endl;

		bat();

	    if (!validateInningsScore()) {
	    	break;
	    }
	}
}

void Game::bat() {

	srand ( time(NULL) );
	int runsScored = rand() % 6;

	// Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();
    } else { 	// else runScored = 0 and the batsman is ‘OUT’
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
    	bowler->wicketsTaken = bowler->wicketsTaken + 1;

    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->wicketsLost;
    	batsman = &battingTeam->players[nextPlayerIndex];
    }
}

bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else { // Else 2nd innings
    	if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {	//Case1: If batting team score > bowling team score
    	        	cout << battingTeam->name << " WON THE MATCH" << endl << endl;
    	        	return false;
    	        	//Case2: Batting team is all OUT OR Bowling team is done bowling
    	        } else if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
    	            if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {
    	            	cout << bowlingTeam->name << " WON THE MATCH" << endl << endl;
    	            } else {
    	            	cout << "MATCH DRAW" << endl << endl;
    	            }
    	            return false;
    	        }
    	

    }

	return true;
}

void Game::showGameScorecard() {

    cout << "-------------------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
      << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------------------" << endl << endl;
}

void Game::startSecondInnings()
{
	cout << "\t\t ||| SECOND INNINGS STARTS ||| " << endl << endl;
	
	isFirstInnings = false;
	
	Team temp = *battingTeam;								//Swapping pointers
	*battingTeam = *bowlingTeam;
	*bowlingTeam = temp;
	
	initializePlayers();
	playInnings();
	
}

void Game::summary()
{
	
	cout<<"\t\t  ||| MATCH ENDS ||| "<<endl<<endl;
	
    cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

    cout << "=================================================" << endl;
    cout << "| PLAYER \t     BATTING \t   BOWLING    |" << endl;

    for (int j = 0; j < playersPerTeam; j++) {
    	Player player = battingTeam->players[j];
    	cout << "|---------------------------------"
    			"---------------|" << endl;
    	cout << "| " << "[" << j << "] " << player.name << "  \t "
        	<< player.runsScored << "(" << player.ballsPlayed << ") \t\t "
			<< player.ballsBowled << "-" << player.runsGiven << "-"
			<< player.wicketsTaken << "\t |" << endl;
    }
    cout << "================================================" << endl << endl;

    cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << endl;

    cout << "============================================"
    		""
    		"=====" << endl;
    cout << "| PLAYER \t     BATTING \t   BOWLING    |" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
    	Player player = bowlingTeam->players[i];
        cout << "|------------------------------------------------|" << endl;
        cout << "| " << "[" << i << "] " << player.name << "  \t "
            << player.runsScored << "(" << player.ballsPlayed << ") \t\t "
            << player.ballsBowled << "-" << player.runsGiven << "-"
			<< player.wicketsTaken << "\t |" << endl;
    }
    cout << "================================================" << endl << endl;
	
}
