#pragma once
#include <fstream>
#include <iostream>
using namespace std;

string search(string file_path, string search_for) {
  string line;
  bool found = false;

  ifstream file;
  file.open(file_path);
  if (file.is_open()) {
    unsigned int line_num = 0;
    // execute while there is a line to read and not found.
    while (getline(file, line) && !found) {
      line_num++;
      if (line.find(search_for, 0) != string::npos) {
        // if found make found true, close the file and exit loop
        found = true;
        file.close();
        break;
      }
    }
    // close file if it's not closed already.
    // or it won't close if nothing have found.
    if (file.is_open())
      file.close();
  }
  return line;
}

// TODO: looks a bit ugly, maybe improve or explain.
string execute(const string &mStr) {
  string result, file;
  FILE *pipe{popen(mStr.c_str(), "r")};
  char buffer[256];
  while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
    file = buffer;
    result += file.substr(0, file.size() - 1);
  }

  pclose(pipe);
  return result;
}

// TODO: change this to a single print function with switch cases with colors.
string printRed(string text, bool space = false) {
  return "\033[31m" + text + "\033[0m" + (space == true ? " " : "");
}