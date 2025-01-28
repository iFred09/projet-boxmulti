/**
 * @file Base.h
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Déclaration de la classe de base pour les objets multimédias
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 */

#ifndef base_h
#define base_h

#include <iostream>
#include <string>
#include <fstream>

/**
 * @class Base
 * @brief Classe abstraite de base pour les objets multimédias
 * 
 * Classe abstraite de base pour les objets multimédias, tels que les photos, les vidéos et les films.
 * Fournit les méthodes de base pour manipuler les objets multimédias et peuvent être override par les classes filles
 * 
 */

class Base{
    friend class Gestionnaire;
    private:
        std::string name{}; // Nom de l'objet multimédia
        std::string filename{}; // Nom du fichier contenant l'objet multimédia
    protected:
        /**
         * @brief Constructeur par défaut de la classe Base
         * Initialise l'objet multimédia avec un nom vide et un nom de fichier vide
         */
        Base();
        
        /**
         * @brief Constructeur de la classe Base avec paramètres
         * 
         * @param name Le nom de l'objet multimédia
         * @param filename Le nom du fichier contenant l'objet multimédia
         */
        Base(std::string name, std::string filename);
    public:
        /**
         * @brief Destructeur pour la classe Base
         * 
         */
        virtual ~Base();
        /**
         * @brief Méthode pour définir le nom de l'objet multimédia
         * 
         * @param name Nouveau nom de l'objet multimédia
         */
        void setName(std::string name);
        /**
         * @brief Méthode pour définir le nom du fichier de l'objet multimédia
         * 
         * @param filename Nouveau nom de fichier de l'objet multimédia
         */
        void setFileName(std::string filename);
        /**
         * @brief Méthode pour obtenir le nom de l'objet multimédia
         * 
         * @return std::string Nom de l'objet multimédia
         */
        std::string getName() const;
        /**
         * @brief Méthode pour obtenir le nom du fichier de l'objet multimédia
         * 
         * @return std::string Nom du fichier de l'objet multimédia
         */
        std::string getFileName() const;
        /**
         * @brief Affiche les valeurs de l'objet multimédia
         * 
         * @param out Flux de sortie
         */
        virtual void printValues(std::ostream &out) const;
        /**
         * @brief Méthode virtuelle pure pour jouer l'objet multimédia
         * 
         * Méthode virtuelle pure pour jouer l'objet multimédia, qui doit être implémentée par les classes filles
         */
        virtual void play() const = 0;
        /**
         * @brief Méthode pour sauvegarder l'objet multimédia dans un flux de sortie
         * 
         * Méthode virtuelle pure pour sauvegarder l'objet multimédia dans un flux de sortie, qui doit être implémentée par les classes filles
         * 
         * @param out Flux de sortie
         */
        virtual void serialize(std::ofstream &out) const = 0;
        /**
         * @brief Méthode pour charger l'objet multimédia depuis un flux d'entrée
         * 
         * Méthode virtuelle pure pour charger l'objet multimédia depuis un flux d'entrée, qui doit être implémentée par les classes filles
         * 
         * @param in Flux d'entrée
         */
        virtual void load(std::ifstream &in) = 0;
};

#endif