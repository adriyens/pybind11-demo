#pragma once
/**
* @file
* Definitions of demo function add() and classes: Pet, Dog, Cat, Car.
*/

// Include pybind11 headers before any other.
#include <pybind11/pybind11.h>
#include <string>

// Just makes things easier.
namespace py = pybind11;
using namespace std;


/** Basic function example. Adds two ints together.
* @param int to add.
* @param int to add.
* @return sum of two ints.
*/
int add(int i, int j);


/** Class example - Pet object (abstract). **/
class Pet
{
public:
   /** Default constructor. **/
   Pet();

   /** Overloaded constructor.
   * @param string to name pet.
   */
   Pet(const string &name);

   /** Sets name of pet.
   * @param string to name pet.
   */
   void setName(const string &name);

   /** Gets name of pet.
   * @return name string of pet.
   */
   const string getName();

   /** Make a sound. Pet is an abstract class so it makes no sound.
   */
   virtual string sound() = 0;

private:
   /** String of pet's name. **/
   string m_name;
};


/** For Python to properly call any virtual functions, we have to create a trampoline class. **/
class PyPet : public Pet
{
public:
   // Inheriting constructor.
   using Pet::Pet;

   // Only need a trampoline function for each virtual function.
   string sound() override
   {
      PYBIND11_OVERLOAD_PURE(string, Pet, sound);
   }
};


/** Inheritance example - Dog object that inherits Pet's public functions. **/
class Dog : public Pet
{
public:
   /** Default constructor. **/
   Dog();

   /** Overloaded constructor. Creates Pet object with same name.
   * @param string to name dog.
   */
   Dog(const string &name);

   /** Overridden sound function. Dogs bark.
   * @return string "woof!" to indicate dog barking.
   */
   string sound();
};


/** Inheritance example - Cat object that inherits Pet's public functions. **/
class Cat : public Pet
{
public:
   /** Default constructor. **/
   Cat();

   /** Overloaded constructor.
   * @param string to name cat.
   */
   Cat(const string &name);

   /** Overridden sound function. Cats meow.
   * @return string "meow!" to indicate cat meowing.
   */
   string sound();
};


/** Car class to hold Pet objects. **/
class Car
{
public:
   /** Default constructor. **/
   Car();

   /** Loads car with pets.
   * @param pointer to a Pet object.
   */
   void loadCar(Pet *pet);

   /** Prints out all pets' names in the car.
   */
   void dumpCar();

private:
   /** Vector of Pet pointers so we can put Cats and Dogs in the same structure. **/
   vector<Pet*> pets;
};

