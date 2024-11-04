#include <iostream>

class Time {
    int hours;
    int minutes;
    int seconds;

    void toTime(int s){
        hours = s / 3600;
        s %= 3600;
        minutes = s / 60;
        seconds = s % 60;
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        Normalize();
    }
    Time(const Time &t) : Time(t.hours, t.minutes, t.seconds) {}
    ~Time() {}

    int GetHours() const { return hours; }
    int GetMinutes() const { return minutes; }
    int GetSeconds() const { return seconds; }

    void PrintTime() const {
        std::cout << this->GetHours() << ":" << this->GetMinutes() << ":" << this->GetSeconds() << std::endl;
    }

    int ToSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void Normalize() {    
        toTime(ToSeconds());
    }

    Time &operator=(const Time &other) {
        this->hours = other.hours;
        this->minutes = other.minutes;
        this->seconds = other.seconds;
        return *this;
    }

    bool operator==(const Time &other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    Time &operator-=(int s) {
        seconds -= s;
        Normalize();
        return *this;
    }

    Time operator-(int s) const {
        Time result = *this;
        result -= s;
        return result;
    }

    Time &operator+=(int s) {
        seconds += s;
        Normalize();
        return *this;
    }

    Time operator+(int s) const {
        Time result = *this;
        result += s;
        return result;
    } 
};


int main() {
    Time t1(13, 44, -30);
    t1.PrintTime();

    Time t2(1, 1, 1);
    t2.PrintTime();

    Time t3 = t1 - t2.ToSeconds();
    t3.PrintTime();

    t1 -= 90; 
    t1.PrintTime(); 

    std::cout << (t1 == t2) << std::endl;

    return 0;
}
