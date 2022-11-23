import Foundation

func solution(_ i:Int, _ j:Int, _ k:Int) -> Int {
    var array : [String] = []
    var str = ""
    var result = 0
    for n in i...j {
        array.append(String(n))
    }
    for i in array {
        str += i
    }
    for i in str {
        if i == Character(String(k)) {
            result += 1
        }
    }
    return result
}