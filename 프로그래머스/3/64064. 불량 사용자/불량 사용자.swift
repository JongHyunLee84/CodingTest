import Foundation

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    var total = Set<Set<String>>()
        
    func go(_ idx: Int, _ list: Set<String>) {
    if idx == banned_id.count { 
        total.insert(list)
        return 
    }
    for i in user_id {
        if !(list.contains(i)) {
            if i.count == banned_id[idx].count {
                if isSame(i, banned_id[idx]) {
                    var tempList = list
                    tempList.insert(i)
                    go(idx+1, tempList)
                }
            }
        }
    }
}

func isSame(_ first: String, _ second: String) -> Bool {
    var firstArr = Array(first)
    var secondArr = Array(second)
    for i in 0..<first.count {
        if secondArr[i] == "*" { continue }
        if firstArr[i] != secondArr[i] { return false }
    }
    return true
} 
    go(0, [])
    return total.count
    
}