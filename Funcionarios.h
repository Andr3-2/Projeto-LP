#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

/*
 * MAIN.C
 * 1 GESTAO  DE FUNCIONARIOS
 *   -> ADIÇÃO DE FUNCIONARIOS
 *   -> REMOÇÃO DE FUNCIONARIOS
 *   -> EDIÇÃO DE FUNCIONARIOS
 *   -> LISTAGEM DE FUNCIONARIOS
 * 2 DIAS TRABALHADOS
 */


#define HORAS_TRABALHADAS "HorasTrabalhadas.txt"

void AdicionarMes(InfoFuncionario *funcionario);

void ApresentarDiasTrabalho(InfoFuncionario funcionario);

InfoFuncionario FuncionarioDiasTrabalhados(InfoFuncionario funcionario);

void SelecionarDiasTrabalhados(InfoFuncionario **funcionarios, int numFuncionarios);

// Apresentar todas as informacoes do Funcionario inserido

void InformacoesFuncionario(InfoFuncionario funcionario);

// Editar um funcionario inserido

InfoFuncionario EditarFuncionario(InfoFuncionario funcionario);

void RemoverFuncionario(
        InfoFuncionario **funcionarios, int *numeroFuncionarios,
        InfoFuncionario **funcionariosRemovido, int *numeroFuncionariosRemovidos,
        int indiceFuncionario);

void FuncionarioSelecionado(InfoFuncionario **funcionarios, int *numeroFuncionarios, int indiceFuncionario,
        InfoFuncionario **funcionariosRemovido, int *numeroFuncionariosRemovidos);


// Mostrar as opcoes na lista de funcionarios (Selecionar Alterar Remover)

void OpcoesListaFuncionarios(InfoFuncionario **funcionarios, int *numeroFuncionarios,
        InfoFuncionario **funcionariosRemovido, int *numeroFuncionariosRemovidos);

// Funcao Responsavel por adicionar um funcionario a Array de Funcionairos

void InserirFuncionario(InfoFuncionario **funcionario, int *codigo, int numeroFuncionarios);

#endif /* FUNCIONARIOS_H */