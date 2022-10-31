#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double num_comput_integral_l_re(double left_boundary_a, double right_boundary_b, unsigned int intervals);
double num_comput_integral_r_re(double left_boundary_a, double right_boundary_b, unsigned int intervals);
double num_comut_integral_trapecia(double left_boundary_a, double right_boundary_b, unsigned int intervals);
double num_comput_integral_Simps(double left_boundary_a, double right_boundary_b, unsigned int intervals);
double integrand_expression(double x);

int main()
{
	double left_boundary_a=-4.5, right_boundary_b=10;
	int intervals, v;
	double integral_s=0;

	while(1)
	{
		printf("\n\tEnter the left boundary\n\t\tX(first)=");
		scanf("%lf", &left_boundary_a);
		printf("\n\tEnter the right boundary\n\t\tX(last)=");
		scanf("%lf", &right_boundary_b);
    while(left_boundary_a==right_boundary_b)
    {
        left_boundary_a=-4.5;
        right_boundary_b=10;
    }
	do
	{
		printf("\n\tEnter the number of partition intervals (N>0)\n\t\tN=");
		scanf("%u", &intervals);
	}while(intervals <= 0);

	do
	{
		printf("\n\tChoose the method of calculating:\n");
		printf("\t\t1. By Left Rectangles:\n");
		printf("\t\t2. By Right Rectangles:\n");
		printf("\t\t3. By Trapecia:\n");
		printf("\t\t4. By Simps(parabola method):\n");
		scanf("%u", &v);

	if (v!=1 && v!=2 && v!=3 && v!=4) printf("\nYou are mistaken\n");
	}while(v!=1 && v!=2 && v!=3 && v!=4);

    system("cls");

	switch(v)
        {
        case 1:
        {
            integral_s = num_comput_integral_l_re(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t*Left Rectangles method*\n");
            printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d", left_boundary_a, right_boundary_b, integral_s, intervals);
        }
        break;

        case 2:
        {
            integral_s = num_comput_integral_r_re(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t======*Right Rectangles method*======\n");
            printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d ", left_boundary_a, right_boundary_b , integral_s, intervals);
        }
        break;

        case 3:
        {
            integral_s = num_comut_integral_trapecia(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t======*trapecia method *======\n");
            printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d", left_boundary_a, right_boundary_b, integral_s, intervals);
        }
        break;
        case 4:
        {
            integral_s = num_comput_integral_Simps(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t======*simps's method *======\n");
            printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d", left_boundary_a, right_boundary_b, integral_s, intervals);
        }
        break;
        }
	}
	return 0;
}

double num_comput_integral_l_re(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
	double integral_s = 0, x = 0, h;
	unsigned int i;
	h = (right_boundary_b - left_boundary_a) / intervals;
	x = left_boundary_a;
	for (i = 0; i <= (intervals - 1); i++)
	{
		integral_s += integrand_expression(x);
		x += h;
	}
	return integral_s * h;
}

double num_comput_integral_r_re(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
	double integral_s = 0, x = 0, h;
	unsigned int i;
	h = (right_boundary_b - left_boundary_a) / intervals;
	x = left_boundary_a + h;
	for (i = 0; i <= intervals; i++)
	{
		integral_s += integrand_expression(x);
		x += h;
	}
	return integral_s * h;
}

double num_comut_integral_trapecia(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
	double integral_s = 0, x = 0, h;
	unsigned int i;
	h = (right_boundary_b - left_boundary_a) / intervals;
	x = left_boundary_a + h;
	for (i = 0; i <= (intervals - 1); i++)
	{
		integral_s += (integrand_expression(x) + integrand_expression(x + h)) / 2;
		x += h;
	}
	return integral_s * h;
}

double num_comput_integral_Simps(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
	double integral_s = 0, sum1 = 0, sum2 = 0, h = 0;
	h = (right_boundary_b - left_boundary_a) / intervals;
	for (int i = 1; i <= (intervals - 1); i++)
	{
		if (i%2!=0)
			sum1 += integrand_expression(left_boundary_a + h * i);
		else
			sum2 += integrand_expression(left_boundary_a+ h * i);
	}
	return (integrand_expression(left_boundary_a) + integrand_expression(right_boundary_b) + 4 * sum1 + 2 * sum2) * h / 3;
}

double integrand_expression(double x)
{
	return pow(x,2)*sin(x);
}
