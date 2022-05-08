#ifndef MISSING_H_INCLUDED
#define MISSING_H_INCLUDED

#include "CGerenciadorObjetos.h"
#include "PIG.h"

void DefinirColoracao(int obj, PIG_Cor cor)
{
    return CGerenciadorObjetos::SetColoracao(obj, cor);
}

int CriarSprite(char const *str)
{
    return PIG_criarSprite(str);
}

void ReiniciarTimer(int timer)
{
    return PIG_reiniciarTimer(timer);
}

void EscreverEsquerda(char const *str, int x, double y, int font)
{
    return PIG_escreverEsquerda(str, x, y, font);
}

void DesenharLinhaSimples(double x1, double y1, double x2, double y2, PIG_Cor cor)
{
    return PIG_desenharLinha(x1, y1, x2, y2, cor, 1);
}

void DefinirOpacidade(int obj, double opacidade)
{
    return CGerenciadorObjetos::SetOpacidade(obj, opacidade);
}

void DesenharSprite(int obj, double x, double y, double largura, double altura, double angulo, int alinhadoCentro = 1)
{
    return PIG_desenharSprite(obj, x, y, largura, altura, angulo, alinhadoCentro, PRETO);
}

void DesenharPonto(double x, double y, PIG_Cor cor, int tamanho)
{
    return PIG_desenharPonto(x, y, cor, tamanho);
}

void DesenharLinhas(SDL_Point *pontos, int quantidadePontos, PIG_Cor cor)
{
    return PIG_desenharLinhasConectadas(pontos, quantidadePontos, cor);
}

void DesenharRetangulo(double x, double y, double altura, double largura, PIG_Cor cor, int alinhadoCentro = 1)
{
    return PIG_desenharRetangulo(x, y, largura, altura, cor, alinhadoCentro);
}

void IniciarDesenho()
{
    return PIG_iniciarDesenho();
}

void EncerrarDesenho()
{
    return PIG_encerrarDesenho();
}

int CriarTimer()
{
    return PIG_criarTimer();
}

double TempoDecorrido(int id_timer)
{
    return PIG_tempoDecorrido(id_timer);
}

void CriarJanela(char const *nome_Janela, int cursor)
{
    LARG_TELA = 1366;
    ALT_TELA = 768;
    return PIG_criarJanela(nome_Janela, LARG_TELA, ALT_TELA);
}

int CriarFonteNormal(char const *nome, int tamanho, PIG_Cor corLetra, int contorno, PIG_Cor corContorno, PIG_Estilo estilo = ESTILO_NORMAL)
{
    return PIG_criarFonte(nome, tamanho, corLetra, contorno, corContorno, estilo);
}

void AtualizarJanela()
{
    PIG_atualizarJanela();
}

void FinalizarJanela()
{
    return PIG_encerrarDesenho();
}

double DistanciaEntrePontos(double x1, double y1, double x2, double y2)
{
    return distanciaEntrePontos(x1, y1, x2, y2);
}

#endif // MISSING_H_INCLUDED
