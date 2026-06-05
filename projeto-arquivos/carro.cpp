#include "carro.hpp"
#include "usuarios.hpp"
#include "utils.hpp"
#include <iostream>
#include <list>

using namespace std;

class Usuario;

Carro::Carro(string placa_cinza, string placa_mercosul, string ano, string cor, string modelo, string renavam, string status_crlv)
    : placa_cinza(placa_cinza), placa_mercosul(placa_mercosul), ano(ano), cor(cor), modelo(modelo), renavam(renavam), status_crlv(status_crlv) {}
// os dois acima sao contrutores, usados para, : usado para a incializacao, se tirar vai dar erro na hora de salvar o carro

void Carro::setPlacaCinza(string pc)
{
    this->placa_cinza = pc;
}
string Carro::getPlacaCinza() const
{
    return this->placa_cinza;
}

void Carro::setPlacaMercosul(string pm)
{
    this->placa_mercosul = pm;
}
string Carro::getPlacaMercosul() const
{
    return this->placa_mercosul;
}

void Carro::setAno(string a)
{
    this->ano = a;
}
string Carro::getAno() const
{
    return this->ano;
}

void Carro::setCor(string c)
{
    this->cor = c;
}
string Carro::getCor() const
{
    return this->cor;
}

void Carro::setModelo(string m)
{
    this->modelo = m;
}
string Carro::getModelo() const
{
    return this->modelo;
}

void Carro::setRenavam(string r)
{
    this->renavam = r;
}
string Carro::getRenavam() const
{
    return this->renavam;
}

void Carro::setCrlv(string cr)
{
    this->status_crlv = cr;
}
string Carro::getCrlv() const
{
    return this->status_crlv;
}

void Carro::setNomeDono(string nd)
{
    this->nome_dono = nd;
}
string Carro::getNomeDono() const
{
    return this->nome_dono;
}

void Carro::setCpfDono(string cpfd)
{
    this->cpf_dono = cpfd;
}
string Carro::getCpfDono() const
{
    return this->cpf_dono;
}

void Carro::setMultasLeves(int ml)
{
    this->multas_leves = ml;
}
int Carro::getMultasLeves() const
{
    return this->multas_leves;
}

void Carro::setMultasMedias(int mm)
{
    this->multas_medias = mm;
}
int Carro::getMultasMedias() const
{
    return this->multas_medias;
}

void Carro::setMultasGraves(int mg)
{
    this->multas_graves = mg;
}
int Carro::getMultasGraves() const
{
    return this->multas_graves;
}

void Carro::setMultasGravissimas(int mg)
{
    this->multas_gravissimas = mg;
}
int Carro::getMultasGravissimas() const
{
    return this->multas_gravissimas;
}

void Carro::cadastrarPlacaCinza(Carro &carro_temp)
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

            PAUSE;

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

            PAUSE;

            continue;
        }

        carro_temp.setPlacaCinza(placa_cinza_temp);

        // PLACA REGISTRADA
        cout << endl;
        cout << "Placa registrada com sucesso: " << placa_cinza_temp.substr(0, 3) << " - " << placa_cinza_temp.substr(3, 4); // COLOCA O HIFEN NA PLACA E MOSTRA NA TELA COM HIFEN, MAS NAO SALVA O HIFEN NO VETOR
        cout << endl;
        // SUBSTR E UMA FUNCAO DA CLASEE STRING QUE INDICA (POSICAO INICIAL, QUANTAS CASAS PARA FRENTE), NESSE CASO, COMECA NO 0 E ANDA 3 CASAS E DEPOIS COMECA NO 3 E ANDA 4 CASAS

        cout << endl;

        PAUSE;

        // SAI DO REGISTRO DA PLACA MERCOSUL
        registrar_placa_cinza = true;
    }
}

