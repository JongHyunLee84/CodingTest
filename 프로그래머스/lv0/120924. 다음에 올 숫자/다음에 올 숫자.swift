import Foundation

func solution(_ common:[Int]) -> Int {
    var plus = common[1] - common[0]
    if common[common.count-1] - common[common.count-2] == plus {
        return common[common.count-1] + plus
    } else {
        return common[common.count-1] * common[1] / common[0]
    }
}