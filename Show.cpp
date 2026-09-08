#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Show {
private:
    int showId;
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat*> showSeats;

public:
    Show(int id, Movie* movie, Screen* screen, string time)
        : showId(id), movie(movie), screen(screen), startTime(time) {
        for (Seat* seat : screen->getSeats())
            showSeats.push_back(new ShowSeat(seat));
    }

    ~Show() {
        for (ShowSeat* seat : showSeats) delete seat;
    }

    int getShowId() const { return showId; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }
    const vector<ShowSeat*>& getShowSeats() const { return showSeats; }

    ShowSeat* findShowSeat(int number) const {
        for (ShowSeat* ss : showSeats)
            if (ss->getSeat()->getSeatNumber() == number) return ss;
        return nullptr;
    }

    void displaySeats() const {
        cout << "\nSeat Layout (A = Available, B = Booked)\n";
        for (ShowSeat* ss : showSeats) {
            cout << ss->getSeat()->getSeatNumber()
                 << "-" << (ss->isAvailable() ? "A" : "B") << "  ";
            if (ss->getSeat()->getSeatNumber() % 10 == 0) cout << '\n';
        }
        cout << '\n';
    }
};
