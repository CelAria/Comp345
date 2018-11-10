//
//  observable.cpp
//  Risk
//
//  Created by Allan Pichardo on 11/10/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "observable.h"
#include "observer.h"
#include <set>

using namespace std;

void Observable::addObserver(Observer *observer) {
    observers.insert(observer);
}

void Observable::notifyObservers() {
    for(auto observer : observers) {
        observer->update();
    }
}
