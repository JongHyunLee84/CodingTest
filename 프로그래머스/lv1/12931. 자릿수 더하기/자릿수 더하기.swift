import Foundation

func solution(_ n:Int) -> Int {
    var str = String(n)
    return str.map { Int(String($0))! }.reduce(0,+)
}