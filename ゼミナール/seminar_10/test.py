import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as anm

#ファイル読み込み関数
def File(file):
    N=0
    f=open(file,'r')
    for line in f:
        if line=='\n':
            N=N+1
    f.close()
    data=pd.read_csv(file,header=None).values.tolist()
    data=np.array(data)
    I=len(data)/N
    J=len(data[0])-1

    return I,J,N,data

#アニメーション化関数
def Anime(J,N,X,Y,Ez,Hx,Hy):
    fig=plt.figure()
    ax=fig.add_subplot(projection='3d')
    frames=[]

    for n in range(0,N,1):
        frameEz=ax.plot_surface(X,Y,Ez[J*n:J*(n+1),:-1],cmap='jet',vmin=-0.25,vmax=0.25)
        #frameHx=ax.plot_surface(X,Y,Hx[J*n:J*(n+1),:-1],cmap='jet',vmin=-0.001,vmax=0.001)
        #frameHy=ax.plot_surface(X,Y,Hy[J*n:J*(n+1),:-1],cmap='jet',vmin=-0.001,vmax=0.001)
        frames.append([frameEz]) #なぜ[]が必要なのか調査

    ax.set_title('2dFDTD animation')
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
    anime=anm.ArtistAnimation(fig,frames,interval=30)
    #anime.save("2dFDTD_3d_thr.gif",writer="pillow")
    plt.show()

    return 0

def main():
    fileEz='C:\\Users\\soccc\\Desktop\\vs code\\seminar_10\\Ez.csv'
    fileHx='C:\\Users\\soccc\\Desktop\\vs code\\seminar_10\\Hx.csv'
    fileHy='C:\\Users\\soccc\\Desktop\\vs code\\seminar_10\\Hy.csv'

    I,J,N,Ez=File(fileEz)
    I,J,N,Hx=File(fileHx)
    I,J,N,Hy=File(fileHy)
    x=np.arange(0,I,1)
    y=np.arange(0,J,1)
    X,Y=np.meshgrid(x,y)

    Anime(J,N,X,Y,Ez,Hx,Hy)

    return 0

if __name__ == "__main__":
    main()