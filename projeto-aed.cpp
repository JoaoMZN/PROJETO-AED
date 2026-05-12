// JOAO MATHEUS ZULIANI NACHTIGALL 252030755
// 2026.01 Projeto final AED

/*COISAS A FAZER:
    arrumar o salvar cadastro de carro, colocar para construtor de class (Joao)
    arrumar a class CarroNovo, mudar para Carro e fazer os ajustes na main(Vitor e Pedro) (peguem e exemplo do cadastro de usuario e apliquem)
    bool salvar carro, arrumar (Vitor ou pedro)
    MUDAR PARA LISTA (PEDRO E VITOR)
    BUSCA BINARIA (PEDRO E VITOR)
*/

#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
#include <cctype>
#include <limits>
#include <fstream>
#include <locale.h>
#include <ctime>
#include <locale>

#ifdef _WIN32 //Macro
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif

using namespace std;

class Carro; // Só para saber que Carro é uma classe
// PRECISA SER UM BOOL, POIS SE NAO FOR, A PERGUNTA NUNCA VAI APARECER PORQUE NENHUMA VARIAVEL E ALTERADA DENTRO DA MAIN, AL TRANFORMAR PARA BOOL ESSA CONDICAO MUDA
bool RetornarAoMenuDeCadastro()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuDeCadastro_Login()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuDeLogin()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuDeRegistro()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuPrincipal_Registro()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuPrincipal_Cadastro()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuPrincipal_Checar()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuPrincipal_Multas()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuPrincipal_Crlv()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuDeRegistro_Salvar()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuDeVeiculos()
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

bool RetornarAoMenuDeCrlv()
{
    CLEAR;

    bool retornar_ao_menu_de_crlv = false;

    while (!retornar_ao_menu_de_crlv)
    {
        CLEAR;

        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "           Tem certeza que deseja retornar ao MENU DO CRLV?" << endl;
        cout << endl;
        cout << "               1 - SIM, retornar ao MENU DO CRLV" << endl;
        cout << endl;
        cout << "               2 - NAO, continuar" << endl;
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

            system("pause");

            break;
        }
        }
    }

    return false;
}

class Usuario
{
private:
    string nome, cpf, email, senha;

public:
    list<Carro> carros;
    list<Carro>::iterator carrosIT;
    Usuario()
    { // construtor
        carrosIT = carros.end();
    };

    void setNome(string n) // dá linha 43 até 78 são setters e getters para as variaveis privadas do Usuario.
    {
        this->nome = n;
    }
    string getNome()
    {
        return this->nome;
    }

    void setCpf(string c)
    {
        this->cpf = c;
    }
    string getCpf()
    {
        return this->cpf;
    }

    void setEmail(string e)
    {
        this->email = e;
    }
    string getEmail()
    {
        return this->email;
    }

    void setSenha(string s)
    {
        this->senha = s;
    }
    string getSenha()
    {
        return this->senha;
    };

