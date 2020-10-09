
public class ClienteEspecial extends Cliente{
	static final int dividaMaxima = 50000;
	static final String tipo = "CE";
	
	/* Construtor da Classe ClienteEspecial
	 * Este construtor invoca o construtor da classe Cliente.
	 */
	ClienteEspecial(String nome, int cpf, int valor){
		super(nome, cpf, valor);
	}
	
	/* Metodo que retorna o valor do atributo tipo do objeto atual */
	String retornaTipo() {
		return tipo;
	}
	
	public boolean obterEmprestimo(int valor) {

        //verifica se valor pertence ao conjunto dos naturais.
        if (valor <= 0) {
            return false;
        }
        
        //verifica se o cliente especial está apto a obter empréstimo de acordocom da dividaMa.
        if ((valor + getValorDaDivida()) > dividaMaxima) {
            return false;
        }

        //atualiza dívida e saldo da conta corrente de acordo com valor do empréstimo.
        else {
            setValorDaDivida(getValorDaDivida() + valor);
            setValorContaCorrente(getValorContaCorrente() + valor);
            return true;
        }
	}
}

