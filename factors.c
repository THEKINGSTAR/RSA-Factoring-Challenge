#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <unistd.h>
#include <gmp.h>

/*getline(&buffer,&size,stdin);*/

void primeFactors(ssize_t n);

/* void primeFactors(int n);*/
/**
 * main - read the code
 *
 * @argc: count of arguments
 * @argv:arguments passed
 *
 * Return: 0 if success
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len;
	ssize_t nread;


	mpz_t numb;
	mpz_init(numb);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <file>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, file) != -1))
	{
		/* printf("Read line of lenght %lld: %s\n", nread, line);*/

		/*numb = atoi(line);*/
		mpz_set_str(numb, line, len);
		gmp_printf("numb is  %Zd\n", numb);
		mpz_clear(numb);
		/*
		 * ldiv_t result = ldiv(numb, 2);
		 * printf("Quotient: %ld\n", result.quot);
		 * printf("Remainder: %ld\n", result.rem);
		 */
		/*primeFactors(numb);*/
		/* fwrite(line, nread, 1, stdout);*/
	}
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);

	return (0);
}


/**
 * primeFactors - print prime factor fucntios
 * @n: input number
 * Return: no return value
 */

void primeFactors(ssize_t n)
{
	ssize_t in_num = n;
	ssize_t c = 2;
	ssize_t dom = 1, num = 1;


	/*printf("NUM IN %i\n",in_num);*/
	while (n > 1)
	{
		if (n % c == 0)
		{
			if (dom * c != in_num)
				dom = dom * c;
			/*printf("%d ", c);*/
			n /= c;
		}
		else
			c++;
	}
	num = c;
	/*printf("\nPrime Facturization: %i, %i ,%i \n\n", in_num, dom, num);*/
	if (dom >= num)
		printf("%li=%li*%li\n", in_num, dom, num);
	if (dom < num)
		printf("%li=%li*%li\n", in_num, num, dom);
}
