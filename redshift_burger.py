###################
# redshift burger #
###################
# simple tool for finding equally spaced arrays
# to give to the montepython 

# e.g.: python redshift_burger -3.0, -4.5, 10 will print
# 10 numbers equally spaced (lin) between -3, -4.5, or
#-3.00, -3.22, -3.44, -3.67, -3.89, -4.11, -4.33, -4.56, -4.78, -5.00

import sys
import numpy as np

if len(sys.argv) != 2:
    print("Usage: python redshift_burger.py start,end,N")
    sys.exit(1)

try:
    start_str, end_str, N_str = sys.argv[1].split(',')
    start, end, N = float(start_str), float(end_str), int(N_str)
except ValueError:
    print("Error: input must be in the format start,end,N (e.g. -3,-4.5,4)")
    sys.exit(1)

vals = np.linspace(start, end, N)
print(", ".join([f"{v:.2f}" for v in vals]))

