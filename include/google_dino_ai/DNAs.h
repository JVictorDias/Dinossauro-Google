

    double* DNADaVez[POPULACAO_TAMANHO];

    double MediaFitnessPopulacao[LARG_GRAFICO];
    double MediaFitnessFilhos[LARG_GRAFICO];
    double BestFitnessPopulacao[LARG_GRAFICO];

    int GeracaoCompleta = 0;

double BestFitnessGeracao()
{
    double Maior = 0;
    for(int i=0; i<POPULACAO_TAMANHO; i++)
    {
        if(Dinossauros[i].Fitness > Maior)
        {
            Maior = Dinossauros[i].Fitness;
        }
    }
    return Maior;
}

double MediaFitnessGeracao()
{
    double Media = 0;
    for(int i=0; i<POPULACAO_TAMANHO; i++)
    {
        Media = Media + Dinossauros[i].Fitness;
    }
    Media = Media/(double)POPULACAO_TAMANHO;
    return Media;
}

double BestFitnessEver()
{
    double Maior = 0;
    for(int i=0; i<GeracaoCompleta; i++)
    {
        if(BestFitnessPopulacao[i] > Maior)
        {
            Maior = BestFitnessPopulacao[i];
        }
    }
    return Maior;
}


void InicializarDNA()
{
    int TamanhoDNA = Dinossauros[0].TamanhoDNA;

    for(int i=0; i<POPULACAO_TAMANHO; i++)
    {
        DNADaVez[i] = (double*)malloc(TamanhoDNA*sizeof(double));
        for(int j=0; j<TamanhoDNA; j++)
        {
            DNADaVez[i][j] = getRandomValue();
        }
    }
}
