import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as anm

#ファイル読み込み関数
def File(file):
    data=pd.read_csv(file, header=None).values.tolist()
    N=len(data)
    K=len(data[0])-1
    z=np.arange(0,K,1)    
    return N,K,z,data

#アニメーション化関数
def Anime(N,Ex,Ey,Ez,Hx,Hy,Hz):
    fig=plt.figure()
    ax=fig.add_subplot(projection='3d')
    frames=[]
    for n in range(0,N,1):
        frameE=ax.plot(Ex,Ey[n-1][:-1],Ez,"blue")
        frameH=ax.plot(Hx[n][:-2],Hy[:-1],Hz[:-1],"red")
        frames.append(frameE+frameH)

    ax.set_title('1dFDTD animation')
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
    anime=anm.ArtistAnimation(fig,frames,interval=30)
    anime.save("1dFDTD_3d_thr.gif",writer="pillow")
    plt.show()

    return 0

def main():
    fileE='C:\\Users\\soccc\\Desktop\\vs code\\seminar_09\\E.csv'
    fileH='C:\\Users\\soccc\\Desktop\\vs code\\seminar_09\\H.csv'

    N,K,Ez,Ey=File(fileE)
    N,K,Hz,Hx=File(fileH)
    Ex=np.zeros(K)
    Hy=np.zeros(K)

    Anime(N,Ex,Ey,Ez,Hx,Hy,Hz)

if __name__ == "__main__":
    main()