import Foundation

func solution(_ s:String) -> [Int] {
    var num = s
    var removeCount = 0
    var totalTurns = 0
    while num != "1" {
        removeCount += num.filter { $0 == "0"}.count 
        totalTurns += 1
        var onlyOnes = num.filter { $0 == "1"}
        num = String(onlyOnes.count, radix: 2)
}
    return [totalTurns, removeCount]
}