void Carro::cadastrarPlacaMercosul(Carro &carro_temp)
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

            PAUSE;

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

            PAUSE;

            continue;
        }

        carro_temp.setPlacaMercosul(placa_mercosul_temp);

        // PLACA REGISTRADA
        cout << "Placa registrada com sucesso: " << placa_mercosul_temp;
        cout << endl;

        cout << endl;

        PAUSE;

        // SAI DO REGISTRO DA PLACA MERCOSUL
        registrar_placa_mercosul = true;
    }
}

void Carro::cadastrarAno(Carro &carro_temp)
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

            PAUSE;

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
            PAUSE;
        }
        else if (ano_fabricacao > ano_maximo)
        {
            cout << endl;
            cout << "Ano INVALIDO!" << endl;

            cout << "O ano maximo permitido e: " << ano_maximo << endl;
            cout << endl;

            PAUSE;
        }
        else
        {
            carro_temp.setAno(ano_temp);

            cout << endl;
            cout << "Ano REGISTRADO com sucesso" << endl;
            cout << endl;

            PAUSE;

            ano_de_fabricacao = true;
        }
    }
}

void Carro::cadastrarCor(Carro &carro_temp)
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

            PAUSE;
        }
        else
        {
            carro_temp.setCor(cor_nova_temp);

            cout << endl;
            cout << "Cor REGISTRADA com sucesso!" << endl;
            cout << endl;

            PAUSE;

            cadastrar_cor = true;

            break;
        }
    }
}

void Carro::cadastrarModelo(Carro &carro_temp)
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

            PAUSE;

            cadastrar_modelo = true;
        }
    }
}

void Carro::cadastrarRenavam(Carro &carro_temp)
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

            PAUSE;

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

            PAUSE;

            continue;
        }
        else
        {
            carro_temp.setRenavam(renavam_novo_temp);

            cout << endl;
            cout << "Renavam REGISTRADO com sucesso" << endl;
            cout << endl;

            PAUSE;

            cadastrar_renavam = true;
        }
    }
}

void Carro::OdernaçãoPorInsercaoRenavamCarro(list<Carro> &carros) // Ordenação dos usuarios por inserção, com base na Renavam do carro
{
    if (carros.size() <= 1)
    {
        return;
    }

    auto it = next(carros.begin());

    while (it != carros.end())
    {
        Carro Copia = *it; // guarda todos os dados da posição do ponteiro

        auto atual = it;
        it++;
        auto posTrocar = atual;

        while (posTrocar != carros.begin() &&
               prev(posTrocar)->getRenavam() > Copia.getRenavam()) // checa apenas o anterior para ver se troca.
        {
            posTrocar--;
        }

        carros.erase(atual); // apaga tudo da posição

        carros.insert(posTrocar, Copia); // coloca na posição, e como se trata de lista, depois de inserido os valores se reorganizam automaticamente
    }
}

Carro* BuscaBinariaCarroPorModelo(list<Carro> &carros, string modelo) // Retornara endereços de todos os atributos de carro e será em valores reais
{
    int inicio = 0;
    int fim = carros.size() - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        auto it = carros.begin();
        advance(it, meio);

        if (it->getModelo() == modelo)
        {
            return &(*it); // Retorna os endereços de todos os valores
        }
        else if (it->getModelo() < modelo)
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

bool Carro::SalvarCarro(Usuario *usuario_logado, Carro &carro_temp)
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

    usuario_logado->carros.push_back(carro_temp);

    this->OdernaçãoPorInsercaoRenavamCarro(usuario_logado->carros); // Ordena a lista carro, com o carro que acabei de salvar
    return true;
}

