#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <map>
#include "Base.h"
#include "Photo.hpp"
#include "Video.hpp"
#include "Film.h"
#include "Groupe.h"

class Gestionnaire{
    private:
        std::map<std::string, std::shared_ptr<Base>> objetsMultimedia;
        std::map<std::string, std::shared_ptr<Groupe>> groupes;
    public:
        std::shared_ptr<Photo> createPhoto(const std::string name, const std::string filename, const double latitude, const double longitude);
        std::shared_ptr<Video> createVideo(const std::string name, const std::string filename, const int duration);
        std::shared_ptr<Film> createFilm(const std::string name, const std::string filename, const int duration);
        std::shared_ptr<Groupe> createGroupe(const std::string name);

        void showObjetsMultimedia(const std::string name, std::ostream& out) const;
        void showGroupes(const std::string name, std::ostream& out) const;

        void playObjetMultimedia(const std::string name, std::ostream& out) const;
};

#endif