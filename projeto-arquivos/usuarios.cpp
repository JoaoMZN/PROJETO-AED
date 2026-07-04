#include "usuarios.hpp"
#include "sistema.hpp"
#include "utils.hpp"
#include "carro.hpp"
#include <iostream>
#include <list>
#include <vector>


Usuario::Usuario()
{ // construtor
    carrosIT = carros.end();
    pontos = 0;
    multas_leves = 0;
    multas_medias = 0;
    multas_graves = 0;
    multas_gravissimas = 0;
};

void Usuario::setNome(string n)
{
    this->nome = n;
}
string Usuario::getNome()
{
    return this->nome;
}

void Usuario::setCpf(string c)
{
    this->cpf = c;
}
string Usuario::getCpf()
{
    return this->cpf;
}

void Usuario::setEmail(string e)
{
    this->email = e;
}
string Usuario::getEmail()
{
    return this->email;
}

void Usuario::setSenha(string s)
{
    this->senha = s;
}
string Usuario::getSenha()
{
    return this->senha;
};

void Usuario::setPontos(int p)
{
    this->pontos = p;
}
int Usuario::getPontos()
{
    return this->pontos;
}

void Usuario::setMultasLeves(int ml)
{
    this->multas_leves = ml;
}
int Usuario::getMultasLeves() const
{
    return this->multas_leves;
}

void Usuario::setMultasMedias(int mm)
{
    this->multas_medias = mm;
}
int Usuario::getMultasMedias() const
{
    return this->multas_medias;
}

void Usuario::setMultasGraves(int mg)
{
    this->multas_graves = mg;
}
int Usuario::getMultasGraves() const
{
    return this->multas_graves;
}

void Usuario::setMultasGravissimas(int mg)
{
    this->multas_gravissimas = mg;
}
int Usuario::getMultasGravissimas() const
{
    return this->multas_gravissimas;
}

void Usuario::cadastrarCPF(Sistema &sistema ,Usuario &usuario_temp)
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
        for (size_t i = 0; i < cpf_novo_temp.length(); i++)
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

        for (auto it = sistema.usuarios.begin(); it != sistema.usuarios.end(); it++)
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

            PAUSE;

            continue;
        }

        bool somente_numeros = true;

        for (size_t i = 0; i < cpf_novo_temp.length(); i++)
        {
            if (!isdigit(cpf_novo_temp[i]))
            {
                somente_numeros = false;

                PAUSE;

                break;
            }
        }

        if (!somente_numeros)
        {
            cout << endl;
            cout << "Formato INVALIDO! Somente numeros sao aceitos!" << endl;
            cout << endl;

            PAUSE;

            continue;
        }

        if (cpf_novo_temp.length() != 11)
        {
            cout << endl;
            cout << "Formato INVALIDO! Deve conter 11 numeros!" << endl;
            cout << endl;

            PAUSE;

            continue;
        }
        else
        {
            // CPF CONDIZ COM AS CONDICOES E PODE SER CADASTRADO

            usuario_temp.setCpf(cpf_novo_temp);

            cout << endl;
            cout << "CPF cadastrado com sucesso!" << endl;
            cout << endl;

            PAUSE;

            // SAI DO WHILE DO CPF
            cadastrarCPF = true;
        }
    }
};

void Usuario::cadastrarNome(Usuario &usuario_temp)
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
        for (size_t i = 0; i < nome_novo_temp.length(); i++)
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
        for (size_t i = 0; i < nome_novo_temp.length(); i++)
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

            PAUSE;

            continue;
        }

        // SEGUNDO A LEGISLACAO BRASILEIRA, TODAS AS PESSOAS TEM DE TER UM NOME PROPRIO E UM SOBRENOME NO MINIMO
        int conta_espacos = 0;

        for (size_t i = 0; i < nome_novo_temp.length(); i++)
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

            PAUSE;

            continue;
        }

        // NOME CORRETO

        usuario_temp.setNome(nome_novo_temp);

        cout << endl;
        cout << "Nome CADASTRADO com sucesso!" << endl;
        cout << endl;

        PAUSE;

        sair_cadastrar_nome = true;
    }
}

