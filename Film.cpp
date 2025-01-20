#include "Film.h"

Film::Film(const std::string name, const std::string filename, int duration)
        :Video(name, filename, duration), chapitres(nullptr), nbChapitres(0){

        }

Film::Film(const Film& film)
        :Video(film), chapitres(nullptr), nbChapitres(film.nbChapitres){
    if (nbChapitres > 0){
        chapitres = new int[nbChapitres];
        std::memcpy(chapitres, film.chapitres, nbChapitres*sizeof(int));
    }
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
    std::memcpy(this->chapitres, chapitres, nbChapitres*sizeof(int));
}

void Film::printValues(std::ostream &out) const{
    for(int i=0 ; i<nbChapitres ; i++){
        out << "Chapitre " << i+1 << ", durée : " << chapitres[i] << '\n';
    }
}