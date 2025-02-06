#include "Graf.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

    Graf::Graf(){
        std::memset(matrix, 0 ,sizeof(matrix));
    }
    void Graf::createVertices(int ile){
        numberOfVertices = ile;
    }   
    void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
        checkIndexes(i_Vertex_Index_1,i_Vertex_Index_2);
        matrix[i_Vertex_Index_1][i_Vertex_Index_2] = true;
    }
    void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
        checkIndexes(i_Vertex_Index_1,i_Vertex_Index_2);
        matrix[i_Vertex_Index_1][i_Vertex_Index_2] = false;
    }
    bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
        if(i_Vertex_Index_1 > numberOfVertices || i_Vertex_Index_2 > numberOfVertices){
            std::cout<<"Incorrect vertex index number -> out of range"<<std::endl;
        }else{
        return matrix[i_Vertex_Index_1][i_Vertex_Index_2] == true;
        }
    }
    int Graf::vertexDegree(int idx){
        int deg = 0;
        for(int i =0;i<numberOfVertices;i++){
            if(matrix[idx][i] == true){
                deg++;
            }
        }
        return deg;
    }
    std::vector<int> Graf::getNeighbourIndices(int idx){
        std::vector<int> neighbours;
        for(int i =0;i<=numberOfVertices;i++){
            if(matrix[idx][i] == true){
                neighbours.push_back(i);
            }
        }
        return neighbours;
    }
    void Graf::printNeighbourIndices(int idx){
        for(int i =0;i<=numberOfVertices;i++){
            if(matrix[idx][i] == true){
                std::cout<<i<<" ";
            }
        }
        std::cout<<std::endl;
    }
    int Graf::getNumberOfEdges(){
        int numberOfEdges = 0;
        for(int i=0;i<=numberOfVertices;i++){
            for(int j=0;j<=numberOfVertices;j++){
                if(matrix[i][j] == true){
                    numberOfEdges++;
                }
            }
        }
        return numberOfEdges;
    }

void Graf::readFromFile(std::string path){
    std::ifstream file(path);
    if(file.is_open()){
    file>>numberOfVertices;
    if(numberOfVertices!=0){
    createVertices(numberOfVertices);
    }
    int i_Vertex_Index_1, i_Vertex_Index_2;
    while(file >> i_Vertex_Index_1 >> i_Vertex_Index_2){
        addEdge(i_Vertex_Index_1, i_Vertex_Index_2);
    }
    file.close();
    }else{
        std::cout<<"Cannot open file"<<std::endl;
        return;
    }
}

    void Graf::clear(){
        std::memset(matrix, 0 ,sizeof(matrix));
    }

    void Graf::checkIndexes(int i_Vertex_Index_1, int i_Vertex_Index_2){
        if(i_Vertex_Index_1 > numberOfVertices || i_Vertex_Index_2 > numberOfVertices){
            std::cout<<"Incorrect vertex index number -> out of range"<<std::endl;
            return;
        }
    }
