#csvモジュールをインポート
import csv

#ファイルのパス名
csvfile='C:\\Users\\soccc\\Desktop\\vs code\\seminar_1107\\seminar_1107_01.csv'

with open(csvfile) as f:
     print(f.read())

#ファイルを開く
f=open(csvfile,encoding="utf-8")

#readerオブジェクトの用意
cr=csv.reader(f)

#ファイルのデータをdataに各行リストで格納
data=list(cr)

#ファイルを閉じる
f.close

#dataに格納されている値を数値化
for i in range(0,60):
    for j in range(0,60):
        data[i][j]=float(data[i][j])