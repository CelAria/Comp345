//
//  attackview.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-08.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <attackview.h>

AttackView:: AttackView() {
    
    
}

bool AttackView:: startAttackPhase() {
    
    cout<<"Do you want to attack? Please enter y for yes, n for no " << endl;
    bool attackPhaseInput = true;
    string attacking;
    char input = NULL;
    bool start = false;
    
    
    while(attackPhaseInput)
    {
        cin >> attacking;
        input = attacking.at(0);
        if(input == 'y')
        {
            attackPhaseInput = false;
            start =true;
        } else if(input =='n'){
            cout<<"Attack Phase over"<<endl;
            return false;
        }
        
        else
            cout<<"Wrong input, please select y for yes, n for no" <<endl;
        
    }

    
    return start;
}

bool AttackView::keepAttacking() {
    bool attackPhaseInput = true;
    string attacking;
    char input = NULL;
    bool start = false;
    cout<<"Keep attacking? Please enter y for yes, n for no" <<endl;
    
    while(attackPhaseInput)
    {
        cin >> attacking;
        input = attacking.at(0);
        if(input =='y')
        {
            attackPhaseInput = false;
            start = true;
        } else if(input== 'n'){
            cout<<"Attack Phase over"<<endl;
            return false;
        }
        
        else
            cout<<"Wrong input, please select y for yes, n for no" <<endl;
        
    }
    return start;
    
}
    

void AttackView::playerCountryList(vector<Country*> allCountries){
     cout<<"pick country you want to attack from: "  <<endl <<endl;
    for(int i = 0; i < allCountries.size(); i++) {
        cout << i+1 << " " << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << " Armies on country: " << allCountries[i]->getArmiesCount()<< endl;
    }
    cout << endl;
    
}

int AttackView:: pickAttackingCountry(){
    int selectCountry;
     cin>>selectCountry;
    return selectCountry;
}

int AttackView:: pickDice(){
    int diceAmount;
    cin>>diceAmount;
    return diceAmount;
}

int AttackView:: moveArmies(){
    int armies;
    cin>>armies;
    return armies;
}

void AttackView::enemyCountryList(vector<Country*> enemies, Player *player){
    cout<<"Neighbours you can attack " << endl<<endl;
    
    
    
    for(int i = 0; i < enemies.size(); i++) {
        
        if(enemies[i]->getOwner()->getPlayerId() != player->getPlayerId()){
            cout << i+1 << " " << enemies[i]->getName() << ", " << enemies[i]->getContinentName() << " Armies on country: " << enemies[i]->getArmiesCount()<< endl;
        }
    }
    cout << endl;
    
}
