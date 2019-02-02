# -*- coding: utf-8 -*-
"""
Created on Fri Jan 18 11:01:27 2019

@author: aorfi
"""

import spinmob as s
import matplotlib.pyplot as plt
import numpy as np


d = s.data.load(filters="*.dat")
plt.plot(d[1],d[2],'b')
plt.xlabel("Position (x)")
plt.ylabel("Momentum (p)")
plt.title("Orfi CA2 Leap Frog 2")
#plt.gca().legend(('Column 1', 'Column 2' ))
plt.show