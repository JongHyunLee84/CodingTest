import Foundation

func solution(_ enroll:[String], _ referral:[String], _ seller:[String], _ amount:[Int]) -> [Int] {
    var sum: [String: Int] = [:]
    var parent: [String: String] = [:]
    for i in 0..<referral.count {
        let name = enroll[i]
        let ref = referral[i]
        parent[name, default: ""] = ref
    }
    for i in 0..<seller.count {
        let tempSeller = seller[i]
        var tempAmount = amount[i] * 100
        var tempParent = parent[tempSeller, default: ""]
        sum[tempSeller, default: 0] += tempAmount - (tempAmount / 10)
        while(tempParent != "" && tempAmount > 0) {
            tempAmount /= 10
            sum[tempParent, default: 0] += tempAmount - (tempAmount / 10)
            tempParent = parent[tempParent, default: ""]
        }
    }
    var result = Array(repeating: 0, count: enroll.count) 
    for i in 0..<enroll.count {
        result[i] = sum[enroll[i], default: 0]
    }
    // for i in sum { print(i) }
    // eroll에서 하나씩 뽑으면서 depth 파악 + 해당 직원의 가격 담아두기
    // 레퍼럴이 있으면 해당 레퍼러의 depth + 1
    // 마지막 depth인 애들부터 한사이클씩 10%주기
    // 각 depth인 애들 호출 가능해야함.
    
    return result
}