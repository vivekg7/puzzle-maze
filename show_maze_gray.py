import cv2
import numpy as np
import pyautogui as pyg

# screen resolution
width, height = pyg.size()

# dimensions of input
n = int(input())
m = int(input())

# size of one block
size = min(width // m, (int(height*0.9)) // n)

# set thickness according to input
if max(m, n) > 40:
    t = 1
else:
    t = 2

# define array
arr = []

# get array from standard input
for _ in range(n):
    arr.append(list(map(int, input().rstrip().split())))

# define a blank image
img = np.zeros(((n+1)*size, (m+1)*size), np.uint8)

# white image
img += 255

# draw lines according to input
for i in range(m-1):
    for j in range(n-1):
        # cv2.circle(img,(size * (i+1), size * (j + 1)), 3, 200, -1)
        if arr[j][i]==1:
            cv2.line(img, (size*(i+1), size*(j+1)), (size*(i+2), size*(j+1)), 0, t)
        if arr[j][i]==2:
            cv2.line(img, (size*(i+1), size*(j+1)), (size*(i+1), size*(j+2)), 0, t)
        if arr[j][i]==3:
            cv2.line(img, (size*(i+1), size*(j+1)), (size*(i+1), size*(j+2)), 0, t)
            cv2.line(img, (size*(i+1), size*(j+1)), (size*(i+2), size*(j+1)), 0, t)
cv2.line(img, (size*m, size), (size*m, size*(n-1)), 0, t)
cv2.line(img, (size, size*n), (size*m, size*n), 0, t)

# show output image on output screen
cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
