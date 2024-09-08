// use the cerr and clog objects to direct outputs to log files.
// also, use command line arguments to specify the log file names.

#include <iostream>
#include <fstream>

int main()
{
  std::ofstream log_file("log.txt");
  std::clog.rdbuf(log_file.rdbuf());

  std::ofstream error_file("error.txt");
  std::cerr.rdbuf(error_file.rdbuf());

  std::cerr << "Error Message: 1" << std::endl;
  std::cerr << "Error Message: 2" << std::endl;

  std::clog << "Log Message: 1" << std::endl;
  std::clog << "Log Message: 2" << std::endl;

  std::cerr << "Error Message: 3" << std::endl;
  std::cerr << "Error Message: 4" << std::endl;

  std::clog << "Log Message: 3" << std::endl;
  std::clog << "Log Message: 4" << std::endl;

  error_file.close();
  log_file.close();

  return 0;
}