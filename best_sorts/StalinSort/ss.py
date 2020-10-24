#!/usr/bin/env python3
from playsound import playsound


def Shot():
    playsound('snd/boom.mp3')


def Athem():
    playsound('snd/ss.mp3')


def StalinSort(arr):
    new_arr = [arr[0]]
    greatest = arr[0]
    for i in range(1, len(arr)):
        if arr[i] < greatest:
            print('Tovarisch ' + arr[i] + ' WAS not a true communist')
            Shot()
        else:
            new_arr.append(arr[i])
            greatest = arr[i]

    return new_arr


arr = []
print('Input size of array:')
size = int(input())

for j in range(size):
    arr.append(input())

arr = StalinSort(arr)

print('Sorted array')
print(arr)
print("It's a communism, bitch")
Athem()
