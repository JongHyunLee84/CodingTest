import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var dic: [Int: Int] = [:]
    for i in tangerine {
        dic[i, default: 0] += 1
    }
    var sortedDic = dic.sorted { $0.value > $1.value }
    var cnt = 0
    var idx = 0
    while cnt < k {
        cnt += sortedDic[idx].1
        idx += 1
    }
    return idx
}