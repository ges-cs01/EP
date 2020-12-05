#include "filapreferencial.c"

int main() {
	PFILA f = criarFila();
	int id;
	bool res;

	printf("################# INSERINDO #######################\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, -1, false);
	if(res) printf("Insercao retornou true (0).\n");
	else printf("Insercao retornou false (0). [OK]\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 1, false);
	if(res) printf("Insercao retornou true (1). [OK]\n");
	else printf("Insercao retornou false (1).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 2, true);
	if(res) printf("Insercao retornou true (2). [OK]\n");
	else printf("Insercao retornou false (2).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 3, false);
	if(res) printf("Insercao retornou true (3). [OK]\n");
	else printf("Insercao retornou false (3).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 4, true);
	if(res) printf("Insercao retornou true (4). [OK]\n");
	else printf("Insercao retornou false (4).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 5, true);
	if(res) printf("Insercao retornou true (5). [OK]\n");
	else printf("Insercao retornou false (5).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 6, false);
	if(res) printf("Insercao retornou true (6). [OK]\n");
	else printf("Insercao retornou false (6).\n");
	exibirLog(f);


	printf("################# ATENDENDO #######################\n");
	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (7), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (7).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (8), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (8).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (9), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (9).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (10), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (10).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (11), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (11).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (12), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (12).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (13), id=%i.\n",id);
	else printf("Atendimento retornou false (13). [OK]\n");
	exibirLog(f);



	printf("################# INSERINDO PARTE 2 ###############\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 7, false);
	if(res) printf("Insercao retornou true (14). [OK]\n");
	else printf("Insercao retornou false (14).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 8, true);
	if(res) printf("Insercao retornou true (15). [OK]\n");
	else printf("Insercao retornou false (15).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 9, false);
	if(res) printf("Insercao retornou true (16). [OK]\n");
	else printf("Insercao retornou false (16).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 10, true);
	if(res) printf("Insercao retornou true (17). [OK]\n");
	else printf("Insercao retornou false (17).\n");
	exibirLog(f);


	printf("################# SAINDO DA FILA ##################\n");

	exibirLog(f);
	res = desistirDaFila(f, 6);
	if(res) printf("Desistindo da fila retornou true (18).\n");
	else printf("Desistindo da fila retornou false (18). [OK]\n");
	exibirLog(f);
	res = desistirDaFila(f, 7);
	if(res) printf("Desistindo da fila retornou true (19). [OK]\n");
	else printf("Desistindo da fila retornou false (19).\n");
	exibirLog(f);
	res = desistirDaFila(f, 8);
	if(res) printf("Desistindo da fila retornou true (20). [OK]\n");
	else printf("Desistindo da fila retornou false (20).\n");
	exibirLog(f);
	res = desistirDaFila(f, 9);
	if(res) printf("Desistindo da fila retornou true (21). [OK]\n");
	else printf("Desistindo da fila retornou false (21).\n");
	exibirLog(f);
	res = desistirDaFila(f, 10);
	if(res) printf("Desistindo da fila retornou true (22). [OK]\n");
	else printf("Desistindo da fila retornou false (22).\n");
	exibirLog(f);

	printf("################# INSERINDO PARTE 3 ###############\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 70, false);
	if(res) printf("Insercao retornou true (xx00). [OK]\n");
	else printf("Insercao retornou false (xx00).\n");
	
    exibirLog(f);
	res = inserirPessoaNaFila(f, 50, true);
	if(res) printf("Insercao retornou true (xx01). [OK]\n");
	else printf("Insercao retornou false (xx01).\n");
	
    exibirLog(f);
	res = inserirPessoaNaFila(f, 45, false);
	if(res) printf("Insercao retornou true (xx02). [OK]\n");
	else printf("Insercao retornou false (xx02).\n");
	
    exibirLog(f);
	res = inserirPessoaNaFila(f, 10, true);
	if(res) printf("Insercao retornou true (xx03). [OK]\n");
	else printf("Insercao retornou false (xx03).\n");
	
    exibirLog(f);
	res = inserirPessoaNaFila(f, 56, false);
	if(res) printf("Insercao retornou true (xxx14). [OK]\n");
	else printf("Insercao retornou false (xxx14).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 71, true);
	if(res) printf("Insercao retornou true (xxx15). [OK]\n");
	else printf("Insercao retornou false (xxx15).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 900, false);
	if(res) printf("Insercao retornou true (xxx16). [OK]\n");
	else printf("Insercao retornou false (xxx16).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 100, true);
	if(res) printf("Insercao retornou true (xxx17). [OK]\n");
	else printf("Insercao retornou false (xxx17).\n");
	exibirLog(f);


	printf("################# SAINDO DA FILA 00xxx ##################\n");

	exibirLog(f);
	res = desistirDaFila(f, 70);
	if(res) printf("70Desistindo da fila retornou true (xxx18). [OK] \n");
	else printf("70Desistindo da fila retornou false (xxx18). \n");
	exibirLog(f);
	res = desistirDaFila(f, 900);
	if(res) printf("900Desistindo da fila retornou true (xxx19). [OK]\n");
	else printf("900Desistindo da fila retornou false (xxx19).\n");
	exibirLog(f);
	res = desistirDaFila(f, 100);
	if(res) printf("100Desistindo da fila retornou true (xxx20). [OK]\n");
	else printf("100Desistindo da fila retornou false (xxx20).\n");
	exibirLog(f);
	res = desistirDaFila(f, 50);
	if(res) printf("Desistindo da fila retornou true (xxx21). [OK]\n");
	else printf("Desistindo da fila retornou false (xxx21).\n");
	exibirLog(f);
	res = desistirDaFila(f, 71);
	if(res) printf("Desistindo da fila retornou true (xxx22). [OK]\n");
	else printf("Desistindo da fila retornou false (xxx22).\n");
	exibirLog(f);
	res = desistirDaFila(f, 10);
	if(res) printf("Desistindo da fila retornou true (xxx24). [OK]\n");
	else printf("Desistindo da fila retornou false (xxx24).\n");
    


	exibirLog(f);
	res = desistirDaFila(f, 45);
	if(res) printf("Desistindo da fila retornou true (xxx24). [OK]\n");
	else printf("Desistindo da fila retornou false (xxx24).\n");
	exibirLog(f);
	res = desistirDaFila(f, 56);
	if(res) printf("Desistindo da fila retornou true (xxx24). [OK]\n");
	else printf("Desistindo da fila retornou false (xxx24).\n");

	exibirLog(f);
    return 0;
}
