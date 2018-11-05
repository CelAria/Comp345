//
//  attackphase.cpp
//  Risk
//
//  Created by Matthew Salaciak 29644490
//  ASSIGNMENT #2
//  Copyright © 2018 comp345. All rights reserved.
//

#include <attackphase.h>


//constructor for attackPhase
AttackPhase :: AttackPhase(Player *player, GameMap *gameMap)
{
    this->player = player;
    this->gameMap = gameMap;
    
    
}

void AttackPhase :: attackLoop()
{
    //asks to attack
    //gets countries owned, picks country, gets armysize from country, gets neighbours owned by other playerID
    //rolls dice based on armies from country & players choice
    //defending country rolls dice based on armies & player's choice
   //compare dice from both players "determines win aka loose army"
    //checks army size of defending country - if 0 attacker wins
  // calls moveArmy if wins
    //asks again if they want to attack
   
    cout<<"Do you want to attack? Please enter y for yes, n for no " << endl;
    bool attackPhaseInput = true;
    string attacking;
    char input = NULL;
    

    while(attackPhaseInput)
    {
        cin >> attacking;
        input = attacking.at(0);
       if(input == 'y')
       {
        attackPhaseInput = false;
       } else if(input =='n'){
           cout<<"Attack Phase over"<<endl;
           return;
       }
       
       else
            cout<<"Wrong input, please select y for yes, n for no" <<endl;
        
    }

          
    
    while(input == 'y')
    {
        attackPhaseInput = true;
        attackDiceLoop = true;
        defendDiceLoop = true;
        playerID = player->getPlayerId();
        
        cout<<"Player# " <<playerID<< " Attack" <<endl;
        cout<<"getting countries owned and armies on them"  <<endl;

        vector<Country*> allCountries = player->getAllCountries();

        countrySelect(allCountries);
        

        cout<<"Keep attacking? Please enter y for yes, n for no" <<endl;
        
        while(attackPhaseInput)
        {
            cin >> attacking;
            input = attacking.at(0);
            if(input =='y')
            {
                attackPhaseInput = false;
            } else if(input== 'n'){
                cout<<"Attack Phase over"<<endl;
                return;
            }
            
            else
                cout<<"Wrong input, please select y for yes, n for no" <<endl;
            
        }
        
    
    }
    

}

//compares attackers and defenders dice
//keeps track of how many wins and looses occur so we can subtract that from the army count later on
void AttackPhase :: compare(int attackDice, int defendDice)
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

void AttackPhase::countrySelect(vector<Country*> allCountries)
{
   cout<<"pick country you want to attack from: "  <<endl <<endl;
    
   for(int i = 0; i < allCountries.size(); i++) {
    cout << i+1 << " " << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << " Armies on country: " << allCountries[i]->getArmiesCount()<< endl;
    }
    cout << endl;
    
    int selectCountry =0;
    bool notEnoughArmies = true;
    vector<Country*> enemies;

    
    while(notEnoughArmies){
        cin>>selectCountry;
        if(selectCountry<1 || selectCountry> allCountries.size())
        {
            cout<<"invalid country selection, choose again" <<endl;
            
            
        }
        else if((allCountries[selectCountry-1]->getArmiesCount()>=2)){
            
            vector<Country*> potentialEnemies = allCountries[selectCountry - 1]->getAllNeighbors();
            
            for(int i=0; i<potentialEnemies.size(); i++)
            {
                if((potentialEnemies[i]->hasNeighbors()) && potentialEnemies[i]->getOwner() != player->getPlayerId())
                {
                    enemies.push_back(potentialEnemies[i]);
                }
                
            }
            
            if(enemies.size()>0)
            {
            
            notEnoughArmies = false;
            } else{
                cout<<"Country has no attackable neighbours, choose again" <<endl;
            }
        } else
             cout<<"Country does not have enough armies on it, choose again" <<endl;
        
    }
     cout<< "The Country you picked to attack from is " << allCountries[selectCountry - 1]->toString() <<endl;


    cout<<"Neighbours you can attack " << endl<<endl;
    

    
    for(int i = 0; i < enemies.size(); i++) {
        
       if(enemies[i]->getOwner() != player->getPlayerId()){
        cout << i+1 << " " << enemies[i]->getName() << ", " << enemies[i]->getContinentName() << " Armies on country: " << enemies[i]->getArmiesCount()<< endl;
        }
    }
    cout << endl;
    
    int selectAttackCountry =0;
    bool wrongInput = true;
    
    while(wrongInput){
        cin>>selectAttackCountry;
        if(selectAttackCountry<1 || selectAttackCountry> enemies.size())
        {
            cout<<"invalid country selection, choose again" <<endl;
        }
        else {
            wrongInput = false;
        }
        
    }
    cout<< "The Country you picked to attack is " << enemies[selectAttackCountry - 1]->toString() <<endl;
    
    cout<<"attacking player...how many dice to roll?" << endl;

    while(attackDiceLoop){
        cin>> diceAmountAttack;
        if((diceAmountAttack >=1 && (diceAmountAttack<4)) && (diceAmountAttack <=(allCountries[selectCountry - 1]->getArmiesCount()-1)))
        {
            player->rollDice(diceAmountAttack);
            attackDiceLoop = false;
        }else
            cout<<"Dice Amount invalid, please choose again " <<endl;


    }
    player ->getDiceRollsAttack(diceAmountAttack);

    cout<<"defending player...how many dice do you want to roll? " << endl;
    while(defendDiceLoop){
        cin>>diceAmountDefend;
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
            cin>>moveArmies;
            if((moveArmies >=1) && (moveArmies <=allCountries[selectCountry - 1]->getArmiesCount()-1)){
                enemies[selectAttackCountry - 1]->setOwner(player->getPlayerId());
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



