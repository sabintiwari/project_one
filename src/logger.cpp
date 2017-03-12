#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "logger.h"


using namespace std;

// Default constructor
Logger::Logger()
{

};
// Logger constructor
Logger::Logger(std::string filename)
{
	log_file.open(filename.c_str(), ios::out | ios::trunc);
};
/* Get the string value from an int. */
std::string Logger::i_to_s(int value)
{
	std::stringstream str;
	str << value;
	return str.str();
}
/* Logs a message to the cout and the log file. Includes a \n at the end. */
void Logger::log(std::string message)
{
	time_t timestamp = time(0);
	char * dt = ctime(&timestamp);
	std::string dt_str(dt);
	dt_str = dt_str.substr(0, dt_str.size() - 1);
	cout << "[" << dt_str << "] " << message << endl;
	if(log_file.is_open())
		log_file << "[" << dt_str << "] " << message << endl;
}
/* Closes the file stream. */
void Logger::close()
{
	log_file.close();
}