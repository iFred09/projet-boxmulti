#include "Gestionnaire.h"

std::shared_ptr<Photo> Gestionnaire::createPhoto(const std::string name, const std::string filename, const double latitude, const double longitude){
    std::shared_ptr<Photo> photo = std::make_shared<Photo>(name, filename, latitude, longitude);
    objetsMultimedia[name] = photo;
    return photo;
}

std::shared_ptr<Video> Gestionnaire::createVideo(const std::string name, const std::string filename, const int duration){
    std::shared_ptr<Video> video = std::make_shared<Video>(name, filename, duration);
    objetsMultimedia[name] = video;
    return video;
}

std::shared_ptr<Film> Gestionnaire::createFilm(const std::string name, const std::string filename, const int duration){
    std::shared_ptr<Film> film = std::make_shared<Film>(name, filename, duration);
    objetsMultimedia[name] = film;
    return film;
}

std::shared_ptr<Groupe> Gestionnaire::createGroupe(const std::string name){
    std::shared_ptr<Groupe> groupe = std::make_shared<Groupe>(name);
    groupes[name] = groupe;
    return groupe;
}

void Gestionnaire::showObjetsMultimedia(const std::string name) const{
    auto it = objetsMultimedia.find(name);
    if (it != objetsMultimedia.end()){
        it->second->printValues(std::cout);
    }
}

void Gestionnaire::showGroupes(const std::string name) const{
    auto it = groupes.find(name);
    if (it != groupes.end()){
        it->second->printValues(std::cout);
    }
}

void Gestionnaire::playObjetMultimedia(const std::string name) const{
    auto it = objetsMultimedia.find(name);
    if (it != objetsMultimedia.end()){
        it->second->play();
    }
}