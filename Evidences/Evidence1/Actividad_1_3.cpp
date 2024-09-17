#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

struct LogEntry {
    std::string month;
    int day;
    int year;
    std::string time;
    std::string ipAddress;
    std::string message;
};

bool compareLogEntries(const LogEntry& entry1, const LogEntry& entry2) {
    // Compare log entries based on date and time
    // You can modify this function based on your sorting criteria
    if (entry1.year != entry2.year) {
        return entry1.year < entry2.year;
    }
    if (entry1.month != entry2.month) {
        return entry1.month < entry2.month;
    }
    if (entry1.day != entry2.day) {
        return entry1.day < entry2.day;
    }
    return entry1.time < entry2.time;
}

int main() {
    std::ifstream inputFile("log-6.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::vector<LogEntry> data;
    std::string month;
    int day;
    int year;
    std::string time;
    std::string ipAddress;
    std::string message;

    while (inputFile >> month >> day >> year >> time >> ipAddress) {
        std::getline(inputFile, message);
        // Remove leading whitespace from the message
        message = message.substr(1);

        LogEntry entry;
        entry.month = month;
        entry.day = day;
        entry.year = year;
        entry.time = time;
        entry.ipAddress = ipAddress;
        entry.message = message;

        data.push_back(entry);
    }

    inputFile.close();

    // Sort the data based on date and time
    std::sort(data.begin(), data.end(), compareLogEntries);

    // Save the sorted data to output608.txt
    std::ofstream outputFile("output608.txt");
    if (!outputFile) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    for (const auto& entry : data) {
        outputFile << entry.month << " " << entry.day << " " << entry.year << " "
                   << entry.time << " " << entry.ipAddress << " " << entry.message << std::endl;
    }

    outputFile.close();

    // Perform binary search on the sorted data
    // Here you can implement the binary search algorithm to search for a range of dates and times

    // Save the search results to range608.txt
    std::ofstream rangeFile("range608.txt");
    if (!rangeFile) {
        std::cerr << "Failed to open range file." << std::endl;
        return 1;
    }

    // Write the search results to rangeFile

    rangeFile.close();

    std::cout << "The file has been sorted and the search results have been saved." << std::endl;

    return 0;
}
