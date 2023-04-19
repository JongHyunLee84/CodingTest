import Foundation

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    var array: [Int] = []
    var result: [Int] = []
    for i in score {
        if array.count < k {
            array.append(i)
            array.sort(by: >)
            result.append(array.last!)
        } else {
            if array[k-1] < i {
                array[k-1] = i
                array.sort(by: >)
                result.append(array.last!)
            } else {
                result.append(array.last!)
            }
        }
    }
    return result
}