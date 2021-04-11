



void InicializarChao()
{
    for(int i=0; i<CHAO_QUANTIDADE; i++)
    {
        chao[i].sprite = oSprite();
        chao[i].X = i*60.0;
        chao[i].Y = 25.0;
    }
}

void InicializarMontanhas()
{
    for(int i=0; i<MONTANHA_QUANTIDADE; i++)
    {
        for(int j=0; j<2; j++)
        {
            montanha[i].X[j] = LARG_TELA/2.0 + LARG_TELA*(j);
            montanha[i].Y[j] = 90;

            montanha[i].sprite[j] = getMontanhaSprite(i*10 + (j+1));
        }
    }
}

void InicializarNuvens()
{
    for(int i=0; i<NUVEM_QUANTIDADE; i++)
    {
        nuvem[i].X = -1;
        nuvem[i].Y = -1;
        nuvem[i].sprite = getNuvemSprite();
    }

    for(int i=0; i<NUVEM_QUANTIDADE; i++)
    {
        double X = (rand()%1100)+50;
        double Y = (rand()%140)+100;
        if(existeNuvem(X, Y) == 0)
        {
            nuvem[i].X = X;
            nuvem[i].Y = Y;
        }
        else
        {
            i--;
        }
    }
}

void InicializarObstaculos()
{
    ObstaculoDaVez = 0;

    for(int i=0; i<MAX_OBSTACULOS; i++)
    {
        getNextObstaculo(&obstaculo[i], ObstaculoDaVez);
    }
}

void InicializarDinossauro(int Indice, double* DNA, double X, double Y)
{
    Dinossauros[Indice].Estado = 0;
    Dinossauros[Indice].X = X;
    Dinossauros[Indice].Y = Y;
    Dinossauros[Indice].Frame = 0;
    Dinossauros[Indice].SpriteAtual = 0;
    Dinossauros[Indice].FrameAviao = 0;
    if(Dinossauros[Indice].ResetarFitness == 1)
    {
        Dinossauros[Indice].Fitness = 0;
    }
    else
    {
        Dinossauros[Indice].Estado = 3;
        DinossaurosMortos++;
    }

    if(DNA == NULL)     /// Inicializa aleatoriamente
    {
        for(int i=0; i<Dinossauros[Indice].TamanhoDNA; i++)
        {
            Dinossauros[Indice].DNA[i] = getRandomValue();
        }
    }
    else                /// Inicializa com o DNA passado pelo parametro
    {
        for(int i=0; i<Dinossauros[Indice].TamanhoDNA; i++)
        {
            Dinossauros[Indice].DNA[i] = DNA[i];
        }
    }

    RNA_CopiarVetorParaCamadas(Dinossauros[Indice].Cerebro, Dinossauros[Indice].DNA);

    Dinossauros[Indice].AviaoCooldown = 0;
    Dinossauros[Indice].AviaoDeslocamento = 0;

    ReiniciarTimer(Dinossauros[Indice].TimerFrame);
    ReiniciarTimer(Dinossauros[Indice].TimerFrameAviao);
}

void InicializarGrafico()
{
    for(int i=0; i<LARG_GRAFICO; i++)
    {
        grafico.MediaFitness[i] = 0;
        grafico.MelhorFitness[i] = 0;
    }
}
