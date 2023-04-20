/***********************************************************
 ** File:    Lead.h
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/19/2023
 ** Section: 34
 ** This file contains the header file of the Lead class
 **********************************************************/
#ifndef LEAD_H_
#define LEAD_H_

#include "Bloon.h"

/*Lead bloons can only be hurt initially by bomb monkeys.
  Once they are damaged by a bomb monkey,
  they turn into a basic bloon(black with health of 10).*/

//


class Lead : public Bloon {
 public:
  // Name: Lead() - Default Constructor
  // Description: Creates a new Lead Bloon
  // Preconditions: None
  // Postconditions: Can create a Lead Bloon
  Lead();
  // Name: Lead(int health, int location)
  // Description: Creates a new Lead bloon with health at a specific location
  // Preconditions: None
  // Postconditions: Can create a Lead bloon
  Lead(int, int);
  // Name: ~Lead - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Lead();
  // Name: Pop
  // Description: Just pops it once and makes it into black bloon
  // Preconditions: None
  // Postconditions: Returns number of pops that occurred.
  // Number of pops is the lesser of (health left of bloon) or (damage caused by monkey).
  int Pop(int damage);
  // Name: GetColor()
  // Description: Returns the current color of a bloon
  // Preconditions: None
  // Postconditions: None
  string GetColor();
 private:
  string m_color;
};
#endif
