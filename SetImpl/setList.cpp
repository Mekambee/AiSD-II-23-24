#include "setList.h"

int setList::getSize(){
    return vec.size();
}

void setList::printSet(){
    for(int i=0; i<getSize(); i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

void setList::insert(int x){
    if(!isInSet(x)){
    vec.push_back(x);
    }
}

void setList::withdraw(int x){
    for(int i=0; i<getSize();i++){
        if(vec[i] == x){
            vec.erase(vec.begin() + i);
        }
    }
}

bool setList::isInSet(int x){
    for(int i=0; i<getSize(); i++){
        if(vec[i] == x){
            return true;
        }
    }
    return false;
}

setList setList::operator+(setList& obj){
    setList newVec;
    newVec = *this;
    for(int i = 0; i < obj.getSize(); i++){
        newVec.insert(obj.vec[i]);
    }
    return newVec;
}

setList setList::operator*(setList& obj){
    setList newVec;
    for(int i = 0; i < obj.getSize(); i++){
        if(isInSet(obj.vec[i])){
            newVec.insert(obj.vec[i]);
        }
    }
    return newVec;
}

setList setList::operator-(setList& obj){
    setList newVec;
    newVec = *this;
    for(int i =0; i<obj.getSize();i++){
        if(newVec.isInSet(obj.vec[i])){
            newVec.withdraw(obj.vec[i]);
        }
    }
    return newVec;
}

bool setList::operator==(setList& obj){
    if(getSize() != obj.getSize()) return false;
    for(int i=0; i<obj.getSize(); i++){
        if(!isInSet(obj.vec[i])){
            return false;
        }
    }
    return true;
}

bool setList::operator<=(setList& obj){
    for(int i=0; i<getSize();i++){
        if(!obj.isInSet(vec[i])){
            return false;
        }
    }
    return true;
}

