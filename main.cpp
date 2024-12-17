//
// main.cpp
// Created on 21/10/2018
//

#include "Photo.hpp"
#include "Video.hpp"

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

    Photo *photo = new Photo("photo", "photo.jpg", 3.55222, 4.77777);
    photo->printValues(std::cout);
    photo->play();
    delete photo;

    Video *video = new Video("video", "video.mov", 5555);
    video->printValues(std::cout);
    video->play();
    delete video;

    return 0;
}
