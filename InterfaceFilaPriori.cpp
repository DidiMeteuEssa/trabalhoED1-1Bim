#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include "conio2.h"

#include "TadFiLaCircular.h"
#include "TADMoldura.h"

void finalizar(int atendimentos, int totalTempoAtendimento)
{
	limparPainel(12, 23, 109, 27);
	textcolor(12);

	gotoxy(12, 23);
	printf("Simulacao encerrada!");
	gotoxy(12, 24);
	printf("Total de atendimentos: %d", atendimentos - 1);
	gotoxy(12, 25);
	printf("Tempo medio por paciente: %.2lf ut\n", atendimentos ? totalTempoAtendimento / atendimentos : 0);
}

int main()
{

	molduraSistema();
	
	textcolor(15);
	gotoxy(12, 6);
	printf("Pressione qualquer tecla para iniciar...");
	getch();
	limparPainel(12, 6, 58, 6);
	

	FILE *arq = fopen("Pacientes.txt", "r");
	if (arq == NULL)
	{
		printf("Erro ao abrir o arquivo.\n");
		getch();
	}
	else
	{
		TpFila fila;
		int atendimentos = 0;
		int totalTempoAtendimento = 0;
		int linhaAtualFila = 0;
		int linhaAtualAtentido = 0;
		int contAtendidos = 0;

		Inicializar(fila);

		srand(time(NULL));

		int ut = 0;
		int lidos = 0;
		int tempoRestante = 0;
		TpPaciente emAtendimento;
		emAtendimento.id = -1;

		char nome[50];
		int id, prio;

		do
		{
			ut++;

			
			if (!feof(arq))
			{
				if (ut % 3 == 1)
				{
					if (!Cheia(fila.cont))
					{
						textcolor(15);

						if (linhaAtualFila >= 16)
						{
							limparPainel(12, 6, 58, 21);
							linhaAtualFila = 0;
						}

						fscanf(arq, " %[^;];%d;%d\n", nome, &id, &prio);
						TpPaciente novo;
						strcpy(novo.nome, nome);
						novo.id = id;
						novo.prioridade = prio;
						Inserir(fila, novo);
						lidos++;

						gotoxy(12, 6 + linhaAtualFila);
						printf("%s ID: %d, Priodidade: %d\n", novo.nome, novo.id, novo.prioridade);
						linhaAtualFila++;
					}

					if (linhaAtualFila >= 16)
					{
						limparPainel(12, 6, 58, 21);
						linhaAtualFila = 0;
					}
				}
			}
			else
			{
				if (linhaAtualFila >= 15)
				{
					limparPainel(12, 6, 58, 21);
					linhaAtualFila = 0;
				}

				gotoxy(12, 6 + linhaAtualFila + 1);
				printf("A fila acabou!\n");
			}

			if (emAtendimento.id == -1 && !Vazia(fila.cont))
			{
				emAtendimento = Retirar(fila);
				tempoRestante = rand() % 4 + 3; 
				atendimentos++;
			}

			limparPainel(12, 23, 109, 27);
			textcolor(11);
			gotoxy(12, 23);
			printf("ut: %d\n", ut);

			gotoxy(12, 24);
			if (emAtendimento.id != -1)
				printf("Em atendimento: %s (ID: %d, / Priodidade: %d) | resta: %d ut\n", emAtendimento.nome, emAtendimento.id, emAtendimento.prioridade, tempoRestante);
			else
				printf("Em atendimento: nenhum\n");

			gotoxy(12, 25);
			printf("Na fila: %d | Lidos do arquivo: %d\n", fila.cont, lidos);
			gotoxy(12, 26);
			printf("Atendimentos realizados: %d\n", atendimentos);
			gotoxy(12, 27);
			printf("Pressione qualquer tecla para encerrar...\n");

			Sleep(1000);
			totalTempoAtendimento++;

			if (tempoRestante > 0)
				tempoRestante--;

			if (tempoRestante == 0 && emAtendimento.id != -1)
			{
				textcolor(15);
				if (linhaAtualAtentido >= 16)
				{
					limparPainel(60, 6, 109, 21);
					linhaAtualAtentido = 0;
				}

				gotoxy(61, 6 + linhaAtualAtentido);
				printf("%s ID: %d, Priodidade: %d\n", emAtendimento.nome, emAtendimento.id, emAtendimento.prioridade);
				emAtendimento.id = -1;
				linhaAtualAtentido++;
				contAtendidos++;
			}

			if (contAtendidos == 100)
			{
				if (linhaAtualAtentido >= 15)
				{
					limparPainel(60, 6, 109, 21);
					linhaAtualAtentido = 0;
				}

				gotoxy(61, 6 + linhaAtualAtentido + 1);
				printf("Todos os pacientes foram atendidos!");
			}

		} while (!kbhit() && (!Vazia(fila.cont) || emAtendimento.id != -1 || !feof(arq)));

		finalizar(atendimentos, totalTempoAtendimento);
		fclose(arq);

		gotoxy(10, 32);
		getch();
		getch();
	}

	return 0;
}
