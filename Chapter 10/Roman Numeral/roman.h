#include <string>

class romanType{
private:
    int unsigned DecimalNumber;
    unsigned int RomanValue(char);
public:
    //constructors
    romanType();
    romanType(unsigned int);
    romanType(std::string);
    //getters
    unsigned int GetInt();
    std::string GetString();
    //setters
    void SetValue(std::string);
    void SetValue(unsigned int);
};
