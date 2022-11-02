#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "forca.h"

//--------------------------------Vraiaveis universais ---------------------------------------------------
	char palavra_secreta[26];
	char chutes[26];// vetor tipo caracter que guarda as letras que o usuário chutou 
	int chutes_dados=0;// inicializa as tentativas do usuário 
// Função abertura imprime a abertura do jogo
//------------------------------------------------Funções --------------------------------------------------------------------------------
//________________________________________________Abertura ______________________________________________________
void abertura(){// Fução tipo vazia que retorna 0 
// Abertura 
	printf("**********************\n");
	printf("*  Jogo da Forca     *\n");
	printf("**********************\n\n");
}
//__________________________________________________Função escolher _____________________________________________
void escolher_palavra(){
	FILE* f;
	f=fopen("palavras.txt","r");// abrir o arquivo txt
	   if(f == 0) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }
	int qtd_palavra; // declaraçã de variuaveis que ira guarda quantidade de palavras no arquivo 
	fscanf(f,"%d",&qtd_palavra);// leitura da primeira linha do arquivo que informa a quantidade de palavras 
//----Numero aleatório 
	srand(time(0));                        // representa a linha 
	int randomico= rand() % qtd_palavra;
//-----	
	for(int i=0; i<= randomico; i++){
		fscanf(f,"%s",palavra_secreta);
	}
	
	fclose(f);
}
//_________________________________Chutar____________________________________________________________________________________
void chuta(){// função definida com paramentros chute[26] e tentativas definidas na função main 
/*sA utilização do ponteirio como paramentro é pegar o endereço de memoraria da variavel tentativas definida na função main
tendo em vista que a variavel tentativas definicda como paramentrod da função chuta é diferente da variavel da tentativas da função 
main*/
	char chute;// definiçã da variavel chute 
		scanf(" %c",& chute);// leitura da variavel chute 
		chutes[(chutes_dados)]=chute;// guardando o chute na string chutes 
		(chutes_dados)++;
}
//_________________________________________Chutes eraados_______________________________________________________
int chuteserrados(){
		int erros=0;// inicialização do erros nivel logico falso 
	for ( int i=0; i < chutes_dados; i++){// varrear o array do jogo 
 int existe=0; // condição de existencia 

   for ( int j=0; j< strlen(palavra_secreta);j++){// varrer o tamanho da palavra e contabiliza chutes certos 
   	if (chutes[i]== palavra_secreta[j]){// se o chute corresponde alguma posição da palavra screta 
   		existe=1; // se a palavra exite nivel logico verdadeiro 
		 break; // para o  segundo lopp 
   		
}
}
if (!existe) erros++;// se o chute não coreesponde  contabiliza os chutes errados 	
}
return erros;
}
//________________________________________Desenahr forca ___________________________________________________________
void desenha(){
	
   int erros= chuteserrados();
    printf("  _______      \n");
    printf(" |/      |     \n");  
    printf(" |      %c%c%c \n"  ,(erros>=1?'(' :' '),(erros >=1 ?'_' :' '), (erros >=1 ?')' :' '));
    printf(" |      %c%c%c   \n"  ,(erros>=3?'\\' :' '),(erros >=2 ?'|' :' '),(erros >=4 ?'/' :' '));                        
    printf(" |       %c    \n",    (erros>=2?'|' :' '));
    printf(" |      %c   \n",(erros>=5?'/' :' '),(erros>=6?'\\' :' '));
    printf("_|___          \n");
    printf("\n\n");

    // ...

		for(int i=0;i<strlen(palavra_secreta);i++){// laço de repetição que repete a quantidade de letra da palavra secreta 
		int achou = jachutou(palavra_secreta[i]);// Tendo em vista que ja achou é uma função que possui retorno associa-se o retorno da função a uma variavel 
		if (achou){// se achou igual nivel alto 
			printf("%c", palavra_secreta[i]);// imprime a palavra secreta de possiçã i 
		}else{// se achou nivel baixo 
			printf("_ ");// imprime o tracinho 
		}
		}
		printf("\n");
}

//_________________________________________Função enforcou ________________________________________________________
// determina limite de erros 
int enforcou () {

return chuteserrados()>=6;// pode errar 5 vezes (cabeça , corpo , 2 braços, 2pernas) 
}
//___________________________________________Função ganhou _____________________________________________________

int acertou (){
for (int i =0; i < strlen(palavra_secreta);i++){
	if ( !jachutou(palavra_secreta[i])){
		return 0;
	}
}	
return 1;
}
//_________________________________Ja achou _________________________________________________________________________________
int jachutou(char letra){

		int achou=0;// inicializa a condição achou 
		for(int j=0;j<chutes_dados;j++){	// laço de repetição que repete iguamente o numerfo de tentativas que é definido pelo o while 
		if (chutes[j]==letra ){// se o chute for igual a uma das letras da palac=vra secreta 
			achou=1;// achou se torna 1 nivel alto 
			break;
     	}
		}
		return achou;
}

//_______________________________Adicionar palavra __________________________________________________________________________

void adicionar() {
    char op;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &op);

    if(op == 'S') {
        char novapalavra[20];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);

    }

}

//--------------------------------------------------------Função main -------------------------------------------------------------------------------------
int main (){
 
escolher_palavra();
abertura();
	do {// executa os comandos abaixo enquanto ocorrer a condição da linha 39
        desenha(); //atribuie as demais função para imprir a letra as letras ja chutatdas e os tracinhos 
		chuta();// o & pega o endereço de memoria da variavel sendo assim o ponteiro de paramentro aponta para o endereço d ememoria da variavel tentativas 
		
	}while( !acertou() && !enforcou());//condição linha 39
	if(enforcou()){
printf("VOCE PERDEU!!\n");
    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      (_)    \n");
    printf(" |      \\|/   \n");
    printf(" |       |     \n");
    printf(" |      / \\   \n");
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");
printf("A palavra era:%s\n", palavra_secreta);
    // ...
}else if (acertou()){

  printf("\nParabéns, você ganhou!\n\n");

    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
}
adicionar();
	return 0;

}
