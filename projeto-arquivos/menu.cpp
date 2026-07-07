#include "menu.hpp"
#include "utils.hpp"
#include "usuarios.hpp"
#include "carro.hpp"
#include "sistema.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cstdio>
#include <cstdlib>

using namespace std;

void MenuSair()
{
    CLEAR;

    cout << "SAIR!" << endl;
    cout << endl;
    PAUSE;

    exit(0);
}

void MenuInicial(Sistema &sistema, Usuario *usuario_logado, Carro &carro_temp)
{
    carro_temp.LoadVeiculos(sistema);

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
            MenuLogin(usuario_logado, carro_temp, sistema);
            break;
        }
        case 2:
        {
            MenuCadastrarUsuario(sistema, usuario_logado, carro_temp);
            break;
        }
        case 3:
        {
            MenuSair();
            return;
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

void MenuLogin(Usuario *&usuario_logado, Carro &carro_temp, Sistema &sistema)
{
    // LOGIN

    CLEAR;

    bool sair_login = false;

    // PONTEIRO DO TIPO USUARIO QUE RECEBE O VALOR NULLPTR (VAZIO)
    Usuario *usuario_login = nullptr;
    Usuario usuario_temp_login;

    while (!sair_login)
    {
        CLEAR;

        cout << endl;
        cout << "-------------------------LOGIN-----------------------------" << endl;
        cout << endl;
        cout << "                       1 - CPF" << endl;
        cout << endl;
        cout << "                      2 - Senha" << endl;
        cout << endl;
        cout << "          3 - Retornar ao MENU DE CADASTRO / LOGIN" << endl;
        cout << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA:  ";

        int opcao_login = 0;
        cin >> opcao_login;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << endl;

        switch (opcao_login)
        {
        case 1:
        {
            // CPF / EMAIL / NOME

            CLEAR;

            bool cpf_email_nome_sair = false;

            while (!cpf_email_nome_sair)
            {
                CLEAR;

                cout << endl;
                cout << "-----------------------------------------------CPF------------------------------------------------------" << endl;
                cout << endl;
                cout << "Digite o seu CPF para fazer o login (ou digite MENU para voltar ao MENU DE LOGIN): " << endl;

                string login;
                getline(cin, login);

                cout << endl;
                cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                cout << endl;

                // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
                for (size_t i = 0; i < login.length(); i++)
                {
                    login[i] = toupper((unsigned char)login[i]);
                }

                if (login == "MENU")
                {
                    if (RetornarAoMenuDeLogin())
                    {
                        cpf_email_nome_sair = true;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    for (size_t i = 0; i < login.length(); i++)
                    {
                        login[i] = tolower((unsigned char)login[i]);
                    }
                    // CHECAR SE O USUARIO EXISTE

                    // O PONTEIRO ANTERIORMENTE CRIADO RECEBE O VALOR GERADO NA FUNCAO CRAIDA ANTERIORMENTE
                    usuario_login = usuario_temp_login.BuscaBinariaUsuarioPorCpf(sistema, login);

                    if (usuario_login != nullptr)
                    {
                        cpf_email_nome_sair = true;
                        cout << "CPF encontrado, prossiga com a senha!" << endl;
                        cout << endl;
                        PAUSE;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Usuario NAO encontrado!" << endl;
                        cout << endl;
                        cout << "Tente NOVAMENTE!" << endl;
                        cout << endl;

                        PAUSE;
                    }
                }
            }

            break;
        }

        case 2:
        {
            // SENHA

            CLEAR;

            bool sair_procurar_senha = false;

            while (!sair_procurar_senha)
            {
                CLEAR;

                cout << endl;
                cout << "---------------------------------------SENHA-------------------------------------" << endl;
                cout << endl;
                cout << "Digite a sua SENHA (ou digite MENU para voltar ao MENU DE LOGIN):  ";

                string senha_login;
                getline(cin, senha_login);

                cout << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
                cout << endl;

                string senha_para_menu = senha_login;

                for (size_t i = 0; i < senha_para_menu.length(); i++)
                {
                    senha_para_menu[i] = toupper((unsigned char)senha_para_menu[i]);
                }

                if (senha_para_menu == "MENU")
                {
                    if (RetornarAoMenuDeLogin())
                    {
                        sair_procurar_senha = true;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {

                    if (usuario_login == nullptr)
                    {
                        cout << endl;
                        cout << "ERRO! Faca o login com CPF primeiro!" << endl;
                        cout << endl;

                        PAUSE;

                        if (RetornarAoMenuDeLogin())
                        {
                            sair_procurar_senha = true;
                        }
                        else
                        {
                            continue;
                        }
                    }

                    if (usuario_login != nullptr && usuario_login->getSenha() == senha_login)
                    {
                        cout << endl;
                        cout << "Login REALIZADO com sucesso!" << endl;
                        cout << endl;

                        usuario_logado = usuario_login;

                        MenuPrincipal(sistema, usuario_logado, carro_temp);

                        break;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Senha INCORRETA! Tente novamente!";
                        cout << endl;

                        PAUSE;
                    }
                }
            }

            break;
        }

        case 3:
        {
            // RETORNAR AO MENU DE CADASTRO

            if (RetornarAoMenuDeCadastro_Login())
            {
                sair_login = true;
            }

            break;
        }

        default:
        {
            cout << endl;
            cout << "Opcao INVALIDA!" << endl;
            cout << endl;

            PAUSE;

            break;
        }
        }
    }
}

void MenuCadastrarUsuario(Sistema &sistema, Usuario *usuario_logado, Carro &carro_temp)
{
    Usuario usuario_temp;
    bool sair = false;

    while (!sair)
    {
        CLEAR;

        cout << "--------------------------CADASTRO DE USUARIO--------------------------" << endl;
        cout << endl;
        cout << "                              1 - CPF" << endl;
        cout << endl;
        cout << "                         2 - Nome Completo" << endl;
        cout << endl;
        cout << "                             3 - E-mail" << endl;
        cout << endl;
        cout << "                             4 - Senha" << endl;
        cout << endl;
        cout << "                            5 - Salvar" << endl;
        cout << endl;
        cout << "            6 - Retornar ao MENU DE CADASTRO / LOGIN" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Digite a OPCAO DESEJADA: ";

        int opcao = 0;
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao)
        {
        case 1:
        {
            usuario_temp.cadastrarCPF(sistema, usuario_temp);
            break;
        }
        case 2:
        {
            usuario_temp.cadastrarNome(usuario_temp);
            break;
        }
        case 3:
        {
            usuario_temp.cadastrarEmail(sistema, usuario_temp);
            break;
        }
        case 4:
        {
            usuario_temp.cadastrarSenha(usuario_temp);
            break;
        }
        case 5:
        {
            if (usuario_temp.SalvarUsuario(sistema, usuario_temp))
            {
                usuario_temp.ExportarUsuario(usuario_temp);
                cout << endl
                     << "Usuario CADASTRADO com sucesso!" << endl;

                PAUSE;
                string cpf = usuario_logado->getCpf();

                usuario_logado = usuario_temp.BuscaBinariaUsuarioPorCpf(sistema, cpf);
                sair = true;

                MenuPrincipal(sistema, usuario_logado, carro_temp);
            }
            else
            {
                cout << endl
                     << "Preencha todos os campos antes de salvar!" << endl;
                PAUSE;
            }
            break;
        }
        case 6:
        {
            if (RetornarAoMenuDeCadastro())
                sair = true;
            break;
        }
        default:
        {
            cout << endl
                 << "Opcao INVALIDA!" << endl;
            PAUSE;
        }
        }
    }
}

void MenuPrincipal(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp)
{
    if (usuario_logado->getCpf() != "11111111111")
    {
        MenuNormal(sistema, usuario_logado, carro_temp);
    }
    else
    {
        MenuPolicial(sistema, usuario_logado, carro_temp);
    }
}

void MenuNormal(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp)
{
    bool menu_normal = true;

    while (menu_normal)
    {
        CLEAR;

        cout << "--------------------------------------DETRAN-DF----------------------------------------" << endl;
        cout << endl;
        cout << usuario_logado->getNome() << " seja bem-vindo!" << endl;
        cout << endl;
        cout << "                              1 - Registrar Veiculo" << endl;
        cout << endl;
        cout << "                              2 - Checar Veiculo(s)" << endl;
        cout << endl;
        cout << "                                   3 - Sair" << endl;
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
            MenuRegistroVeiculo(sistema, usuario_logado, carro_temp);

            break;
        }
        case 2:
        {
            MenuChecarVeiculos(sistema, usuario_logado, carro_temp);

            break;
        }
        case 3:
        {
            MenuSair();
        }
        default:
        {
            break;
        }
        }
    }
}

void MenuPolicial(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp)
{
    while (true)
    {
        CLEAR;

        cout << "--------------------------------------DETRAN-DF----------------------------------------" << endl;
        cout << endl;
        cout << "Perfil Policial" << endl;
        cout << endl;
        cout << "                                1 - Aplicar multa" << endl;
        cout << endl;
        cout << "                                 2 - Checar CNH" << endl;
        cout << endl;
        cout << "                                    3 - Sair" << endl;
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
            MenuAplicarMulta(sistema, usuario_logado, carro_temp);
            break;
        }
        case 2:
        {
            MenuChecarCnh(sistema, usuario_logado);
            break;
        }
        case 3:
        {
            MenuSair();
            return;
        }
        default:
        {
            CLEAR;
            cout << "Opcao invalida!" << endl;
            PAUSE;
        }
        }
    }
}

