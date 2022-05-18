#include"TeamStatistics.hpp";


TeamStatistics::TeamStatistics(string abbr)
{
	this->_abbr = abbr;
}

TeamStatistics::~TeamStatistics()
{
}


void TeamStatistics::Print() {
	cout << this->_abbr << " " << this->_games << " " << this->_points << " ";

	PrintScore(this->_totalScore);

	cout << " ";

	PrintGoalDifference(this->_totalScore);

	cout << endl;
}

void TeamStatistics::AddGame(GameScore score) {
	this->_totalScore.scored += score.scored;
	this->_totalScore.received += score.received;

	if (score.scored > score.received) this->_points += 3;
	if (score.scored == score.received) this->_points += 1;

	this->_games++;
}

bool TeamStatistics::operator < (const TeamStatistics& other) const {
	int thisDiff = CalcGoalDifference(this->_totalScore);
	int otherDiff = CalcGoalDifference(other._totalScore);

	if (this->_points < other._points)
		return true;
	if (this->_points == other._points) {
		if (thisDiff < otherDiff) {
			return true;
		}
		if (thisDiff == otherDiff
			&& this->_abbr.length() < other._abbr.length()) {
			return true;
		}
	}

	return false;
}