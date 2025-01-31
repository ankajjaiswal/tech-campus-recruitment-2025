#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
using namespace std;
void extractLogs(const std::string& inputFile, const string& date, const string& outputDir = "output") {
    ifstream infile(inputFile);
    
    if (!infile.is_open()) {
        throw ios_base::failure("Error: Could not open the log file.");
    }

    
    system(("mkdir -p " + outputDir).c_str());

   
    string outputFile = outputDir + "/output_" + date + ".txt";
    ofstream outfile(outputFile);

    if (!outfile.is_open()) {
        throw ios_base::failure("Error: Could not create the output file.");
    }

    string line;
    while (std::getline(infile, line)) {
        
        if (line.substr(0, 10) == date) {
            outfile << line << std::endl;
        }
    }

    cout << "Logs for " << date << " have been extracted to " << outputFile << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./extract_logs <YYYY-MM-DD>" << endl;
        return 1;
    }

    string date = argv[1];

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        cerr << "Error: Invalid date format. Please use YYYY-MM-DD." << endl;
        return 1;
    }

    string inputFile = "large_log_file.txt";  
    
    try {
        extractLogs(inputFile, date);
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
