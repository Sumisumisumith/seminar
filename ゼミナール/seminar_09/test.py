import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as anm

#ファイル読み込み関数
def File(file):
    EH = pd.read_csv(file, header=None).values.tolist()
    n=len(EH)
    k=len(EH[0])-1
    t=np.arange(0,k,1)    
    return n,k,t,EH

#アニメーション化関数
def Animation(EH,n,k,x,y):
    fig=plt.figure()
    frames=[]
    for i in range(0,n,2):
        frame=plt.plot(x[0:k],y[i-1][0:k],"blue")
        frames.append(frame)

    plt.xlim(0,k)
    plt.xlabel('t')
    plt.ylabel(EH)
    plt.title('FDTD animation')
    anime=anm.ArtistAnimation(fig,frames,interval=50)
    #anime.save("1dFDTD_2d_thr_"+EH+".gif",writer="pillow")
    plt.show()

#電界アニメーション表示
fileE='C:\\Users\\soccc\\Desktop\\vs code\\seminar_09\\E.csv'
n,k,x,y=File(fileE)
Animation('E',n,k,x,y)

#磁界アニメーション表示
fileH='C:\\Users\\soccc\\Desktop\\vs code\\seminar_09\\H.csv'
n,k,x,y=File(fileH)
Animation('H',n,k-1,x,y)