/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "utils.h"
using std::string;
std::string kYourName = "Wang Xiuqiang"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::unordered_set<std::string> applicants;
  std::ifstream input(filename);
  if (!input.is_open()) {
    std::cerr << "Error: could not open file " << filename << std::endl;
    return applicants;
  }
  std::string name;
  while (getline(input, name)) {
    applicants.insert(name);
  }
  input.close();
  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name,
                                            std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> matches;
  for (auto it : students) {
    std::istringstream ss(it);
    std::vector<std::string> tokens;
    std::vector<std::string> names;
    ss >> tokens[0] >> tokens[1];
    if (tokens.at(0).at(0) == names.at(0).at(0) && tokens.at(1).at(0) == names.at(1).at(0)) {
      matches.push(&it);
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  std::mt19937 gen;
  std::uniform_int_distribution<int> dis(0, matches.size() - 1);
  int index = dis(gen);
  for (int i = 0; i < index - 1; i++) {
    matches.pop();
  }
  return *matches.front();
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
