// A -> I = E
// E -> P O P | P
// O -> + | - | * | / | **
// P -> I | L | UI | UL | (E)
// U -> + | - | !
// I -> C | CI
// C -> a | b | ... | y | z
// L -> D | DL
// D -> 0 | 1 | ... | 8 | 9

//Todo! create a text file called input.txt and store these grammar on it.
//Do we have to be concerned about white space  
//We may have to remove white spaces from buffers

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string buff;

bool A(void);
bool E(void);
bool O(void);
bool P(void);
bool U(void);
bool I(void);
bool C(void);
bool L(void);
bool D(void);

int main(int argc, char *argsv[]){
    
    
    //read the input file 
    ifstream fin("input.txt");

    //check if the file is open and ready to read if not cout cannot be read
    if(fin.is_open()){
        while (fin.good()){ //checks if at the end of the file. once it hits/had read to the end of the file, it will break the while loop
            //get a line and parse it from there
            getline(fin, buff);
            string t = buff;
            //begin to parse
            if (A()){
                cout<< t << "is in the language"<<endl;
            }else{
                cout<< t << "is not in the language"<<endl;
            }
        }
    }
    else{
        cout << "Input file cannot be read."<<endl;
    }

     return 0;

}

bool A(void){
    // A -> I = E

    if(I()) {
        if(buff[0] == '='){
            if(E()){
                return true;
            }
        }
    }
    return false;
}

bool I(void){
   // I -> C | CI
   if(C()){
        buff = buff.substr(1);
        return true;
    }
       else if (C()){
            if(I()){
                buff =  buff.substr(1); //move to the next item 
                return true;
            }
            
        }
   
   return false;
}

bool C(void){
    if ('a' <= buff[0] || buff[0] <= 'z'){
        buff = buff.substr(1);
        return true;
    }
    return false;
}

bool E(void){
   // E -> P O P | P
   if (P()){ // test for P        ===
        if (O()){ // test for O .  ==  Following the specified rules.
            if (P()){ // test for P ==
                buff = buff.substr(1);
                return true;
            }
        }
   }
   return false;
}

bool P(void){
    // P -> I | L | UI | UL | (E)
    if (I() || L()){
        buff = buff.substr(1);
        return true;
    }
    else if(U()){
            if(I()){
                buff = buff.substr(1);
                return true;
            }
            
        }
    else if(U()){
            if(L()){
                buff = buff.substr(1);
            }
            return true;
    }
    else if(buff[0] == '('){
            buff = buff.substr(1);
            if (E()){
                if(buff[0] == ')'){
                    buff = buff.substr(1);
                    return true;
                }
            }
        }
        return false;
 }
    

bool L(void){
    // L => D | DL
    if(D()) {
        return true;
    }
    else if(D()){
        if(L()){
            buff = buff.substr(1);
            return true;
        }
    }

    return false;
}
bool O(void){
    // O -> + | - | * | / | **
   // if(buff[0] == '+' || buff[0] == '-' || buff[0] == '*' || buff[0] == '/' || buff[0] == '**'){
     //   buff = buff.substr(1);
       return true;
    //}
    
    //return false;
}

bool U(void){
    // U -> + | - | !
    if(buff[0] == '+' || buff[0] == '-' || buff[0] == '!'){
        buff = buff.substr(1);
        return true;
    }
    return false;
}

bool D(void){
    // D -> 0 | 1 | ... | 8 | 9
    if(0 <= buff[0] && buff[0] <= 9){
        buff = buff.substr(1);
        return true;
    }
    return false;
}

//notes : static binding is a fixed variable declaration 
//      : dynamic binding happens when the program runse2 
