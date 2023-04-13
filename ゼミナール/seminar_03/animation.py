#各モジュールをインポート
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import ArtistAnimation

#グラフ形式作成
fig=plt.figure()

#x方向の配列設定
x=np.arange(0,10,0.1)

#静止画グラフを格納する配列を用意
ims=[]

#グラフ作成
for i in range(100):
    y=np.sin(x-i)
    img=plt.plot(x,y,"b")
    ims.append(img)

#アニメーション化
ani=ArtistAnimation(fig,ims)

#アニメーション表示
plt.show()