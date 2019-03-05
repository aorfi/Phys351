# -*- coding: utf-8 -*-
"""
Created on Fri Jan 18 11:01:27 2019

@author: aorfi
"""

import spinmob as s
import matplotlib.pyplot as plt
import numpy as np


d = s.data.load(filters="*.dat")

plt.plot(d[5],d[6],'b')
plt.xlabel("x1")
#plt.ylim(40, 43)
plt.ylabel("y1")
plt.title("x1 vs y1")
#plt.gca().legend(('Column 1', 'Column 2' ))
plt.show