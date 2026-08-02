// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

int calculateSum(const int values[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += values[i];
    }
    return sum;
}

double calculateAverage(const int values[], int count)
{
    int sum = calculateSum(values, count);
    return static_cast<double>(sum) / count;
}

int findMaximum(const int values[], int count)
{
    int maximum = values[0];
    for (int i = 1; i < count; ++i)
    {
        if (values[i] > maximum)
        {
            maximum = values[i];
        }
    }
    return maximum;
}

int findMinimum(const int values[], int count)
{
    int minimum = values[0];
    for (int i = 1; i < count; ++i)
    {
        if (values[i] < minimum)
        {
            minimum = values[i];
        }
    }
    return minimum;
}

int main()
{
    int count;
    cout << "How many numbers? ";
    cin >> count;

    if (count <= 0)
    {
        cout << "Error: Number of values must be positive." << endl;
        return 0;
    }

    int values[1000];
    for (int i = 0; i < count; ++i)
    {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> values[i];
    }

    int sum = calculateSum(values, count);
    double average = calculateAverage(values, count);
    int maximum = findMaximum(values, count);
    int minimum = findMinimum(values, count);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}

