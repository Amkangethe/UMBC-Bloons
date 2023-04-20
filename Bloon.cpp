/***********************************************************
 ** File:    Bloon.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/7/2023
 ** Section: 34
 **********************************************************/
#include "Bloon.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//Abstract class - cannot directly instantiate this class
Bloon::Bloon() //Default Constructor
{
  m_health = 0;
  m_location = 0;
}

//Makes sure everything in child class is deallocated
Bloon::Bloon(int health, int location) //Overloaded Constructor
{
  m_health = health;
  m_location = location;
}

//Makes sure everything in child class is deallocated
Bloon::~Bloon()
{
  //This class is virtual, no need for code
}

//Returns health of bloon
int Bloon::GetHealth()
{
  return m_health;
}

//Sets health of bloon
void Bloon::SetHealth(int health)
{
  m_health = health;
}

//Returns location of bloon
int Bloon::GetLocation()
{
  return m_location;
}

//Sets location of bloon
void Bloon::SetLocation(int location)
{
  m_location = location;
}

//Defines popping
int Bloon::Pop(int damage)
{
  //This class is virtual, no need for code
  return 0;
}

//Virtually Gets Color
string Bloon::GetColor()
{
  //This class is virtual, no need for code
  return "";
}

//Prints the detials of a bloon
ostream &operator<< (ostream &output, Bloon &myBloon)
{
	output << "Bloon: " << myBloon.GetColor() << " ";
	output << "Health: " << myBloon.GetHealth();

	return output;
}
