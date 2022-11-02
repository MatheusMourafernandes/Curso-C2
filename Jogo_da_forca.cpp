#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "forca.h"

//--------------------------------Vraiaveis universais ---------------------------------------------------
	char palavra_secreta[26];
	char chutes[26];// vetor tipo caracter que guarda as letras que o usu�rio chutou 
	int chutes_dados=0;// inicializa as tentativas do usu�rio 
// Fun��o abertura imprime a abertura do jogo
//------------------------------------------------Fun��es --------------------------------------------------------------------------------
//________________________________________________Abertura ______________________________________________________
void abertura(){// Fu��o tipo vazia que retorna 0 
// Abertura 
	printf("**********************\n");
	printf("*  Jogo da Forca     *\n");
	printf("**********************\n\n");
}
//__________________________________________________Fun��o escolher _____________________________________________
void escolher_palavra(){
	FILE* f;
	f=fopen("palavras.txt","r");// abrir o arquivo txt
	   if(f == 0) {
            printf("Banco de dados de palavras n�o dispon�vel\n\n");
            exit(1);
        }
	int qtd_palavra; // declara�� de variuaveis que ira guarda quantidade de palavras no arquivo 
	fscanf(f,"%d",&qtd_palavra);// leitura da primeira linha do arquivo que informa a quantidade de palavras 
//----Numero aleat�rio 
	srand(time(0));                        // representa a linha 
	int randomico= rand() % qtd_palavra;
//-----	
	for(int i=0; i<= randomico; i++){
		fscanf(f,"%s",palavra_secreta);
	}
	
	fclose(f);
}
//_________________________________Chutar____________________________________________________________________________________
void chuta(){// fun��o definida com paramentros chute[26] e tentativas definidas na fun��o main 
/*sA utiliza��o do ponteirio como paramentro � pegar o endere�o de memoraria da variavel tentativas definida na fun��o main
tendo em vista que a variavel tentativas definicda como paramentrod da fun��o chuta � diferente da variavel da tentativas da fun��o 
main*/
	char chute;// defini�� da variavel chute 
		scanf(" %c",& chute);// leitura da variavel chute 
		chutes[(chutes_dados)]=chute;// guardando o chute na string chutes 
		(chutes_dados)++;
}
//_________________________________________Chutes eraados_______________________________________________________
int chuteserrados(){
		int erros=0;// inicializa��o do erros nivel logico falso 
	for ( int i=0; i < chutes_dados; i++){// varrear o array do jogo 
 int existe=0; // condi��o de existencia 

   for ( int j=0; j< strlen(palavra_secreta);j++){// varrer o tamanho da palavra e contabiliza chutes certos 
   	if (chutes[i]== palavra_secreta[j]){// se o chute corresponde alguma posi��o da palavra screta 
   		existe=1; // se a palavra exite nivel logico verdadeiro 
		 break; // para o  segundo lopp 
   		
}
}
if (!existe) erros++;// se o chute n�o coreesponde  contabiliza os chutes errados 	
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

		for(int i=0;i<strlen(palavra_secreta);i++){// la�o de repeti��o que repete a quantidade de letra da palavra secreta 
		int achou = jachutou(palavra_secreta[i]);// Tendo em vista que ja achou � uma fun��o que possui retorno associa-se o retorno da fun��o a uma variavel 
		if (achou){// se achou igual nivel alto 
			printf("%c", palavra_secreta[i]);// imprime a palavra secreta de possi�� i 
		}else{// se achou nivel baixo 
			printf("_ ");// imprime o tracinho 
		}
		}
		printf("\n");
}

//_________________________________________Fun��o enforcou ________________________________________________________
// determina limite de erros 
int enforcou () {

return chuteserrados()>=6;// pode errar 5 vezes (cabe�a , corpo , 2 bra�os, 2pernas) 
}
//___________________________________________Fun��o ganhou _____________________________________________________

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

		int achou=0;// inicializa a condi��o achou 
		for(int j=0;j<chutes_dados;j++){	// la�o de repeti��o que repete iguamente o numerfo de tentativas que � definido pelo o while 
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

    printf("Voc� deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &op);

    if(op == 'S') {
        char novapalavra[20];

        printf("Digite a nova palavra, em letras mai�sculas: ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de palavras n�o dispon�vel\n\n");
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

//--------------------------------------------------------Fun��o main -------------------------------------------------------------------------------------
int main (){
 
escolher_palavra();
abertura();
	do {// executa os comandos abaixo enquanto ocorrer a condi��o da linha 39
        desenha(); //atribuie as demais fun��o para imprir a letra as letras ja chutatdas e os tracinhos 
		chuta();// o & pega o endere�o de memoria da variavel sendo assim o ponteiro de paramentro aponta para o endere�o d ememoria da variavel tentativas 
		
	}while( !acertou() && !enforcou());//condi��o linha 39
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

  printf("\nParab�ns, voc� ganhou!\n\n");

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
