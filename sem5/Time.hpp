
#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    static inline int objectCount;

    void toTime(int s);
public:
    Time();
    Time(int h, int m, int s);
    Time(const Time &t);

    Time &operator=(const Time &other);
    bool operator==(const Time &other) const;
    Time &operator-=(int s);
    Time operator-(int s) const;
    Time &operator+=(int s);
    Time operator+(int s) const;

    ~Time();

    void SetHours(const int h);
    int ToSeconds();
    void Normalize();
    int GetHours() const;
    int GetMinutes() const;
    int GetSeconds() const;
    void PrintTime() const;
};
