// Big Prime Number
// Problem Statement
// Dylan loves prime numbers very much. He has n prime
// numbers and he can use any prime number an infinite number
// of times.
// When he plays with his prime numbers, he uses his prime
// numbers and multiples them with each other, and makes a
// number.
// For example, if Dylan has prime numbers, 2, 3, and 5, then he
// can make:
// 2, 3, 4(2*2), 5, 6, (2*3), 8(2*2*2), 9(3*3), 10(2*5), 12, 15...
// He can use his prime numbers an infinite number of times.
// One day his father came and saw his son playing with numbers
// and asked him the Kth number he can make from his prime
// numbers.
// Help Dylan in finding the Kth number.
// Example 1
// Input
// 3
// 2 3 5
// 3
// Output
// 4
// Explanation
// He can make 2, 3, 4(2*2), 5, 6(2*3), 8(2*2*2), 9(3*3), 10(2*5),
// 12, 15. So, the third number he can make is 4.
// Example 2
// Input
// 3
// 2 3 5
// 7
// Output
// 9
// Explanation
// He can make 2, 3, 4(2*2), 5, 6(2*3), 8(2*2*2), 9(3*3), 10(2*5),
// 12, 15. So, the seventh number he can make is 9.
// Input format :
// input1: n, number of prime numbers which Dylan has.
// input2: An array containing a list of n prime numbers which Dylan
// has.
// input3: Value of k.
// Output format :
// Return the Kth number he can make from his prime numbers.


#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

long long findKthNumber(int n, vector<int>& primes, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    unordered_set<long long> visited;

    for (int prime : primes) {
        pq.push(prime);
        visited.insert(prime);
    }

    long long result = 0;
    for (int i = 0; i < k; i++) {
        long long current = pq.top();
        pq.pop();
        result = current;

        for (int prime : primes) {
            long long next = current * prime;
            if (!visited.count(next)) {
                pq.push(next);
                visited.insert(next);
            }
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter the number of prime numbers: ";
    cin >> n;

    vector<int> primes(n);
    cout << "Enter the prime numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> primes[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    long long result = findKthNumber(n, primes, k);

    cout << "The " << k << "th number Dylan can make is: " << result << endl;

    return 0;
}