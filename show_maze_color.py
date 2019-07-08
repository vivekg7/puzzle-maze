import cv2
import numpy as np
from random import randint as rn
import pyautogui as pyg

# screen resolution
width, height = pyg.size()

# dimensions of input
n = int(input())
m = int(input())

# size of one block
size = min(width // m, int(height*0.9) // n)

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
img = np.zeros(((n+1)*size, (m+1)*size, 3), np.uint8)

# draw lines according to input
for i in range(m-1):
    for j in range(n-1):
        # cv2.circle(img,(size * (i+1), size * (j + 1)), 3, (200), -1)
        if arr[j][i]==1:
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+2), size*(j+1)),(rn(50,230),rn(50,230),rn(50,230)),t)
        if arr[j][i]==2:
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+1), size*(j+2)),(rn(50,230),rn(50,230),rn(50,230)),t)
        if arr[j][i]==3:
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+1), size*(j+2)),(rn(50,230),rn(50,230),rn(50,230)),t)
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+2), size*(j+1)),(rn(50,230),rn(50,230),rn(50,230)),t)
cv2.line(img, (size*m, size), (size*m, size*(n-1)), (rn(50,230), rn(50,230),rn(50,230)), t)
cv2.line(img, (size, size*n), (size*m, size*n), (rn(50,230), rn(50,230),rn(50,230)), t)

# show output image on output screen
cv2.imshow('maze', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
