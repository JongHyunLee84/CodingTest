import Foundation

func solution(_ spell:[String], _ dic:[String]) -> Int {
    var str = spell.joined()
    var count = 0
    for i in dic {
        for j in str {
            if i.contains(j) {
                count += 1
            }
        }
        if count == str.count {
            return 1
        }
        count = 0
    }
    return 2
}