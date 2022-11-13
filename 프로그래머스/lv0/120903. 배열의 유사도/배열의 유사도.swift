import Foundation

func solution(_ s1:[String], _ s2:[String]) -> Int {
    var result: [String] = []
    for one in s1 {
        for two in s2{
            if one == two {
                result.append(one)
            }
        }
    }
    return result.count
}