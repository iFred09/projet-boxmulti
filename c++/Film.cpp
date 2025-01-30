/**
 * @file Film.cpp
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief 
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Film.h"


/**
 * @brief Constructeur par défaut de la classe Film
 * 
 */

Film::Film()
        :Video(), chapitres(nullptr), nbChapitres(0){

        }

Film::Film(const std::string name, const std::string filename)
        :Video(name, filename), chapitres(nullptr), nbChapitres(0){

        }

/**
 * @brief Constructeur de la classe Film avec paramètres
 * 
 * Constructeur avec arguments qui initialise un film avec un nom, un nom de fichier et une durée
 * 
 * @param name Nom du film
 * @param filename Nom du fichier contenant le film
 * @param duration Durée du film
 */

Film::Film(const std::string name, const std::string filename, int duration)
        :Video(name, filename, duration), chapitres(nullptr), nbChapitres(0){

        }

Film::Film(const std::string name, const std::string filename, int duration, const int* chapitres, int nbChapitres)
            :Video(name, filename, duration), chapitres(nullptr), nbChapitres(0){
            setChapitres(chapitres, nbChapitres);
        }

/**
 * @brief Constructeur de copie de la classe Film
 * 
 * Constructeur de copie qui initialise un film avec les mêmes valeurs qu'un autre film
 * 
 * @param film Film à copier
 */
Film::Film(const Film& film)
        :Video(film), chapitres(nullptr), nbChapitres(film.nbChapitres){
    setChapitres(film.chapitres, film.nbChapitres);
}

/**
 * @brief Destructeur pour la classe Film
 * 
 */

Film::~Film(){
    delete[] chapitres;
}

/**
 * @brief Méthode pour obtenir les chapitres du film
 * 
 * @return const int* Tableau des chapitres du film
 */

const int* Film::getChapitres() const{
    return chapitres;
}

/**
 * @brief Méthode pour obtenir le nombre de chapitres du film
 * 
 * @return const int Nombre de chapitres du film
 */

const int Film::getNbChapitres() const{
    return nbChapitres;
}

/**
 * @brief Méthode pour définir les chapitres du film
 * 
 * @param chapitres Tableau des chapitres du film
 * @param nbChapitres Nombre de chapitres du film
 */

void Film::setChapitres(const int* chapitres, int nbChapitres){
    if (this->chapitres == chapitres) return;
    delete[] this->chapitres;
    if (nbChapitres <= 0 || chapitres == nullptr){
        this->nbChapitres = 0;
        this->chapitres = nullptr;
        return;
    }
    this->nbChapitres = nbChapitres;
    this->chapitres = new int[nbChapitres];
    for (int i=0 ; i<nbChapitres ; i++){
        this->chapitres[i] = chapitres[i];
    }
}

/**
 * @brief Affiche les valeurs du film
 * 
 * @param out Flux de sortie
 */

void Film::printValues(std::ostream &out) const{
    Video::printValues(out);
    for(int i=0 ; i<nbChapitres ; i++){
        out << "Chapitre " << i+1 << ", durée : " << chapitres[i] << std::endl;
    }
}

/**
 * @brief Méthode pour écrire les données d'un film depuis un fichier
 * 
 * Sérialisation : écriture des données du film dans un fichier
 * 
 * @param filename 
 */

void Film::serialize(std::ofstream &out) const{
    out << "Film" << std::endl;
    out << getName() << std::endl;
    out << getFileName() << std::endl;
    out << getDuration() << std::endl;
    out << nbChapitres << std::endl;
    for(int i=0 ; i<nbChapitres ; i++){
        out << chapitres[i] << std::endl;
    }
}

/**
 * @brief Méthode pour lire les données d'un film depuis un fichier
 * 
 * Désérialisation : lecture des données du film depuis un fichier
 * 
 * @param filename 
 */

void Film::load(std::ifstream &in){
    in >> nbChapitres;
    chapitres = new int[nbChapitres];
    for(int i=0 ; i<nbChapitres ; i++){
        in >> chapitres[i];
    }
}