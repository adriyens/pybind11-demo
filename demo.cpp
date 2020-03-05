/**
* @file
* Implementations of demo classes: Pet, Dog, Cat, and Car.
*/

#include "demo.h"
#include <iostream>


/* Basic function implementation. */
int add(int i, int j)
{
   return i + j;
}


/* Pet class implementations. */
Pet::Pet()
{
}

Pet::Pet(const string &name) : m_name(name)
{
}

void Pet::setName(const string &name)
{
   m_name = name;
}

const string Pet::getName()
{
   return m_name;
}


/* Dog class implementations. */
Dog::Dog()
{
}

Dog::Dog(const string &name)
{
   setName(name);
}

string Dog::sound()
{
   return "woof!";
}


/* Cat class implementations. */
Cat::Cat()
{
}

Cat::Cat(const string &name)
{
   setName(name);
}

string Cat::sound()
{
   return "meow!";
}


/* Car class implementations. */
Car::Car()
{
}

void Car::loadCar(Pet *pet)
{
   pets.push_back(pet);
}

void Car::dumpCar()
{
   for (int i = 0; i < pets.size(); i++)
   {
      cout << i + 1 << ": " << pets.at(i)->getName() << endl;
   }
}

