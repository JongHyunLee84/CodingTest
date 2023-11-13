import Foundation

func solution(_ numbers:[Int]) -> String { 
    let ret = numbers.sorted { num1, num2 -> Bool in
        var str1 = String(num1)
        var str2 = String(num2)
        var case1 = Int(str1 + str2)!
        var case2 = Int(str2 + str1)!
        return case1 > case2
    }.map { String($0) }.joined()
    return ret.first! == "0" ? "0" : ret
}