#pragma once

enum class ShowSeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat* seat;
    ShowSeatStatus status;

public:
    ShowSeat(Seat* seat) : seat(seat), status(ShowSeatStatus::AVAILABLE) {}

    Seat* getSeat() const { return seat; }
    ShowSeatStatus getStatus() const { return status; }

    bool isAvailable() const {
        return status == ShowSeatStatus::AVAILABLE;
    }

    void book() { status = ShowSeatStatus::BOOKED; }
    void release() { status = ShowSeatStatus::AVAILABLE; }
};
