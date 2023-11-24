#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Gear {
    int id;
    double x, y, radius;
};

double calculateRotations(const std::vector<Gear>& gears, int startGearId, int endGearId) {
    std::unordered_map<int, std::unordered_set<int>> graph;

    // Build the graph based on overlapping gears
    for (int i = 0; i < gears.size(); ++i) {
        for (int j = i + 1; j < gears.size(); ++j) {
            double distance = sqrt(pow(gears[i].x - gears[j].x, 2) + pow(gears[i].y - gears[j].y, 2));
            double sumRadii = gears[i].radius + gears[j].radius;

            if (distance <= sumRadii) {
                graph[i].insert(j);
                graph[j].insert(i);
            }
        }
    }

    // Perform BFS to find the gear chain between startGear and endGear
    std::queue<int> q;
    std::unordered_set<int> visited;

    q.push(startGearId);
    visited.insert(startGearId);

    while (!q.empty()) {
        int currentGearId = q.front();
        q.pop();

        for (int neighbor : graph[currentGearId]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    // Check if both startGear and endGear are connected in the gear chain
    if (visited.find(endGearId) != visited.end()) {
        // Calculate the number of rotations for endGear for one rotation of startGear
        double rotations = 1.0;

        for (int currentGearId : visited) {
            rotations *= gears[currentGearId].radius / gears[startGearId].radius;
        }

        return rotations;
    }

    return 0.0; // Indicates that processing failed
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Gear> gears(N);

    for (int i = 0; i < N; ++i) {
        gears[i].id = i;
        std::cin >> gears[i].x >> gears[i].y >> gears[i].radius;
    }

    int startGearId, endGearId;
    std::cin >> startGearId >> endGearId;

    double rotations = calculateRotations(gears, startGearId - 1, endGearId - 1);

    if (rotations != 0.0) {
        std::cout << std::fixed << std::setprecision(2) << rotations << std::endl;
    } else {
        std::cout << "Could Not Process" << std::endl;
    }

    return 0;
}
