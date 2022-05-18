#pragma once
#include<string>
#include<iostream>
#include"GameScore.hpp"

using namespace std;

class TeamStatistics
{
public:
	TeamStatistics(string abbr);
	~TeamStatistics();

	void AddGame(GameScore score);

	void Print();

	bool operator < (const TeamStatistics& other) const;
	string _abbr;
	unsigned int _points = 0;
	unsigned int _games = 0;
	GameScore _totalScore = {};

private:
};