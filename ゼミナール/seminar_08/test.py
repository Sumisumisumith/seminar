import csv
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import ArtistAnimation

#ファイル読み込み関数
def File(file):
    f=open(file)
    EH=[]
    for i in f.readline():
        EH[i]=f.readline()
    f.close()
    n=len(EH)
    k=len(EH[0])-1
    t=np.arange(0,k,1)
    return n,k,t,EH


fileE='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1226\\E.csv'
n,k,x,y=File(fileE)
print(k)