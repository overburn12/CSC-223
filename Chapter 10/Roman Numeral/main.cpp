#include <iostream>
#include <string>
#include "roman.cpp"

int main(){
    int romanNumeralNumber;
    std::string romanNumeralString;

    romanType romanNumeral1;

    std::cout << "Enter a Roman Numeral or a Decimal Number: ";
    std::cin >> romanNumeralString;

    if('0' <= romanNumeralString[0] && romanNumeralString[0] <= '9'){
        romanNumeralNumber = 0;
        for(int i = 0; i < romanNumeralString.length();  i++){
            romanNumeralNumber *= 10;
            romanNumeralNumber += (romanNumeralString[i]-'0');
        }
        if(romanNumeralNumber >= 4000){
            std::cout << "Too big for this Roman Numeral converter. Keep it under 4000" << std::endl;
            return 0;
        }
        romanNumeral1.SetValue(romanNumeralNumber);
    }else{
        romanNumeral1.SetValue(romanNumeralString);
    }
    
    std::cout << romanNumeral1.GetInt() << " = " << romanNumeral1.GetString() << std::endl;

    return 0;
}
