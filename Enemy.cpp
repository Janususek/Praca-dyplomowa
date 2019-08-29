#include "Enemy.h"
#include <iostream>
#include <curses.h>
#include <fstream>

void Enemy::update(){
    
    if ( currentUpdate == updatesTreshold){
        // losuj kierunek
    unsigned int los=std::rand()%(4);
    // moveUP/moveDown etc.
    if(los == 0){ moveUP();}
    else if(los == 1){ moveDOWN();}
    else if(los == 2){ moveLEFT();}
    else if(los == 3){ moveRIGHT();}
    currentUpdate = 0;
    }
    else
    {
        currentUpdate++;
    }
    
    
}
void Enemy::draw(){
    mvprintw(y,x,character.c_str());
}

Enemy::Enemy(int x, int y, Map* map)
{ this->x = x;
    this->y = y;
    this->character = "T";
    this->map = map;
    // set file path "D:\Praca_dyplomowa\test\Pytania_Testowe\Biologia\Pyt_1.txt"
    filePath+=subject;
    unsigned int questionNumber = std::rand()%(questionsCup) + 1;
    filePath += std::to_string(questionNumber) + ".txt";
    answers.resize(n_answers);
    std::ifstream stream(filePath);
    if(stream.is_open()){
        std::getline(stream,question);
        for(int i = 0; i < n_answers; i++){
            std::getline(stream,answers[i]);
        }
        std::string temp;
        std::getline(stream,temp);
        corectAnswer = std::stoi(temp);
    }
    stream.close();
    window = newwin(6,question.size()+2,10,10);
}

Enemy::~Enemy()
{
    if(window != nullptr) delwin(window);
}
void Enemy::moveUP(){
    int x1=this->x;
    int y1=this->y; 
    if (map->getTile(x1,y1-1)!=map->ch){
        y--;
    }
}
void Enemy::moveDOWN(){
    int x1=this->x;
    int y1=this->y;
    if (map->getTile(x1,y1+1)!=map->ch){
        y++;
    }
}
void Enemy::moveRIGHT(){
    int x1=this->x;
    int y1=this->y; 
    if (map->getTile(x1+1,y1)!=map->ch){
        this->x++;
    }
}
void Enemy::moveLEFT(){
    int x1=this->x;
    int y1=this->y;
    if (map->getTile(x1-1,y1)!=map->ch){
        x--;
    }
}
void Enemy::askQuestion(){
        unsigned int choice=0;
        unsigned int highlight=0; 
        bool chosen = false;
        printQuestion(highlight);
    while (!chosen)
    {
    char c = wgetch(window);   
        switch(c)
        { 
            case 'w':
                if (highlight!=0){
                    highlight--;
                }else{
                    highlight=n_answers-1;
                }    
            break;
            case 's': 
                if (highlight!=n_answers-1){
                    highlight++;
                }else{
                    highlight=0;
                }    
            break;
            case 'e':
                choice=highlight; 
                chosen=true;
            break;
        }
        printQuestion(highlight);
    }
}
void Enemy::printQuestion(unsigned int highlight){
    wclear (window); //czyszczenie okna
    box(window,0,0);
    mvwprintw(window,1,1,question.c_str());
    for (int i=0; i<3; i++){
        if (i==highlight){
            wattron(window, A_REVERSE);
            mvwprintw(window,i+2,1,answers[i].c_str());
            wattroff(window, A_REVERSE);
        }
        else{
            mvwprintw(window,i+2,1,answers[i].c_str());
        }
    }
    wrefresh(window);
}