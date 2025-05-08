// Importacao de bibliotecas (dependecias)
#include <stdio.h>	//Entradas/Saidas
#include <stdlib.h>	//Manipulacao de Memoria, Funcao System e Aleatorio
#include <locale.h>	//Caracteres em Portugues
#include <time.h>	//Time (Tempo/Data)
#include <ctype.h>	//Para Analise de Caracteres

//Declaracao das Variaveis Inteiras ('i' para incremento em loops)
int i, tamanhoSenha, opcao; 

//Determina os caracteres disponiveis para gerar senha tipo 1
const char caracteresMin[] = "abcdefghijklmnopqrstuvwxyz";
//Determina os caracteres disponiveis para gerar senha tipo 2
const char caracteresMai[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//Determina os caracteres disponiveis para gerar senha tipo 3
const char caracteresNum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890123456789";
//Determina os caracteres disponiveis para gerar senha tipo 4
const char caracteresEsp[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890123456789!@#$%&*!@#$%&*!@#$%&*";
//Definicao dos tipos de forca da senha dentro de uma Matriz
const char classificacao[4][6] = {{"Muito"},{"Fraca"}, {"Media"}, {"Forte"}};

//Declara um ponteiro para a string da senha, pois ela pode variar de tamanho
char *senha;
//Declara o Char para repeticao do programa (gerar outra senha)
char repete = 's';

//Funcao para Exibir o Cabecalho do Programa
void cabecalho () {
	printf(" __________________________________________________________"); 			//Cabecalho
	printf("\n|  _______________________________________________________ |"); 		//Cabecalho
	printf("\n| |   ____                    _                  _       | |");		//Cabecalho
	printf("\n| |  / ___| ___ _ __ __ _  __| | ___  _ __    __| | ___  | |");		//Cabecalho
	printf("\n| | | |  _ / _ \\ '__/ _` |/ _` |/ _ \\| '__|  / _` |/ _ \\ | |");	//Cabecalho
	printf("\n| | | |_| |  __/ | | (_| | (_| | (_) | |    | (_| |  __/ | |");		//Cabecalho
	printf("\n| |  \\____|\\___|_|  \\__,_|\\__,_|\\___/|_|     \\__,_|\\___| | |");//Cabecalho
	printf("\n| | / ___|  ___ _ __ | |__   __ _ ___                    | |");		//Cabecalho
	printf("\n| | \\___ \\ / _ \\ '_ \\| '_ \\ / _` / __|                   | |");	//Cabecalho
	printf("\n| |  ___) |  __/ | | | | | | (_| \\__ \\                   | |");		//Cabecalho
	printf("\n| | |____/ \\___|_| |_|_| |_|\\__,_|___/                   | |");		//Cabecalho
	printf("\n| |______________________________________________________| |");		//Cabecalho
	printf("\n|__________________________________________________________|\n\n");	//Cabecalho
}

//Funcao de Configuracao da Senha
void configSenha () {
	do {
		//Muda o titulo da aba, a cor dos caracteres e limpa o prompt
		system("cls"); system("title Gerador de Senhas Aleat rias"); system("color a");
		//Executa o Cabecalho do Programa
		cabecalho();
		printf("\n>>Informe a quantidade de caracteres que deseja gerar: ");
		//Aguarda o usuario digitar o tamanho da senha (Quantidade de Caracteres que deseja gerar)
		scanf("%i", &tamanhoSenha);
		
		if(tamanhoSenha <= 0) {//Se tamanho da senha for 0 ou menor, executa o seguinte erro:
			system("color 4"); system("cls"); //Limpa o prompt e muda a cor para vermelho
			cabecalho(); //Exibe cabecalho
			printf("\n\n[!] INFORME UMA QUANTIDADE MAIOR QUE 0 [!]");	//Mensagem de Erro
			printf("\n[!] INFORME UMA QUANTIDADE MAIOR QUE 0 [!]");		//Mensagem de Erro
			printf("\n[!] INFORME UMA QUANTIDADE MAIOR QUE 0 [!]\n\n");	//Mensagem de Erro
			system("pause"); //Aguarda o usuario ler o erro e confirmar
		}
	} while (tamanhoSenha <= 0);
	
	//Com a funcao 'malloc' realiza a aloca o din mica na mem ria de acordo com o tamanho necessario
	// e incrementa +1 para reservar espa o do caractere '\0' nulo que sera incluido no final
	senha = malloc((tamanhoSenha + 1) * sizeof(char));
	
	do {
		system("color a"); system("cls"); //Limpa o prompt
		cabecalho(); //Exibe cabecalho
		printf("\nVoce escolheu gerar uma senha de %i caracteres.\n", tamanhoSenha);
		printf("\nEscolha o tipo de senha que deseja gerar\n");
		printf("\n>Opcoes de Senha: \n");
		printf("1- Apenas Letras Minusculas\n"); //Tipo 1
		printf("2- Letras Minusculas e Maiusculas\n"); //Tipo 2
		printf("3- Letras e Numeros (Maiusculas e Minusculas)\n"); //Tipo 3
		printf("4- Letras, Numeros e Caracteres Especiais\n"); //Tipo 4
		printf("\n>>Digite o Numero equivalente a opcao escolhida: ");
		scanf("%i", &opcao); //Aguarda input do usuario
		
		if (opcao < 1 || opcao > 4) { //Caso opcao escolhida seja invalida
			system("color 4"); system("cls"); //Limpa o prompt e muda a cor para vermelha
			cabecalho(); //Mostra o cabecalho
			printf("\n[!] SELECIONE UMA OPCAO VALIDA (DE 1 A 4) [!]");	//Mensagem de Erro
			printf("\n[!] SELECIONE UMA OPCAO VALIDA (DE 1 A 4) [!]");	//Mensagem de Erro
			printf("\n[!] SELECIONE UMA OPCAO VALIDA (DE 1 A 4) [!]\n\n");//Mensagem de Erro
			system("pause"); //Aguarda o usuario ler a mensagem de erro e confirmar
		}
	} while (opcao < 1 || opcao > 4); //Repete a escolha da opcao at que seja escolhida uma opcao valida
}

// Funcao gerar senha
void gerarSenha() {
	srand(time(NULL)); //Inicializa o Gerador de Numeros Aleatorios, utilizando o timestamp atual como base para a seed
	
	switch(opcao) {//Switch-Case para gerar cada tipo de senha diferente
		case 1:
			for(i=0; i<tamanhoSenha; i++) {//Repeticao para selecionar com rand() cada caractere da senha[] incrementando com i
				senha[i] = caracteresMin[rand() % 26];
			}
			senha[tamanhoSenha] = '\0'; //Seta o caractere nulo no final da string senha para utilizar o 'printf()' na sequencia sem causar erro
			printf("\nSenha Gerada: %s\n", senha); //Exibe a senha gerada!
		break;
		
		case 2:
			for(i=0; i<tamanhoSenha; i++) {
				senha[i] = caracteresMai[rand() % 52];
			}
			senha[tamanhoSenha] = '\0';
			printf("\nSenha Gerada: %s\n", senha);
		break;

		case 3:
			for(i=0; i<tamanhoSenha; i++) {
				senha[i] = caracteresNum[rand() % 72];
			}
			senha[tamanhoSenha] = '\0';
			printf("\nSenha Gerada: %s\n", senha);
		break;

		case 4:
			for(i=0; i<tamanhoSenha; i++) {
				senha[i] = caracteresEsp[rand() % 93];
			}
			senha[tamanhoSenha] = '\0';
			printf("\nSenha Gerada: %s\n", senha);
		break;
	}
}

//Funao para Verificar/Analisar e Classificar a Forca da senha com base na senha atual que foi gerada
void verificarSenha(char *senha) {
	//Score para classificar a forca da senha
	int forca = 0;
	
	//Verificar se a senha tem ao menos 10 caracteres
	if(tamanhoSenha >= 10) {
		forca++; //Incrementa um ponto no Score
	}
	
	//Verificar se a senha tem letras maiusculas e minusculas
	int maiuscula = 0, minuscula = 0;
	//Loop para checar cada caractere da senha
	for (i = 0; i < tamanhoSenha; i++) {
		if(isupper(senha[i])) {
			maiuscula++; //Verifica se tem pelo menos 1 caractere MAIUSCULO
		}
		if(islower(senha[i])) {
			minuscula++; //Verifica se tem pelo menos 1 caractere minusculo
		}
	}
	
	//Se houver ao menos 1 MAIUSCULO E 1 Minusculo
	if(maiuscula > 0 && minuscula > 0) {
		forca++; //Incrementa um ponto no Score
	}
	
	//Verificar se a senha tem numeros
	int numeros = 0;
	//Loop para checar cada caractere da senha
	for (i = 0; i < tamanhoSenha; i++) {
		if(isdigit(senha[i])) numeros++; //Verifica se tem pelo menos 1 caractere numerico
	}
	
	//Se houver ao menos 1 caractere numerico
	if(numeros > 0) {
		forca++; //Incrementa um ponto no Score
	}
	
	//Verificar se a senha tem caracteres especiais
	int caracteresEspeciais = 0;
	//Loop para checar cada caractere da senha
	for (i = 0; i < tamanhoSenha; i++) {
		if(ispunct(senha[i])) caracteresEspeciais++; //Verifica se tem pelo menos 1 caractere especial
	}
	
	//Se houver ao menos 1 caractere especial
	if(caracteresEspeciais > 0) {
		forca++; //Incrementa um ponto no Score
	}
	
	printf("\nForca da senha: ");
	switch (forca) { //Verifica a forca da senha (Muito Fraca/Fraca/Media/Forte)
		case 1: //Score de 1 ponto = Fraca
			for (i=0; i<5; i++) {
				printf("%c", classificacao[forca][i]); //Executa a matriz em loop para exibir 'Fraca'
			}
		break;
		
		case 2: //Score de 2 pontos = Media
			for (i=0; i<5; i++) {
				printf("%c", classificacao[forca][i]); //Executa a matriz em loop para exibir 'Media'
			}
		break;
		
		case 3: //Score de 3 pontos = Forte
			for (i=0; i<5; i++) {
				printf("%c", classificacao[forca][i]); //Executa a matriz em loop para exibir 'Forte'
			}
		break;
		
		case 4: //Score de 4 pontos = Muito Forte (score maximo)
			for (i=0; i<5; i++) {
				printf("%c", classificacao[0][i]); //Executa a matriz em loop para exibir 'Muito'
			}
			printf(" "); //Espaco ' ' em branco para formatacao do texto
			for (i=0; i<5; i++) {
				printf("%c", classificacao[forca - 1][i]); //Executa a matriz em loop para exibir 'Forte'
			}
		break;
		
		default: //Score de 0 pontos = Muito Fraca (score minimo)
			for (i=0; i<5; i++) {
				printf("%c", classificacao[forca][i]); //Executa a matriz em loop para exibir 'Muito'
			}
			printf(" "); //Espaco ' ' em branco para formatacao do texto
			for (i=0; i<5; i++) {
				printf("%c", classificacao[1][i]); //Executa a matriz em loop para exibir 'Fraca'
			}
		break;
	}
}

void main () {
	//Define para Lingua Portuguesa para exibir corretamente os caracteres com acento usados nos 'printf()'
	//se bem que eu acabei removendo todos os caracteres acentuados, mas vou deixar a funcao ai no codigo
	setlocale(LC_ALL, "Portuguese");
	
	do {
		system("cls"); system("title Gerador de Senhas Aleat rias"); system("color a"); //Muda o t tulo da aba, a cor dos caracteres e limpa o prompt
		configSenha(); //Executa a Funcao de Configura o da Senha
		gerarSenha(); //Executa a Funcao que Gera a Senha
		verificarSenha(senha); //Executa a Funcao de Verifica o da For a da Senha
		free(senha); //Libera o espa o da memoria que foi alocado anteriormente
		printf("\n>>Deseja gerar outra senha? [S/N]: "); //Gerar outra senha Reinciar o Programa
		scanf("%s", &repete); //Aguarda o usuario digitar se quer gerar outra senha ou nao
	} while(repete == 'S' || repete == 's'|| repete == 'sim'); //Loop para repetir o programa
	system("color 8"); //Finaliza o Programa com uma cor mais apagada
	
	printf("\n\n\nGerador de Senhas Pseudo-Aleatorias");
	printf("\nDesenvolvido por Matheus de Alcantara & Henrique Bicudo");
	printf("\n\n[2023]\n\n\n");
}
