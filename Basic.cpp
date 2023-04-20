/***********************************************************
 ** File:    Basic.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/7/2023
 ** Section: 34
 **********************************************************/
#include "Basic.h"
#include "Bloon.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Basic::Basic() : Bloon()
{
  m_color = "Invisible";
}

// Overloaded constructor
Basic::Basic(int health, int location) : Bloon(health, location)
{
    int currHealth = health;

   
    if (currHealth == 1)
    {
        m_color = "red";
    }
    else if (currHealth == 2)
    {
        m_color = "blue";
    }
    else if (currHealth == 3)
    {
        m_color = "green";
    }
    else if (currHealth == 4)
    {
        m_color = "yellow";
    }
    else if (currHealth == 5)
    {
        m_color = "pink";
    }
    else
    {
        m_color = "black";
    }
}

// Destructor
Basic::~Basic()
{
}

// Changes the color of the bloon based on how many health it has left
int Basic::Pop(int damage)
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



  int currHealth = GetHealth();
 
  if (currHealth <= 0)
    {
     // SetHealth(currHealth);
      return totalPops;
    }
  else if (currHealth == 1)
    {
      m_color = "red";
    }
  else if (currHealth == 2)
    {
      m_color = "blue";
    }
  else if (currHealth == 3)
    {
      m_color = "green";
    }
  else if (currHealth == 4)
    {
      m_color = "yellow";
    }
  else if (currHealth == 5)
    {
      m_color = "pink";
    }
  else
    {
      m_color = "black";
    }

  //return
  return totalPops;
}




// Returns the current color of a bloon
string Basic::GetColor()
{
  return m_color;
}
