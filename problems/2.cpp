/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include<vector>
#include<assert.h>
#include<iostream>

std::vector<int> neighbour_product(const std::vector<int>& array)
{
    if (array.size() < 2) 
        return array;

    auto left_product = std::vector<int> {1, array[0]};
    for (auto val = array.begin()+1; val != array.end()-1; val++)
        left_product.push_back(*val * left_product.back());

    auto right_product = std::vector<int> {1, array.back()};
    for (auto val = array.rbegin()+1; val != array.rend()-1; val++)
        right_product.push_back(*val * right_product.back());

    auto left = left_product.begin();
    auto right = right_product.rbegin();
    auto neigh_product = std::vector<int>();
    while (left!=left_product.end())
    {
        neigh_product.push_back(*left * (*right));
        left++, right++;
    }

    return neigh_product;
}

void print(const std::vector<int>& array)
{
    for (auto val: array) 
        std::cout << val << ' ';
    std::cout << std::endl;
}

int main()
{
    print(neighbour_product(std::vector<int>{1,2,3,4,5})); // Results should be [120, 60, 40, 30, 24]
    print(neighbour_product(std::vector<int>{4, 2, 5, 6, 7})); // [420, 840, 336, 280, 240]
    print(neighbour_product(std::vector<int>{2})); // [2]
    print(neighbour_product(std::vector<int>{4, 3})); // [3, 4]
}