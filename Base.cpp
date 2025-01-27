/**
 * @file Base.cpp
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Implémentation de la classe de base pour les objets multimédias
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Base.h"

/**
 * @brief Constructeur par défaut de la classe Base
 * Initialise l'objet multimédia avec un nom vide et un nom de fichier vide
 * 
 */
Base::Base(){
    this->name = "";
    this->filename = "";
}

/**
 * @brief Constructeur de la classe Base avec paramètres
 * 
 * @param name Nom de l'objet multimédia
 * @param filename Nom du fichier contenant l'objet multimédia
 */

Base::Base(std::string name, std::string filename){
    this->name = name;
    this->filename = filename;
}

/**
 * @brief Destructeur pour la classe Base
 * 
 */

Base::~Base(){
    
}

/**
 * @brief Méthode pour définir le nom de l'objet multimédia
 * 
 * @param name Nouveau nom de l'objet multimédia
 */

void Base::setName(std::string name){
    this->name = name;
}

/**
 * @brief Méthode pour définir le nom du fichier de l'objet multimédia
 * 
 * @param filename Nouveau nom de fichier de l'objet multimédia
 */

void Base::setFileName(std::string filename){
    this->filename = filename;
}

/**
 * @brief Méthode pour obtenir le nom de l'objet multimédia
 * 
 * @return std::string Nom de l'objet multimédia
 */

std::string Base::getName() const{
    return name;
}

/**
 * @brief Méthode pour obtenir le nom du fichier de l'objet multimédia
 * 
 * @return std::string Nom du fichier de l'objet multimédia
 */

std::string Base::getFileName() const{
    return filename;
}

/**
 * @brief Affiche les valeurs de l'objet multimédia
 * 
 * @param out Flux de sortie
 */

void Base::printValues(std::ostream &out) const{
    out << "Nom : " << name << std::endl;
    out << "Nom du fichier : " << filename << std::endl;
}