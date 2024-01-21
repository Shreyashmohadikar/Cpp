#include <iostream>
#include <vector>

using namespace std;

vector<int> room_optimization(int A, int B, int C, int D, int X, int Y) {
    vector<int> room_types = {A, B, C, D};
    sort(room_types.begin(), room_types.end(), greater<int>());

    vector<int> initial_rooms(4, 0);
    vector<int> final_rooms(4, 0);
    int total_area = X + Y;

    // Calculate initial rooms
    for (int i = 0; i < 4; ++i) {
        while (X >= room_types[i]) {
            X -= room_types[i];
            initial_rooms[i]++;
        }
    }

    // Calculate final rooms
    for (int i = 0; i < 4; ++i) {
        while (total_area >= room_types[i]) {
            total_area -= room_types[i];
            final_rooms[i]++;
        }
    }

    // Calculate difference
    vector<int> difference(4, 0);
    for (int i = 0; i < 4; ++i) {
        difference[i] = initial_rooms[i] - final_rooms[i];
    }

    return difference;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int X, Y;
    cin >> X >> Y;

    vector<int> result = room_optimization(A, B, C, D, X, Y);

    // Output the difference in the number of rooms for each type
    for (int i = 0; i < 4; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
