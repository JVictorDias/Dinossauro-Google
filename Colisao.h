
int verificarColisao(   double X1, double Y1, double Larg1, double Alt1,
                        double X2, double Y2, double Larg2, double Alt2)
{
    if(X1 + Larg1 <= X2)
    {
        return 0;
    }
    if(X1 >= X2 + Larg2)
    {
        return 0;
    }
    if(Y1 + Alt1 <= Y2)
    {
        return 0;
    }
    if(Y1 >= Y2 + Alt2)
    {
        return 0;
    }
    return 1;
}

void AplicarColisao()
{
    int IndiceObstaculo;
    double XObstaculo, YObstaculo, AlturaObstaculo, LarguraObstaculo;
    double DinoX, DinoY, DinoLarg, DinoAlt;
    int FatorDeCorrecaoHorizontal = 7;
    int FatorDeCorrecaoVertical = 5;

    for(int i=0; i<QuantidadeDinossauros; i++)
    {
        if(Dinossauros[i].Estado != 3)      /// MORTO
        {
            IndiceObstaculo = ProcurarProximoObstaculo(Dinossauros[i].X);

            XObstaculo = obstaculo[IndiceObstaculo].X;
            YObstaculo = obstaculo[IndiceObstaculo].Y;
            AlturaObstaculo = obstaculo[IndiceObstaculo].sprite[obstaculo[IndiceObstaculo].FrameAtual]->Altura;
            LarguraObstaculo = obstaculo[IndiceObstaculo].sprite[obstaculo[IndiceObstaculo].FrameAtual]->Largura;

            DinoX = Dinossauros[i].X + FatorDeCorrecaoHorizontal;
            DinoY = Dinossauros[i].Y + FatorDeCorrecaoVertical;
            DinoLarg = Dinossauros[i].sprite[Dinossauros[i].SpriteAtual].Largura - 2*FatorDeCorrecaoHorizontal;
            DinoAlt  = Dinossauros[i].sprite[Dinossauros[i].SpriteAtual].Altura  - 2*FatorDeCorrecaoVertical;

            if(verificarColisao(DinoX,      DinoY,      DinoLarg,           DinoAlt,
                                XObstaculo, YObstaculo, LarguraObstaculo,   AlturaObstaculo) == 1)
            {
                Dinossauros[i].Estado = 3;
                DinossaurosMortos = DinossaurosMortos + 1;
                //system("pause");
            }
        }
    }
}

