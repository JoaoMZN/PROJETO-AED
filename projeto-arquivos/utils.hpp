#pragma once

#include <iostream>
#include <limits>

#ifdef _WIN32 // Macro
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif

#ifdef _WIN32
#define CLEAR system("cls")
#define PAUSE system("pause")
#else
#define CLEAR system("clear")
#define PAUSE                                                \
    {                                                        \
        cout << "Pressione Enter para continuar...";         \
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); \
        cin.get();                                           \
    }
#endif

inline bool RetornarAoMenuDeCadastro()
{
    CLEAR;

    bool retornar_ao_menu_de_cadastro = false;

    while (!retornar_ao_menu_de_cadastro)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de cadastro?" << endl;
        cout << endl;
        cout << "                       Nenhum dado sera salvo" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE CADASTRO / LOGIN" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar o CADASTRO DE USUARIO" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_de_cadastro = 0;
        cin >> opcao_menu_de_cadastro;

        switch (opcao_menu_de_cadastro)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuDeCadastro_Login()
{
    CLEAR;

    bool retornar_ao_menu_de_cadastro = false;

    while (!retornar_ao_menu_de_cadastro)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de cadastro?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE CADASTRO / LOGIN" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar o LOGIN" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_de_cadastro = 0;
        cin >> opcao_menu_de_cadastro;

        switch (opcao_menu_de_cadastro)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuDeLogin()
{
    CLEAR;

    bool retornar_ao_menu_de_login = false;

    while (!retornar_ao_menu_de_login)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao MENU DE LOGIN?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE LOGIN" << endl;
        cout << endl;
        cout << "                   2 - NAO, continuar o LOGIN" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_de_login = 0;
        cin >> opcao_menu_de_login;

        switch (opcao_menu_de_login)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuDeRegistro()
{
    CLEAR;

    bool retornar_ao_menu_de_registro = false;

    while (!retornar_ao_menu_de_registro)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de registro?" << endl;
        cout << endl;
        cout << "                       Nenhum dado sera salvo" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE REGISTRO" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar o CADASTRO DO VEICULO" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_de_registro = 0;
        cin >> opcao_menu_de_registro;

        switch (opcao_menu_de_registro)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuPrincipal_Registro()
{
    CLEAR;

    bool retornar_ao_menu_principal = false;

    while (!retornar_ao_menu_principal)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de principal?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE PRINCIPAL" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar o REGISTRO DO VEICULO" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_para_o_principal = 0;
        cin >> opcao_menu_para_o_principal;

        switch (opcao_menu_para_o_principal)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuPrincipal_Cadastro()
{
    CLEAR;

    bool retornar_ao_menu_principal = false;

    while (!retornar_ao_menu_principal)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de principal?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE PRINCIPAL" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar o CADASTRO / LOGIN de USUARIO" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_para_o_principal = 0;
        cin >> opcao_menu_para_o_principal;

        switch (opcao_menu_para_o_principal)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuPrincipal_Checar()
{
    CLEAR;

    bool retornar_ao_menu_principal = false;

    while (!retornar_ao_menu_principal)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de principal?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE PRINCIPAL" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar a CHECAGEM DE VEICULOS" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_para_o_principal = 0;
        cin >> opcao_menu_para_o_principal;

        switch (opcao_menu_para_o_principal)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuPrincipal_Multas()
{
    CLEAR;

    bool retornar_ao_menu_principal = false;

    while (!retornar_ao_menu_principal)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de principal?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE PRINCIPAL" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar em MULTAS" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_para_o_principal = 0;
        cin >> opcao_menu_para_o_principal;

        switch (opcao_menu_para_o_principal)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuPrincipal_Crlv()
{
    CLEAR;

    bool retornar_ao_menu_principal = false;

    while (!retornar_ao_menu_principal)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de principal?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE PRINCIPAL" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar em CRLV" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_para_o_principal = 0;
        cin >> opcao_menu_para_o_principal;

        switch (opcao_menu_para_o_principal)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuDeRegistro_Salvar()
{
    CLEAR;

    bool retornar_ao_menu_de_registro_salvar = false;

    while (!retornar_ao_menu_de_registro_salvar)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Voce quer mudar algum dado antes de SALVAR o veiculo" << endl;
        cout << endl;
        cout << "               1 - SIM, mudar ALGUM dado do veiculo" << endl;
        cout << endl;
        cout << "               2 - NAO, SALVAR veiculo" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_de_registro_salvar = 0;
        cin >> opcao_menu_de_registro_salvar;

        switch (opcao_menu_de_registro_salvar)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuDeVeiculos()
{
    CLEAR;

    bool retornar_ao_menu_de_veiculos = false;

    while (!retornar_ao_menu_de_veiculos)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao MENU DE VEICULOS?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DE VEICULOS" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar a CHECAGEM DE VEICULOS" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_veiculos = 0;
        cin >> opcao_menu_veiculos;

        switch (opcao_menu_veiculos)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuDeMultas()
{
    CLEAR;

    bool retornar_ao_menu_de_multas = false;

    while (!retornar_ao_menu_de_multas)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu de multas?" << endl;
        cout << endl;
        cout << "                               1 - SIM" << endl;
        cout << endl;
        cout << "                               2 - NAO" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_de_cadastro = 0;
        cin >> opcao_menu_de_cadastro;

        switch (opcao_menu_de_cadastro)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}

inline bool RetornarAoMenuPolicial()
{
    CLEAR;

    bool retornar_ao_menu_de_multas = false;

    while (!retornar_ao_menu_de_multas)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao menu policial?" << endl;
        cout << endl;
        cout << "                               1 - SIM" << endl;
        cout << endl;
        cout << "                               2 - NAO" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: " << endl;

        int opcao_menu_de_cadastro = 0;
        cin >> opcao_menu_de_cadastro;

        switch (opcao_menu_de_cadastro)
        {
        case 1:
        {
            return true;
        }

        case 2:
        {
            return false;
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

    return false;
}