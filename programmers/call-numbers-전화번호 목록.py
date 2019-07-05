# https://programmers.co.kr/learn/courses/30/lessons/42577


# def solution(phone_book):
#     for idx, phone in enumerate(phone_book):

#         rest = list(filter(lambda x: x != phone, phone_book))

#         for r in rest:
#             if r.startswith(phone):
#                 return False

#     return True

# 언제나 더 좋은 방법!

def solution(phoneBook):
    phoneBook.sort()

    for p1, p2 in zip(phoneBook, phoneBook[1:]):
        if p2.startswith(p1):
            return False
    return True


print(solution(["119", "97674223", "1195524421"]))
print(solution(["123", "456", "789", "789"]))
print(solution(["12", "123", "1235", "567", "88"]))
