

PIG_Cor calcularCor(double Intensidade, PIG_Cor CorBase)
{
    CorBase.r = CorBase.r*Intensidade;
    CorBase.g = CorBase.g*Intensidade;
    CorBase.b = CorBase.b*Intensidade;

    return CorBase;
}

void DesenharRedeNeural(int X, int Y, int Largura, int Altura)
{
    double NeuroEntradaX[DINO_BRAIN_QTD_INPUT];
    double NeuroEntradaY[DINO_BRAIN_QTD_INPUT];
    double NeuroEscondidoX[DINO_BRAIN_QTD_LAYERS][DINO_BRAIN_QTD_HIDE];
    double NeuroEscondidoY[DINO_BRAIN_QTD_LAYERS][DINO_BRAIN_QTD_HIDE];
    double NeuroSaidaX[DINO_BRAIN_QTD_OUTPUT];
    double NeuroSaidaY[DINO_BRAIN_QTD_OUTPUT];

    double Entrada[DINO_BRAIN_QTD_INPUT];
    double XOrigem = X + 325;
    double YOrigem = Y + Altura;
    double LarguraPintura = Largura;
    double AlturaPintura = Altura;
    double TamanhoNeuronio = 20;
    char String[1000];
    int Sprite;
    int qtdEscondidas       = MelhorDinossauro->Cerebro->QuantidadeEscondidas;
    int qtdNeuroEntrada     = MelhorDinossauro->Cerebro->CamadaEntrada.QuantidadeNeuronios;
    int qtdNeuroEscondidas  = MelhorDinossauro->Cerebro->CamadaEscondida[0].QuantidadeNeuronios;
    int qtdNeuroSaida       = MelhorDinossauro->Cerebro->CamadaSaida.QuantidadeNeuronios;

    for(int i=0; i<DINO_BRAIN_QTD_INPUT; i++)
    {
        Entrada[i] = MelhorDinossauro->Cerebro->CamadaEntrada.Neuronios[i].Saida;
    }

    double EscalaAltura = ((double)AlturaPintura)/(double)(qtdNeuroEscondidas-1);
    double EscalaLargura = ((double)LarguraPintura-475)/(double)(qtdEscondidas+1);

    sprintf(String,"[Obst�culo] Distancia: %.2f", Entrada[0]);
    EscreverEsquerda(String, X + 15, YOrigem - 0*EscalaAltura -5, Fonte);

    sprintf(String,"[Obst�culo] Largura: %.2f", Entrada[1]);
    EscreverEsquerda(String, X + 15, YOrigem - 1*EscalaAltura -5, Fonte);

    sprintf(String,"[Obst�culo] Altura: %.2f", Entrada[2]);
    EscreverEsquerda(String, X + 15, YOrigem - 2*EscalaAltura -5, Fonte);

    sprintf(String,"[Obst�culo] Comprimento: %.2f", Entrada[3]);
    EscreverEsquerda(String, X + 15, YOrigem - 3*EscalaAltura -5, Fonte);

    sprintf(String,"[Cen�rio] Velocidade: %.2f", Entrada[4]);
    EscreverEsquerda(String, X + 15, YOrigem - 4*EscalaAltura -5, Fonte);

    sprintf(String,"[Dinossauro] Altura: %.2f", Entrada[5]);
    EscreverEsquerda(String, X + 15, YOrigem - 5*EscalaAltura -5, Fonte);

    double temp = YOrigem - (EscalaAltura*(qtdNeuroEscondidas-2))/2.0 + (EscalaAltura*(qtdNeuroSaida-1))/2.0;

    sprintf(String,"Pular");
    EscreverEsquerda(String, X + Largura - 100, temp - 0*EscalaAltura -5, Fonte);

    sprintf(String,"Abaixar");
    EscreverEsquerda(String, X + Largura - 100, temp - 1*EscalaAltura -5, Fonte);

    if(DINO_BRAIN_QTD_OUTPUT == 3)
    {
        sprintf(String,"Avi�o");
        EscreverEsquerda(String, X + Largura - 100, temp - 2*EscalaAltura -5, Fonte);
    }

    /// Desenhar Conexoes

    for(int i=0; i<qtdNeuroEntrada-1; i++)
    {
        NeuroEntradaX[i] = XOrigem;
        NeuroEntradaY[i] = YOrigem - i*EscalaAltura;
    }

    for(int i=0; i<qtdEscondidas; i++)
    {
        int qtdCamadaAnterior;
        Camada* CamadaAnterior;
        double *XAnterior, *YAnterior;

        if(i == 0)
        {
            qtdCamadaAnterior = qtdNeuroEntrada;
            CamadaAnterior = &MelhorDinossauro->Cerebro->CamadaEntrada;
            XAnterior = NeuroEntradaX;
            YAnterior = NeuroEntradaY;
        }
        else
        {
            qtdCamadaAnterior = qtdNeuroEscondidas;
            CamadaAnterior = &MelhorDinossauro->Cerebro->CamadaEscondida[i-1];
            XAnterior = NeuroEscondidoX[i-1];
            YAnterior = NeuroEscondidoY[i-1];
        }

        for(int j=0; j<qtdNeuroEscondidas-1; j++)
        {
            NeuroEscondidoX[i][j] = XOrigem + (i+1)*EscalaLargura;
            NeuroEscondidoY[i][j] = YOrigem - j*EscalaAltura;

            for(int k=0; k<qtdCamadaAnterior-1; k++)
            {
                double Peso = MelhorDinossauro->Cerebro->CamadaEscondida[i].Neuronios[j].Peso[k];
                double Saida = CamadaAnterior->Neuronios[k].Saida;
                if(Peso*Saida > 0)
                {
                    DesenharLinhaSimples(XAnterior[k],
                                         YAnterior[k],
                                         NeuroEscondidoX[i][j],
                                         NeuroEscondidoY[i][j], VERMELHO);

                }
                else
                {
                    DesenharLinhaSimples(XAnterior[k],
                                         YAnterior[k],
                                         NeuroEscondidoX[i][j],
                                         NeuroEscondidoY[i][j], CINZA_CLARO);
                }
            }
        }

    }

    for(int i=0; i<qtdNeuroSaida; i++)
    {
        int UltimaCamada = MelhorDinossauro->Cerebro->QuantidadeEscondidas-1;
        double temp = YOrigem - (EscalaAltura*(qtdNeuroEscondidas-2))/2.0 + (EscalaAltura*(qtdNeuroSaida-1))/2.0;

        NeuroSaidaX[i] = XOrigem + (qtdEscondidas+1)*EscalaLargura;
        NeuroSaidaY[i] = temp - i*EscalaAltura;

        for(int k=0; k<qtdNeuroEscondidas-1; k++)
        {
            double Peso = MelhorDinossauro->Cerebro->CamadaSaida.Neuronios[i].Peso[k];
            double Saida = MelhorDinossauro->Cerebro->CamadaEscondida[UltimaCamada].Neuronios[k].Saida;

            if(Peso*Saida > 0)
            {
                DesenharLinhaSimples(NeuroEscondidoX[UltimaCamada][k],
                                     NeuroEscondidoY[UltimaCamada][k],
                                     NeuroSaidaX[i],
                                     NeuroSaidaY[i], VERMELHO);


            }
            else
            {
                DesenharLinhaSimples(NeuroEscondidoX[UltimaCamada][k],
                                     NeuroEscondidoY[UltimaCamada][k],
                                     NeuroSaidaX[i],
                                     NeuroSaidaY[i], CINZA_CLARO);
            }
        }
    }

    /// Desenhar Neuronios

    for(int i=0; i<qtdNeuroEntrada-1; i++)
    {
        PIG_Cor cor;
        double Opacidade;

        switch(i)
        {
            case 0:
            {
                Opacidade = fabs(Entrada[0])/800.0;
                cor = calcularCor(Opacidade, BRANCO);
            }   break;
            case 1:
            {
                Opacidade = Entrada[1]/73.0;
                cor = calcularCor(Opacidade, BRANCO);
            }   break;
            case 2:
            {
                Opacidade = Entrada[2]/90.0;
                cor = calcularCor(Opacidade, BRANCO);
            }   break;
            case 3:
            {
                Opacidade = Entrada[3]/47.0;
                cor = calcularCor(Opacidade, BRANCO);
            }   break;
            case 4:
            {
                Opacidade = Entrada[4]/8.0;
                if(Entrada[4] > 8)
                {
                    Opacidade = 1;
                }
                cor = calcularCor(Opacidade, BRANCO);
            }   break;
            case 5:
            {
                Opacidade = Entrada[5]/120.0;
                cor = calcularCor(Opacidade, BRANCO);
            }   break;
        }

        DefinirColoracao(SpriteNeuronAtivado, cor);
        DefinirOpacidade(SpriteLuz, Opacidade*255);

        DesenharSprite(SpriteLuz,
                       NeuroEntradaX[i],
                       NeuroEntradaY[i],
                       3.5*TamanhoNeuronio,
                       3.5*TamanhoNeuronio, 0);

        DesenharSprite(SpriteNeuronAtivado,
                       NeuroEntradaX[i],
                       NeuroEntradaY[i],
                       TamanhoNeuronio,
                       TamanhoNeuronio, 0);

        DefinirOpacidade(SpriteLuz, 255);
        DefinirColoracao(SpriteNeuronAtivado, BRANCO);

        DesenharSprite(SpriteSeta,
                       NeuroEntradaX[i] - 56,
                       NeuroEntradaY[i],
                       64,
                       12, 0);
    }

    for(int i=0; i<qtdEscondidas; i++)
    {

        for(int j=0; j<qtdNeuroEscondidas-1; j++)
        {

            Sprite = SpriteNeuronDesativado;
            double SaidaNeuronio = MelhorDinossauro->Cerebro->CamadaEscondida[i].Neuronios[j].Saida;
            if(SaidaNeuronio > 0)
            {
                Sprite = SpriteNeuronAtivado;
                DesenharSprite( SpriteLuz,
                                NeuroEscondidoX[i][j],
                                NeuroEscondidoY[i][j],
                                3.5*TamanhoNeuronio,
                                3.5*TamanhoNeuronio, 0);
            }

            DesenharSprite(Sprite,
                           NeuroEscondidoX[i][j],
                           NeuroEscondidoY[i][j],
                           TamanhoNeuronio,
                           TamanhoNeuronio, 0);
        }
    }

    for(int i=0; i<qtdNeuroSaida; i++)
    {
        Sprite = SpriteNeuronDesativado;
        double SaidaNeuronio = MelhorDinossauro->Cerebro->CamadaSaida.Neuronios[i].Saida;
        if(SaidaNeuronio > 0.5)
        {
            Sprite = SpriteNeuronAtivado;
            DesenharSprite(SpriteLuz,
                       NeuroSaidaX[i],
                       NeuroSaidaY[i],
                       3.5*TamanhoNeuronio,
                       3.5*TamanhoNeuronio, 0);
        }

        DesenharSprite(Sprite,
                       NeuroSaidaX[i],
                       NeuroSaidaY[i],
                       TamanhoNeuronio,
                       TamanhoNeuronio, 0);
    }


}

