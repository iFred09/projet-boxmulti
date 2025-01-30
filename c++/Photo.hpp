/**
 * @file Photo.hpp
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Déclaration et implémentation de la classe Photo, héritant de la classe Base
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef PHOTO_HPP
#define PHOTO_HPP 

#include "Base.h"

/**
 * @brief Classe pour les objets multimédias de type photo
 * 
 */

class Photo : public Base {
    friend class Gestionnaire;
    private:
        double latitude;    // Latitude de la photo
        double longitude;
        /**
         * @brief Constructeur par défaut de la classe Photo
         * 
         * Constructeur sans argument qui initialise une photo avec un nom vide, un nom de fichier vide, une latitude et une longitude à 0
         * 
         */

        Photo():Base(){
            this->latitude = 0;
            this->longitude = 0;
        }

        Photo(const std::string name, const std::string filename)
            :Base(name, filename), latitude(0), longitude(0){

            }

        /**
         * @brief Constructeur de la classe Photo avec paramètres
         * 
         * Constructeur avec arguments qui initialise une photo avec un nom, un nom de fichier, une latitude et une longitude
         * 
         * @param name Nom de la photo
         * @param filename Nom du fichier contenant la photo
         * @param latitude Latitude de la photo
         * @param longitude Longitude de la photo
         */

        Photo(const std::string name, const std::string filename, const double latitude, const double longitude)
            :Base(name, filename), latitude(latitude), longitude(longitude){

            }
    public:
        /**
         * @brief Destructeur pour la classe Photo
         * 
         */

        ~Photo(){
            std::cout << "Destruction de la photo " << this->getName() << std::endl;
        }

        /**
         * @brief Méthode pour obtenir la latitude de la photo
         * 
         * @return const double Latitude de la photo
         */
        
        const double getLatitude() const{
            return latitude;
        }

        /**
         * @brief Méthode pour obtenir la longitude de la photo
         * 
         * @return const double Longitude de la photo
         */

        const double getLongitude() const{
            return longitude;
        }

        /**
         * @brief Méthode pour définir la latitude de la photo
         * 
         * @param latitude Nouvelle latitude de la photo
         */

        void setLatitude(double latitude){
            this->latitude = latitude;
        }

        /**
         * @brief Méthode pour définir la longitude de la photo
         * 
         * @param longitude Nouvelle longitude de la photo
         */

        void setLongitude(double longitude){
            this->longitude = longitude;
        }

        /**
         * @brief Affiche les valeurs de la photo
         * 
         * @param out Flux de sortie
         */

        void printValues(std::ostream &out) const override{
            Base::printValues(out);
            out << "Latitude : " << latitude << std::endl;
            out << "Longitude : " << longitude << std::endl;
        }

        /**
         * @brief Méthode pour jouer la photo
         * 
         * Ouvre l'image avec le logiciel imagej
         * 
         */

        void play() const override{
            std::string arg = "imagej " + this->getFileName() + " &";
            const char* argconv = arg.data();
            system(argconv);
        }

        /**
         * @brief Méthode pour écrire les données d'une photo dans un fichier
         * 
         * Sérialisation : écriture des données de la photo dans un fichier
         * 
         * @param filename Nom du fichier de sauvegarde
         */

        void serialize(std::ofstream &out) const override{
            out << "Photo" << std::endl;
            out << this->getName() << std::endl;
            out << this->getFileName() << std::endl;
            out << this->latitude << std::endl;
            out << this->longitude << std::endl;
        }

        /**
         * @brief Méthode pour lire les données d'une photo depuis un fichier
         * 
         * Désérialisation : lecture des données d'une photo depuis un fichier
         * 
         * @param filename Nom du fichier à charger
         */

        void load(std::ifstream &in) override{
            std::string name;
            std::string filename;
            double latitude;
            double longitude;
            in >> name;
            in >> filename;
            in >> latitude;
            in >> longitude;
            this->setName(name);
            this->setFileName(filename);
            this->setLatitude(latitude);
            this->setLongitude(longitude);
        }
};

#endif