#include "item.h"
#include "globalvar.h"
int bgmSound=50, toolSound=50, storySound=50;
int curScene=0, prevScene=0;
QSize btnSize(120,60), boxSize(50,50), picSize(200,200);
int colorStatus[5]={0};
int use_color=-1;
Item* items[6];


globalvar::globalvar()
{


}

