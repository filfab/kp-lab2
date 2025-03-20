#pragma once
#include <string>
#include <exception>

class ArabRzym {
    private:
        inline static std::string liczby_r[13] =
        { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

        inline static int liczby_a[13] =
        { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };


    public:
        static int rzym2arab(std::string rzym) noexcept(false);
        static std::string arab2rzym(int arab) noexcept(false);


    class ArabRzymException : public std::exception {
        private:
            std::string msg;


        public:
            ArabRzymException(const char* message) : msg(message) {}

            const char* what() const throw() {
                return msg.c_str();
            }
    };
};

