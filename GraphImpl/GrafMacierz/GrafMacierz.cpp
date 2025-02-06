// #include "Graf.h"

// void test1()
// {   
//     std::cout<<"------Test1------"<<std::endl;
//     Graf* G = new Graf();    
//     G->createVertices(10);
//     G->addEdge(1, 2);
//     G->addEdge(2, 3);
//     G->addEdge(1, 5);
//     std::cout<<"Stopnien wezla 1"<<std::endl;
//     std::cout << G->vertexDegree(1)<<"\n";
//     std::cout<<"Stopnien wezla 8"<<std::endl;
//     std::cout << G->vertexDegree(8) << "\n";
//     std::cout<<"Sasiedzi 1"<<std::endl;
//     G->printNeighbourIndices(1);
//     std::cout<<"Sasiedzi 1"<<std::endl;
//     G->printNeighbourIndices(1);
//     std::cout<<"Czy 1 polaczone z 2?"<<std::endl;
//     std::cout << G->checkEdge(1, 2)<<"\n";
//     G->removeEdge(1, 2);
//     std::cout<<"Sasiedzi 1"<<std::endl;
//     G->printNeighbourIndices(1);
//     std::cout<<"Czy 1 polaczone z 2?"<<std::endl;
//     std::cout << G->checkEdge(1, 2) << "\n\n\n\n\n";   
// }

// void test2()
// {   
//     std::cout<<"-------Test2-------"<<std::endl;
//     Graf* G = new Graf();
//     // G->readFromFile("C:\\Users\\tomek\\Desktop\\algorytmy�wiczenia\\week3\\Graf.txt");
//     std::cout<<"Wczytana zawartosc pliku:"<<std::endl;
//     G->readFromFile("/Users/kamilpiechota/Desktop/AiSD2/zadanie3Graf/GrafMacierz/GrafSmall.txt");

//     // G->readFromFile("/Users/kamilpiechota/Desktop/AiSD2/zadanie3Graf/GrafMacierz/GrafL.txt");

//     std::cout<<"Sasiedzi 1"<<std::endl;
//     G->printNeighbourIndices(1);
//     std::cout<<"Liczba krawedzi"<<std::endl;
//     std::cout << G->getNumberOfEdges();
// }

// int main()
// {
//     test1();
//     test2();  
// }
#include "Graf.h"

void test2()
{
    Graf* G = new Graf();
    // G->readFromFile("C:\\Users\\Tomek\\Desktop\\OCENY_ALGO\\GRAF_GR3\\GTest.txt");
    G->readFromFile("/Users/kamilpiechota/Desktop/AiSD2/zadanie3Graf/GrafMacierz/graftest.txt");
    std::cout<<"sąsiedzi 0\n";
    G->printNeighbourIndices(0);
    std::cout<<"sąsiedzi 7\n";
    G->printNeighbourIndices(7);
    std::cout<<"sąsiedzi 9\n";
    G->printNeighbourIndices(9);
    std::cout<<"vert degr 0\n";
    std::cout << G->vertexDegree(0) << "\n";
    std::cout<<"vert degr 7\n";
    std::cout << G->vertexDegree(7) << "\n";
    std::cout<<"vert degr 9\n";
    std::cout << G->vertexDegree(9) << "\n";
    std::cout<<"liczba krawedzi \n";
    std::cout << G->getNumberOfEdges() << "\n\n";
}

int main()
{
       test2();  
}



