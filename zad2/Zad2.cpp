#include "ArabRzym.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char const *argv[]){
    for (int i=1; i<argc; i++) {
        std::string number;
        int j = 0; char c;
        while ((c = std::toupper(argv[i][j])) != '\0') {
            number.push_back(c);
            j++;
        }

        
        try {
            std::string ans = ArabRzym::arab2rzym(stoi(number));
            std::cout << number << " = " << ans << std::endl;
        }
        catch (const std::invalid_argument& e) {
            try {
                int ans = ArabRzym::rzym2arab(number);
                std::cout << number << " = " << ans << std::endl;
            }
            catch (const ArabRzym::ArabRzymException& e) { std::cout << "Niepoprawny argument: " << number << " " << e.what() << std::endl; }   
        }
        catch (const ArabRzym::ArabRzymException& e) { std::cout << "Niepoprawny argument: " << number << " " << e.what() << std::endl; }

    }

    return 0;
}
