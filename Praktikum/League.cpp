#include "League.hpp"

League::League()
{
}

League::~League()
{
}

void League::addGame(string home, string other, GameScore score) {
	TeamStatistics* homeStats = this->teams.find(home)->second;
	TeamStatistics* otherStats = this->teams.find(other)->second;

	homeStats->AddGame(score);
	otherStats->AddGame({ score.received, score.scored });
}

void League::addTeam(string abbr) {
	this->teams.insert({ abbr, new TeamStatistics(abbr) });
}

void League::Print() {
	int arraySize = this->teams.size();
	TeamStatistics** ts = (TeamStatistics**)malloc(sizeof(TeamStatistics*) * arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		ts[i] = nullptr;
	}

	for (pair<string, TeamStatistics*> teamPair : this->teams) {
		TeamStatistics* stats = teamPair.second;

		for (int i = 0; i < arraySize; i++)
		{
			if(ts[i] == nullptr) {
				ts[i] = stats;
				break;
			}
			else if (*ts[i] < *stats) {
				TeamStatistics* temp = ts[i];
				ts[i] = stats;
				stats = temp;
			}
		}
	}

	for (int i = 0; i < arraySize; i++) {
		ts[i]->Print();
	}
}


bool Condition(TeamStatistics* t, TeamStatistics* other) {
	int thisDiff = CalcGoalDifference(t->_totalScore);
	int otherDiff = CalcGoalDifference(other->_totalScore);
	if (t->_totalScore.scored > other->_totalScore.scored)
		return true;
	if (t->_points == other->_points) {
		if (thisDiff > otherDiff) {
			return true;
		}
		if (thisDiff == otherDiff
			&& t->_abbr.length() > other->_abbr.length()) {
			return true;
		}
	}

	return false;
}