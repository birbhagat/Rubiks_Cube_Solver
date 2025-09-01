//
// Created by vibho on 03-07-2023.
//
#include "GenericCube.h"

class Cube3D : public GenericCube {
private:

    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
    }

public:
    char cube[6][3][3]{};

    Cube3D() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

    GenericCube &u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    GenericCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    GenericCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    GenericCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    GenericCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    GenericCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    GenericCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    GenericCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    GenericCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    GenericCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    GenericCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    GenericCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    GenericCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    GenericCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    GenericCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    GenericCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    GenericCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    GenericCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const Cube3D &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    Cube3D &operator=(const Cube3D &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const Cube3D &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }

};