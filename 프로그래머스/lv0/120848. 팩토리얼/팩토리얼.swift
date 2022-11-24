import Foundation

func solution(_ n:Int) -> Int {
    var num = Double(n)
    var i : Double = 1.0
while num / i > i {
    num /= i
    i += 1
}
    return Int(i)
}