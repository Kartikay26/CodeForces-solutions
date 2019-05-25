import time
import random
from math import *
from collections import defaultdict
from itertools import *
import re

def solve(n):
    return bool(re.fullmatch("(1|14|144)*", n))

print("YES" if solve(input()) else "NO")