void DesenharGrafico(int X, int Y, int Largura, int Altura)
{
    SDL_Point PontosBest[LARG_GRAFICO];
    SDL_Point PontosMedia[LARG_GRAFICO];
    SDL_Point PontosMediaFilhos[LARG_GRAFICO];

    double scala;
    double scalaHorizontal;

    if(BestFitnessGeracao() > BestFitnessEver())
    {
        scala = BestFitnessGeracao()/(double)Altura;
    }
    else
    {
        scala = BestFitnessEver()/(double)Altura;
    }

    if(GeracaoCompleta == 0)
    {
        scalaHorizontal = 0;
    }
    else
    {
        scalaHorizontal = (double)Largura/(double)(GeracaoCompleta);
    }

    for(int i=1; i<11; i++)
    {
        DesenharLinhaSimples(X,
                             Y+i*(Altura/10),
                             X+Largura,
                             Y+i*(Altura/10),
                             CINZA_CLARO);

        DesenharLinhaSimples(X+i*(Largura/10),
                             Y,
                             X+i*(Largura/10),
                             Y+Altura,
                             CINZA_CLARO);
    }

    DesenharLinhaSimples(X, Y, X+Largura, Y,        PRETO);
    DesenharLinhaSimples(X, Y, X,         Y+Altura, PRETO);

    for(int i=0; i<GeracaoCompleta+1; i++)
    {
        int PontoX = X+1+(i*scalaHorizontal);
        double YMedia, YBest;

        if(i == GeracaoCompleta)
        {
            YMedia = Y+1+(int)(MediaFitnessGeracao()/scala);
            YBest = Y+1+(int)(BestFitnessGeracao()/scala);
        }
        else
        {
            YMedia = Y+1+(int)(MediaFitnessPopulacao[i]/scala);
            YBest = Y+1+(int)(BestFitnessPopulacao[i]/scala);
        }

        DesenharPonto(PontoX, YMedia, VERMELHO, 3);
        PontosMedia[i].x = PontoX;
        PontosMedia[i].y = ALT_TELA - YMedia;

        DesenharPonto(PontoX, YBest,  AZUL, 3);
        PontosBest[i].x = PontoX;
        PontosBest[i].y = ALT_TELA - YBest;
    }

    DesenharLinhas(PontosBest, GeracaoCompleta+1, AZUL);
    DesenharLinhas(PontosMedia, GeracaoCompleta+1, VERMELHO);
    //DesenharLinhas(PontosMediaFilhos, GeracaoCompleta, VERDE);
}

