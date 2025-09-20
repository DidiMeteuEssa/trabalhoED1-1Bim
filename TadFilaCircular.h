#define MAXFILA 100

struct TpPaciente
{
	char nome[50];
	int id;
	int prioridade;
};

struct TpFila
{
	int inicio, fim, cont;
	struct TpPaciente fila[MAXFILA];
};

void Inicializar(TpFila &f)
{
	f.inicio = 0;
	f.fim = -1;
	f.cont = 0;
}

char Vazia(int cont)
{
	return cont == 0;
}

char Cheia(int cont)
{
	return cont == MAXFILA;
}

void Inserir(TpFila &F, struct TpPaciente novo)
{
	F.fim = (F.fim + 1) % MAXFILA;
	F.fila[F.fim] = novo;
	F.cont++;

	int i = F.fim;
	while (i != F.inicio && F.fila[i].prioridade < F.fila[(i - 1 + MAXFILA) % MAXFILA].prioridade)
	{
		TpPaciente temp = F.fila[i];
		F.fila[i] = F.fila[(i - 1 + MAXFILA) % MAXFILA];
		F.fila[(i - 1 + MAXFILA) % MAXFILA] = temp;
		i = (i - 1 + MAXFILA) % MAXFILA;
	}
}

TpPaciente Retirar(TpFila &F)
{
	TpPaciente retirado;
	retirado = F.fila[F.inicio];
	F.inicio = (F.inicio + 1) % MAXFILA;
	F.cont--;
	return retirado;
}

