#ifndef VENCIMENTOS_H
#define VENCIMENTOS_H

/*
 *FUNÇÕES DE CALCULO DE VENCIMENTOS
 * 
 * 1 CALCULAR VENCIMENTOS
 * 2 EDITAR/GUARDAR TABELAS DE IRS
 * 3 EDITAR/GUARDAR TABELAS DE SS
 */

#include <stdlib.h>
#include <stdio.h>

#define X_IRS 7
#define Y_IRS 36
#define X_SS 3
#define Y_SS 3

#define DIAINTEIRO 8
#define MEIODIA 4

#define SALARIO "Salario.txt"

void CarregarFciheiro(InfoFuncionario **funcionario, int numFuncionarios);

void printss(float **ss);

void carregarvalorsSS(float **ss);

void salvarvaloresSS(float **ss);

void altrarvalorss(float **ss);

//IRS

void carregarvaloresIRS(float **irs0, float **irs1, float **irs2);

void printirs(float** irs);

void salvarvaloresIRS(float **irs0, float **irs1, float **irs2);

void editarirs0(float** irs0);

void editarirs(float **irs0, float **irs1, float **irs2);

void printVencimentos(InfoFuncionario **funcionarios, int func);

void calcularirsSS(InfoFuncionario **funcionarios, int func, float **irs, float **ss);

int DescubrirMes(InfoFuncionario funcionario, int mes, int ano);

int TestarData(int ano, int mes, int total, int *anos, int *meses);

void ApresentarDatas(InfoFuncionario *funcionarios, int numFuncionarios);

void GastosEmpresa(InfoFuncionario *funcionarios, int numFuncionarios);

void Vencimentos(InfoFuncionario **funcionarios, int numeroFuncionarios);

#endif /* VENCIMENTOS_H */

