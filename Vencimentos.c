#include "EstruturaDados.h"
#include "Auxiliar.h"
#include "Vencimentos.h"

void printss(float **ss) {

    printf("                entidade\n");
    printf("               empregadora  trabalhador  global\n");
    for (int i = 0; i < Y_SS; i++) {
        if (i == 0) {
            printf("Trabalhador Geral ");
        }
        if (i == 1) {
            printf("Geral             ");
        }
        if (i == 2) {
            printf("Administração     ");
        }
        printf(" | %.4f | %.4f | %.4f \n",
                ss[0][i],
                ss[1][i],
                ss[2][i]);
    }
}

void carregarvalorsSS(float **ss) {

    FILE* file = fopen("ss.txt", "r");
    int j = 0;

    while (!feof(file)) {
        fscanf(file, "%f %f %f",
                &ss[0][j],
                &ss[1][j],
                &ss[2][j]);
        /*printf("%f %f %f\n",
                ss[0][j],
                ss[1][j],
                ss[2][j]);*/
        j++;
    }
    fclose(file);

}

void salvarvaloresSS(float **ss) {
    FILE* file = fopen("ss.txt", "w");
    int j = 0;

    for (int j = 0; j < Y_SS; j++) {
        fprintf(file, "%f %f %f\n",
                ss[0][j],
                ss[1][j],
                ss[2][j]);
        /*printf("%f %f %f\n",
                ss[0][j],
                ss[1][j],
                ss[2][j]);*/
    }
    fclose(file);
    printss(ss);
}

void altrarvalorss(float **ss) {
    int x, y, op;
    printss(ss);
    do {
        printf("\n1.Alterar valor\n"
                "0.Sair\n=");
        scanf("%d", &op);
        if (op == 1) {
            printf("x=");
            scanf("%d", &x);
            printf("y=");
            scanf("%d", &y);
            printf("Novo Valor=");
            scanf("%f", &ss[x][y]);
            printss(ss);
        }
        if (op == 0) {
            clear();
        }
    } while (op != 0);
}

//IRS

void carregarvaloresIRS(float **irs0, float **irs1, float **irs2) {

    //IRS S0LTEIRO
    FILE* file0 = fopen("irs0.txt", "r");
    //CARREGAR ARREIO COM A PERCENTAGEM DE IRS
    int j = 0;
    while (!feof(file0)) {
        fscanf(file0, "%f %f %f %f %f %f %f",
                &irs0[0][j],
                &irs0[1][j],
                &irs0[2][j],
                &irs0[3][j],
                &irs0[4][j],
                &irs0[5][j],
                &irs0[6][j]);
        /*printf("%g %g %g %g %g %g %g\n",
                irs0[0][j],
                irs0[1][j],
                irs0[2][j],
                irs0[3][j],
                irs0[4][j],
                irs0[5][j],
                irs0[6][j]);*/
        j++;
    }
    fclose(file0);

    //IRS CASADO1
    FILE* file1 = fopen("irs1.txt", "r");
    j = 0;
    while (!feof(file1)) {
        fscanf(file1, "%f %f %f %f %f %f %f",
                &irs1[0][j],
                &irs1[1][j],
                &irs1[2][j],
                &irs1[3][j],
                &irs1[4][j],
                &irs1[5][j],
                &irs1[6][j]);
        /*printf("%g %g %g %g %g %g %g\n",
                irs1[0][j],
                irs1[1][j],
                irs1[2][j],
                irs1[3][j],
                irs1[4][j],
                irs1[5][j],
                irs1[6][j]);*/
        j++;
    }
    fclose(file1);

    //IRS CASADO2
    FILE* file2 = fopen("irs2.txt", "r");
    j = 0;
    while (!feof(file2)) {
        fscanf(file2, "%f %f %f %f %f %f %f",
                &irs2[0][j],
                &irs2[1][j],
                &irs2[2][j],
                &irs2[3][j],
                &irs2[4][j],
                &irs2[5][j],
                &irs2[6][j]);
        /*printf("%g %g %g %g %g %g %g\n",
                irs2[0][j],
                irs2[1][j],
                irs2[2][j],
                irs2[3][j],
                irs2[4][j],
                irs2[5][j],
                irs2[6][j]);*/
        j++;
    }
    fclose(file2);
}

void printirs(float** irs) {
    int j = 0, i = 0;
    printf("\t0\t1\t2\t3\t4\t5\t6\n");
    do {
        printf("%2d.| %5.0f | %.3f | %.3f | %.3f | %.3f | %.3f |  %.3f\n",
                i,
                irs[0][j],
                irs[1][j],
                irs[2][j],
                irs[3][j],
                irs[4][j],
                irs[5][j],
                irs[6][j]);
        j++;
        i++;
    } while (i < 36);
}

