//
// Created by vibho on 03-07-2023.
//
#include<bits/stdc++.h>
#include "../Data Structures/GenericCube.h"

#ifndef RUBIKSCUBESOLVERV1_0_0_CUBEDFS_H
#define RUBIKSCUBESOLVERV1_0_0_CUBEDFS_H
// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class CubeDFS {
private:

    vector<GenericCube::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(GenericCube::MOVE(i));
            moves.push_back(GenericCube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(GenericCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    CubeDFS(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<GenericCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};


#endif //RUBIKSCUBESOLVERV1_0_0_CUBEDFS_H
