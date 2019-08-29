#pragma once
#include <curses.h>
#include "Player.h"
#include "Map.h"
#include "Generator.h"
#include "Enemy.h"
#include <ctime>
#include <vector>

class Game
{
private:
    // fields
    unsigned int numberOfTeachers = 50;
    bool isRunning;
    Map map;
    Player player;
    Generator generator;
    WINDOW* window;
    // methods
    void handleInput();
    void update();
    void colisionDetection();
    void draw();
    std::vector<Enemy*> teachers;
public:
    // constructors and destructors
    Game():player(100,10,&map),generator(14,59,&map){
        srand(time(NULL));
        isRunning=true;
        window = initscr();
        for(int i = 0; i < numberOfTeachers; i++){
            unsigned int losX = std::rand()%(map.getWidth()-1);
            unsigned int losY = std::rand()%(map.getHeight()-1);
            // TODO: sprawdzić czy nie na pozycji teachera
            while(map.getTile(losX,losY)==map.ch || player.x == losX && player.y == losY || losX == 0 || losY == 0){
                losX = std::rand()%(map.getWidth()-1);
                losY = std::rand()%(map.getHeight()-1);
            }
            auto teacher = new Enemy(losX,losY,&map);
            teachers.push_back(teacher);
        }
        clear();
        noecho();
        keypad(window,true);
        cbreak();
        generator.generate();
    };
    ~Game(){
        for(auto teacher : teachers){
            if(teacher != nullptr) delete teacher;
        }
    };
    // public methods
    void run();
};


