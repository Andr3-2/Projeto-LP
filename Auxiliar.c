#include "EstruturaDados.h"
#include "Auxiliar.h"

void clear() {
    system("@cls||clear");
}

int VerificarAnoMes(int ano, int mes, InfoFuncionario funcionario) {

    for (int i = 0; i < funcionario.MesesTrabalhados; i++) {

        if (funcionario.TrabalhoMes[i].Data.Mes == mes && funcionario.TrabalhoMes[i].Data.Ano == ano) {
            return i;
        }
    }
    return -1;
}

void printmes(InfoFuncionario *funcionarios, int func) {
    printf("DIAS TRABALHADOS\n"
            "meses = %d\n\n", funcionarios[func].MesesTrabalhados);
    
    for (int i = 0; i < funcionarios[func].MesesTrabalhados; i++) {
        printf("mes: %d ano: %d\n"
                "dias inteiros: %d\n"
                "meios dias: %d\n"
                "fins de semana: %d\n\n",
                funcionarios[func].TrabalhoMes[i].Data.Mes,
                funcionarios[func].TrabalhoMes[i].Data.Ano,
                funcionarios[func].TrabalhoMes[i].DiasInteiros,
                funcionarios[func].TrabalhoMes[i].MeiosDias,
                funcionarios[func].TrabalhoMes[i].FimDeSemana);
    }
}

void InserirInt(int *Numero, int Minimo, int Maximo) {

    do {
        scanf("%d", Numero);

        if (*Numero <= Maximo && *Numero >= Minimo) {
            return;
        }
        printf("O Valor esta incorreto \n");

    } while (1 == 1);

}

void InserirFloat(float *Numero, float Minimo, float Maximo) {

    do {
        scanf("%f", Numero);

        if (*Numero <= Maximo && *Numero >= Minimo) {
            return;
        }
        printf("O Valor esta incorreto \n");

    } while (1 == 1);

}

void InserirCargo(enum cargo *Numero, int Minimo, int Maximo) {

    do {
        scanf("%d", Numero);

        if (*Numero <= Maximo && *Numero >= Minimo) {
            return;
        }
        printf("O Valor esta incorreto \n");

    } while (1 == 1);

}

void InserirEstadoCivil(enum estadoCivil *Numero, int Minimo, int Maximo) {

    do {
        scanf("%d", Numero);

        if (*Numero <= Maximo && *Numero >= Minimo) {
            return;
        }
        printf("O Valor esta incorreto \n");

    } while (1 == 1);

}

void ApresentarCargo(enum cargo Cargo) {

    printf("Cargo: ");
    switch (Cargo) {

        case Empregado:
            printf("Empregado");
            break;

        case Chefe:
            printf("Chefe");
            break;
        case Administrador:
            printf("Administrador");
            break;
    }
    printf("\n");
}

void ApresentarEstadocivil(enum cargo EstadoCivil) {

    printf("Estado Civil: ");
    switch (EstadoCivil) {

        case Solteiro:
            printf("Solteiro");
            break;

        case Casado1:
            printf("Casado 1 Titular");
            break;

        case Casado2:
            printf("Casado 2 Titulares");
            break;

        case Divorciado:
            printf("Divorciado");
            break;

        case Viuvo:
            printf("Viuvo");
            break;
    }
    printf("\n");
}

int VerificarFuncionario(InfoFuncionario funcionarios[], int codigo, int numeroFuncionarios) {

    for (int i = 0; i < numeroFuncionarios; i++) {
        if (funcionarios[i].Codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void ListaFuncionarios(InfoFuncionario *funcionarios, int numeroFuncionarios) {

    if (numeroFuncionarios > 0) {

        printf("\n\n"
                "----------Funcionarios------------ "
                "\n\n");

        for (int i = 0; i < numeroFuncionarios; i++) {

            printf("Codigo : %5d  Nome : %s \n", funcionarios[i].Codigo, funcionarios[i].Nome);
        }
    }
}

void ListaFuncionariosRemovidos(InfoFuncionario funcionariosRemovidos[], int numeroFuncionariosRemovidos) {

    if (numeroFuncionariosRemovidos > 0) {

        printf("\n\n"
                "----------Funcionarios Removidos------------ "
                "\n\n");

        for (int i = 0; i < numeroFuncionariosRemovidos; i++) {

            printf("Codigo : %5d  Nome : %s \n", funcionariosRemovidos[i].Codigo, funcionariosRemovidos[i].Nome);
        }
    }
}

void SalvarFuncionarios(
        InfoFuncionario funcionarios[], int numFuncionarios,
        InfoFuncionario funcionariosRemovidos[], int numFuncionariosRemovidos,
        int codigo) {

    FILE *fFuncionarios = fopen(FUNCIONARIOS, "wb");

    fprintf(fFuncionarios, "%d \n", numFuncionarios);
    fprintf(fFuncionarios, "%d \n", numFuncionariosRemovidos);
    fprintf(fFuncionarios, "%d \n", codigo);

    fwrite(funcionarios, sizeof (InfoFuncionario), numFuncionarios, fFuncionarios);

    for (int i = 0; i < numFuncionarios; i++) {
        fwrite(funcionarios[i].TrabalhoMes, sizeof (TempoTrabalhado), funcionarios[i].MesesTrabalhados, fFuncionarios);
    }

    fwrite(funcionariosRemovidos, sizeof (InfoFuncionario), numFuncionariosRemovidos, fFuncionarios);

    fclose(fFuncionarios);
}

void LoadFuncionarios(
        InfoFuncionario **funcionarios, int *numFuncionarios,
        InfoFuncionario **funcionariosRemovidos, int *numFuncionariosRemovidos,
        int *codigo) {

    FILE *fFuncionarios = fopen(FUNCIONARIOS, "rb");

    fscanf(fFuncionarios, "%d \n", numFuncionarios);
    fscanf(fFuncionarios, "%d \n", numFuncionariosRemovidos);
    fscanf(fFuncionarios, "%d \n", codigo);

    *funcionarios = (InfoFuncionario*) realloc(*funcionarios, sizeof (InfoFuncionario)*(*numFuncionarios));
    if (*funcionarios == NULL) {
        printf("Erro a realocar memoria");
    }

    fread(*funcionarios, sizeof (InfoFuncionario), *numFuncionarios, fFuncionarios);

    for (int i = 0; i < *numFuncionarios; i++) {

        (*funcionarios)[i].TrabalhoMes =
                (TempoTrabalhado*) malloc(sizeof (TempoTrabalhado)*((*funcionarios)[i].MesesTrabalhados));

        fread((*funcionarios)[i].TrabalhoMes, sizeof (TempoTrabalhado), (*funcionarios)[i].MesesTrabalhados, fFuncionarios);
    }

    *funcionariosRemovidos = realloc(*funcionariosRemovidos, sizeof (InfoFuncionario)*(*numFuncionariosRemovidos));
    fread(*funcionariosRemovidos, sizeof (InfoFuncionario), *numFuncionariosRemovidos, fFuncionarios);

    fclose(fFuncionarios);
}
