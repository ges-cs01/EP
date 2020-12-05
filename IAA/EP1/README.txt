----------------------------------------------------------------------------------
/* Guilherme Elui de Souza, 11796152 */

----------------------------------------------------------------------------------
- Compilação:   javac Main.java
- Execução:     java -Xss100m Main <arquivo_de_entrada.txt> <arquivo_de_saida.png>

-----------------------------------------EXEMPLOS---------------------------------

- Como exemplos existem arquivos de entrada no diretório chamado entradas,
  são eles entradaKoch.txt e entradaRegion.txt, que testam funcionalidades
  implementadas e originam as imagens saidaKoch.png e saidaRegion.png.

- Uso: 	java -Xss100m Main entradas/entradaKoch.txt saidaKoch.png
        java -Xss100m Main entradas/entradaRegion.txt saidaRegion.png

-----------------------------------------TODO-------------------------------------
- TODO 0: ***CORRIGIDO em 2020-11-20.***
    - Corrigir stackOverflowError que ocorre quando o usuário do arquivo de entrada
      tenta chamar de forma redundante a REGION_FILL. Em outras palavras, quando o
      usuário tenta colorir com a mesma cor uma região já colorida com tal cor. Por
      exemplo, tentar colorir uma região já azul com azul.

        - Exemplo de erro:
                            REGION_FILL 438 352
                            REGION_FILL 438 352

        - Exemplo correto:
                            REGION_FILL 438 352
                            SET_COLOR 0 0 200   /* deve-se mudar a cor anterior */
                            REGION_FILL 438 352

- TODO 1: ***CORRIGIDO em 2020-11-20.***
    - Corrigir stackOverflowError que ocorre quando o usuário do arquivo de entrada
      tenta chamar a KOCH_CURVE com o limiar l sendo menor ou igual a 1.

- TODO 2:
    - Corrigir a função REGION_FILL para que ela preencha adequadamente linhas
      diagonais. Exemplo do erro pode ser verificado com o arquivo bugsTest.txt.
      Note como ao chamar REGION_FILL 128 128, apenas este pixel é pintado. Para 
      linhas não-diagonais a função funciona adequadamente.

---------------------------------------------------------------------------------
