#!/usr/bin/env python3
import random

def bogo_sort(data):
    with open('out.txt', 'w') as file:
        while any(x > y for x, y in zip(data, data[1:])):
            file.write(str(data) + '\n')
            random.shuffle(data)

print('Input array size: ', end='')
N = int(input())

arr = []
for i in range(N):
    tmp = input()
    arr.append(int(tmp))

bogo_sort(arr)
print(arr)


