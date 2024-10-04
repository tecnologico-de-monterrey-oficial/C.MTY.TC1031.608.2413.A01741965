#pragma once


struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string issue;
    string key;
    Log(
        string year,
        string month,
        string day,
        string time,
        string ip,
        string issue
    );
    string convertMonth(string month);
    bool operator<(Log log);
};

Log::Log(string year, string month, string day, string time, string ip, string issue) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->issue = issue;
    this->key = year + convertMonth(month) + day + time;
}

string Log::convertMonth(string month) {
    if (month == "Jan") {
        return "01";
    } else if (month == "Feb") {
        return "02";
    } else if (month == "Mar") {
        return "03";
    } else if (month == "Apr") {
        return "04";
    } else if (month == "May") {
        return "05";
    } else if (month == "Jun") {
        return "06";
    } else if (month == "Jul") {
        return "07";
    } else if (month == "Aug") {
        return "08";
    } else if (month == "Sep") {
        return "09";
    } else if (month == "Oct") {
        return "10";
    } else if (month == "Nov") {
        return "11";
    } else if (month == "Dec") {
        return "12";
    } else {
        return "00";
    }
}

bool Log::operator<(Log log) {
    return key < log.key;
}

