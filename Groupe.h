#ifndef GROUPE_H
#define GROUPE_H

#include "Base.h"
#include <list>

class Groupe : public std::list<Base*>{
    private:
        std::string name;
    public:
        Groupe(std::string);
        ~Groupe();
        std::string getName() const;
        void printValues(std::ostream&) const;
};

#endif