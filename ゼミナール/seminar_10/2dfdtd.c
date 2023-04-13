#include "2dfdtd.h"

//初期値設定
void Set(float Ez[I][J][N]){
    int i=0,j=0;
    for(i=I/2-150;i<(I/2+150);j++){
        for(j=J/2-150;j<(J/2+150);j++){
            Ez[i][j][0]=0;
        }
    }
}

//2dFDTD法
void Cal(float Ez[I][J][N], float Hx[I][J][N], float Hy[I][J][N]){
   int i=0,j=0,n=0;
   for(n=1;n<N;n++){
        //電界計算
        for(i=1;i<I-1;i++){
            for(j=1;j<J-1;j++){
                Ez[i][j][n]=C1*Hy[i][j][n-1]+C2*Hy[i-1][j][n-1]+C3*Hx[i][j][n-1]+C4*Hx[i][j-1][n-1]+C5*Ez[i][j][n-1];
            }
        }
        //波源
        Ez[I/2][J/2][n]=sin(w*n*dt);

        //透過
        for(i=0;i<I;i++){
            Ez[i][0][n]=Ez[i][1][n-1]+((v*dt-dx)/(v*dt+dx))*(Ez[i][1][n]-Ez[i][0][n-1]);
            Ez[i][J-1][n]=Ez[i][J-2][n-1]+((v*dt-dx)/(v*dt+dx))*(Ez[i][J-2][n]-Ez[i][J-1][n-1]);
        }
        for(j=0;j<J;j++){
            Ez[0][j][n]=Ez[1][j][n-1]+((v*dt-dy)/(v*dt+dy))*(Ez[1][j][n]-Ez[0][j][n-1]);
            Ez[I-1][j][n]=Ez[I-2][j][n-1]+((v*dt-dy)/(v*dt+dy))*(Ez[I-2][j][n]-Ez[I-1][j][n-1]);
        }

        //反射
        /*for(i=0;i<I;i++){
            Ez[i][0][n]=0;
            Ez[i][J-1][n]=0;
        }
        for(j=0;j<J;j++){
            Ez[0][j][n]=0;
            Ez[I-1][j][n]=0;
        }*/

        //磁界計算
        for(i=0;i<I-1;i++){
            for(j=0;j<J-1;j++){
                Hx[i][j][n]=C6*Ez[i][j+1][n]+C7*Ez[i][j][n]+C8*Hx[i][j][n-1];
                Hy[i][j][n]=C9*Ez[i+1][j][n]+C10*Ez[i][j][n]+C11*Hy[i][j][n-1];
            }
        }
    }
}

//ファイル出力
void File(float F[I][J][N],char *fname){
    FILE *fp;
    int i=0,j=0,n=0;

    fp = fopen( fname, "w");
    for(n=0;n<N;n++){
        for(i=0;i<I;i++){
            for(j=0;j<J;j++){
                fprintf( fp, "%lf,",F[i][j][n]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n"); //nごとに改行
    }
    fclose(fp);
    printf("%s exported\n",fname);
}

int main(void){
    float Ez[I][J][N]={0};
    float Hx[I][J][N]={0};
    float Hy[I][J][N]={0};

    //Set(Ez);
    Cal(Ez,Hx,Hy);
    File(Ez,"Ez.csv");
    File(Hx,"Hx.csv");
    File(Hy,"Hy.csv");

    return 0;
}