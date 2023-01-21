#include <stdio.h>
#include <stdlib.h>
#include "EstruturaDados.h"
#include "Auxiliar.h"
#include "Vencimentos.h"
#include "Funcionarios.h"

int main(int argc, char** argv) {

    // Array dos Funcionarios atuais da empresa
    InfoFuncionario *funcionarios = (InfoFuncionario*) malloc(sizeof (InfoFuncionario));
    int numeroFuncionarios = 0;

    // Array dos Funcionarios Removidos da empresa
    InfoFuncionario *funcionariosRemovido = (InfoFuncionario*) malloc(sizeof (InfoFuncionario));
    int numeroFuncionariosRemovidos = 0;

    int codigo = 0;
    char opcao;

    do {
        printf("Deseja Carregar o ultimo Save ? (S/N) \n");
        scanf("%c", &opcao);
        clear();

        if (opcao == 's' || opcao == 'S') {
            LoadFuncionarios(&funcionarios, &numeroFuncionarios,
                    &funcionariosRemovido, &numeroFuncionariosRemovidos,
                    &codigo);
            break;
        } else if (opcao == 'n' || opcao == 'N') {
            break;
        }
        printf("Opcao invalida \n\n");
    } while (1 == 1); // Loop se nao for a opcao Valida


    do {

        printf("Insira a opcao: \n"
                "A = Adicionar Funcionario \n"
                "L = Lista de Funcionarios \n"
                "D = Dias Trabalhados \n"
                "V = Vencimentos\n"
                "S = Sair \n\n");
        scanf(" %c", &opcao);
        clear();

        switch (opcao) {

            case 'a':
            case 'A':
                // Chamar a funcao Funcionarios para Inserir um funcionario à Array dos funcionarios
                funcionarios = realloc(funcionarios, sizeof (InfoFuncionario)*(++numeroFuncionarios));
                // funcionarios[numeroFuncionarios - 1] = InserirFuncionario(funcionarios[numeroFuncionarios - 1], &codigo);
                InserirFuncionario(&funcionarios, &codigo, numeroFuncionarios - 1);
                break;

            case 'l':
            case 'L':
                // Apresentar toda a lista de Funcionarios na empresa e removidos
                OpcoesListaFuncionarios(&funcionarios, &numeroFuncionarios,
                        &funcionariosRemovido, &numeroFuncionariosRemovidos);
                break;

            case 'd':
            case 'D':
                SelecionarDiasTrabalhados(&funcionarios, numeroFuncionarios);
                break;

            case'v':
            case 'V':
                Vencimentos(&funcionarios, numeroFuncionarios);
                break;
        }
    } while (opcao != 's' && opcao != 'S');

    do {
        printf("Deseja Gravar ? (S/N) \n");
        scanf(" %c", &opcao);
        clear();

        if (opcao == 's' || opcao == 'S') {
            SalvarFuncionarios(
                    funcionarios, numeroFuncionarios,
                    funcionariosRemovido, numeroFuncionariosRemovidos,
                    codigo);
            break;
        } else if (opcao == 'n' || opcao == 'N') {
            break;
        }
        printf("Opcao invalida \n\n");
    } while (1 == 1); // Loop se nao for a opcao Valida

    for (int i = 0; i < numeroFuncionarios; i++) {
        free(funcionarios[i].TrabalhoMes);
        funcionarios[i].TrabalhoMes = NULL;
    }

    free(funcionarios);
    funcionarios = NULL;

    free(funcionariosRemovido);
    funcionariosRemovido = NULL;

    return (EXIT_SUCCESS);
}