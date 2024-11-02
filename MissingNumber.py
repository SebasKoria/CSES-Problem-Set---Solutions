n = int(input())

expected_sum = n * (n + 1) / 2
actual_sum = 0

for num in input().split():
    actual_sum += int(num)

print(int(expected_sum - actual_sum))
