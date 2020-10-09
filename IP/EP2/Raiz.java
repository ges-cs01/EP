/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   <2020104> - <Norton Trevisan Roman>                           **/
/**                                                                 **/
/**   Segundo Exercício-Programa                                    **/
/**                                                                 **/
/**                                                                 **/
/**   <17/04/2020>                                             	    **/
/*********************************************************************/

//Cálculo para raiz quadrada

public class Raiz {
	

    /*
     * Funcao mod calcula o modulo da diferenca entre dois numeros.
       Caso a diferenca seja negativa, seu valor eh multi-
       plicado por -1, obtendo-se assim um valor positivo.
      
     * Parametros: 
            i)  num1: primeiro numero.
            ii) num2: segundo numero.
     
     * Retorno: 
            i)  caso (num1 - num2) seja menor que zero 
            a funcao retorna o modulo da diferenca.
           
            ii) caso seja maior ou igual que zero retorna apenas 
            a propria diferenca.
     */
    static double mod (double num1, double num2) { 
        if (num1 - num2 < 0) {
            double modulo = (num1 - num2) * (-1);
            return modulo;
        }

        else {
            return num1 - num2;
        }
    }
		
    
    /*
     * Funcao raizQuadrada calcula a raiz quadrada de um valor, com uma determinada
       precisão epsilon. Retorna a raiz, ou -1 quando:
		
	  	* a < 0
		* epsilon <= 0
		* epsilon >= 1
        
        * Parâmetro:
		a - valor cuja raiz quadrada será calculada
		epsilon - precisão do cálculo
	*/
    

    /* Inicialmente a funcao testa as condicoes necessarias para 
       o calculo da raiz. 
      
     * Para o caso de ser verdadeira sera atribuido x = a/2, 
       vide formula dada
     
     * A seguir, enquanto a condicao do while nao retorna como false
       sao executadas repetidamente as operacoes entre as chaves
       de modo a se obter a raiz quadrada
     
     * O valor de x eh armazenado na variavel raiz e portanto
       x pode ser atualizado para seu proximo valor sem perda. 
     
     * Para o outro caso o retorno sera -1 */
	
    static double raizQuadrada(double a, double epsilon) {    
        double x, raiz;

        if (a >= 0 && epsilon > 0 && epsilon < 1) {
            x = a / 2;
            
            do {
                raiz = x;
                x = ((a / x) + x) / 2;
            
            } while (mod(raiz, x) >= epsilon);              //call da funcao mod com os argumentos raiz e x
            
            return raiz;
        }

        else {
            return -1;
        }
    }

	public static void main(String[] args) {
        System.out.println(raizQuadrada(100, 0.1));

	}
}
