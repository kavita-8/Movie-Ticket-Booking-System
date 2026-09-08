#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Each class is kept in its own .cpp file as required by the assignment.
#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "Booking.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void createDemoData(Cinema& cinema, vector<Movie*>& movies,
                    vector<Show*>& shows) {
    Screen* screen1 = new Screen(1);
    Screen* screen2 = new Screen(2);

    // 10 Silver, 10 Gold, 10 Platinum seats per screen.
    for (int i = 1; i <= 30; ++i) {
        SeatType type;
        if (i <= 10) type = SeatType::SILVER;
        else if (i <= 20) type = SeatType::GOLD;
        else type = SeatType::PLATINUM;

        screen1->addSeat(i, type);
        screen2->addSeat(i, type);
    }

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    movies.push_back(new Movie("Avengers: Endgame", "English", 181));
    movies.push_back(new Movie("3 Idiots", "Hindi", 170));
    movies.push_back(new Movie("Interstellar", "English", 169));

    shows.push_back(new Show(101, movies[0], screen1, "10:00 AM"));
    shows.push_back(new Show(102, movies[0], screen2, "06:00 PM"));
    shows.push_back(new Show(103, movies[1], screen1, "02:00 PM"));
    shows.push_back(new Show(104, movies[2], screen2, "01:00 PM"));
    shows.push_back(new Show(105, movies[2], screen2, "09:00 PM"));
}

void listMovies(const vector<Movie*>& movies) {
    cout << "\n========== MOVIES ==========\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". ";
        movies[i]->display();
    }
}

void listShows(const vector<Show*>& shows) {
    cout << "\n========== SHOWS ==========\n";
    for (Show* show : shows) {
        cout << "Show ID: " << show->getShowId()
             << " | " << show->getMovie()->getTitle()
             << " | Screen " << show->getScreen()->getScreenNumber()
             << " | " << show->getStartTime() << '\n';
    }
}

Show* chooseShow(const vector<Show*>& shows) {
    listShows(shows);

    cout << "\nEnter Show ID: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        clearInput();
        cout << "Invalid input.\n";
        return nullptr;
    }

    for (Show* show : shows)
        if (show->getShowId() == id) return show;

    cout << "Show not found.\n";
    return nullptr;
}

Payment* choosePayment() {
    cout << "\nPayment Method\n";
    cout << "1. UPI\n";
    cout << "2. Card\n";
    cout << "3. Cash\n";
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if (cin.fail()) {
        clearInput();
        return nullptr;
    }

    if (choice == 1) return new UpiPayment();
    if (choice == 2) return new CardPayment();
    if (choice == 3) return new CashPayment();

    cout << "Invalid payment method.\n";
    return nullptr;
}

int main() {
    Cinema cinema("PVR INOX Demo Cinema");
    vector<Movie*> movies;
    vector<Show*> shows;
    BookingService bookingService;

    createDemoData(cinema, movies, shows);

    int choice;

    do {
        cout << "\n\n========================================\n";
        cout << "       MOVIE TICKET BOOKING SYSTEM\n";
        cout << "       " << cinema.getName() << '\n';
        cout << "========================================\n";
        cout << "1. List Movies\n";
        cout << "2. View Shows\n";
        cout << "3. View Available/Booked Seats\n";
        cout << "4. Book Ticket\n";
        cout << "5. Print Ticket\n";
        cout << "6. Cancel Booking\n";
        cout << "7. List All Bookings\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            listMovies(movies);
            break;

        case 2:
            listShows(shows);
            break;

        case 3: {
            Show* show = chooseShow(shows);
            if (show) show->displaySeats();
            break;
        }

        case 4: {
            Show* show = chooseShow(shows);
            if (!show) break;

            show->displaySeats();

            cout << "Enter customer name: ";
            clearInput();
            string name;
            getline(cin, name);

            cout << "Enter phone number: ";
            string phone;
            getline(cin, phone);

            cout << "How many seats do you want to book? ";
            int count;
            cin >> count;

            if (cin.fail() || count <= 0) {
                clearInput();
                cout << "Invalid number of seats.\n";
                break;
            }

            vector<int> seatNumbers;
            cout << "Enter seat numbers separated by spaces: ";

            for (int i = 0; i < count; ++i) {
                int seat;
                cin >> seat;
                if (cin.fail()) {
                    clearInput();
                    cout << "Invalid seat number.\n";
                    seatNumbers.clear();
                    break;
                }
                seatNumbers.push_back(seat);
            }

            if (seatNumbers.empty()) break;

            Payment* payment = choosePayment();
            if (!payment) break;

            Customer customer(name, phone);
            bookingService.bookTicket(customer, show, seatNumbers, payment);
            break;
        }

        case 5: {
            cout << "Enter Booking ID: ";
            int id;
            cin >> id;

            if (cin.fail()) {
                clearInput();
                cout << "Invalid booking ID.\n";
                break;
            }

            Booking* booking = bookingService.findBooking(id);
            if (booking) TicketPrinter::print(*booking);
            else cout << "Booking not found.\n";
            break;
        }

        case 6: {
            cout << "Enter Booking ID to cancel: ";
            int id;
            cin >> id;

            if (cin.fail()) {
                clearInput();
                cout << "Invalid booking ID.\n";
                break;
            }

            bookingService.cancelBooking(id);
            break;
        }

        case 7:
            bookingService.listBookings();
            break;

        case 0:
            cout << "Thank you for using the Movie Ticket Booking System!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    for (Show* show : shows) delete show;
    for (Movie* movie : movies) delete movie;

    return 0;
}
