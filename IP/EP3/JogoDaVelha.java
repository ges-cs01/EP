/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   <2020104> - <Norton Trevisan Roman>                           **/
/**                                                                 **/
/**   Terceiro Exercício-Programa                                   **/
/**                                                                 **/
/**                                                                 **/
/**   <12/05/2020>                                                  **/
/*********************************************************************/

/*
 * Jogo da Velha - programa para verificar o status de um jogo.
 *
 * Lista de Status calculado:
 *  0 - Jogo não iniciado: o tabuleiro está 'vazio', isto é sem peças X e O;
 *  1 - Jogo encerrado1: o primeiro jogador (que usa as peças X) é o ganhador;
 *  2 - Jogo encerrado2: o segundo jogador (que usa as peças O) é o ganhador;
 *  3 - Jogo encerrado3: empate - todas as casas do tabuleiro estão preenchidas com X e O, mas nenhum dos jogadores ganhou;
 *  4 - Jogo já iniciado e em andamento: nenhuma das alternativas anteriores.	
*/
public class JogoDaVelha {
    static final char pecaX = 'X';
    static final char pecaY = 'O';
    static final char espacoVazio = ' ';

/*
 * verificaXIgual compara e determina se três posições possuem elementos X.
 *      
 *      -Entrada:
 *      	posicaoXUm, posicaoXDois, posicaoXTres: argumentos devem conter a posição do caracter.
 *          	Ex.: verificaXIgual(matriz[1][1], matriz[2][2], matriz[3][3]).
 *
 *      -Saída:
 *          retorna false caso em alguma das três posições exista elemento diferente de pecaX.
 *          retorna true caso as três posições possuam elementos iguais a pecaX.
*/
    static boolean verificaXIgual(char posicaoXUm, char posicaoXDois, char posicaoXTres) {
        if ((posicaoXUm == pecaX) && (posicaoXDois == pecaX) && (posicaoXTres == pecaX)) {
            return true;
        }
        return false;
    }

/*
 * verificaYIgual compara e determina se três posições possuem elementos iguais a pecaY.
 *      
 *      -Entrada:
 *          posicaoYUm, posicaoYDois, posicaoYTres: argumentos devem conter a posição do caracter.
 *              Ex.: verificaYIgual(matriz [1][1], matriz[2][2], matriz[3][3]).
 *
 *      -Saída:
 *          retorna false caso em alguma das três posições exista elemento diferente de pecaY.
 *          retorna true caso as três posições possuam elementos iguais a pecaY. 
*/
    static boolean verificaYIgual(char posicaoYUm, char posicaoYDois, char posicaoYTres) {
        if ((posicaoYUm == pecaY) && (posicaoYDois == pecaY) && (posicaoYTres == pecaY)) {
            return true;
        }
        return false;
    }

/*
 * isMatrixEmpty faz a iteração por todos elementos de uma matriz e determina se ela contém algum elemento X ou O.
 *      
 *      -Entrada:
 *          char[][] matrix: tabuleiro 3x3 de uma partida de jogo da velha.
 *      
 *      -Saída:
 *          retorna false caso exista elemento X ou caso exista elemento O.
 *          retorna true caso contrário. 
*/
    static boolean isMatrixEmpty(char[][] matrix) {
    	for (int i = 0; i < 3; i++) { 
        	for (int j = 0; j < 3; j++) {
                if ((matrix[i][j] == pecaY || matrix[i][j] == pecaX)) {
                    return false;
                }
            }
        }
        return true;
    }

/*
 * isMatrixFull faz a iteração por todos elementos da matriz e determina se ela contém algum espaço vazio.
 *      
 *      -Entrada:
 *          char[][] matrix: tabuleiro 3x3 de uma partida de jogo da velha.
 *
 *      -Saída:
 *          retorna false caso exista elemento vazio.
 *          retorna true caso não exista elemento vazio. 
*/
    static boolean isMatrixFull(char[][] matrix) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((matrix[i][j] == espacoVazio)) {
                    return false;
                }
            }
        }
        return true;
    }

