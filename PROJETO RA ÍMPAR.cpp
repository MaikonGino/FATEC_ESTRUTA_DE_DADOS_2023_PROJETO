#include <iostream>

const int MAX_SOCIOS = 100;
const int MAX_REGISTROS = 100;

struct Socio {
    int numeroTitulo;
    char* nomeTitular;
    int numeroDependente1;
    int numeroDependente2;
    bool pagamentoMensalidade;
};

struct RegistroPortaria {
    int numeroTitulo;
    char* nome;
    bool entrada;  // true para entrada, false para sa�da
};

void inserirSocio(Socio* socios[], int& totalSocios, Socio* novoSocio) {
    if (totalSocios < MAX_SOCIOS) {
        socios[totalSocios++] = novoSocio;
    } else {
        std::cout << "Limite de s�cios atingido." << std::endl;
        delete novoSocio->nomeTitular;
        delete novoSocio;
    }
}

void listarSocios(Socio* socios[], int totalSocios) {
    for (int i = 0; i < totalSocios; ++i) {
        std::cout << "N�mero do T�tulo: " << socios[i]->numeroTitulo << std::endl;
        std::cout << "Nome do Titular: " << socios[i]->nomeTitular << std::endl;
        std::cout << "N�mero do Dependente 1: " << socios[i]->numeroDependente1 << std::endl;
        std::cout << "N�mero do Dependente 2: " << socios[i]->numeroDependente2 << std::endl;
        std::cout << "Pagamento da Mensalidade: " << (socios[i]->pagamentoMensalidade ? "Em dia" : "Inadimplente") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

void removerSocio(Socio* socios[], int& totalSocios, int numeroTitulo) {
    for (int i = 0; i < totalSocios; ++i) {
        if (socios[i]->numeroTitulo == numeroTitulo) {
            delete[] socios[i]->nomeTitular;
            delete socios[i];

            // Remover s�cio movendo os outros elementos para frente
            for (int j = i; j < totalSocios - 1; ++j) {
                socios[j] = socios[j + 1];
            }
            --totalSocios;
            std::cout << "S�cio removido com sucesso." << std::endl;
            return;
        }
    }

    std::cout << "S�cio n�o encontrado." << std::endl;
}

void carregarDados(Socio* socios[], int& totalSocios, const char* nomeArquivo) {
    // Implementa��o da leitura do arquivo aqui
    std::cout << "Fun��o de leitura de arquivo n�o implementada." << std::endl;
}

void registrarPortaria(const Socio* socios[], int totalSocios, RegistroPortaria registros[], int& totalRegistros) {
    // Implementa��o do registro de portaria aqui
    std::cout << "Fun��o de registro de portaria n�o implementada." << std::endl;
}

void gerarRelatorio(const RegistroPortaria registros[], int totalRegistros) {
    // Implementa��o do relat�rio aqui
    std::cout << "Fun��o de gera��o de relat�rio n�o implementada." << std::endl;
}

void gerarRelatorioArquivo(const RegistroPortaria registros[], int totalRegistros, const char* nomeArquivo) {
    // Implementa��o da gera��o de relat�rio em arquivo aqui
    std::cout << "Fun��o de gera��o de relat�rio em arquivo n�o implementada." << std::endl;
}

void liberarMemoria(Socio* socios[], int totalSocios) {
    for (int i = 0; i < totalSocios; ++i) {
        delete[] socios[i]->nomeTitular;
        delete socios[i];
    }
}

int main() {
    Socio* socios[MAX_SOCIOS];
    RegistroPortaria registros[MAX_REGISTROS];
    int totalSocios = 0;
    int totalRegistros = 0;

    int opcao;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Inserir S�cio" << std::endl;
        std::cout << "2. Listar S�cios" << std::endl;
        std::cout << "3. Remover S�cio" << std::endl;
        std::cout << "4. Carregar Dados" << std::endl;
        std::cout << "5. Registrar Portaria" << std::endl;
        std::cout << "6. Gerar Relat�rio" << std::endl;
        std::cout << "7. Gerar Relat�rio (Arquivo)" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma op��o: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                Socio* novoSocio = new Socio;
                novoSocio->nomeTitular = new char[50];

                std::cout << "Digite o n�mero do t�tulo: ";
                std::cin >> novoSocio->numeroTitulo;
                std::cout << "Digite o nome do titular: ";
                std::cin >> novoSocio->nomeTitular;
                std::cout << "Digite o n�mero do dependente 1: ";
                std::cin >> novoSocio->numeroDependente1;
                std::cout << "Digite o n�mero do dependente 2: ";
                std::cin >> novoSocio->numeroDependente2;
                std::cout << "Pagamento da mensalidade em dia? (1 para Sim, 0 para N�o): ";
                std::cin >> novoSocio->pagamentoMensalidade;

                inserirSocio(socios, totalSocios, novoSocio);
                break;
            }
            case 2:
                listarSocios(socios, totalSocios);
                break;
            case 3: {
                int numeroTitulo;
                std::cout << "Digite o n�mero do t�tulo do s�cio a ser removido: ";
                std::cin >> numeroTitulo;
                removerSocio(socios, totalSocios, numeroTitulo);
                break;
            }
            case 4: {
                char nomeArquivo[50];
                std::cout << "Digite o nome do arquivo para carregar os dados: ";
                std::cin >> nomeArquivo;
                carregarDados(socios, totalSocios, nomeArquivo);
                break;
            }
            case 5:
                registrarPortaria(socios, totalSocios, registros, totalRegistros);
                break;
            case 6:
                gerarRelatorio(registros, totalRegistros);
                break;
            case 7: {
                char nomeArquivo[50];
                std::cout << "Digite o nome do arquivo para salvar o relat�rio: ";
                std::cin >> nomeArquivo;
                gerarRelatorioArquivo(registros, totalRegistros, nomeArquivo);
                break;
            }
            case 0:
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Op��o inv�lida. Tente novamente." << std::endl;
                break;
        }

    } while (opcao != 0);

    // Liberar mem�ria antes de encerrar o programa
    liberarMemoria(socios, totalSocios);

    return 0;
}
