#include "game.h"

using namespace std;

int main() {

	Game g;
	g.Welcome();
	g.showAllPlayers();

	cout << "\nPress Enter to Continue";
	cin.ignore();

	g.selectPlayers();
	g.printTeams();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "\nPress Enter to Toss";
	cin.ignore();

	g.toss();
	g.startFirstInnings();
	g.startSecondInnings();
	g.summary();

	return 0;
}
