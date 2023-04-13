import csv
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import ArtistAnimation

#ファイル読み込み
csvfile_E='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1205\\E.csv'
f=open(csvfile_E,encoding="utf-8")
cr=csv.reader(f)
y=list(cr)
f.close

n=len(y)
k=len(y[0])-1
x=np.arange(0,k)

for i in range(0,n):
    for j in range(0,k):
        y[i][j]=float(y[i][j])

#アニメーション化
fig=plt.figure()
ims=[]

for i in range(0,n,2):
    img=plt.plot(x,y[n-i-1][:-1],"blue")
    ims.append(img)

plt.xlabel('t')
plt.ylabel('E(z,t)')
plt.title('FDTD animation')
ani=ArtistAnimation(fig,ims,interval=10)
ani.save("FDTD.gif",writer="pillow")
plt.show()