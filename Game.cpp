/***********************************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/9/2023
 ** Section: 34
 **********************************************************/
#ifndef GAME_CPP
#define GAME_CPP
#include "Monkey.h" //Parent class of all monkeys
#include "Dart.h" //Child class of monkey
#include "Bomb.h" //Child class of monkey
#include "Boomerang.h" //Child class of monkey
#include "Bloon.h" //Parent class of all bloons
#include "Basic.h" //Child class of bloon
#include "Lead.h" //Child class of bloon
#include "Zebra.h" //Child class of bloon
#include "Game.h"
//Includes of allowed libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*
**Constants related to starting game**
const int START_ROUND = 1; //Starting round
const int START_LIFE = 100; //Starting life (num damage before losing game)
const int START_MONEY = 10; //Starting money for player

Constants related to the length of the path
const int PATH_LENGTH = 3; //Length of the path (could be anything)
const int START_BLOON = -1; //Starting location of all bloons

**Constants related to money/cost**
const int COST_DART = 2; //Starting cost for dart monkey
const int COST_BOOMERANG = 4; //Starting cost for boomerang monkey
const int COST_BOMB = 6; //Starting cost for a bomb monkey
const int COST_IMPROVE = 2; //Cost for each improvement (regardless of type)
const int EARN_POP = 1; //Earnings per pop of a bloon
const int IMPROVE_VALUE = 2; //When a monkey is improved, increases the value based on this

**Constants related to damage**
const int DAMAGE_DART = 1; //Starting damage for dart monkey
const int DAMAGE_BOOM = 1; //Starting damage for boomerage monkey
const int DAMAGE_BOMB = 1; //Starting damage for bomb monkey
*/

//Default Constructor
Game::Game()
{
	//Make everything at base.
	m_curRound = START_ROUND; //Tracks number of rounds played in game.
	m_curMoney = START_MONEY; //Tracks current money for upgrades.
	m_curLife = START_LIFE; //Tracks current life. When 0, game over.
}

//Destructor
Game::~Game()
{
	for ( unsigned int i = 0; i < m_monkeys.size(); i++)
	{
		delete m_monkeys.at(i);

	}

	for ( unsigned int i = 0; i < m_bloons.size(); i++)
	{
		delete m_bloons.at(i);

	}
}

//Welcomes the player to the game. Continually calls MainMenu until user quits
void Game::StartGame()
{
	//User input
	int choice = 0;
	
	//Welcome
	cout << "Welcome to UMBC Bloons" << endl;
	
	//Loop through MainMenu()
	while (choice != 6 || m_curLife <= 0)
	{
		if (m_curLife <= 0)
		{
			cout << "Sorry, you have lost the game." << endl;
			return;
		}
		choice = MainMenu();
	}

	//When game quits
	cout << "Thanks for playing!" << endl;
}

//Checks to see if player still has life.If m_curLife <= 0, game ends with loss.
//Calls function related to user choice.
int Game::MainMenu()
{
	//User input
	int choice = 0;

	//Get users input from options
	cout << "What would you like to do ?" << endl;
	cout << "1. View Map" << endl;
	cout << "2. Buy New Monkey" << endl;
	cout << "3. Improve Existing Monkey" << endl;
	cout << "4. Progress Round" << endl;
	cout << "5. Check Stats" << endl;
	cout << "6. Quit" << endl;

	cin >> choice;

	//Function based off choice
	switch (choice)
	{
	case 1:
		PrintMap();
		break;
	case 2:
		BuyMonkey();
		break;
	case 3:
		ImproveMonkey();
		break;
	case 4:
		PlayRound();
		break;
	case 5:
		Stats();
		break;
	}

	//Return
	return choice;

}

