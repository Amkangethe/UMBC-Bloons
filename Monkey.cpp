/***********************************************************
 ** File:    Monkey.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/7/2023
 ** Section: 34
 **********************************************************/
#include "Monkey.h"
#include "Basic.h"
#include "Bloon.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

//Default Constructor
Monkey::Monkey()
{
  m_type = "";
  m_damage = 0;
  m_location = 0;
}

// Overloaded Constructor
Monkey::Monkey(string type, int damage, int location)
{
  SetType(type);
  SetDamage(damage);
  SetLocation(location);
}

//Destructor
Monkey::~Monkey()
{
  //This class is virtual, no need for code
}

//Returns type of monkey
string Monkey::GetType()
{
  return m_type;
}

//Returns damage of monkey
int Monkey::GetDamage()
{
  return m_damage;
}

//Returns location of monkey
int Monkey::GetLocation()
{
  return m_location;
}

//Sets type of monkey
void Monkey::SetType(string type)
{
  m_type = type;
}

//Sets damage of monkey
void Monkey::SetDamage(int damage)
{
  m_damage = damage;
}

//Set location of monkey
void Monkey::SetLocation(int location)
{
  m_location = location;
}

//Defines attack for an monkey
int Monkey::Attack(vector<Bloon*> bloon)
{
  //This class is virtual, no need for code
  return 0;
}

//Prints the detials of a monkey
ostream &operator<< (ostream &output, Monkey &myMonkey)
{
	output << myMonkey.GetType() << ": Location " << myMonkey.GetLocation() << " ";
	output << "Damage: " << myMonkey.GetDamage();

	return output;

}
