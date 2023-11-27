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
    bool entrada;  // true para entrada, false para saída
};

void inserirSocio(Socio* socios[], int& totalSocios, Socio* novoSocio) {
    if (totalSocios < MAX_SOCIOS) {
        socios[totalSocios++] = novoSocio;
    } else {
        std::cout << "Limite de sócios atingido." << std::endl;
        delete novoSocio->nomeTitular;
        delete novoSocio;
    }
}

void listarSocios(Socio* socios[], int totalSocios) {
    for (int i = 0; i < totalSocios; ++i) {
        std::cout << "Número do Título: " << socios[i]->numeroTitulo << std::endl;
        std::cout << "Nome do Titular: " << socios[i]->nomeTitular << std::endl;
        std::cout << "Número do Dependente 1: " << socios[i]->numeroDependente1 << std::endl;
        std::cout << "Número do Dependente 2: " << socios[i]->numeroDependente2 << std::endl;
        std::cout << "Pagamento da Mensalidade: " << (socios[i]->pagamentoMensalidade ? "Em dia" : "Inadimplente") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

void removerSocio(Socio* socios[], int& totalSocios, int numeroTitulo) {
    for (int i = 0; i < totalSocios; ++i) {
        if (socios[i]->numeroTitulo == numeroTitulo) {
            delete[] socios[i]->nomeTitular;
            delete socios[i];

            // Remover sócio movendo os outros elementos para frente
            for (int j = i; j < totalSocios - 1; ++j) {
                socios[j] = socios[j + 1];
            }
            --totalSocios;
            std::cout << "Sócio removido com sucesso." << std::endl;
            return;
        }
    }

    std::cout << "Sócio não encontrado." << std::endl;
}

void carregarDados(Socio* socios[], int& totalSocios, const char* nomeArquivo) {
    // Implementação da leitura do arquivo aqui
    std::cout << "Função de leitura de arquivo não implementada." << std::endl;
}

void registrarPortaria(const Socio* socios[], int totalSocios, RegistroPortaria registros[], int& totalRegistros) {
    // Implementação do registro de portaria aqui
    std::cout << "Função de registro de portaria não implementada." << std::endl;
}

void gerarRelatorio(const RegistroPortaria registros[], int totalRegistros) {
    // Implementação do relatório aqui
    std::cout << "Função de geração de relatório não implementada." << std::endl;
}

void gerarRelatorioArquivo(const RegistroPortaria registros[], int totalRegistros, const char* nomeArquivo) {
    // Implementação da geração de relatório em arquivo aqui
    std::cout << "Função de geração de relatório em arquivo não implementada." << std::endl;
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
        std::cout << "1. Inserir Sócio" << std::endl;
        std::cout << "2. Listar Sócios" << std::endl;
        std::cout << "3. Remover Sócio" << std::endl;
        std::cout << "4. Carregar Dados" << std::endl;
        std::cout << "5. Registrar Portaria" << std::endl;
        std::cout << "6. Gerar Relatório" << std::endl;
        std::cout << "7. Gerar Relatório (Arquivo)" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                Socio* novoSocio = new Socio;
                novoSocio->nomeTitular = new char[50];

                std::cout << "Digite o número do título: ";
                std::cin >> novoSocio->numeroTitulo;
                std::cout << "Digite o nome do titular: ";
                std::cin >> novoSocio->nomeTitular;
                std::cout << "Digite o número do dependente 1: ";
                std::cin >> novoSocio->numeroDependente1;
                std::cout << "Digite o número do dependente 2: ";
                std::cin >> novoSocio->numeroDependente2;
                std::cout << "Pagamento da mensalidade em dia? (1 para Sim, 0 para Não): ";
                std::cin >> novoSocio->pagamentoMensalidade;

                inserirSocio(socios, totalSocios, novoSocio);
                break;
            }
            case 2:
                listarSocios(socios, totalSocios);
                break;
            case 3: {
                int numeroTitulo;
                std::cout << "Digite o número do título do sócio a ser removido: ";
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
                std::cout << "Digite o nome do arquivo para salvar o relatório: ";
                std::cin >> nomeArquivo;
                gerarRelatorioArquivo(registros, totalRegistros, nomeArquivo);
                break;
            }
            case 0:
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }

    } while (opcao != 0);

    // Liberar memória antes de encerrar o programa
    liberarMemoria(socios, totalSocios);

    return 0;
}
