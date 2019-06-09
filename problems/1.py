'''
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
'''

def check_sum_exists(array, k):
    expected_values = set()
    for value in array:
        if value in expected_values:
            return True
        expected_values.add(k-value)
    return False

assert check_sum_exists([10, 15, 3, 7], 17)
assert not check_sum_exists([1, 2, 3, 4], 20)