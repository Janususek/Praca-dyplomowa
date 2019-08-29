#include <curses.h>
#include "Game.h"
#include <stdlib.h>

// private methods
void Game::update(){
    player.update();
    for(auto teacher : teachers){
        teacher->update();
    }
};
void Game::draw(){
    clear();
    generator.draw();
    map.draw();
    player.draw();
    for(auto teacher : teachers){
        teacher->draw();
    }
};
void Game::handleInput(){
    char c = wgetch(window);
    switch(c)
    { 
        case 'w':
            player.moveUP();
        break;
        case 's': 
            player.moveDOWN();
        break;
        case 'd':
            player.moveRIGHT(); 
        break;
        case 'a':
            player.moveLEFT();
        break;
    }
}
// public methods
void Game::run(){
    while (isRunning)
    {
        handleInput();
        update();
        draw();
        colisionDetection();
        refresh();
    };
};
void Game::colisionDetection(){
    for(auto teacher : teachers){
        if(teacher->x == player.x && teacher->y == player.y){
            teacher->askQuestion();
        }
    }

}

