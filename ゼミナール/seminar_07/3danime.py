import csv
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import ArtistAnimation

#ファイル読み込み関数
def File(file):
    f=open(file, encoding="utf-8")
    cr=csv.reader(f)
    EH=list(cr)
    f.close
    n=len(EH)
    k=len(EH[0])-1
    t=np.arange(0,k,1)
    for i in range(0,n):
        for j in range(0,k):
            EH[i][j]=float(EH[i][j])
    return n,k,t,EH

#電磁界アニメーション表示
fileE='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1219\\E.csv'
fileH='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1219\\H.csv'

En,Ek,Ez,Ey=File(fileE)
Hn,Hk,Hz,Hx=File(fileH)

fig=plt.figure()
ax=fig.add_subplot(projection='3d')
frames=[]
Ex=np.zeros(Ek)
Hy=np.zeros(Hk)
for i in range(0,En,2):
    frameE=ax.plot(Ex,Ey[En-i-1][:-1],Ez,"blue")
    frameH=ax.plot(Hx[Hn-i-1][:-1],Hy,Hz,"red")
    frames.append(frameE+frameH)

anime=ArtistAnimation(fig,frames,interval=30)
anime.save("FDTD_3d_ref.gif",writer="pillow")
ax.set_title('FDTD animation')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
plt.show()