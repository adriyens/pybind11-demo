##
# @file
# Python script that calls C++ classes and functions from demo module.
#

# Import module created.
import demo

# Calling basic function.
print("1 + 2 = " + str(demo.add(1, 2)))
print("5 + 6 = " + str(demo.add(5, 6)))
print("")

# Creating Dog class that inherits Pet properties.
d = demo.Dog("Molly")

# Calling Pet functions on Dog object.
print("My dog's name is " + d.getName())
d.setName("Charlie")
print("My dog's name is now " + d.getName())

# Calling overridden sound function.
print("My dog goes " + d.sound())
print("")

# Creating Cat class that inherits Pet properties.
c = demo.Cat("Tom")

# Calling Pet functions on Cat object.
print("My cat's name is " + c.getName())
c.setName("Jerry")
print("My cat's name is now " + c.getName())

# Calling overridden sound function.
print("My cat goes " + c.sound())
print("")

# Creating a car to put all the pets in.
s = demo.Car()

s.loadCar(d)
s.loadCar(c)
 
print("The following animals are in the car:")
s.dumpCar()