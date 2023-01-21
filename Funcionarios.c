#include "EstruturaDados.h"
#include "Auxiliar.h"
#include "Funcionarios.h"
#include <string.h>

//O FICHEIRO DEVE ESTAR EM TXT E DEVE APRESENTAR
//CODIGO MES ANO DIAS INTEIROS MEIOS DIAS FINS DE SEMANA
void CarregarFciheiro(InfoFuncionario **funcionario, int numFuncionarios) {

    int i, DiasInteiros, FimDeSemana, MeiosDias, mes, ano;

    char filename[50], extensao[] = ".txt";

    printf("Insira o nome do ficheiro do mes (max 50 caracteres): ");
    scanf(" %[^\n]s", filename);

    strcat(filename, extensao);
    //printf("%s",filename);
    FILE * file = fopen(filename, "r");

    while (!feof(file)) {
        
        fscanf(file, "%d %d %d %d %d %d",
                &i,
                &mes,
                &ano,
                &DiasInteiros,
                &MeiosDias,
                &FimDeSemana);

        i = VerificarFuncionario(*funcionario, i, numFuncionarios);

        (*funcionario)[i].MesesTrabalhados++;
        int j = (*funcionario)[i].MesesTrabalhados - 1;
        
        (*funcionario)[i].TrabalhoMes = (TempoTrabalhado*) realloc(
                (*funcionario)[i].TrabalhoMes,
                sizeof (TempoTrabalhado)*(*funcionario)[i].MesesTrabalhados);
        
        //teste
        //printf("%d %d %d %d\n",i,j, FimDeSemana,);
        (*funcionario)[i].TrabalhoMes[j].DiasInteiros = DiasInteiros;
        (*funcionario)[i].TrabalhoMes[j].Data.Mes = mes;
        (*funcionario)[i].TrabalhoMes[j].Data.Ano = ano;
        (*funcionario)[i].TrabalhoMes[j].FimDeSemana = FimDeSemana;
        (*funcionario)[i].TrabalhoMes[j].MeiosDias = MeiosDias;
        
        printmes(*funcionario, i);
    }
    fclose(file);
}

void AdicionarMes(InfoFuncionario *funcionario) {

    int mes, ano, i;

    printf("Insira o Mes e Ano que deseja adicionar os dias de trabalho \n");

    printf("Mes: ");
    InserirInt(&mes, 1, 12);

    printf("Ano: ");
    InserirInt(&ano, 2000, 3000);

    i = VerificarAnoMes(ano, mes, *funcionario);

    if (i == -1) {
        (*funcionario).MesesTrabalhados++;
        i = (*funcionario).MesesTrabalhados - 1;

        (*funcionario).TrabalhoMes = (TempoTrabalhado*) realloc(
                (*funcionario).TrabalhoMes,
                sizeof (TempoTrabalhado)*(*funcionario).MesesTrabalhados);

        if ((*funcionario).TrabalhoMes == NULL) {
            printf("Erro a realocar memoria");
        }

        (*funcionario).TrabalhoMes[i].Data.Mes = mes;
        (*funcionario).TrabalhoMes[i].Data.Ano = ano;
    }

    printf("\n"
            "Insira o numero de dias inteiros trabalhados: ");
    InserirInt(&(*funcionario).TrabalhoMes[i].DiasInteiros, 0, 31);

    printf("\n"
            "Insira o numero de meios dias trabalhados: ");
    InserirInt(&(*funcionario).TrabalhoMes[i].MeiosDias, 0, 31);

    printf("\n"
            "Insira o numero de dias no fim de semana trabalhados: ");
    InserirInt(&(*funcionario).TrabalhoMes[i].FimDeSemana, 0, 10);

    clear();
}

