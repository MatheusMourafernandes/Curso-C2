#include<stdio.h>

void potencia(int* resultado, int a, int b) {
    *resultado = 1;
    for(int i = 0; i < b; i++) {
        *resultado = *resultado * a;
    }
    printf("%d", *resultado);
}



int main (){
	int num, pot ,res;
printf(" Informe o numero: ");
scanf("%d",& num);
printf("\n");

printf(" Informe a potencia: ");
scanf("%d",& pot);
printf("\n");
potencia(&res, num,pot);
}
