# Google Dino I.A.

Projeto onde várias Redes Neurais competem para aprender a jogar o jogo do dinossauro no navegador Google Chrome.

![Preview-Screens](https://github.com/JVictorDias/Dinossauro-Google/blob/master/preview.gif)

# Sobre o Projeto

  A ideia consiste em utilizar uma "seleção artificial" para evoluir os pesos de várias redes neurais, com o propósito de encontrar a melhor combinação e assim obter o melhor comportamento para o personagem.

  O jogo foi recriado do zero(sem engines) utilizando a biblioteca gráfica **Programming Interface Gaming (PIG)** que por sua vez é baseada na tradicional **Simple DirectMedia Layer (SDL)**.
  
  A Rede Neural Artificial utilizada foi uma Perceptron Multilayer com 3 camadas!

  - Camada de Entrada com 6 sensores + 1 Viés, totalizando 7 Neurônios
  - Camada Escondida com 6 neurônios + 1 Viés, totalizando 7 Neurônios
  - Camada de Saída com 3 neurônios (Pular, Abaixar, Avião)
  - A função de ativação utilizada em todos os neurônios foi a ReLU.
  - O método de aprendizagem é comumente chamado de "Random Mutations".
  - O tamanho da população que utilizei variou entre 1000 ~ 5000 indivíduos.
  - O tempo de aprendizagem variou entre 15 ~ 60 minutos por modo de Jogo.

      **Para mais informações e explicações acesse o [vídeo demonstrativo](https://www.youtube.com/watch?v=NZlIYr1slAk).** 



# Por quê?

  Desenvolvi esse projeto por curiosidade e diversão :)
  
  Para mais projetos como esse visite o [canal](youtube.com/UniversoProgramado).



# Observações:

- O arquivo 'redeNeural.c' contém todas as funções relativas à implementação da Rede Neural (tudo sobre a rede neural está nesse arquivo).
  Ele está genérico, ou seja, você pode baixar o arquivo e incluir no seu projeto e você conseguirá usar a rede neural facilmente.
    
    Exemplo:  
    ```
    RedeNeural* Dino = RNA_CriarRedeNeural(1,2,3,4);
    ```          
    Nesse exemplo nós estamos criando uma variável chamada 'Dino' que vai receber a Rede Neural que foi alocada dentro da função RNA_CriarRedeNeural()... Não esqueça de destruí-la após usar, utilizando a função: 
    ```
    RNA_DestruirRedeNeural(Dino);
     ```      
- A função 'ControlarEstadoDinossauros' dentro do arquivo 'main.cpp' contém o código que faz a comunicação entre o jogo e a rede neural.
- O resto dos arquivos são apenas os códigos da implementação do jogo.


**Os arquivos "Dinossauro Treinando.zip" e "Dinossauro x1.zip" contém o executável para Windows :)**

Um grande abraço!
