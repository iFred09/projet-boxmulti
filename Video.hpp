#ifndef video_hpp
#define video_hpp

#include "Base.h"

class Video : public Base{
    private:
        int duration;
    public:
        Video():Base(){
            this->duration = 0;
        }
        Video(const std::string name, const std::string filename, int duration)
            :Base(name, filename), duration(duration){
        }

        ~Video(){
            std::cout << "Destruction de la vidéo " << this->getName() << std::endl;
        }

        int getDuration() const{
            return duration;
        }

        void setDuration(int duration){
            this->duration = duration;
        }
        
        void printValues(std::ostream &out) const override{
            Base::printValues(out);
            out << "Durée : " << duration << '\n';
        }

        void play() const override{
            std::string arg = "mpv " + this->getFileName() + " &";
            const char* argconv = arg.data();
            system(argconv);
        }
};

#endif