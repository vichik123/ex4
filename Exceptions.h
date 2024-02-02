#include <exception>
#include <string>   
#include <stdexcept>

class DeckFileNotFound : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Deck File Error: File not found";
        }
	};

class DeckFileFormatError : public std::exception {
public:
    DeckFileFormatError(int lineNumber) : lineNumber(lineNumber) {}

    const char* what() const noexcept override {
        return ("Deck File Error: File format error in line " + std::to_string(lineNumber)).c_str();
    }

private:
    int lineNumber;
};



class InvalidArgument : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Deck File Error: Deck size is invalid";
		}
	};