void Usuario::cadastrarEmail(Sistema &sistema, Usuario &usuario_temp)
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
        for (size_t i = 0; i < email_novo_temp.length(); i++)
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
        for (size_t i = 0; i < email_novo_temp.length(); i++)
        {
            email_novo_temp[i] = tolower((unsigned char)email_novo_temp[i]);
        }

        // CHECA SE O EMAIL JA FOI REGISTRADO
        bool email_registrado = false;

        for (auto it = sistema.usuarios.begin(); it != sistema.usuarios.end(); it++)
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

            PAUSE;

            continue;
        }

        // CHECAR SE REALEMENTE E UM EMAIL
        bool emailValido = false;

        // O -1 INDICA QUE NADA FOI ENCONTRADO
        size_t posArroba = 0;
        size_t posPonto = 0;

        // PROCURA O @
        for (size_t i = 0; i < email_novo_temp.length(); i++)
        {
            if (email_novo_temp[i] == '@')
            {
                posArroba = i;

                break;
            }
        }

        // SE ENCONTROU O @
        if (posArroba != 0)
        {
            // PROUCURA UM PONTO APOS O @
            for (size_t i = posArroba + 1; i < email_novo_temp.length(); i++)
            {
                if (email_novo_temp[i] == '.')
                {
                    posPonto = i;

                    break;
                }
            }
        }

        // VALIDA O EMAIL, O .LENGTH APARECE DENOVO, PORQUE ELE GARANTE QUE O PONTO NAO VA APARECER COMO ULTIMO CARACTERE DO EMAIL
        if (posArroba != 0 && posPonto != 0 && posPonto < email_novo_temp.length() - 1)
        {
            emailValido = true;
        }

        if (emailValido == false)
        {
            cout << endl;
            cout << "Formato INVALIDO! Cheque novamente o email digitado: " << email_novo_temp << endl;
            cout << endl;

            PAUSE;

            continue;
        }
        else
        {
            // EMAIL CADASTRADO

            usuario_temp.setEmail(email_novo_temp);

            cout << endl;
            cout << "EMAIL cadastrado com sucesso!" << endl;
            cout << endl;

            PAUSE;

            sair_cadastrar_email = true;
        }
    }
}

void Usuario::cadastrarSenha(Usuario &usuario_temp)
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
        for (size_t i = 0; i < menu.length(); i++)
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

            PAUSE;

            continue;
        }

        // CRIAR UMA REGRA PARA MONTAR A SENHA
        bool temLetras = false;

        bool temNumeros = false;

        for (size_t i = 0; i < senha_nova_temp.length(); i++)
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

            PAUSE;

            continue;
        }
        else
        {
            // SENHA VALIDA

            usuario_temp.setSenha(senha_nova_temp);

            cout << endl;
            cout << "Senha cadastrada com sucesso!" << endl;
            cout << endl;

            PAUSE;

            sair_cadastrar_senha = true;
        }
    }
}

void Usuario::OdernacaoPorInsercaoCpfUsuarios(Sistema &sistema) // Ordenação dos usuarios por inserção, com base no cpf de cada usuario
{
    if (sistema.usuarios.size() == 1)
    {
        return;
    }

    auto it = next(sistema.usuarios.begin());

    while (it != sistema.usuarios.end())
    {
        Usuario Copia = *it; // guarda todos os dados da posição do ponteiro

        auto atual = it;
        it++;
        auto posTrocar = atual;

        while (posTrocar != sistema.usuarios.begin() &&
               prev(posTrocar)->getCpf() > Copia.getCpf()) // checa apenas o anterior para ver se troca.
        {
            posTrocar--;
        }
        if (posTrocar != atual) // Executa apenas se precisar de troca
        {
            sistema.usuarios.erase(atual); // apaga tudo da posição

            sistema.usuarios.insert(posTrocar, Copia); // coloca na posição, e como se trata de lista, depois de inserido os valores se reorganizam automaticamente
        }
    }
}

Usuario *Usuario::BuscaBinariaUsuarioPorCpf(Sistema &sistema, string cpf) // Retorna um endereço que será convertido nos valores do usuario encontrado
{
    int inicio = 0;
    int fim = sistema.usuarios.size() - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        auto it = sistema.usuarios.begin();
        advance(it, meio);

        if (it->getCpf() == cpf)
        {
            return &(*it); // endereço de todos os valores da posiçao
        }
        else if (it->getCpf() < cpf)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return nullptr;
}

bool Usuario::SalvarUsuario(Sistema &sistema, Usuario &usuario_temp)
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

    sistema.usuarios.push_back(usuario_temp);
    OdernacaoPorInsercaoCpfUsuarios(sistema); // Ordena nossa lista já incluindo o novo usuario.
    return true;
}

