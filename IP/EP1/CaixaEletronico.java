/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   <2020104> - <Norton Trevisan Roman>                           **/
/**                                                                 **/
/**   Primeiro Exercício-Programa                                   **/
/**                                                                 **/
/**                                                                 **/
/**   <26/03/2020>                                                  **/
/*********************************************************************/

/*
	Caixa eletrônico das Ilhas Weblands, com estoque ilimitado de cédulas
	de B$50,00, B$10,00, B$5,00 e B$1,00.
*/
public class CaixaEletronico {
	// Número de cédulas de B$50,00
	static int n50;
	
	// Número de cédulas de B$10,00
	static int n10;

	// Número de cédulas de B$5,00
	static int n5;
	
	// Número de cédulas de B$1,00
	static int n1;


	/*
		Determina a quantidade de cada nota necessária para totalizar
		um determinado valor de retirada, de modo a minimizar a quantidade
		de cédulas entregues.
		
		Abastece as variáveis globais n50, n10, n5 e n1 com seu respectivo
		número de cédulas.
		
		Parâmetro:
			valor - O valor a ser retirado
     	*/

    static void fazRetirada(int valor) {
        if (valor < 0) {                        //tratamento de erro no caso do argumento (valor) menor do que zero.
            n1 = n5 = n10 = n50 = -1;
        }                            
        
        else {                              
            n50 = (valor / 50); 
            n10 = (valor - (n50 * 50)) / 10;
            n5 = (valor - (n50 * 50) - (n10 * 10)) / 5;
            n1 = (valor - (n50 * 50) - (n10 * 10) - (n5 * 5)) / 1;
        }

        /* 
         * Explicacao da logica: 
         *
         * como o operador '/' retornara apenas a parte inteira da divisao, 
         * eh possivel explorar tal fato para as atribuicoes de n1, n5, n10 e n50.
         * 
         * Por exemplo, para valor = 66, (66 / 50) sera 1, que eh a quantidade de cedulas n50 necessarias.
         * 
         * Entao se a seguir subtrairmos (66 - 50), restarao apenas 16 e o resultado da divisao (16 / 10) sera 1,
         * que eh o numero de cedulas n10 necessarias. E assim sucessivamente, ate n1.
         * 
         * Generalizando para todos casos, temos as relacoes presentes no condicional else. 
         * Do valor total subtrai-se a quantidade de dinheiro ja devolvida e 
         * a seguir realiza-se a divisao com o operador '/'.
         * 
	 */    
    }

	
	public static void main(String[] args) {
        	fazRetirada(66);                            //teste

		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);
	}
}

