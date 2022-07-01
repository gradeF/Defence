#pragma once
#include <vector>
#include <string>
#include "framework.h"
class DataHandler
{
public:
	DataHandler()
	{
	};
	void SetData(std::string ID, int score)
	{
		this->ID.push_back(ID);
		this->score.push_back(score);

	};
	void GetData() const;
	void Sort()
	{

	}
private:
	std::vector <std::string> ID;
	std::vector <int> score;
};

