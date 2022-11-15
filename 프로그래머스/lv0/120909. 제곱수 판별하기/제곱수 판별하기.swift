import Foundation

func solution(_ n:Int) -> Int {
    for i in 0..<n {
        if i * i == n {
            return 1
        }
    }
    return 2
}