#include <iostream>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        // If there is only one disk, move it from source to destination
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }
    
    // Move n-1 disks from source to auxiliary peg using destination as an auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    
    // Move the n-1 disks from auxiliary peg to destination using source as an auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;
    
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, and C are the names of the rods
    return 0;
}
