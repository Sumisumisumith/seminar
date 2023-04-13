#include "fdtd.h"

//初期値設定
void Set(float F[N][K]){
    int k=0;

    for(k=(K/2-150);k<(K/2+150);k++){
        F[0][k] = sinf(2*pi*5*k/300);
    }
}

//波動計算
void Cal(float E[N/2][K], float H[N/2][K],float F[N][K]){
   int n=0,k=0;

   for(n=2;n<N;n+=2){
        for(k=1;k<K-1;k++){
            F[n][k]=C1*F[n-2][k]+C2*F[n-1][k]+C3*F[n-1][k-1];
        }
        F[n][0]=0;
        F[n][K-1]=0;
        for(k=0;k<K-1;k++){
            F[n+1][k]=C4*F[n-1][k]+C5*F[n][k+1]+C6*F[n][k];
        }
    }
    //配列fを電場、磁場にわける
    for(n=0;n<N/2;n++){
        for(k=0;k<K;k++){
            E[n][k]=F[2*n][k];
            H[n][k]=F[2*n+1][k];
        }
    }
}

//ファイル出力
void File(float F[N][K],char *fname){
    FILE *fp;
    int n=0,k=0;

    fp = fopen( fname, "w");
    for(n=N/2-1;n>=0;n--){
        for(k=0;k<K;k++){
        fprintf( fp, "%lf,",F[n][k]);      
        }
    fprintf(fp, "\n");
    }
    fclose(fp);
    puts("書き出しが完了しました");
}

int main(void){
    float E[N/2][K]={0},H[N/2][K]={0},F[N][K]={0};

    Set(F);
    Cal(E,H,F);
    File(E,"E.csv");

    return 0;
}