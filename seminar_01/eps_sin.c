#include<stdio.h>
#include<math.h>
#define e 2.71828182
#define pi 3.141592653

int main(){
    FILE *fp;
    char *fname="semihw_1003_02_sin_d.csv";
    int i;
    double x[2048];
    double eps[2048];

//sin関数誤差データ生成
    fp=fopen(fname,"w");
    for(i=0;i<200;i++){
        x[i]=pow(0.5,i);
        eps[i]=1-sin(x[i])/x[i];
        fprintf(fp,"%.17e,%.17e\n",x[i],fabs(eps[i]));
    }
    fclose(fp);
    
    return 0;
}