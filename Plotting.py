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
plt.xlabel("q[1]")
#plt.ylim(40, 43)
plt.ylabel("q[2]")
plt.title("q[1] vs q[2]")
#plt.gca().legend(('Column 1', 'Column 2' ))
plt.show