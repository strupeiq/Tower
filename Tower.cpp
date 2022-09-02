#include <vector>

#include "headers/graphics.h"
#include "Tower.h"

#pragma comment(lib, "Msimg32.lib")


const int WIDTH = 1200;
const int HEIGHT = 900;

int h = 80;
int disk_width_1 = 300;
int disk_width_2 = 300;
int disk_width_3 = 300;
int max_r = 150;

int x_0_1 = 200;
int x_0_2 = 590;
int x_0_3 = 980;
int y_0 = HEIGHT;

int f_n = 5;
int s_n = 2;
int t_n = 3;

std::vector<int> first_pillar(f_n);
std::vector<int> second_pillar(s_n);
std::vector<int> third_pillar(t_n);

bool selectionFrom = true;
bool selectionTo = false;
int from;   //Откуда пришли;

//vector<int> pillars[3];

//vector<int> pillar = {10, 7, 5, 2};


/*
Первый диск из (x0-r0 - left; y0 - w - top) в точку (x0 + r0 - right; y0 - bottom)
Второй диск из (x0-r1; y0 – w * 2) в точку (x0+r1; y0 – w)
x_0 - r[i] - left
y_0 - h * (i + 1) - top
x_0 + r[i] - right
y_0 - h * i - bottom
*/
std::vector<int> r(5);

void vector_push() {                                     //Заполняет векторы
    for (int i = 0; i < first_pillar.size(); ++i) {
        first_pillar[i] = disk_width_1;
        disk_width_1 -= 60;

    }
    for (int i = 0; i < second_pillar.size(); ++i) {
        second_pillar[i] = disk_width_2;
        disk_width_2 -= 60;
    }
    for (int i = 0; i < third_pillar.size(); ++i) {
        third_pillar[i] = disk_width_3;
        disk_width_3 -= 60;
    }
}                                                                               

void r_push() {                                          //Заполняет радиусы
    for (int i = 0; i < r.size(); ++i) {
        r[i] = max_r;
        max_r -= 30;
    }
}

void draw_disks_1() {
    for (int i = 0; i < first_pillar.size(); ++i) {
        setfillstyle(SOLID_FILL, RGB(59, 153, 105));
        bar(x_0_1 - r[i], y_0 - h * (i + 1), x_0_1 + r[i], y_0 - h * i);
    }
}

void draw_disks_2() {
    for (int i = 0; i < second_pillar.size(); ++i) {
        setfillstyle(SOLID_FILL, RGB(59, 153, 105));
        bar(x_0_2 - r[i], y_0 - h * (i + 1), x_0_2 + r[i], y_0 - h * i);
    }
}

void draw_disks_3() {
    for (int i = 0; i < third_pillar.size(); ++i) {
        setfillstyle(SOLID_FILL, RGB(59, 153, 105));
        bar(x_0_3 - r[i], y_0 - h * (i + 1), x_0_3 + r[i], y_0 - h * i);
    }
}

int select_disk_1() {
    int x = mousex();
    int y = mousey();

    if (x >= x_0_1 - r[first_pillar.size() - 1] && x <= x_0_1 + r[first_pillar.size() - 1]
        && y >= y_0 - h * (first_pillar.size() - 1) && y <= y_0 - h * first_pillar.size()) {

        return 1;
    }
    return 0;
}

int select_disk_2() {
    int x = mousex();
    int y = mousey();

    if (x >= x_0_2 - r[second_pillar.size() - 1] && x <= x_0_2 + r[second_pillar.size() - 1]
        && y >= y_0 - h * (second_pillar.size() - 1) && y <= y_0 - h * second_pillar.size()) {

        return 2;
    }
}

int select_disk_3() {
    int x = mousex();
    int y = mousey();

    if (x >= x_0_3 - r[third_pillar.size() - 1] && x <= x_0_3 + r[third_pillar.size() - 1]
        && y >= y_0 - h * (third_pillar.size() - 1) && y <= y_0 - h * third_pillar.size()) {

        return 3;
    }
}

void game() {
    setfillstyle(SOLID_FILL, BROWN);
    bar(180, 300, 220, 900);
    bar(570, 300, 610, 900);                   //Отрисовка столбиков
    bar(960, 300, 1000, 900);

    draw_disks_1();
    draw_disks_2();
    draw_disks_3();



    if (selectionFrom) {
        if (select_disk_1()) {
            setfillstyle(SOLID_FILL, RED);
            bar(x_0_1 - r[first_pillar.size() - 1], y_0 - h * first_pillar.size(), x_0_1 + r[first_pillar.size() - 1], y_0 - h * (first_pillar.size() - 1));
        }
        else if (select_disk_2()) {
            setfillstyle(SOLID_FILL, RED);
            bar(x_0_2 - r[second_pillar.size() - 1], y_0 - h * second_pillar.size(), x_0_2 - r[second_pillar.size() - 1], y_0 - h * (second_pillar.size() - 1));
        }
        else if (select_disk_3()) {
            setfillstyle(SOLID_FILL, RED);
            bar(x_0_3 - r[third_pillar.size() - 1], y_0 - h * third_pillar.size(), x_0_3 - r[third_pillar.size() - 1], y_0 - h * (third_pillar.size() - 1));
        }
        selectionFrom = false;
        selectionTo = true;
    }
    else if (selectionTo) {
        /*
        if (select_disk_1()) {                                                                        //Если нажата 3 вершина
            if (select_disk_2()) {
                if (first_pillar[first_pillar.size() - 1] < second_pillar[second_pillar.size() - 1]) {
                    second_pillar.resize(s_n++);
                    second_pillar.push_back(first_pillar[first_pillar.size() - 1]);
                    first_pillar.pop_back();
                }
            }
            else if (select_disk_3()) {
                if (first_pillar[first_pillar.size() - 1] < third_pillar[third_pillar.size() - 1]) {
                    third_pillar.resize(t_n++);
                    third_pillar.push_back(first_pillar[first_pillar.size() - 1]);
                    first_pillar.pop_back();
                }
            }
        }*/

        if (select_disk_1()) {

        }

    }
    else if (select_disk_2()) {                                                                       //Если нажата 2 вершина
        if (select_disk_1()) {
            if (second_pillar[second_pillar.size() - 1] < first_pillar[first_pillar.size() - 1]) {
                first_pillar.resize(f_n++);
                first_pillar.push_back(second_pillar[second_pillar.size() - 1]);
                second_pillar.pop_back();
            }
        }
        else if (select_disk_3()) {
            if (second_pillar[second_pillar.size() - 1] < third_pillar[third_pillar.size() - 1]) {
                third_pillar.resize(t_n++);
                third_pillar.push_back(second_pillar[second_pillar.size() - 1]);
                second_pillar.pop_back();
            }
        }
    }
    else if (select_disk_3()) {                                                                       //Если нажата 3 вершина
        if (select_disk_1()) {
            if (third_pillar[third_pillar.size() - 1] < first_pillar[first_pillar.size() - 1]) {
                first_pillar.resize(f_n++);
                first_pillar.push_back(third_pillar[third_pillar.size() - 1]);
                third_pillar.pop_back();
            }
        }
        else if (select_disk_2()) {
            if (third_pillar[third_pillar.size() - 1] < second_pillar[second_pillar.size() - 1]) {
                second_pillar.resize(s_n++);
                second_pillar.push_back(third_pillar[third_pillar.size() - 1]);
                third_pillar.pop_back();
            }
        }
    }
    selectionTo = false;
    selectionFrom = true;
}