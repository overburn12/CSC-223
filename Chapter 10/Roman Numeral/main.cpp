#include <iostream>
#include <string>
#include "romanImp.cpp"

int main(){
    int anum;
    std::string astring;

    romanType rn1;

    std::cout << "Enter a Roman Numeral or a Decimal Number: ";
    std::cin >> astring;

    if('0' <= astring[0] && astring[0] <= '9'){
        anum = 0;
        for(int i=0; i<astring.length();  i++){
            anum *= 10;
            anum += (astring[i]-'0');
        }
        if(anum >= 4000){
            std::cout << "Too big for conventional Roman Numerals. Keep it under 4000" << std::endl;
            return 0;
        }
        rn1.SetValue(anum);
    }else{
        rn1.SetValue(astring);
    }
    
    std::cout << rn1.GetInt() << " = " << rn1.GetString() << std::endl;

    return 0;
}
