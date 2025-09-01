<<<<<<< HEAD
#include <bits/stdc++.h>
#include "Data Structures/Cube3D.cpp"
#include "Data Structures/CubeBitboard.cpp"
#include "Data Structures/Cube1D.cpp"
#include "CubeSolvers/CubeBFS.h"
#include "CubeSolvers/CubeDFS.h"
using namespace std;
int main() {

     //DFS Solver Testing __________________________________________________________________________________________
//     cout<<"Solving with DFS ----------------------------------------------------------------"<<endl;
//     Cube3D cube;
//     cube.print();
//
//     vector<Cube3D::MOVE> shuffle_moves = cube.randomShuffleCube(6);
//     for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//     cout << "\n";
//     cube.print();
//
//     CubeDFS<Cube3D, Hash3d> dfsSolver(cube, 8);
//     vector<Cube3D::MOVE> solve_moves = dfsSolver.solve();
//
//     for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//     cout << "\n";
//     dfsSolver.rubiksCube.print();


    //BFS Solver -----------------------------------------------------------------------------------------------------
    cout<<"Solving with BFS ----------------------------------------------------------------"<<endl;
    CubeBitboard cube2;
    cube2.print();
    int numShuffles;
    cout<<"Please Enter the number of Shuffles to be made: ";
    cin>>numShuffles;
    vector<Cube3D::MOVE> shuffle_moves2 = cube2.randomShuffleCube(numShuffles);
    for(auto move: shuffle_moves2) cout << cube2.getMove(move) << " ";
    cout << "\n";
    cube2.print();

    CubeBFS<CubeBitboard, HashBitboard> bfsSolver(cube2);
    vector<GenericCube::MOVE> solve_moves2 = bfsSolver.solve();

    for(auto move: solve_moves2) cout << cube2.getMove(move) << " ";
    cout << "\n";
    bfsSolver.rubiksCube.print();
=======
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
>>>>>>> 377e59d (Changes)
    return 0;
}
