import Foundation

func solution(_ n:Int) -> Int {
    var result = 0
        String(n).compactMap { i in
            var j = i
            result += Int(String(j)) ?? 0
        }
    return result
}