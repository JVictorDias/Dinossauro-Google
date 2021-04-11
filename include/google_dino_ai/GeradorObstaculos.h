



void GerarListaObstaculos()
{
    int contadorEspinhos = 0;
    int Largura;

    obstaculosModelo[0].X = 1250;
    obstaculosModelo[0].Y = 15;
    obstaculosModelo[0].Tipo = 5;

    for(int i=1; i<20000; i++)
    {
        if(contadorEspinhos >= 10)
        {
            obstaculosModelo[i].Tipo = ESPINHO_CODIGO_TIPO;
            contadorEspinhos = 0;
        }
        else
        {
            obstaculosModelo[i].Tipo = rand()%6;
            if(DINO_BRAIN_QTD_OUTPUT == 3)
            {
                contadorEspinhos++;
            }

        }

        /// ---------------

        Sprite* sprit = getObstaculosSprite(obstaculosModelo[i-1].Tipo, 0);
        Largura = sprit->Largura;

        obstaculosModelo[i].X = obstaculosModelo[i-1].X + Largura + 500 + ((rand()%200)-100);

        /// ---------------

        if(obstaculosModelo[i].Tipo == PASSARO_CODIGO_TIPO)
        {
            obstaculosModelo[i].Y = 20 + rand()%65;
        }
        else
        {
            if(obstaculosModelo[i].Tipo == ESPINHO_CODIGO_TIPO)
            {
                obstaculosModelo[i].Y = 10;
            }
            else
            {
                obstaculosModelo[i].Y = 15;
            }
        }
    }
}

void GerarListaObstaculosTreinoSemEspinho()
{
    int Largura;

    obstaculosModelo[0].X = 1250;
    obstaculosModelo[0].Y = 15;
    obstaculosModelo[0].Tipo = 0;

    for(int i=1; i<10000; i++)
    {
        if(i < 600)
        {
            obstaculosModelo[i].Tipo = 5;
        }
        else
        {
            obstaculosModelo[i].Tipo = (i-600)/300;
            if(obstaculosModelo[i].Tipo > 5)
            {
                obstaculosModelo[i].Tipo = 5;
            }
        }
        //obstaculosModelo[i].Tipo = 0;

        /// ---------------

        Sprite* sprit = getObstaculosSprite(obstaculosModelo[i-1].Tipo, 0);
        Largura = sprit->Largura;

        obstaculosModelo[i].X = obstaculosModelo[i-1].X + Largura + 400 + ((rand()%200)-100) ;

        /// ---------------

        if(obstaculosModelo[i].Tipo == PASSARO_CODIGO_TIPO)
        {
            obstaculosModelo[i].Y = 20 + i%65;
        }
        else
        {
            obstaculosModelo[i].Y = 15;
        }
    }

    FILE* f = fopen("obstaculos.dat","wb");
    fwrite(obstaculosModelo, 10000, sizeof(Obstaculo), f);
    fclose(f);

    f = fopen(GOOGLE_DINO_AI_RESOURCES_PATH"/obstaculos.txt","w");
    for(int i=0; i<10000; i++)
    {
        fprintf(f,"%d %f %f\n", obstaculosModelo[i].Tipo, obstaculosModelo[i].X, obstaculosModelo[i].Y);
    }
    fclose(f);
}



void CarregarListaObstaculos()
{
    FILE* f = fopen(GOOGLE_DINO_AI_RESOURCES_PATH"/obstaculos.dat","rb");
    fread(obstaculosModelo, 20000, sizeof(Obstaculo), f);
    fclose(f);
}
