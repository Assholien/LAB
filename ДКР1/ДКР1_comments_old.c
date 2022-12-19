#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
//#include <string.h>

int main()
{
    //char continue_char[100] = "y";
    unsigned int continue_value = 1;
    while(continue_value==1)
    //while(strcasecmp(continue_char,"n")!=0)
        {
        int N=1;
        double sum=0, a=0, value_too_high=1;//, checksum=0;
        do
        {
            do
            {
                printf("Enter N\t");
                scanf("%d", &N);
            } while(N<1); //&& N<0); //wanted to make it work with unsigned int. Oh, well...
            printf("Enter a\t");
            scanf("%lf", &a);
            //a = 10000000000000000000;
            //a = 10000000000000000000;
            //a = 100000000000000000000;
            //N = 9, a = 100; // - Safe values
            //N = 1;
            //a = 1e+308;
            value_too_high=1;
            for(int i=0; i<N; i++) value_too_high*=a;
            //printf("\t%d\t%g", N, a);
            //printf("%g", value_too_high);
            if (value_too_high>1e+308) printf("Sorry, this combination is just too much to handle. Try again?\n");
        } while(value_too_high>1e+308);
        for(int n=1; n<=N; n++)
        {
            double temp_sum=0;//, checksum_temp=0;
            int first=1, n_temp = n-1; // first is (-1)^(n-1), n_temp is n-1
            if (n_temp!=0) first = (n_temp%2==0 ? 1:-1); // -1^0 = 1 || -1^1 = -1
            double div = (double) a + first * n; //div is a+ (-1)^(n-1)*n. Made to double-check for all zero values and exclude them.
            //printf("div=%lf\t", div);
            double temp_a=1;
            for (int i=0; i<n; i++) temp_a*=a; // this is suppose to be a^n, but if I set N to 100 and a to 100 it's mismatched between test_a...
            //printf("temp_a=%g", temp_a);
            if(div!=0) temp_sum = (double) first * temp_a / div;
            sum+=temp_sum;
            //double div2 = (double) a + pow (-1, n - 1) * n;
            //printf("div2=%g\t", div2);
            //if(div2!=0) checksum_temp = (double) pow (-1,n-1) * pow (a, n) / div2;
            //checksum+=checksum_temp;
            //double temp_a_test = pow(a,n); //wanted to double-check my a^n sollution with this.
            //printf("\n\niteration - %d\ntemp_a\n%g\ntemp_a_test\n%g\ntemp_sum\n%g\nchecksum_temp\n%g\nsum\n%g\nchecksum\n%g", n, temp_a, temp_a_test, temp_sum, checksum_temp, sum, checksum);
            //printf("\n\niteration - %d\ntemp_a\n%g\ntemp_sum\n%g\nsum\n%g\n", n, temp_a, temp_sum, sum);
        }
        sum++;//, checksum++;
        //printf("\n\tsum\n\t\t%g\n\tchecksum\n\t\t%g\n", sum, checksum);
        printf("\n\tsum\n\t\t%g\n", sum);
        //printf("\n\tsum\n\t\t%lf\n", sum);
        do
        {
            printf("\t\nAnother go?\n\t\t\t1 - Yes/2 - No\t");
            //scanf("%s", continue_char);
            scanf("%u", &continue_value);
        } while(continue_value !=1 && continue_value !=2);//while(strcasecmp(continue_char,"y")!=0 && strcasecmp(continue_char,"n")!=0);
    }
    return 0;
}
