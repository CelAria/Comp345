//
//  observable.h
//  Risk
//
//  Created by Allan Pichardo on 11/10/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "observer.h"
#include <set>

using namespace std;

class Observable {
private:
    set<Observer*> observers;
    
public:
    virtual void addObserver(Observer* observer) {observers.insert(observer);};
    virtual void notifyObservers() = 0;
};
