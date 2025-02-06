#include "setArr.h"
#include "setList.h"

int main(){
    setArr arraySet;
    setArr arraySet2;

    std::cout<<"TABLICA :"<<std::endl;
    arraySet.insert(1);
    arraySet.insert(2);
    arraySet.insert(3);
    arraySet.insert(4);
    arraySet.insert(5);
    arraySet.insert(6);
    arraySet.printSet();

    arraySet.withdraw(6);
    arraySet.printSet();

    arraySet2.insert(1);
    arraySet2.insert(2);
    arraySet2.insert(3);
    
    setArr res = arraySet + arraySet2;
    res.printSet();
    setArr res1 = arraySet * arraySet2;
    res1.printSet();
    setArr res2 = arraySet - arraySet2;
    res2.printSet();

    std::cout<<(arraySet==arraySet2)<<std::endl;
    std::cout<<(arraySet<=arraySet2)<<std::endl;
    std::cout<<(arraySet2<=arraySet)<<std::endl;

    std::cout<<"----------------------"<<std::endl<<"LISTA :"<<std::endl;

    setList listSet;
    setList listSet2;

    listSet.insert(1);
    listSet.insert(2);
    listSet.insert(3);
    listSet.insert(4);
    listSet.insert(5);
    listSet.insert(6);
    listSet.printSet();

    listSet.withdraw(6);
    listSet.printSet();

    listSet2.insert(1);
    listSet2.insert(2);
    listSet2.insert(3);
    
    setList res3 = listSet + listSet2;
    res.printSet();
    setList res4 = listSet * listSet2;
    res1.printSet();
    setList res5 = listSet - listSet2;
    res2.printSet();

    std::cout<<(listSet==listSet2)<<std::endl;
    std::cout<<(listSet<=listSet2)<<std::endl;
    std::cout<<(listSet2<=listSet)<<std::endl;
}

