#!/usr/bin/env python
# 

__version__ = "0.1.2"

def copyright():
    return "numpyext python module: Copyright (c) 2007-2018 Jiao Y Y Lin"


from . import numpyext as binding

def getdataptr(npyarr):
    '''extract data pointer from a numpy array and return a PyCObject'''
    return binding.getdataptr(npyarr)


def wrapdataptr(ptr, dtype, size):
    '''wrap a void pointer in the given PyCObject into  a numpy array
    dtype: type code or numpy dtype instance
    size: size of array
    '''
    if not isinstance(dtype, int):
        dtype = dtype.num
        pass
    return binding.wrapdataptr(ptr, dtype, size)
        

# version
__id__ = "$Id$"

#  End of file 
