import Foundation

func solution(_ array:[Int]) -> Int {
    var n : [Int] = []
    var count = 0
    for i in 0..<1000 {
        for j in array {
            if i == j {
                count += 1
            }
        }
        n.append(count)
        count = 0
    }
    if n.firstIndex(of: n.max()!)! != n.lastIndex(of: n.max()!)! {
        return -1
    }
    return n.firstIndex(of: n.max()!)!
}
