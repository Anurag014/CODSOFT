#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int hardness, total_moves = 0;

    cout << "1. Easy\n2. Medium\n3. Hard\nSelect Difficulty level: ";
    cin >> hardness;

    switch (hardness) {
        case 1:
            total_moves = 20;
            break;
        case 2:
            total_moves = 10;
            break;
        case 3:
            total_moves = 5;
            break;
    }

    srand(time(0));
    int jackpot = rand() % 100 + 1;

    while (true) {
        int guess;
        cout<<"Guess Left: "<<total_moves<<endl;
        cout << "Guess no: ";
        cin >> guess;

        if (guess == jackpot) {
            cout << "You win" << endl;
            break;
        } else if (guess > jackpot) {
            cout << "Hint: low number" << endl;
        } else {
            cout << "Hint: high number" << endl;
        }

        total_moves--;

        if (total_moves == 0) {
            cout << "You lose" << endl;
            cout << "Jackpot number is " << jackpot << endl;
            break;
        }
    }

    return 0;
}
