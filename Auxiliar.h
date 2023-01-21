#ifndef AUXILIAR_H
#define AUXILIAR_H

/*
 * FUNÇÕES AUXILIARES
 * 
 * 1 INTRODUÇAO DE INFORMAÇÃO
 * 2 CARREGAR/GUARDAR FUNCIONARIOS
 * 3 PRINT INFORMAÇÃO
 */

#include <stdio.h>
#include <stdlib.h>

#define FUNCIONARIOS "Funcionarios.bin"

#define OP_INVALIDA "   !opção inválida!"

void clear();

int VerificarAnoMes(int ano, int mes, InfoFuncionario funcionario);

void printmes(InfoFuncionario *funcionarios, int func);

void InserirInt(int *Numero, int Minimo, int Maximo);

void InserirFloat(float *Numero, float Minimo, float Maximo);

void InserirCargo(enum cargo *Numero, int Minimo, int Maximo);

void InserirEstadoCivil(enum estadoCivil *Numero, int Minimo, int Maximo);

void ApresentarCargo(enum cargo Cargo);

void ApresentarEstadocivil(enum cargo EstadoCivil);

int VerificarFuncionario(InfoFuncionario funcionarios[], int codigo, int numeroFuncionarios);

void ListaFuncionarios(InfoFuncionario *funcionarios, int numeroFuncionarios);

void ListaFuncionariosRemovidos(InfoFuncionario funcionariosRemovidos[], int numeroFuncionariosRemovidos);

void SalvarFuncionarios(
        InfoFuncionario funcionarios[], int numFuncionarios,
        InfoFuncionario funcionariosRemovidos[], int numFuncionariosRemovidos,
        int codigo);

void LoadFuncionarios(
        InfoFuncionario **funcionarios, int *numFuncionarios,
        InfoFuncionario **funcionariosRemovidos, int *numFuncionariosRemovidos,
        int *codigo);

#endif /* AUXILIAR_H */

