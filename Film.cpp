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
    if (nbChapitres < 0) return;
    delete[] this->chapitres;
    this->nbChapitres = nbChapitres;
    this->chapitres = new int[nbChapitres];
    if (chapitres == nullptr) return;
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

void Film::serialize(std::string filename) const{
    std::ofstream file(filename);
    if(file.is_open()){
        file << "Film" << std::endl;
        file << getName() << std::endl;
        file << getFileName() << std::endl;
        file << getDuration() << std::endl;
        file << nbChapitres << std::endl;
        for(int i=0 ; i<nbChapitres ; i++){
            file << chapitres[i] << std::endl;
        }
        file.close();
    }
}

/**
 * @brief Méthode pour lire les données d'un film depuis un fichier
 * 
 * Désérialisation : lecture des données du film depuis un fichier
 * 
 * @param filename 
 */

void Film::load(std::string filename){
    std::ifstream file(filename);
    if(file.is_open()){
        std::string type;
        std::getline(file, type);
        std::string name;
        std::getline(file, name);
        std::string filename;
        std::getline(file, filename);
        int duration;
        file >> duration;
        int nbChapitres;
        file >> nbChapitres;
        int* chapitres = new int[nbChapitres];
        for(int i=0 ; i<nbChapitres ; i++){
            file >> chapitres[i];
        }
        setChapitres(chapitres, nbChapitres);
        Video::setName(name);
        Video::setFileName(filename);
        Video::setDuration(duration);
        delete[] chapitres;
        file.close();
    }
}