#include "Base.h"

Base::Base(){
    this->name = "";
    this->filename = "";
}

Base::Base(std::string name, std::string filename){
    this->name = name;
    this->filename = filename;
}

Base::~Base(){
    
}

void Base::setName(std::string name){
    this->name = name;
}

void Base::setFileName(std::string filename){
    this->filename = filename;
}

std::string Base::getName() const{
    return name;
}

std::string Base::getFileName() const{
    return filename;
}

void Base::printValues(std::ostream &out) const{
    out << "Nom : " << name << '\n';
    out << "Nom du fichier : " << filename << '\n';
}