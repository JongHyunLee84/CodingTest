import Foundation

func solution(_ array:[Int]) -> [Int] {
    var result : [Int] = []
    var max = 0
    for i in array {
        if i > max {
            max = i
        }
    }
    result.append(max)
    result.append(array.firstIndex(of:max)!)
    return result
}