void MenuRegistroVeiculo(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp)
{
    bool sair_registro = false;

    while (!sair_registro)
    {
        CLEAR;

        cout << endl;
        cout << "------------------------REGISTRO DE VEICULO-----------------------" << endl;
        cout << endl;
        cout << "                            1 - Placa" << endl;
        cout << endl;
        cout << "                            2 - Ano" << endl;
        cout << endl;
        cout << "                            3 - Cor" << endl;
        cout << endl;
        cout << "                           4 - Modelo" << endl;
        cout << endl;
        cout << "                           5 - Renavam" << endl;
        cout << endl;
        cout << "                           6 - Salvar" << endl;
        cout << endl;
        cout << "                   7 - Retornar ao menu principal" << endl;
        cout << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJDA: ";

        int registro_de_veiculo = 0;
        cin >> registro_de_veiculo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (registro_de_veiculo)
        {
        case 1:
        {
            // PLACA
            bool registrar_placa = false;

            while (!registrar_placa)
            {
                CLEAR;

                cout << endl;
                cout << "----------------------------REGISTRO DA PLACA----------------------------" << endl;
                cout << endl;
                cout << "                   1 - Placa CINZA / NORMAL" << endl;
                cout << endl;
                cout << "                   2 - Placa MERCOSUL" << endl;
                cout << endl;
                cout << "                   3 - Retornar ao menu de registro" << endl;
                cout << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << endl;

                cout << "Digite a OPCAO DESEJADA: ";

                int tipo_de_placa = 0;
                cin >> tipo_de_placa;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (tipo_de_placa)
                {
                case 1:
                {
                    // PLACA NORMAL / CINZA

                    carro_temp.cadastrarPlacaCinza(carro_temp);

                    registrar_placa = true;

                    break;
                }

                case 2:
                {
                    // PLACA MERCOSUL

                    carro_temp.cadastrarPlacaMercosul(carro_temp);

                    registrar_placa = true;

                    break;
                }

                case 3:
                {
                    // RETORNAR AO MENU DE REGISTRO

                    // ESSE IF CONCLUI A SINTAXE DO BOOL COMO FUNCAO CRIADO ANTERIORMENTE
                    if (RetornarAoMenuDeRegistro())
                    {
                        registrar_placa = true;
                    }

                    break;
                }

                default:
                {
                    cout << endl;
                    cout << "OPCAO INVALIDA!" << endl;
                    cout << endl;

                    PAUSE;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    break;
                }
                }
            }

            break;
        }

        case 2:
        {
            // ANO

            carro_temp.cadastrarAno(carro_temp);

            break;
        }

        case 3:
        {
            // COR

            carro_temp.cadastrarCor(carro_temp);

            break;
        }

        case 4:
        {
            // MODELO

            carro_temp.cadastrarModelo(carro_temp);

            break;
        }

        case 5:
        {
            // RENAVAM

            carro_temp.cadastrarRenavam(carro_temp);

            break;
        }

        case 6:
        {
            // SALVAR
            if (carro_temp.SalvarCarro(sistema, usuario_logado, carro_temp))
            {
                carro_temp.ExportarVeiculo(sistema);

                cout << endl;
                cout << "Carro CADASTRADO com sucesso!" << endl;
                cout << endl;

                PAUSE;

                carro_temp = Carro();

                sair_registro = true;
            }
            else
            {
                cout << "Por favor, preencha o(s) campo(s) acima antes de salvar!" << endl;
                cout << endl;

                PAUSE;
            }

            break;
        }

        case 7:
        {
            // RETORNAR AO MENU PRINCIPAL

            if (RetornarAoMenuPrincipal_Registro())
            {
                sair_registro = true;
            }

            break;
        }

        default:
        {
            cout << endl;
            cout << "OPCAO INVALIDA!" << endl;
            cout << endl;

            PAUSE;

            break;
        }
        }
    }
}

