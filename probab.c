#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    double cpg[4][4] = {
        {0.18, 0.27, 0.43, 0.12}, // řádek a (sloupce a, c, g, t)
        {0.17, 0.37, 0.27, 0.19}, // řádek c (sloupce a, c, g, t)
        {0.16, 0.34, 0.38, 0.12}, // řádek g (sloupce a, c, g, t)
        {0.08, 0.36, 0.38, 0.18}  // řádek t (sloupce a, c, g, t)
    };
    double null_model[4][4] = {
        {0.30, 0.21, 0.28, 0.21}, // řádek a (sloupce a, c, g, t)
        {0.32, 0.30, 0.08, 0.30}, // řádek c (sloupce a, c, g, t)
        {0.25, 0.24, 0.30, 0.21}, // řádek g (sloupce a, c, g, t)
        {0.18, 0.24, 0.29, 0.29}  // řádek t (sloupce a, c, g, t)
    };
    char bases[101] = {0};
    int bases_num[100] = {0};
    double values[99] = {0};
    double log_values[99] = {0};
    int len = 0;
    int radek = 0;
    int sloupec = 0;
    double result_cpg = 0;
    double result_null = 0;


    scanf("%100s", bases);
    len = strlen(bases);

    for(int i = 0;i<100;i++) {
        if(bases[i] == 'a') bases_num[i] = 0;
        if(bases[i] == 'c') bases_num[i] = 1;
        if(bases[i] == 'g') bases_num[i] = 2;
        if(bases[i] == 't') bases_num[i] = 3;
    }

    for (int i = 0; i < len - 1; i++) {
        radek = bases_num[i];
        sloupec = bases_num[i + 1];
        values[i] = cpg[radek][sloupec];
    }

    //for(int i = 0;i<(len-1);i++) printf("%f\n", values[i]);

    for(int i = 0;i<(len-1);i++) log_values[i] = 0 - log10(values[i]);

    for(int i = 0;i<(len-1);i++) result_cpg = result_cpg + log_values[i];

    printf("for  cpg: %.6f\n", result_cpg);

    for (int i = 0; i < len - 1; i++) {
        radek = bases_num[i];
        sloupec = bases_num[i + 1];
        values[i] = null_model[radek][sloupec];
    }

    for (int i = 0; i < 99; i++) {
        log_values[i] = 0.0;
    }

    for(int i = 0;i<(len-1);i++) log_values[i] = 0 - log10(values[i]);

    for(int i = 0;i<(len-1);i++) result_null = result_null + log_values[i];

    printf("for null: %.6f\n", result_null);

    if(result_cpg > result_null) printf("more likely from NULL\n");
    if(result_cpg < result_null) printf("more likely from CPG\n");
}
