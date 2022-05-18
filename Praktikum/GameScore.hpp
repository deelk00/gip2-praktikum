#pragma once
#include<iostream>

struct GameScore
{
	unsigned int scored = 0;
	unsigned int received = 0;
};

inline int CalcGoalDifference(GameScore score) {
	return score.scored - score.received;
}

inline void PrintGoalDifference(GameScore score) {
	std::cout << std::showpos << CalcGoalDifference(score) << std::noshowpos;
}

inline void PrintScore(GameScore score) {
	std::cout << score.scored << ":" << score.received;
}