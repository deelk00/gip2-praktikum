#pragma once
#include<map>+
#include <string>
#include "TeamStatistics.hpp"

using namespace std;

class League
{
public:
	League();
	~League();

	void addTeam(string abbr);
	void addGame(string home, string other, GameScore score);

	void Print();

private:
	map<string, TeamStatistics*> teams;
};