    void cadastrarCPF(Usuario &usuario_temp, list<Usuario> &usuarios)
    {
        CLEAR;

        bool cadastrarCPF = false;

        string cpf_novo_temp;

        while (!cadastrarCPF)
        {
            CLEAR;

            cout << endl;
            cout << "----------------------------------------------CPF-------------------------------------------------" << endl;
            cout << endl;
            cout << "Digite o seu CPF (ou digite MENU para voltar ao MENU DE CADASTRO):  ";

            getline(cin >> ws, cpf_novo_temp);

            cout << endl;
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < cpf_novo_temp.length(); i++)
            {
                cpf_novo_temp[i] = toupper((unsigned char)cpf_novo_temp[i]);
            }

            if (cpf_novo_temp == "MENU")
            {
                if (RetornarAoMenuDeCadastro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cpf_novo_temp = "";

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cpf_novo_temp = "";

                    continue;
                }
            }

            // CHECA SE O CPF JA ESTA CADASTRADO
            bool cpf_registrado = false;

            for (auto it = usuarios.begin(); it != usuarios.end(); it++)
            {
                if (it->getCpf() == cpf_novo_temp)
                {
                    cpf_registrado = true;

                    break;
                }
            }

            if (cpf_registrado)
            {
                cout << endl;
                cout << "CPF ja REGISTRADO!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            bool somente_numeros = true;

            for (int i = 0; i < cpf_novo_temp.length(); i++)
            {
                if (!isdigit(cpf_novo_temp[i]))
                {
                    somente_numeros = false;

                    system("pause");

                    break;
                }
            }

            if (!somente_numeros)
            {
                cout << endl;
                cout << "Formato INVALIDO! Somente numeros sao aceitos!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            if (cpf_novo_temp.length() != 11)
            {
                cout << endl;
                cout << "Formato INVALIDO! Deve conter 11 numeros!" << endl;
                cout << endl;

                system("pause");

                continue;
            }
            else
            {
                // CPF CONDIZ COM AS CONDICOES E PODE SER CADASTRADO

                usuario_temp.setCpf(cpf_novo_temp);

                cout << endl;
                cout << "CPF cadastrado com sucesso!" << endl;
                cout << endl;

                system("pause");

                // SAI DO WHILE DO CPF
                cadastrarCPF = true;
            }
        }
    };

    void cadastrarNome(Usuario &usuario_temp)
    {
        CLEAR;

        bool sair_cadastrar_nome = false;

        string nome_novo_temp;

        while (!sair_cadastrar_nome)
        {
            CLEAR;

            cout << endl;
            cout << "------------------------------------------CADASTRAR NOME-------------------------------------------------" << endl;
            cout << endl;
            cout << "Digite seu NOME COMPLETO (ou MENU para voltar ao MENU DE CADASTRO):  ";

            getline(cin, nome_novo_temp);

            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < nome_novo_temp.length(); i++)
            {
                nome_novo_temp[i] = toupper((unsigned char)nome_novo_temp[i]);
            }

            if (nome_novo_temp == "MENU")
            {
                if (RetornarAoMenuDeCadastro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    nome_novo_temp = "";

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    nome_novo_temp = "";

                    continue;
                }
            }

            bool somente_letras = true;

            // CHECAR SE SAO APENAS LETRAS E ESPACOS
            for (int i = 0; i < nome_novo_temp.length(); i++)
            {
                if (!isalpha(nome_novo_temp[i]) && nome_novo_temp[i] != ' ')
                {
                    somente_letras = false;
                    break;
                }
            }

            if (!somente_letras)
            {
                cout << endl;
                cout << "Formato INVALIDO! Deve conter apenas letras!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            // SEGUNDO A LEGISLACAO BRASILEIRA, TODAS AS PESSOAS TEM DE TER UM NOME PROPRIO E UM SOBRENOME NO MINIMO
            int conta_espacos = 0;

            for (int i = 0; i < nome_novo_temp.length(); i++)
            {
                if (nome_novo_temp[i] == ' ')
                {
                    conta_espacos++;
                }
            }

            if (conta_espacos < 1)
            {
                cout << endl;
                cout << "Nome INCOMPLETO! Digite seu NOME e SOBRENOME!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            // NOME CORRETO

            usuario_temp.setNome(nome_novo_temp);

            cout << endl;
            cout << "Nome CADASTRADO com sucesso!" << endl;
            cout << endl;

            system("pause");

            sair_cadastrar_nome = true;
        }
    }

    void cadastrarEmail(Usuario &usuario_temp, list<Usuario> &usuarios)
    {
        CLEAR;

        bool sair_cadastrar_email = false;

        string email_novo_temp;

        while (!sair_cadastrar_email)
        {
            CLEAR;

            cout << endl;
            cout << "-----------------------------------------CADASTRAR EMAIL--------------------------------------------" << endl;
            cout << endl;
            cout << "Digite o seu EMAIL (ou MENU para voltar ao MENU DE CADASTRO):  ";

            getline(cin >> ws, email_novo_temp);

            cout << endl;
            cout << "----------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < email_novo_temp.length(); i++)
            {
                email_novo_temp[i] = toupper((unsigned char)email_novo_temp[i]);
            }

            if (email_novo_temp == "MENU")
            {
                if (RetornarAoMenuDeCadastro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    email_novo_temp = "";

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    email_novo_temp = "";

                    continue;
                }
            }

            // TRANSFORMA TODAS AS LETRAS PARA MINUSCULO
            for (int i = 0; i < email_novo_temp.length(); i++)
            {
                email_novo_temp[i] = tolower((unsigned char)email_novo_temp[i]);
            }

            // CHECA SE O EMAIL JA FOI REGISTRADO
            bool email_registrado = false;

            for (auto it = usuarios.begin(); it != usuarios.end(); it++)
            {
                if (it->getEmail() == email_novo_temp)
                {
                    email_registrado = true;

                    break;
                }
            }

            if (email_registrado)
            {
                cout << endl;
                cout << "EMAIL ja REGISTRADO!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            // CHECAR SE REALEMENTE E UM EMAIL
            bool emailValido = false;

            // O -1 INDICA QUE NADA FOI ENCONTRADO
            int posArroba = -1;
            int posPonto = -1;

            // PROCURA O @
            for (int i = 0; i < email_novo_temp.length(); i++)
            {
                if (email_novo_temp[i] == '@')
                {
                    posArroba = i;

                    break;
                }
            }

            // SE ENCONTROU O @
            if (posArroba != -1)
            {
                // PROUCURA UM PONTO APOS O @
                for (int i = posArroba + 1; i < email_novo_temp.length(); i++)
                {
                    if (email_novo_temp[i] == '.')
                    {
                        posPonto = i;

                        break;
                    }
                }
            }

            // VALIDA O EMAIL, O .LENGTH APARECE DENOVO, PORQUE ELE GARANTE QUE O PONTO NAO VA APARECER COMO ULTIMO CARACTERE DO EMAIL
            if (posArroba != -1 && posPonto != -1 && posPonto < email_novo_temp.length() - 1)
            {
                emailValido = true;
            }

            if (emailValido == false)
            {
                cout << endl;
                cout << "Formato INVALIDO! Cheque novamente o email digitado: " << email_novo_temp << endl;
                cout << endl;

                system("pause");

                continue;
            }
            else
            {
                // EMAIL CADASTRADO

                usuario_temp.setEmail(email_novo_temp);

                cout << endl;
                cout << "EMAIL cadastrado com sucesso!" << endl;
                cout << endl;

                system("pause");

                sair_cadastrar_email = true;
            }
        }
    }

    void cadastrarSenha(Usuario &usuario_temp)
    {
        CLEAR;

        bool sair_cadastrar_senha = false;

        string senha_nova_temp;

        while (!sair_cadastrar_senha)
        {
            CLEAR;

            cout << endl;
            cout << "-----------------------------------CADASTRAR SENHA-----------------------------------------------" << endl;
            cout << endl;
            cout << "Digite sua SENHA (ou MENU para voltar ao MENU DE CADASTRO):  ";

            getline(cin, senha_nova_temp);

            cout << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // COMO E UMA SENHA E ELA E ESPECIFICA, CRIA-SE UMA OUTRA STRING QUE RECEBE ELA, PARA ALTERAR ELA E NAO A SENHA
            string menu = senha_nova_temp;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < menu.length(); i++)
            {
                menu[i] = toupper((unsigned char)menu[i]);
            }

            if (menu == "MENU")
            {
                if (RetornarAoMenuDeCadastro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    senha_nova_temp = "";

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    senha_nova_temp = "";

                    continue;
                }
            }

            // A SENHA DEVE TER NO MINIMO 8 CARACTERES
            if (senha_nova_temp.length() < 8)
            {
                cout << endl;
                cout << "Formato INVALIDO! A senha deve ter no minimo 8 caracteres, essa tem apenas " << senha_nova_temp.length() << "!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            // CRIAR UMA REGRA PARA MONTAR A SENHA
            bool temLetras = false;

            bool temNumeros = false;

            for (int i = 0; i < senha_nova_temp.length(); i++)
            {
                if (isalpha(senha_nova_temp[i]))
                {
                    temLetras = true;
                }

                if (isdigit(senha_nova_temp[i]))
                {
                    temNumeros = true;
                }
            }

            if (temLetras != true || temNumeros != true)
            {
                cout << endl;
                cout << "Formato INVALIDO! A senha deve conter LETRAS E NUMEROS!" << endl;
                cout << endl;

                system("pause");

                continue;
            }
            else
            {
                // SENHA VALIDA

                usuario_temp.setSenha(senha_nova_temp);

                cout << endl;
                cout << "Senha cadastrada com sucesso!" << endl;
                cout << endl;

                system("pause");

                sair_cadastrar_senha = true;
            }
        }
    }

    bool SalvarUsuario(list<Usuario> &usuarios, Usuario &usuario_temp)
    {
        bool valido = true;

        // CHECAR SE TODOS OS CAMPOS DO CADASTRO FORAM PREENCHIDOS
        if (usuario_temp.getCpf().empty())
        {
            cout << endl;
            cout << "Preencha o CPF antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (usuario_temp.getNome().empty())
        {
            cout << endl;
            cout << "Preencha o NOME antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (usuario_temp.getEmail().empty())
        {
            cout << endl;
            cout << "Preencha o EMAIL antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (usuario_temp.getSenha().empty())
        {
            cout << endl;
            cout << "Preencha a SENHA antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (!valido)
        {
            return false;
        }

        usuarios.push_back(usuario_temp);

        return true;
    }

    void ExportarUsuario(Usuario &ususarios)
    {
        // ESSE VOID RETORNA APENAS ERROS NA TELA E MAIS NADA

        // APPEND, PERMITIR QUE NOVOS VEICULOS SEJAM CADASTRADOS SEM EXCLUIR OS QUE JA EXISITAM
        ofstream arquivoUsuarios("UsuarioCadastrados.txt", ios::app);

        if (!arquivoUsuarios.is_open())
        {
            CLEAR;

            cout << endl;
            cout << "ERRO ao abrir o arquivo!" << endl;
            cout << endl;

            system("pause");
        }

        arquivoUsuarios << "NOME: " << ususarios.getNome() << endl;
        arquivoUsuarios << "CPF: " << ususarios.getCpf() << endl;
        arquivoUsuarios << "EMAIL: " << ususarios.getEmail() << endl;
        arquivoUsuarios << "SENHA: " << ususarios.getSenha() << endl;

        arquivoUsuarios << endl;

        arquivoUsuarios.close();
    }

    void LoadUsuario(list<Usuario> &usuarios)
    {
        ifstream arquivosUsuarios("UsuarioCadastrados.txt");

        if (!arquivosUsuarios.is_open())
        {
            return;
        }

        // VARIAVEL TEMPORARIA PARA LER OS USUARIOS DO ARQUIVO
        Usuario ler_usuario_temp;

        // SERVE PARA SEPARAR CADA USUARIO
        string linha;

        while (getline(arquivosUsuarios, linha))
        {
            // EVITA ENTRADA VAZIA NO INÍCIO OU ENTRE USUÁRIOS
            if (linha.empty())
            {
                continue;
            }

            if (linha.rfind("NOME:", 0) == 0)
            {
                ler_usuario_temp.setNome(linha.substr(6)); // TIRA "NOME: "
            }

            getline(arquivosUsuarios, linha);

            if (linha.rfind("CPF:", 0) == 0)
            {
                ler_usuario_temp.setCpf(linha.substr(5));
            }

            getline(arquivosUsuarios, linha);

            if (linha.rfind("EMAIL:", 0) == 0)
            {
                ler_usuario_temp.setEmail(linha.substr(7));
            }

            getline(arquivosUsuarios, linha);

            if (linha.rfind("SENHA:", 0) == 0)
            {
                ler_usuario_temp.setSenha(linha.substr(7));
            }

            // LE A LINHA EM BRANCO DEPOIS DO USUARIO
            getline(arquivosUsuarios, linha);

            usuarios.push_back(ler_usuario_temp);
        }

        arquivosUsuarios.close();
    }
};

class Policial : public Usuario
{
public:
    Policial()
    {
        setNome("Policia");
        setCpf("11111111111");
        setEmail("policiarodoviaria@detran.com");
        setSenha("PoliciaRodoviaria-Detran");
    }
};

class Carro
{
private:
    string placa_cinza, placa_mercosul;
    string ano, cor, modelo;
    string renavam, status_crlv;

public:
    Carro() {}

    Carro(string placa_cinza, string placa_mercosul, string ano, string cor, string modelo, string renavam, string status_crlv)
        : placa_cinza(placa_cinza), placa_mercosul(placa_mercosul), ano(ano), cor(cor), modelo(modelo), renavam(renavam), status_crlv(status_crlv) {}
    // os dois acima sao contrutores, usados para, : usado para a incializacao, se tirar vai dar erro na hora de salvar o carro

    void setPlacaCinza(string pc)
    {
        this->placa_cinza = pc;
    }
    string getPlacaCinza() const
    {
        return this->placa_cinza;
    }

    void setPlacaMercosul(string pm)
    {
        this->placa_mercosul = pm;
    }
    string getPlacaMercosul() const
    {
        return this->placa_mercosul;
    }

    void setAno(string a)
    {
        this->ano = a;
    }
    string getAno() const
    {
        return this->ano;
    }

    void setCor(string c)
    {
        this->cor = c;
    }
    string getCor() const
    {
        return this->cor;
    }

    void setModelo(string m)
    {
        this->modelo = m;
    }
    string getModelo() const
    {
        return this->modelo;
    }

    void setRenavam(string r)
    {
        this->renavam = r;
    }
    string getRenavam() const
    {
        return this->renavam;
    }

    void setCrlv(string cr)
    {
        this->status_crlv = cr;
    }
    string getCrlv() const
    {
        return this->status_crlv;
    }

    void cadastrarPlacaCinza(Carro &carro_temp)
    {
        CLEAR;

        string placa_cinza_temp;

        bool registrar_placa_cinza = false; // PLACA CINZA E O NOME DADO AS PLACAS CONVENCIONAIS

        while (!registrar_placa_cinza)
        {
            CLEAR;

            cout << endl;
            cout << "------------------------------------------------------------------REGISTRO DE PLACA CINZA---------------------------------------------------------" << endl;
            cout << endl;

            cout << "Digite a placa CINZA / NORMAL sem o hifen (ou digite MENU para voltar ao MENU DE REGISTRO!):  ";

            getline(cin, placa_cinza_temp);

            cout << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < placa_cinza_temp.length(); i++)
            {
                placa_cinza_temp[i] = toupper((unsigned char)placa_cinza_temp[i]);
            }

            // RETORNA AO MENU DE REGISTRO DE PLACA
            if (placa_cinza_temp == "MENU")
            {
                if (RetornarAoMenuDeRegistro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    placa_cinza_temp = "";

                    // SE ELE QUISER VOLTAR RETORNA, MAS NAO UM VALOR INTEIRO POR ESTAR EM UM VOID E OS VOIDS NAO RETORNAM NADA
                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    placa_cinza_temp = "";

                    // CONITNUA NA LOGICA DE ANO
                    continue;
                }
            }

            // CHECAR SE A PLACA TEM 7 CARACTERES OU DIGITOS
            if (placa_cinza_temp.length() != 7)
            {
                cout << endl;
                cout << "Formato INVALIDO! (deve possuir 7 caracteres)" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            // CHECAR SE SEGUE O PADRAO CINZA / NORMAL: LLL - NNNN
            bool cinza = true;

            if (!isalpha(placa_cinza_temp[0]))
                cinza = false; // CHECA SE O PRIMEIRO DIGITO E UMA LETRA

            if (!isalpha(placa_cinza_temp[1]))
                cinza = false; // CHECA SE O SEGUNDO DIGITO E UMA LETRA

            if (!isalpha(placa_cinza_temp[2]))
                cinza = false; // CHECA SE O TERCEIRO DIGITO E UMA LETRA

            if (!isdigit(placa_cinza_temp[3]))
                cinza = false; // CHECA SE O QUARTO DIGITO E UM NUMERO

            if (!isdigit(placa_cinza_temp[4]))
                cinza = false; // CHECA SE O QUINTO DIGITO E UM NUMERO

            if (!isdigit(placa_cinza_temp[5]))
                cinza = false; // CHECA SE O SEXTO DIGITO E UM NUMERO

            if (!isdigit(placa_cinza_temp[6]))
                cinza = false; // CHECA SE O SETIMO DIGITO E UM NUMERO

            if (!cinza)
            {
                cout << endl;
                cout << "Formato INVALIDO! A placa deve seguir o padrao NORMAL / CINZA!" << endl;
                cout << endl;

                cout << "PADRAO CINZA / NORMAL : LLL - NNNN" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            carro_temp.setPlacaCinza(placa_cinza_temp);

            // PLACA REGISTRADA
            cout << endl;
            cout << "Placa registrada com sucesso: " << placa_cinza_temp.substr(0, 3) << " - " << placa_cinza_temp.substr(3, 4); // COLOCA O HIFEN NA PLACA E MOSTRA NA TELA COM HIFEN, MAS NAO SALVA O HIFEN NO VETOR
            cout << endl;
            // SUBSTR E UMA FUNCAO DA CLASEE STRING QUE INDICA (POSICAO INICIAL, QUANTAS CASAS PARA FRENTE), NESSE CASO, COMECA NO 0 E ANDA 3 CASAS E DEPOIS COMECA NO 3 E ANDA 4 CASAS

            cout << endl;

            system("pause");

            // SAI DO REGISTRO DA PLACA MERCOSUL
            registrar_placa_cinza = true;
        }
    }

    void cadastrarPlacaMercosul(Carro &carro_temp)
    {
        CLEAR;

        string placa_mercosul_temp;

        bool registrar_placa_mercosul = false;

        while (!registrar_placa_mercosul)
        {
            CLEAR;

            cout << endl;
            cout << "------------------------------------------------------REGISTRO DE PLACA MERCOSUL---------------------------------------------------------------------" << endl;
            cout << endl;

            cout << "Digite a placa MERCOSUL (ou digite MENU para voltar ao MENU DE REGISTRO!):  ";

            getline(cin, placa_mercosul_temp);

            cout << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < placa_mercosul_temp.length(); i++)
            {
                placa_mercosul_temp[i] = toupper((unsigned char)placa_mercosul_temp[i]);
            }

            // RETORNA AO MENU DE REGISTRO DE PLACA
            if (placa_mercosul_temp == "MENU")
            {
                if (RetornarAoMenuDeRegistro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    placa_mercosul_temp = "";

                    // SE ELE QUISER VOLTAR RETORNA, MAS NAO UM VALOR INTEIRO POR ESTAR EM UM VOID E OS VOIDS NAO RETORNAM NADA
                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    placa_mercosul_temp = "";

                    // CONITNUA NA LOGICA DE ANO
                    continue;
                }
            }

            // CHECAR SE A PLACA TEM 7 CARACTERES OU DIGITOS
            if (placa_mercosul_temp.length() != 7)
            {
                cout << "Formato INVALIDO! (deve possuir 7 caracteres)" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            // CHECAR SE SEGUE O PADRAO MERCOSUL: LLLNLNN
            bool mercosul = true;

            if (!isalpha(placa_mercosul_temp[0]))
                mercosul = false; // CHECA SE O PRIMEIRO DIGITO E UMA LETRA

            if (!isalpha(placa_mercosul_temp[1]))
                mercosul = false; // CHECA SE O SEGUNDO DIGITO E UMA LETRA

            if (!isalpha(placa_mercosul_temp[2]))
                mercosul = false; // CHECA SE O TERCEIRO DIGITO E UMA LETRA

            if (!isdigit(placa_mercosul_temp[3]))
                mercosul = false; // CHECA SE O QUARTO DIGITO E UM NUMERO

            if (!isalpha(placa_mercosul_temp[4]))
                mercosul = false; // CHECA SE O QUINTO DIGITO E UMA LETRA

            if (!isdigit(placa_mercosul_temp[5]))
                mercosul = false; // CHECA SE O SEXTO DIGITO E UM NUMERO

            if (!isdigit(placa_mercosul_temp[6]))
                mercosul = false; // CHECA SE O SETIMO DIGITO E UM NUMERO

            if (!mercosul)
            {
                cout << "Formato INVALIDO! A placa deve seguir o padrao MERCOSUL!" << endl;
                cout << endl;

                cout << "PADRAO MERCOSUL: LLLNLNN" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            carro_temp.setPlacaMercosul(placa_mercosul_temp);

            // PLACA REGISTRADA
            cout << "Placa registrada com sucesso: " << placa_mercosul_temp;
            cout << endl;

            cout << endl;

            system("pause");

            // SAI DO REGISTRO DA PLACA MERCOSUL
            registrar_placa_mercosul = true;
        }
    }

    void cadastrarAno(Carro &carro_temp)
    {
        CLEAR;

        string ano_temp;

        bool ano_de_fabricacao = false;

        while (!ano_de_fabricacao)
        {
            CLEAR;

            cout << endl;
            cout << "------------------------------------------------ANO DE FABRICACAO---------------------------------------------------------" << endl;
            cout << endl;
            cout << "Digite o ano de FABRICACAO do veiculo (ou MENU para voltar ao MENU DE REGISTRO):  ";

            getline(cin, ano_temp);

            cout << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < ano_temp.length(); i++)
            {
                ano_temp[i] = toupper((unsigned char)ano_temp[i]);
            }

            if (ano_temp == "MENU")
            {
                if (RetornarAoMenuDeRegistro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    ano_temp = "";

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    ano_temp = "";

                    continue;
                }
            }

            bool apenas_numeros = true;

            for (int i = 0; i < ano_temp.length(); i++)
            {
                if (!isdigit(ano_temp[i]))
                {
                    apenas_numeros = false;

                    break;
                }
            }

            if (!apenas_numeros)
            {
                cout << endl;
                cout << "Formato INVALIDO! Digite apenas NUMEROS!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            if (ano_temp.empty())
            {
                continue;
            }

            // CONVERTE A STRING ANO PARA INTEIRO, PARA SEGUIR A LOGICA DE COMPARACAO E EXISTENCIA
            int ano_fabricacao = stoi(ano_temp);

            // PEGA O ANO EM QUE ESTAMOS +1 COMO MAXIMO, ESSE COMANDO PEGA AUTOMATICAMENTE O ANO DO COMPUTADOR, JA FOI PROGRAMADO POR ALGUEM DESSA MANEIRA
            time_t t = time(nullptr);
            tm *data = localtime(&t);
            int ano_atual = data->tm_year + 1900;

            int ano_maximo = ano_atual + 1;

            if (ano_fabricacao < 1886)
            {
                cout << endl;
                cout << "Data INVALIDA!" << endl;
                cout << endl;
                cout << "--------------------------------------INVENCAO DO AUTOMOVEL--------------------------------------" << endl;
                cout << endl;
                cout << "Os carros como os conhecemos hoje foram inventados em 1886, quando o engenheiro alemao \nKarl Benz patenteou o Benz-Patent Motorwagen, o primeiro veiculo \na ser produzido comercialmente movida a gasolina" << endl;
                cout << "------------------------------------------------------------------------------------------------";

                cout << endl;
                system("pause");
            }
            else if (ano_fabricacao > ano_maximo)
            {
                cout << endl;
                cout << "Ano INVALIDO!" << endl;

                cout << "O ano maximo permitido e: " << ano_maximo << endl;
                cout << endl;

                system("pause");
            }
            else
            {
                carro_temp.setAno(ano_temp);

                cout << endl;
                cout << "Ano REGISTRADO com sucesso" << endl;
                cout << endl;

                system("pause");

                ano_de_fabricacao = true;
            }
        }
    }

    void cadastrarCor(Carro &carro_temp)
    {
        CLEAR;

        string cor_nova_temp;

        bool cadastrar_cor = false;

        while (!cadastrar_cor)
        {
            CLEAR;

            cout << endl;
            cout << "--------------------------------------------------CADASTRAR COR-------------------------------------------------" << endl;
            cout << endl;

            cout << "Digite a cor do seu veiculo (ou digite MENU para retornar ao MENU DE REGISTRO):  ";

            getline(cin, cor_nova_temp);

            cout << endl;
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < cor_nova_temp.length(); i++)
            {
                cor_nova_temp[i] = toupper((unsigned char)cor_nova_temp[i]);
            }

            if (cor_nova_temp == "MENU")
            {
                if (RetornarAoMenuDeRegistro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cor_nova_temp = "";

                    // SE ELE QUISER VOLTAR RETORNA, MAS NAO UM VALOR INTEIRO POR ESTAR EM UM VOID E OS VOIDS NAO RETORNAM NADA
                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cor_nova_temp = "";

                    // CONITNUA NA LOGICA DE ANO
                    continue;
                }
            }

            // CHECAR SE SAO APENAS LETRAS
            bool so_letras = true;

            for (int i = 0; i < cor_nova_temp.length(); i++)
            {
                if (!isalpha(cor_nova_temp[i]) && cor_nova_temp[i] != ' ')
                {
                    so_letras = false;

                    break;
                }
            }

            if (!so_letras)
            {
                cout << endl;
                cout << "Formato INVALIDO! Digite apenas LETRAS!" << endl;
                cout << endl;

                system("pause");
            }
            else
            {
                carro_temp.setCor(cor_nova_temp);

                cout << endl;
                cout << "Cor REGISTRADA com sucesso!" << endl;
                cout << endl;

                system("pause");

                cadastrar_cor = true;

                break;
            }
        }
    }

    void cadastrarModelo(Carro &carro_temp)
    {
        CLEAR;

        bool cadastrar_modelo = false;

        string modelo_novo_temp;

        while (!cadastrar_modelo)
        {
            CLEAR;

            cout << endl;
            cout << "---------------------------------------------------CADASTRAR MODELO------------------------------------------------------" << endl;
            cout << endl;

            cout << "Digite o MODELO do seu veiculo (ou digite MENU para retornar ao MENU DE REGISTRO):  ";

            getline(cin, modelo_novo_temp);

            cout << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < modelo_novo_temp.length(); i++)
            {
                modelo_novo_temp[i] = toupper((unsigned char)modelo_novo_temp[i]);
            }

            if (modelo_novo_temp == "MENU")
            {
                if (RetornarAoMenuDeRegistro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    modelo_novo_temp = "";

                    // SE ELE QUISER VOLTAR RETORNA, MAS NAO UM VALOR INTEIRO POR ESTAR EM UM VOID E OS VOIDS NAO RETORNAM NADA
                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    modelo_novo_temp = "";

                    continue;
                }
            }
            else
            {
                carro_temp.setModelo(modelo_novo_temp);

                cout << endl;
                cout << "Modelo REGISTRADO com sucesso!" << endl;
                cout << endl;

                system("pause");

                cadastrar_modelo = true;
            }
        }
    }

    void cadastrarRenavam(Carro &carro_temp)
    {
        CLEAR;

        bool cadastrar_renavam = false;

        string renavam_novo_temp;

        while (!cadastrar_renavam)
        {
            CLEAR;

            cout << endl;
            cout << "--------------------------------------------------------RENAVAM------------------------------------------------" << endl;
            cout << endl;
            cout << "Digite o RENAVAM do veiculo (ou MENU para voltar ao MENU DE REGISTRO):  ";

            getline(cin, renavam_novo_temp);

            cout << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < renavam_novo_temp.length(); i++)
            {
                renavam_novo_temp[i] = toupper((unsigned char)renavam_novo_temp[i]);
            }

            if (renavam_novo_temp == "MENU")
            {
                if (RetornarAoMenuDeRegistro())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    renavam_novo_temp = "";

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    renavam_novo_temp = "";

                    continue;
                }
            }

            bool apenas_numeros = true;

            for (int i = 0; i < renavam_novo_temp.length(); i++)
            {
                if (!isdigit(renavam_novo_temp[i]))
                {
                    apenas_numeros = false;

                    break;
                }
            }

            if (!apenas_numeros)
            {
                cout << endl;
                cout << "Formato INVALIDO! Digite apenas NUMEROS!" << endl;
                cout << endl;

                system("pause");

                continue;
            }

            if (renavam_novo_temp.empty())
            {
                continue;
            }

            if (renavam_novo_temp.length() != 11)
            {
                cout << endl;
                cout << "Formato INVALIDO! Deve ter 11 digitos numericos" << endl;
                cout << endl;

                system("pause");

                continue;
            }
            else
            {
                carro_temp.setRenavam(renavam_novo_temp);

                cout << endl;
                cout << "Renavam REGISTRADO com sucesso" << endl;
                cout << endl;

                system("pause");

                cadastrar_renavam = true;
            }
        }
    }

    bool SalvarCarro(Usuario *usuario_logado, Carro &carro_temp)
    {
        bool valido = true;

        // CHECAR SE TODOS OS CAMPOS DO CADASTRO FORAM PREENCHIDOS
        if (carro_temp.getPlacaCinza().empty() && carro_temp.getPlacaMercosul().empty())
        {
            cout << endl;
            cout << "Preencha a PLACA antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (carro_temp.getAno().empty())
        {
            cout << endl;
            cout << "Preencha o ANO antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (carro_temp.getCor().empty())
        {
            cout << endl;
            cout << "Preencha a COR antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (carro_temp.getModelo().empty())
        {
            cout << endl;
            cout << "Preencha o MODELO antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        if (carro_temp.getRenavam().empty())
        {
            cout << endl;
            cout << "Preencha o RENAVAM antes de salvar!" << endl;
            cout << endl;

            valido = false;
        }

        // COPIA NAO CONSTANTE PARA DAR CERTO LIMPAR A STRING
        // O CONST SIGINFICA APENAS LEITURA, RECEBE POR ENDERECO E NAO ALTERA NADA, O QUE IMPEDE LIMPAR A PLACA
        Carro carro_a_salvar = carro_temp;

        if (!carro_temp.getPlacaCinza().empty() && !carro_temp.getPlacaMercosul().empty())
        {
            cout << endl;
            cout << "Preencha apenas UM TIPO DE PLACA!" << endl;
            cout << endl;

            carro_a_salvar.setPlacaCinza("");

            carro_a_salvar.setPlacaMercosul("");

            valido = false;
        }

        if (!valido)
        {
            return false;
        }

        usuario_logado->carros.push_back(Carro{// arrumar isso depois, esta colocando com o struct e nao com o class
                                               carro_temp.getPlacaCinza(),
                                               carro_temp.getPlacaMercosul(),
                                               carro_temp.getAno(),
                                               carro_temp.getCor(),
                                               carro_temp.getModelo(),
                                               carro_temp.getRenavam(),
                                               carro_temp.getCrlv()});

        return true;
    }

    void ExportarVeiculo(Usuario *usuario_logado)
    {
        // ESSE VOID RETORNA APENAS ERROS NA TELA E MAIS NADA
        CLEAR;

        // AQUI NAO PODE COLOCAR COMO APPEND, POIS CASO O USUARIOS MODIFIQUE ALGUMA COISA NO CARRO, ELE SALVA DOIS CARROS E NAO FAZ A ALTERACAO NESCESSARIA
        ofstream arquivoVeiculos("ArquivoVeiculos.txt");

        if (!arquivoVeiculos.is_open())
        {
            CLEAR;

            cout << endl;
            cout << "ERRO ao abrir o arquivo!" << endl;
            cout << endl;

            system("pause");
        }
        else
        {
            for (auto it = usuario_logado->carros.begin(); it != usuario_logado->carros.end(); it++)
            {

                arquivoVeiculos << "NOME: " << usuario_logado->getNome() << endl;
                arquivoVeiculos << "CPF: " << usuario_logado->getCpf() << endl;
                if (!it->getPlacaCinza().empty())
                {
                    arquivoVeiculos << "PLACA CINZA: " << it->getPlacaCinza() << endl;
                }
                else if (!it->getPlacaMercosul().empty())
                {
                    arquivoVeiculos << "PLACA MERCOSUL: " << it->getPlacaMercosul() << endl;
                }
                arquivoVeiculos << "ANO: " << it->getAno() << endl;
                arquivoVeiculos << "COR: " << it->getCor() << endl;
                arquivoVeiculos << "MODELO: " << it->getModelo() << endl;
                arquivoVeiculos << "RENAVAM: " << it->getRenavam() << endl;

                arquivoVeiculos << endl;
            }
            arquivoVeiculos.close();
        }
    }

    void LoadVeiculos(Usuario *usuario_logado)
    {
        ifstream arquivoVeiculos("ArquivoVeiculos.txt");

        if (!arquivoVeiculos.is_open())
        {
            cout << "Arquivo de veiculos nao encontrado ou erro ao abrir." << endl;
            cout << endl;

            system("pause");

            return;
        }

        // LIMPA O VETOR ATUAL PARA EVITAR DUPLICACAO
        usuario_logado->carros.clear();

        string linha;

        Carro carro_temp;

        // GARANTIR QUE PERTENCE AO USAURIO LOGADO
        bool nome_confere = false;

        bool cpf_confere = false;

        bool dados_preenchidos = false;

        while (getline(arquivoVeiculos, linha))
        {
            // SE A LINHA ESTIVER VAZIA INDICA O FIM DOS DADOS DE UM CARRO, LOGO TERA OUTRO CARRO
            if (linha.empty())
            {
                // SE TIVER LIDO OS DADOS E O CARRO PERTENCER AO USAURIO, SALVA O CARRO
                if (dados_preenchidos && nome_confere && cpf_confere)
                {
                    usuario_logado->carros.push_back(carro_temp);
                }

                // RESETA AS VARIAVEIS PARA O PROXIMO CARRO DO ARQUIVO CASO NAO SEJA ESSE
                carro_temp = Carro();

                nome_confere = false;

                cpf_confere = false;

                dados_preenchidos = false;

                continue;
            }

            // VERIFICA O NOME
            if (linha.rfind("NOME: ", 0) == 0)
            {
                string nome_arquivo = linha.substr(6);

                if (nome_arquivo == usuario_logado->getNome())
                {
                    nome_confere = true;
                }
            }

            else if (linha.rfind("CPF: ", 0) == 0)
            {
                string cpf_arquivo = linha.substr(5);

                if (cpf_arquivo == usuario_logado->getCpf())
                {
                    cpf_confere = true;
                }
            }

            else if (linha.rfind("PLACA CINZA: ", 0) == 0)
            {
                carro_temp.setPlacaCinza(linha.substr(13));

                dados_preenchidos = true;
            }

            else if (linha.rfind("PLACA MERCOSUL: ", 0) == 0)
            {
                carro_temp.setPlacaMercosul(linha.substr(16));

                dados_preenchidos = true;
            }

            else if (linha.rfind("ANO: ", 0) == 0)
            {
                carro_temp.setAno(linha.substr(5));

                dados_preenchidos = true;
            }

            else if (linha.rfind("COR: ", 0) == 0)
            {
                carro_temp.setCor(linha.substr(5));

                dados_preenchidos = true;
            }

            else if (linha.rfind("MODELO: ", 0) == 0)
            {
                carro_temp.setModelo(linha.substr(8));

                dados_preenchidos = true;
            }

            else if (linha.rfind("RENAVAM: ", 0) == 0)
            {
                carro_temp.setRenavam(linha.substr(9));

                dados_preenchidos = true;
            }
        }

        // CASO NAO TERMINE EM LINHA VAZIA O ARQUIVO, SE O ULTIMO CARRO FOR VALIDO. SALVA NO VETOR
        if (dados_preenchidos && nome_confere && cpf_confere)
        {
            usuario_logado->carros.push_back(carro_temp);
        }

        arquivoVeiculos.close();
    }

    void VeiculosRegistrados(list<Carro> &carros)
    {
        bool sair_veiculos_registrados = false;

        while (!sair_veiculos_registrados)
        {
            CLEAR;

            cout << endl;
            cout << "-------------------------------------------------VEICULOS REGISTRADOS-------------------------------------------------" << endl;
            cout << endl;

            // LOGICA DE CHECAR SE TEM ALGUM VEICULO
            if (carros.empty())
            {
                cout << endl;
                cout << "Nenhum VEICULO foi registrado!" << endl;
                cout << endl;
            }
            else
            {
                // MOSTRAR TODOS OS CARROS
                int contador = 1;
                for (auto it = carros.begin(); it != carros.end(); it++)
                {
                    cout << "--------------------------------------CARRO " << contador << "-----------------------------------------" << endl;
                    cout << endl;
                    cout << "Modelo: " << it->getModelo() << endl;
                    cout << endl;
                    cout << "Cor: " << it->getCor() << endl;
                    cout << endl;
                    cout << "Ano: " << it->getAno() << endl;
                    cout << endl;

                    // LOGICA DA PLACA
                    if (!it->getPlacaCinza().empty())
                    {
                        cout << "Placa:  " << it->getPlacaCinza() << endl;
                        cout << endl;
                    }
                    else if (!it->getPlacaMercosul().empty())
                    {
                        cout << "Placa:  " << it->getPlacaMercosul() << endl;
                        cout << endl;
                    }

                    cout << "Renavam:  " << it->getRenavam() << endl;
                    cout << endl;
                    contador++;
                }
            }

            cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            cout << "Todos os carros REGISTRADOS!" << endl;
            cout << endl;

            system("pause");

            sair_veiculos_registrados = true;
        }
    }

    void ExcluirVeiculos(list<Carro> &carros)
    {
        bool sair_excluir_veiculo = false;

        while (!sair_excluir_veiculo)
        {
            CLEAR;

            cout << endl;
            cout << "------------------------------------------------------------------------------EXCLUIR VEICULOS-----------------------------------------------------------------------" << endl;
            cout << endl;
            cout << "Digite algum componente dele para excluir (ou digite MENU para voltar ao MENU DE VEICULOS):  ";

            string excluir_veiculo;
            getline(cin, excluir_veiculo);

            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < excluir_veiculo.length(); i++)
            {
                excluir_veiculo[i] = toupper((unsigned char)excluir_veiculo[i]);
            }

            if (excluir_veiculo == "MENU")
            {
                if (RetornarAoMenuDeVeiculos())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    continue;
                }
            }

            // CHECAR A COMPONENTE COM O STRUCT CARRO
            bool encontrado = false;

            for (auto it = carros.begin(); it != carros.end(); it++)
            {
                if (excluir_veiculo == it->getPlacaCinza() ||
                    excluir_veiculo == it->getPlacaMercosul() ||
                    excluir_veiculo == it->getAno() ||
                    excluir_veiculo == it->getCor() ||
                    excluir_veiculo == it->getModelo() ||
                    excluir_veiculo == it->getRenavam())
                {
                    CLEAR;

                    encontrado = true;
                    cout << endl;
                    cout << "-------------------------------------------------------" << endl;
                    cout << endl;
                    cout << "       Tem certeza que deseja excluir o veiculo" << endl;
                    cout << endl;
                    cout << "                1 - SIM, EXCLUIR veiculo" << endl;
                    cout << endl;
                    cout << "            2 - NAO, voltar ao MENU DE VEICULOS" << endl;
                    cout << endl;
                    cout << "-------------------------------------------------------" << endl;
                    cout << endl;

                    cout << "Digite a OPCAO DESEJADA:  ";

                    int opcao_excluir_carro = 0;
                    cin >> opcao_excluir_carro;

                    switch (opcao_excluir_carro)
                    {
                    case 1:
                    {
                        // SIM

                        CLEAR;

                        carros.erase(it);

                        cout << endl;
                        cout << "Veiculo EXCLUIDO com sucesso!" << endl;
                        cout << endl;

                        system("pause");

                        sair_excluir_veiculo = true;

                        break;
                    }

                    case 2:
                    {
                        // NAO
                        sair_excluir_veiculo = true;

                        break;
                    }

                    default:
                    {
                        cout << endl;
                        cout << "Opcao INVALIDA!" << endl;
                        cout << endl;

                        system("pause");

                        break;
                    }
                    }

                    break;
                }
            }

            if (!encontrado)
            {
                CLEAR;

                cout << "NENHUM veiculo foi encontrado!" << endl;
                cout << endl;

                system("pause");

                continue;
            }
        }
    }

    void AlterarVeiculo(list<Carro> &carros, Usuario *usuario_logado)
    {
        bool sair_alterar_veiculo = false;

        while (!sair_alterar_veiculo)
        {
            CLEAR;

            cout << endl;
            cout << "-----------------------------------------------------ALTERAR VEICULO(S)-------------------------------------------------" << endl;
            cout << "Digite algum DADO do veiculo(ou digite MENU para voltar ao MENU DE VEICULO):  ";

            string alterar_veiculo;
            getline(cin, alterar_veiculo);

            cout << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            for (int i = 0; i < alterar_veiculo.length(); i++)
            {
                alterar_veiculo[i] = toupper((unsigned char)alterar_veiculo[i]);
            }

            if (alterar_veiculo == "MENU")
            {
                if (RetornarAoMenuDeVeiculos())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    continue;
                }
            }

            for (auto it = carros.begin(); it != carros.end(); it++)
            {
                if (alterar_veiculo == it->getPlacaCinza() ||
                    alterar_veiculo == it->getPlacaMercosul() ||
                    alterar_veiculo == it->getAno() ||
                    alterar_veiculo == it->getCor() ||
                    alterar_veiculo == it->getModelo() ||
                    alterar_veiculo == it->getRenavam())
                {
                    bool sair_encontrou_alterar_veiculo = false;

                    while (!sair_encontrou_alterar_veiculo)
                    {
                        CLEAR;

                        cout << endl;
                        cout << "-----------------------------------------------------" << endl;
                        cout << endl;
                        cout << "           1 - Alterar PLACA CINZA" << endl;
                        cout << endl;
                        cout << "           2 - Alterar PLACA MERCOSUL" << endl;
                        cout << endl;
                        cout << "           3 - Alterar ANO" << endl;
                        cout << endl;
                        cout << "           4 - Alterar COR" << endl;
                        cout << endl;
                        cout << "           5 - Alterar MODELO" << endl;
                        cout << endl;
                        cout << "           6 - Retornar ao MENU DE VEICULOS" << endl;
                        cout << endl;
                        cout << "------------------------------------------------------" << endl;
                        cout << endl;

                        cout << "Digite a OPCAO DESEJADA:  ";

                        int opcao_encontrou_alterar_veiculo = 0;
                        cin >> opcao_encontrou_alterar_veiculo;

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        switch (opcao_encontrou_alterar_veiculo)
                        {
                        case 1:
                        {
                            cadastrarPlacaCinza(*it);
                            it->setPlacaMercosul("");

                            ExportarVeiculo(usuario_logado);

                            cout << endl;
                            cout << "Nova PLACA CINZA registrada com sucesso!" << endl;
                            cout << endl;

                            system("pause");

                            sair_encontrou_alterar_veiculo = true;
                            sair_alterar_veiculo = true;

                            break;
                        }

                        case 2:
                        {
                            cadastrarPlacaMercosul(*it);
                            it->setPlacaCinza("");

                            ExportarVeiculo(usuario_logado);

                            cout << endl;
                            cout << "Nova PLACA MERCOSUL registrada com sucesso!" << endl;
                            cout << endl;

                            system("pause");

                            sair_encontrou_alterar_veiculo = true;
                            sair_alterar_veiculo = true;

                            break;
                        }

                        case 3:
                        {
                            cadastrarAno(*it);

                            ExportarVeiculo(usuario_logado);

                            cout << endl;
                            cout << "Novo ANO registrado com sucesso!" << endl;
                            cout << endl;

                            system("pause");

                            sair_encontrou_alterar_veiculo = true;
                            sair_alterar_veiculo = true;

                            break;
                        }

                        case 4:
                        {
                            cadastrarCor(*it);

                            ExportarVeiculo(usuario_logado);

                            cout << endl;
                            cout << "Nova COR registrada com sucesso!" << endl;
                            cout << endl;

                            system("pause");

                            sair_encontrou_alterar_veiculo = true;
                            sair_alterar_veiculo = true;

                            break;
                        }

                        case 5:
                        {
                            cadastrarModelo(*it);

                            ExportarVeiculo(usuario_logado);

                            cout << endl;
                            cout << "Novo MODELO registrado com sucesso!" << endl;
                            cout << endl;

                            system("pause");

                            sair_encontrou_alterar_veiculo = true;
                            sair_alterar_veiculo = true;
                            break;
                        }
                        case 6:
                        {
                            // RETORNAR AO MENU DE VEICULO

                            if (RetornarAoMenuDeVeiculos())
                            {
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                sair_encontrou_alterar_veiculo = true;

                                sair_alterar_veiculo = true;
                            }
                            else
                            {
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                continue;
                            }

                            break;
                        }

                        default:
                        {
                            cout << endl;
                            cout << "Opcao INVALIDA!" << endl;
                            cout << endl;

                            system("pause");

                            break;
                        }
                        }
                    }
                }
                else
                {
                    cout << endl;
                    cout << "NENHUM veiculo encontrado!" << endl;
                    cout << endl;

                    system("pause");

                    break;
                }
            }
        }
    }

    void GerarCrlv(list<Carro> &carros, Usuario *usuario_logado)
    {
        bool sair_gerar_crlv = false;

        while (!sair_gerar_crlv)
        {
            CLEAR;

            cout << endl;
            cout << "-----------------------------------------GERAR CRLV---------------------------------------------" << endl;
            cout << endl;
            cout << "Digite um dos componentes do VEICULO para gerar o CRLV do mesmo!" << endl;
            cout << endl;
            cout << "Ou digite MENU para voltar ao MENU CRLV!" << endl;
            cout << endl;

            cout << "Digite o DADO do carro:  ";

            string gerar_crlv;
            getline(cin, gerar_crlv);

            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < gerar_crlv.length(); i++)
            {
                gerar_crlv[i] = toupper((unsigned char)gerar_crlv[i]);
            }

            // RETORNA AO MENU DE REGISTRO DE PLACA
            if (gerar_crlv == "MENU")
            {
                if (RetornarAoMenuDeCrlv())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    // SE ELE QUISER VOLTAR RETORNA, MAS NAO UM VALOR INTEIRO POR ESTAR EM UM VOID E OS VOIDS NAO RETORNAM NADA
                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    // CONITNUA NA LOGICA DE ANO
                    continue;
                }
            }

            bool encontrou_veiculo = false;

            for (auto it = carros.begin(); it != carros.end(); it++)
            {
                if (gerar_crlv == it->getPlacaCinza() ||
                    gerar_crlv == it->getPlacaMercosul() ||
                    gerar_crlv == it->getAno() ||
                    gerar_crlv == it->getCor() ||
                    gerar_crlv == it->getModelo() ||
                    gerar_crlv == it->getRenavam())
                {
                    CLEAR;

                    cout << endl;
                    cout << "----------------------------------------CRLV---------------------------------------" << endl;
                    cout << endl;
                    // A SETA PASSA O PONTEIRO PELO STRUCT USUARIO E SALVA O NOME DELE
                    cout << "Propietario: " << usuario_logado->getNome() << endl;
                    cout << endl;
                    cout << "Modelo: " << it->getModelo() << endl;
                    cout << endl;
                    cout << "Ano: " << it->getAno() << endl;
                    cout << endl;
                    cout << "Cor: " << it->getCor() << endl;
                    cout << endl;
                    if (!it->getPlacaCinza().empty())
                    {
                        cout << "Placa: " << it->getPlacaCinza() << endl;
                        cout << endl;
                    }
                    else if (!it->getPlacaMercosul().empty())
                    {
                        cout << "Placa: " << it->getPlacaMercosul() << endl;
                        cout << endl;
                    }

                    cout << "Renavam: " << it->getRenavam() << endl;
                    cout << endl;
                    cout << "----------------------------------------------------------------------------------" << endl;
                    cout << endl;

                    system("pause");

                    encontrou_veiculo = true;

                    sair_gerar_crlv = true;

                    break;
                }
            }

            if (!encontrou_veiculo)
            {
                cout << endl;
                cout << "Nenhum VEICULO foi encontrado com esse dado!" << endl;
                cout << endl;

                system("pause");
            }
        }
    }

    void ExportarCrlv(list<Carro> &carros, Usuario *usuario_logado)
    {
        bool sair_exportar_crlv = false;

        while (!sair_exportar_crlv)
        {
            CLEAR;

            cout << endl;
            cout << "------------------------------------------------EXPORTAR CRLV----------------------------------------------" << endl;
            cout << endl;
            cout << "Digite um dos componentes do VEICULO para exportar o CRLV do mesmo!" << endl;
            cout << endl;
            cout << "Ou digite MENU para voltar ao MENU CRLV!" << endl;
            cout << endl;

            cout << "Digite o DADO do veiculo: ";

            string exportar_crlv;
            getline(cin >> ws, exportar_crlv);

            cout << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;

            // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
            for (int i = 0; i < exportar_crlv.length(); i++)
            {
                exportar_crlv[i] = toupper((unsigned char)exportar_crlv[i]);
            }

            // RETORNA AO MENU DE REGISTRO DE PLACA
            if (exportar_crlv == "MENU")
            {
                if (RetornarAoMenuDeCrlv())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    // SE ELE QUISER VOLTAR RETORNA, MAS NAO UM VALOR INTEIRO POR ESTAR EM UM VOID E OS VOIDS NAO RETORNAM NADA
                    return;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    // CONITNUA NA LOGICA DE ANO
                    continue;
                }
            }

            bool encontrou_veiculo = false;

            for (auto it = carros.begin(); it != carros.end(); it++)
            {
                if (exportar_crlv == it->getPlacaCinza() ||
                    exportar_crlv == it->getPlacaMercosul() ||
                    exportar_crlv == it->getAno() ||
                    exportar_crlv == it->getCor() ||
                    exportar_crlv == it->getModelo() ||
                    exportar_crlv == it->getRenavam())
                {

                    encontrou_veiculo = true;

                    string nome_exportar_crlv = "CRLV_";

                    if (!it->getPlacaCinza().empty())
                    {
                        nome_exportar_crlv += it->getPlacaCinza();
                    }
                    else
                    {
                        nome_exportar_crlv += it->getPlacaMercosul();
                    }

                    nome_exportar_crlv += ".txt";

                    ofstream arquivoCRLV(nome_exportar_crlv);

                    if (!arquivoCRLV.is_open())
                    {
                        cout << endl;
                        cout << "ERRO ao abrir o arquivo!" << endl;
                        cout << endl;

                        system("pause");

                        return;
                    }

                    arquivoCRLV << "-----------------------------CRLV----------------------------" << endl;
                    arquivoCRLV << endl;
                    arquivoCRLV << "Propietario:  " << usuario_logado->getNome() << endl;
                    arquivoCRLV << endl;
                    arquivoCRLV << "Modelo:  " << it->getModelo() << endl;
                    arquivoCRLV << endl;
                    arquivoCRLV << "Ano:  " << it->getAno() << endl;
                    arquivoCRLV << endl;
                    arquivoCRLV << "Cor: " << it->getCor() << endl;
                    arquivoCRLV << endl;
                    if (!it->getPlacaCinza().empty())
                    {
                        arquivoCRLV << "Placa:  " << it->getPlacaCinza() << endl;
                        arquivoCRLV << endl;
                    }
                    else if (!it->getPlacaMercosul().empty())
                    {
                        arquivoCRLV << "Placa:  " << it->getPlacaMercosul() << endl;
                        arquivoCRLV << endl;
                    }
                    arquivoCRLV << "Renvam:  " << it->getRenavam() << endl;
                    arquivoCRLV << endl;
                    arquivoCRLV << "-----------------------------------------------------------------" << endl;

                    arquivoCRLV.close();

                    cout << endl;
                    cout << "CRLV exportado com sucesso!" << endl;

                    system("pause");

                    sair_exportar_crlv = true;

                    break;
                }
            }

            if (!encontrou_veiculo)
            {
                cout << endl;
                cout << "Nenhum VEICULO foi encontrado com esse dado!" << endl;
                cout << endl;

                system("pause");

                continue;
            }
        }
    }

    void ListarVeiculos_CRLV(list<Carro> &carros)
    {
        bool sair_listar_veiculos_crlv = false;

        while (!sair_listar_veiculos_crlv)
        {
            CLEAR;

            cout << endl;
            cout << "------------------------------------------VEICULOS REGISTRADOS----------------------------------------------------" << endl;
            cout << endl;

            // LOGICA DE CHECAR SE TEM ALGUM VEICULO
            if (carros.empty())
            {
                cout << endl;
                cout << "Nenhum VEICULO foi registrado!" << endl;
                cout << endl;

                if (RetornarAoMenuDeCrlv())
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    sair_listar_veiculos_crlv = true;
                }
            }
            else
            {
                int contador = 1;
                // MOSTRAR TODOS OS CARROS
                for (auto it = carros.begin(); it != carros.end(); it++)
                {
                    cout << endl;
                    cout << "-----------------------------------CARRO " << contador << "--------------------------------------" << endl;
                    cout << endl;
                    cout << "Modelo:  " << it->getModelo() << endl;
                    cout << endl;
                    cout << "Cor:  " << it->getCor() << endl;
                    cout << endl;
                    cout << "Ano:  " << it->getAno() << endl;
                    cout << endl;

                    // LOGICA DA PLACA
                    if (!it->getPlacaCinza().empty())
                    {
                        cout << "Placa:  " << it->getPlacaCinza() << endl;
                        cout << endl;
                    }
                    else if (!it->getPlacaMercosul().empty())
                    {
                        cout << "Placa:  " << it->getPlacaMercosul() << endl;
                        cout << endl;
                    }

                    cout << "Renavam:  " << it->getRenavam() << endl;
                    cout << endl;
                    cout << "-----------------------------------------------------------------------------------------" << endl;
                }
            }

            cout << endl;

            cout << "Todos os VEICULOS registrados!" << endl;
            cout << endl;

            system("pause");

            sair_listar_veiculos_crlv = true;
        }
    }
};

class Multa : public Carro
{
    // carro ja tem o usuario, portanto nao precisa do usuario
    // checar multas nos carros e pontos na carteira
};

// SE FOSSE APENAS USUARIO: RETORNA UMA COPIA DO STRUCT USUARIO, E IMPEDE MUDANCAS NA CONTA E NAO RETORNA NADA CASO O USUARIO NAO EXISTA
// SE FOSSE APENAS USUARIO&: INDICA REFERENCIA DA MEMORIA, OU SEJA, A MEMORIA NAO PODE SER NULA OU NAO EXISTIR, PORTANTO NAO RETORNA NADA CASO NAO EXISTA
// COM USUARIO*: SERVE COMO UM PONTEIO, O FATO DE COLOCAR * DEPOIS DA VARIAVEL, FUNCIONA COMO UM PONTEIRO, DESSA MANEIRA RETORNA O ESPACO DE MEMORIA CASO EXISTA E SE NAO EXISTIR NADA, RETORNARA NULL
Usuario *EncontrarUsuarioPorLogin(list<Usuario> &usuarios, const string &login)
{
    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {
        if (it->getCpf() == login ||
            it->getEmail() == login)
        {
            // CASO ENCONTRE O USUARIO, RETORNA O ESPACO DE MEMORIA , O ENDERECO EM QUE O USUARIO SE ENCONTRA
            // SERVE PARA RETORNAR NULLPTR (NAO EXISTE)
            return &(*it);
        }
        else if (it->getCpf() == "11111111111" ||
                 it->getEmail() == "policiarodoviaria@detran.com")
        {
            return &(*it);
        }
    }

    return nullptr;
}

Usuario *EncontrarUsuarioPorSenha(list<Usuario> &usuarios, const string &senha)
{
    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {
        if (it->getSenha() == senha)
        {
            return &(*it);
        }
    }

    return nullptr;
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    list<Usuario> usuarios;
    Usuario usuario_temp;

    Usuario *usuario_logado = nullptr;

    Usuario usuario_load;
    usuario_load.LoadUsuario(usuarios);

    Carro carro_temp;

    Policial(); // cria o usuario policial

    bool perfil_Policial = false;

    while (true)
    {
        CLEAR;

        cout << "-------------------------------MENU PRINCIPAL----------------------------------------" << endl;
        cout << endl;

        // COLOCAR SE O LOGIN JA ESTA FEITO
        if (usuario_logado != nullptr)
        {
            if (usuario_logado->getCpf() != "11111111111")
            {
                cout << "Seja Bem vindo " << usuario_logado->getNome() << "!" << endl;
                cout << endl;
            }
            else
            {
                perfil_Policial = true;
                cout << "Perfil Policial" << endl;
                cout << endl;
            }
        }
        else
        {
            cout << "Nao Logado!" << endl;
            cout << endl;
        }

        if (!perfil_Policial)
        {
            cout << "                      1 - Realizar Cadastro / Login" << endl;
            cout << endl;
            cout << "                      2 - Resgistrar Veiculo" << endl;
            cout << endl;
            cout << "                      3 - Checar Veiculo(s)" << endl;
            cout << endl;
            cout << "                      4 - CRLV" << endl;
            cout << endl;
        }

        cout << "                      5 - Sair" << endl;
        cout << endl;

        if (perfil_Policial)
        {
            cout << "                      6 - Aplicar multa" << endl;
            cout << endl;
            cout << "                      7 - Checar CNH / veiculo" << endl;
            cout << endl;
        }

        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Digite a OPCAO DESEJADA: ";

        int opcao = 0;
        cin >> opcao;

        cout << endl;

        switch (opcao)
        {
        case 1:
        {
            // REALIZAR CADASTRO / LOGIN

            CLEAR;

            bool sair_cadastro_login = false;

            while (!sair_cadastro_login)
            {
                CLEAR;

                cout << "--------------------------CADASTRO / LOGIN--------------------------" << endl;
                cout << endl;
                cout << "                   1 - Cadastrar Usuario" << endl;
                cout << endl;
                cout << "                   2 - Login" << endl;
                cout << endl;
                cout << "                   3 - Retornar ao menu principal" << endl;
                cout << endl;
                cout << "--------------------------------------------------------------------" << endl;
                cout << endl;

                cout << "Digite a OPCAO DESEJADA: ";

                int cadastro_login = 0;
                cin >> cadastro_login;

                // cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (cadastro_login)
                {
                case 1:
                {
                    // CADASTRAR USUARIO

                    CLEAR;

                    Usuario usuario_temp;

                    bool cadastrar_usuario = false;

                    while (!cadastrar_usuario)
                    {
                        CLEAR;

                        cout << "--------------------------CADASTRO DE USUARIO--------------------------" << endl;
                        cout << endl;
                        cout << "                       1 - CPF" << endl;
                        cout << endl;
                        cout << "                       2 - Nome Completo" << endl;
                        cout << endl;
                        cout << "                       3 - E-mail" << endl;
                        cout << endl;
                        cout << "                       4 - Senha" << endl;
                        cout << endl;
                        cout << "                       5 - Salvar" << endl;
                        cout << endl;
                        cout << "            6 - Retornar ao MENU DE CADASTRO / LOGIN" << endl;
                        cout << endl;
                        cout << "----------------------------------------------------------------------" << endl;
                        cout << endl;

                        cout << "Digite a OPCAO DESEJADA: " << endl;

                        int opcao_cadastro_usuario = 0;
                        cin >> opcao_cadastro_usuario;

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << endl;

                        switch (opcao_cadastro_usuario)
                        {
                        case 1:
                        {
                            // CPF

                            usuario_temp.cadastrarCPF(usuario_temp, usuarios);

                            break;
                        }

                        case 2:
                        {
                            // NOME COMPLETO

                            usuario_temp.cadastrarNome(usuario_temp);

                            break;
                        }

                        case 3:
                        {
                            // E-MAIL

                            usuario_temp.cadastrarEmail(usuario_temp, usuarios);

                            break;
                        }

                        case 4:
                        {
                            // SENHA

                            usuario_temp.cadastrarSenha(usuario_temp);

                            break;
                        }

                        case 5:
                        {
                            // SALVAR

                            if (usuario_temp.SalvarUsuario(usuarios, usuario_temp))
                            {
                                // SALVAR OS USUARIO EM UM ARQUIVO
                                usuario_temp.ExportarUsuario(usuarios.back());

                                cout << endl;
                                cout << "Usuario CADASTRADO com sucesso!" << endl;
                                cout << endl;

                                system("pause");

                                // ASSIM QUE CRIAR O USUARIO, JA LOGAR AUTOMATICAMENTE
                                usuario_logado = &usuarios.back();

                                cadastrar_usuario = true;

                                sair_cadastro_login = true;
                            }
                            else
                            {
                                cout << endl;
                                cout << "Por favor, preencha o(s) campo(s) acima antes de salvar!" << endl;
                                cout << endl;

                                system("pause");
                            }
                            break;
                        }

                        case 6:
                        {
                            // RETORNAR AO MENU DE CADASTRO

                            if (RetornarAoMenuDeCadastro())
                            {
                                cadastrar_usuario = true;
                            }

                            break;
                        }

                        default:
                        {
                            cout << endl;
                            cout << "Opcao INVALIDA!" << endl;
                            cout << endl;

                            system("pause");

                            break;
                        }
                        }
                    }

                    break;
                }

                case 2:
                {
                    // LOGIN

                    CLEAR;

                    bool sair_login = false;

                    // PONTEIRO DO TIPO USUARIO QUE RECEBE O VALOR NULLPTR (VAZIO)
                    Usuario *usuario_login = nullptr;

                    while (!sair_login)
                    {
                        CLEAR;

                        cout << endl;
                        cout << "-------------------------LOGIN-----------------------------" << endl;
                        cout << endl;
                        cout << "           1 - CPF / EMAIL" << endl;
                        cout << endl;
                        cout << "           2 - Senha" << endl;
                        cout << endl;
                        cout << "   3 - Retornar ao MENU DE CADASTRO / LOGIN" << endl;
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

                                // cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                cout << endl;
                                cout << "-----------------------------------------------CPF / EMAIL ------------------------------------------------------" << endl;
                                cout << endl;
                                cout << "Digite o seu CPF / EMAIL para fazer o login (ou digite MENU para voltar ao MENU DE LOGIN): ";

                                string login;
                                getline(cin, login);

                                cout << endl;
                                cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << endl;

                                // TRANSFORMA TODAS AS LETRAS PARA MAIUSCULO
                                for (int i = 0; i < login.length(); i++)
                                {
                                    login[i] = toupper((unsigned char)login[i]);
                                }

                                if (login == "MENU")
                                {
                                    if (RetornarAoMenuDeLogin())
                                    {
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                        cpf_email_nome_sair = true;
                                    }
                                    else
                                    {
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                        continue;
                                    }
                                }
                                else
                                {
                                    for (int i = 0; i < login.length(); i++)
                                    {
                                        login[i] = tolower((unsigned char)login[i]);
                                    }
                                    // CHECAR SE O USUARIO EXISTE

                                    // O PONTEIRO ANTERIORMENTE CRIADO RECEBE O VALOR GERADO NA FUNCAO CRAIDA ANTERIORMENTE
                                    usuario_login = EncontrarUsuarioPorLogin(usuarios, login);

                                    if (usuario_login != nullptr)
                                    {
                                        cpf_email_nome_sair = true;
                                    }
                                    else
                                    {
                                        cout << endl;
                                        cout << "Usuario NAO encontrado!" << endl;
                                        cout << endl;
                                        cout << "Tente NOVAMENTE!" << endl;
                                        cout << endl;

                                        system("pause");
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

                                for (int i = 0; i < senha_para_menu.length(); i++)
                                {
                                    senha_para_menu[i] = toupper((unsigned char)senha_para_menu[i]);
                                }

                                if (senha_para_menu == "MENU")
                                {
                                    if (RetornarAoMenuDeLogin())
                                    {
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                        sair_procurar_senha = true;
                                    }
                                    else
                                    {
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

                                        system("pause");

                                        if (RetornarAoMenuDeLogin())
                                        {
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            sair_procurar_senha = true;
                                        }
                                        else
                                        {
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            continue;
                                        }
                                    }

                                    // CHECA SE A SENHA ESTA CORRETA, A SETA UTILIZADA TEM A FUNCAO DE UM PONTEIRO QUE APONTA PARA UM OBJETO, E COMO SE FOSSE USUARIO.SENHA MAS USA A SETA POIS E UM PONTEIRO E NAO UM STRUCT
                                    if (usuario_login != nullptr && usuario_login->getSenha() == senha_login)
                                    {
                                        cout << endl;
                                        cout << "Login REALIZADO com sucesso!" << endl;
                                        cout << endl;

                                        usuario_logado = usuario_login;

                                        carro_temp.LoadVeiculos(usuario_logado);

                                        system("pause");

                                        sair_login = true;

                                        sair_procurar_senha = true;

                                        sair_cadastro_login = true;

                                        break;
                                    }
                                    else
                                    {
                                        cout << endl;
                                        cout << "Senha INCORRETA! Tente novamente!";
                                        cout << endl;

                                        system("pause");
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

                            system("pause");

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            break;
                        }
                        }
                    }

                    break;
                }

                case 3:
                {
                    // RETORNAR AO MENU PRINCIPAL

                    if (RetornarAoMenuPrincipal_Cadastro())
                    {
                        sair_cadastro_login = true;
                    }

                    break;
                }

                default:
                {
                    cout << endl;
                    cout << "Opcao INVALIDA!" << endl;
                    cout << endl;

                    system("pause");

                    break;
                }
                }
            }

            break;
        }

        case 2:
        {
            // REGISTRAR VEICULO

            if (usuario_logado == nullptr)
            {
                cout << endl;
                cout << "Faca LOGIN / CADASTO para acessar a aba REGISTRO DE VEICULO(s)!" << endl;
                cout << endl;

                system("pause");

                break;
            }
            else
            {
                CLEAR;

                bool sair_registro = false;

                while (!sair_registro)
                {
                    CLEAR;

                    cout << endl;
                    cout << "------------------------REGISTRO DE VEICULO-----------------------" << endl;
                    cout << endl;
                    cout << "                   1 - Placa" << endl;
                    cout << endl;
                    cout << "                   2 - Ano" << endl;
                    cout << endl;
                    cout << "                   3 - Cor" << endl;
                    cout << endl;
                    cout << "                   4 - Modelo" << endl;
                    cout << endl;
                    cout << "                   5 - Renavam" << endl;
                    cout << endl;
                    cout << "                   6 - Salvar" << endl;
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

                        CLEAR;

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

                                system("pause");

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
                        if (carro_temp.SalvarCarro(usuario_logado, carro_temp))
                        {
                            carro_temp.ExportarVeiculo(usuario_logado);

                            cout << endl;
                            cout << "Carro CADASTRADO com sucesso!" << endl;
                            cout << endl;

                            system("pause");

                            carro_temp = Carro{}; // arrumar isso para class

                            sair_registro = true;
                        }
                        else
                        {
                            cout << "Por favor, preencha o(s) campo(s) acima antes de salvar!" << endl;
                            cout << endl;

                            system("pause");
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

                        system("pause");

                        break;
                    }
                    }
                }
            }

            break;
        }

        case 3:
        {
            // CHECAR VEICULO (S)

            if (usuario_logado == nullptr)
            {
                cout << endl;
                cout << "Faca LOGIN / CADASTO para acessar a aba CHECAR VEICULO(s)!" << endl;
                cout << endl;

                system("pause");

                break;
            }
            else
            {
                CLEAR;

                bool sair_checar_veiculos = false;

                while (!sair_checar_veiculos)
                {
                    CLEAR;

                    cout << endl;
                    cout << "-----------------------------CHECAR VEICULO(S)------------------------------" << endl;
                    cout << endl;
                    cout << "               1 - Veiculo(s) Registrado(s)" << endl;
                    cout << endl;
                    cout << "               2 - Excluir Veiculo" << endl;
                    cout << endl;
                    cout << "               3 - Alterar Veiculo" << endl;
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
                        // VEICULOS REGISTRADOS
                        carro_temp.VeiculosRegistrados(usuario_logado->carros);

                        sair_checar_veiculos = true;

                        break;
                    }

                    case 2:
                    {
                        // EXCLUIR VEICULO
                        carro_temp.ExcluirVeiculos(usuario_logado->carros);

                        carro_temp.ExportarVeiculo(usuario_logado);

                        sair_checar_veiculos = true;

                        break;
                    }

                    case 3:
                    {
                        // ALTERAR VEICULO
                        carro_temp.AlterarVeiculo(usuario_logado->carros, usuario_logado);

                        sair_checar_veiculos = true;

                        break;
                    }

                    case 4:
                    {
                        // RETORNAR AO MENU PRINCIPAL
                        if (RetornarAoMenuPrincipal_Checar())
                        {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            sair_checar_veiculos = true;
                        }

                        break;
                    }

                    default:
                    {
                        cout << endl;
                        cout << "Opcao INVALIDA!" << endl;
                        cout << endl;

                        system("pause");

                        break;
                    }
                    }
                }
            }

            break;
        }

        case 4:
        {
            // GERAR CRLV

            // CHECAR SE O LOGIN DE USUARIO ESTA LOGADO
            if (usuario_logado == nullptr)
            {
                cout << endl;
                cout << "Faca LOGIN / CADASTRO para acessar a aba CRLV!" << endl;
                cout << endl;

                system("pause");
            }
            else
            {
                CLEAR;

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

                        sair_crlv = true;

                        break;
                    }

                    case 4:
                    {
                        // RETORNAR AO MENU PRINCIPAL
                        if (RetornarAoMenuPrincipal_Crlv())
                        {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            sair_crlv = true;
                        }
                        else
                        {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            continue;
                        }

                        break;
                    }

                    default:
                    {
                        cout << endl;
                        cout << "Opcao INVALIDA!" << endl;
                        cout << endl;

                        system("pause");

                        break;
                    }
                    }
                }
            }

            break;
        }

