#ifndef FILM_H
#define FILM_H

#include "Video.hpp"

class Film : public Video{
    private:
        int* chapitres{};
        int nbChapitres{};
    public:
        Film();
        Film(const std::string name, const std::string filename, int duration);
        Film(const Film& film);
        ~Film();
        const int* getChapitres() const;
        int getNbChapitres() const;
        void setChapitres(const int* chapitres, int nbChapitres);
        void printValues(std::ostream&) const override;
};

#endif