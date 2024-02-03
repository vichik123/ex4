#ifndef EXCEPTION_H
#define EXCEPTION_H

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
        static const std::string retValue = ("Deck File Error: File format error in line " + std::to_string(lineNumber));
        return retValue.c_str();
    }

private:
    int lineNumber;
};



class DeckFileInvalidSize : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Deck File Error: Deck size is invalid";
		}
	};

#endif //EXCEPTION_H