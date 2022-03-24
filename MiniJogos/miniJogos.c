#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int continuarJogo;

int desejaContinuar() {
    printf("Deseja continuar jogando?\n1 - Sim\n2 - Voltar para o menu\n\n");
    printf("Resposta: ");
    scanf("%d", &continuarJogo);

    system("cls");

    return continuarJogo;
}

void menuInicial() {
    printf("=============== BEM VINDO AO RIAN MINI GAMES =================\n\n");

    printf("1 - Perguntas e Respostas\n2 - Adivinhe o n�mero\n3 - Olho de cobra\n4 - Sair\n\nEscolha o jogo: ");
}

void mensagemSairDoJogo() {
    printf("Poxa, que pena, at� mais !!");
}

void mensagemEscolhaInvalida() {
    printf("Escolha um numero v�lido !\n\n");
}

// Jogo Perguntas e Respostas

#define QUANTIDADE_PERGUNTAS 3

int escolhaPerguntasERespostas;
int escolhaCorreta;

void menuPerguntasERespostas() {
    printf("---------------- Perguntas e Respostas -------------------\n\n");

    printf("Esse � um jogo onde o computador faz uma pergunta e apresenta 3 alternativas e pede para o");
    printf(" usu�rio escolher qual � a correta. Ao escolher a alternativa o computador deve dizer se est� correta");
    printf(" ou errada, caso esteja errada o computador deve mostrar a resposta correta.\n");

    printf("Esse mini jogo possui um total de 3 perguntas e a ordem delas n�o precisa ser diferente"); 
    printf(" para cada rodada, o mesmo vale para suas respostas.\n");

    printf("Ao terminar o jogo o jogador pode escolher entre jogar de novo ou voltar para o menu.\n\n\n");
}

void verificarSeCorreto(int escolha, int escolhaCorreta) {
    if(escolha == escolhaCorreta) 
    	printf("\nParab�ns, voc� acertou a resposta !!\n\n\n");
        
    else 
        printf("\nQue pena, voce errou a resposta. A alternativa correta era a %d�\n\n\n", escolhaCorreta);;
}

void alternativas(char primeiraAlternativa[], char segundaAlternativa[], char terceiraAlternativa[]) {
    printf("1 - %s\n", primeiraAlternativa);
    printf("2 - %s\n", segundaAlternativa);
    printf("3 - %s\n\n", terceiraAlternativa);

    printf("Escolha: ");
}

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

// Jogo Adivinhe o Numero

#define QUANTIDADE_TENTATIVAS 5
#define VALOR_MAXIMO 10

int numeroMaquina;
int numeroUsuario;

void menuAdivinheONumero() {
    printf("--------------- Adivinhe o N�mero --------------\n\n");

    printf("A ideia desse jogo � tentar adivinhar qual o n�mero que o computador est� 'pensando' entre 0 e %d.", VALOR_MAXIMO);
    printf(" O computador vai perguntar para o usu�rio digitar um n�mero e vai dizer se esse numero � maior ou ");
    printf("menor do que o n�mero que o computador est� 'pensando'. O jogo deve acabar depois de 5 tentativas ");
    printf("(nesse caso o jogador perdeu) ou ao acertar o n�mero do computador (nesse caso o jogador ganhou).\n");
    
    printf("Ao terminar o jogo o jogador pode escolher entre jogar de novo ou voltar para o menu.\n\n\n");
}

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

// Jogo Olho de Cobra

#define PONTUACAO_MAXIMA 50

struct Jogador {
    char nome[50];
    int pontuacao;
};
typedef struct Jogador Jogador;

Jogador jogadores[2];
int dado1, dado2, somaDados;
int vitoria = 0;

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

void nomesJogadores() {
    fflush(stdin);

    printf("Nome do Primeiro Jogador: ");
    gets(jogadores[0].nome);

    printf("Nome do Segundo Jogador: ");
    gets(jogadores[1].nome);

    jogadores[0].pontuacao = 0;
    jogadores[1].pontuacao = 0;
}

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

int analisarVitoria(int jogadorTurno) {
    if(jogadores[jogadorTurno].pontuacao + somaDados >= PONTUACAO_MAXIMA) {
        printf("Parab�ns %s, voc� venceu o jogo !!\n\n\n", jogadores[jogadorTurno].nome);
        vitoria = 1;
        return 1;
    }
    return 0;
}

int jogarDados() {
    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;

    printf("Valor do dado 1: %d\n", dado1);
    printf("Valor do dado 2: %d\n\n", dado2);
    somaDados = dado1 + dado2;
}

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











