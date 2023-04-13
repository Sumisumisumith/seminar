#include<stdio.h>
#include<math.h>
#define PI 3.141592653
int main(){
    FILE *fp;
    char *fname="semihw_1003_01.csv";
    int i;
    double x[256],y[256];

//ファイル処理
    fp=fopen(fname,"w");
    if(fp==NULL){
        printf("%sファイルが開けません/n",fname);
        return -1;
    }

//データ作成
    for(i=0;i<100;i++){
        x[i]=(PI/50)*i;
        y[i]=sin((PI/50)*i);
        fprintf(fp,"%lf,%lf\n",x[i],y[i]);
    }

    fclose(fp);
    return 0;
}

