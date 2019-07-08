import cv2
import numpy as np

n = int(input())
m = int(input())

size = 50

arr = []

for _ in range(n):
    arr.append(list(map(int, input().rstrip().split())))

img = np.zeros(((n+1)*size, (m+1)*size), np.uint8)

for i in range(m-1):
    for j in range(n-1):
        #cv2.circle(img,(size * (i+1), size * (j + 1)), 3, (200), -1)
        if arr[j][i]==1:
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+2), size*(j+1)),(255),1)
        if arr[j][i]==2:
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+1), size*(j+2)),(255),1)
        if arr[j][i]==3:
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+1), size*(j+2)),(255),1)
            cv2.line(img,(size*(i+1), size*(j+1)),(size*(i+2), size*(j+1)),(255),1)
cv2.line(img, (size*m, size), (size*m, size*(n-1)), 255, 1)
cv2.line(img, (size, size*n), (size*m, size*n), 255, 1)
cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()

