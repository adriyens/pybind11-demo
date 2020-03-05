##
# @file
# Creates a module so that Python scripts can call C++ functions by just importing the module.
#

import os
import sys

from distutils.core import setup, Extension
from distutils import sysconfig

cpp_args = ['-std=c++11', '-stdlib=libc++', '-mmacosx-version-min=10.7']

sfc_module = Extension(
    'demo',
    sources = ['demo.cpp', 'wrapper.cpp'],
    include_dirs=['pybind11/include', 'include'],
    language='c++',
    extra_compile_args = cpp_args,
    )

setup(
    name = 'demo',
    version = '1.0',
    description = 'An example project using pybind11.',
    ext_modules = [sfc_module],
)