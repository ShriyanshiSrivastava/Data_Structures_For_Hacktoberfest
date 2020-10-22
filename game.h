#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"

class Game
{
	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;

		void Welcome();
		void showAllPlayers();
		int takeIntegerInput();
		void selectPlayers();
		bool validate(int);
		void printTeams();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScorecard();
		void startSecondInnings();
		void summary();
};
