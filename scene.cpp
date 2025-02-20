
#include "scene.h"
#include "globalvar.h"
#include "startmenu.h"

scene::scene(int num, QObject* parent){
    pause=new mybtn("P");
    pause->setFixedSize(boxSize);
    pause->move(700,50);
    bkpk=new mybtn("B");
    bkpk->setFixedSize(boxSize);
    bkpk->move(50,50);
    ensureVisible(pause);
    ensureVisible(bkpk);
    backpack=new Backpack();
    connect(backpack, &Backpack::to_game, this, &scene::cont);
    QString s="hero";
    Character* H=new Character(100,100,100, s);
    switch (num) {
    case 1:
        map[0]=new Map(":/resources/image/world1.jpg",800,600);
        map[1]=new Map(":/resources/image/city1.jpg",800,600);
        map[2]=new Map(":/resources/image/mono1.jpg",800,600);
        map[0]->setCharacter(H,0);
        map[0]->addTeleportPoint(800, map[1]);
        map[0]->addInteractionPoint(750, "Enter");
        for (int i = 0; i < 5; ++i) {
            backpack->putItem(i);
        }
        break;
    default:
        break;
    }
    for (int i = 0; i < 3; ++i) {
        map[i]->addWidget(pause);
        map[i]->addWidget(bkpk);
    }
    connect(pause, &mybtn::btnClicked, this, &scene::paused);
    connect(bkpk, &mybtn::btnClicked, this, &scene::to_bkpk);
    s=QString(":/resources/image/pause.jpg");
    pauseMenu=new startmenu(s);
    pauseMenu->start->setText("CONTINUE");
    setScene(pauseMenu);
    pauseMenu->exit->setText("EXIT");
    connect(pauseMenu->start, &mybtn::btnClicked, this, &scene::cont);
    connect(pauseMenu->exit, &mybtn::btnClicked, this, &scene::to_menu);
}

void scene::start(){
    setScene(map[0]);
    activeMap=map[0];
}
void scene::cont(){
    setScene(activeMap);
}

void scene::paused(){
    setScene(pauseMenu);
}

void scene::to_bkpk(){
    backpack->showItems();
    setScene(backpack);
}
