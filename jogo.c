#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char palavrasecreta[30];
char chutes[30];
int chutesdados = 0;
char palavras[8][8] = {{"banana"}, {"abacate"}, {"uva"}, {"melao"}, {"pera"}, {"pitaia"}, {"pera"}, {"ameixa"}};

void abertura()
{
	printf("*********************************************************************************\n");
	printf("**********************************JOGO DA FORCA**********************************\n");
	printf("*********************************************************************************\n");
}
void define_palavra()
{
    int i;
    srand(time(NULL));
    int r = rand() % 8;
    for(i = 0; i < sizeof(palavras[r]); i++)
    {
        palavrasecreta[i] = palavras[r][i];
    }
}

int verifica_chute(char letra) 
{

	for(int j = 0; j < strlen(palavrasecreta); j++) 
    {
		if(letra == palavrasecreta[j]) 
        {
			return 1;
		}
	}

	return 0;
}
int chuteserrados() 
{
	int erros = 0;

	for(int i = 0; i < chutesdados; i++) {

		if(!verifica_chute(chutes[i])) {
			erros++;
		}
	}

	return erros;
}


int jachutou(char letra) 
{
	int achou = 0;
	for(int j = 0; j < chutesdados; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}
int ganhou() {
	for(int i = 0; i < strlen(palavrasecreta); i++) {
		if(!jachutou(palavrasecreta[i])) {
			return 0;
		}
	}

	return 1;
}

void chutar()
{
    char chute;
    printf("Chute uma letra (em minusculo) : ");
    scanf("%s", &chute);
    if(verifica_chute(chute))
    {
        printf("Voce acertou uma letra\n");
    }
    else
    {
        printf("Voce errou uma letra\n");

    }
    chutes[chutesdados] = chute;
    chutesdados ++;
}

int enforcou() {
	return chuteserrados() >= 5;
}

void desenhaforca() {

	int erros = chuteserrados();

	printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
	printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
	printf(" |       %c     \n", (erros>=2?'|':' '));
	printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
	printf(" |              \n");
	printf("_|___           \n");
	printf("\n\n");

	for(int i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i])) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}

	}
	printf("\n");

}


int main(void)
{
	char jogar_denovo[5];
	char sim[5] = {"S"};
	abertura();
	jogo:
		define_palavra();
		do {

			desenhaforca();
			chutar();

		} while (!ganhou() && !enforcou());

		if(ganhou()) {
			printf("\nParabens, voce ganhou!\n\n");

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

		} else {
			printf("\nPuxa, você foi enforcado!\n");
			printf("A palavra era **%s**\n\n", palavrasecreta);

			printf("    _______________         \n");
			printf("   /               \\       \n");
			printf("  /                 \\      \n");
			printf("//                   \\/\\  \n");
			printf("\\|   XXXX     XXXX   | /   \n");
			printf(" |   XXXX     XXXX   |/     \n");
			printf(" |   XXX       XXX   |      \n");
			printf(" |                   |      \n");
			printf(" \\__      XXX      __/     \n");
			printf("   |\\     XXX     /|       \n");
			printf("   | |           | |        \n");
			printf("   | I I I I I I I |        \n");
			printf("   |  I I I I I I  |        \n");
			printf("   \\_             _/       \n");
			printf("     \\_         _/         \n");
			printf("       \\_______/           \n");
		}
		
		printf("Deseja jogar denovo ?(S/N)");
		scanf("%s", jogar_denovo);
		int comparador = strcmp(jogar_denovo, sim);
    	if(comparador == 0)
		{
			chutesdados = 0;
			goto jogo;
		}
}