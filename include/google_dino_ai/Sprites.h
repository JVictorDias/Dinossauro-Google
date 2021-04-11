#include "Definicoes.h"

#define OBSTACULOS_SPRITE_QUANTIDADE    8

typedef struct sprite
{
    int Largura, Altura;
    int Objeto;

}   Sprite;

    Sprite SpriteObstaculo[OBSTACULOS_SPRITE_QUANTIDADE];
    Sprite SpriteAviao[2];

    int SpriteNeuronDesativado;
    int SpriteNeuronAtivado;
    int SpriteLuz;
    int SpriteSeta;
    static int num_of_calls;


void InicializarSpriteAviao()
{
    char String[1000];

    for(int i=0; i<2; i++)
    {
        sprintf(String, GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/aviao%d.bmp", i);
        SpriteAviao[i].Objeto = CriarSprite(String);
        SpriteAviao[i].Largura = 70;
        SpriteAviao[i].Altura = 37;
    }
}

void InicializarSpritesObstaculos()
{
    int i;
    int LarguraObstaculos[OBSTACULOS_SPRITE_QUANTIDADE] = {32,23,15,49,73, 42,42, 810};
    int AlturaObstaculos[OBSTACULOS_SPRITE_QUANTIDADE]  = {33,46,33,33,47, 36,36, 31};

    char String[1000];

    for(i=0; i<OBSTACULOS_SPRITE_QUANTIDADE-1; i++)
    {

        sprintf(String, GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/obs%d.bmp", i);
        SpriteObstaculo[i].Objeto = CriarSprite(String);
        SpriteObstaculo[i].Largura = LarguraObstaculos[i];
        SpriteObstaculo[i].Altura = AlturaObstaculos[i];
    }
    SpriteObstaculo[i].Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/obs7.png");
    SpriteObstaculo[i].Largura = LarguraObstaculos[i];
    SpriteObstaculo[i].Altura = AlturaObstaculos[i];
}

void InicializarSprites()
{
    InicializarSpritesObstaculos();
    InicializarSpriteAviao();

    SpriteNeuronDesativado = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/neuronio7.png");
    DefinirColoracao(SpriteNeuronDesativado, PRETO);
    SpriteNeuronAtivado = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/neuronio7.png");
    DefinirColoracao(SpriteNeuronAtivado, BRANCO);
    SpriteLuz = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/luz.png");

    SpriteSeta = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/seta2.png");
    DefinirColoracao(SpriteSeta, PRETO);
}

Sprite getMontanhaSprite(int codigo)
{
    Sprite sprite;

    sprite.Largura = 1366;
    sprite.Altura = 180;

    switch(codigo)
    {
        case 1:
        {
            sprite.Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/fundo0.bmp");
        }   break;
        case 2:
        {
            sprite.Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/fundo1.bmp");
        }   break;
        case 11:
        {
            sprite.Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/fundo2.bmp");
        }   break;
        case 12:
        {
            sprite.Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/fundo3.bmp");
        }   break;
        case 21:
        {
            sprite.Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/fundo4.bmp");
        }   break;
        case 22:
        {
            sprite.Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/fundo5.bmp");
        }   break;
    }

    return sprite;
}

Sprite oSprite()
{
    static int cont = 0;
    char String[1000];
    int Indice;
    Sprite sprite;

    if(cont == 4)
    {
        Indice = rand()%2 + 4;
        cont = 0;

    }
    else
    {
        Indice = rand()%4;
        cont = cont + 1;
    }

    sprintf(String, GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/chao%d.bmp", Indice);
    sprite.Objeto = CriarSprite(String);

    static int num_calls = 0;
    std::cout << "oSprite() call:" <<num_of_calls++ << "\n";
    // r();

    sprite.Largura = 60;
    sprite.Altura = 12;

    return sprite;
}

Sprite getDinossauroSprite(int Indice, PIG_Cor cor)
{
    static int num_calls = 0;
    int LarguraFramesDino[10] = {40,40,55,55,40,40,40,40,39,39};
    int AlturaFramesDino[10] = {43,43,25,26,43,43,43,43,37,37};
    char String[1000];
    Sprite sprite;

    sprintf(String, GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/dino%d.bmp", Indice);
    sprite.Objeto = CriarSprite(String);
    std::cout << "getDinossauroSprite() call:" <<num_calls++ << "\n\n";

    sprite.Largura = LarguraFramesDino[Indice];
    sprite.Altura = AlturaFramesDino[Indice];

    DefinirColoracao(sprite.Objeto, cor);

    return sprite;
}

Sprite* getObstaculosSprite(int Tipo, int Frame)
{
    if(Tipo == PASSARO_CODIGO_TIPO)
    {
        if(Frame == 0)
        {
            return &SpriteObstaculo[5];
        }
        else
        {
            return &SpriteObstaculo[6];
        }
    }
    else
    {
        if(Tipo == ESPINHO_CODIGO_TIPO)
        {
            return &SpriteObstaculo[7];
        }
        else
        {
            return &SpriteObstaculo[Tipo];
        }
    }
}

Sprite getNuvemSprite()
{
    Sprite sprite;

    sprite.Objeto = CriarSprite(GOOGLE_DINO_AI_RESOURCES_PATH"/imagens/nuvem.bmp");
    sprite.Largura = 46;
    sprite.Altura = 13;

    return sprite;
}
