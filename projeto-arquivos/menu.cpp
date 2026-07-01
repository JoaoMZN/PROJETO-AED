#include "menu.hpp"
#include "utils.hpp"
#include "usuarios.hpp"
#include "carro.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cstdio>
#include <cstdlib>

using namespace std;

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
    else
    {
        ofstream arquivosVeiculosSistema("ArquivosVeiculosSistema.txt", ios::app);

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

        // remove("ArquivoVeiculosTemp.txt");

        cout << "SAIR!" << endl;
        cout << endl;

        PAUSE;

        exit(0);
    }
}

void MenuInicial(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros, vector<list<Usuario *>> &usuariosHash, vector<list<Carro *>> &carrosHash)
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
            MenuLogin(usuarios, usuario_logado, carro_temp, carros, usuariosHash, carrosHash);
            break;
        }
        case 2:
        {
            MenuCadastrarUsuario(usuarios, usuario_logado, carro_temp, carros, carrosHash, usuariosHash);
            break;
        }
        case 3:
        {
            MenuSair(usuario_logado);
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

void MenuLogin(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros, vector<list<Usuario *>> &usuariosHash, vector<list<Carro *>> &carrosHash)
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
                    usuario_login = usuario_temp_login.BuscaCpfHash(usuariosHash, login);

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
                        cout << "ERRO! Faca o login com CPF/EMAIL primeiro!" << endl;
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

                        if (usuario_logado->getCpf() != "11111111111")
                        {
                            carro_temp.LoadVeiculos(usuarios, carrosHash);
                        }
                        else
                        {
                            carro_temp.LoadVeiculosPolicia(usuario_logado);
                        }

                        MenuPrincipal(usuarios, usuario_logado, carro_temp, carros, carrosHash);

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

void MenuCadastrarUsuario(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros, vector<list<Carro *>> &carrosHash, vector<list<Usuario *>> &usuariosHash)
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
            usuario_temp.cadastrarCPF(usuario_temp, usuarios);
            break;
        }
        case 2:
        {
            usuario_temp.cadastrarNome(usuario_temp);
            break;
        }
        case 3:
        {
            usuario_temp.cadastrarEmail(usuario_temp, usuarios);
            break;
        }
        case 4:
        {
            usuario_temp.cadastrarSenha(usuario_temp);
            break;
        }
        case 5:
        {
            if (usuario_temp.SalvarUsuario(usuarios, usuario_temp, usuariosHash))
            {
                usuario_temp.ExportarUsuario(usuario_temp);
                cout << endl
                     << "Usuario CADASTRADO com sucesso!" << endl;

                PAUSE;
                usuario_logado = usuario_temp.BuscaBinariaUsuarioPorCpf(usuarios, usuario_temp.getCpf());
                sair = true;

                MenuPrincipal(usuarios, usuario_logado, carro_temp, carros, carrosHash);
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

void MenuPrincipal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros, vector<list<Carro *>> &carrosHash)
{
    if (usuario_logado->getCpf() != "11111111111")
    {
        MenuNormal(usuarios, usuario_logado, carro_temp, carrosHash, carros);
    }
    else
    {
        MenuPolicial(usuario_logado, usuarios, carros, carro_temp, carrosHash);
    }
}

void MenuNormal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, vector<list<Carro *>> &carrosHash, list<Carro> &carros)
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
        cout << "                                   3 - CRLV" << endl;
        cout << endl;
        cout << "                                   4 - Sair" << endl;
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
            MenuRegistroVeiculo(usuarios, usuario_logado, carro_temp, carrosHash, carros);

            break;
        }
        case 2:
        {
            MenuChecarVeiculos(usuarios, usuario_logado, carro_temp, carros);

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

void MenuPolicial(Usuario *&usuario_logado, list<Usuario> &usuarios, list<Carro> &carros, Carro &carro_temp, vector<list<Carro *>> &carrosHash)
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
            MenuAplicarMulta(carros, usuario_logado, carro_temp, usuarios, carrosHash);
            break;
        }
        case 2:
        {
            MenuChecarCnh(usuarios, usuario_logado);
            break;
        }
        case 3:
        {
            MenuSair(usuario_logado);
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

void MenuRegistroVeiculo(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, vector<list<Carro *>> &carrosHash, list<Carro> &carros)
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
            if (carro_temp.SalvarCarro(usuario_logado, carro_temp, carrosHash, carros, usuarios))
            {
                carro_temp.ExportarVeiculo(usuarios);

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

void MenuChecarVeiculos(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros)
{
    // CHECAR VEICULO (S)
    bool sair_checar_veiculos = false;

    while (!sair_checar_veiculos)
    {
        CLEAR;

        cout << "-------------------------CARRO(S) CADASTRADO(S)----------------------------------" << endl;
        cout << endl;

        if (carros.empty())
        {
            cout << "Nenhum carro cadastrado!" << endl;
            cout << endl;
            cout << "Cadastre um carro primeiro!" << endl;
            cout << endl;

            PAUSE;

            sair_checar_veiculos = false;
        }

        int contador = 1;

        auto it = carros.begin();

        for (; it != carros.end(); it++)
        {
            cout << contador << " - ";
            if (!it->getPlacaCinza().empty())
            {
                cout << it->getPlacaCinza() << " | ";
            }
            else
            {
                cout << it->getPlacaMercosul() << " | ";
            }
            cout << it->getModelo() << endl;

            contador++;
        }

        it = carros.begin();

        cout << "Escolha o carro que deseja alterar: ";
        int escolha = 0;
        cin >> escolha;
        cout << endl;

        for (int i = 1; i < escolha && it != carros.end(); i++)
        {
            it++;
        }

        if (it == carros.end())
        {
            cout << "Carro invalido!" << endl;

            PAUSE;

            continue;
        }
        else
        {
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
            cout << "               1 - Excluir Veiculo" << endl;
            cout << endl;
            cout << "               2 - Alterar Veiculo" << endl;
            cout << endl;
            cout << "               3 - Multas" << endl;
            cout << endl;
            cout << "               4 - Retornar ao MENU PRINCIPAL" << endl;
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
                carro_temp.ExcluirVeiculos(usuario_logado->carros);

                carro_temp.ExportarVeiculo(usuarios);

                sair_checar_veiculos = true;

                break;
            }

            case 2:
            {
                // ALTERAR VEICULO
                carro_temp.AlterarVeiculo(usuario_logado->carros, usuario_logado, usuarios);

                sair_checar_veiculos = true;

                break;
            }

            case 3:
            {
                // Multas

                carro_temp.Multas(usuario_logado->carros);

                break;
            }

            case 4:
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

void MenuCRLV(Usuario *&usuario_logado, Carro &carro_temp)
{
    // GERAR CRLV
    bool sair_crlv = false;

    while (!sair_crlv)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------CRLV------------------------------" << endl;
        cout << endl;
        cout << "               1 - Gerar CRLV" << endl;
        cout << endl;
        cout << "               2 - Exportar CRLV" << endl;
        cout << endl;
        cout << "               3 - Listar Veiculos" << endl;
        cout << endl;
        cout << "               4 - Retornar ao MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA:  ";

        int opcao_crlv = 0;
        cin >> opcao_crlv;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao_crlv)
        {
        case 1:
        {
            // GERAR CRLV
            carro_temp.GerarCrlv(usuario_logado->carros, usuario_logado);

            break;
        }

        case 2:
        {
            // EXPORTAR CRLV
            carro_temp.ExportarCrlv(usuario_logado->carros, usuario_logado);

            break;
        }

        case 3:
        {
            // LISTAR VEICULOS
            carro_temp.ListarVeiculos_CRLV(usuario_logado->carros);

            break;
        }

        case 4:
        {
            // RETORNAR AO MENU PRINCIPAL
            if (RetornarAoMenuPrincipal_Crlv())
            {
                sair_crlv = true;
            }
            else
            {
                continue;
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

void MenuAplicarMulta(list<Carro> &carros, Usuario *usuario_logado, Carro &carro_temp, list<Usuario> &usuarios, vector<list<Carro *>> &carrosHash)
{
    carro_temp.MultaRenavam(carros, usuario_logado, usuarios, carrosHash);

    return;
}

void MenuChecarCnh(list<Usuario> &usuarios, Usuario *&usuario_logado)
{
    bool menu_checar_cnh = true;

    while (menu_checar_cnh)
    {
        CLEAR;

        cout << "-------------------------Checar CNH-------------------------" << endl;
        cout << endl;
        usuario_logado->ChecagemCnh(usuarios);
        cout << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;

        menu_checar_cnh = false;
    }

    return;
}