//
//  attackphase.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-10-24.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <attackphase.h>



AttackPhase :: AttackPhase(Player *player)
{
    this->player = player;
    
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
        cout<<" how many dice do you want to roll?" << endl;
        
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



