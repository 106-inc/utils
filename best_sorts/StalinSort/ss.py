#!/usr/bin/env python3
from playsound import playsound


def Shot():
    playsound('snd/boom.mp3')


def Athem():
    playsound('snd/ss.mp3')


def Tired():
    playsound('snd/tired_stalin.mp3')
    print('Oh, it was so much work..')


def KillPrint(kill_lst):
    print("Missing:")
    print(kill_lst)
    '''
    for elem in kill_lst:
        print(elem + ' ', end='')
    '''
    # print()
      

def StalinSort(arr):
    new_arr = [arr[0]]
    greatest = arr[0]
    kill_lst = []
    kills = 0
    is_tired = 0
    for i in range(1, len(arr)):
        if arr[i] < greatest:
            if is_tired:
                kill_lst.append(arr[i])
            else:
                print('Tovarisch ' + arr[i] + ' WAS not a true communist')
                Shot()
                kills += 1
                if kills > 3:
                    Tired()
                    is_tired = 1
        else:
            new_arr.append(arr[i])
            greatest = arr[i]

    KillPrint(kill_lst)
    return new_arr


arr = []
print('Input size of array:')
size = int(input())

for j in range(size):
    arr.append(input())

arr = StalinSort(arr)

print('True communist list:')
print(arr)
print("It's a communism, bitch")
Athem()