/*
 * verificaStatus determina o status de uma partida de jogo da velha.
 *      
 *      -Entrada:
 *          tabuleiro: tabuleiro 3x3 de caracteres representando uma partida válida de jogo da velha.
 *
 *      -Saída:
 *          um inteiro contendo o status da partida (valores válidos de zero a quatro). 
*/
    static int verificaStatus(char[][] tabuleiro) {
        int status = -1;

        if (isMatrixEmpty(tabuleiro)) {
            status = 0;			//status não iniciado.
        }

        else {
            status = 4;			//status em andamento.
        }
        
        if (isMatrixFull(tabuleiro)) {
            status = 3;			//status empate.
        }

        /* ******************************** X_VENCEDOR ***************************** */ 

        // Verifica se existe linha i toda preenchida com X. 
        for (int i = 0; i < 3; i++) {
            if (verificaXIgual(tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2])) {
                status = 1;
            }
        }
        
        // Verifica se existe coluna j toda preenchida com X.
        for (int j = 0; j < 3; j++) {
            if (verificaXIgual(tabuleiro[0][j], tabuleiro[1][j], tabuleiro[2][j])) {
                status = 1;
            }
        }
        
        // Verifica se a diagonal está toda preenchida com X.
        if (verificaXIgual(tabuleiro[0][0], tabuleiro[1][1], tabuleiro[2][2])) {
            status = 1;
        }
        
        // Verifica se a anti-diagonal está toda preenchida com X.
        if (verificaXIgual(tabuleiro[2][0], tabuleiro[1][1], tabuleiro[0][2])) {
            status = 1;
        }

        /* ******************************* Y_VENCEDOR ***************************** */

        // Verifica se existe linha i toda preenchida com O.
        for (int i = 0; i < 3; i++) {
            if (verificaYIgual(tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2])) {
                status = 2;
            }
        }

        // Verifica se existe coluna j toda preenchida com O.
        for (int j = 0; j < 3; j++) {
            if (verificaYIgual(tabuleiro[0][j], tabuleiro[1][j], tabuleiro[2][j])) {
                status = 2;
            }
        }

        // Verifica se a diagonal está toda preenchida com O.
        if (verificaYIgual(tabuleiro[0][0], tabuleiro[1][1], tabuleiro[2][2])) {
            status = 2;
        }

        // Verifica se a anti-diagonal está toda preenchida com O.
        if (verificaYIgual(tabuleiro[2][0], tabuleiro[1][1], tabuleiro[0][2])) {
            status = 2;
        }

        return status;
    }

    public static void main(String[] args) {
        //muitos testes
        char[][] tab0 =  {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
        char[][] tab1 =  {{'X','X','X'},{'O','O',' '},{' ',' ',' '}};
        char[][] tab2 =  {{'O','X','X'},{'X','O','O'},{' ',' ','O'}};
        char[][] tab3 =  {{'O','X','X'},{'X','O','O'},{'O','X','X'}};
        char[][] tab4 =  {{' ',' ',' '},{'X','O','X'},{' ',' ',' '}};
        char[][] tab5 =  {{' ',' ',' '},{'O','O',' '},{'X','X','X'}};
        char[][] tab6 =  {{' ',' ','O'},{'X','O','O'},{'O','X','X'}};
        char[][] tab7 =  {{'X','X','O'},{'O','O','X'},{'X','X','O'}};
        char[][] tab8 =  {{' ','X',' '},{' ','O',' '},{' ','X',' '}};
        char[][] tab9 =  {{' ',' ',' '},{'X','X','X'},{'O','O',' '}};
        char[][] tab10 = {{'X','O','X'},{'O','O','X'},{'X','O',' '}};
    	char[][] tab11 = {{' ','X','O'},{' ','X',' '},{' ','X','O'}};
        char[][] tab12 = {{' ',' ',' '},{' ',' ',' '},{' ',' ','X'}};
        char[][] tab13 = {{'X',' ','O'},{' ','X','O'},{' ',' ','X'}};
        char[][] tab14 = {{'X','O','X'},{'X','O','O'},{'X',' ',' '}};
        char[][] tab15 = {{'X','O','X'},{'O','X','O'},{'X','X','O'}};
        char[][] tab16 = {{'O','O','X'},{'X','X','O'},{'O','X','X'}};
        char[][] tab17 = {{'X',' ','O'},{' ','O','X'},{'O','X',' '}};
        char[][] tab18 = {{'X','O',' '},{' ',' ',' '},{' ',' ',' '}};
        char[][] tab19 = {{'X','O',' '},{' ','O','O'},{'X','X','X'}};
        char[][] tab20 = {{'O','O','O'},{'X','X',' '},{' ','X',' '}};
        char[][] tab21 = {{' ',' ',' '},{'X','O','X'},{'O','X','O'}};
        char[][] tab22 = {{'O',' ',' '},{'O','X','X'},{'O',' ','X'}};
        char[][] tab23 = {{'O','O','X'},{'X','O','X'},{'O','X','X'}};
        char[][] tab24 = {{' ','X','O'},{'X','O','O'},{'X','O','X'}};
        char[][] tab25 = {{'X','O','X'},{'O','X','X'},{'O','X','O'}};
        char[][] tab26 = {{'X','O','X'},{'O','X','O'},{'X',' ',' '}};
        char[][] tab27 = {{' ',' ',' '},{' ','X',' '},{' ',' ',' '}};
        char[][] tab28 = {{'X',' ',' '},{'O','O','O'},{'X','X',' '}};
        char[][] tab29 = {{'O','X','O'},{'X','O','X'},{'X','O','X'}};
        char[][] tab30 = {{'X','O','O'},{'X','X','O'},{' ','X','O'}};

        System.out.println("Status calculado: " + verificaStatus(tab0));
        System.out.println("Status esperado para o tabuleiro0: 0\n");

        System.out.println("Status calculado: " + verificaStatus(tab1));
        System.out.println("Status esperado para o tabuleiro1: 1\n");

        System.out.println("Status calculado: " + verificaStatus(tab2));
        System.out.println("Status esperado para o tabuleiro2: 2\n");

        System.out.println("Status calculado: " + verificaStatus(tab3));
        System.out.println("Status esperado para o tabuleiro3: 3\n");

        System.out.println("Status calculado: " + verificaStatus(tab4));
        System.out.println("Status esperado para o tabuleiro4: 4\n");

        System.out.println("Status calculado: " + verificaStatus(tab5));
        System.out.println("Status esperado para o tabuleiro5: 1\n");

        System.out.println("Status calculado: " + verificaStatus(tab6));
        System.out.println("Status esperado para o tabuleiro6: 2\n");

        System.out.println("Status calculado: " + verificaStatus(tab7));
        System.out.println("Status esperado para o tabuleiro7: 3\n");

    	System.out.println("Status calculado: " + verificaStatus(tab8));
        System.out.println("Status esperado para o tabuleiro8: 4\n");

    	System.out.println("Status calculado: " + verificaStatus(tab9));
        System.out.println("Status esperado para o tabuleiro9: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab10));
    	System.out.println("Status esperado para o tabuleiro10: 2\n");

    	System.out.println("Status calculado: " + verificaStatus(tab11));
    	System.out.println("Status esperado para o tabuleiro11: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab12));
    	System.out.println("Status esperado para o tabuleiro12: 4\n");

    	System.out.println("Status calculado: " + verificaStatus(tab13));
    	System.out.println("Status esperado para o tabuleiro13: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab14));
    	System.out.println("Status esperado para o tabuleiro14: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab15));
    	System.out.println("Status esperado para o tabuleiro15: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab16));
    	System.out.println("Status esperado para o tabuleiro16: 3\n");
    	
        System.out.println("Status calculado: " + verificaStatus(tab17));
    	System.out.println("Status esperado para o tabuleiro17: 2\n");

    	System.out.println("Status calculado: " + verificaStatus(tab18));
    	System.out.println("Status esperado para o tabuleiro18: 4\n");

    	System.out.println("Status calculado: " + verificaStatus(tab19));
    	System.out.println("Status esperado para o tabuleiro19: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab20));
    	System.out.println("Status esperado para o tabuleiro20: 2\n");
        
    	System.out.println("Status calculado: " + verificaStatus(tab21));
    	System.out.println("Status esperado para o tabuleiro21: 4\n");

    	System.out.println("Status calculado: " + verificaStatus(tab22));
    	System.out.println("Status esperado para o tabuleiro22: 2\n");

    	System.out.println("Status calculado: " + verificaStatus(tab23));
    	System.out.println("Status esperado para o tabuleiro23: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab24));
    	System.out.println("Status esperado para o tabuleiro24: 4\n");

    	System.out.println("Status calculado: " + verificaStatus(tab25));
    	System.out.println("Status esperado para o tabuleiro25: 3\n");

    	System.out.println("Status calculado: " + verificaStatus(tab26));
    	System.out.println("Status esperado para o tabuleiro26: 1\n");

    	System.out.println("Status calculado: " + verificaStatus(tab27));
    	System.out.println("Status esperado para o tabuleiro27: 4\n");

    	System.out.println("Status calculado: " + verificaStatus(tab28));
    	System.out.println("Status esperado para o tabuleiro28: 2\n");

    	System.out.println("Status calculado: " + verificaStatus(tab29));
    	System.out.println("Status esperado para o tabuleiro29: 3\n");

    	System.out.println("Status calculado: " + verificaStatus(tab30));
    	System.out.println("Status esperado para o tabuleiro30: 2\n");
    }
}
