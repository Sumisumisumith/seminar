#include "waveeq.h"

//初期値設定
/*
void Set(double f[N][I]){
    int i=0;
    srand((unsigned int) time(NULL));

    for(i=I/3;i<((2*I)/3);i++){
        f[0][i] = (double)rand()/RAND_MAX;
    }

    for(i=I/3;i<((2*I)/3);i++){
        f[1][i+1] = f[0][i];
    } 
}
*/

void Set(double f[N][I]){
    int i=0;

    for(i=I/3;i<((2*I)/3);i++){
        f[0][i] = sin(((2*pi)/(I/3))*i);
    }

    for(i=I/3;i<((2*I)/3);i++){
        f[1][i-1] = f[0][i];
    } 
}

//波動計算
void Cal(double f[N][I]){
   int i=0,n=0;

   for(n=2;n<N;n++){
        for(i=1;i<I-1;i++){
            f[n][i]=C*f[n-1][i+1]+(1-C)*f[n-1][i]+C*f[n-1][i-1]-f[n-2][i];
        }
        f[n][0]=f[n-1][1];
        f[n][I-1]=f[n-1][I-2];
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
    printf("%s exported",fname);
}

int main(void){
    double f[N][I]={0};

    Set(f);
    Cal(f);
    File(f,"wave_eq.csv");

    return 0;
}