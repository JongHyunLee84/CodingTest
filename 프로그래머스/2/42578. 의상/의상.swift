import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dic: [String: Int] = [:]
    for i in clothes {
        dic[i[1], default: 0] += 1
    }
    var ret = 0
    for i in dic {
        if ret == 0 {
            ret += i.value+1
        } else {
                    ret *= i.value+1
        }
    }
    ret -= 1
    return ret
}