void MenuChecarVeiculos(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp)
{
    // CHECAR VEICULO (S)
    bool sair_checar_veiculos = false;

    while (!sair_checar_veiculos)
    {
        CLEAR;

        cout << "-------------------------CARRO(S) CADASTRADO(S)----------------------------------" << endl;
        cout << endl;

        if (usuario_logado->carros.empty())
        {
            cout << "Nenhum carro cadastrado!" << endl;
            cout << endl;
            cout << "Cadastre um carro primeiro!" << endl;
            cout << endl;

            PAUSE;

            sair_checar_veiculos = false;
            break;
        }

        int contador = 1;

        for (auto it = usuario_logado->carros.begin(); it != usuario_logado->carros.end(); it++)
        {
            cout << contador << " - ";
            if (!it->getPlacaCinza().empty())
            {
                cout << "Placa: " << it->getPlacaCinza() << " | ";
            }
            else
            {
                cout << "Placa: " << it->getPlacaMercosul() << " | ";
            }
            cout << "Modelo: " << it->getModelo() << endl;

            cout << endl;

            contador++;
        }

        auto it = usuario_logado->carros.begin();

        cout << endl;

        cout << "Escolha o carro que deseja checar: ";
        int escolha = 0;
        cin >> escolha;
        cout << endl;

        for (int i = 1; i < escolha && it != usuario_logado->carros.end(); i++)
        {
            it++;
        }

        CLEAR;

        if (it == usuario_logado->carros.end())
        {
            cout << "Carro invalido!" << endl;

            PAUSE;

            continue;
        }
        else
        {   cout<< "Informacoes do Carro: "<<endl;
            cout<< endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            if (!it->getPlacaCinza().empty())
            {
                cout << "Placa cinza: " << it->getPlacaCinza() << endl;
            }
            else
            {
                cout << "Placa mercosul: " << it->getPlacaMercosul() << endl;
            }
            cout << endl;
            cout << "Cor: " << it->getCor() << endl;
            cout << endl;
            cout << "Ano: " << it->getAno() << endl;
            cout << endl;
            cout << "Modelo: " << it->getModelo() << endl;
            cout << endl;
            cout << "Renavam: " << it->getRenavam() << endl;
            cout << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            cout << endl;

            cout << "------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << "               1 - Excluir Veiculo" << endl;
            cout << endl;
            cout << "               2 - Alterar Veiculo" << endl;
            cout << endl;
            cout << "               3 - Multas" << endl;
            cout << endl;
            cout<< "               4 - Gerar CRLV"<< endl;
            cout<< endl;
            cout << "               5 - Retornar ao MENU PRINCIPAL" << endl;
            cout << endl;
            cout << "---------------------------------------------------------------------------" << endl;
            cout << endl;

            cout << "Digite a OPCAO DESEJADA: " << endl;

            int opcao_checar_veiculos = 0;
            cin >> opcao_checar_veiculos;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (opcao_checar_veiculos)
            {
            case 1:
            {
                // EXCLUIR VEICULO
                carro_temp.ExcluirVeiculos(sistema, usuario_logado, it);

                carro_temp.ExportarVeiculo(sistema);

                sair_checar_veiculos = true;

                break;
            }

            case 2:
            {
                // ALTERAR VEICULO
                carro_temp.AlterarVeiculo(sistema, usuario_logado, it);

                sair_checar_veiculos = true;

                break;
            }

            case 3:
            {
                // Multas

                carro_temp.Multas(sistema, usuario_logado, it);

                break;
            }
            
            case 4:
            {
                carro_temp.GerarCrlv(sistema, usuario_logado, it);

                break;
            }
            
            case 5:
            {
                // RETORNAR AO MENU PRINCIPAL
                if (RetornarAoMenuPrincipal_Checar())
                {
                    sair_checar_veiculos = true;
                }

                break;
            }

            default:
            {
                cout << endl;
                cout << "Opcao INVALIDA!" << endl;
                cout << endl;

                PAUSE;

                break;
            }
            }
        }
    }
}

void MenuAplicarMulta(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp)
{
    carro_temp.MultaRenavam(sistema, usuario_logado);

    return;
}

void MenuChecarCnh(Sistema &sistema, Usuario *&usuario_logado)
{
    bool menu_checar_cnh = true;

    while (menu_checar_cnh)
    {
        CLEAR;

        cout << "-------------------------Checar CNH-------------------------" << endl;
        cout << endl;
        usuario_logado->ChecagemCnh(sistema);
        cout << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;

        menu_checar_cnh = false;
    }

    return;
}