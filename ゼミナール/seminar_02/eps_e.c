#include<stdio.h>
#include<math.h>
#define e 2.718281828459045

int main(){
    FILE *fp;
    char *fname="seminar_03_e_d.csv";
    int i;
    double x[2048];
    double eps[2048];

//ネイピア数誤差データ生成
    fp=fopen(fname,"w");
    for(i=0;i<1100;i++){
        x[i]=pow(0.5,i);
        eps[i]=1-((exp(x[i])-1)/x[i]);
        fprintf(fp,"%.17e,%.17e\n",x[i],fabs(eps[i]));
    }
    fclose(fp);

    return 0;
}