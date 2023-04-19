import Foundation

func solution(_ name:[String], _ yearning:[Int], _ photo:[[String]]) -> [Int] {
    var result: [Int] = []
    for i in photo {
        var n = 0
        for j in i {
            if name.contains(j) {
                let index = name.firstIndex(of: j)!
                n += yearning[index]
            }
        }
        result.append(n)
    }
    return result
}