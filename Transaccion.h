#include <fstream>
using namespace std;
template <typename M>
struct Transaccion
{
    string emisor;
    string receptor;
    M monto;
    Transaccion(string _emisor, string _receptor, M _monto)
    {
        emisor = _emisor;
        receptor = _receptor;
        monto = _monto;
    }
};
template <typename M>
ostream &operator<<(ostream &o, const Transaccion<M> &p)
{
    o << "(" << p.emisor << " -> " << p.monto << " -> " << p.receptor << ")";
    return o;
}