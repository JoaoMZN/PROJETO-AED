#include "menu.hpp"
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

void MenuIncial(list<Usuario> &usuarios, Usuario *usuario_logado, Carro &carro_temp)
{
    while (true)
    {
        CLEAR;

        cout << "--------------------------------------DETRAN-DF----------------------------------------" << endl;
        cout << endl;
        cout << "                                 1 - Realizar Login" << endl;
        cout << endl;
        cout << "                               2 - Realizar Cadastro" << endl;
        cout << endl;
        cout << "                                       3 - Sair" << endl;
        cout << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;

        cout << "Digite a OPCAO desejada: ";
        int opcao = 0;
        cin >> opcao;

        switch (opcao)
        {
            case 1:
            {
                MenuLogin(usuarios, usuario_logado, carro_temp);
                break;
            }
            case 2:
            {
                MenuCadastrarUsuario(usuarios, usuario_logado);
                break;
            }
            case 3:
            {
                MenuSair(usuario_logado);
                break;
            }
            default:
            {
                CLEAR;
                cout << "Opcao invalida!" << endl;
                PAUSE;

                break;
            }
        }
    }
}

void MenuPrincipal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp)
{
    bool perfil_Policial = false;

    while (true)
    {
        CLEAR;

        cout << "--------------------------------------DETRAN-DF----------------------------------------" << endl;
        cout << endl;

        if (usuario_logado->getCpf() != "11111111111")
        {
            cout << "Seja Bem vindo " << usuario_logado->getNome() << "!" << endl;

            cout << endl;

            MenuNormal(usuarios, usuario_logado, carro_temp);
        }
        else
        {
            perfil_Policial = true;
            cout << "Perfil Policial" << endl;

            cout << endl;

            MenuPolicial(usuario_logado, usuarios);
        }

        cout << endl;

        if (perfil_Policial)
        {
            cout << "                      6 - Aplicar multa" << endl;
            cout << "                      7 - Checar CNH" << endl;
        }

        cout << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Digite a OPCAO DESEJADA: ";

        int opcao = 0;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            MenuCadastroLogin(usuarios, usuario_logado, carro_temp);
            break;
        case 2:
            MenuRegistroVeiculo(usuarios, usuario_logado, carro_temp);
            break;
        case 3:
            MenuChecarVeiculos(usuarios, usuario_logado, carro_temp);
            break;
        case 4:
            MenuCRLV(usuario_logado, carro_temp);
            break;
        case 5:
            MenuSair(usuario_logado);
            return;
        case 6:
            if (!perfil_Policial)
            {
                cout << "Opcao invalida!" << endl;
                PAUSE;
            }
            else
            {
                Carro multa_placa;
                multa_placa.MultaPlaca(usuario_logado->carros, usuario_logado);
            }
            break;
        case 7:
            if (!perfil_Policial)
            {
                cout << "Opcao invalida!" << endl;
                PAUSE;
            }
            else
            {
                usuario_logado->ChecagemCnh(usuarios);
            }
            break;
        default:
            cout << endl
                 << "OPCAO INVALIDA!" << endl
                 << endl;
            PAUSE;
        }
    }
}

void MenuNormal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp)
{
    cout << "                      1 - Registrar Veiculo" << endl;
    cout << endl;
    cout << "                      2 - Checar Veiculo(s)" << endl;
    cout << endl;
    cout << "                           3 - CRLV" << endl;
    cout << endl;
    cout << "                           4 - Sair" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "Digite a OPCAO desejada: ";
    int opcao = 0;
    cin >> opcao;

    switch (opcao)
    {
        case 1:
        {
            MenuRegistroVeiculo(usuarios, usuario_logado, carro_temp);

            break;
        }
        case 2:
        {
            MenuChecarVeiculos(usuarios, usuario_logado, carro_temp);

            break;
        }
        case 3:
        {
            MenuCRLV(usuario_logado, carro_temp);

            break;
        }
        case 4:
        {
            MenuSair(usuario_logado);

            break;
        }
        default:
        {
            CLEAR;

            cout << "Opcao invalida!" << endl;

            PAUSE;

            break;
        }
    }

}

void MenuPolicial(Usuario *&usuario_logado, list<Usuario> &usuarios)
{
    
    cout << "                      1 - Aplicar multa" << endl;
    cout << endl;
    cout << "                       2 - Checar CNH" << endl;
    cout << endl;
    cout << "                          3 - Sair" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "Digite a OPCAO desejada: ";
    int opcao = 0;
    cin >> opcao;

    switch (opcao)
    {
        case 1:
        {
            // arrumar para colocar um menu para aplica multa

            break;
        }
        case 2:
        {
            // arrumar para colocar para checar cnh

            break;
        }
        case 3:
        {
            MenuSair(usuario_logado);

            break;
        }
        default:
        {
            CLEAR;
            
            cout << "Opcao invalida!" << endl;

            PAUSE;
        }
    }
}

