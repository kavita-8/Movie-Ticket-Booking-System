#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cinema {
private:
    string name;
    vector<Screen*> screens;

public:
    Cinema(string name) : name(name) {}

    ~Cinema() {
        for (Screen* screen : screens) delete screen;
    }

    string getName() const { return name; }

    void addScreen(Screen* screen) {
        screens.push_back(screen);
    }

    const vector<Screen*>& getScreens() const { return screens; }
};
