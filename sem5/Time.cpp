#include "Time.hpp"

void Time::toTime(int s){
        hours = s / 3600;
        s %= 3600;
        minutes = s / 60;
        seconds = s % 60;
    }

Time::Time() : hours(0), minutes(0), seconds(0) {
        objectCount++;
        std::cout << "Default Constructor called. Current object count: " << objectCount << std::endl;
    }
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    Normalize();
    objectCount++;
    std::cout << "Parameterized Constructor called. Current object count: " << objectCount << std::endl;
}
Time::Time(const Time &t) : Time(t.hours, t.minutes, t.seconds) {}
Time::~Time() {
    objectCount--;
    std::cout << "Destructor called. Current object count: " << objectCount << std::endl;
}

int Time::GetHours() const { return hours; }
int Time::GetMinutes() const { return minutes; }
int Time::GetSeconds() const { return seconds; }

void Time::PrintTime() const {
    std::cout << this->GetHours() << ":" << this->GetMinutes() << ":" << this->GetSeconds() << std::endl;
}

int Time::ToSeconds(){
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::Normalize() {    
    toTime(ToSeconds());
}

void Time::SetHours(const int h){
    hours = h;
    Normalize();
}

Time &Time::operator=(const Time &other) {
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    return *this;
}

bool Time::operator==(const Time &other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

Time &Time::operator-=(int s) {
    seconds -= s;
    Normalize();
    return *this;
}

Time Time::operator-(int s) const {
    Time result = *this;
    result -= s;
    return result;
}

Time &Time::operator+=(int s) {
    seconds += s;
    Normalize();
    return *this;
}

Time Time::operator+(int s) const {
    Time result = *this;
    result += s;
    return result;
}