#include <stdio.h>
#include <math.h>

int main(void){
    //初期値設定
    #define N 60
    #define I 60
    #define pi 3.141592653589793238462643
    #define C1 1
    #define C2 0
    #define C3 -1

    //ファイル準備
    FILE *fp;
    char *fname = "seminar_1107_01.csv";

    //変数設定
    int i;
    int n;
    double f[N][I] = {0};

    //1行目初期値設定
    for(i=I/3;i<((2*I)/3);i++){
        f[0][i] = sin(((2*pi)/(I/3))*i);
    }

    //2行目初期値設定
    for(i=I/3;i<((2*I)/3);i++){
        f[1][i+1] = sin((((2*pi)/(I/3)))*i);
    }

    //計算エンジン
    for(n=2;n<N;n++){
        for(i=0;i<I;i++){
            if((i==0)||(i==(I-1))){
                f[n][i]=f[n-1][i];
            }
            else{
                f[n][i]=C1*f[n-1][i+1]+C2*f[n-1][i]+C1*f[n-1][i-1]+C3*f[n-2][i];
            }
        }
    }

    //ファイル出力
    fp = fopen( fname, "w");
    for(n=N-1;n>=0;n--){
        for(i=0;i<I;i++){
        fprintf( fp, "%lf,",f[n][i]);      
        }
    fprintf(fp, "\n");
    }
    fclose(fp);
    puts("書き出しが完了しました");

    return 0;
}