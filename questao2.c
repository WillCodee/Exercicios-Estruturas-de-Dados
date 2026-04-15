#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <locale.h>

#define MAX 10

struct dados_planta{
  char especie[30];
  int dias_sem_agua;
  char status_irrigacao;
  
};

struct dados_planta plantas[MAX];

int op,idg=0;
char res;
char busca[30];
int achou=0;

void menu(){
    system("clear");
    printf("\n--------PAINEL SISTEMA DE IRRIGAÇÃO DE PLANTAS------------------\n\n");
    printf("\n1 - Cadastrar Planta");
    printf("\n2 - Verificar Irrigção");
    printf("\n3 - Sair");
}

void cadastrar(){
    system("clear");
    printf("\n------- PAINEL PARA CADASTRO DE PLANTA---------\n\n");
    if(idg == 10){
        system("clear");
		printf("\nLista de Plantas em seu Limite Maximo\n");
        fflush(stdout);
		sleep(3);
		return;
    }
    
    do{
        printf("\nInforme a Espécie da Planta: ");
        scanf(" %s",&plantas[idg].especie);
        
        printf("\nInforme a quantidade de dias sem água: ");
        scanf("%d",&plantas[idg].dias_sem_agua);
        
        printf("\nInforme o Status de Irrigação\n[N(necessita de rega) / O(ok)]: ");
        scanf(" %c",&plantas[idg].status_irrigacao);
        
        plantas[idg].status_irrigacao = toupper(plantas[idg].status_irrigacao);
        
        if(idg == 10){
        system("clear");
		printf("\nLista de Plantas em seu Limite Maximo\n");
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

        
    }while(res == 's' && idg<10);
}

void irrigacao(struct dados_planta *p){
    system("clear");
    printf("\n--------SISTEMA DE IRRIGAÇÃO----------\n\n");
    printf("ANTES DA ATUALIZÇÃO:\n\n");
    printf("\n Especie: %s",p->especie);
    printf("\n Dias sem Água: %d",p->dias_sem_agua);
    printf("\n Status da Irrigação: %c",p->status_irrigacao);
    
    if(p->dias_sem_agua >= 3){
        p->status_irrigacao = 'O';
        p->dias_sem_agua = 0;
    }
    
    printf("\n\nDEPOIS DA ATUALIZÇÃO:\n");
    printf("\n Especie: %s",p->especie);
    printf("\n Dias sem Água: %d",p->dias_sem_agua);
    printf("\n Status da Irrigação: %c",p->status_irrigacao);
    
    fflush(stdout);
	sleep(10);
	return;
}

int main()
{
    do{
        menu();
        printf("\nInforme a Operação Desejada: ");
        scanf("%d",&op);
        
        switch(op){
            case 1:
            cadastrar();
            break;
            
            case 2:
             if(idg == 0){
                 system("clear");
                printf("\nLista de Plantas Vazia...");
                fflush(stdout);
			    sleep(3);
			    break;
            }
            
            printf("Informe a especie da Planta que deseja verificar: ");
            scanf(" %s",&busca);
            for(int i=0; i<idg; i++){
                if(strcmp(busca,plantas[i].especie)==0){
                    irrigacao(&plantas[i]);
                    achou=1;
                }
            }
            
            if(achou == 0){
                system("clear");
                printf("Planta não encontrada...");
                fflush(stdout);
			    sleep(3);
            }
            achou=0;
            break;
            
            default:
        }
        
        
        
        
    }while(op != 3);
    

    return 0;
}
