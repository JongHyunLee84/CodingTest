import Foundation

func solution(_ numbers:[Int], _ k:Int) -> Int {
    var n = 0
    for _ in 1..<k {
        n += 2
        if n > numbers.count {
            n -= numbers.count
        }
    }
    return numbers[n]
    
}