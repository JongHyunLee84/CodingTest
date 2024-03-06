import Foundation

func solution(_ sequence:[Int]) -> Int64 {
    var sum: Int64 = 0 
    var result: Int64 = 0
    for i in 0..<sequence.count {
        var temp = Int64(sequence[i])
        if i % 2 == 0 {
            sum += temp
        } else {
            sum += temp * -1
        }
        if sum < 0 {
            sum = 0
        } else {
            result = max(result,sum)
        }
    } 
    sum = 0
    for i in 0..<sequence.count {
        var temp = Int64(sequence[i])
        if i % 2 != 0 {
            sum += temp
        } else {
            sum += temp * -1
        }
        if sum < 0 {
            sum = 0
        } else {
            result = max(result, sum)
        }
    } 
    return result 
}