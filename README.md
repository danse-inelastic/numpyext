[![Build Status](https://travis-ci.com/danse-inelastic/numpyext.svg?branch=master)](https://travis-ci.com/danse-inelastic/numpyext)

This package provides tools to make use numpy arrays in c++ and c.

# Iterator1D template 
Iterator1D generates iterators of numpy array so that you can use it in c++
just as it is 1D iterator.

see pyext/Iterator1D_Example.cc and tests/signon.py for an example.

# getdataptr
getdataptr creates PyCObject of void pointer pointing to the start of the
data array held in a numpy array.

To manipulate the pointer, you must be sure that you know its layout 
(contiguous or not), and know what you are doing with it.

see pyext/getdataptr.cc and tests/signon.py for an example.


# wrapdataptr
wrapdataptr wrap a void * pointer to be a numpy array. The returned
numpy array shares memory with the original data pointer. So be
careful to keep a reference to the original python object where the
void * pointer is derived from.

See pyext/wrapdataptr.cc and tests/signon.py for an example.
