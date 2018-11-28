//
//  CheaterAttack.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-27.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "CheaterAttack.h"

CheaterAttack:: CheaterAttack(Player *player, GameMap *gameMap)
{
    this->player = player;
    this->gameMap = gameMap;
    attackView = AttackView ();
    srand((unsigned)time(0));
    
    
}

void CheaterAttack :: attackLoop()
{
    //asks to attack
    //gets countries owned, picks country, gets armysize from country, gets neighbours owned by other playerID
    //rolls dice based on armies from country & players choice
    //defending country rolls dice based on armies & player's choice
    //compare dice from both players "determines win aka loose army"
    //checks army size of defending country - if 0 attacker wins
    // calls moveArmy if wins
    //asks again if they want to attack
    
    int randomAmountStart  =0;
    randomAmountStart = (rand() % 4 + 1);
    
    if(randomAmountStart == 1 || randomAmountStart == 4){
        start = true;
    }
    else {
        start = false;
    }
    
    
    
    //    start= attackView.startAttackPhase();
    playerID = player->getPlayerId();
    cout<<"Player# " <<playerID <<" Do you want to attack?"<<endl;
    if(start) {
        cout<<"Yes "<<endl;
    }
    else {
        cout<<"No "<<endl;
    }
    
    while(start)
    {
        
        attackDiceLoop = true;
        defendDiceLoop = true;
        playerID = player->getPlayerId();
        
        cout<<"Player# " <<playerID<< " Attack" <<endl;
        cout<<"getting countries owned and armies on them"  <<endl;
        
        vector<Country*> allCountries = player->getAllCountries();
        
        
        countrySelect(allCountries);
        
        start = false;
//        int randomAmountContinue  =0;
//        randomAmountContinue = (rand() % 3 + 1);
//
//        if (continueAttack && randomAmountContinue == 1){
//            cout<<"Do you want to attack again? "<<endl;
//            cout<<"yes "<<endl;
//            start = true;
//        }
//        else {
//            cout<<"stop attacking..."<<endl;
//            start = false;
        }
        
//    }
}

//compares attackers and defenders dice
//keeps track of how many wins and looses occur so we can subtract that from the army count later on


//lets user pick which country to select from
//if country doesnt have enough armies, asks to pick again
//carries out attack/defender dice rolls
//subtracts armies lost
//if country is defeated, asks winner to move x amount of armies

void CheaterAttack::countrySelect(vector<Country*> allCountries)
{
    
    
    attackView.playerCountryList(allCountries);
    
  
    bool notEnoughArmies = true;
    vector<Country*> enemies;
    vector<Country*> allEnemies;
    
    
    
    
    while(notEnoughArmies){
        vector<Country*> allNeighbours;
        vector <Country*> StealCountries;
        
        for (int i =0; i<allCountries.size();i++){
           allNeighbours = allCountries[i]->getAllNeighbors();
            for(int j =0; j<allNeighbours.size();j++){
                if(allNeighbours[j]->getOwner()->getPlayerId() != player->getPlayerId()){
                StealCountries.push_back(allNeighbours[j]);
            }
            }
        }
        
        if(StealCountries.size() ==0)
        {
            cout<<"No more enemey neighbours to take..."<<endl;
            return;
            
        }
        
        for(int i = 0; i<StealCountries.size(); i++){
            cout<<"You have taken " << StealCountries[i]->toString()<<endl;
            StealCountries[i]->setOwner(player);
            player->addCountry(gameMap->getCountry(StealCountries[i]->getName()));
            
        }
        StealCountries.clear();

    }
}



