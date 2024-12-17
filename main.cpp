//
// main.cpp
// Created on 21/10/2018
//

#include "Photo.hpp"
#include "Video.hpp"
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

    return 0;
}
