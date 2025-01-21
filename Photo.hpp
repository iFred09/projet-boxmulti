#ifndef photo_hpp
#define photo_hpp

#include "Base.h"

class Photo : public Base {
    private:
        double latitude;
        double longitude;
    public:
        Photo():Base(){
            this->latitude = 0;
            this->longitude = 0;
        }
        Photo(const std::string name, const std::string filename, const double latitude, const double longitude)
            :Base(name, filename), latitude(latitude), longitude(longitude){

            }

        ~Photo(){
            std::cout << "Destruction de la photo " << this->getName() << std::endl;
        }
        
        double getLatitude() const{
            return latitude;
        }

        double getLongitude() const{
            return longitude;
        }

        void setLatitude(double latitude){
            this->latitude = latitude;
        }

        void setLongitude(double longitude){
            this->longitude = longitude;
        }

        void printValues(std::ostream &out) const override{
            Base::printValues(out);
            out << "Latitude : " << latitude << '\n';
            out << "Longitude : " << longitude << '\n';
        }

        void play() const override{
            std::string arg = "imagej " + this->getFileName() + " &";
            const char* argconv = arg.data();
            system(argconv);
        }

};

#endif