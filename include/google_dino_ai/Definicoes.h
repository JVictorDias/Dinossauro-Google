#ifndef GOOGLE_DINO_AI__DEFINICOES_HPP_
#define GOOGLE_DINO_AI__DEFINICOES_HPP_

#define PASSARO_CODIGO_TIPO     5
#define ESPINHO_CODIGO_TIPO     6

#define MODO_JOGO               0       /// 0 = TREINANDO   - OBS: Aumentar tamanho da populacao para 2000
                                        /// 1 = JOGAVEL     - OBS: Diminuir tamanho da populacao para 1

#define POPULACAO_TAMANHO       2000


#define DINO_BRAIN_QTD_LAYERS   1       /// Quantidade de camadas escondidas na rede neural
#define DINO_BRAIN_QTD_INPUT    6       /// Quantidade de neuronios na camada de entrada
#define DINO_BRAIN_QTD_HIDE     6       /// Quantidade de neuronios nas camadas escondidas
#define DINO_BRAIN_QTD_OUTPUT   3       /// Quantidade de neuronios na camada de saida

#endif  // GOOGLE_DINO_AI__DEFINICOES_HPP_
