/* Den has two four-digit combination locks for protecting his bicycle from
thieves. Every evening he arms the bicycle antitheft alarm and fastens the
bicycle to a special stand with one of the locks. Den never uses the same lock
two evenings in a row. One night a thief tried to open the lock using the code
0000. The alarm went off and the thief hurried away. The next night the thief
decided to try the code 0001, then 0002, and so on in ascending order of the
number. Den never changes the codes of his locks. On the night when the thief
came for the first time the bicycle was fastened with the first lock. Input The
first line contains the combination that opens the first lock and the second
line contains the combination that opens the second lock. Both combinations are
strings consisting of four digits from 0 to 9.  */

#include <iostream>
#include <string>
#include <string_view>
using namespace std;

bool bicycle(string lock1, string lock2) {
  int attempts = 0;
  bool useFirstLock = true; // Start with the first lock

  for (int code = 0; code <= 9999; ++code) {
    // Generate the current code as a 4 digit string
    string attempt = to_string(code);
    attempt = string(4 - attempt.length(), '0') + attempt; // Pad with zeros

    ++attempts;

    // Check the current lock
    if ((useFirstLock && attempt == lock1) ||
        (!useFirstLock && attempt == lock2)) {
      /*       cout << attempts << endl; */
      return true; // Stop when a match is found
    }

    // Alternate to the other lock for the next evening
    useFirstLock = !useFirstLock;
  }

  return false;
}

int main() {
  string lock1, lock2;
  cin >> lock1 >> lock2;
  cout << (bicycle(lock1, lock2) ? "yes" : "no") << endl;
  return 0;
}
