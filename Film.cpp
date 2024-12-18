#include "Film.h"

Film::Film(const std::string name, const std::string filename, int duration)
        :Video(name, filename, duration), chapitres(nullptr), nbChapitres(0){

        }

Film::~Film(){
    delete[] chapitres;
}

int* Film::getChapitres() const{
    return chapitres;
}

int Film::getNbChapitres() const{
    return nbChapitres;
}

void Film::setChapitres(int* chapitres, int nbChapitres){
    this->nbChapitres = nbChapitres;
    if (this->chapitres){
        delete[] this->chapitres;
    }
    this->chapitres = new int[nbChapitres];
    for (int i=0 ; i<nbChapitres ; i++){
        this->chapitres[i] = chapitres[i];
    }
}

void Film::printValues(std::ostream &out) const{
    for(int i=0 ; i<nbChapitres ; i++){
        out << "Chapitre " << i+1 << ", durée : " << chapitres[i] << '\n';
    }
}