        case 5:
        {
            // SAIR

            CLEAR;

            cout << "SAIR!" << endl;
            cout << endl;

            system("pause");

            return 0;
        }

        case 6:
        {
            // Aplicar multa
            CLEAR;

            if (!perfil_Policial)
            {
                cout << "Opcao invalida!" << endl;
                cout << endl;
                break;
            }
            else
            {
                // montar funcao que procura veiculo pela placa ou pelo renavam, para aplicar multa, e talvez adicione pontos na carteira
                bool menu_aplicar_multa = true;

                while (menu_aplicar_multa)
                {
                    CLEAR;

                    cout << "-----------------------------------" << endl;
                    cout << endl;
                    cout << "1 - Multar por Placa Cinza" << endl;
                    cout << endl;
                    cout << "2 - Multar po Placa Mercosul" << endl;
                    cout << endl;
                    cout << "3 - Retornar ao Menu Principal" << endl;
                    cout << endl;
                    cout << "-----------------------------------" << endl;

                    int opcao_menu_aplicar_multa = 0;
                    cout << "Digite a opcao desejada: ";
                    cin >> opcao_menu_aplicar_multa;

                    switch (opcao_menu_aplicar_multa)
                    {
                    case 1:
                    {
                        // Placa Cinza

                        bool menu_multar_por_placa_cinza = true;

                        while (menu_multar_por_placa_cinza)
                        {
                            CLEAR;

                            cout << "--------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "   Informe a Placa Cinza que deseja procurar: ";

                            string multa_placa_cinza_temp;
                            getline(cin >> ws, multa_placa_cinza_temp);
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;

                            // void que procura a placa cinza
                        }

                        break;
                    }

                    case 2:
                    {
                        // Placa Mercosul

                        bool menu_multar_por_placa_mercosul = true;

                        while (menu_multar_por_placa_mercosul)
                        {
                            CLEAR;

                            cout << "--------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "   Informe a Placa Mercosul que deseja procurar: ";

                            string multa_placa_mercosul_temp;
                            getline(cin >> ws, multa_placa_mercosul_temp);
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;

                            // void que procura a placa mercosul
                        }

                        break;
                    }

                    case 3:
                    {
                        CLEAR;
                        // retornar ao menu

                        menu_aplicar_multa = false;
                        break;
                    }

                    default:
                    {
                        CLEAR;

                        cout << "Opcao invalida" << endl;

                        break;
                    }
                    }
                }
            }

            break;
        }

