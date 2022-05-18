#include"TeamStatistics.hpp"
#include "League.hpp"

using namespace std;

int main()
{
	League league;

	int teamsCount;
	cout << "Anzahl Teams: ";
	cin >> teamsCount;

	for (int i = 0; i < teamsCount; i++)
	{
		string abbr;
		cin >> abbr;
		league.addTeam(abbr);
	}

	cout << "[Heim-Kürzel] [Heim-Tore] [Auswärts-Tore] [Auswärts-Kürzel]" << endl;

	string home;
	string other;
	unsigned int homeScore;
	unsigned int otherScore;

	while (cin >> home >> homeScore >> otherScore >> other) {
		league.addGame(home, other, { homeScore, otherScore });
	}

	cout << "Resultate: " << endl;

	league.Print();

	return 0;
}