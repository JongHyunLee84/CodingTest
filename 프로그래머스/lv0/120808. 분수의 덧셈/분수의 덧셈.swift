import Foundation

func solution(_ denum1:Int, _ num1:Int, _ denum2:Int, _ num2:Int) -> [Int] {
    var plusDe = 0
    var num = num1
    var mulNums = num1 * num2
    var n = 2
    if num1 == num2 {
       plusDe = denum1 + denum2
        for _ in 0..<num {
            if plusDe % n == 0 && num % n == 0 {
                plusDe /= n
                num /= n
            } else {
                n += 1
        }
        }
    } else {
        plusDe = (denum1*num2) + (denum2*num1)
        num = num1 * num2
        for _ in 0..<num {
            if plusDe % n == 0 && num % n == 0 {
                plusDe /= n
                num /= n
            } else {
                n += 1
        }
        }
        
    }
    return [plusDe, num]
}