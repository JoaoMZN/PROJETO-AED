#include "sistema.hpp"
#include <list>
#include <clocale>
#include <vector>
#include "menu.hpp"
#include "usuarios.hpp"
#include "carro.hpp"
#include "utils.hpp"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    Sistema sistema;
    Usuario *usuario_logado = nullptr;
    Carro carro_temp;

    Usuario usuario_load;
    usuario_load.LoadUsuario(sistema);

    Usuario *policial_existe = usuario_load.BuscaBinariaUsuarioPorCpf(sistema, "11111111111");

    if (policial_existe == nullptr)
    {
        Usuario policial;
        policial.setNome("Policia");
        policial.setCpf("11111111111");
        policial.setEmail("policiarodoviaria@detran.com");
        policial.setSenha("policia");
        sistema.usuarios.push_back(policial);
        usuario_load.OdernacaoPorInsercaoCpfUsuarios(sistema);
    }

    MenuInicial(sistema, usuario_logado, carro_temp);

    return 0;
}