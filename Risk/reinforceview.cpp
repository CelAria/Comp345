// Team project assignment #3
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
//
// ------------------------------------------------------

#include "reinforceview.h"
#include <iostream>

using namespace std;

void ReinforceView::presentReinforce(){
     cout << "Reinforce phase:" << endl << endl;
}

int ReinforceView::getNumOfArmiesToPlace(GameMap* gameMap, Player *player){
    //number of countries owend by the player
    int numOfCountriesOwned = player->getCountriesCount();
    //number of armies the player recived based on the number of countries owend by the player /3
    //if this number is less then 3 give the player 3 armies
    int numOfArmiesRecieved = (numOfCountriesOwned/3);
    if(numOfArmiesRecieved <= 3)
        numOfArmiesRecieved = 3;
    
    vector<Country*> allCountries = player->getAllCountries();
    vector<string> continentControlValue;
    int myCounter = 0;
    //loops through all the countries the player controls
    for(int i = 0; i < allCountries.size(); i++)
    {
        //if the player controls all contries in the continent
        if(player->controlsContinent(allCountries[i]->getContinentName(), gameMap))
        {
            //add continent to vector continentControlValue to then check if it is only add once
            continentControlValue.push_back(allCountries[i]->getContinentName());
            for(int j = 0; j < continentControlValue.size(); j++)
            {
                if(continentControlValue[j] == allCountries[i]->getContinentName())
                {
                    myCounter++;
                }
            }
            //if a continent appears only once in the continentControlValue vector, then adjust the numOfArmiesRecieved
            if(myCounter == 1)
            {
                vector<Country*> allCountries2 = player->getCountriesByContinent(allCountries[i]->getContinentName());
                //if the player controls all the countries in a continent, then add the number of countries in that continent to the numOfArmiesRecieved
                numOfArmiesRecieved += allCountries2.size();
            }
            myCounter = 0;
        }
    }
    return numOfArmiesRecieved;
}
//display stats of the player'hand and number of countrues the player owns
void ReinforceView::displayStats(int numOfArmiesRecieved, Player *player){
    cout << "Number of armies: " << numOfArmiesRecieved << endl;
    cout << "Player" << player->getPlayerId() << " currently controls " << player->getCountriesCount() << " countries and holds "
    << player->getCardsCount() << " cards" << endl;
    cout << "Type of cards the player holds:" << endl;
    cout << "Infantry: " << player->getHand()->getNumOfInfantryCards()
    << ", Artillery: " << player->getHand()->getNumOfArtilleryCards()
    << ", Cavalry: " << player->getHand()->getNumOfCavalryCards() << endl;
}
//exchange player's cards for armies
void ReinforceView::userInputCardExchange(int numOfArmiesRecieved, Player *player){
    //if the player has less than 5 cards call the exchange method.
    while(player->getCardsCount() > 5)
    {
        string userInput;
        //print statments to ask the user which type of exchange the player whats to execute
        cout << endl;
        cout << "Card exchange (Enter either 0, 1, 2 or 3) " <<endl;
        cout << "\t• 0 = Exchange 3 cards of the same type" << endl;
        cout << "\t• 1 = Exchange 3 Infantry cards" << endl;
        cout << "\t• 2 = Exchange 3 Artillery cards" << endl;
        cout << "\t• 3 = Exchange 3 Cavalry cards" << endl;
        cout <<"Type of card exchange -> ";
        getline (cin, userInput);
        numOfArmiesRecieved = numOfArmiesRecieved + player->getHand()->exchange(userInput);
    }
    //if the player still has more than 2 cards, ask the user if he or she wants to exchange one more time
    if((player->getCardsCount() > 2)){
        string userInput;
        cout << "Do you want to do a card exchange? y/n -> ";
        getline (cin, userInput);
        if(userInput == "y"){
            string userInput2;
            cout << endl;
            //print statments to ask the user which type of exchange the player whats to execute
            cout << "Card exchange (Enter either 0, 1, 2 or 3) " <<endl;
            cout << "\t• 0 = Exchange 3 cards of the same type" << endl;
            cout << "\t• 1 = Exchange 3 Infantry cards" << endl;
            cout << "\t• 2 = Exchange 3 Artillery cards" << endl;
            cout << "\t• 3 = Exchange 3 Cavalry cards" << endl;
            cout <<"Type of card exchange -> ";
            getline (cin, userInput2);
            numOfArmiesRecieved = numOfArmiesRecieved + player->getHand()->exchange(userInput2);
        }
    }
    cout << endl;
}

//displays the countries that the player owns
void ReinforceView::displayContriesPlayerOwns(vector<Country*> allCountries, Player *player){
    cout << "The number of armies placed in each country that player " << player->getPlayerId() << " controls: " << endl;
    //displays the number of armies in each country the player controls
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getArmiesCount() << " armies placed in " << allCountries[i]->getName() <<endl;
    }
}
//asks the user in which country the player wants to had his or hers armies
bool ReinforceView::placeArmiesHuman(GameMap* gameMap, vector<Country*> allCountries, int numOfArmiesRecieved, Player *player){
    int numOfArmiesToPlace = numOfArmiesRecieved;
     cout << endl;
     cout << "The number of armies to be placed: " << numOfArmiesToPlace << endl;
    // do loop that loop through all the countries and if there are still armies left to place, repeat
    do{
        //loop through all the countries the player owns
        for(int i = 0; i < allCountries.size(); i++)
        {
            //ask the user how many armies the player wants to add to the a counrty
            string userInput;
            cout << "How many armies do you want to placed in " << allCountries[i]->getName() << "? -> ";
            getline (cin, userInput);
            //if the input is not a digit continue to the next iteration
            if(!isdigit(userInput[0])){
                continue;
            }
            //converts the input to an int
            int userInput2 = (userInput.at(0)-48);
                //checks if the input is smaller than the number of that needs to be placed
                if(userInput2 > numOfArmiesToPlace){
                    cout << "Input entered is greater than the number of armies left to place" << endl;
                }else{
                    numOfArmiesToPlace -= userInput2;
                    gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount() + userInput2));
                }
                //break out of the loop if there is no more armies to be placed
                if(numOfArmiesToPlace == 0){
                    break;
                }
        }
    }while(numOfArmiesToPlace > 0);
     cout << endl;
     return true;
}



