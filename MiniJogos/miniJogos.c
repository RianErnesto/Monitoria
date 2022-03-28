// Inclusão de Bibliotecas
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Variável para monitorar caso o usuário queira continuar jogando ou não
int continuarJogo;

// Função destinada a verificar se o usuário deseja continuar jogando
int desejaContinuar() {
    printf("Deseja continuar jogando?\n1 - Sim\n2 - Voltar para o menu\n\n");
    printf("Resposta: ");
    scanf("%d", &continuarJogo);

    system("cls");

    return continuarJogo;
}

// Coloca o menu dos jogos na tela do usuário
void menuInicial() {
    printf("=============== BEM VINDO AO RIAN MINI GAMES =================\n\n");

    printf("1 - Perguntas e Respostas\n2 - Adivinhe o n�mero\n3 - Olho de cobra\n4 - Sair\n\nEscolha o jogo: ");
}

// Coloca uma mensagem de saída do jogo na tela do usuário
void mensagemSairDoJogo() {
    printf("Poxa, que pena, at� mais !!");
}

// Coloca uma mensagem de escolha inválida na tela do usuário
void mensagemEscolhaInvalida() {
    printf("Escolha um numero v�lido !\n\n");
}

// JOGO PERGUNTAS E RESPOSTAS

// Variável constante da quantidade de perguntas que o jogo terá
#define QUANTIDADE_PERGUNTAS 3

// Variável que pega o valor digitado pelo usuário na hora de colocar a resposta da pergunta
int escolhaPerguntasERespostas;
// Variável referente a alternativa correta de cada pergunta
int escolhaCorreta;

// Coloca o menu do jogo Perguntas e Respostas
void menuPerguntasERespostas() {
    printf("---------------- Perguntas e Respostas -------------------\n\n");

    printf("Esse � um jogo onde o computador faz uma pergunta e apresenta 3 alternativas e pede para o");
    printf(" usu�rio escolher qual � a correta. Ao escolher a alternativa o computador deve dizer se est� correta");
    printf(" ou errada, caso esteja errada o computador deve mostrar a resposta correta.\n");

    printf("Esse mini jogo possui um total de 3 perguntas e a ordem delas n�o precisa ser diferente"); 
    printf(" para cada rodada, o mesmo vale para suas respostas.\n");

    printf("Ao terminar o jogo o jogador pode escolher entre jogar de novo ou voltar para o menu.\n\n\n");
}

// Função que checa se a alternativa escolhida pelo usuário é correta
void verificarSeCorreto(int escolha, int escolhaCorreta) {
    if(escolha == escolhaCorreta) 
    	printf("\nParab�ns, voc� acertou a resposta !!\n\n\n");
        
    else 
        printf("\nQue pena, voce errou a resposta. A alternativa correta era a %d�\n\n\n", escolhaCorreta);;
}

// Printa na tela do usuário as alternativas existentes da pergunta
void alternativas(char primeiraAlternativa[], char segundaAlternativa[], char terceiraAlternativa[]) {
    printf("1 - %s\n", primeiraAlternativa);
    printf("2 - %s\n", segundaAlternativa);
    printf("3 - %s\n\n", terceiraAlternativa);

    printf("Escolha: ");
}

 
// Função que guarda as configurações da questão, 
// chama a função que printa as alternativas, e pega a alternativa escolhida pelo usuário
// e chama a função pra fazer a verificação 
void primeiraPergunta() {
    escolhaCorreta = 3;

    char primeiraAlternativaErrada[] = "Bryan";
    char segundaAlternativaErrada[] = "Ryan";
    char alternativaCorreta[] = "Rian";
    
    printf("Qual meu nome?\n\n");
    alternativas(primeiraAlternativaErrada, segundaAlternativaErrada, alternativaCorreta);

    scanf("%d", &escolhaPerguntasERespostas);
    verificarSeCorreto(escolhaPerguntasERespostas, escolhaCorreta);
}

void segundaPergunta() {
    escolhaCorreta = 1;

    char primeiraAlternativaErrada[] = "21";
    char segundaAlternativaErrada[] = "22";
    char alternativaCorreta[] = "20";
    
    printf("Qual minha idade?\n\n");
    alternativas(alternativaCorreta, primeiraAlternativaErrada, segundaAlternativaErrada);

    scanf("%d", &escolhaPerguntasERespostas);
    verificarSeCorreto(escolhaPerguntasERespostas, escolhaCorreta);
}

