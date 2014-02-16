#ifndef COULEURPION_H
#define COULEURPION_H

#include <iostream>
#include <type_traits>


enum class CouleurPion {
    aucuneCouleur,
    noir,
    blanc,
};

//Permet d'utiliser directement cout avec CouleurPion, (par exemple cout << CouleurPion::noir << endl; )
inline std::ostream& operator << (std::ostream& os, const CouleurPion& obj)
{
   os << static_cast<std::underlying_type<CouleurPion>::type>(obj);
   return os;
}

#endif // COULEURPION_H
