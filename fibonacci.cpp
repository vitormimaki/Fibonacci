#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

bool fibonacci(int num) {
	bool pertence = false;
	int *fib;
	int i = 0;
	
	fib = (int *)malloc(sizeof(int) *  1);
	fib[0] = 0;
	
	for(i = 1; fib[i-1] < num; i++) {
		fib = (int *)realloc(fib, sizeof(int) * (i+1));
		if(i > 1) {
			fib[i] = fib[i-1] + fib[i-2];
		} else {
			fib[i] = i;
		}
	}
	
	int tam = i - 1;
	
	printf("[");
	for(i = 0; i <= tam && pertence == false; i++) {
		if(i == tam) {
			printf("%d]\n\n", fib[i]);
			if(fib[i] == num){
				pertence = true;
			}
		} else {
			printf("%d, ", fib[i]);
		}
	}
	free(fib);
	
	return pertence;
}

int main(void) {
	int num = -1;
	bool pertence;
	
	setlocale(LC_ALL, "portuguese");
	
	do {
		printf("Informe um número: ");
		scanf("%d", &num);
		if(num < 0) {
			system("cls");
			printf("Deve ser > 0\n");
		}
	} while (num < 0);
	
	pertence = fibonacci(num);
	
	if(pertence) {
		printf("O número %d PERTENCE a sequência.\n\n", num);
	} else {
		printf("O número %d NÃO PERTENCE a sequência.\n\n", num);
	}
	
	system("pause");
	
	return 0;
}
