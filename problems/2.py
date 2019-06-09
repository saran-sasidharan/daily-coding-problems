'''
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
'''

def neighbour_product(array):
    if (len(array) < 2):
        return array

    left_product = [1, array[0]]
    for val in array[1:-1]:
        left_product.append(val * left_product[-1])

    right_product = [1, array[-1]]
    for val in reversed(array[1:-1]):
        right_product.append(val * right_product[-1])

    neigh_products = []
    for lval, rval in zip(left_product, reversed(right_product)):
        neigh_products.append(lval * rval)
    
    return neigh_products

assert neighbour_product([1,2,3,4,5]) == [120, 60, 40, 30, 24]
assert neighbour_product([4, 2, 5, 6, 7]) == [420, 840, 336, 280, 240]
assert neighbour_product([2]) == [2]
assert neighbour_product([4, 3]) == [3, 4]

    

