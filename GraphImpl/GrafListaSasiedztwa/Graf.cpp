#include "Graf.h"
#include "edge.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

    Graf::Graf(){}
    void Graf::createVertices(int ile){
        vertexList.resize(ile+1);
    }  
    void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
        if(i_Vertex_Index_1 > vertexList.size() || i_Vertex_Index_2 > vertexList.size() 
            || i_Vertex_Index_1 < 0 || i_Vertex_Index_2 < 0){
            std::cout << "Index out of range" << std::endl;
        }else{
        edge krawedz(i_Vertex_Index_1,i_Vertex_Index_2);
        vertexList[i_Vertex_Index_1].push_back(krawedz);
        }
    }   
    bool Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
        
        if(checkIndexes(i_Vertex_Index_1,i_Vertex_Index_2)){

        std::vector<edge> &currentEdge = vertexList[i_Vertex_Index_1];

        for(auto it = currentEdge.begin();it != currentEdge.end();){
            if(it->vertex_Index2 == i_Vertex_Index_2){
                currentEdge.erase(it);
                return true;
                }
            }
        }
        return false;
    }
    bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
        if(checkIndexes(i_Vertex_Index_1,i_Vertex_Index_2)){
            int temp = vertexList[i_Vertex_Index_1].size();
            for(int i =0; i< temp;i++){
                if(vertexList[i_Vertex_Index_1][i].vertex_Index2 == i_Vertex_Index_2){
                    return true;
                }
            }
        }
        return false;
    }
    int Graf::vertexDegree(int idx){
        if(idx < 0 || idx > (int)vertexList.size()){
            std::cout<<"Index out of range"<<std::endl;
            return 0;
        }else{
            return vertexList[idx].size();
        }
    }
    std::vector<int> Graf::getNeighbourIndices(int idx){
        std::vector<int> neighbours;
        if(idx < 0 || idx > vertexList.size()){
            std::cout<<"Index out of range"<<std::endl;
            return neighbours;
        }else{
            std::vector<edge> temp = vertexList[idx];
        for(int i = 0; i < temp.size(); ++i){
            neighbours.push_back(temp[i].vertex_Index2);
            }
        }
        return neighbours;
    }
    void Graf::printNeighbourIndices(int idx){
            std::vector<int> temp = getNeighbourIndices(idx);
            for(int i =0; i<temp.size();i++){
                std::cout<<temp[i]<<" ";
            }
        std::cout<<std::endl;
    }
    int Graf::getNumberOfEdges(){
        int sum = 0;
        for(int i = 0;i<vertexList.size();i++){
            sum += vertexList[i].size();
        }
        return sum;
    }
void Graf::readFromFile(std::string path) {
    std::ifstream file(path);
    if(file.is_open()){
    int numberOfVertices;
    file >> numberOfVertices;
    if(numberOfVertices!=0){
    createVertices(numberOfVertices);
    }
    int i_Vertex_Index_1, i_Vertex_Index_2;
    while (file >> i_Vertex_Index_1 >> i_Vertex_Index_2) {
        addEdge(i_Vertex_Index_1, i_Vertex_Index_2);
    }
    file.close();
    }else{
        std::cout<<"Cannot open file"<<std::endl;
        return;
    }
}

    bool Graf::checkIndexes(int i_Vertex_Index_1, int i_Vertex_Index_2){
    if(i_Vertex_Index_1 > vertexList.size() || i_Vertex_Index_2 > vertexList.size() 
        || i_Vertex_Index_1 < 0 || i_Vertex_Index_2 < 0){
        std::cout << "Index out of range" << std::endl;
        return false;
        }
        return true;
    }
