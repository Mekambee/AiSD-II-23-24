// #include "KolejkaPriorytetowa.h"
// #include <iostream>

// int main(){
//     KolejkaPriorytetowa queue;
//     queue.insert(5);
//     queue.insert(4);
//     queue.insert(7);
//     queue.insert(2);
//     queue.insert(1);
//     queue.insert(8);
//     queue.insert(3);
//     queue.insert(6);
//     queue.insert(9);
    
//     queue.print();
//     std::cout<<"Root item:"<<queue.getRootElem()<<std::endl<<"Removing root"<<std::endl;
//     queue.RemoveRootElem();
//     queue.print();
//     std::cout<<"Root item:"<<queue.getRootElem()<<std::endl<<"Removing root"<<std::endl;
//     queue.RemoveRootElem();
//     queue.print();
// }

#include "KolejkaPriorytetowa.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    KolejkaPriorytetowa kolejka;

    kolejka.insert(6);
    kolejka.insert(3);
    kolejka.insert(21);
    kolejka.insert(142);
    kolejka.insert(-12);
    kolejka.insert(21);
    kolejka.insert(25);
    kolejka.insert(17);
    kolejka.insert(1);


for(int i=0;i<12;i++)
{
    cout << kolejka.getRootElem() << " ";
    kolejka.RemoveRootElem();
}
    
    return 0;
}