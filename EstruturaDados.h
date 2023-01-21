#ifndef ESTRUTURADADOS_H
#define ESTRUTURADADOS_H


/*
 * ENUMERAÇÕES E ESTRURURAS
 * 
 * 1 ESTRUTURAS DE FUNCIONARIOS E RENDIMENTOS
 * 2 ENUMERAÇÕES DE CARGOS E ESTADO CIVIL
 */

enum cargo {
    Empregado = 1,
    Chefe,
    Administrador
};

enum estadoCivil {
    Solteiro = 1,
    Casado1,
    Casado2,
    Divorciado,
    Viuvo
};

typedef struct {
    int Dia, Mes, Ano;
} Data;

typedef struct{
    int Mes,Ano;
} MesTrabalho;

typedef struct {
    MesTrabalho Data;
    int DiasInteiros;
    int MeiosDias;
    int FimDeSemana;
    float salarioliquido, salario, irs, ss;
} TempoTrabalhado;

// Informacoes de cada funcionario

typedef struct {
    char Nome[50];
    int Codigo, NumeroTelefone, NumeroDeFilhos;
    enum estadoCivil EstadoCivil;
    enum cargo Cargo;
    float SalarioPorHora, SubsidioAlimentacao;
    Data DataNascimento, DataEntradaEmpresa, DataSaidaEmpresa;
    TempoTrabalhado *TrabalhoMes;
    int MesesTrabalhados;

} InfoFuncionario;



#endif /* ESTRUTURADADOS_H */

