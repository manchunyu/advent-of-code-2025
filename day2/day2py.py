#part 1
# file = open("day2input.txt", "r")
# r = map(lambda i : i.strip("\n").split("-"), file.read().split(","))
# total = 0
# for ra in r:
#     for num in range(int(ra[0]), int(ra[1]) + 1):
#         s_num = str(num)
#         if s_num[0:len(s_num)//2] == s_num[len(s_num)//2 + 1:]:
#             total += int(s_num)

# print(total)

file = open("day2input.txt", "r")
r = map(lambda i : i.strip("\n").split("-"), file.read().split(","))
total = 0
for ra in r:
    for num in range(int(ra[0]), int(ra[1]) + 1):
        s_num = str(num)
        num_len = len(s_num)
        for i in range(1, num_len // 2 + 1):
            if num_len % i == 0:
                if s_num == s_num[:i] * (num_len // i):
                    total += int(s_num)
                    break

print(total)

