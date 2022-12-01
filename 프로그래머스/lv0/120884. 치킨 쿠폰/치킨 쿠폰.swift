import Foundation

func solution(_ chicken:Int) -> Int {
    var result = 0
    if chicken == 0 {
        return 0
    }
    for _ in 1...chicken {
        result += 1
        if result % 10 == 0 {
            result += 1
        }
    }
    return result / 10 
}