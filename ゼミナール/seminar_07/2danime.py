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

#アニメーション化関数
def Animation(EorH,n,k,x,y):
    figre=plt.figure()
    frames=[]
    for i in range(0,n,2):
        frame=plt.plot(x,y[n-i-1][:-1],"blue")
        frames.append(frame)

    plt.xlim(0,k)
    plt.xlabel('t')
    plt.ylabel(EorH)
    plt.title('FDTD animation')
    anime=ArtistAnimation(figre,frames,interval=30)
    anime.save("FDTD_2d_ref_"+EorH+".gif",writer="pillow")
    plt.show()

#電界アニメーション表示
fileE='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1219\\E.csv'
n,k,x,y=File(fileE)
Animation('E',n,k,x,y)

#磁界アニメーション表示
fileH='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1219\\H.csv'
n,k,x,y=File(fileH)
Animation('H',n,k,x,y)