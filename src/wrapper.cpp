/**
* @file
* Wrapper for C++ functions so that Python scripts are able to call them.
*/

/* Getting our class and function declarations to wrap. */
#include "demo.h"

/** pybind11 macro that binds C++ code into a module so that these classes and functions can be called in Python.
* @param name of module (shouldn't be in quotes).
* @param variable of type py::module which is the main interface for creating bindings.
*/
PYBIND11_MODULE(demo, m)
{
   /** Basic function binding.
   * @param name of function in quotes.
   * @param address of function.
   */
   m.def("add", &add);

   /** Pet class binding. Takes in trampoline class to indicate virtual function.
   * @param variable of type py::module which is the main interface for creating bindings.
   * @param name of class in quotes.
   */
   py::class_<Pet, PyPet>(m, "Pet")
      // Default ctor.
      .def(py::init<>())
      // Overloaded ctor.
      .def(py::init<const string&>())
      .def("setName", &Pet::setName)
      .def("getName", &Pet::getName)
      // Pure virtual sound function.
      .def("sound", &Pet::sound);

   /** Dog class binding. Takes in Pet class.
   * @param variable of type py::module which is the main interface for creating bindings.
   * @param name of class in quotes.
   */
   py::class_<Dog, Pet>(m, "Dog")
      // Default ctor.
      .def(py::init<>())
      // Overloaded ctor.
      .def(py::init<const string &>())
      // Overridden sound function.
      .def("sound", &Dog::sound);

   /** Cat class binding. Takes in Pet class.
   * @param variable of type py::module which is the main interface for creating bindings.
   * @param name of class in quotes.
   */
   py::class_<Cat, Pet>(m, "Cat")
      // Default ctor.
      .def(py::init<>())
      // Overloaded ctor.
      .def(py::init<const string &>())
      // Overridden sound function.
      .def("sound", &Cat::sound);

   /** Car class binding. Is a standalone class so it doesn't need any other template parameters.
   * @param variable of type py::module which is the main interface for creating bindings.
   * @param name of class in quotes.
   */
   py::class_<Car>(m, "Car")
      .def(py::init<>())
      .def("loadCar", &Car::loadCar)
      .def("dumpCar", &Car::dumpCar);
}
