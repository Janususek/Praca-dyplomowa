#pragma once
#include "Entity.h"
#include <string>
#include <curses.h>
class Enemy: public Entity
{
    int currentUpdate=0;
    int updatesTreshold=2; // liczba pętli opóźniających teachera
    std::string question; // string z pytaniem
    std::vector<std::string> answers; // wector odpowiedzi
    unsigned int n_answers=3; // ilość odpowiedzi
    std::string filePath = "D:\\Praca_dyplomowa\\test\\Pytania_Testowe\\"; // ścieżka dostępowa do pytań
    int questionsCup=2; // ilość pytań w zestawie
    std::string subject = "Biologia\\Pyt_"; //nazwa przedmiotu (matematyka, biologia itd)
    unsigned int corectAnswer; //numer poprawnej odpowiedzi
    WINDOW* window = nullptr;
    void printQuestion(unsigned int highlight);
public:
    Enemy(int x, int y, Map* map);
    ~Enemy();
    virtual void update() override;
    virtual void draw() override;
    virtual void moveUP() override;
    virtual void moveDOWN() override;
    virtual void moveRIGHT() override;
    virtual void moveLEFT() override;
    void askQuestion ();
    



    
};
