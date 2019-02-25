
#define LARG_GRAFICO            600
#define CHAO_QUANTIDADE         30
#define MONTANHA_QUANTIDADE     3
#define NUVEM_QUANTIDADE        15

#define QTD_SPRITE_CACTUS       6
#define MAX_OBSTACULOS          7



typedef struct dinossauro
{
    double X, Y;
    double VelocidadeY;
    int Frame;
    int SpriteAtual;
    int Estado;
    Sprite sprite[10];
    int TimerFrame;
    int ResetarFitness;

    int FrameAviao;
    int TimerFrameAviao;
    double AviaoDeslocamento;
    double AviaoCooldown;

    int TamanhoDNA;
    double* DNA;
    double Fitness;

    RedeNeural* Cerebro;

}   Dinossauro;

typedef struct obstaculo
{
    double X, Y;
    int Tipo;
    Sprite* sprite[2];
    int TimerFrames;
    int FrameAtual;

}   Obstaculo;

typedef struct chao
{
    double X, Y;
    Sprite sprite;

}   Chao;

typedef struct montanha
{
    double X[2], Y[2];
    Sprite sprite[2];

}   Montanha;

typedef struct nuvem
{
    double X, Y;
    Sprite sprite;

}   Nuvem;

typedef struct grafico
{
    double MediaFitness[LARG_GRAFICO];
    double MelhorFitness[LARG_GRAFICO];

}   Grafico;






