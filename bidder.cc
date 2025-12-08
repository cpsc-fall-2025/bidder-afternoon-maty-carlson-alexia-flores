#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// INSTRUCTIONS
// ============================================================================
// 1. Implement the three functions below.
// 2. You may use the main() function at the bottom to test your code locally.
// 3. Do not change the function signatures.
// ============================================================================

// TODO: Implement this function to return a vector of strings
// containing the names of everyone on your team.
std::vector<std::string> GetTeamMembers() {
  std::vector<std::string> TeamMembers;
  TeamMembers.push_back("Maty Carlson");
  TeamMembers.push_back("Alexia Flores");
  return TeamMembers;
}

// TODO: Implement this function to return a string that describes
// the strategy your logic uses to bid (e.g., "We bid high early on").
std::string GetStrategy() {
  std::string OurStrategy = "skip 1st 1/5 of the bids, bid an even amount of the budget for the remaining bids";
  return OurStrategy;
}

// TODO: Implement the bidding logic.
// parameters:
//   rounds: The total number of rounds in the game.
//   budget: The total points available to spend across all rounds.
//   output_filename: The name of the file where the bids should be written.
//
// Logic:
//   1. Calculate how much to bid in each round.
//   2. Open 'output_filename' for writing.
//   3. Write the bid for each round on a new line in the file.
//
// Constraints:
//   - You must write exactly 'rounds' number of lines.
//   - The sum of all bids must not exceed 'budget'.
//   - Bids must be non-negative integers.
void GenerateBids(int rounds, int budget, std::string output_filename) {
  std::ofstream WhateverMan (output_filename);
  const int NumSkippedRounds {rounds/5};
  for (int i = 1; i <= NumSkippedRounds; i++) {
    WhateverMan << 0 << "\n";
  }
  int Remainder {budget};
  const int NumBidRounds {rounds-NumSkippedRounds};
  int BidAmount {budget/NumBidRounds};
  for (int i = NumSkippedRounds+1; i <= rounds; i++) {
    Remainder -= BidAmount;
    if (i == rounds) {
       BidAmount += Remainder;
    }
    WhateverMan << BidAmount << "\n";

  }
  // Your code here
}

// ============================================================================
// MAIN FUNCTION
// Use this to test your code.
// This function will be ignored by the "make test" command.
// ============================================================================
int main() {
  // You can write code here to call your functions and see if they work.
  // Example:
  // GenerateBids(10, 100, "test_output.txt");

  return 0;
}
