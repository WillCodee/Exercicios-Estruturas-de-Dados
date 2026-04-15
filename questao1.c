#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <locale.h>

#define MAX 10

struct notebook {
	char modelo[20];
	char marca[20];
	double preco;
	int qtd_RAM;
};

struct notebook maior_ram;
struct notebook laptop[MAX];
int idg=0;
char res;

void menu() {
	system("clear");
	printf("\n-------PAINEL DAS LOJAS DE PRODUTOS ELETRONICOS -------------\n\n");
	printf("1 - Cadastrar Notebook\n");
	printf("2 - Exibir Notebook\n");
	printf("3 - Sair\n");
	printf("Escolha a opção desejada: ");
}


void cadastrar() {
	system("clear");
	printf("\n------CADASTRAR NOTEBOOK----\n\n");

	if(idg == 10) {
		system("clear");
		printf("\nLista de Notebooks em seu Limite Maximo\n");
        fflush(stdout);
		sleep(3);
		return;
	}

	do{

		printf("\nInforme Modelo de Notebook: ");
		scanf(" %s",&laptop[idg].modelo);

		printf("\nInforme Marca do Notebook: ");
		scanf(" %s",&laptop[idg].marca);

		printf("\nInforme Preço do Notebook: ");
		scanf("%lf",&laptop[idg].preco);

		printf("\nInforme a quantidade de Memória RAM: ");
		scanf("%d",&laptop[idg].qtd_RAM);

		if(idg == 10) {
			system("clear");
			printf("\nLista de Notebooks em seu Limite Máximo\n");
			fflush(stdout);
            sleep(3);
			break;
		}

		idg++;

		printf("\nDeseja Continuar o Cadastro?[S/N]: ");
		scanf(" %c",&res);

        system("clear");

		res = tolower(res);
		if(res != 's') {
			printf("\nSaindo da Tela de Cadastro...");
			fflush(stdout);
			sleep(3);
			break;
		}

	}while(res == 's' && idg < 10) ;
}

void exibir() {

    system("clear");
	printf("\n------EXIBIR NOTEBOOKS----\n\n");
	
	 if(idg == 0){
        printf("Nenhum notebook cadastrado.\n");
        fflush(stdout);
        sleep(3);
        return;
    }
	
	maior_ram = laptop[0];
	for(int i= 1; i<idg; i++){
	    if(laptop[i].qtd_RAM > maior_ram.qtd_RAM){
	        maior_ram = laptop[i];
	    }
	}
	
	printf("Notebook com Maior Memoria RAM\n");
	printf("\nModelo: %s",maior_ram.modelo);
	printf("\nPreço: %.2lf",maior_ram.preco);
	fflush(stdout);
	sleep(3);
}

int main()
{

	int op;
    setlocale(LC_ALL," ");
    
    
	do {
		menu();
		scanf("%i",&op);

		switch(op) {
		case 1:
			cadastrar();
			break;

		case 2:
			exibir();
			break;

		default:
		}


	} while(op != 3);



	return 0;
}