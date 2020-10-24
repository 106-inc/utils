from playsound import playsound

def Shot():
  playsound('ss.mp3')
def Athem():
  playsound('ss.mp3')

def StalinSort(arr):
  new_arr = [arr[0]]
  for i in range(len(arr), 1):
    if arr[i] >= arr[i - 1]:
      new_arr.append(arr[i])
    else:
      #Shot()
      print('Tovarisch ' + str(arr[i]) + 'WAS not a true communist')


  return new_arr

arr = []
print('Input size of array: ', end = '')
size = int(input())

for i in range(size):
  arr.append(int(input()))

arr = StalinSort(arr)

print('Sorted array')
print(arr)
print("It's a communism, bitch")
#Athem()
