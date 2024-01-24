import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    // var nestedArray = Array(repeating: Array(repeating:0 ,count: n), count: n)
    var array: [Int] = []
    for i in Int(left)...Int(right) {
        let row = i / n
        let column = i % n 
        if row > column { array.append(row+1) }
        else { array.append(column+1) }
    }
    return array
}