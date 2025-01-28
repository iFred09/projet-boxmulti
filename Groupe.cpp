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