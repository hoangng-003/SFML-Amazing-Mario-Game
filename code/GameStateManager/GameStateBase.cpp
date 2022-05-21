#include "GameStateBase.h"
#include "GSLose.h"
#include "GSMenu.h"
#include "GSMap1.h"
#include "GSMap2.h"
#include "GSMap3.h"
#include "GSLose2.h"
#include "GSLose3.h"


GameStateBase* GameStateBase :: createState(StateTypes st){
  GameStateBase* gs = nullptr;
  switch(st){
        case INVALID: 
          break;
        case MENU:
          gs = new GSMenu();
          break;
        case LOSE:
          gs = new GSLose();
          break;
        case MAP1:
          gs = new GSMap1();
          break;
        case LOSE2:
          gs = new GSLose2();
          break;
        case MAP2:
          gs = new GSMap2();
          break;
        case LOSE3:
          gs = new GSLose3();
          break;
        case MAP3:
          gs = new GSMap3();
          break;
        case END:
          break;
        default:
          break;
      } 
  return gs;
}

GameStateBase :: GameStateBase(){

}
GameStateBase :: ~GameStateBase(){
  
}