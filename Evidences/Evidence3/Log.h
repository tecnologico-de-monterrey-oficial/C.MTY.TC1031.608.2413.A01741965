#pragma once
#include <string>
#include <iostream> 
using namespace std;

struct Log {
    string time;
    string ip;
    string message;
    string year;
    string month;
    string day;
    string issue;
    string key;
    int count;

    Log(string year, string month, string day, string time, string ip, string issue);
    Log() {}
    Log(string ip);
    string convertMonth(string month) const;
    string convertFromMonth(const string& month) const; 
    string getKey() const;  
    string getIp() const;
    int getCount() const;
    void setCount(int count);

};

Log::Log(string year, string month, string day, string time, string ip, string issue) {
    this->year = year;
    this->month = convertMonth(month);
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->issue = issue;
    this->key = year + this->month + day + time;

}

Log::Log(string ip) {
    this->ip = ip;
    this->count = 1;
}

string Log::convertMonth(string month) const {
    if (month == "Jan") return "01";
    else if (month == "Feb") return "02";
    else if (month == "Mar") return "03";
    else if (month == "Apr") return "04";
    else if (month == "May") return "05";
    else if (month == "Jun") return "06";
    else if (month == "Jul") return "07";
    else if (month == "Aug") return "08";
    else if (month == "Sep") return "09";
    else if (month == "Oct") return "10";
    else if (month == "Nov") return "11";
    else if (month == "Dec") return "12";
    return "00";
}

string Log::convertFromMonth(const string& month) const { 
    if (month == "01") return "Jan";
    else if (month == "02") return "Feb";
    else if (month == "03") return "Mar";
    else if (month == "04") return "Apr";
    else if (month == "05") return "May";
    else if (month == "06") return "Jun";
    else if (month == "07") return "Jul";
    else if (month == "08") return "Aug";
    else if (month == "09") return "Sep";
    else if (month == "10") return "Oct";
    else if (month == "11") return "Nov";
    else if (month == "12") return "Dec";
    return "00";
}

string Log::getKey() const {
    return key;
}

string Log::getIp() const {
    return ip;
}

int Log::getCount() const {
    return count;
}

void Log::setCount(int count) {
    this->count = count;
}


