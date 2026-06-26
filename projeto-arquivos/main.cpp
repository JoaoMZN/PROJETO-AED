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

    list<Usuario> usuarios;
    vector<list<Usuario*>> usuariosHash(101);
    list<Carro> carros;
    vector<list<Carro*>> carrosHash(101);
    Usuario *usuario_logado = nullptr;
    Carro carro_temp;

    Usuario usuario_load;
    usuario_load.LoadUsuario(usuarios, usuariosHash);

    Usuario *policial_existe = usuario_load.BuscaBinariaUsuarioPorCpf(usuarios, "11111111111");

    if (policial_existe == nullptr)
    {
        Usuario policial;
        policial.setNome("Policia");
        policial.setCpf("11111111111");
        policial.setEmail("policiarodoviaria@detran.com");
        policial.setSenha("policia");
        usuarios.push_back(policial);
        usuario_load.OdernaçãoPorInsercaoCpfUsuarios(usuarios);
        usuario_load.montagemTabelaHash(usuarios, usuariosHash);
    }

    MenuInicial(usuarios, usuario_logado, carro_temp, carros, usuariosHash, carrosHash);

    return 0;
}