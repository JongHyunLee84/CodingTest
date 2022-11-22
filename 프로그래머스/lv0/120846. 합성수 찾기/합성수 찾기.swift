import Foundation

func solution(_ n:Int) -> Int {
    var result = 0
    for i in 1...n {
        var j = 0
        for n in 1...i {
            if i % n == 0 {
                j += 1
            }
        }
        if j >= 3 {
            result += 1
        }
    }
    return result
}