//For each location on the path, outputs the bloonsand the monkeys(or none)
void Game::PrintMap()
{
	int monkCounter = 1, bloonCounter = 1;

	//Loop through all paths on map
	for (int currPath = 1; currPath <= PATH_LENGTH; currPath++)
	{
		bool MFound = false;
		bool BFound = false;
		//Display
		cout << "**Location " << currPath << "**" << endl;
		cout << "--Monkeys--" << endl;

		//Loop through monkey vector
		for (long unsigned int i = 0; i < m_monkeys.size(); i++)
		{
			if (m_monkeys.at(i)->GetLocation() == currPath)
			{
				MFound = true;
			}
		}
		//IF no monkeys found on path
		if (!MFound)
		{
			cout << "NONE" << endl;
		}
		else
		{
			//Loops through vector
			for (long unsigned int element = 0; element < m_monkeys.size(); element++)
			{
				//If monkey is at the same path as current
				if (m_monkeys.at(element)->GetLocation() == currPath)
				{
					//Display Monkey
					cout << monkCounter << ". " << * m_monkeys.at(element) << endl;
					monkCounter++;
				}
			}
		}

		//Reset monkey counter
		monkCounter = 1;

		
		cout << "<<Bloons>>" << endl;
		//Loop through bloon vector
		for (long unsigned int i = 0; i < m_bloons.size(); i++)
		{
			if (m_bloons.at(i)->GetLocation() == currPath)
			{
				BFound = true;
			}
		}
		if (!BFound)
		{
			cout << "NONE" << endl;
		}
		else
		{
			//Loops through vector
			for (long unsigned int element = 0; element < m_bloons.size(); element++)
			{
				//If bloon is at the same path as current
				if (m_bloons.at(element)->GetLocation() == currPath)
				{
					//Display Bloon
					cout << bloonCounter << ". " << *m_bloons.at(element) << endl;
					bloonCounter++;
				}
			}

		}

		//Reset bloon counter
		bloonCounter = 1;

		cout << endl;
	}
}

//Asks the user which monkey they would like to buy
//Reduces m_curMoney and then calls PlaceMonkey (which creates and places new monkey)
void Game::BuyMonkey()
{
	//Display optins and get user choice
	int type = 0;
	cout << "What type of monkey would you like to buy?" << endl;
	cout << "1. Dart Monkey" << endl;
	cout << "2. Boomerang Monkey" << endl;
	cout << "3. Bomb Monkey" << endl;
	cout << "4. Cancel" << endl;

	cin >> type;

	while (type < 1 || type > 4)
	{
		cout << "Enter a number 1-4:" << endl;
		cin >> type;
	}

	//Check if user can afford monkey type
	switch (type)
	{
	case 1:
		if(m_curMoney - COST_DART < 0)
		{
			cout << "Cannot afford Dart Monkey!" << endl;
			return;
		}
		m_curMoney -= COST_DART;
		break;
	case 2:
		if (m_curMoney - COST_BOOMERANG < 0)
		{
			cout << "Cannot afford Boomerang Monkey!" << endl;
			return;
		}
		m_curMoney -= COST_BOOMERANG;
		break;
	case 3:
		if (m_curMoney - COST_BOMB < 0)
		{
			cout << "Cannot afford Bomb Monkey!" << endl;
			return;
		}
		m_curMoney -= COST_BOMB;
		break;
	default:
		cout << "Cancelled" << endl;
		return;
	}


	//Place monkey
	PlaceMonkey(type);


}

//Based on monkey purchased in BuyMonkey, asks user where to place new monkey
//Dynamically allocates new monkey and populates location and adds to m_monkey
void Game::PlaceMonkey(int type)
{
	int path = 0;
	//Ask for path location, cancel
	cout << "Where would you like to place the new monkey? (1-" << PATH_LENGTH << ")" << endl;
	cin >> path;

	//If path is invalid
	while(path < 1 || PATH_LENGTH < path)
	{
		cout << "Enter a location 1-" << PATH_LENGTH << ":" << endl;
		cin >> path;
	}

	//Put new Monkey into vector
	if (type == 1)
	{
		Monkey * dart = new Dart("Dart Monkey", DAMAGE_DART, path);
		m_monkeys.push_back(dart);
		cout << "New " << dart->GetType() << " placed in location " << dart->GetLocation() << endl;
	}
	else if (type == 2)
	{
		Monkey* boom = new Boomerang("Boomerang Monkey", DAMAGE_BOOM, path);
		m_monkeys.push_back(boom);
		cout << "New " << boom->GetType() << " placed in location " << boom->GetLocation() << endl;

	}
	else if(type == 3)
	{
		Monkey *bomb = new Bomb("Bomb Monkey", DAMAGE_BOMB, path);
		m_monkeys.push_back(bomb);
		cout << "New " << bomb->GetType() << " placed in location " << bomb->GetLocation() << endl;

	}
}

