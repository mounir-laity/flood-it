#include "Filehandler.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

FileHandler::FileHandler(unsigned lines, unsigned columns, unsigned colors)
{
    this->lines = lines;
    this->columns = columns;
    this->colors = colors;

}

int FileHandler::readRecord() {
    ifstream inFile("records.txt",fstream::in | fstream::app);
    //For some reason, it always fails when opening a file in a subdirectory,
    //even with the path from the resource file
    if(inFile.fail()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    string wanted = to_string(lines)+"x"+to_string(columns)+"x"+to_string(colors);
    string line;
    string subString = "9999";
    while(getline(inFile, line)) {
        if(!line.find(wanted)) {
            subString = line.substr(line.find(":") + 1);
        }
    }
    int record = std::stoi(subString);
    inFile.close();
    return record;
}


void FileHandler::writeRecord(int record) {
    ifstream inFile("records.txt",fstream::in | fstream::out | fstream::app);
    ofstream temp("temp.txt", fstream::in | fstream::out | fstream::app);
    if(!inFile || !temp) {
        cerr << "Can't open the files." <<endl;
    }
    string wanted = to_string(lines)+"x"+to_string(columns)+"x"+to_string(colors);
    string newRecord = wanted+":"+to_string(record);
    string line;
    bool found = false;
    while(getline(inFile, line)) {
        if(!line.find(wanted)) {
            found = true;
            line = newRecord;
        }
        temp << line <<endl;
    }
    if(!found) {
        temp << newRecord <<endl;
    }
    inFile.close();
    temp.close();
    remove("records.txt");
    rename("temp.txt", "records.txt");
    remove("temp.txt");
}