void Carro::ExportarVeiculo(list<Usuario> &usuarios) // troquei para listas
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

        PAUSE;
    }
    else
    { // Aqui vamos Rescrever todas as informações no arquivo, não tendo erro de duplicada e sobscrita.
        for (auto usuario = usuarios.begin(); usuario != usuarios.end(); usuario++)
        {
            for (auto carro = usuario->carros.begin(); carro != usuario->carros.end(); carro++)
            {
                arquivoVeiculos << "NOME: " << usuario->getNome() << endl;
                arquivoVeiculos << "CPF: " << usuario->getCpf() << endl;

                if (!carro->getPlacaCinza().empty())
                {
                    arquivoVeiculos << "PLACA CINZA: " << carro->getPlacaCinza() << endl;
                }
                else if (!carro->getPlacaMercosul().empty())
                {
                    arquivoVeiculos << "PLACA MERCOSUL: " << carro->getPlacaMercosul() << endl;
                }

                arquivoVeiculos << "ANO: " << carro->getAno() << endl;
                arquivoVeiculos << "COR: " << carro->getCor() << endl;
                arquivoVeiculos << "MODELO: " << carro->getModelo() << endl;
                arquivoVeiculos << "RENAVAM: " << carro->getRenavam() << endl;
                arquivoVeiculos << endl;
            }
        }
        arquivoVeiculos.close();
    }
}

void Carro::LoadVeiculos(list<Usuario> &usuarios)
{
    ifstream arquivoVeiculos("ArquivoVeiculos.txt");

    if (!arquivoVeiculos.is_open())
    {
        cout << "Arquivo de veiculos nao encontrado ou erro ao abrir." << endl;
        cout << endl;

        PAUSE;

        return;
    }

    // Evitar duplicação
    for (auto usuario = usuarios.begin(); usuario != usuarios.end(); usuario++)
    {
        usuario->carros.clear();
    }

    string linha;
    string cpf_arquivo = "";

    Carro carro_temp;

    bool dados_preenchidos = false;

    while (getline(arquivoVeiculos, linha))
    {
        // Linha vazia indica fim dos dados de um carro
        if (linha.empty())
        {
            // Se o carro foi preenchido corretamente
            if (dados_preenchidos)
            {
                // Apenas para conseguir chamar a Busca binaria dentro da classe Carro, pois essa função foi declarada na classe Usuario
                Usuario usuario_auxiliar;
                Usuario *usuario_encontrado = usuario_auxiliar.BuscaBinariaUsuarioPorCpf(usuarios, cpf_arquivo);

                if (usuario_encontrado != nullptr)
                {
                    usuario_encontrado->carros.push_back(carro_temp);
                }
            }

            carro_temp = Carro();

            cpf_arquivo = "";

            dados_preenchidos = false;

            continue;
        }

        if (linha.rfind("CPF: ", 0) == 0)
        {
            cpf_arquivo = linha.substr(5);
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

    // último carro do arquivo
    if (dados_preenchidos)
    {
        // Apenas para conseguir chamar a Busca binaria dentro da classe Carro, pois essa função foi declarada na classe Usuario
        Usuario usuario_auxiliar;
        Usuario *usuario_encontrado = usuario_auxiliar.BuscaBinariaUsuarioPorCpf(usuarios, cpf_arquivo);

        if (usuario_encontrado != nullptr)
        {
            usuario_encontrado->carros.push_back(carro_temp);
        }
    }

    arquivoVeiculos.close();
}

void Carro::VeiculosRegistrados(list<Carro> &carros)
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

        PAUSE;

        sair_veiculos_registrados = true;
    }
}

void Carro::ExcluirVeiculos(list<Carro> &carros)
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

                    PAUSE;

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

                    PAUSE;

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

            PAUSE;

            continue;
        }
    }
}