void salvarvaloresIRS(float **irs0, float **irs1, float **irs2) {
    FILE* file0 = fopen("irs0.txt", "w");
    //CARREGAR ARREIO COM A PERCENTAGEM DE IRS

    for (int j = 0; j < Y_IRS; j++) {
        fprintf(file0, "%f %f %f %f %f %f %f\n",
                irs0[0][j],
                irs0[1][j],
                irs0[2][j],
                irs0[3][j],
                irs0[4][j],
                irs0[5][j],
                irs0[6][j]);
    }
    fclose(file0);

    //IRS CASADO1
    FILE* file1 = fopen("irs1.txt", "w");

    for (int i = 0; i < Y_IRS; i++) {
        fprintf(file1, "%f %f %f %f %f %f %f\n",
                irs1[0][i],
                irs1[1][i],
                irs1[2][i],
                irs1[3][i],
                irs1[4][i],
                irs1[5][i],
                irs1[6][i]);
    }
    fclose(file1);

    //IRS CASADO2
    FILE* file2 = fopen("irs2.txt", "w");

    for (int j = 0; j < Y_IRS; j++) {
        fprintf(file2, "%f %f %f %f %f %f %f\n",
                irs2[0][j],
                irs2[1][j],
                irs2[2][j],
                irs2[3][j],
                irs2[4][j],
                irs2[5][j],
                irs2[6][j]);
    }
    fclose(file2);
}

void editarirs0(float** irs0) {
    int j = 0, i = 0, x, y, op;

    printirs(irs0);

    do {
        printf("\n1. alterar\n"
                "0.sair\n=");
        scanf("%d", &op);
        if (op == 1) {
            printf("\nx=");
            scanf("%d", &x);
            printf("\ny=");
            scanf("%d", &y);
            printf("\nnovo valor=");
            scanf("%f", &irs0[x][y]);
            printirs(irs0);
        }
    } while (op);
}

void editarirs(float **irs0, float **irs1, float **irs2) {
    int op;
    do {
        printf("\n--Editar Irs--\n"
                "1.IRS Solteiro\n"
                "2.IRS Casado 1 Titular\n"
                "3.IRS Casado 2 Titular\n"
                "0.Sair\n"
                "=");
        scanf("%d", &op);
        switch (op) {
            case 1:
                editarirs0(irs0);
                break;
            case 2:
                editarirs0(irs1);
                break;
            case 3:
                editarirs0(irs2);
                break;
            case 0:
                break;
            default:
                clear();
                puts(OP_INVALIDA);
                break;
        }
    } while (op != 0);
}

void printVencimentos(InfoFuncionario **funcionarios, int func) {
    printf("\n---SALARIO---\n\n");
    for (int i = 0; i < (*funcionarios)[func].MesesTrabalhados; i++) {
        printf("mes: %d ano: %d\n"
                "Salario: %.2f\n"
                "Salario liquido: %.2f\n\n",
                (*funcionarios)[func].TrabalhoMes[i].Data.Mes,
                (*funcionarios)[func].TrabalhoMes[i].Data.Ano,
                (*funcionarios)[func].TrabalhoMes[i].salario,
                (*funcionarios)[func].TrabalhoMes[i].salarioliquido);
    }
}

