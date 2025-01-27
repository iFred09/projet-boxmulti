/**
 * @file Groupe.h
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Déclaration de la classe pour les groupes d'objets multimédias
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef GROUPE_H
#define GROUPE_H

#include "Base.h"
#include <list>
#include <memory>

/**
 * @brief Classe pour les groupes d'objets multimédias
 * 
 */

class Groupe : public std::list<std::shared_ptr<Base>>{
    private:
        std::string name;   // Nom du groupe
    public:
        /**
         * @brief Constructeur par défaut de la classe Groupe
         * 
         */
        Groupe();

        /**
         * @brief Constructeur de la classe Groupe avec paramètres
         * 
         * Constructeur avec arguments qui initialise un groupe avec un nom
         * 
         * @param name Nom du groupe
         */
        Groupe(std::string name);

        /**
         * @brief Destructeur pour la classe Groupe
         * 
         */
        ~Groupe();

        /**
         * @brief Méthode pour obtenir le nom du groupe
         * 
         * @return std::string Nom du groupe
         */
        std::string getName() const;

        /**
         * @brief Affiche les valeurs du groupe
         * 
         * @param out Flux de sortie
         */
        void printValues(std::ostream& out) const;

        /**
         * @brief Méthode pour écrire les données d'un groupe dans un fichier
         * 
         * Sérialisation : écriture des données d'un groupe dans un fichier
         * 
         * @param filename 
         */
        void serialize(std::string filename) const;

        /**
         * @brief Méthode pour lire les données d'un groupe depuis un fichier
         * 
         * Désérialisation : lecture des données d'un groupe depuis un fichier
         * 
         * @param filename 
         */

        void load(std::string filename);
};

#endif