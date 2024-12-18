//
// main.cpp
// Created on 21/10/2018
//

#include "Photo.hpp"
#include "Video.hpp"
#include "Film.h"
#include <random>

using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    Base *hello = new Base("hello", "hello.txt");
    hello->printValues(std::cout);
    std::cout << "Name: " << hello->getName() << std::endl;
    hello->setName("coucou");
    std::cout << "New Name: " << hello->getName() << std::endl;
    delete hello;

    Base *boomboom = new Base("explosion", "boumboum.txt");
    boomboom->printValues(std::cout);
    boomboom->setName("boomboom");
    boomboom->setFileName("explosion.txt");
    boomboom->printValues(std::cout);
    delete boomboom;

    // Photo *photo = new Photo("photo", "photo.jpg", 3.55222, 4.77777);
    // photo->printValues(std::cout);
    // photo->play();
    // delete photo;

    // Video *video = new Video("video", "video.mov", 5555);
    // video->printValues(std::cout);
    // video->play();
    // delete video;

    Base *tabMedias[3];
    tabMedias[0] = new Video("video", "video.mov", 5555);
    tabMedias[1] = new Photo("photo", "photo.jpg", 3.55222, 4.77777);
    tabMedias[2] = new Video("video", "video.mov", 5555);

    for(int i=0 ; i<3 ; i++){
        tabMedias[i]->printValues(std::cout);
    }

    for(int i=0 ; i<3 ; i++){
        delete tabMedias[i];
    }

    Film *film = new Film("film1", "film1.mp4", 5555);
    int chapitres[15];

    std::mt19937 gen(std::time(0)); // Mersenne Twister 19937 générateur
    std::uniform_int_distribution<> dis(1, 100); // Nombres entiers entre 1 et 100
    // génère 15 nombres aléatoires entre 1 et 100
    for(int i=0 ; i<15 ; i++){
        chapitres[i] = dis(gen);
    }
    film->setChapitres(chapitres, 15);
    cout << "Film " << film->getName() << " : contient " << film->getNbChapitres() << " chapitres" << std::endl;
    film->printValues(cout);

    delete film;

    return 0;
}
