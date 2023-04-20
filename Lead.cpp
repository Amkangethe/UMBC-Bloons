/***********************************************************
 ** File:    Lead.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/19/2023
 ** Section: 34
 **********************************************************/
#include "Lead.h"
#include "Bloon.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Lead::Lead() : Bloon()
{
  m_color = "Invisible";
}

// Overloaded constructor
Lead::Lead(int health, int location) : Bloon(health, location)
{

  //Make color equal lead
  m_color = "Lead";

}

// Destructor
Lead::~Lead()
{
  //Nothing here needed
}

// Changes the color of the bloon based on how many health it has left
int Lead::Pop(int damage)
{
  //Total pops
  int totalPops = 0;

  //total pops is the lesser of health or damage
  if (GetHealth() < damage)
    {
      totalPops = GetHealth();
    }
  else
    {
      totalPops = damage;
    }

  //Set health
  SetHealth(GetHealth() - damage);


  //return
  return totalPops;
}




// Returns the current color of a bloon
string Lead::GetColor()
{
  return m_color;
}
