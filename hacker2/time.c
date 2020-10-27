#include<stdio.h>
#include<time.h>
#include <cc50.h>
#include <math.h>

int
main(void)
{
    time_t t;
    time(&t);


    printf ("Digite a quantidade de caracteres para testar o tempo de computação\n");
    int CONTADOR2 = GetInt();
    long long int CONTADOR = pow ( 80 , CONTADOR2);
    for (int i=0; i<CONTADOR; i++)
    {
	long long int PERC;
	if (i>0)
		PERC = i * 100 / CONTADOR;
	printf ("%i de %lli     %lli percentual", i, CONTADOR, PERC);
	int a = 32, b = 32, c = 32, d = 32, e = 32, f = 32, g = 32, h = 32, i = 32, j = 32;
	int k = 124, l = 124;
	int m = PERC / 10;
	if ( m >= 1 )
		a = 61;
	if ( m >= 2)
		b = 61;
	if ( m >= 3)
		c = 61;
	if ( m >= 4)
		d = 61;
	if ( m >= 5)
		e = 61;
	if ( m >= 6)
		f = 61;
	if ( m >= 7)
		g = 61;
	if ( m >= 8 )
		h = 61;
	if ( m >= 9)
		i = 61;
	if ( m >= 10 )
		i = 61;
	printf ("%c%c%c%c%c%c%c%c%c%c%c%c\n", k, a, b, c, d, e, f, g, h, i, j, l);
    }

    printf("\n previus time is : %s",ctime(&t));


    time_t t2;
    time(&t2);
    printf("\n current time is : %s",ctime(&t2));
    printf("\n quantidade de caracteres para ataque de força bruta: %d\n", CONTADOR2);
}
