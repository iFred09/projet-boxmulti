#ifndef base_h
#define base_h

#include <iostream>
#include <string>

class Base{
    private:
        std::string name{}, filename{};
    public:
        Base();
        Base(std::string name, std::string filename);
        virtual ~Base();
        void setName(std::string);
        void setFileName(std::string);
        std::string getName() const;
        std::string getFileName() const;
        virtual void printValues(std::ostream &out) const;
        virtual void play() const = 0;
};

#endif