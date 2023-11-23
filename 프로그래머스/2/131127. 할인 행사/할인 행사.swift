import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var ret = 0
    var sum = number.reduce(0,+)
    for i in 0..<discount.count {
        var cntDic: [String: Int] = [:]
        for j in i..<min(discount.count,(i+sum)) {
            if want.contains(discount[j]) {
                cntDic[discount[j], default: 0] += 1
            }
        }
        var isSame = true
        for j in 0..<want.count {
            if cntDic[want[j], default: 0] != number[j] {
                isSame = false
                break
            }
        }
        if isSame { ret += 1}
    }
    return ret
}