#!/usr/bin/env python
from __future__ import print_function

import numpy as np, time
from danse.ins.numpyext import numpyext as ne

def test():
    for i in range(200):
        a = np.zeros(int(5e8))
        t = ne.getdataptr(a)
        if (i%10==0): print(a.shape, t)
        time.sleep(.1)
    return

if __name__ == '__main__': test()
