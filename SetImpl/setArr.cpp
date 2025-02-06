#include "setArr.h"

setArr::setArr(){
    size = 0;
    table = new bool[universeSize];
    for (int i = 0; i < universeSize; i++){
        table[i] = false;
    }
}

bool setArr::checkRangeCorrectness(int x){
    if(!(x<100 && x>-1)){
        return false;
    }
    return true;
}

void setArr::insert(int x){
    if(!isInSet(x)){
    if(checkRangeCorrectness(x)){
    table[x] = true;
    size++;
    }else{
        std::cout<<"Nieprawidłowy range"<<std::endl;
        }
    }
}
void setArr::withdraw(int x){
    if(checkRangeCorrectness(x)){
    table[x] = false;
    size--;
    }else{
        std::cout<<"Nieprawidłowy range"<<std::endl;
    }
}
bool setArr::isInSet(int i){
    if(checkRangeCorrectness(i)){
    return table[i]==true;
    }else{
        std::cout<<"Nieprawidłowy range"<<std::endl;
        return false;
    }
}
int setArr::getSize(){
    return size;
}
void setArr::clearSet(){
    for(int i = 0; i <universeSize; i++){
        table[i] = false;
    }
}
void setArr::printSet(){
    for(int i = 0; i <universeSize; i++){
        if(table[i]==true){
            std::cout<<i<<" ";
        }
    }
    std::cout<<std::endl;
}
setArr setArr::operator+(setArr& object){
    setArr newArr;
    for(int i=0; i<universeSize; i++){
    if(table[i] == true || object.table[i] == true){
        newArr.insert(i);
        }
    }
    return newArr;
}
setArr setArr::operator*(setArr& object){
    setArr newArr;
    for(int i = 0; i<universeSize; i++){
    if(table[i] == true && object.table[i] == true){
        newArr.insert(i);
        }
    }
    return newArr;
}
setArr setArr::operator-(setArr& object){
    setArr newArr;
    for(int i = 0; i<universeSize; i++){
    if(!object.table[i] && table[i]){
        newArr.insert(i);
        }
    }
    return newArr;
}
bool setArr::operator==(setArr& object){
    for(int i = 0; i<universeSize; i++){
        if(table[i] != object.table[i]){
            return false;
        }
    }
    return true;
}
bool setArr::operator<=(setArr& object){
    for(int i=0; i<universeSize; i++){
        if(!object.table[i] && table[i]){
            return false;
        }
    }
    return true;
}