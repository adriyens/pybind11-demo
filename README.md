# pybind11-demo
Simple demo of a C++ extension for Python using [pybind11](https://github.com/pybind/pybind11).

This demo has examples of a basic function, add(), that returns the sum of two ints together. It also includes an example of polymorphism using an abstract Pet class and its derived classes, Dog and Cat.

## Dependencies
- Python 3.x
- [pybind11](https://github.com/pybind/pybind11)
- **For Windows:** Visual Studio 2014+ with C++ Redistributable Packages

## Installation
- clone this repo
- `pip install ./pybind11-demo`

## Test call
Run the script: `py ./pybind11-demo/script.py`

Or use it directly in a Python shell.

```
>>> import demo
>>> demo.add(1, 2)
3
>>> d = demo.Dog("Daniel")
>>> d.getName()
'Daniel'
>>> d.sound()
'woof!'
>>> c = demo.Cat("Adrianne")
>>> c.getName()
'Adrianne'
>>> c.sound()
'meow!'
```