void MenuCadastroLogin(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp)
{
    bool sair = false;

    while (!sair)
    {
        CLEAR;
        cout << "--------------------------CADASTRO / LOGIN--------------------------" << endl;
        cout << "                   1 - Cadastrar Usuario" << endl;
        cout << "                   2 - Login" << endl;
        cout << "                   3 - Retornar ao menu principal" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Digite a OPCAO DESEJADA: ";

        int opcao = 0;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            MenuCadastrarUsuario(usuarios, usuario_logado);
            sair = true;
            break;
        case 2:
            MenuLogin(usuarios, usuario_logado, carro_temp);
            sair = true;
            break;
        case 3:
            if (RetornarAoMenuPrincipal_Cadastro())
                sair = true;
            break;
        default:
            cout << endl
                 << "Opcao INVALIDA!" << endl
                 << endl;
            PAUSE;
        }
    }
}

void MenuCadastrarUsuario(list<Usuario> &usuarios, Usuario *&usuario_logado)
{
    Usuario usuario_temp;
    bool sair = false;

    while (!sair)
    {
        CLEAR;
        cout << "--------------------------CADASTRO DE USUARIO--------------------------" << endl;
        cout << "                       1 - CPF" << endl;
        cout << "                       2 - Nome Completo" << endl;
        cout << "                       3 - E-mail" << endl;
        cout << "                       4 - Senha" << endl;
        cout << "                       5 - Salvar" << endl;
        cout << "            6 - Retornar ao MENU DE CADASTRO / LOGIN" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Digite a OPCAO DESEJADA: ";

        int opcao = 0;
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao)
        {
        case 1:
            usuario_temp.cadastrarCPF(usuario_temp, usuarios);
            break;
        case 2:
            usuario_temp.cadastrarNome(usuario_temp);
            break;
        case 3:
            usuario_temp.cadastrarEmail(usuario_temp, usuarios);
            break;
        case 4:
            usuario_temp.cadastrarSenha(usuario_temp);
            break;
        case 5:
            if (usuario_temp.SalvarUsuario(usuarios, usuario_temp))
            {
                usuario_temp.ExportarUsuario(usuario_temp);
                cout << endl
                     << "Usuario CADASTRADO com sucesso!" << endl
                     << endl;
                PAUSE;
                usuario_logado = usuario_temp.BuscaBinariaUsuarioPorCpf(usuarios, usuario_temp.getCpf());
                sair = true;
            }
            else
            {
                cout << endl
                     << "Preencha todos os campos antes de salvar!" << endl
                     << endl;
                PAUSE;
            }
            break;
        case 6:
            if (RetornarAoMenuDeCadastro())
                sair = true;
            break;
        default:
            cout << endl
                 << "Opcao INVALIDA!" << endl
                 << endl;
            PAUSE;
        }
    }
}

void MenuLogin(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp)
{
    // todo o conteúdo do case 2 (LOGIN) do seu main atual
}

void MenuRegistroVeiculo(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp)
{
    if (usuario_logado == nullptr)
    {
        cout << endl
             << "Faca LOGIN / CADASTRO para acessar REGISTRO DE VEICULO(s)!" << endl
             << endl;
        PAUSE;
        return;
    }
}

void MenuChecarVeiculos(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp)
{
    if (usuario_logado == nullptr)
    {
        cout << endl
             << "Faca LOGIN / CADASTRO para acessar CHECAR VEICULO(s)!" << endl
             << endl;
        PAUSE;
        return;
    }
}

void MenuCRLV(Usuario *&usuario_logado, Carro &carro_temp)
{
    if (usuario_logado == nullptr)
    {
        cout << endl
             << "Faca LOGIN / CADASTRO para acessar CRLV!" << endl
             << endl;
        PAUSE;
        return;
    }
}

void MenuSair(Usuario *&usuario_logado)
{
    CLEAR;

    if (usuario_logado == nullptr)
    {
        cout << "SAIR!" << endl;
        cout << endl;
        PAUSE;
        return;
    }

    ofstream arquivosVeiculosSistema("arquivosVeiculosSistema.txt", ios::app);

    if (!arquivosVeiculosSistema.is_open())
    {
        cout << endl;
        cout << "ERRO ao abrir o arquivo!" << endl;
        cout << endl;
        PAUSE;
        return;
    }

    for (auto it = usuario_logado->carros.begin(); it != usuario_logado->carros.end(); it++)
    {
        arquivosVeiculosSistema << "NOME: " << usuario_logado->getNome() << endl;
        arquivosVeiculosSistema << "CPF: " << usuario_logado->getCpf() << endl;

        if (!it->getPlacaCinza().empty())
            arquivosVeiculosSistema << "PLACA CINZA: " << it->getPlacaCinza() << endl;
        else if (!it->getPlacaMercosul().empty())
            arquivosVeiculosSistema << "PLACA MERCOSUL: " << it->getPlacaMercosul() << endl;

        arquivosVeiculosSistema << "ANO: " << it->getAno() << endl;
        arquivosVeiculosSistema << "COR: " << it->getCor() << endl;
        arquivosVeiculosSistema << "MODELO: " << it->getModelo() << endl;
        arquivosVeiculosSistema << "RENAVAM: " << it->getRenavam() << endl;
        arquivosVeiculosSistema << endl;
    }

    arquivosVeiculosSistema.close();

    cout << "SAIR!" << endl;
    cout << endl;

    PAUSE;
}