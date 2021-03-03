//Breno Augusto - RA 2840482011030
//Programa responsavel por codificar e traduzir desde simples frases que podem ser colocada rapidamente, até textos que podem ser escritos dentro do .txt que é criado automaticamente 

#include <iostream>

//strcpy; strcat etc
#include <stdio.h>

//acentos
#include <locale.h>

//strlen
#include <string.h>

//Esquema de cores
#define RED "\033[31;40m"
#define GREEN "\033[1;92m"
#define WHITE "\033[37;40m"
#define YELLOW "\033[33;40m"
#define BLUE "\033[1;36m"
#define CYAN "\033[1;96m"

//tamanho do vetor 
#define MAX 3000

using namespace std;

//não sei porque coloquei como global, nao vou mexer pq ta funcionando
char frase[MAX];

//variaveis usadas para armazenamento dos txt
char linha[MAX], texto[MAX];	

//flag
int l = 0;

//Função para codificar	
void codificador (char bruto[MAX]){
	
	//laço de codificação
	for(int i = 0; i < strlen(bruto); i++){
		
		bruto[i] += 3;
		
	}
	
	cout << endl;
	
	//laço para mostrar
	for(int i = 0; i < strlen(bruto); i++){
		
		cout << GREEN << bruto[i] << WHITE;
		
	}
	
	cout << endl << endl;
	
	//caso l = 1 (gravar em txt == verdadeiro)
	if(l == 1){
		
		char textocod[MAX];
		
		FILE *arqCod;
		
		//abrir o arquivo para gravar
		arqCod = fopen("Codificado.txt", "w");
		
		//gravar o texto no .txt
		for(int i = 0; i < strlen(bruto); i++){
			
			fputc(bruto[i], arqCod);
		
		}
		
		fclose(arqCod);
		
		cout << YELLOW << "Codificação salva no arquivo 'Codificado.txt'\n\n" << WHITE;
	}
	
	system("pause");
	
	//zerar flag
	l = 0;
	
}

//Função de decodificação
void decodificador (char bruto[MAX]){
	
	//Decodificação
	for(int i = 0; i < strlen(bruto); i++){
		
		bruto[i] -= 3;
		
	}
	
	cout << endl;
	
	//Laço para mostrar
	for(int i = 0; i < strlen(bruto); i++){
		
		cout << GREEN << bruto[i] << WHITE;
		
	}
	
	cout << endl << endl;
	
	//caso seja pedido para ser gravado no .txt
	if(l == 1){
		
		char textocod[MAX];
		
		FILE *arqCod;
		
		//ele abre o arquivo para escrita
		arqCod = fopen("bruto.txt", "w");
		
		//gravação
		for(int i = 0; i < strlen(bruto); i++){
			
			fputc(bruto[i], arqCod);
		
		}
		
		fclose(arqCod);
		
		cout << YELLOW << "Decoodificação salva no arquivo 'bruto.txt'\n\n" << WHITE;
	}
	
	system("pause");
	
	//zerar flag
	l = 0;
}

int main(){
	
	FILE *arq;
		
	//variavel de escolha no menu
	int esc, i = 1;
	
	do{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");
	
		cout << GREEN << "-----------" << YELLOW << " CIFRA DE CÉSAR " << GREEN << "-----------" << WHITE << endl << endl; 
	
		cout << "(1) Codificar frase\n";
		cout << "(2) Decodificar frase\n";
		cout << "(3) Codificar texto\n";
		cout << "(4) Decodificar texto\n";
		cout << "(9) Sair\n\n";
		
	
		cout << "Escolha: ";
		cin >> esc;
	
		switch (esc){
		
			case 1:
			
				system("cls");
			
				cout << GREEN << "-----------" << YELLOW << " CODIFICADOR DE FRASES " << GREEN << "-----------" << WHITE << endl << endl; 
					
				cout << "Digite a frase: ";
			
				//limpar buffer do teclado (ou algo do tipo ai) (é pra ele nao pular o fgets por causa do ENTER)
				getchar();
			
				//Função recomendada para puxar as strings
				fgets(frase, MAX, stdin);
			
				codificador(frase);
			
				break;
			
			case 2:
			
				system("cls");
			
				cout << GREEN << "-----------" << YELLOW << " DECODIFICADOR DE FRASES " << GREEN << "-----------" << WHITE << endl << endl; 
			
				cout << "Digite a frase: ";
			
				//limpar buffer do teclado (ou algo do tipo ai) (é pra ele nao pular o fgets por causa do ENTER)
				getchar();
			
				//Função recomendada para puxar as strings
				fgets(frase, MAX, stdin);
			
				decodificador(frase);
			
				break;
				
			case 3:
				
				system("cls");
				
				cout << GREEN << "---------------------------------" << YELLOW << " CODIFICADOR DE TEXTO " << GREEN << "---------------------------------" << WHITE << endl << endl; 
				
				cout << "\nColoque o texto desejado em bruto.txt e ";
				
				//abrir o arquivo e ler
				arq = fopen("bruto.txt", "r");
				
					system("pause");
					
					//caso ele esteja vazio
					if (arq == NULL){
					
						cout << RED << "\nDeu ruim no arquivo ai meu chapa, vamos criar um novo\n\n" << WHITE;
						
						//Criando o arquivo
						arq = fopen("bruto.txt", "w");
						
						fclose(arq);
					
						system("pause");
						
						break;
					
					}
					
					//zerar a variavel responsavel por armazenar o texto todo
					strcpy (texto, "");	
					
					//enquanto tiver coisa no txt ele continua
					while(fgets(linha, MAX, arq) != NULL) {
						
						//concatenação das strings	
						strcat(texto, linha);
							
					}
					
					fclose(arq);
				
				//flag para gravar no .txt	
				l = 1;
							
				codificador(texto);
						
				break;
			
			case 4:
				
				system("cls");
				
				cout << GREEN << "---------------------------------" << YELLOW << " DECODIFICADOR DE TEXTO " << GREEN << "---------------------------------" << WHITE << endl << endl; 
				
				cout << "\nColoque o texto desejado em Codificado.txt e ";
				
				system("pause");
				
				//abrir o arquivo e ler
				arq = fopen("Codificado.txt", "r");
					
					//caso ele esteja vazio
					if (arq == NULL){
					
						cout << RED << "\nDeu ruim no arquivo ai meu chapa, vamos criar um novo\n\n" << WHITE;
					
						//Criando o arquivo
						arq = fopen("Codificado.txt", "w");
						
						fclose(arq);
							
						system("pause");
						
						break;
					
					}
					
					//zerar a variavel responsavel por armazenar o texto todo
					strcpy (texto, "");	
					
					//enquanto tiver coisa no txt ele continua
					while(fgets(linha, MAX, arq) != NULL) {
						
						//concatenação das strings	
						strcat(texto, linha);
							
					}
					
				fclose(arq);
				
				l = 1;
					
				decodificador(texto);
				
				break;
				
		
			//caso de saída	
			case 9:
			
				return 0;
		
			//caso nao coloque nada com nada
			default:
			
				cout << RED << "\nColoque algo decente por favor\n\n" << WHITE;
			
				system("pause");
		}
		
	//só sai se apertar 9	
	}while (esc != 9);
	
	return 0;
}
