

int existeNuvem(double X, double Y)
{
    for(int i=0; i<NUVEM_QUANTIDADE; i++)
    {
        if(DistanciaEntrePontos(X, Y, nuvem[i].X, nuvem[i].Y) < 46)
        {
            return 1;
        }
    }
    return 0;
}

double getRandomValue()
{
    return (rand()%20001/10.0) - 1000.0;
    //return (rand()%201/10.0) - 10.0;
    //return (rand()%2001/1000.0) - 1.0;
    //return (rand()%2001/10000.0) - 0.1;

    //return rand()%3 - 1;
}

void getNextObstaculo(Obstaculo* obs, int Indice)
{
    obs->X = obstaculosModelo[Indice].X;
    obs->Y = obstaculosModelo[Indice].Y;
    obs->Tipo = obstaculosModelo[Indice].Tipo;

    if(obs->Tipo == PASSARO_CODIGO_TIPO)
    {
        obs->sprite[0] = getObstaculosSprite(obs->Tipo, 0);
        obs->sprite[1] = getObstaculosSprite(obs->Tipo, 1);
    }
    else
    {
        obs->sprite[0] = getObstaculosSprite(obs->Tipo, 0);
        obs->sprite[1] = getObstaculosSprite(obs->Tipo, 0);
    }
    obs->FrameAtual = 0;
    ReiniciarTimer(obs->TimerFrames);

    ObstaculoDaVez++;
}

void SalvarRedeArquivo()
{
    double Maior = 0;
    int Indice = 0;
    for(int i=0; i<POPULACAO_TAMANHO; i++)
    {
        if(Dinossauros[i].Fitness > Maior)
        {
            Maior = Dinossauros[i].Fitness;
            Indice = i;
        }
    }

    char String[1000];
    sprintf(String, "redes\\%.2f - [%d,%d,%d,%d]",
            DistanciaRecorde,
            DINO_BRAIN_QTD_LAYERS,
            DINO_BRAIN_QTD_INPUT,
            DINO_BRAIN_QTD_HIDE,
            DINO_BRAIN_QTD_OUTPUT);

    FILE* f = fopen(String,"wb");
    fwrite(&Dinossauros[Indice].TamanhoDNA,  1,                              sizeof(int), f);
    fwrite(Dinossauros[Indice].DNA,         Dinossauros[Indice].TamanhoDNA, sizeof(double), f);
    fclose(f);

}

void VerificarTeclas()
{
    if(MODO_JOGO != 1)
    {
        if(PIG_Tecla == TECLA_BAIXO)
        {
            Periodo = Periodo/2.0;
        }
        if(PIG_Tecla == TECLA_CIMA)
        {
            Periodo = Periodo*2.0;
        }
    }

    if(PIG_Tecla == TECLA_ESC)
    {
        DesenharTela = -DesenharTela;
    }
}

int ProcurarProximoObstaculo(double X)
{
    int Indice = 0;
    double Menor = 999999;
    int Largura;

    for(int i=0; i<MAX_OBSTACULOS; i++)
    {
        Largura = obstaculo[i].sprite[obstaculo[i].FrameAtual]->Largura;

        if(obstaculo[i].X < Menor && obstaculo[i].X + Largura > X)
        {
            Menor = obstaculo[i].X;
            Indice = i;
        }
    }

    return Indice;
}


