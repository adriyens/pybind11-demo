##
# @file
# Creates a module so that Python scripts can call C++ functions by just importing the module.
#

import os
import sys

from distutils.core import setup, Extension
from distutils import sysconfig

cpp_args = ['-std=c++11', '-stdlib=libc++', '-mmacosx-version-min=10.7']

demo_module = Extension(
    'demo',
    # Only need to include class implementations in sources (no need for header file)
    sources=['src/demo.cpp', 'src/wrapper.cpp'],
    include_dirs=['pybind11/include', 'include'],
    language='c++',
    extra_compile_args = cpp_args,
    )

setup(
    name='demo',
    version='1.0',
    url='https://github.com/adriyens/pybind11-demo',
    author='Adrianne Santinor',
    author_email='adrianne.santinor@gmail.com',
    description='An example module using pybind11.',
    ext_modules = [demo_module],
    install_requires=['pybind11>=2.4'],
    setup_requires=['pybind11>=2.4'],
)
