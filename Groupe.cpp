#include "Groupe.h"

Groupe::Groupe(std::string name)
        :name(name){
    
}

Groupe::~Groupe(){
}

std::string Groupe::getName() const{
    return name;
}

void Groupe::printValues(std::ostream &out) const{
    out << "Groupe " << name << " : \n";
    for(const Base* b : *this){
        b->printValues(out);
    }
}