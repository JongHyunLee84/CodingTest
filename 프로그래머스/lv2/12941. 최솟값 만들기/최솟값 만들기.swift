import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int
{
    var result = 0 
    var a = A.sorted(), b = B.sorted(by: >)
    for i in 0..<A.count {
        result += a[i] * b[i]
    }

    return result
}