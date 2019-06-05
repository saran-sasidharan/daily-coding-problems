/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

compile instruction: g++ -std=c++11 5.cpp
*/

#include<vector>
#include<set>
#include<assert.h>


bool checkSumExist(const std::vector<int>& array, int k)
{
    std::set<int> expected_values;
    for (auto value: array)
    {
        if (expected_values.find(value) != expected_values.end())
            return true;
        expected_values.insert(k - value);
    }
    return false;
}

int main()
{
    std::vector<int> array1 = {10, 15, 3, 7};
    assert(checkSumExist(array1, 17));

    std::vector<int> array2 = {1, 2, 3, 4};
    assert(!checkSumExist(array2, 20));
}

