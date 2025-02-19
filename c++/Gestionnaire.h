/**
 * @file Gestionnaire.h
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Déclaration de la classe Gestionnaire pour gérer les objets multimédias et les groupes
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <stdexcept>
#include <map>
#include "Base.h"
#include "Photo.hpp"
#include "Video.hpp"
#include "Film.h"
#include "Groupe.h"

/**
 * @brief Classe pour gérer les objets multimédias et les groupes
 * 
 */

class Gestionnaire{
    private:
        std::map<std::string, std::shared_ptr<Base>> objetsMultimedia;  // Map des objets multimédias
        std::map<std::string, std::shared_ptr<Groupe>> groupes;         // Map des groupes
        /**
         * @brief Méthode pour obtenir un objet multimédia
         * 
         * @param name Nom de l'objet multimédia
         * @return std::shared_ptr<Base> Un pointeur intelligent vers l'objet multimédia
         */
        std::shared_ptr<Base> getObjetMultimedia(const std::string name) const;
        /**
         * @brief Méthode pour obtenir un groupe
         * 
         * @param name Nom du groupe
         * @return std::shared_ptr<Groupe> Un pointeur intelligent vers le groupe
         */
        std::shared_ptr<Groupe> getGroupe(const std::string name) const;
    public:
        /**
         * @brief Crée une photo et l'ajoute à la liste des objets multimédias
         * 
         * @param name Nom de la photo
         * @param filename Nom du fichier contenant la photo
         * @return std::shared_ptr<Photo> Un pointeur intelligent vers la photo créée
         */
        std::shared_ptr<Photo> createPhoto(const std::string name, const std::string filename);
        /**
         * @brief Crée une photo et l'ajoute à la liste des objets multimédias
         * 
         * @param name Nom de la photo
         * @param filename Nom du fichier contenant la photo
         * @param latitude Latitude de la photo
         * @param longitude Longitude de la photo
         * @return std::shared_ptr<Photo> Un pointeur intelligent vers la photo créée
         */
        std::shared_ptr<Photo> createPhoto(const std::string name, const std::string filename, const double latitude, const double longitude);

        /**
         * @brief Crée une vidéo et l'ajoute à la liste des objets multimédias
         * 
         * @param name Nom de la vidéo
         * @param filename Nom du fichier contenant la vidéo
         * @return std::shared_ptr<Video> Un pointeur intelligent vers la vidéo créée
         */
        std::shared_ptr<Video> createVideo(const std::string name, const std::string filename);
        /**
         * @brief Crée une vidéo et l'ajoute à la liste des objets multimédias
         * 
         * @param name Nom de la vidéo
         * @param filename Nom du fichier contenant la vidéo
         * @param duration Durée de la vidéo
         * @return std::shared_ptr<Video> Un pointeur intelligent vers la vidéo créée
         */
        std::shared_ptr<Video> createVideo(const std::string name, const std::string filename, const int duration);

        /**
         * @brief Crée un film et l'ajoute à la liste des objets multimédias
         * 
         * @param name Nom du film
         * @param filename Nom du fichier contenant le film
         * @return std::shared_ptr<Film> Un pointeur intelligent vers le film créé
         */
        std::shared_ptr<Film> createFilm(const std::string name, const std::string filename);
        /**
         * @brief Crée un film et l'ajoute à la liste des objets multimédias
         * 
         * @param name Nom du film
         * @param filename Nom du fichier contenant le film
         * @param duration Durée du film
         * @return std::shared_ptr<Film> Un pointeur intelligent vers le film créé
         */
        std::shared_ptr<Film> createFilm(const std::string name, const std::string filename, const int duration);

        /**
         * @brief Crée un groupe et l'ajoute à la liste des groupes
         * 
         * @param name Nom du groupe
         * @return std::shared_ptr<Groupe> Un pointeur intelligent vers le groupe créé
         */
        std::shared_ptr<Groupe> createGroupe(const std::string name);

        /**
         * @brief Affiche les valeurs d'un objet multimédia
         * 
         * @param name Nom de l'objet multimédia
         * @param out Flux de sortie
         */
        void showObjetsMultimedia(const std::string name, std::ostream& out) const;

        /**
         * @brief Affiche les valeurs d'un groupe
         * 
         * @param name Nom du groupe
         * @param out Flux de sortie
         */
        void showGroupes(const std::string name, std::ostream& out) const;

        /**
         * @brief Joue un objet multimédia
         * 
         * @param name Nom de l'objet multimédia
         * @param out Flux de sortie
         */
        void playObjetMultimedia(const std::string name, std::ostream& out) const;

        /**
         * @brief Méthode pour écrire les données d'une base de données dans un fichier
         * 
         * Sérialisation : écriture des données d'une base de données dans un fichier
         * 
         * @param filename Nom du fichier de sauvegarde
         */
        void serialize(const std::string filename) const;
        
        /**
         * @brief Méthode pour lire les données d'une base de données depuis un fichier
         * 
         * Désérialisation : lecture des données d'une base de données depuis un fichier
         * 
         * @param filename Nom du fichier de lecture
         */

        void load(const std::string filename);

        /**
         * @brief Méthode pour afficher tous les objets multimédias
         * 
         * @param out Flux de sortie
         */
        void showAllObjetsMultimedia(std::ostream &out) const;

        /**
         * @brief Méthode pour afficher tous les groupes
         * 
         * @param out Flux de sortie
         */
        void showAllGroupes(std::ostream &out) const;

        /**
         * @brief Méthode pour supprimer un objet multimédia
         * 
         * @param name Nom de l'objet multimédia
         */
        void deleteObjetMultimedia(const std::string name);

        /**
         * @brief Méthode pour supprimer un groupe
         * 
         * @param name Nom du groupe
         */
        void deleteGroupe(const std::string name);
};

/**
 * @brief Classe pour gérer les exceptions de nom déjà utilisé, dérivé de l'exception invalid_argument
 * 
 */

class NomDejaUtiliseException : public std::invalid_argument{
    public:
        NomDejaUtiliseException(const std::string& name) : std::invalid_argument("Nom " + name + " déjà utilisé"){}
};

#endif