void terceiraPergunta() {
    escolhaCorreta = 1;

    char primeiraAlternativaErrada[] = "9�";
    char segundaAlternativaErrada[] = "5�";
    char alternativaCorreta[] = "7�";
    
    printf("Em qual per�odo estou?\n\n");
    alternativas(alternativaCorreta, primeiraAlternativaErrada, segundaAlternativaErrada);

    scanf("%d", &escolhaPerguntasERespostas);
    verificarSeCorreto(escolhaPerguntasERespostas, escolhaCorreta);
}

// Função principal do jogo que chama as perguntas e 
// depois chama a função que checa se o usuário deseja continuar jogando
void jogoPerguntasERespostas() {
    while(1) {
        menuPerguntasERespostas();

        primeiraPergunta();
        segundaPergunta();
        terceiraPergunta();

        if(desejaContinuar() != 1) 
            break;
    }
}

// JOGO ADIVINHE O NÚMERO

// Guarda a quantidade de tentativas que o jogador tem
#define QUANTIDADE_TENTATIVAS 5
// Define o valor máximo que a máquina pode pensar
#define VALOR_MAXIMO 10

// Guardam os respectivos valores da máquina e do usuário
int numeroMaquina;
int numeroUsuario;

// Coloca o menu do jogo Adivinhe o Número
void menuAdivinheONumero() {
    printf("--------------- Adivinhe o N�mero --------------\n\n");

    printf("A ideia desse jogo � tentar adivinhar qual o n�mero que o computador est� 'pensando' entre 0 e %d.", VALOR_MAXIMO);
    printf(" O computador vai perguntar para o usu�rio digitar um n�mero e vai dizer se esse numero � maior ou ");
    printf("menor do que o n�mero que o computador est� 'pensando'. O jogo deve acabar depois de 5 tentativas ");
    printf("(nesse caso o jogador perdeu) ou ao acertar o n�mero do computador (nesse caso o jogador ganhou).\n");
    
    printf("Ao terminar o jogo o jogador pode escolher entre jogar de novo ou voltar para o menu.\n\n\n");
}

// Verifica em qual intervalo do número pensado pela máquina se encontra o número do jogador
int checarCondicao() {
    if(numeroUsuario == numeroMaquina) {
        printf("Voc� Acertou !!\n\n\n");
        return 1;
    }
    else if(numeroUsuario < numeroMaquina) {
        printf("Seu n�mero foi menor que o da m�quina\n\n");
    }
    else {
        printf("Seu n�mero foi maior que o da m�quina.\n\n");
    }
    return 0;
}

// Pega o número que o usuário tiver dentro do limite de tentativa e depois checa a condição de vitório
void chutesDoUsuario() {
    int i;
    for(i = 0; i < QUANTIDADE_TENTATIVAS; i++) {
        printf("Tentativa %d: ", i + 1);
        scanf("%d", &numeroUsuario);
        if(checarCondicao() == 1) break;
    }
    if(i == QUANTIDADE_TENTATIVAS) {
        printf("Quantidade de tentativas esgotada!\n");
        printf("O n�mero que a m�quina estava pensando era ... %d\n\n\n", numeroMaquina);
    }
}

// Função principal do jogo que chama a função de escolher um número da máquina e 
// depois chama a função que checa se o usuário deseja continuar jogando
void jogoAdivinheONumero() {
    srand(time(0));

    while(1) {
        menuAdivinheONumero();

        numeroMaquina = (rand() % VALOR_MAXIMO) + 1;
        chutesDoUsuario();

        if(desejaContinuar() != 1) 
            break;
    }
}

// JOGO OLHO DE COBRA

// Guarda qual o máximo de pontuação que um usuário pode conquistar
#define PONTUACAO_MAXIMA 50

// Cria um struct do tipo Jogador que salva informações de nome e pontuação de cada jogador
struct Jogador {
    char nome[50];
    int pontuacao;
};
typedef struct Jogador Jogador;

// Inicia um array do tipo Jogador, para armezar os dois jogadores que jogarão o jogo
Jogador jogadores[2];
// Variáveis que guardam os valores do dado e somam
int dado1, dado2, somaDados;
// Variável usada para finalizar ou não o jogo
int vitoria = 0;

// Coloca o menu do jogo Olho de Cobra
void menuOlhoDeCobra() {
    printf("------------- Jogo Olho de Cobra ---------------\n\n");

    printf("Esse jogo precisa de duas pessoas para jogar, os jogadores competir�o entre si para tentar chegar ");
    printf("em 50 pontos.");
    printf(" O computador vai pedir o nome dos dois jogadores e escolher quem vai jogar primeiro.\n");

    printf("O turno de um jogador tem a seguinte l�gica:\n");

    printf("O computador vai jogar dois dados e a soma dos valores � adicionado para a pontuacao do jogador, ");
    printf("O jogador pode escolher jogar os dados novamente ou finalizar seu turno.\n");

    printf("\t- Ao escolher finalizar o turno, o jogador salva todos os pontos que ganhou durante seu turno e ");
    printf("passa a vez para o outro jogador.\n");

    printf("Ao escolher jogar os dados de novo, a soma desses novos valores ser� acrescentada a sua pontua��o, ");
    printf("por�m o jogador tem dois riscos! Se em um dado cair o valor 1, o jogador perde todos os pontos acumulados no ");
    printf("turno e perde sua vez. Se os dois dados ca�rem 1, o jogador perde todos os pontos que ganhou durante o jogo, ");
    printf("voltando para zero, e perde sua vez.\n\n\n");
}

