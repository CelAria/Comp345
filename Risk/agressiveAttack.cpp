//
//  agressiveAttack.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-16.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "agressiveAttack.h"
//constructor for attackPhase
AgressiveAttack :: AgressiveAttack(Player *player, GameMap *gameMap)
{
    this->player = player;
    this->gameMap = gameMap;
    attackView = AttackView ();
    
    
}

void AgressiveAttack :: attackLoop()
{
    //asks to attack
    //gets countries owned, picks country, gets armysize from country, gets neighbours owned by other playerID
    //rolls dice based on armies from country & players choice
    //defending country rolls dice based on armies & player's choice
    //compare dice from both players "determines win aka loose army"
    //checks army size of defending country - if 0 attacker wins
    // calls moveArmy if wins
    //asks again if they want to attack
    
    
    start = true;
//    start= attackView.startAttackPhase();
     playerID = player->getPlayerId();
    cout<<"Player# " <<playerID <<" Do you want to attack?"<<endl;
    cout<<"yes "<<endl;
    
    while(start)
    {
        
        attackDiceLoop = true;
        defendDiceLoop = true;
        playerID = player->getPlayerId();
        
        cout<<"Player# " <<playerID<< " Attack" <<endl;
        cout<<"getting countries owned and armies on them"  <<endl;
        
        vector<Country*> allCountries = player->getAllCountries();
        
        
        countrySelect(allCountries);
        if (continueAttack){
        cout<<"Do you want to attack again? "<<endl;
        cout<<"yes "<<endl;
        start = true;
        }
        else {
            cout<<"stop attacking...no neighbours or too weak"<<endl;
            start = false;
        }
        
    }
}

//compares attackers and defenders dice
//keeps track of how many wins and looses occur so we can subtract that from the army count later on
void AgressiveAttack :: compare(int attackDice, int defendDice)
{
    winAttackCounter=0;
    winDefenseCounter=0;
    if(attackDice ==3 && defendDice ==2) {
        
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats defender "<<player->getDefenseDice1()  << endl;
            winAttackCounter++;
            
            
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats (or is equal to) attacker "<<player->getAttackDice1()  << endl;
            winDefenseCounter++;
        }
        
        if(player->getAttackDice2() > player->getDefenseDice2())
        {
            
            cout<<"attack wins " <<player->getAttackDice2()<< " beats defender "<<player->getDefenseDice2()  << endl;
            winAttackCounter++;
            
        }else if(player->getAttackDice2() <= player->getDefenseDice2()) {
            
            cout<<"defender wins " <<player->getDefenseDice2()<< " beats (or is equal to) attacker "<<player->getAttackDice2()  << endl;
            winDefenseCounter++;
            
        }
        
        
        
    }
    if(attackDice ==3 && defendDice ==1) {
        
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            
            cout<<"attack wins " <<player->getAttackDice1()<< " beats defender "<<player->getDefenseDice1()  << endl;
            winAttackCounter++;
            
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats (or is equal to) attacker "<<player->getAttackDice1()  << endl;
            winDefenseCounter++;
            
        }
        
        
    }
    
    
    if(attackDice ==2 && defendDice ==2) {
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats defender "<<player->getDefenseDice1()  << endl;
            winAttackCounter++;
            
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats (or is equal to) attacker "<<player->getAttackDice1()  << endl;
            winDefenseCounter++;
            
        }
        
        if(player->getAttackDice2() > player->getDefenseDice2())
        {
            
            cout<<"attack wins " <<player->getAttackDice2()<< " beats defender "<<player->getDefenseDice2()  << endl;
            winAttackCounter++;
            
        }else if(player->getAttackDice2() <= player->getDefenseDice2()) {
            cout<<"defender wins " <<player->getDefenseDice2()<< " beats (or is equal to) attacker "<<player->getAttackDice2()  << endl;
            winDefenseCounter++;
            
        }
        
        
    }
    if(attackDice ==2 && defendDice ==1) {
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats defender "<<player->getDefenseDice1()  << endl;
            winAttackCounter++;
            
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats (or is equal to) attacker "<<player->getAttackDice1()  << endl;
            winDefenseCounter++;
            
        }
        
        
        
        
    }
    if(attackDice ==1 && defendDice ==2) {
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats defender "<<player->getDefenseDice1()  << endl;
            winAttackCounter++;
            
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats (or is equal to) attacker "<<player->getAttackDice1()  << endl;
            winDefenseCounter++;
            
        }
        
    }
    
    if(attackDice ==1 && defendDice ==1) {
        
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats defender "<<player->getDefenseDice1()  << endl;
            winAttackCounter++;
            
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats (or is equal to) attacker "<<player->getAttackDice1()  << endl;
            winDefenseCounter++;
            
        }
        
        
        
    }
    
    
    
    
}


