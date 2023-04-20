/***********************************************************
 ** File:    Bomb.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/7/2023
 ** Section: 34
 **********************************************************/
#include "Bomb.h"
#include "Bloon.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

// Default Constructor
Bomb::Bomb() : Monkey()
{
  //Calls the Monkey default constructor through inheritance.
}

// Overloaded constructor
Bomb::Bomb(string type, int damage, int location) : Monkey(type, damage, location)
{
  //Calls the Monkey overloaded constructor through inheritance.
}

// Virtual Destructor
Bomb::~Bomb()
{
  //No dynamically allocated memory
}

//Iterates through all bloons.Hits all bloons in same location as bomb.
//Returns total bloon health or damage (whichever is less) for earnings (money)
int Bomb::Attack(vector <Bloon*> bloon)
{

	//Pop is originally 0
	int pop = 0;


    for (long unsigned int b = 0; b < bloon.size(); b++)
    {

        //If bloon is at the same location as dart monkey
        if (bloon.at(b)->GetLocation() == GetLocation())
        {
            //If bloon is lead bloon
            if (bloon.at(b)->GetColor() == "Lead")
            {
                //Throw bomb
                cout << "The " << GetType() << " launches a bomb!" << endl;

                //If when bombed, is less than 11, then:
                if (bloon.at(b)->GetHealth() - GetDamage() < 11)
                {
                    //Pop bloon
                    pop += bloon.at(b)->Pop(GetDamage());

                    //Announce bloon is popped and now black
                    cout << "The " << bloon.at(b)->GetColor() << " bloon pops!" << endl;
                    cout << "The bloon is now black!" << endl;


                }
                else
                {
                    pop += bloon.at(b)->Pop(GetDamage());
                }

            }
            else if (bloon.at(b)->GetColor() == "Zebra")
            {
                //Throw bomb
                cout << "The " << GetType() << " launches a bomb!" << endl;

                //If when bombed, is less than 11, then:
                if (bloon.at(b)->GetHealth() - GetDamage() < 13)
                {
                    //Pop bloon
                    pop += bloon.at(b)->Pop(GetDamage());

                    //Announce bloon is popped and now black
                    cout << "The " << bloon.at(b)->GetColor() << " bloon pops!" << endl;
                    cout << "The bloon has split into two black bloons!" << endl;


                }
                else
                {
                    pop += bloon.at(b)->Pop(GetDamage());
                }

            }
            else
            {
                //Monkey shoots dart at first bloon and returns
                cout << "The " << GetType() << " launches a bomb!" << endl;
                cout << "The " << bloon.at(b)->GetColor() << " bloon pops!" << endl;
                pop += bloon.at(b)->Pop(GetDamage());

                //announce new bloon
                int currHealth = bloon.at(b)->GetHealth();

                if (currHealth <= 0)
                {
                    cout << "The bloon is now gone!" << endl;
                }
                else if (currHealth == 1)
                {
                    cout << "The bloon is now red." << endl;
                }
                else if (currHealth == 2)
                {
                    cout << "The bloon is now blue." << endl;
                }
                else if (currHealth == 3)
                {
                    cout << "The bloon is now green." << endl;
                }
                else if (currHealth == 4)
                {
                    cout << "The bloon is now yellow." << endl;
                }
                else if (currHealth == 5)
                {
                    cout << "The bloon is now pink." << endl;
                }

            }





        }




    }

	//Return 0 if nothing
	return pop;
}
