import Foundation

func solution(_ elements:[Int]) -> Int {
    var possible: Set<Int> = []
    for i in 0..<elements.count {
        var tempSum = 0
        for j in i..<(i+elements.count) {
            tempSum += elements[j%elements.count]
            possible.insert(tempSum)
        }
    }
    return possible.count
}