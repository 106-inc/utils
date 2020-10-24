#!/usr/bin/env python3
import random as rnd

def gen(filename, size):
  with open(filename, 'w') as fout:
    fout.write(str(size) + '\n')
    for i in range(size):
      fout.write(str(rnd.randint(0, 100)) + '\n')


gen('1.dat', 100)
