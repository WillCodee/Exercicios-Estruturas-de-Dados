#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <locale.h>

#define MAX 10

struct dados_projeto{
    char nome_peca[50];
    int tempo_estimado;
    int status_conclusao;
};

struct dados_projeto dados[MAX];
int op=0,idg=0;
char resp;

void menu(){
    system("clear");
    printf("\n---------MENU DE OPÇÕES IMPRESSORA 3D---------\n\n");
    printf("\n1-Cadastrar informações da Peça");
    printf("\n2-Alterar Status da Peça");
    printf("\n3-Sair\n");
}

void cadastrar(){
        if(idg == 10){
            system("clear");
		    printf("\nLista de Peças em seu Limite Maximo\n");
            fflush(stdout);
		    sleep(3);
		    return;
        }
        
    do{
        system("clear");
        printf("\n----------CADASTRO DA PEÇA----------------\n\n");
        
        printf("Informe o nome da Peça: ");
        getchar();
        fgets(dados[idg].nome_peca, 30,stdin);
        dados[idg].nome_peca[strcspn(dados[idg].nome_peca, "\n")] = '\0';
        
        printf("\nInforme o Tempo Estimado de Impressão (em minutos): ");
        scanf("%d",&dados[idg].tempo_estimado);
        
        printf("\nInforme o Status de Conclusão [0-não concluido / 1-concluido]: ");
        scanf("%d",&dados[idg].status_conclusao);
        
        while(dados[idg].status_conclusao != 0 && dados[idg].status_conclusao != 1){
            printf("\nValor invalido!\n Informe a opção correta");
            printf("\nInforme o Status de Conclusão [0-não concluido / 1-concluido]: ");
            scanf("%d",&dados[idg].status_conclusao);
        }
        
        idg++;
        
        printf("\nDeseja Continuar o Cadastro?[S/N]: ");
		scanf(" %c",&resp);

        system("clear");

		resp = tolower(resp);
		if(resp != 's') {
			printf("\nSaindo da Tela de Cadastro...");
			fflush(stdout);
			sleep(3);
			break;
		}
        
        if(idg == 10){
            system("clear");
		    printf("\nLista de Peças em seu Limite Maximo\n");
            fflush(stdout);
		    sleep(3);
		    break;
        }
        
        
    }while(resp == 's' && idg<10);
    
    
}

void alterarStatus(struct dados_projeto *p,int tamanho,int tempo_max){
    
    for(int i=0; i<tamanho; i++){
        if((p+i)->tempo_estimado <= tempo_max){
            printf("\nPEÇAS ANTES DA ALTERAÇÃO:\n");
            printf("\nNome da Peça: %s",(p+i)->nome_peca);
            printf("\nTempo Estimado: %d",(p+i) -> tempo_estimado);
            printf("\nStatus de Conclusão: %d",(p+i)-> status_conclusao);
            (p+i)->status_conclusao = 1;
            printf("\nPEÇAS DEPOIS DA ALTERAÇÃO:\n");
            printf("\nNome da Peça: %s",(p+i)->nome_peca);
            printf("\nTempo Estimado: %d",(p+i) -> tempo_estimado);
            printf("\nStatus de Conclusão: %d",(p+i)-> status_conclusao);
        }
    }
    
    printf("\nStatus de Peças alterado com sucesso");
    fflush(stdout);
	sleep(10);
	return;
    
}

int main()
{
    do{
        menu();
        printf("Informe a opção Desejada: ");
        scanf("%d",&op);
        
        switch(op){
            
            case 1:
                cadastrar();
            break;
            
            case 2:
            if(idg == 0){
                system("clear");
                printf("\nSem Peças Cadastradas");
                fflush(stdout);
        		sleep(3);
        		break;
            }
            
            system("clear");
                int tempo_limite;
                printf("\n---------PAINEL PARA ALERAÇÃO DE STATUS DE PROJETO---------\n\n");
                printf("Informe um Tempo limite máximo (em minutos): ");
                scanf("%d",&tempo_limite);
                
                alterarStatus(dados,idg,tempo_limite);
            break;
            
            default:
            
        }
        
    }while(op != 3);
    return 0;
}