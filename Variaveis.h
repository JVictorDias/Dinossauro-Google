


    PIG_Cor     Cores[8] = {CINZA, AMARELO, VERDE, VERMELHO, AZUL, CIANO, LARANJA, ROXO};

    Dinossauro  Dinossauros[POPULACAO_TAMANHO];
    int         QuantidadeDinossauros = 0;

    Chao        chao[CHAO_QUANTIDADE];
    Montanha    montanha[MONTANHA_QUANTIDADE];
    Nuvem       nuvem[NUVEM_QUANTIDADE];
    Grafico     grafico;
    Dinossauro* MelhorDinossauro;

    Obstaculo   obstaculo[MAX_OBSTACULOS];
    Obstaculo   obstaculosModelo[20000];

    int         Fonte, FonteVermelha, FonteAzul;
    double      VELOCIDADE;
    int         TimerGeral = 0;
    double      Periodo = 0.005;
    double      DistanciaRecorde, DistanciaAtual;

    int         DinossaurosMortos;
    int         ObstaculoDaVez = 1;
    int         Geracao;
    int         DesenharTela = 1;