//Asks the user which monkey they would like to improve
//Increases chosen monkey's damage by IMPROVE_VALUE above
void Game::ImproveMonkey()
{
	//Return if no monkeys
	if (m_monkeys.empty())
	{
		cout << "Buy a monkey first!" << endl;
		return;
	}
	//Return if cant afford to improve
	if (m_curMoney - COST_IMPROVE < 0)
	{
		cout << "Can't afford improvements" << endl;
		return;
	}

	//Choice
	long unsigned int choice = 0, monkCounter = 1;

	//Display monkeys
	cout << "Which monkey would you like to improve (1-" << m_monkeys.size() << ")" << endl;
	
	//Loops through vector
	for (long unsigned int element = 0; element < m_monkeys.size(); element++)
	{
		//Display Monkey
		cout << monkCounter << ". " << *m_monkeys.at(element) << endl;
		monkCounter++;
		
	}
	cin >> choice;

	//Validate choice
	while (choice < 1 || choice > m_monkeys.size())
	{
		cout << "Enter a monkey 1-" << m_monkeys.size() << ":" << endl;
		cin >> choice;
	}

	choice--;

	//Improve damage
	int currDamage = m_monkeys.at(choice)->GetDamage();
	currDamage += IMPROVE_VALUE;

	//Improve damge to monkey
	if(m_monkeys.at(choice)->GetType() == "Dart Monkey")
	{
		m_curMoney -= COST_IMPROVE;
		m_monkeys.at(choice)->SetDamage(currDamage);
		cout << m_monkeys.at(choice)->GetType() << " in position " << m_monkeys.at(choice)->GetLocation() << " improved!" << endl;
	}
	else if (m_monkeys.at(choice)->GetType() == "Boomerang Monkey")
	{
		m_curMoney -= COST_IMPROVE;
		m_monkeys.at(choice)->SetDamage(currDamage);
		cout << m_monkeys.at(choice)->GetType() << " in position "<<  m_monkeys.at(choice)->GetLocation() << " improved!" << endl;

	}
	else if (m_monkeys.at(choice)->GetType() == "Bomb Monkey")
	{
		m_curMoney -= COST_IMPROVE;
		m_monkeys.at(choice)->SetDamage(currDamage);
		cout << m_monkeys.at(choice)->GetType() << " in position " << m_monkeys.at(choice)->GetLocation() << " improved!" << endl;

	}
}

// Announces beginning and end of round
//Calls PopulateBloons once then ResolveBattle once.
//Calls RemovePopped (5 times due to erase function)
//Calls MoveBloons once then calls CheckPath (5 times due to erase call)
//Increments curRound
void Game::PlayRound()
{
	
	cout << "Starting Round " << m_curRound << endl;

	//Populate Bloons
	PopulateBloons();

	//Resolve Bloons
	ResolveBattle();
	
	//Removed Popped
	for (int i = 0; i < 5; i++)
	{
		RemovePopped();
	}
	
	//Move bloons
	MoveBloons();
	
	


	//Check lead
	for (int i = 0; i < 100; i++)
	{
		CheckLead();
	}

	//Check Zebra
	for (int i = 0; i < 100; i++)
	{
		CheckZebra();
	}

	//Check Path
	for (int i = 0; i < 5; i++)
	{
		CheckPath();
	}

	//Complete Round
	cout << "Round " << m_curRound << " Completed" << endl;
	
	//Start Next Round
	++m_curRound;

}

// Description: Each round, dynamically allocated bloons added to path in position START_BLOON
void Game::PopulateBloons()
{
	Bloon* bloon;

	//Loops through round count
	for (int round = 1; round <= m_curRound; round++)
	{
		if (round == 1)
		{
			bloon = new Basic(1, START_BLOON + 1);
		}
		else if (round == 2)
		{
			bloon = new Basic(2, START_BLOON + 1);
		}
		else if (round == 3)
		{
			bloon = new Basic(3, START_BLOON + 1);
		}
		else if (round == 4)
		{
			bloon = new Basic(4, START_BLOON + 1);
		}
		else if (round == 5)
		{
			bloon = new Basic(5, START_BLOON + 1);
		}
		else if (round == 6)
		{
			bloon = new Basic(6, START_BLOON + 1);
		}
		else if (round > 6)
		{
			bloon = new Basic(6 + (round - 6), START_BLOON + 1);
		}

		//Add Bloon
		cout << "A new " << bloon->GetColor() << " bloon appears!" << endl;
		m_bloons.push_back(bloon);

		if (round > 10)
		{
			bloon = new Lead(round, START_BLOON + 1);
			cout << "A new " << bloon->GetColor() << " bloon appears!" << endl;
			m_bloons.push_back(bloon);
		}

		if (round > 12)
		{
			bloon = new Zebra(round, START_BLOON + 1);
			cout << "A new " << bloon->GetColor() << " bloon appears!" << endl;
			m_bloons.push_back(bloon);
		}

	
	}
}

