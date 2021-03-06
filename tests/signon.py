#!/usr/bin/env python
from __future__ import print_function

from danse.ins import numpyext
from danse.ins.numpyext import numpyext as numpyextmodule
from numpy import array, arange


def test0():
    print(numpyext)
    print("copyright information:")
    print("   ", numpyext.copyright())
    print("   ", numpyextmodule.copyright())

    print()
    print("module information:")
    print("    file:", numpyextmodule.__file__)
    print("    doc:", numpyextmodule.__doc__)
    print("    contents:", dir(numpyextmodule))

    print()
    print(numpyextmodule.hello())
    return


def testprintdblarray():
    a = arange(1, 10, 1.0)
    numpyextmodule.printdblarray(a)
    return


def testprintdblarray2():
    a = arange(1, 10, 1.0)
    ptr = numpyextmodule.getdataptr(a)
    size = len(a)
    del a
    numpyextmodule.printdblarray2(ptr, size)
    return


def testwrapptr():
    a = arange(1, 10, 1.0)
    ptr = numpyextmodule.getdataptr(a)
    b = numpyextmodule.wrapdataptr(ptr, a.dtype.num, len(a))
    a[4] = 999
    assert a[4] == b[4]
    return
    


def main():
    test0()
    testprintdblarray()
    testprintdblarray2()
    testwrapptr()
    return


if __name__ == "__main__": main()


# version
__id__ = "$Id$"

#  End of file 
