/**
 * @file Film.h
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Déclaration de la classe Film, héritant de la classe Video
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef FILM_H
#define FILM_H

#include "Video.hpp"

/**
 * @brief Classe pour les objets multimédias de type film, héritant de la classe Video
 * 
 */

class Film : public Video{
    friend class Gestionnaire;
    private:
        int* chapitres{};   // Tableau des chapitres du film
        int nbChapitres{};  // Nombre de chapitres du film
        /**
         * @brief Constructeur par défaut de la classe Film
         * 
         */
        Film();

        /**
         * @brief Constructeur de la classe Film avec paramètres
         * 
         * Constructeur avec arguments qui initialise un film avec un nom et un nom de fichier
         * 
         * @param name Nom du film
         * @param filename Nom du fichier contenant le film
         */
        Film(const std::string name, const std::string filename);

        /**
         * @brief Constructeur de la classe Film avec paramètres
         * 
         * Constructeur avec arguments qui initialise un film avec un nom, un nom de fichier et une durée
         * 
         * @param name Nom du film
         * @param filename Nom du fichier contenant le film
         * @param duration Durée du film
         */
        Film(const std::string name, const std::string filename, int duration);

        /**
         * @brief Constructeur de la classe Film avec paramètres
         * 
         * Constructeur avec arguments qui initialise un film avec un nom, un nom de fichier, une durée, des chapitres et le nombre de chapitres
         * 
         * @param name Nom du film
         * @param filename Nom du fichier contenant le film
         * @param duration Durée du film
         * @param chapitres Tableau des chapitres du film
         * @param nbChapitres Nombre de chapitres du film
         */
        Film(const std::string name, const std::string filename, int duration, const int* chapitres, int nbChapitres);
    public:
        /**
         * @brief Constructeur de copie de la classe Film
         * 
         * Constructeur de copie qui initialise un film avec les mêmes valeurs qu'un autre film
         * 
         * @param film Film à copier
         */
        Film(const Film& film);

        /**
         * @brief Destructeur pour la classe Film
         * 
         */
        ~Film();

        /**
         * @brief Méthode pour obtenir les chapitres du film
         * 
         * @return const int* Tableau des chapitres du film
         */
        const int* getChapitres() const;

        /**
         * @brief Méthode pour obtenir le nombre de chapitres du film
         * 
         * @return const int Nombre de chapitres du film
         */
        const int getNbChapitres() const;

        /**
         * @brief Méthode pour définir les chapitres du film
         * 
         * @param chapitres Tableau des chapitres du film
         * @param nbChapitres Nombre de chapitres du film
         */
        void setChapitres(const int* chapitres, int nbChapitres);

        /**
         * @brief Affiche les valeurs du film
         * 
         * @param out Flux de sortie
         */
        void printValues(std::ostream& out) const override;

        /**
         * @brief Méthode pour écrire les données d'un film dans un fichier
         * 
         * Sérialisation : écriture des données d'un film dans un fichier
         * 
         * @param filename Nom du fichier de sauvegarde
         */
        void serialize(std::ofstream& out) const override;

        /**
         * @brief Méthode pour lire les données d'un film depuis un fichier
         * 
         * Désérialisation : lecture des données d'un film depuis un fichier
         * 
         * @param filename Nom du fichier à charger
         */
        void load(std::ifstream& in) override;
};

class NombreChapitresException : public std::invalid_argument{
    public:
        NombreChapitresException() : std::invalid_argument("Erreur : Nombre de chapitres invalide"){}
};

class NullChapitresException : public std::invalid_argument{
    public:
        NullChapitresException() : std::invalid_argument("Erreur : Tableau de chapitres nul"){}
};

#endif