void Usuario::ExportarUsuario(Usuario &usuarios)
{
    if (usuarios.getCpf() == "11111111111")
    {
        return;
    }

    ofstream arquivoUsuarios("UsuarioCadastrados.txt", ios::app);

    if (!arquivoUsuarios.is_open())
    {
        CLEAR;

        cout << endl;
        cout << "ERRO ao abrir o arquivo!" << endl;
        cout << endl;

        PAUSE;
    }

    arquivoUsuarios << "NOME: " << usuarios.getNome() << endl;
    arquivoUsuarios << "CPF: " << usuarios.getCpf() << endl;
    arquivoUsuarios << "EMAIL: " << usuarios.getEmail() << endl;
    arquivoUsuarios << "SENHA: " << usuarios.getSenha() << endl;
    arquivoUsuarios << "LEVES: " << usuarios.getMultasLeves() << endl;
    arquivoUsuarios << "MEDIAS: " << usuarios.getMultasMedias() << endl;
    arquivoUsuarios << "GRAVES: " << usuarios.getMultasGraves() << endl;
    arquivoUsuarios << "GRAVISSIMAS: " << usuarios.getMultasGravissimas() << endl;

    arquivoUsuarios << endl;

    arquivoUsuarios.close();
}

void Usuario::LoadUsuario(Sistema &sistema)
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

        if (linha.rfind("LEVES: ", 0) == 0)
        {
            ler_usuario_temp.setMultasLeves(stoi(linha.substr(7)));
        }

        getline(arquivosUsuarios, linha);

        if (linha.rfind("MEDIAS: ", 0) == 0)
        {
            ler_usuario_temp.setMultasMedias(stoi(linha.substr(8)));
        }

        getline(arquivosUsuarios, linha);

        if (linha.rfind("GRAVES: ", 0) == 0)
        {
            ler_usuario_temp.setMultasGraves(stoi(linha.substr(8)));
        }
        
        getline(arquivosUsuarios, linha);

        if (linha.rfind("GRAVISSIMAS: ", 0) == 0)
        {
            ler_usuario_temp.setMultasGravissimas(stoi(linha.substr(13)));
        }

        getline(arquivosUsuarios, linha);

        sistema.usuarios.push_back(ler_usuario_temp);
    }

    arquivosUsuarios.close();
}

void Usuario::ChecagemCnh(Sistema &sistema)
{
    bool menu_cnh = true;

    while (menu_cnh)
    {
        cout << "Informe o CPF que deseja procurar (ou digite MENU): ";

        string cnh;
        getline(cin >> ws, cnh);
        cout << endl;

        for (size_t i = 0; i < cnh.length(); i++)
        {
            cnh[i] = toupper((unsigned char)cnh[i]);
        }

        if (cnh == "MENU")
        {
            if (RetornarAoMenuPolicial())
            {
                return;
            }
            else
            {
                continue;
            }
        }

        Usuario *usuarioEncontrado = BuscaBinariaUsuarioPorCpf(sistema, cnh); // Ponteiro de classe usuario que retornara o endereço do atributo cpf, caso exista

        if (usuarioEncontrado != nullptr)
        {
            CLEAR;

            Carro carro_multa;

            string cpf_multa = carro_multa.getCpfDono();

            int pontos_multa = usuarioEncontrado->getPontos();

            cout << "CNH encontrada!" << endl;
            cout << endl;

            cout << "--------------------------------------------------" << endl;

            cout << endl;

            cout << "Nome: " << usuarioEncontrado->getNome() << endl;
            cout << endl;
            cout << "CPF: " << usuarioEncontrado->getCpf() << endl;
            cout << endl;
            cout << "Pontos na CNH: " << usuarioEncontrado->getPontos() << endl;
            cout << endl;
            cout << "Multas Leves: " << getMultasLeves() << endl;
            cout << endl;
            cout << "Multas Medias: " << getMultasMedias() << endl;
            cout << endl;
            cout << "Multas Graves: " << getMultasGraves() << endl;
            cout << endl;
            cout << "Multas Gravissimas: " << getMultasGravissimas() << endl;
            cout << endl;

            PAUSE;

            if (pontos_multa >= 40 && getMultasGravissimas() != 0)
            {
                cout << endl;
                cout << "Retirar carteira" << endl;
                cout << endl;

                PAUSE;
            }
            else if (pontos_multa >= 30 && getMultasGravissimas() >= 1)
            {
                cout << endl;
                cout << "Retirar carteira" << endl;
                cout << endl;

                PAUSE;
            }
            else if (pontos_multa >= 20 && getMultasGravissimas() >= 2)
            {
                cout << endl;
                cout << "Retirar carteira" << endl;
                cout << endl;

                PAUSE;
            }
            else
            {
                cout << endl;
                cout << "Pontos e multas aceitaveis" << endl;
                cout << endl;

                PAUSE;
            }

            PAUSE;

            return;
        }
        else
        {
            CLEAR;

            cout << "CNH nao encontrada!" << endl;

            PAUSE;

            return;
        }
    }
}