// Função que pega os nomes dos jogadores e reseta sua pontuação
void nomesJogadores() {
    fflush(stdin);

    printf("Nome do Primeiro Jogador: ");
    gets(jogadores[0].nome);

    printf("Nome do Segundo Jogador: ");
    gets(jogadores[1].nome);

    jogadores[0].pontuacao = 0;
    jogadores[1].pontuacao = 0;
}

// Função que analisa as condições impostas pelo comando e aplica as correções necessárias
int analisarCondicoes(int jogadorTurno) {
    if(dado1 == 1 && dado2 == 1) {
        printf("Voce perdeu toda a sua pontua��o e passou a vez !\n\n\n");
        jogadores[jogadorTurno].pontuacao = 0;
        return 1;
    }
    else if(dado1 == 1 || dado2 == 1) {
        printf("Voce perdeu a pontuacao obtida na rodada e passou a vez.\n\n\n");
        return 1;
    }
    return 0;
}

// Faz a checagem se algum jogador alcançou a pontuação máxima
int analisarVitoria(int jogadorTurno) {
    if(jogadores[jogadorTurno].pontuacao + somaDados >= PONTUACAO_MAXIMA) {
        printf("Parab�ns %s, voc� venceu o jogo !!\n\n\n", jogadores[jogadorTurno].nome);
        vitoria = 1;
        return 1;
    }
    return 0;
}

// Função usada para gerar randomicamente os valores dos dados e somá-los
int jogarDados() {
    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;

    printf("Valor do dado 1: %d\n", dado1);
    printf("Valor do dado 2: %d\n\n", dado2);
    somaDados = dado1 + dado2;
}

// Função em que o jogador do turno joga, jogando os dados e checando as condições
void jogadorJoga(int jogadorTurno) {
    int escolhaJogador;
    int passouAVez = 0;

    while(1) {
    	system("cls");
    	printf("Turno do jogador %s\n\n", jogadores[jogadorTurno].nome);
    	printf("Pontua��o do Jogador: %d\n\n", jogadores[jogadorTurno].pontuacao);
        jogarDados();

        printf("Pontua��o a ganhar : %d\n\n", somaDados);

        if(analisarCondicoes(jogadorTurno) || analisarVitoria(jogadorTurno)) 
            break;

		jogadores[jogadorTurno].pontuacao += somaDados;
		printf("Nova pontua��o : %d\n\n", jogadores[jogadorTurno].pontuacao);

        printf("1 - Jogar os dados novamente\n2 - Finalizar o turno\n\n");
        printf("Escolha: ");
        scanf("%d", &escolhaJogador);

        if(escolhaJogador != 1)
            break;
    }

}

// Função principal do jogo que roda em loop o jogo até alguem ganhar, e
// depois chama a função que checa se o usuário deseja continuar jogando
void jogoOlhoDeCobra() {
    srand(time(0));
    while(1) {
        vitoria = 0;
        
        menuOlhoDeCobra();
        system("pause");
        system("cls");
        
        nomesJogadores();
        int jogadorTurno = rand() % 2;

        while(!vitoria) {
            jogadorJoga(jogadorTurno);

            jogadorTurno++;
            if(jogadorTurno == 2)
                jogadorTurno = 0;
                
            system("pause");
        }

        if(desejaContinuar() != 1) 
            break;
    }
}

// Função principal do projeto que fornece as escolhas de jogos para o usuário e chama 
// as funções para direcionar pra cada jogo
void main() {
	setlocale(LC_ALL, "Portuguese");
    int escolha;

    while(escolha != 4) {
        menuInicial();
        scanf("%d", &escolha);
        printf("%d", escolha);

        switch(escolha) {
            case 1:
            	system("cls");
                jogoPerguntasERespostas();
            break;

            case 2:
                system("cls");
                jogoAdivinheONumero();
            break;

            case 3:
                system("cls");
                jogoOlhoDeCobra();
            break;

            case 4:
                system("cls");
                mensagemSairDoJogo();
            break;

            default:
                system("cls");
                mensagemEscolhaInvalida();
            break;
        }
    }
}