void calcularirsSS(InfoFuncionario **funcionarios, int func, float **irs, float **ss) {
    int salario;
    for (int mes = 0; mes < (*funcionarios)[func].MesesTrabalhados; mes++) {
        //SALARIO
        (*funcionarios)[func].TrabalhoMes[mes].salario =
                (*funcionarios)[func].TrabalhoMes[mes].DiasInteiros * (*funcionarios)[func].SalarioPorHora * DIAINTEIRO
                + (*funcionarios)[func].TrabalhoMes[mes].MeiosDias * (*funcionarios)[func].SalarioPorHora * MEIODIA
                + (*funcionarios)[func].TrabalhoMes[mes].FimDeSemana * (*funcionarios)[func].SalarioPorHora * DIAINTEIRO * 1.5;
        //TAXA DE IRS
        for (int j = 0; j < Y_IRS; j++) {
            if ((*funcionarios)[func].TrabalhoMes[mes].salario <= irs[0][j]) {
                salario = j - 1;
                //printf("%f\n", irs[0][j]);
                break;
            }
        }

        printf("salario:%d\n", salario);

        int i = (*funcionarios)[func].NumeroDeFilhos;
        printf("\n%d\n", (*funcionarios)[func].NumeroDeFilhos);
        i = i + 1;
        (*funcionarios)[func].TrabalhoMes[mes].irs = irs[i][salario];

        printf("irs:%f\n", irs[i][salario]);
        printf("irs:%f\n", (*funcionarios)[func].TrabalhoMes[mes].irs);

        if ((*funcionarios)[func].Cargo == Empregado) {
            (*funcionarios)[func].TrabalhoMes[mes].ss = ss[0][1];
            printf("ss:%f\n", (*funcionarios)[func].TrabalhoMes[mes].ss);
        }
        if ((*funcionarios)[func].Cargo == Chefe ||
                (*funcionarios)[func].Cargo == Administrador) {
            (*funcionarios)[func].TrabalhoMes[mes].ss = ss[2][1];
            printf("ss:%f\n", (*funcionarios)[func].TrabalhoMes[mes].ss);
        }
        //CALCULAR IRS
                (*funcionarios)[func].TrabalhoMes[mes].salarioliquido =
                (*funcionarios)[func].TrabalhoMes[mes].salario
                - (*funcionarios)[func].TrabalhoMes[mes].salario * (*funcionarios)[func].TrabalhoMes[mes].irs
                - (*funcionarios)[func].TrabalhoMes[mes].salario * (*funcionarios)[func].TrabalhoMes[mes].ss
                + (*funcionarios)[func].SubsidioAlimentacao * (*funcionarios)[func].TrabalhoMes[mes].DiasInteiros
                + (*funcionarios)[func].SubsidioAlimentacao * (*funcionarios)[func].TrabalhoMes[mes].MeiosDias
                + (*funcionarios)[func].SubsidioAlimentacao * (*funcionarios)[func].TrabalhoMes[mes].FimDeSemana;

        /*for (int mes = 0; mes < (*funcionarios)[func].MesesTrabalhados; mes++) {
            printf("\n\nmes: %d ano: %d\n"
                    "Salario: %.2f\n"
                    "Salario liquido: %.2f\n",
                    (*funcionarios)[func].TrabalhoMes[mes].Data.Mes,
                    (*funcionarios)[func].TrabalhoMes[mes].Data.Ano,
                    (*funcionarios)[func].TrabalhoMes[mes].salario,
                    (*funcionarios)[func].TrabalhoMes[mes].salarioliquido);
        }*/
    }
    //ESTE CLEAR LIMPA O IRS E SS PARA TESTE
    //
    clear();
    //printVencimentos(funcionarios, func);
}

int DescubrirMes(InfoFuncionario funcionario, int mes, int ano) {

    for (int i = 0; i < funcionario.MesesTrabalhados; i++) {
        if (mes == funcionario.TrabalhoMes[i].Data.Mes &&
                ano == funcionario.TrabalhoMes[i].Data.Ano) {
            return i;
        }
    }
    return -1;
}

int TestarData(int ano, int mes, int total, int *anos, int *meses) {
    for (int i = 0; i < total; i++) {

        if (ano == anos[i] && mes == meses[i]) {
            return -1;
        }
    }
    return 1;
}

void ApresentarDatas(InfoFuncionario *funcionarios, int numFuncionarios) {

    int total = 0;
    int *anos = malloc(sizeof (int));
    int *meses = malloc(sizeof (int));

    for (int i = 0; i < numFuncionarios; i++) {
        for (int u = 0; u < funcionarios[i].MesesTrabalhados; u++) {
            if (TestarData(
                    funcionarios[i].TrabalhoMes[u].Data.Ano,
                    funcionarios[i].TrabalhoMes[u].Data.Mes,
                    total, anos, meses) == 1) {
                total++;
                anos = realloc(anos, sizeof (int)*total);
                meses = realloc(meses, sizeof (int)*total);

                anos[total - 1] = funcionarios[i].TrabalhoMes[u].Data.Ano;
                meses[total - 1] = funcionarios[i].TrabalhoMes[u].Data.Mes;
            }
        }
    }

    for (int i = 0; i < total; i++) {
        printf("Mes %d  Ano %d \n",
                meses[i],
                anos[i]);
    }

    printf("\n\n");
}

void GastosEmpresa(InfoFuncionario *funcionarios, int numFuncionarios) {

    int num, total = 0;
    int mes, ano;
    FILE *txtSalario;

    printf("Datas Possiveis: \n");
    ApresentarDatas(funcionarios, numFuncionarios);

    printf("Insira a data que deseja ver\n");
    printf("Mes: ");
    InserirInt(&mes, 1, 12);
    printf("Ano: ");
    InserirInt(&ano, 2000, 3000);
    clear();

    printf("-------Salarios-------\n");
    printf("Mes: %d  Ano: %d \n\n", mes, ano);

    for (int i = 0; i < numFuncionarios; i++) {

        num = DescubrirMes(funcionarios[i], mes, ano);

        if (num != -1) {
            printf("Codigo: %d  Nome: %s  Salario: %.2f \n\n",
                    funcionarios[i].Codigo,
                    funcionarios[i].Nome,
                    funcionarios[i].TrabalhoMes[num].salarioliquido);

            total += funcionarios[i].TrabalhoMes[num].salarioliquido;
        }
    }
    // Nao está acabado -------------------------------------------
    printf("Gastos Empresa: %d \n\n", total);

    printf("Esta informacao está em Salarios.txt\n\n");

    // Informacao no txt
    txtSalario = fopen(SALARIO, "w");

    fprintf(txtSalario, "-------Salarios-------\n"
            "Mes: %d  Ano: %d \n\n", mes, ano);


    for (int i = 0; i < numFuncionarios; i++) {

        num = DescubrirMes(funcionarios[i], mes, ano);

        if (num != -1) {
            fprintf(txtSalario, "Codigo: %d  Nome: %s  Salario: %.2f \n\n",
                    funcionarios[i].Codigo,
                    funcionarios[i].Nome,
                    funcionarios[i].TrabalhoMes[num].salarioliquido);
        }
    }

    fprintf(txtSalario, "Gastos Empresa: %d \n", total);

    fclose(txtSalario);

}

