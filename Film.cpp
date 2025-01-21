#include "Film.h"

Film::Film()
        :Video(), chapitres(nullptr), nbChapitres(0){

        }

Film::Film(const std::string name, const std::string filename, int duration)
        :Video(name, filename, duration), chapitres(nullptr), nbChapitres(0){

        }

Film::Film(const Film& film)
        :Video(film), chapitres(nullptr), nbChapitres(film.nbChapitres){
    setChapitres(film.chapitres, film.nbChapitres);
}

Film::~Film(){
    delete[] chapitres;
}

const int* Film::getChapitres() const{
    return chapitres;
}

int Film::getNbChapitres() const{
    return nbChapitres;
}

void Film::setChapitres(const int* chapitres, int nbChapitres){
    if (nbChapitres < 0) return;
    delete[] this->chapitres;
    this->nbChapitres = nbChapitres;
    this->chapitres = new int[nbChapitres];
    std::memcpy(this->chapitres, chapitres, nbChapitres*sizeof(int));
}

void Film::printValues(std::ostream &out) const{
    Video::printValues(out);
    for(int i=0 ; i<nbChapitres ; i++){
        out << "Chapitre " << i+1 << ", durée : " << chapitres[i] << '\n';
    }
}