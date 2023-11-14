import Foundation

func solution(_ citations:[Int]) -> Int {
    let array = citations.sorted(by: <)
    let maxNum = array.max()!
    var ret = 0
    for i in 0..<maxNum {
        var less = 0
        var more = 0
        for j in 0..<array.count {
            if array[j] >= i { more += 1 }
            if array[j] < i { less += 1 }
        }
        if i <= more && i > less {
                ret = i
            }
    }
    
    return ret
}