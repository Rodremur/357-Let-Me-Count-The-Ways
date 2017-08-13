/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 357 - Let Me Count The Ways
 * Fecha: 20-04-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>

int n, i, j, c1;
int coins[] = {1, 5, 10, 25, 50};

int main(int argc, char const *argv[])
{
	while (scanf("%d", &n) == 1) {
        c1 = n + 1;
        long long t[c1];
        t[0] = 1;
        for (i = 1; i < c1; i++) {
            t[i] = 0;
        }
        for (i = 0; i < 5; i++) {
            for (j = coins[i]; j < c1; j++) {
                t[j] += t[j - coins[i]];
            }
        }
        if (t[c1-1] != 1)
            printf("There are %lld ways to produce %d cents change.\n", t[c1-1], n);
        else
            printf("There is only %lld way to produce %d cents change.\n", t[c1-1], n);
	}
    return 0;
}