        case 7:
        {
            // Checar veiculo
            CLEAR;

            if (!perfil_Policial)
            {
                cout << "Opcao invalida!" << endl;
                cout << endl;
                break;
            }
            else
            {
                // checar se tem multas pendentes para pagamento

                bool menu_checar_multas_pendentes = true;

                while (menu_checar_multas_pendentes)
                {
                    CLEAR;

                    cout << "-----------------------------------" << endl;
                    cout << endl;
                    cout << "1 - Buscar por Placa Cinza" << endl;
                    cout << endl;
                    cout << "2 - Buscar por Placa Mercosul" << endl;
                    cout << endl;
                    cout << "3 - Retornar ao Menu Principal" << endl;
                    cout << endl;
                    cout << "-----------------------------------" << endl;

                    int opcao_menu_checar_multas_pendentes = 0;
                    cout << "Digite a opcao desejada: ";
                    cin >> opcao_menu_checar_multas_pendentes;

                    switch (opcao_menu_checar_multas_pendentes)
                    {
                    case 1:
                    {
                        // Placa Cinza

                        bool menu_buscar_por_placa_cinza = true;

                        while (menu_buscar_por_placa_cinza)
                        {
                            CLEAR;

                            cout << "--------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "   Informe a Placa Cinza que deseja procurar: ";

                            string busca_placa_cinza_temp;
                            getline(cin >> ws, busca_placa_cinza_temp);
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;

                            // void que procura a placa cinza
                        }

                        break;
                    }

                    case 2:
                    {
                        // Placa Mercosul

                        bool menu_buscar_por_placa_mercosul = true;

                        while (menu_buscar_por_placa_mercosul)
                        {
                            CLEAR;

                            cout << "--------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "   Informe a Placa Mercosul que deseja procurar: ";

                            string buscar_placa_mercosul_temp;
                            getline(cin >> ws, buscar_placa_mercosul_temp);
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;

                            // void que procura a placa mercosul
                        }

                        break;
                    }

                    case 3:
                    {
                        CLEAR;
                        // retornar ao menu

                        menu_checar_multas_pendentes = false;

                        break;
                    }

                    default:
                    {
                        CLEAR;

                        cout << "Opcao invalida" << endl;

                        break;
                    }
                    }
                }

                break;
            }

        default:
        {
            cout << endl;
            cout << "OPCAO INVALIDA!" << endl;
            cout << endl;

            system("pause");

            break;
        }
        }
        }
    }
    return 0;
}
