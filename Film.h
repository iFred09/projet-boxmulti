#ifndef FILM_H
#define FILM_H

#include "Video.hpp"

class Film : public Video{
    private:
        int* chapitres;
        int nbChapitres;
    public:
        Film(const std::string name = "", const std::string filename = "", int duration = 0);
        Film(const Film&);
        ~Film();
        int* getChapitres() const;
        int getNbChapitres() const;
        void setChapitres(int*, int);
        void printValues(std::ostream&) const override;
};

#endif