#include "roman.h"

romanType::romanType(){
  DecimalNumber = 0;
}

romanType::romanType(unsigned int InputDecimalNumber){
  DecimalNumber = InputDecimalNumber;
}

romanType::romanType(std::string strRomanNumeral){
  SetValue(strRomanNumeral);
}

void romanType::SetValue(unsigned int InputDecimalNumber){
  DecimalNumber = InputDecimalNumber;
}

void romanType::SetValue(std::string strRomanNumeral){
    #define CurrentNumeral strRomanNumeral[i]
    #define FirstNumeral   strRomanNumeral[0]
    #define NumeralLength  strRomanNumeral.length()

    DecimalNumber = 0;
    if( strRomanNumeral != "" ){
      char PreviousNumeral = FirstNumeral;
      DecimalNumber = RomanValue(FirstNumeral);
      for( unsigned int i = 1; i < NumeralLength; i++ ){
          DecimalNumber += RomanValue(CurrentNumeral);
          if( RomanValue(PreviousNumeral) < RomanValue(CurrentNumeral) )
              DecimalNumber -= RomanValue(PreviousNumeral) * 2;
          PreviousNumeral = CurrentNumeral;
      }
    }
}

unsigned int romanType::GetInt(){
  return DecimalNumber;
}

std::string romanType::GetString(){
    std::string strRomanNumeral;
    int TempDecimalNumber = (signed int) DecimalNumber;
    int NumeralListSize = 13;
    std::string RomanNumeralLetters[] = { "M", "CM",  "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int         RomanNumeralNumbers[] = {1000,  900, 500,   400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
    do{
        for( int i = 0; i < NumeralListSize; i++ ){
            if( TempDecimalNumber - RomanNumeralNumbers[i] >= 0 ){
                strRomanNumeral += RomanNumeralLetters[i];
                TempDecimalNumber -= RomanNumeralNumbers[i];
                break;
            }
        }
    }while( TempDecimalNumber > 0 );
    return strRomanNumeral;
}

unsigned int romanType::RomanValue(char RomanNumeralLetter){
    switch(RomanNumeralLetter){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
