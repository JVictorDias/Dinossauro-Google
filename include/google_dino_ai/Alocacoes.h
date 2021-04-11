

void AlocarDinossauro()
{
    static int ControladorCor = 0;
    int Tamanho;

    static int num_calls = 0;
    std::cout << "\nAlocarDinossauro() call:" << num_of_calls++ << "\n";

    for(int i=0; i<10; i++)
    {
        Dinossauros[QuantidadeDinossauros].sprite[i] = getDinossauroSprite(i, Cores[ControladorCor]);
    }

    Dinossauros[QuantidadeDinossauros].TimerFrame       = CriarTimer();
    Dinossauros[QuantidadeDinossauros].TimerFrameAviao  = CriarTimer();
    Dinossauros[QuantidadeDinossauros].ResetarFitness   = 1;

    Dinossauros[QuantidadeDinossauros].Cerebro = RNA_CriarRedeNeural(DINO_BRAIN_QTD_LAYERS,
                                                                     DINO_BRAIN_QTD_INPUT,
                                                                     DINO_BRAIN_QTD_HIDE,
                                                                     DINO_BRAIN_QTD_OUTPUT);

    Tamanho = RNA_QuantidadePesos(Dinossauros[QuantidadeDinossauros].Cerebro);

    Dinossauros[QuantidadeDinossauros].TamanhoDNA = Tamanho;
    Dinossauros[QuantidadeDinossauros].DNA = (double*)malloc(Tamanho*sizeof(double));

    InicializarDinossauro(QuantidadeDinossauros, NULL, 0, 0);

    ControladorCor = (ControladorCor+1)%8;
    QuantidadeDinossauros = QuantidadeDinossauros + 1;
}

void AlocarDinossauros()
{
    for(int i=0; i<POPULACAO_TAMANHO; i++)
    {
        AlocarDinossauro();
    }
}

void AlocarObstaculos()
{
    for(int i=0; i<MAX_OBSTACULOS; i++)
    {
        obstaculo[i].TimerFrames = CriarTimer();
    }
}
