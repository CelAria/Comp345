//
//  attackphase.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-10-24.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <attackphase.h>



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
    
    cout<<"Do you want to attack? " << endl;
    cin >> attacking;
    while(attacking == 'y')
    {
        attackDiceLoop = true;
        defendDiceLoop = true;
        playerID = player->getPlayerId();
        
        cout<<"Player# " <<playerID<< " Attack" <<endl;
        cout<<"getting countries owned and armies on them"  <<endl <<endl;
       
        vector<Country*> allCountries = player->getAllCountries();

        countrySelect(allCountries);
        
      
        
        

        

        
       
        cout << endl;
        
        
        
        cout<<"how many dice do you want to roll?" << endl;
        
        while(attackDiceLoop){
        cin>> diceAmountAttack;
        if((diceAmountAttack >=1 && (diceAmountAttack<4)))
        {
            player->rollDice(diceAmountAttack);
            attackDiceLoop = false;
        }else
            cout<<"Dice Amount invalid, please choose again " <<endl;
            
        
        }
        player ->getDiceRollsAttack(diceAmountAttack);
        
        cout<<" defending player how many dice do you want to roll? " << endl;
        while(defendDiceLoop){
            cin>>diceAmountDefend;
            if((diceAmountDefend >=1 && (diceAmountDefend<3)))
            {
                player ->defendRollDice(diceAmountDefend);
                defendDiceLoop = false;
            } else
            cout<<"Dice Amount invalid, please choose again " <<endl;
            
            
        }

        player ->getDiceRollsDefend(diceAmountDefend);
        
        compare(diceAmountAttack, diceAmountDefend);
        

        cout<<"Keep attacking? " <<endl;
        cin>> attacking;
        
    
    }
    

}


void AttackPhase :: compare(int attackDice, int defendDice)
{
    if(attackDice ==3 && defendDice ==2) {
        
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats "<<player->getDefenseDice1()  << endl;
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats or is equal to "<<player->getAttackDice1()  << endl;
        }
        
        if(player->getAttackDice2() > player->getDefenseDice2())
        {
    
            cout<<"attack wins " <<player->getAttackDice2()<< " beats "<<player->getDefenseDice2()  << endl;
        }else if(player->getAttackDice2() <= player->getDefenseDice2()) {
           
            cout<<"defender wins " <<player->getDefenseDice2()<< " beats or is equal to "<<player->getAttackDice2()  << endl;
        }
    
        
        
    }
    if(attackDice ==3 && defendDice ==1) {
        
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
           
            cout<<"attack wins " <<player->getAttackDice1()<< " beats "<<player->getDefenseDice1()  << endl;
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
           
           cout<<"defender wins " <<player->getDefenseDice1()<< " beats or is equal to "<<player->getAttackDice1()  << endl;
        }

        
    }
    
    
    if(attackDice ==2 && defendDice ==2) {
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
           cout<<"attack wins " <<player->getAttackDice1()<< " beats "<<player->getDefenseDice1()  << endl;
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
           cout<<"defender wins " <<player->getDefenseDice1()<< " beats or is equal to "<<player->getAttackDice1()  << endl;
        }
        
        if(player->getAttackDice2() > player->getDefenseDice2())
        {
            
            cout<<"attack wins " <<player->getAttackDice2()<< " beats "<<player->getDefenseDice2()  << endl;
        }else if(player->getAttackDice2() <= player->getDefenseDice2()) {
           cout<<"defender wins " <<player->getDefenseDice2()<< " beats or is equal to "<<player->getAttackDice2()  << endl;
        }
        
        
    }
    if(attackDice ==2 && defendDice ==1) {
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
             cout<<"attack wins " <<player->getAttackDice1()<< " beats "<<player->getDefenseDice1()  << endl;
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
           cout<<"defender wins " <<player->getDefenseDice1()<< " beats or is equal to "<<player->getAttackDice1()  << endl;
        }
        
        
        
        
    }
    if(attackDice ==1 && defendDice ==2) {
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats "<<player->getDefenseDice1()  << endl;
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
            
            cout<<"defender wins " <<player->getDefenseDice1()<< " beats or is equal to "<<player->getAttackDice1()  << endl;
        }
        
    }
    
    if(attackDice ==1 && defendDice ==1) {
        
        if(player->getAttackDice1() > player->getDefenseDice1())
        {
            cout<<"attack wins " <<player->getAttackDice1()<< " beats "<<player->getDefenseDice1()  << endl;
        }else if(player->getAttackDice1() <= player->getDefenseDice1()) {
           cout<<"defender wins " <<player->getDefenseDice1()<< " beats or is equal to "<<player->getAttackDice1()  << endl;
        }
        
        
        
    }
    
   
    
  
}

void AttackPhase::countrySelect(vector<Country*> allCountries)
{
   cout<<"pick country you want to attack from: "  <<endl <<endl;
    
   for(int i = 0; i < allCountries.size(); i++) {
    cout << i+1 << " " << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << " Armies on country: " << allCountries[i]->getArmiesCount()<< endl;
    }
    cout << endl;
    
    int selection =0;
    bool notEnoughArmies = true;

    
    while(notEnoughArmies){
        cin>>selection;
        if(selection<1 || selection> allCountries.size())
        {
            cout<<"invalid country selection, choose again" <<endl;
            
            
        }else if((allCountries[selection-1]->getArmiesCount()>=2)){
            notEnoughArmies = false;
        } else
             cout<<"Country does not have enough armies on it, choose again" <<endl;
        
    }
    cout<< "you picked " << allCountries[selection - 1]->toString() <<endl;
    
    cout<<"Neighbours you can attack " << endl;
    
    vector<Country*> enemies = allCountries[selection - 1]->getAllNeighbors();
    
    
    
}



