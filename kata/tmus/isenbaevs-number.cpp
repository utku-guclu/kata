// Vladislav Isenbaev is a two-time champion of Ural, vice champion of TopCoder
// Open 2009, and absolute champion of ACM ICPC 2009. In the time you will spend
// reading this problem statement Vladislav would have solved a problem. Maybe,
// even two… Since Vladislav Isenbaev graduated from the Specialized Educational
// and Scientific Center at Ural State University, many of the former and
// present contestants at USU have known him for quite a few years. Some of them
// are proud to say that they either played in the same team with him or played
// in the same team with one of his teammates… Let us define Isenbaev's number
// as follows. This number for Vladislav himself is 0. For people who played in
// the same team with him, the number is 1. For people who weren't his teammates
// but played in the same team with one or more of his teammates, the number is
// 2, and so on. Your task is to automate the process of calculating Isenbaev's
// numbers so that each contestant at USU would know their proximity to the ACM
// ICPC champion. Input The first line contains the number of teams n (1 ≤ n ≤
// 100). In each of the following n lines you are given the names of the three
// members of the corresponding team. The names are separated with a space. Each
// name is a nonempty line consisting of English letters, and its length is at
// most 20 symbols. The first letter of a name is capital and the other letters
// are lowercase. Output For each contestant mentioned in the input data output
// a line with their name and Isenbaev's number. If the number is undefined,
// output “undefined” instead of it. The contestants must be ordered
// lexicographically.

// Isenbaev has number 0
// His direct teammates get number 1
// Teammates of his teammates get number 2
// And so on...

// A graph problem :)

// Each person is a "node" in our graph
// If two people were on the same team, they have an "edge" connecting them
// We want to find the shortest path from Isenbaev to everyone else

/* TODO */
// 1. Create a graph from the input:
// For each team of 3 people
// Connect each person to the other two people on their team

// 2. Use Breadth-First Search (BFS) starting from Isenbaev:
// Start with Isenbaev (distance = 0)
// Find all his teammates (distance = 1)
// Find their teammates (distance = 2)
// And so on...

// Print result:
// -- Sort all names alphabetically
// -- For each name:
//      -- If we found a distance, print it
//      -- If we couldn't reach them, print "undefined"

#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// example input
// 7
/* Isenbaev Oparin Toropov
Ayzenshteyn Oparin Samsonov
Ayzenshteyn Chevdar Samsonov
Fominykh Isenbaev Oparin
Dublennykh Fominykh Ivankov
Burmistrov Dublennykh Kurpilyanskiy
Cormen Leiserson Rivest */

/* Structure to store a team of 3 players */
struct Team {
  string player1, player2, player3;
};

// Function to print Isenbaev's numbers
void printIsenbaevNumbers(const map<string, set<string>> &graph,
                          const map<string, int> &distances) {
  // Get all unique names from graph
  set<string> allPlayers;
  for (const auto &pair : graph) {
    allPlayers.insert(pair.first);
  }

  // Print in alphabetically order
  for (const string &player : allPlayers) {
    cout << player << " ";
    if (distances.find(player) != distances.end()) {
      cout << distances.at(player);
    } else {
      cout << "undefined";
    }
    cout << "\n";
  }
}

// Function to calculate Isenbaev's numbers using BFS
map<string, int>
calculateIsenbaevNumbers(const map<string, set<string>> &graph) {
  map<string, int> distances; // Store distances from Isenbaev

  // Check if Isenbaev exist in the graph
  if (graph.find("Isenbaev") == graph.end()) {
    return distances; // Return empty map if Isenbaev not found
  }

  // Initialize BFS
  queue<string> bfsQueue;
  bfsQueue.push("Isenbaev");
  distances["Isenbaev"] = 0; // Isenbaev's own number is 0

  // Process BFS queue
  while (!bfsQueue.empty()) {
    string currentPlayer = bfsQueue.front(); // Get current player
    bfsQueue.pop(); // Remove current player from the queue

    // Get current player's distance
    int currentDistance = distances[currentPlayer];

    // Process all teammates of current player
    for (const string &teammate : graph.at(currentPlayer)) {
      // If we haven't visited this teammate yet
      if (distances.find(teammate) == distances.end()) {
        // Set their distance (current distance + 1)
        distances[teammate] = currentDistance + 1;
        // Add them to queue for processing;
        bfsQueue.push(teammate);
      }
    }
  }
  return distances;
}

// Function to build graph from teams
map<string, set<string>> buildGraph(const vector<Team> &teams) {
  // Create adjacency list representation of the graph
  map<string, set<string>> graph;

  // Process each team
  for (const Team &team : teams) {
    // Add connections for player1
    graph[team.player1].insert(team.player2);
    graph[team.player1].insert(team.player3);

    // Add connections for player2
    graph[team.player2].insert(team.player1);
    graph[team.player2].insert(team.player3);

    // Add connections for player3
    graph[team.player3].insert(team.player1);
    graph[team.player3].insert(team.player2);
  }

  return graph;
}

// Test function to print the graph
void printGraph(const map<string, set<string>> &graph) {
  cout << "\nGraph connections:\n";
  for (const auto &pair : graph) {
    cout << pair.first << " is connected to: ";
    for (const string &teammate : pair.second) {
      cout << teammate << " ";
    }
    cout << "\n";
  }
}

// Function to get teammates number and for each row 3 teammates
vector<Team> getInput() {
  int n;
  cin >> n; // number of teams

  vector<Team> teams;
  // We need to clear the newline after reading n
  cin.ignore();

  // Read n teams
  for (int i = 0; i < n; i++) {
    Team team;
    cin >> team.player1 >> team.player2 >> team.player3;
    teams.push_back(team);
  }

  return teams;
}

int main() {
  // Read input
  vector<Team> teams = getInput();

  // Build graph
  map<string, set<string>> graph = buildGraph(teams);

  // Print graph to verify connections
  // printGraph(graph);

  // Calculate Isenbaev's numbers
  map<string, int> distances = calculateIsenbaevNumbers(graph);

  // Print Isenbaev's numbers
  printIsenbaevNumbers(graph, distances);

  return 0;
}