void ApresentarDiasTrabalho(InfoFuncionario funcionario) {

    char filename[50], extensao[] = ".txt";

    printf("Insira o nome do ficheiro do mes (max 50 caracteres): ");
    scanf(" %s", filename);
    
    strcat(filename, extensao);
    
    FILE *ficheiro = fopen(filename, "w");

    fprintf(ficheiro, "Numero %d Funcionario %s \n\n", funcionario.Codigo, funcionario.Nome);

    for (int i = 0; i < funcionario.MesesTrabalhados; i++) {
        fprintf(ficheiro, "Mes %d  Ano %d : \n",
                funcionario.TrabalhoMes[i].Data.Mes,
                funcionario.TrabalhoMes[i].Data.Ano);
        fprintf(ficheiro,
                "Dias Inteiros %d \n"
                "Meios Dias %d \n"
                "Fins de Semana %d \n\n",
                funcionario.TrabalhoMes[i].DiasInteiros,
                funcionario.TrabalhoMes[i].MeiosDias,
                funcionario.TrabalhoMes[i].FimDeSemana);
    }


    fclose(ficheiro);
}

InfoFuncionario FuncionarioDiasTrabalhados(InfoFuncionario funcionario) {

    int opcao;

    printf("Insira a Opcao \n"
            "1  = Apresentar os Dias Trabalhados De Cada Mes num Ficheiro txt \n"
            "2  = Adicionar um Mes de Trabalho(Ou Editar) \n"
            "-1 = Sair \n\n");
    scanf("%d", &opcao);
    clear();



    do {

        if (opcao == 1) {
            ApresentarDiasTrabalho(funcionario);
            break;
        } else if (opcao == 2) {
            AdicionarMes(&funcionario);
            break;
        }
        if (opcao == -1) {
            break;
        }

    } while (1 == 1);


    return funcionario;
}

void SelecionarDiasTrabalhados(InfoFuncionario **funcionarios, int numFuncionarios) {

    int codigoDigitado;
    int IndiceFuncionario;

    ListaFuncionarios(*funcionarios, numFuncionarios);

    printf("\n"
            "Insira o funcionarios que deseja ver/adicionar dias de trabalho \n"
            "-2 = Carregar ficheiro\n"
            "-1 = Sair \n\n");
    scanf(" %d", &codigoDigitado);
    clear();

    while (1 == 1) {
        // Se nao quer voltar para o menu
        if (codigoDigitado == -2) {
            CarregarFciheiro(funcionarios, numFuncionarios);
            break;
        }
        if (codigoDigitado == -1) {
            break;
        } else {

            // Verificar se tem e qual é o funcionario com codigo igual ao inserido;
            IndiceFuncionario = VerificarFuncionario(*funcionarios, codigoDigitado, numFuncionarios);
            printmes(*funcionarios, IndiceFuncionario);
            if (IndiceFuncionario != -1) {

                (*funcionarios)[IndiceFuncionario] = FuncionarioDiasTrabalhados((*funcionarios)[IndiceFuncionario]);
                break;
            }// o codigo inserido está incorreto é pedido outro codigo ou a opcao de sair
            else {

                printf("\n"
                        "O Codigo inserido está incorreto \n"
                        "Insire outro codigo ou -1 para voltar \n\n");
                scanf("%d", &codigoDigitado);
                clear();

                // Se o codigo é diferente de -1 volta a testar toda a array de funcionarios
                if (codigoDigitado == -1) {

                    break;
                }
                // Se o codigo é diferente de -1 volta para o incio
                // para verificar se tem um codigo igual ao inserido
            }
        }
    }
}


// Apresentar todas as informacoes do Funcionario inserido

void InformacoesFuncionario(InfoFuncionario funcionario) {

    printf("\n\n");
    printf("Codigo: %d \n", funcionario.Codigo);
    printf("Nome: %s \n", funcionario.Nome);
    printf("Numero Telefone: %d \n", funcionario.NumeroTelefone);
    printf("Numero de Filhos: %d \n", funcionario.NumeroDeFilhos);
    ApresentarEstadocivil(funcionario.EstadoCivil);
    ApresentarCargo(funcionario.Cargo);
    printf("Salario Base por Hora: %.2f \n", funcionario.SalarioPorHora);
    printf("Subsidio de Alimentacao: %.2f \n", funcionario.SubsidioAlimentacao);
    printf("Data de Nascimento: %d %d %d \n",
            funcionario.DataNascimento.Dia,
            funcionario.DataNascimento.Mes,
            funcionario.DataNascimento.Ano);
    printf("Data de Entrada na Empresa: %d %d %d \n",
            funcionario.DataEntradaEmpresa.Dia,
            funcionario.DataEntradaEmpresa.Mes,
            funcionario.DataEntradaEmpresa.Ano);

    if (funcionario.DataSaidaEmpresa.Dia != -1) {
        printf("Data de Saida da Empresa: %d %d %d \n",
                funcionario.DataSaidaEmpresa.Dia,
                funcionario.DataSaidaEmpresa.Mes,
                funcionario.DataSaidaEmpresa.Ano);
    }
}

