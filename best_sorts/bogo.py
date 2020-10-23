import random

def bogo_sort(data):
    with open('out.txt', 'w') as file:
        while any(x > y for x, y in zip(data, data[1:])):
            file.write(str(data) + '\n')
            random.shuffle(data)

arr = [1, 3, 5, 2, 6, 7, 9, 10, 85, 46, 73, 93, 49]

bogo_sort(arr)

print(arr)




