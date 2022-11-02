#include<stdio.h>
 void abertura (int numero){
 	
 	printf(" O numero para a tabuada é :", numero );
 	printf("\n");
 }
 
 
 
 int main (){
 	int numero, i, res ; 
printf(" Qual numero sera atabuada ?\n");
scanf ("%d", & numero);
abertura(numero);
for ( i=0; i<11; i++){
res=i*numero;
printf("%d x %d = %d\n", i , numero, res);	
}	
 	
 	
 	
 }
