/***********************************************************
 ** File:    Zebra.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/20/2023
 ** Section: 34
 **********************************************************/
#include "Zebra.h"
#include "Bloon.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Zebra::Zebra() : Bloon()
{
    m_color = "Invisible";
}

// Overloaded constructor
Zebra::Zebra(int health, int location) : Bloon(health, location)
{

    //Make color equal Zebra
    m_color = "Zebra";

}

// Destructor
Zebra::~Zebra()
{
    //Nothing here needed
}

// Changes the color of the bloon based on how many health it has left
int Zebra::Pop(int damage)
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
string Zebra::GetColor()
{
    return m_color;
}