// Description: Each monkey attacks the whole bloon vector.
//For each pop, curMoney is increased.
void Game::ResolveBattle()
{

	for (long unsigned int monkey = 0; monkey < m_monkeys.size(); monkey++)
	{
		int pop = EARN_POP * m_monkeys.at(monkey)->Attack(m_bloons);
		m_curMoney += pop;
	}
}

//Iterates through m_bloons and if health is <= 0, bloon is deallocated removed from m_bloons
void Game::RemovePopped()
{
	for (long unsigned int i = 0; i < m_bloons.size(); i++)
	{
		if (m_bloons.at(i)->GetHealth() <= 0)
		{
			//deallocate memory, remove bloon from vector, fix count
			delete m_bloons.at(i);
			m_bloons.erase(m_bloons.begin() + i);
			i = 0;
		}
	}

	
}

//For each Lead bloon less than 11 health, delete and make black bloon
void Game::CheckLead()
{
	int location = 0;
	Bloon* bloon;


	for (long unsigned int b = 0; b < m_bloons.size(); b++)
	{
		if (m_bloons.at(b)->GetColor() == "Lead" && m_bloons.at(b)->GetHealth() < 11)
		{
			location = m_bloons.at(b)->GetLocation();

			//cout << m_bloons.at(b)->GetColor() << " at location " << m_bloons.at(b)->GetLocation() << endl;

			//deallocate memory, remove bloon from vector
			delete m_bloons.at(b);
			m_bloons.erase(m_bloons.begin() + b);

			//Make basic bloon with health 10
			bloon = new Basic(10, location);

			//Announce Lead has become basic
			//cout << "Lead " << endl;

			//Insert new bloon
			m_bloons.insert(m_bloons.begin() + b, bloon);

			//Fix count
			b = 0;
		}
	}
}

//For each Lead bloon less than 13 health, delete and make black bloon
void Game::CheckZebra()
{
	int location = 0;
	Bloon* bloon;


	for (long unsigned int b = 0; b < m_bloons.size(); b++)
	{
		if (m_bloons.at(b)->GetColor() == "Zebra" && m_bloons.at(b)->GetHealth() < 13)
		{
			location = m_bloons.at(b)->GetLocation();

			//cout << "Found Zebra at " << m_bloons.at(b)->GetLocation() << endl;
			
			
			//deallocate memory, remove bloon from vector
			delete m_bloons.at(b);
			m_bloons.erase(m_bloons.begin() + b);

			//Make two basic black bloons with health 10
			for (int i = 0; i < 2; i++)
			{
				bloon = new Basic(12, location);

				//Insert new bloon
				m_bloons.insert(m_bloons.begin() + b, bloon);

				

				//cout << m_bloons.at(b)->GetColor() << " at location " << m_bloons.at(b)->GetLocation() << endl;
			}

			//Fix count
			b = 0;

			
		}
	}
}


//For each bloon that still lives, it moves one location down the path
void Game::MoveBloons()
{
    //Move bloons
	for (long unsigned int bloon = 0; bloon < m_bloons.size(); bloon++)
	{
		m_bloons.at(bloon)->SetLocation(m_bloons.at(bloon)->GetLocation() + 1);
	}
	cout << "The bloons move along the path" << endl;
}


// Name: CheckPath
// Description: Iterates over m_bloons to see if location is equal to (or greater than)
//              PATH_LENGTH. If location is equal to PATH_LENGTH, causes damage to player.
//              Damage to player is one per health of bloon.
//              If 10 green bloons (health 3) hit player, player takes 30 damage
//              Bloons that hurt player are deallocated and erased from m_bloons
//              HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed
void Game::CheckPath()
{
	int injury = 0;

	for (unsigned int i = 0; i < m_bloons.size(); i++)
	{
		if (m_bloons.at(i)->GetLocation() > PATH_LENGTH)
		{
			//output damage of bloon
			injury += m_bloons.at(i)->GetHealth();
			cout << "A bloon made it to the end of the path and you took " << m_bloons.at(i)->GetHealth() << " damage" << endl;
			

			delete m_bloons.at(i);
			m_bloons.erase(m_bloons.begin() + i);
			i = 0;

		}
	}
	m_curLife -= injury;
}


//Displays the information about the game
//(current round, number of monkeys, money, and lives left)
void Game::Stats()
{
	cout << "**CURRENT STATS**" << endl;
	cout << "Current Round: " << m_curRound << endl;
	cout << "Monkeys Working: " << m_monkeys.size() << endl;
	cout << "Current Money: " << m_curMoney << endl;
	cout << "Current Life: " << m_curLife << endl;
}


#endif