// Editar um funcionario inserido

InfoFuncionario EditarFuncionario(InfoFuncionario funcionario) {

    int opcao;
    do {
        printf("\n"
                "Qual Parte deseja editar ? \n"
                "Nome = 1 \n"
                "Numero Telefone = 2 \n"
                "Numero de Filhos = 3 \n"
                "Estado Civil = 4 \n"
                "Cargo = 5 \n"
                "Salario Base por Hora= 6 \n"
                "Subsidio de Alimentacao = 7 \n"
                "Data de Nascimento = 8 \n"
                "Data de entrada na empresa = 9 \n"
                "Sair = 0 \n");
        scanf("%d", &opcao);
        clear();
        // Editar o Funcionar conforme a opcao escolhida em cima
        switch (opcao) {

            case 1:
                printf("Nome: ");
                scanf(" %s", funcionario.Nome);
                break;

            case 2:
                printf("Numero de telefone: ");
                InserirInt(&funcionario.NumeroTelefone, 100000000, 1000000000);
                break;

            case 3:
                printf("Numero de filhos: ");
                InserirInt(&funcionario.NumeroDeFilhos, 0, 500);
                break;

            case 4:
                printf("Estado Civil \n"
                        "(Solteiro = 1,Casado 1 Titular = 2,Casado 2 Titulares =3 Divorciado = 4,Viuvo = 5) : ");
                InserirEstadoCivil(&funcionario.EstadoCivil, 1, 4);
                break;

            case 5:
                printf("Cargo \n"
                        "(Empregado = 1,Chefe = 2,Administrador = 3) : ");
                InserirCargo(&funcionario.Cargo, 1, 3);
                break;

            case 6:
                printf("Salario por hora: ");
                InserirFloat(&funcionario.SalarioPorHora, 0, 1000000);
                break;

            case 7:
                printf("Subsidio de Alimentacao: ");
                InserirFloat(&funcionario.SubsidioAlimentacao, 0, 1000000);
                break;

            case 8:
                printf("Data Nascimento(dia mes ano): ");
                InserirInt(&funcionario.DataNascimento.Dia, 1, 31);
                InserirInt(&funcionario.DataNascimento.Mes, 1, 12);
                InserirInt(&funcionario.DataNascimento.Ano, 2000, 3000);
                break;

            case 9:
                printf("Data de Entrada na Empresa(dia mes ano): ");
                InserirInt(&funcionario.DataEntradaEmpresa.Dia, 1, 31);
                InserirInt(&funcionario.DataEntradaEmpresa.Mes, 1, 12);
                InserirInt(&funcionario.DataEntradaEmpresa.Ano, 2000, 3000);

                break;

        }
    } while (opcao != 0);
    printf("\n");

    return funcionario;
}

