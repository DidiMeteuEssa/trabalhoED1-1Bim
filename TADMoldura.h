void DesenhaMoldura(int LI, int CI, int LF, int CF)
{
    int a;
    gotoxy(CI, LI);
    printf("%c", 201);

    gotoxy(CF, LF);
    printf("%c", 188);

    gotoxy(CI, LF);
    printf("%c", 200);

    gotoxy(CF, LI);
    printf("%c", 187);

    for (a = CI + 1; a < CF; a++)
    {
        gotoxy(a, LI);
        printf("%c", 205);
        gotoxy(a, LF);
        printf("%c", 205);
    }

    for (a = LI + 1; a < LF; a++)
    {
        gotoxy(CI, a);
        printf("%c", 186);
        gotoxy(CF, a);
        printf("%c", 186);
    }
}

void molduraSistema()
{

    textcolor(10);

    DesenhaMoldura(1, 10, 3, 110);

    DesenhaMoldura(28, 10, 30, 110);

    DesenhaMoldura(1, 10, 30, 110);

    DesenhaMoldura(3, 10, 22, 59);
    DesenhaMoldura(3, 59, 22, 110);

    DesenhaMoldura(3, 10, 5, 59);
    DesenhaMoldura(3, 59, 5, 110);

    gotoxy(10, 3);
    printf("%c", 204);

    gotoxy(10, 5);
    printf("%c", 204);

    gotoxy(110, 3);
    printf("%c", 185);

    gotoxy(110, 5);
    printf("%c", 185);

    gotoxy(110, 22);
    printf("%c", 185);

    gotoxy(10, 28);
    printf("%c", 204);

    gotoxy(10, 22);
    printf("%c", 204);

    gotoxy(59, 3);
    printf("%c", 203);

    gotoxy(59, 5);
    printf("%c", 206);

    gotoxy(59, 22);
    printf("%c", 202);

    gotoxy(110, 28);
    printf("%c", 185);

    textcolor(13);
    gotoxy(11, 2);
    printf("                               TRABALHO DE ED1 - FILA DE ATENDIMENTO");

    gotoxy(11, 29);
    printf("                      DIEGO FELIPPE DA F. CALESCO / JOAO GABRIEL DA SILVA                  ");

    textcolor(14);
    gotoxy(12, 4);
    printf("Fila de Pacientes");

    gotoxy(61, 4);
    printf("Pacientes Atendidos");
}

void limparPainel(int xInicio, int yInicio, int xFinal, int yFinal)
{
    for (int y = yInicio; y <= yFinal; y++)
    {
        for (int x = xInicio; x <= xFinal; x++)
        {
            gotoxy(x, y);
            printf(" ");
        }
    }
}