void Carro::AlterarVeiculo(list<Carro> &carros, Usuario *usuario_logado, list<Usuario> &usuarios)
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

                        ExportarVeiculo(usuarios);

                        cout << endl;
                        cout << "Nova PLACA CINZA registrada com sucesso!" << endl;
                        cout << endl;

                        PAUSE;

                        sair_encontrou_alterar_veiculo = true;
                        sair_alterar_veiculo = true;

                        break;
                    }

                    case 2:
                    {
                        cadastrarPlacaMercosul(*it);
                        it->setPlacaCinza("");

                        ExportarVeiculo(usuarios);

                        cout << endl;
                        cout << "Nova PLACA MERCOSUL registrada com sucesso!" << endl;
                        cout << endl;

                        PAUSE;

                        sair_encontrou_alterar_veiculo = true;
                        sair_alterar_veiculo = true;

                        break;
                    }

                    case 3:
                    {
                        cadastrarAno(*it);

                        ExportarVeiculo(usuarios);

                        cout << endl;
                        cout << "Novo ANO registrado com sucesso!" << endl;
                        cout << endl;

                        PAUSE;

                        sair_encontrou_alterar_veiculo = true;
                        sair_alterar_veiculo = true;

                        break;
                    }

                    case 4:
                    {
                        cadastrarCor(*it);

                        ExportarVeiculo(usuarios);

                        cout << endl;
                        cout << "Nova COR registrada com sucesso!" << endl;
                        cout << endl;

                        PAUSE;

                        sair_encontrou_alterar_veiculo = true;
                        sair_alterar_veiculo = true;

                        break;
                    }

                    case 5:
                    {
                        cadastrarModelo(*it);

                        ExportarVeiculo(usuarios);

                        cout << endl;
                        cout << "Novo MODELO registrado com sucesso!" << endl;
                        cout << endl;

                        PAUSE;

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

                        PAUSE;

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

                PAUSE;

                break;
            }
        }
    }
}

void Carro::Multas(list<Carro> &carros) // nao acabado
{
    bool menu_multas = true;

    while (menu_multas)
    {
        CLEAR;

        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "           1 - Checar multas pendentes" << endl;
        cout << endl;
        cout << "           2 - Pagar multa" << endl;
        cout << endl;
        cout << "           3 - Retornar ao Menu de Multas" << endl;
        cout << endl;
        cout << "--------------------------------------------------------" << endl;

        int opcao = 0;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            // checar multas

            bool menu_multa_placa = true;

            while (menu_multa_placa)
            {
                CLEAR;

                cout << "--------------------------------------------------------" << endl;
                cout << endl;
                cout << "Informe a Placa que deseja procurar (ou digite MENU): ";

                string multa_placa_temp;
                getline(cin >> ws, multa_placa_temp);
                cout << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << endl;

                for (int i = 0; i < multa_placa_temp.length(); i++)
                {
                    multa_placa_temp[i] = toupper((unsigned char)multa_placa_temp[i]);
                }

                if (multa_placa_temp == "MENU")
                {
                    if (RetornarAoMenuDeMultas()) // fazer menu
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

                bool achou = false;

                auto it = carros.begin();

                for (auto i = it; i != carros.end(); i++)
                {
                    if (multa_placa_temp == it->getPlacaCinza() || multa_placa_temp == it->getPlacaMercosul())
                    {
                        it = i;
                        achou = true;
                    }
                }

                if (achou)
                {
                    CLEAR;

                    cout << "Veiculo encontrado!" << endl;

                    // arrumar logica de multa, como vai mostrar que tem multa

                    PAUSE;

                    return;
                }
                else
                {
                    CLEAR;

                    cout << "Veiculo nao encontrado!" << endl;

                    PAUSE;

                    return;
                }
            }

            break;
        }
        case 2:
        {
            // pagar multa

            bool menu_multa_placa = true;

            while (menu_multa_placa)
            {
                CLEAR;

                cout << "--------------------------------------------------------" << endl;
                cout << endl;
                cout << "Informe a Placa que deseja procurar (ou digite MENU): ";

                string multa_placa_temp;
                getline(cin >> ws, multa_placa_temp);
                cout << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << endl;

                for (int i = 0; i < multa_placa_temp.length(); i++)
                {
                    multa_placa_temp[i] = toupper((unsigned char)multa_placa_temp[i]);
                }

                if (multa_placa_temp == "MENU")
                {
                    if (RetornarAoMenuDeMultas()) // fazer menu
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

                bool achou = false;

                auto it = carros.begin();

                for (auto i = it; i != carros.end(); i++)
                {
                    if (multa_placa_temp == it->getPlacaCinza() || multa_placa_temp == it->getPlacaMercosul())
                    {
                        it = i;
                        achou = true;
                    }
                }

                if (achou)
                {
                    CLEAR;

                    cout << "Veiculo encontrado!" << endl;

                    // arrumar logica de multa, como vai mostrar que tem multa

                    PAUSE;

                    return;
                }
                else
                {
                    CLEAR;

                    cout << "Veiculo nao encontrado!" << endl;

                    PAUSE;

                    return;
                }
            }

            break;
        }
        case 3:
        {
            CLEAR;

            if (RetornarAoMenuDeVeiculos())
            {
                return;
            }
            else
            {
                continue;
            }

            PAUSE;
        }
        default:
        {
            CLEAR;

            cout << "Opcao invalida" << endl;

            PAUSE;
        }
        }
    }
}