void RemoverFuncionario(
        InfoFuncionario **funcionarios, int *numeroFuncionarios,
        InfoFuncionario **funcionariosRemovido, int *numeroFuncionariosRemovidos,
        int indiceFuncionario) {

    for (int i = 0; i < *numeroFuncionarios; i++) {
        free((*funcionarios)[i].TrabalhoMes);
        (*funcionarios)[i].TrabalhoMes = NULL;
    }

    printf("\nData de Saida da Empresa \n");
    printf("Dia: ");
    InserirInt(&(*funcionarios)[indiceFuncionario].DataSaidaEmpresa.Dia, 1, 31);
    printf("Mes: ");
    InserirInt(&(*funcionarios)[indiceFuncionario].DataSaidaEmpresa.Mes, 1, 12);
    printf("Ano: ");
    InserirInt(&(*funcionarios)[indiceFuncionario].DataSaidaEmpresa.Ano, 1900, 2100);
    clear();

    // Mover o funcionario para a array de Funcionarios Removidos
    *funcionariosRemovido = realloc(*funcionariosRemovido, sizeof (InfoFuncionario)*(++(*numeroFuncionariosRemovidos)));

    (*funcionariosRemovido)[*numeroFuncionariosRemovidos - 1] = (*funcionarios)[indiceFuncionario];

    (*numeroFuncionarios)--;

    // Mover todos os funcionarios que estavam a frente do funcionario removido
    // um espaço para trás para ocupar o espaço do funcionario removido
    for (int u = indiceFuncionario; u < *numeroFuncionarios; u++) {

        (*funcionarios)[u] = (*funcionarios)[u + 1];
    }
    *funcionarios = realloc(*funcionarios, sizeof (InfoFuncionario)*(*numeroFuncionarios));
}

void FuncionarioSelecionado(InfoFuncionario **funcionarios, int *numeroFuncionarios, int indiceFuncionario,
        InfoFuncionario **funcionariosRemovido, int *numeroFuncionariosRemovidos) {

    char editar;

    do {
        // Apresentar todas as informacoes do funcionario escolhido
        InformacoesFuncionario((*funcionarios)[indiceFuncionario]);

        printf("\n"
                "Deseja fazer alguma alteracao ? \n"
                "Editar Funcionario = E \n"
                "Remover = R \n"
                "Sair = S \n");
        scanf(" %c", &editar);
        clear();

        switch (editar) {
            case 'e':
            case 'E':
                (*funcionarios)[indiceFuncionario] = EditarFuncionario((*funcionarios)[indiceFuncionario]);
                break;
            case'r':
            case 'R':
                RemoverFuncionario(
                        funcionarios, numeroFuncionarios,
                        funcionariosRemovido, numeroFuncionariosRemovidos,
                        indiceFuncionario);
                editar = 's';
                break;
            case 's':
            case 'S':
                break;
            default:
                puts(OP_INVALIDA);
                break;
        }
    } while (editar != 's' && editar != 'S');

}


// Mostrar as opcoes na lista de funcionarios (Selecionar Alterar Remover)

void OpcoesListaFuncionarios(InfoFuncionario **funcionarios, int *numeroFuncionarios,
        InfoFuncionario **funcionariosRemovido, int *numeroFuncionariosRemovidos) {

    int codigoDigitado;
    char editar;

    int IndiceFuncionario;

    // Apresentar a Lista de Funcionarios na Empresa
    ListaFuncionarios(*funcionarios, *numeroFuncionarios);

    // Opcao de Selecionar algum funcionario ou voltar para o Menu
    printf("\n"
            "Se Deseja Selecionar Algum Funcionario Digite o seu Codigo \n"
            "Se Deseja Voltar atras Digite -1 \n"
            "Se Deseja Ver os Funcionarios Removidos -2 \n\n");
    scanf("%d", &codigoDigitado);
    clear();

    while (1 == 1) {
        // Se nao quer voltar para o menu
        if (codigoDigitado == -1) {
            break;
        } else if (codigoDigitado == -2) { // Funcionarios Removidos

            // Apresentar a Lista de Funcionarios Removidos
            ListaFuncionariosRemovidos(*funcionariosRemovido, *numeroFuncionariosRemovidos);

            printf("\n"
                    "Se Deseja Selecionar Algum Funcionario Digite o seu Codigo \n"
                    "Se Deseja Voltar atras Digite -1 \n");
            scanf("%d", &codigoDigitado);
            clear();

            if (codigoDigitado == -1) {
                break;
            }

            while (1 == 1) {
                // Verificar se tem e qual é o funcionario com codigo igual ao inserido;
                IndiceFuncionario = VerificarFuncionario(*funcionariosRemovido, codigoDigitado, *numeroFuncionariosRemovidos);

                if (IndiceFuncionario != -1) {

                    InformacoesFuncionario((*funcionariosRemovido)[IndiceFuncionario]);
                    printf("\n");
                    break;
                }// o codigo inserido está incorreto é pedido outro codigo ou a opcao de sair
                else {

                    printf("\n"
                            "O Codigo inserido está incorreto \n"
                            "Insire outro codigo ou -1 para voltar \n");
                    scanf("%d", &codigoDigitado);
                    clear();

                    // Se o codigo é diferente de -1 volta a testar toda a array de funcionarios
                    if (codigoDigitado == -1) {

                        break;
                    }
                    // Se o codigo é diferente de -1 volta para o incio
                    // para verificar se tem um codigo igual ao inserido
                }
            }
            break;
        } else { // Funcionarios 

            // Verificar se tem e qual é o funcionario com codigo igual ao inserido;
            IndiceFuncionario = VerificarFuncionario(*funcionarios, codigoDigitado, *numeroFuncionarios);

            if (IndiceFuncionario != -1) {

                FuncionarioSelecionado(funcionarios, numeroFuncionarios, IndiceFuncionario,
                        funcionariosRemovido, numeroFuncionariosRemovidos);
                break;
            }// o codigo inserido está incorreto é pedido outro codigo ou a opcao de sair
            else {

                printf("\n"
                        "O Codigo inserido está incorreto \n"
                        "Insire outro codigo ou -1 para voltar \n");
                scanf("%d", &codigoDigitado);
                clear();

                // Se o codigo é diferente de -1 volta a testar toda a array de funcionarios
                if (codigoDigitado == -1) {

                    break;
                }
                // Se o codigo é diferente de -1 volta para o incio
                // para verificar se tem um codigo igual ao inserido
            }
        }
    }
}

