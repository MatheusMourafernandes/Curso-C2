#include<stdio.h>
void soma_vet ( int array[10]){
for (int i=0; i< 10; i++){
printf (" vetor posiçã %d \n",i);
int pos;
scanf("%d",& pos);
array[i]= pos; 
}
printf("Vetor[");
for (int j=0; j<10; j++){
	printf ("  %d", array[j]);
}
printf("]\n");	
	int total=0;
	for(int i; i<10;i++){
	total+=  array[i];	
	}
	printf("Total %d", total);
	
}



int main (){
	int vet[10];
soma_vet(vet);

	
}

