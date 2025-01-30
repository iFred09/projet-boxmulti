//
// main.cpp
// Created on 21/10/2018
//

#include "Photo.hpp"
#include "Video.hpp"
#include "Film.h"
#include "Groupe.h"
#include "Gestionnaire.h"
#include "tcpserver.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

#ifdef AVANT_ETAPE5

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

    Photo *photo = new Photo("photo", "photo.jpg", 3.55222, 4.77777);
    photo->printValues(std::cout);
    photo->play();
    delete photo;

    Video *video = new Video("video", "video.mov", 5555);
    video->printValues(std::cout);
    video->play();
    delete video;

}

#endif

#ifdef ETAPE_5_10

int main(int argc, const char* argv[])
{
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

    std::shared_ptr<Photo> photo1 = std::make_shared<Photo>("Vacances", "vacances.jpg", 43.5, 7.0);
    std::shared_ptr<Photo> photo2 = std::make_shared<Photo>("Vacances2", "vacances2.jpg", 45.3, 2.0);
    std::shared_ptr<Video> video1 = std::make_shared<Video>("Film", "film.mp4", 120);

    Groupe groupeVacances("Vacances");
    groupeVacances.push_back(photo1);
    groupeVacances.push_back(photo2);

    Groupe groupeFilms("Films");
    groupeFilms.push_back(video1);
    groupeFilms.push_back(photo1);

    std::cout << "Affichage du groupe Vacances :" << std::endl;
    groupeVacances.printValues(std::cout);

    std::cout << "\nAffichage du groupe Films :" << std::endl;
    groupeFilms.printValues(std::cout);

    return 0;
}
#endif

// #define ETAPE_10
#ifdef ETAPE_10

int main(int argc, const char* argv[]){
    std::cout << "Début du test gestionnaire" << std::endl;

    Gestionnaire gestionnaire;
    std::shared_ptr<Photo> photo = gestionnaire.createPhoto("Vacances", "vacances.jpg", 43.5, 7.0);
    std::shared_ptr<Video> video = gestionnaire.createVideo("Video", "film.mp4", 120);
    std::shared_ptr<Groupe> groupe = gestionnaire.createGroupe("Vacances"); 

    groupe->push_back(photo);
    groupe->push_back(video);

    std::shared_ptr<Photo> photo2 = new Photo();

    gestionnaire.showObjetsMultimedia("Vacances", std::cout);
    gestionnaire.showGroupes("Vacances", std::cout);

    return 0;
}

#endif

// #define ETAPE_11
#ifdef ETAPE_11

const int PORT = 3331;

int main(int argc, const char* argv[]){
    Gestionnaire db;
    std::shared_ptr<Photo> photo = db.createPhoto("Paris", "paris.jpg", 43.5, 7.0);
    std::shared_ptr<Photo> photo2 = db.createPhoto("babar", "babar.jpg", 99.9, 2.0);
    std::shared_ptr<Video> video = db.createVideo("Film", "film.mp4", 120);
    std::shared_ptr<Groupe> groupe = db.createGroupe("Vacances");

    groupe->push_back(photo);
    groupe->push_back(video);
    
    // creation TCPServer

    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // processing request

    std::stringstream ss(request);
    std::string command;
    std::string argument;

    ss >> command >> argument;

    std::cout << "searching for " << argument << std::endl;
    std::stringstream output;
    if (command == "show"){
        output << "Recherche de " << argument << " : " << ";";
        db.showGroupes(argument, output);
        db.showObjetsMultimedia(argument, output);
        std::string outputStr = output.str();
        std::replace(outputStr.begin(), outputStr.end(), '\n', ';');
        response = outputStr;
    } else if (command == "play"){
        output << "Recherche de " << argument << " : " << ";";
        db.playObjetMultimedia(argument, output);
        response = output.str();
    } else {
        response = "unknown command";
    }

    // return false would close the connecytion with the client
    return true;
    });
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }
}

#endif

#define ETAPE_12
#ifdef ETAPE_12

int main(int argc, const char* argv[]){
    const int PORT = 3331;

    Gestionnaire db;
    std::shared_ptr<Photo> photo = db.createPhoto("Paris", "paris.jpg", 43.5, 7.0);
    std::shared_ptr<Photo> photo2 = db.createPhoto("babar", "babar.jpg", 99.9, 2.0);
    std::shared_ptr<Video> video = db.createVideo("unfilm", "film.mp4", 120);
    std::shared_ptr<Video> video2 = db.createVideo("unfilm2", "film2.mp4", 120);
    std::shared_ptr<Groupe> groupe = db.createGroupe("Vacances");

    groupe->push_back(photo);
    groupe->push_back(video);

    db.serialize("db.txt");

    Gestionnaire db2;
    db2.load("db.txt");
    
    db.showObjetsMultimedia("unfilm", std::cout);
    db2.showObjetsMultimedia("unfilm", std::cout);
    db2.showObjetsMultimedia("Paris", std::cout);
    db2.showObjetsMultimedia("unfilm2", std::cout);

    // creation TCPServer

    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // processing request

    std::stringstream ss(request);
    std::string command;
    std::string argument;

    ss >> command >> argument;

    std::stringstream output;
    if (command == "afficher"){
        output << "Recherche de " << argument << " : " << ";";
        if (argument == "groupes"){
            db2.showAllGroupes(output);
        } 
        else if (argument == "multimédias"){
            db2.showAllObjetsMultimedia(output);
        }
        else{
            db.showGroupes(argument, output);
            db.showObjetsMultimedia(argument, output);
        }
        std::string outputStr = output.str();
        std::replace(outputStr.begin(), outputStr.end(), '\n', ';');
        response = outputStr;
    } else if (command == "jouer"){
        output << "Recherche de " << argument << " : " << ";";
        db.playObjetMultimedia(argument, output);
        response = output.str();
    } else {
        response = "Erreur : Commande inconnue";
    }

    // return false would close the connecytion with the client
    return true;
    });
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}

#endif
