/**
 * @file Gestionnaire.cpp
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Implémentation de la classe pour gérer les objets multimédias et les groupes
 * @version 1.0
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Gestionnaire.h"


/**
 * @brief Crée une photo et l'ajoute à la liste des objets multimédias
 * 
 * @param name Nom de la photo
 * @param filename Nom du fichier contenant la photo
 * @param latitude Latitude de la photo
 * @param longitude Longitude de la photo
 * @return std::shared_ptr<Photo> Un pointeur intelligent vers la photo créée
 */

std::shared_ptr<Photo> Gestionnaire::createPhoto(const std::string name, const std::string filename, const double latitude, const double longitude){
    std::shared_ptr<Photo> photo = std::make_shared<Photo>(name, filename, latitude, longitude);
    objetsMultimedia[name] = photo;
    return photo;
}

/**
 * @brief Crée une vidéo et l'ajoute à la liste des objets multimédias
 * 
 * @param name Nom de la vidéo
 * @param filename Nom du fichier contenant la vidéo
 * @param duration Durée de la vidéo
 * @return std::shared_ptr<Video> Un pointeur intelligent vers la vidéo créée
 */

std::shared_ptr<Video> Gestionnaire::createVideo(const std::string name, const std::string filename, const int duration){
    std::shared_ptr<Video> video = std::make_shared<Video>(name, filename, duration);
    objetsMultimedia[name] = video;
    return video;
}

/**
 * @brief Crée un film et l'ajoute à la liste des objets multimédias
 * 
 * @param name Nom du film
 * @param filename Nom du fichier contenant le film
 * @param duration Durée du film
 * @return std::shared_ptr<Film> Un pointeur intelligent vers le film créé
 */

std::shared_ptr<Film> Gestionnaire::createFilm(const std::string name, const std::string filename, const int duration){
    std::shared_ptr<Film> film = std::make_shared<Film>(name, filename, duration);
    objetsMultimedia[name] = film;
    return film;
}

/**
 * @brief Crée un groupe et l'ajoute à la liste des groupes
 * 
 * @param name Nom du groupe
 * @return std::shared_ptr<Groupe> Un pointeur intelligent vers le groupe créé
 */

std::shared_ptr<Groupe> Gestionnaire::createGroupe(const std::string name){
    std::shared_ptr<Groupe> groupe = std::make_shared<Groupe>(name);
    groupes[name] = groupe;
    return groupe;
}

/**
 * @brief Méthode pour rechercher et obtenir un objet multimédia
 * 
 * @param name Nom de l'objet multimédia
 * @return std::shared_ptr<Base> Un pointeur intelligent vers l'objet multimédia s'il existe, sinon nullptr
 */

std::shared_ptr<Base> Gestionnaire::getObjetMultimedia(const std::string name) const{
    auto it = objetsMultimedia.find(name);
    if (it != objetsMultimedia.end()){
        return it->second;
    }
    return nullptr;
}

/**
 * @brief Méthode pour rechercher et obtenir un groupe
 * 
 * @param name Nom du groupe
 * @return std::shared_ptr<Groupe> Un pointeur intelligent vers le groupe s'il existe, sinon nullptr
 */

std::shared_ptr<Groupe> Gestionnaire::getGroupe(const std::string name) const{
    auto it = groupes.find(name);
    if (it != groupes.end()){
        return it->second;
    }
    return nullptr;
}

/**
 * @brief Méthode pour afficher les valeurs d'un objet multimédia
 * 
 * @param name Nom de l'objet multimédia
 * @param out Flux de sortie
 */

void Gestionnaire::showObjetsMultimedia(const std::string name, std::ostream &out) const{
    auto multimedia = getObjetMultimedia(name);
    if (multimedia){
        out << "Objet multimédia " << name << " trouvé : " << std::endl;
        multimedia->printValues(out);
    }
    else{
        out << "Objet multimédia " << name << " non trouvé" << std::endl;
    }
}

/**
 * @brief Méthode pour afficher les valeurs d'un groupe
 * 
 * @param name Nom du groupe
 * @param out Flux de sortie
 */

void Gestionnaire::showGroupes(const std::string name, std::ostream &out) const{
    auto groupe = getGroupe(name);
    if (groupe){
        out << "Groupe " << name << " trouvé : " << std::endl;
        groupe->printValues(out);
    }
    else{
        out << "Groupe " << name << " non trouvé" << std::endl;
    }
}

/**
 * @brief Méthode pour jouer un objet multimédia
 * 
 * @param name Nom de l'objet multimédia
 * @param out Flux de sortie
 */

void Gestionnaire::playObjetMultimedia(const std::string name, std::ostream &out) const{
    auto multimedia = getObjetMultimedia(name);
    if (multimedia){
        out << "Objet multimédia " << name << " trouvé, lecture..." << std::endl;
        multimedia->play();
    }
    else{
        out << "Objet multimédia " << name << " non trouvé" << std::endl;
    }
}

/**
 * @brief Méthode pour écrire les données d'une base de données dans un fichier
 * 
 * Sérialisation : écriture des données d'une base de données dans un fichier
 * 
 * @param filename Nom du fichier de sauvegarde
 */

void Gestionnaire::serialize(const std::string filename) const{
    std::ofstream file(filename);
    if(file.is_open()){
        for(const auto& obj : objetsMultimedia){
            file << "ObjetMultimedia" << std::endl;
            file << obj.first << std::endl;
            obj.second->serialize(filename);
        }
        for(const auto& groupe : groupes){
            file << "Groupe" << std::endl;
            file << groupe.first << std::endl;
            groupe.second->serialize(filename);
        }
        file.close();
    }
}

/**
 * @brief Méthode pour lire les données d'une base de données depuis un fichier
 * 
 * Désérialisation : lecture des données d'une base de données depuis un fichier
 * 
 * @param filename Nom du fichier de lecture
 */

void Gestionnaire::load(const std::string filename){
    std::ifstream file(filename);
    if(file.is_open()){
        std::string type;
        while(std::getline(file, type)){
            if (type == "ObjetMultimedia"){
                std::string name;
                std::getline(file, name);
                std::string objType;
                std::getline(file, objType);
                if (objType == "Photo"){
                    std::string filename;
                    std::getline(file, filename);
                    double latitude;
                    file >> latitude;
                    double longitude;
                    file >> longitude;
                    createPhoto(name, filename, latitude, longitude);
                }
                else if (objType == "Video"){
                    std::string filename;
                    std::getline(file, filename);
                    int duration;
                    file >> duration;
                    createVideo(name, filename, duration);
                }
                else if (objType == "Film"){
                    std::string filename;
                    std::getline(file, filename);
                    int duration;
                    file >> duration;
                    createFilm(name, filename, duration);
                }
            }
            else if (type == "Groupe"){
                std::string name;
                std::getline(file, name);
                createGroupe(name);
            }
        }
        file.close();
    }
}