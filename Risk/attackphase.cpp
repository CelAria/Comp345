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
        
        playerID = player->getPlayerId();
        
        cout<< playerID <<endl;
        cout<<" how many dice do you want to roll?" << endl;
        cin>> diceAmountAttack;
        player->rollDice(diceAmountAttack);
        player ->getDiceRollsAttack(diceAmountAttack);
        cout<<" defending player how many dice do you want to roll?" << endl;
        cin>>diceAmountDefend;

        player ->defendRollDice(diceAmountDefend);
        player ->getDiceRollsDefend(diceAmountDefend);
        
        
        cout<<"Keep attacking? " <<endl;
        cin>> attacking;
        
    
    }
    

}


void AttackPhase :: compare()
{
   
    
}