void DesenharObstaculos()
{
    for(int i=0; i<MAX_OBSTACULOS; i++)
    {
        DesenharSprite(obstaculo[i].sprite[obstaculo[i].FrameAtual]->Objeto,
                       obstaculo[i].X,
                       obstaculo[i].Y,
                       obstaculo[i].sprite[obstaculo[i].FrameAtual]->Largura,
                       obstaculo[i].sprite[obstaculo[i].FrameAtual]->Altura,
                       0);
    }
}

void DesenharChao()
{
    for(int i=0; i<CHAO_QUANTIDADE; i++)
    {
        DesenharSprite(chao[i].sprite.Objeto,
                       chao[i].X,
                       chao[i].Y,
                       chao[i].sprite.Largura,
                       chao[i].sprite.Altura,
                       0);
    }
}

void DesenharMontanhas()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            DesenharSprite(montanha[i].sprite[j].Objeto,
                           montanha[i].X[j], montanha[i].Y[j],
                           montanha[i].sprite[j].Largura,
                           montanha[i].sprite[j].Altura, 0);
        }
    }
}

void DesenharFundo()
{
    DesenharRetangulo(0,0,ALT_TELA,LARG_TELA, BRANCO);
}

void DesenharNuvens()
{
    for(int i=0; i<NUVEM_QUANTIDADE; i++)
    {
        DesenharSprite(nuvem[i].sprite.Objeto,
                       nuvem[i].X,
                       nuvem[i].Y,
                       nuvem[i].sprite.Largura,
                       nuvem[i].sprite.Altura, 0);
    }
}

