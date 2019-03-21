# -*- coding: utf-8 -*-
"""
Created on Fri Jan 18 11:01:27 2019

@author: aorfi
"""

import spinmob as s
import matplotlib.pyplot as plt
import numpy as np


d = s.data.load(filters="*.dat")

plt.plot(d[0],d[1],'b')
plt.xlabel("x")
#plt.ylim(40, 43)
plt.ylabel("y")
plt.gca().set_aspect('equal', adjustable='box')
plt.title("Kepler Orbit")
#plt.gca().legend(('Column 1', 'Column 2' ))
plt.show