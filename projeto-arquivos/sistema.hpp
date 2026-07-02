#pragma onde 
#include <list> 
#include <vector>

using namespace std;

class Usuario;
class Carro;

struct Sistema
{
    list<Usuario> usuarios;
    list<Carro> carros;
    vector<list<Carro*>> carrosHash;
};