# Dinossauro-Google

- O arquivo 'redeNeural.c' contém todas as funções relativas a implementação da Rede Neural (tudo sobre a rede neural está nesse arquivo).
  Ele está genérico, ou seja, você pode copiar o arquivo e incluir no seu projeto e você conseguirá usar a rede neural facilmente.
    Exemplo:  RedeNeural* Dino = RNA_CriarRedeNeural(1,2,3,4);
              Nesse exemplo nós estamos criando uma variável chamada 'Dino' que vai receber a Rede Neural que foi alocada dentro da função RNA_CriarRedeNeural()... Não esqueça de destrui-la após usar,               utilizando a função RNA_DestruirRedeNeural(Dino);
  
- A função 'ControlarEstadoDinossauros' dentro do arquivo 'main.cpp' contém o código que faz a comunicação entre o jogo e a rede neural.
- O resto dos arquivos são apenas os códigos da implementação do jogo.

O arquivo Dinossauro.zip contém o executável (Windows) :)

Um grande abraço!