void Carro::GerarCrlv(list<Carro> &carros, Usuario *usuario_logado)
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

                PAUSE;

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

            PAUSE;
        }
    }
}

void Carro::ExportarCrlv(list<Carro> &carros, Usuario *usuario_logado)
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

                    PAUSE;

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

                PAUSE;

                sair_exportar_crlv = true;

                break;
            }
        }

        if (!encontrou_veiculo)
        {
            cout << endl;
            cout << "Nenhum VEICULO foi encontrado com esse dado!" << endl;
            cout << endl;

            PAUSE;

            continue;
        }
    }
}

void Carro::ListarVeiculos_CRLV(list<Carro> &carros)
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

        PAUSE;

        sair_listar_veiculos_crlv = true;
    }
}

void Carro::LoadVeiculosPolicia(Usuario *usuario_logado)
{
    ifstream arquivosVeiculosSistema("arquivosVeiculosSistema.txt");

    if (!arquivosVeiculosSistema.is_open())
    {
        cout << "Arquivo de veiculos nao encontrado ou erro ao abrir." << endl;
        cout << endl;

        PAUSE;

        return;
    }

    usuario_logado->carros.clear();

    string linha;

    Carro carro_temp;

    while (getline(arquivosVeiculosSistema, linha))
    {
        // SE A LINHA ESTIVER VAZIA INDICA O FIM DOS DADOS DE UM CARRO, LOGO TERA OUTRO CARRO
        if (linha.empty())
        {
            usuario_logado->carros.push_back(carro_temp);

            // RESETA AS VARIAVEIS PARA O PROXIMO CARRO DO ARQUIVO CASO NAO SEJA ESSE
            carro_temp = Carro();

            continue;
        }

        // VERIFICA O NOME
        if (linha.rfind("NOME: ", 0) == 0)
        {
            carro_temp.setNomeDono(linha.substr(6));
        }

        else if (linha.rfind("CPF: ", 0) == 0)
        {
            carro_temp.setCpfDono(linha.substr(5));
        }

        else if (linha.rfind("PLACA CINZA: ", 0) == 0)
        {
            carro_temp.setPlacaCinza(linha.substr(13));
        }

        else if (linha.rfind("PLACA MERCOSUL: ", 0) == 0)
        {
            carro_temp.setPlacaMercosul(linha.substr(16));
        }

        else if (linha.rfind("ANO: ", 0) == 0)
        {
            carro_temp.setAno(linha.substr(5));
        }

        else if (linha.rfind("COR: ", 0) == 0)
        {
            carro_temp.setCor(linha.substr(5));
        }

        else if (linha.rfind("MODELO: ", 0) == 0)
        {
            carro_temp.setModelo(linha.substr(8));
        }

        else if (linha.rfind("RENAVAM: ", 0) == 0)
        {
            carro_temp.setRenavam(linha.substr(9));
        }
    }

    if (carro_temp.getPlacaCinza() != "") // logica para ter certeza de que serao salvos todos os veiculos
    {
        usuario_logado->carros.push_back(carro_temp);
    }
}