// Funcao Responsavel por adicionar um funcionario a Array de Funcionairos

void InserirFuncionario(InfoFuncionario **funcionario, int *codigo, int numeroFuncionarios) {

    (*funcionario)[numeroFuncionarios].Codigo = ++(*codigo);
    (*funcionario)[numeroFuncionarios].MesesTrabalhados = 0;
    (*funcionario)[numeroFuncionarios].DataSaidaEmpresa.Dia = -1;

    (*funcionario)[numeroFuncionarios].TrabalhoMes = (TempoTrabalhado*) malloc(sizeof (TempoTrabalhado));

    printf("Nome: ");
    scanf(" %s", (*funcionario)[numeroFuncionarios].Nome);

    printf("Numero de telefone: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].NumeroTelefone, 100000000, 1000000000);

    printf("Numero de filhos: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].NumeroDeFilhos, 0, 500);

    printf("Estado Civil \n"
            "(Solteiro = 1,Casado 1 Titular = 2,Casado 2 Titulares =3 Divorciado = 4,Viuvo = 5) : ");
    InserirEstadoCivil(&(*funcionario)[numeroFuncionarios].EstadoCivil, 1, 5);

    printf("Cargo \n"
            "(Empregado = 1,Chefe = 2,Administrador = 3) : ");
    InserirCargo(&(*funcionario)[numeroFuncionarios].Cargo, 1, 3);

    printf("Salario por hora: ");
    InserirFloat(&(*funcionario)[numeroFuncionarios].SalarioPorHora, 0, 1000000);

    printf("Subsidio de Alimentacao: ");
    InserirFloat(&(*funcionario)[numeroFuncionarios].SubsidioAlimentacao, 0, 1000000);

    printf("Data Nascimento(dia mes ano): ");
    printf("Dia: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].DataNascimento.Dia, 1, 31);
    printf("Mes: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].DataNascimento.Mes, 1, 12);
    printf("Ano: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].DataNascimento.Ano, 1900, 2100);

    printf("Data de Entrada na Empresa(dia mes ano): ");
    printf("Dia: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].DataEntradaEmpresa.Dia, 1, 31);
    printf("Mes: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].DataEntradaEmpresa.Mes, 1, 12);
    printf("Ano: ");
    InserirInt(&(*funcionario)[numeroFuncionarios].DataEntradaEmpresa.Ano, 1900, 2100);

    clear();
}
