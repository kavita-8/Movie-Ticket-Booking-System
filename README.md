# 🎬 Movie Ticket Booking System

The **Movie Ticket Booking System** is a console-based application developed in **C++** to simulate the basic operations of a cinema ticket booking platform.

The system allows users to view available movies, show timings, screens, and seat availability before making a booking.

---

## 📌 Project Overview

Users can select a movie show, choose one or more seats, and book tickets according to different seat categories:

| Seat Category | Price |
|---|---:|
| Silver | ₹150 |
| Gold | ₹250 |
| Platinum | ₹400 |

The system supports multiple payment methods:

- UPI
- Card
- Cash

A booking is confirmed **only after successful payment**, and a ticket containing the booking details is generated.

The system also provides functionality to:

- View available movies
- View show timings and screens
- View seat availability
- Book one or more seats
- Calculate ticket prices
- Make payments
- View bookings
- Print tickets
- Cancel bookings
- Release seats after cancellation
- Handle failed payments
- Validate invalid inputs

---

## ✨ Features

### 🎥 Movie & Show Management
- View available movies
- View available shows
- Display screen number
- Display show timings

### 💺 Seat Management
- View seat layout
- Display seats as `AVAILABLE` or `BOOKED`
- Select one or more seats
- Prevent booking of already-booked seats
- Automatically release seats after cancellation
- Release selected seats when payment fails

### 💰 Seat Categories

- **Silver — ₹150**
- **Gold — ₹250**
- **Platinum — ₹400**

### 💳 Payment

The system supports:

- UPI Payment
- Card Payment
- Cash Payment

If payment fails, the booking is **not confirmed** and the selected seats are released.

### 🎟️ Booking

- Generate a unique booking ID
- Store customer and show details
- Calculate total amount
- Confirm booking after successful payment
- Print ticket details
- Cancel existing bookings

---

## 🏗️ System Design

The project is structured into multiple classes, with each class having a specific responsibility.

### Main Classes

| Class | Responsibility |
|---|---|
| `Movie` | Stores movie information |
| `Cinema` | Manages cinema and screens |
| `Screen` | Manages seats |
| `Seat` | Represents individual seats and categories |
| `Show` | Represents a movie show |
| `ShowSeat` | Maintains seat availability for a show |
| `Customer` | Stores customer information |
| `Booking` | Manages booking details |
| `Payment` | Abstract payment class |
| `UpiPayment` | Handles UPI payments |
| `CardPayment` | Handles card payments |
| `CashPayment` | Handles cash payments |
| `PriceCalculator` | Calculates ticket prices |
| `TicketPrinter` | Prints ticket details |
| `BookingService` | Handles booking operations |

---

## 🧠 OOP Concepts Used

The project demonstrates the following Object-Oriented Programming concepts:

### Encapsulation
Data members are kept private and accessed through appropriate methods.

### Abstraction
`Payment` is implemented as an abstract class that defines common payment operations.

### Inheritance
`UpiPayment`, `CardPayment`, and `CashPayment` inherit from the `Payment` class.

### Polymorphism
Runtime polymorphism is demonstrated through the different implementations of the `pay()` method.

### Static Members
Static members are used for generating unique booking IDs.

### Composition
Strong ownership relationships are used where the lifetime of one object depends on another.

Examples:

```text
Cinema → Screen
Screen → Seat
Show → ShowSeat