void DesenharAviao(int i)
{
    if(Dinossauros[i].Estado == 4)  /// Voando
    {
        DesenharSprite(SpriteAviao[Dinossauros[i].FrameAviao].Objeto,
                       Dinossauros[i].X + 13,
                       Dinossauros[i].Y + 12,
                       SpriteAviao[Dinossauros[i].FrameAviao].Largura,
                       SpriteAviao[Dinossauros[i].FrameAviao].Altura, 0);
    }
}

void DesenharDinossauros()
{
    int Frame, Largura, Altura, Sprite;

    for(int i=0; i<QuantidadeDinossauros; i++)
    {
        Sprite = Dinossauros[i].SpriteAtual;
        Frame = Dinossauros[i].sprite[Sprite].Objeto;
        Largura = Dinossauros[i].sprite[Sprite].Largura;
        Altura = Dinossauros[i].sprite[Sprite].Altura;

        DesenharSprite( Frame,
                        Dinossauros[i].X,
                        Dinossauros[i].Y,
                        Largura,
                        Altura,
                        0);

        DesenharAviao(i);
    }
}




void Desenhar()
{
    int BASE = 360;

    if(DesenharTela == 1)
    {
        IniciarDesenho();

        DesenharFundo();
        DesenharNuvens();
        DesenharMontanhas();
        // r();
        DesenharChao();
        DesenharObstaculos();
        DesenharDinossauros();

        DesenharRedeNeural(665, 360, 700, 350);
        DesenharGrafico(20, 390, LARG_GRAFICO, 350);

        char String[1000];

        sprintf(String,"Gera��o: %d", Geracao);
        EscreverEsquerda(String, 20, BASE, Fonte);

        sprintf(String,"Clock: %f segundo", Periodo);
        EscreverEsquerda(String, 20, BASE-20, Fonte);

        sprintf(String,"Velocidade: %.2f (%.0f pixels por segundo)", fabs(VELOCIDADE), fabs(VELOCIDADE)/Periodo);
        EscreverEsquerda(String, 20, BASE-40, Fonte);

        sprintf(String,"Distancia Recorde:");
        EscreverEsquerda(String, 20, BASE-60, Fonte);

        sprintf(String,"%.0f pixels", DistanciaRecorde);
        EscreverEsquerda(String, 150, BASE-60, FonteAzul);

        sprintf(String,"Distancia Atual:");
        EscreverEsquerda(String, 20, BASE-80, Fonte);

        sprintf(String,"%.0f pixels", DistanciaAtual);
        EscreverEsquerda(String, 150, BASE-80, Fonte);

        // EncerrarDesenho();
    }
}
