import Foundation

func solution(_ money:Int) -> [Int] {
    var coffee = 5500
    var result : [Int] = []
    result.append(money/coffee)
    result.append(money%coffee)
    return result
}