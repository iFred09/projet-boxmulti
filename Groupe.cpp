/**
 * @file Groupe.cpp
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Implémentation de la classe pour les groupes d'objets multimédias
 * @version 0.1
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Groupe.h"
#include "Photo.hpp"
#include "Video.hpp"
#include "Film.h"

/**
 * @brief Constructeur par défaut de la classe Groupe
 * 
 */

Groupe::Groupe()
        :name(""){
    
}

/**
 * @brief Constructeur de la classe Groupe avec paramètres
 * 
 * Constructeur avec arguments qui initialise un groupe avec un nom
 * 
 * @param name Nom du groupe
 */

Groupe::Groupe(std::string name)
        :name(name){
    
}

/**
 * @brief Destructeur pour la classe Groupe
 * 
 */

Groupe::~Groupe(){
}

/**
 * @brief Méthode pour obtenir le nom du groupe
 * 
 * @return std::string Nom du groupe
 */

std::string Groupe::getName() const{
    return name;
}

/**
 * @brief Affiche les valeurs du groupe
 * 
 * @param out Flux de sortie
 */

void Groupe::printValues(std::ostream &out) const{
    out << "Groupe " << name << " : \n";
    for(const std::shared_ptr<Base>& b : *this){
        b->printValues(out);
    }
}

void Groupe::serialize(std::string filename) const{
    std::ofstream file(filename);
    if(file.is_open()){
        file << "Groupe" << std::endl;
        file << name << std::endl;
        file << this->size() << std::endl;
        for(const std::shared_ptr<Base>& b : *this){
            b->serialize(filename);
        }
        file.close();
    }
}

void Groupe::load(std::string filename){
    std::ifstream file(filename);
    if(file.is_open()){
        std::string type;
        std::getline(file, type);
        std::getline(file, name);
        std::string nbObjets;
        std::getline(file, nbObjets);
        int nb = std::stoi(nbObjets);
        for(int i=0 ; i<nb ; i++){
            std::string type;
            std::getline(file, type);
            if (type == "Photo"){
                std::shared_ptr<Photo> photo = std::make_shared<Photo>();
                photo->load(filename);
                this->push_back(photo);
            }
            else if (type == "Video"){
                std::shared_ptr<Video> video = std::make_shared<Video>();
                video->load(filename);
                this->push_back(video);
            }
            else if (type == "Film"){
                std::shared_ptr<Film> film = std::make_shared<Film>();
                film->load(filename);
                this->push_back(film);
            }
        }
        file.close();
    }
}