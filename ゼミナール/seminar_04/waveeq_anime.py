import csv
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import ArtistAnimation

#ファイル読み込み
csvfile='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1114\\seminar_1114_01.csv'
f=open(csvfile,encoding="utf-8")
cr=csv.reader(f)
y=list(cr)
f.close

for i in range(0,len(y)):
    for j in range(0,len(y)):
        y[i][j]=float(y[i][j])

#アニメーション化
fig=plt.figure()
x=np.arange(0,len(y),1)
ims=[]

for n in range(0,len(y)):
    img=plt.plot(x,y[len(y)-n-1][:-1],"blue")
    ims.append(img)

plt.xlim(0,len(y))
plt.ylim(-2,2)
plt.xlabel('i')
plt.ylabel('f(n,i)')
plt.title('wave.eq animation')
ani=ArtistAnimation(fig,ims,interval=100)
ani.save("wave_eq.gif",writer="pillow")
plt.show()