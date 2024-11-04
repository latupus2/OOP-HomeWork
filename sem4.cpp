#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    static inline int objectCount;

    void toTime(int s){
        hours = s / 3600;
        s %= 3600;
        minutes = s / 60;
        seconds = s % 60;
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {
        objectCount++;
        std::cout << "Default Constructor called. Current object count: " << objectCount << std::endl;
    }
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        Normalize();
        objectCount++;
        std::cout << "Parameterized Constructor called. Current object count: " << objectCount << std::endl;
    }
    Time(const Time &t) : Time(t.hours, t.minutes, t.seconds) {}
    ~Time() {
        objectCount--;
        std::cout << "Destructor called. Current object count: " << objectCount << std::endl;
    }

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

    void SetHours(const int h){
        hours = h;
        Normalize();
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


int main()
{
    Time t;
    t.SetHours(1);

    Time t2 = t;
    t2.SetHours(2);
    t2.PrintTime();

    {
        t2.SetHours(12);
        t2.PrintTime();
        Time t2(22, 22, 22);
        t2.PrintTime();
    }
    t2.PrintTime();

    Time t3(3, 3, 3);
    t3 = t;
    t3.SetHours(3);
    t3.PrintTime();

    return 0;
}
