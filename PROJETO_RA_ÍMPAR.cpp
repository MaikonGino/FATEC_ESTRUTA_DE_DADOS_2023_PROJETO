#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>

using namespace std;

const int MAX_SOCIOS = 100;
const int MAX_REGISTROS = 100;
const int MAX_NOME_TITULAR = 50;

const char* LISTA_SOCIO = "D:\\GITHUB\\FATEC_ESTRUTA_DE_DADOS_2023_PROJETO\\LISTA_SOCIO.txt";

struct Socio {
    int numeroTitulo;
    char nomeTitular[MAX_NOME_TITULAR];
    int numeroDependente1;
    int numeroDependente2;
    bool pagamentoMensalidade;
};

struct RegistroPortaria {
    int numeroTitulo;
    char nome[MAX_NOME_TITULAR];
    bool entrada;  // true para entrada, false para saída
};

void inserirSocio(Socio socios[], int& totalSocios, Socio novoSocio) {
    if (totalSocios < MAX_SOCIOS) {
        socios[totalSocios++] = novoSocio;
    } else {
        cout << "Limite de sócios atingido." << endl;
    }
}

void listarSocios(const Socio socios[], int totalSocios) {
    for (int i = 0; i < totalSocios; ++i) {
        cout << "Número do Título: " << socios[i].numeroTitulo << endl;
        cout << "Nome do Titular: " << socios[i].nomeTitular << endl;
        cout << "Número do Dependente 1: " << socios[i].numeroDependente1 << endl;
        cout << "Número do Dependente 2: " << socios[i].numeroDependente2 << endl;
        cout << "Pagamento da Mensalidade: " << (socios[i].pagamentoMensalidade ? "Em dia" : "Inadimplente") << endl;
        cout << "-----------------------------" << endl;
    }
}

void removerSocio(Socio socios[], int& totalSocios, int numeroTitulo) {
    for (int i = 0; i < totalSocios; ++i) {
        if (socios[i].numeroTitulo == numeroTitulo) {
            for (int j = i; j < totalSocios - 1; ++j) {
                socios[j] = socios[j + 1];
            }
            --totalSocios;
            cout << "Sócio removido com sucesso." << endl;
            return;
        }
    }

    cout << "Sócio não encontrado." << endl;
}

void registrarEntrada(const Socio socios[], int totalSocios, RegistroPortaria registros[], int& totalRegistros, int numeroTitulo) {
    for (int i = 0; i < totalSocios; ++i) {
        if (socios[i].numeroTitulo == numeroTitulo && socios[i].pagamentoMensalidade) {
            registros[totalRegistros].numeroTitulo = socios[i].numeroTitulo;
            std::strncpy(registros[totalRegistros].nome, socios[i].nomeTitular, MAX_NOME_TITULAR - 1);
            registros[totalRegistros].nome[MAX_NOME_TITULAR - 1] = '\0';
            registros[totalRegistros].entrada = true;
            ++totalRegistros;
            cout << "Entrada registrada com sucesso." << endl;
            return;
        }
    }

    cout << "Sócio não encontrado ou inadimplente." << endl;
}

void registrarSaida(RegistroPortaria registros[], int& totalRegistros, int numeroTitulo) {
    for (int i = 0; i < totalRegistros; ++i) {
        if (registros[i].numeroTitulo == numeroTitulo && registros[i].entrada) {
            registros[i].entrada = false;
            cout << "Saída registrada com sucesso." << endl;
            return;
        }
    }

    cout << "Sócio não encontrado ou não registrado na entrada." << endl;
}

void gerarRelatorio(const RegistroPortaria registros[], int totalRegistros) {
    if (totalRegistros == 0) {
        cout << "Nenhuma entrada ou saída registrada." << endl;
        return;
    }

    ofstream arquivo(LISTA_SOCIO);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(arquivo.rdbuf());

    cout << "Relatório de Visitas:" << endl;
    cout << "=====================" << endl;

    for (int i = 0; i < totalRegistros; ++i) {
        cout << registros[i].numeroTitulo << " " << registros[i].nome << " ";
        cout << (registros[i].entrada ? "E" : "S") << endl;
    }

    cout.rdbuf(coutbuf);

    arquivo.close();

    cout << "Relatório salvo com sucesso em " << LISTA_SOCIO << "." << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    Socio socios[MAX_SOCIOS];
    RegistroPortaria registros[MAX_REGISTROS];
    int totalSocios = 0;
    int totalRegistros = 0;

    int opcao;
    do {
        cout << "Menu:" << endl;
        cout << "1. Inserir Sócio" << endl;
        cout << "2. Listar Sócios" << endl;
        cout << "3. Remover Sócio" << endl;
        cout << "4. Registrar Entrada" << endl;
        cout << "5. Registrar Saída" << endl;
        cout << "6. Gerar Relatório" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                Socio novoSocio;
                cout << "Digite o número do título: ";
                cin >> novoSocio.numeroTitulo;
                cout << "Digite o nome do titular: ";
                cin.ignore();
                cin.getline(novoSocio.nomeTitular, MAX_NOME_TITULAR);
                cout << "Digite o número do dependente 1: ";
                cin >> novoSocio.numeroDependente1;
                cout << "Digite o número do dependente 2: ";
                cin >> novoSocio.numeroDependente2;
                cout << "Pagamento da mensalidade em dia? (1 para Sim, 0 para Não): ";
                cin >> novoSocio.pagamentoMensalidade;

                inserirSocio(socios, totalSocios, novoSocio);
                break;
            }
            case 2:
                listarSocios(socios, totalSocios);
                break;
            case 3: {
                int numeroTitulo;
                cout << "Digite o número do título do sócio a ser removido: ";
                cin >> numeroTitulo;
                removerSocio(socios, totalSocios, numeroTitulo);
                break;
            }
            case 4: {
                int numeroTitulo;
                cout << "Digite o número do título do sócio para registrar entrada: ";
                cin >> numeroTitulo;
                registrarEntrada(socios, totalSocios, registros, totalRegistros, numeroTitulo);
                break;
            }
            case 5: {
                int numeroTitulo;
                cout << "Digite o número do título do sócio para registrar saída: ";
                cin >> numeroTitulo;
                registrarSaida(registros, totalRegistros, numeroTitulo);
                break;
            }
            case 6:
                gerarRelatorio(registros, totalRegistros);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
