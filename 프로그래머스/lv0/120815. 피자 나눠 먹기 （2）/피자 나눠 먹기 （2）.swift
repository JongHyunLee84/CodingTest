import Foundation
var num = 0
func solution(_ n:Int) -> Int {
    for i in 1...n {
        var first = n % i
        var second = 6 % i
        if first == 0 && second == 0 {
            num = i
        }
    }
    if n % 6 == 0 {
        return n / 6
    } else {
        return ((n * 6) / num) / 6
    }
   
}