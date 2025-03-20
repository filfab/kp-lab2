#include "ArabRzym.hpp"
#include <iostream>

int ArabRzym::rzym2arab(std::string rzym) {
    int arab = 0;
    std::string original = rzym;
    for (int i=12; i>-1; i--) {
        int c = 0;
        while (!rzym.compare(0, liczby_r[i].length(), liczby_r[i])) {
            if (++c > 3) { throw ArabRzymException("(złe ułożenie znaków/zniedozwolone znaki)"); }
            arab += liczby_a[i];
            rzym = rzym.erase(0, liczby_r[i].length());
        }
    }

    if (!rzym.empty()) { throw ArabRzymException("(złe ułożenie znaków/zniedozwolone znaki)"); }
    return arab;
}


std::string ArabRzym::arab2rzym(int arab) {
    if (arab<1 || arab>3999) { throw ArabRzymException("(liczba musi być z zakresu [1;3999])"); }

    std::string rzym = "";
    for (int i=12; i>-1; i--) {
            while (arab >= liczby_a[i]) {
                rzym = rzym + liczby_r[i];
                arab = arab - liczby_a[i];
            }
        }
        return rzym;
}
