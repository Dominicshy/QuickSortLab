#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Function to print the vector (for testing purposes)
void printVector(const std::vector<int>& numbers) {
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Partitions a sub-array for Quick Sort.
 *        It picks a pivot (the midpoint) and rearranges the elements such that
 *        all elements less than the pivot are to its left, and all elements
 *        greater are to its right.
 *
 * @param numbers The vector of integers to be sorted.
 * @param i The starting index of the sub-array.
 * @param k The ending index of the sub-array.
 * @return The high index of the left partition.
 */
int Partition(std::vector<int>& numbers, int i, int k) {
    // TODO: Implement the Partition function as per lab requirements.
    // Calculate the pivot as the middle element.
    // Use a while loop with low and high pointers to perform swaps.
    // Ensure the function returns the high index of the left partition.

    // set up mid point
    int pivot = numbers.at(i + (k - i) / 2);
    // set point so we don't need to change the range of i to k
    int& low = i;
    int& high = k;
    
    // set up range to low aka i/fist idex to k aka last idex
    while (low < k) {
        // if the number is lest then pivot to move to start and remove it spot make easy later on
        if (numbers.at(low) < pivot) {
            int temp = numbers.at(low);
            numbers.erase(numbers.begin() + low);
            numbers.insert(numbers.begin(), temp);
            low = low + 1;
                     }
        // if it bigger than pivot we need to move it to end and replace it that is less then org low
        else if (numbers.at(low) > pivot) {
            while (low < high) {
                if (numbers.at(low) < numbers.at(high)) {
                    high = high - 1;

                }
                else {
                    std::swap(numbers.at(low), numbers.at(high));
                    high = k;
                    low = low + 1;
                }
            }
          }
        // help leave the while
        else {
            low = low + 1;
        }
        
        
    }
    // return numbers back to quicksort
    return low;
}

/**
 * @brief Implements the Quick Sort algorithm recursively.
 *        It works by partitioning the array and then sorting the two
 *        resulting halves independently.
 *
 * @param numbers The vector of integers to be sorted.
 * @param i The starting index of the sub-array.
 * @param k The ending index of the sub-array.
 */
void QuickSort(std::vector<int>& numbers, int i, int k) {
    // TODO: Implement the QuickSort function as per lab requirements.
    // Base Case: If the partition size is 1 or 0 (i >= k), return.
    // Recursive Step: Call Partition, then recursively sort the left partition (i to j)
    // and the right partition (j + 1 to k).
    
    if (i >= k) {
        return;
    }

    
    else {
        Partition(numbers, i, k);
        
        int j = (i + (k - i) / 2);
        // if the middle point is the lowest number we need to move it to first make/ was painful to try move it without use this way
        if (i < j) {
            std::swap(numbers.at(i), numbers.at(j));
        }
        // rnage to first idex to middle idex
        while(i <= j){
            //swap if it bigger number next to it then so on
            if (numbers.at(i) > numbers.at(i + 1)) {
                std::swap(numbers.at(i), numbers.at(i + 1));
            }
            // help leave while
            else {
                i = i + 1;
            }

        }
        // idex that is next to middle idex tp last idex
        while (j + 1 < k) {
            //going backward to find bigher to end and lowest to start next to middle index
            if (numbers.at(k - 1) > numbers.at(k)) {
                std::swap(numbers.at(k - 1), numbers.at(k));
                
            }
            // leave while
            else {
                k = k - 1;
            }

        }
        //leave while and return the numbers back to int main()
        i = i + 1;
        

    }

}

int main() {
    std::vector<int> numbers = { 10, 7, 8, 9, 1, 5 };
    std::cout << "Original array: ";
    printVector(numbers);

    // Call QuickSort
    QuickSort(numbers, 0, numbers.size() - 1);

    std::cout << "Sorted array: ";
    printVector(numbers);

    std::vector<int> numbers2 = { 38, 27, 43, 3, 9, 82, 10 };
    std::cout << "Original array 2: ";
    printVector(numbers2);

    // Call QuickSort
    QuickSort(numbers2, 0, numbers2.size() - 1);

    std::cout << "Sorted array 2: ";
    printVector(numbers2);

    return 0;
}