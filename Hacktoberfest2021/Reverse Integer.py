# Time Complexity --> O(1)

class Solution:
    def reverse(self, x: int) -> int:
        # str = "Hello World"
        # str = str[::-1]
        # str = str[:-1]
        # return str + "Amisha"
        if x in range(-2**31, 2**31 - 1):
            y = x
            x = str(x)
            x = x[::-1]
            if y < 0:
                x = x[:-1]
                if int(x) in range(-2**31, 2**31 - 1):
                    return int(x) * -1
                else:
                    return 0
            else:
                if int(x) in range(-2**31, 2**31 - 1):
                    return int(x)
                else:
                    return 0
        else:
            return 0
            
        
    