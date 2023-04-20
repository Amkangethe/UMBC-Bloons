/***********************************************************
 ** File:    Boomerang.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Allan Kangethe
 ** Date     4/7/2023
 ** Section: 34
 **********************************************************/
#include "Boomerang.h"
#include "Bloon.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

 // Default Constructor
Boomerang::Boomerang() : Monkey()
{
    //Calls the Monkey default constructor through inheritance.
}

// Overloaded constructor
Boomerang::Boomerang(string type, int damage, int location) : Monkey(type, damage, location)
{
    //Calls the Monkey overloaded constructor through inheritance.
}

// Virtual Destructor
Boomerang::~Boomerang()
{
    //No dynamically allocated memory
}

//Iterates through all bloons.For each bloon in the same location as boomerang,
//hits each bloon twice (once out and once back)
int Boomerang::Attack(vector <Bloon*> bloon)
{
    int pop = 0;

    // Create a vector to store the bloons hit by the boomerang
    vector<Bloon*> bloonsHit;

    for (long unsigned int b = 0; b < bloon.size(); b++)
    {


        if (bloon.at(b)->GetLocation() == GetLocation())
        {



            if (bloon.at(b)->GetColor() == "Zebra")
            {
                //Throw boomerang
                cout << "The " << GetType() << " throws a boomerang at the bloon!" << endl;

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
            else if (bloon.at(b)->GetColor() != "Lead")
            {
                // Hit the bloon once
                cout << "The " << GetType() << " throws a boomerang at the bloon!" << endl;
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


                // Add the bloon to the list of hit bloons
                if (bloon.at(b)->GetHealth() > 0)
                {
                    bloonsHit.push_back(bloon.at(b));

                }
            }



        }



    }

    // Hit the bloons that have been hit once again
    for (long unsigned int i = 0; i < bloonsHit.size(); i++)
    {

        cout << "The " << bloonsHit.at(i)->GetColor() << " bloon pops!" << endl;
        pop += bloonsHit.at(i)->Pop(GetDamage());

        //announce new bloon
        int currHealth = bloonsHit.at(i)->GetHealth();

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

    return pop;
}