void Carro::MultaPlaca(list<Carro> &carros, Usuario *usuario_logado) // nao acabado
{
    bool menu_multa_placa = true;

    while (menu_multa_placa)
    {
        CLEAR;

        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "Informe a Placa que deseja procurar (ou digite MENU): ";

        string multa_placa_temp;
        getline(cin >> ws, multa_placa_temp);
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;

        for (int i = 0; i < multa_placa_temp.length(); i++)
        {
            multa_placa_temp[i] = toupper((unsigned char)multa_placa_temp[i]);
        }

        if (multa_placa_temp == "MENU")
        {
            if (RetornarAoMenuDeMultasPlaca())
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

        bool achou = false;

        auto it = carros.begin();
        auto placa_multada = it;

        for (auto i = it; i != carros.end(); i++)
        {
            if (multa_placa_temp == it->getPlacaCinza() || multa_placa_temp == it->getPlacaMercosul())
            {
                it = i;
                achou = true;
                placa_multada = it;
            }
        }

        if (achou)
        {
            CLEAR;

            cout << "Veiculo encontrado!" << endl;

            cout << "--------------------------------------------------" << endl;

            // logica para puxar os dados inteiros do veiculo
            cout << endl;
            cout << "Nome: " << placa_multada->nome_dono << endl;
            cout << endl;
            cout << "CPF: " << placa_multada->cpf_dono << endl;
            cout << endl;
            cout << "Placa: " << multa_placa_temp << endl;
            cout << endl;
            cout << "Modelo: " << placa_multada->modelo << endl;
            cout << endl;
            cout << "Cor: " << placa_multada->cor << endl;
            cout << endl;
            cout << "Ano: " << placa_multada->ano << endl;
            cout << endl;
            cout << "Renavam: " << placa_multada->renavam << endl;
            cout << endl;
            cout << "---------------------------------------------------" << endl;

            bool veiculo_multa = true;

            // arrumar a logica de salvar os pontos na carteira
            Usuario usuario_multado;

            while (veiculo_multa)
            {
                cout << "-----------------------------------------" << endl;
                cout << "Tipo de Multa: " << endl;
                cout << endl;
                cout << "1 - Leve" << endl;
                cout << endl;
                cout << "2 - Media" << endl;
                cout << endl;
                cout << "3 - Grave" << endl;
                cout << endl;
                cout << "4 - Gravissima" << endl;
                cout << endl;
                cout << "5 - Retornar ao Menu Principal" << endl;
                cout << endl;
                cout << "----------------------------------------------" << endl;

                cout << "Tipo da multa: ";
                int opcao_multa_placa = 0;
                cin >> opcao_multa_placa;

                switch (opcao_multa_placa)
                {
                case 1:
                {
                    CLEAR;

                    // leve
                    usuario_multado.setPontos(usuario_multado.getPontos() + 3);

                    setMultasLeves(getMultasLeves() + 1);

                    break;
                }

                case 2:
                {
                    CLEAR;

                    // media
                    usuario_multado.setPontos(usuario_multado.getPontos() + 4);

                    setMultasMedias(getMultasMedias() + 1);

                    break;
                }

                case 3:
                {
                    CLEAR;

                    // grave

                    usuario_multado.setPontos(usuario_multado.getPontos() + 5);

                    setMultasGraves(getMultasGraves() + 1);

                    break;
                }

                case 4:
                {
                    CLEAR;

                    // gravissima

                    usuario_multado.setPontos(usuario_multado.getPontos() + 7);

                    setMultasGravissimas(getMultasGravissimas() + 1);

                    break;
                }

                case 5:
                {
                    CLEAR;

                    if (RetornarAoMenuPrincipal_Multas())
                    {
                        veiculo_multa = false;

                        return;
                    }
                    else
                    {
                        continue;
                    }

                    break;
                }

                default:
                {
                    CLEAR;

                    cout << "Opcao invalida" << endl;

                    PAUSE;
                    break;
                }
                }
            }

            cout << endl;
            cout << "Multa registrada com sucesso" << endl;
            cout << endl;

            PAUSE;

            return;
        }
        else
        {
            CLEAR;

            cout << endl;
            cout << "Veiculo nao encontrado!" << endl;
            cout << endl;

            PAUSE;

            continue;
        }
    }
}
