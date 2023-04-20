/***********************************************************
 ** File:    Zebra.h
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/19/2023
 ** Section: 34
 ** This file contains the header file of the Zebra class
 **********************************************************/
#ifndef ZEBRA_H
#define ZEBRA_H

#include "Bloon.h"

 /*Zebra bloons split into two basic bloons (black with health of 10 each)*/


class Zebra : public Bloon {
public:
	// Name: Zebra() - Default Constructor
	// Description: Creates a new Zebra Bloon
	// Preconditions: None
	// Postconditions: Can create a Zebra Bloon
	Zebra();
	// Name: Zebra(int health, int location)
	// Description: Creates a new Zebra bloon with health at a specific location
	// Preconditions: None
	// Postconditions: Can create a Zebra bloon
	Zebra(int, int);
	// Name: ~Zebra - Virtual Destructor
	// Description: Makes sure everything in child class is deallocated
	// Preconditions: None
	// Postconditions: Everything dynamically allocated is deallocated
	~Zebra();
	// Name: Pop
	// Description: Just pops it once and makes it into black bloon and white bloon
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