//lets user pick which country to select from
//if country doesnt have enough armies, asks to pick again
//carries out attack/defender dice rolls
//subtracts armies lost
//if country is defeated, asks winner to move x amount of armies

void AgressiveAttack::countrySelect(vector<Country*> allCountries)
{
    
    
    attackView.playerCountryList(allCountries);
    
    int selectCountry =0;
    bool notEnoughArmies = true;
    vector<Country*> enemies;
    vector<Country*> allEnemies;
    
  
    
    
    while(notEnoughArmies){
        int bigArmyCountry =0;
        int bigArmyCount =0;
        for(int i =0; i<allCountries.size(); i++){
            bigArmyCountry = allCountries[i]->getArmiesCount();
            for (int j=0;j<allCountries.size(); j++){
                if(bigArmyCount < allCountries[i]->getArmiesCount()){
                    bigArmyCount =allCountries[i]->getArmiesCount();
                    bigArmyCountry=j;
                }
                
            }
            
        }
       
        
        
        
        
        selectCountry = bigArmyCountry;
        
        
        if(selectCountry<1 || selectCountry> allCountries.size())
        {
            cout<<"invalid country selection, choose again" <<endl;
            
            
            
        }
        else if((allCountries[selectCountry-1]->getArmiesCount()>=2)){
            continueAttack = true;
            vector<Country*> potentialEnemies = allCountries[selectCountry - 1]->getAllNeighbors();
            
            for(int i=0; i<potentialEnemies.size(); i++)
            {
                if(potentialEnemies[i]->getOwner() != player->getPlayerId())
                {
                    enemies.push_back(potentialEnemies[i]);
                }
                
            }
            
            if(enemies.size()>0)
            {
                
                notEnoughArmies = false;
            } else{
                cout<<"Country has no attackable neighbours" <<endl;
                continueAttack = false;
                return;
                
                
            }
        } else{
            cout<<"Country does not have enough armies on it" <<endl;
            continueAttack = false;
            return;
            
            
        }
        
    }
    cout<< "The Country you picked to attack from is " << allCountries[selectCountry - 1]->toString() <<endl;
    
    
    
    
    attackView.enemyCountryList(enemies, player);
    
    int selectAttackCountry =1;
    bool wrongInput = true;
    
    while(wrongInput){
        
        
        if(selectAttackCountry<1 || selectAttackCountry> enemies.size())
        {
            cout<<"invalid country selection, choose again" <<endl;
            selectAttackCountry +=1;
        }
        else {
            wrongInput = false;
        }
        
    }
    
    cout<< "The Country you picked to attack is " << enemies[selectAttackCountry - 1]->toString() <<endl;
    
    cout<<"attacking player...how many dice to roll?" << endl;
    diceAmountAttack =3;
    while(attackDiceLoop){
        
        
        cout<<diceAmountAttack<<endl;
        
        
        if((diceAmountAttack >=1 && (diceAmountAttack<4)) && (diceAmountAttack <=(allCountries[selectCountry - 1]->getArmiesCount()-1)))
        {
            player->rollDice(diceAmountAttack);
            attackDiceLoop = false;
        }
        else
        { cout<<"Dice Amount invalid, please choose again " <<endl;
            diceAmountAttack -=1;
        }
        
        
        
    }
    player ->getDiceRollsAttack(diceAmountAttack);
    
    
        cout<<"defending player...how many dice to roll?" << endl;
    while(defendDiceLoop){
        
        if(enemies[selectAttackCountry - 1]->getStrat() == 0){
            diceAmountDefend = attackView.pickDice();
        }
        
        if(enemies[selectAttackCountry - 1]->getStrat() == 1){
            cout<<2<<endl;
            diceAmountDefend =2;
            
            if((diceAmountDefend >=1 && diceAmountDefend<3) && (diceAmountDefend <= enemies[selectAttackCountry - 1]->getArmiesCount()))
                
            {
                player ->defendRollDice(diceAmountDefend);
                defendDiceLoop = false;
            } else{
                cout<<"Dice Amount invalid, please choose again " <<endl;
                cout<<1<<endl;
                diceAmountDefend = 1;
                player ->defendRollDice(diceAmountDefend);
                defendDiceLoop = false;
            }
            
            
        }
        
        
        
        if(enemies[selectAttackCountry - 1]->getStrat() == 2){
            
            cout<<2<<endl;
            diceAmountDefend =2;
            if((diceAmountDefend >=1 && diceAmountDefend<3) && (diceAmountDefend <= enemies[selectAttackCountry - 1]->getArmiesCount()))
                
            {
                player ->defendRollDice(diceAmountDefend);
                defendDiceLoop = false;
            } else{
                cout<<"Dice Amount invalid, please choose again " <<endl;
                cout<<1<<endl;
                diceAmountDefend = 1;
                player ->defendRollDice(diceAmountDefend);
                defendDiceLoop = false;
            }
            
        }
        
        
        if((diceAmountDefend >=1 && diceAmountDefend<3) && (diceAmountDefend <= enemies[selectAttackCountry - 1]->getArmiesCount()))
        {
            player ->defendRollDice(diceAmountDefend);
            defendDiceLoop = false;
        } else
            cout<<"Dice Amount invalid, please choose again " <<endl;
        
        
    }
    
    
    player ->getDiceRollsDefend(diceAmountDefend);
    
    compare(diceAmountAttack, diceAmountDefend);
    
    
    cout<<""<<endl;
    cout<<"attacking army defeated this many armies: " <<winAttackCounter<<endl;
    cout<<"defending army defeated this many armies: " <<winDefenseCounter<<endl;
    cout<<""<<endl;
    
    
    allCountries[selectCountry - 1]->setArmiesCount(allCountries[selectCountry - 1]->getArmiesCount() - winDefenseCounter);
    enemies[selectAttackCountry - 1]->setArmiesCount(enemies[selectAttackCountry - 1]->getArmiesCount()-winAttackCounter);
    
    if( enemies[selectAttackCountry - 1]->getArmiesCount() ==0){
        cout<<"you have defeated " << enemies[selectAttackCountry - 1]->getName()<< ", " << enemies[selectAttackCountry - 1]->getContinentName()<<endl;
        
        cout<<"How many armies do you wish to move from: "<<allCountries[selectCountry - 1]->toString()<<endl;
        
        bool moveArmyInput = true;
        while(moveArmyInput){
            
//            moveArmies=attackView.moveArmies();
            moveArmies =1;
            
            
            if((moveArmies >=1) && (moveArmies <=allCountries[selectCountry - 1]->getArmiesCount()-1)){
                enemies[selectAttackCountry - 1]->setOwner(player->getPlayerId());
                enemies[selectAttackCountry - 1]->setStrat(1);
                gameMap->getCountry(enemies[selectAttackCountry - 1]->getName())->setArmiesCount(moveArmies);
                player->addCountry(gameMap->getCountry(enemies[selectAttackCountry - 1]->getName()));
                gameMap->getCountry(allCountries[selectCountry - 1]->getName())->setArmiesCount(allCountries[selectCountry - 1]->getArmiesCount()-moveArmies);
                cout<<"Moved " <<moveArmies <<" armies" <<endl;
                moveArmyInput=false;
                
            }else{
                cout<<"invalid amount of armies pick again"<<endl;
            }
            
            
        }
    }
    
    
    
}