void Vencimentos(InfoFuncionario **funcionarios, int numeroFuncionarios) {

    int func, opcao, i;

    float** ss = malloc((sizeof (float*) * X_SS));
    for (int j = 0; j < X_SS; j++) {
        ss[j] = malloc(sizeof (float)* Y_SS);
    }
    //CARREGAR VALORES SS
    carregarvalorsSS(ss);

    float** irs0 = malloc(sizeof (float*) * X_IRS);
    for (int j = 0; j < X_IRS; j++) {
        irs0[j] = malloc(sizeof (float)*Y_IRS);
    }

    float** irs1 = malloc(sizeof (float*) * X_IRS);
    for (int j = 0; j < X_IRS; j++) {
        irs1[j] = malloc(sizeof (float)*Y_IRS);
    }

    float** irs2 = malloc(sizeof (float*) * X_IRS);
    for (int j = 0; j < X_IRS; j++) {
        irs2[j] = malloc(sizeof (float)*Y_IRS);
    }

    carregarvaloresIRS(irs0, irs1, irs2);
    //MENU IRS
    do {
        printf("\n---MENU VENCIMENTOS---\n"
                "1.Calcular Vencimentos do funcionario no Mes\n"
                "2.Calculo dos Salarios num mes e gastos da empresa\n"
                "3.Editar Valores de IRS\n"
                "4.Guardar Valores de IRS\n"
                "5.Alterar Valores SEGURANÇA SOCIAL\n"
                "6.Guardar Valores SEGURANÇA SOCIAL\n"
                "0.Sair\n"
                "=");
        scanf("%d", &opcao);
        clear();

        for (int i = 0; i < numeroFuncionarios; i++) {

            //CALCULAR IRS
            if ((*funcionarios)[i].EstadoCivil == Solteiro ||
                    (*funcionarios)[i].EstadoCivil == Divorciado ||
                    (*funcionarios)[i].EstadoCivil == Viuvo) {
                calcularirsSS(funcionarios, i, irs0, ss);
            }
            if ((*funcionarios)[i].EstadoCivil == Casado1) {
                calcularirsSS(funcionarios, i, irs1, ss);
            }
            if ((*funcionarios)[i].EstadoCivil == Casado2) {
                calcularirsSS(funcionarios, i, irs2, ss);
            }
        }

        switch (opcao) {
            case 0:
                break;
            case 1:
                ListaFuncionarios(*funcionarios, numeroFuncionarios);
                printf("\n\n");
                printf("Selecionar funcionário: \n"
                        "-1 para Sair \n");
                scanf("%d", &func);

                i = VerificarFuncionario(*funcionarios, func, numeroFuncionarios);
                //CALCULAR IRS
                if (i != -1) {
                    if ((*funcionarios)[i].EstadoCivil == Solteiro ||
                            (*funcionarios)[i].EstadoCivil == Divorciado ||
                            (*funcionarios)[i].EstadoCivil == Viuvo) {
                        printVencimentos(funcionarios, i);
                    }
                    if ((*funcionarios)[i].EstadoCivil == Casado1) {
                        printVencimentos(funcionarios, i);
                    }
                    if ((*funcionarios)[i].EstadoCivil == Casado2) {
                        printVencimentos(funcionarios, i);
                    }
                }
                break;
            case 2:
                GastosEmpresa(*funcionarios, numeroFuncionarios);
                break;
            case 3:
                editarirs(irs0, irs1, irs2);
                clear();
                break;
            case 4:
                salvarvaloresIRS(irs0, irs1, irs2);
                clear();
                break;
            case 5:
                altrarvalorss(ss);
                clear();
                break;
            case 6:
                salvarvaloresSS(ss);
                break;
            default:
                clear();
                puts(OP_INVALIDA);
                break;
        }
    } while (opcao != 0);
}
