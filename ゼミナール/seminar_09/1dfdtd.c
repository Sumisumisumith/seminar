#include "1dfdtd.h"

//初期値設定
void Set(float E[N][K]){
    int k=0;
    for(k=(K/2-150);k<(K/2+150);k++){
        E[0][k]=0;
    }
}

//電磁界計算
void Cal(float E[N][K], float H[N][K]){
   int n=0,k=0;
   for(n=1;n<N;n++){
        //電界計算
        for(k=1;k<K-1;k++){
            E[n][k]=C1*E[n-1][k]+C2*H[n-1][k]+C3*H[n-1][k-1];
        }
        //波源
        E[n][K/2] = sin(w*n*dt);

        //透過
        E[n][0]=E[n-1][1]+((v*dt-dz)/(v*dt+dz))*(E[n][1]-E[n-1][0]);
        E[n][K-1]=E[n-1][K-2]+((v*dt-dz)/(v*dt+dz))*(E[n][K-2]-E[n-1][K-1]);
        
        //反射
        //E[n][0]=0;
        //E[n][K-1]=0;

        //磁界計算
        for(k=0;k<K-1;k++){
            H[n][k]=C4*H[n-1][k]+C5*E[n][k+1]+C6*E[n][k];
        }
    }
}

//ファイル出力
void File(float F[N][K],char *fname){
    FILE *fp;
    int n=0,k=0;

    fp=fopen(fname,"w");
    for(n=0;n<N;n++){
        for(k=0;k<K;k++){
            fprintf( fp, "%lf,",F[n][k]);      
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("%s exported\n",fname);
}

int main(void){
    float E[N][K]={0};
    float H[N][K]={0};

    Set(E);
    Cal(E,H);
    File(E,"E.csv");
    File(H,"H.csv");

    return 0;
}