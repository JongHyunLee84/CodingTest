import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var last = words[0].first!
    var who = 1
    var turn = 1
    var array: [String] = []
    for i in words {
        if i.first! != last || array.contains(i) {
            return [who, turn]
        }
        if who % n == 0 {
            who = 1
            turn += 1
        } else {
            who += 1
        }
        array.append(i)
        last = i.last!
    }
    return [0,0]
}