

void MovimentarChao()
{
    for(int i=0; i<CHAO_QUANTIDADE; i++)
    {
        chao[i].X = chao[i].X + VELOCIDADE;

        if(chao[i].X + chao[i].sprite.Largura/2.0 < 0)
        {
            chao[i].X = chao[i].X + chao[i].sprite.Largura*(CHAO_QUANTIDADE);
        }
    }
}

void MovimentarMontanhas()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            montanha[i].X[j] = montanha[i].X[j] + VELOCIDADE*((i*0.02) + 0.01);

            if(montanha[i].X[j] < -LARG_TELA/2)
            {
                montanha[i].X[j] = montanha[i].X[j] + 2*LARG_TELA;
            }
        }
    }
}

void MovimentarNuvem()
{
    for(int i=0; i<NUVEM_QUANTIDADE; i++)
    {
        nuvem[i].X = nuvem[i].X + VELOCIDADE*0.01;
        if(nuvem[i].X < -23.0)
        {
            nuvem[i].X = nuvem[i].X + LARG_TELA + 46.0;
        }
    }
}

void MovimentarObstaculos()
{
    int Largura;

    for(int i=0; i<MAX_OBSTACULOS; i++)
    {
        obstaculo[i].X = obstaculo[i].X + VELOCIDADE;
        Largura = obstaculo[i].sprite[0]->Largura;

        if(obstaculo[i].X + Largura < -10)
        {
            getNextObstaculo(&obstaculo[i], ObstaculoDaVez);
            obstaculo[i].X = obstaculo[i].X - DistanciaAtual;
        }
    }
}

void MovimentarDinossauros()
{
    for(int i=0; i<QuantidadeDinossauros; i++)
    {
        if(Dinossauros[i].Estado == 3)  /// MUERTO
        {
            Dinossauros[i].X = Dinossauros[i].X + VELOCIDADE;
        }
        else
        {
            if(Dinossauros[i].Estado == 0 || Dinossauros[i].Estado == 1)
            {
                Dinossauros[i].Fitness = Dinossauros[i].Fitness + 2.0;
            }
            else
            {
                Dinossauros[i].Fitness = Dinossauros[i].Fitness + 1.0;
            }
        }
    }
}


