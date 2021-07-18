/*
    Travelling Salesman Problem Genetic algorithms (GAs)
    usage: ./tsp population(int) generations(int) keep(0<float<1) mutate(float)
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "point.h"  // Point class
#include "tsp-ga.h"  // TSPGenome class


//  Read .txt-file containing points
static void read_txt_and_fill(std::vector<Point>& txt_points)
{
    std::ifstream myfile;
    std::vector<int> read_point;
    std::string filestr = "points.txt";
    myfile.open(filestr);
    if (myfile.is_open())
    {
        std::cout << "\n** reading from .txt-file **\n";
        int points;
        while (myfile >> points)
        {
            read_point.push_back(points);
        }
        myfile.close();
    }
    else std::cout << "Unable to open file.";
    int n = 1;
    for (int i=0; i < read_point.front(); i++)
    {
        Point new_Points(read_point.at(n), read_point.at(n+1), read_point.at(n+2));
        txt_points.push_back(new_Points);
        n+=3;  // needed to insert points into x, y and z.
    }
}
//  print points from .txt-file
void printVec(const std::vector<Point>& points)
{
    std::cout << "\nWe have " << points.size() << " points\n";
    for (int i=0; i < points.size(); i++)
    {
        std::cout << "Point(" << i << "): " << points[i].getX_coord()
        <<", " << points[i].getY_coord()
        <<", " << points[i].getZ_coord() << std::endl;
    }
}

void printPath(const std::vector<int>& shortestPath)
{
    std::cout << "\nBest order: [ ";
    for (int i=0; i < shortestPath.size()-1; i++)
    {
        std::cout << shortestPath[i] << ' ';
    }
    std::cout << shortestPath[shortestPath.size()-1] << "]" << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<Point> points;

    if (argc != 5)  // incorrect number of arguments entered
    {  
        std::cout << "Usage: ./tsp population(int) generations(int) keep(float) mutate(float)" << std::endl;
        std::cout << "e.g.: ./tsp 1000 100 0.4 1.2" << std::endl;
        exit(1);
    }

    unsigned int popSize = static_cast<int>(atoi(argv[1]));  // population size
    unsigned int numGen =  static_cast<int>(atoi(argv[2]));  // # of generations
    int keepPop = static_cast<int>(atof(argv[3]) * (static_cast<float>(popSize)));    // % of population to keep, range [0, 1]
    int numMut = static_cast<int>(popSize * atof(argv[4]));   // mutation applied to population

    if (popSize < 0 || numGen < 0 || atof(argv[3]) < 0 || atof(argv[3]) > 1 || atof(argv[4]) < 0)
    {
        std::cout << "**Values out of range**" << std::endl;
        exit(1);
    }
    read_txt_and_fill(points);
    if (points.size() < 20)
    {
        printVec(points);
    }
    else
    {
        std::cout << "Read " << points.size() << " points" << std::endl;
    }
    // generate a different random sequence each time it runs
    srand(time(nullptr));
    TSPGenome path(points.size());
    path = findAShortPath(points, popSize, numGen, keepPop, numMut);
    std::cout   << "\nShortest distance: "
                << path.getCircuitLength()
                << std::endl;
    printPath(path.getOrder());
    points.clear();  // destroy all elements in vector
    return 0;
}
