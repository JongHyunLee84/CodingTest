let n = Int(readLine()!)!

public func factorial(_ n: Int) -> Int {
    var num = n
    var two = 0
    var five = 0
    while num > 1 {
        var temp = num
        while temp % 2 == 0 {
            two += 1
            temp /= 2
        }
        while temp % 5 == 0 {
            five += 1
            temp /= 5
        }
        num -= 1
    }
    return min(two, five)
}

print(factorial(n))