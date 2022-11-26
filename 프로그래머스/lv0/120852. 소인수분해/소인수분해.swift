import Foundation

func solution(_ n:Int) -> [Int] {
    var num1 = n
    var num = 2
    var a = Array<Int>()
    for _ in 0..<n {
    if num1 % num == 0 {
        num1 = num1 / num
        if !a.contains(num) {
            a.append(num)
        }
    } else {
        num += 1
    }
    }
    if a.isEmpty {
        a.append(2)
    }
    
    return a
}