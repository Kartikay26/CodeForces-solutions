import time
import random
from math import *
from collections import defaultdict
from itertools import *
import re

def solve(n):
    n = int(n)
    return n//2 if n%2==0 else -n//2

print(solve(input()))