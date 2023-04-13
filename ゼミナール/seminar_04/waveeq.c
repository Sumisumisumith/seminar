#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.141592653589793238462643
#define N 60
#define I 60
#define C 1

//1,2行初期値設定
void Set(double f[N][I]){
    int i=0;

    for(i=I/3;i<((2*I)/3);i++){
        f[0][i] = 1;
    }

    for(i=I/3;i<((2*I)/3);i++){
        f[1][i+1] = f[0][i];
    } 
}

//波動計算
void Cal(double f[N][I]){
   int i=0,n=0;

   for(n=2;n<N;n++){
        for(i=0;i<I;i++){
            if((i==0)){
                f[n][i]=f[n-1][2];
            }
            else if(i==I){
                f[n][i]=f[n-1][I-1];
            }
            else{
                f[n][i]=C*f[n-1][i+1]+(1-C)*f[n-1][i]+C*f[n-1][i-1]-f[n-2][i];
            }
        }
    }
}

//ファイル出力
void File(double f[N][I],char *fname){
    FILE *fp;
    int n=0,i=0;

    fp = fopen( fname, "w");
    for(n=N-1;n>=0;n--){
        for(i=0;i<I;i++){
        fprintf( fp, "%lf,",f[n][i]);      
        }
    fprintf(fp, "\n");
    }
    fclose(fp);
    puts("書き出しが完了しました");
}

int main(void){
    double f[N][I]={0};

    Set(f);
    Cal(f);
    File(f,"seminar_1114_01.csv");

    return 0;
}