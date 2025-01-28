/**
 * @file Video.hpp
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Déclaration et implémentation de la classe Video, héritant de la classe Base
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "Base.h"

/**
 * @brief Classe pour les objets multimédias de type vidéo
 * 
 */

class Video : public Base{
    friend class Film;
    friend class Gestionnaire;
    private:
        int duration;    // Durée de la vidéo
        /**
         * @brief Constructeur par défaut de la classe Video
         * 
         * Constructeur sans argument qui initialise une vidéo avec un nom vide, un nom de fichier vide et une durée à 0
         * 
         */

        Video():Base(){
            this->duration = 0;
        }

        Video(const std::string name, const std::string filename)
            :Base(name, filename), duration(0){
        }

        /**
         * @brief Constructeur de la classe Video avec paramètres
         * 
         * Constructeur avec arguments qui initialise une vidéo avec un nom, un nom de fichier et une durée
         * 
         * @param name Nom de la vidéo
         * @param filename Nom du fichier contenant la vidéo
         * @param duration Durée de la vidéo
         */

        Video(const std::string name, const std::string filename, int duration)
            :Base(name, filename), duration(duration){
        }
    public:
        /**
         * @brief Destructeur pour la classe Video
         * 
         */

        ~Video(){
            std::cout << "Destruction de la vidéo " << this->getName() << std::endl;
        }

        /**
         * @brief Méthode pour obtenir la durée de la vidéo
         * 
         * @return const int Durée de la vidéo
         */

        const int getDuration() const{
            return duration;
        }

        /**
         * @brief Méthode pour définir la durée de la vidéo
         * 
         * @param duration Nouvelle durée de la vidéo
         */

        void setDuration(int duration){
            this->duration = duration;
        }

        /**
         * @brief Affiche les valeurs de la vidéo
         * 
         * @param out Flux de sortie
         */
        
        void printValues(std::ostream &out) const override{
            Base::printValues(out);
            out << "Durée : " << duration << std::endl;
        }

        /**
         * @brief Méthode pour jouer la vidéo
         * 
         * Lance la lecture de la vidéo avec le lecteur mpv
         */

        void play() const override{
            std::string arg = "mpv " + this->getFileName() + " &";
            const char* argconv = arg.data();
            system(argconv);
        }

        /**
         * @brief Méthode pour écrire les données d'une vidéo dans un fichier
         * 
         * Sérialisation : écriture des données de la vidéo dans un fichier
         * 
         * @param filename Nom du fichier de sauvegarde
         */

        void serialize(std::ofstream &out) const override{
            out << "Vidéo" << std::endl;
            out << this->getName() << std::endl;
            out << this->getFileName() << std::endl;
            out << this->getDuration() << std::endl;
        }

        /**
         * @brief Méthode pour lire les données d'une vidéo depuis un fichier
         * 
         * Désérialisation : lecture des données d'une vidéo depuis un fichier
         * 
         * @param filename Nom du fichier à charger
         */

        void load(std::ifstream &in) override{
            std::string type;
            std::string name;
            std::string filename;
            int duration;
            getline(in, name);
            getline(in, filename);
            in >> duration;
            this->setName(name);
            this->setFileName(filename);
            this->setDuration(duration);
        }
};

#endif